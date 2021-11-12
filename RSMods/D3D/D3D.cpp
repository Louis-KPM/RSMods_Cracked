#include "D3D.hpp"
#include "../Mods/ExtendedRangeMode.hpp"
#include "../Mods/CollectColors.hpp"

/// <summary>
/// Apply Custom String Colors
/// </summary>
void D3D::SetCustomColors() {
	for (int strIdx = 0; strIdx < 6;strIdx++) {
		ColorMap customColorsFull;

		ColorMap normalColors = GetCustomColors(strIdx, false);
		ColorMap cbColors = GetCustomColors(strIdx, true);


		customColorsFull.insert(normalColors.begin(), normalColors.end());
		customColorsFull.insert(cbColors.begin(), cbColors.end());

		ERMode::SetCustomColors(strIdx, customColorsFull);
	}
}

/// <param name="strIdx"> - Current String thickest to thinnest (zero-indexed)</param>
/// <param name="CB"> - Are we using colorblind colors?</param>
/// <returns>List of All Potential Colors for a String</returns>
ColorMap D3D::GetCustomColors(int strIdx, bool CB) {
	RSColor iniColor;
	std::string ext;

	if (CB)
		ext = "_CB";
	else
		ext = "_N";

	iniColor = Settings::GetStringColors(CB)[strIdx];
	int H;
	float S, L;
	CollectColors::RGB2HSL(iniColor.r, iniColor.g, iniColor.b, H, S, L);

	ColorMap customColors = {
		{"Ambient" + ext, CollectColors::GetAmbientStringColor(H, CB)},
		{"Disabled" + ext, CollectColors::GetDisabledStringColor(H, S, L, CB)},
		{"Enabled" + ext, iniColor},
		{"Glow" + ext, CollectColors::GetGlowStringColor(H)},
		{"PegsTuning" + ext, CollectColors::GetTuningPegColor(H, CB)},
		{"PegsReset" + ext, CollectColors::GetPegResetColor()},
		{"PegsSuccess" + ext, CollectColors::GetPegSuccessColor(CB)},
		{"PegsInTune" + ext, CollectColors::GetPegInTuneColor(H, CB)},
		{"PegsOutTune" + ext, CollectColors::GetPegOutTuneColor()},
		{"TextIndicator" + ext, CollectColors::GetRegTextIndicatorColor(H, CB)},
		{"ForkParticles" + ext, CollectColors::GetRegForkParticlesColor(H, CB)},
		{"NotewayNormal" + ext, CollectColors::GetNotewayNormalColor(H, S, L, CB)},
		{"NotewayAccent" + ext, CollectColors::GetNotewayAccentColor(H, CB)},
		{"NotewayPreview" + ext, CollectColors::GetNotewayPreviewColor(H, CB)},
		{"GC_Main" + ext, CollectColors::GetGuitarcadeMainColor(H, strIdx, CB)},
		{"GC_Add" + ext, CollectColors::GetGuitarcadeAdditiveColor(H, strIdx, CB)},
		{"GC_UI" + ext, CollectColors::GetGuitarcadeUIColor(H, strIdx, CB)}
	};

	return customColors;
}

/// <returns>Random Color</returns>
RSColor GenerateRandomColor() {
	RSColor rndColor;

	static std::uniform_real_distribution<> urd(0.0f, 1.0f);
	rndColor.r = (float)urd(rng);
	rndColor.g = (float)urd(rng);
	rndColor.b = (float)urd(rng);

	return rndColor;
}

/// <summary>
/// Generate a texture to later be used to override a texture.
/// </summary>
/// <param name="pDevice"> - Device Pointer</param>
/// <param name="ppTexture"> - Output Texture</param>
/// <param name="colorSet"> - List of colors to jam into the texture</param>
/// <param name="in_width"> - How wide should the texture be?</param>
/// <param name="in_height"> - How tall should the texture be?</param>
/// <param name="in_lineHeight"> - How thick should each line be?</param>
/// <param name="howManyLines"> - How many lines should there be?</param>
void D3D::GenerateTexture(IDirect3DDevice9* pDevice, IDirect3DTexture9** ppTexture, ColorList colorSet, UINT in_width, UINT in_height, int in_lineHeight, int howManyLines) {
	while (GetModuleHandleA("gdiplus.dll") == NULL) // JIC, to prevent crashing
		Sleep(500);

	using namespace Gdiplus;
	UINT width = in_width, height = in_height;
	int lineHeight = in_lineHeight;

	if (Ok != GdiplusStartup(&token_, &inp, NULL))
		std::cout << "GDI+ failed to start up!" << std::endl;

	Bitmap bmp(width, height, PixelFormat32bppARGB);
	Graphics graphics(&bmp);
	RSColor currColor;

	REAL blendPositions[] = { 0.0f, 0.4f, 1.0f };

	for (int i = 0; i < howManyLines; i++) {
		currColor = colorSet[i]; // If we are in range of 0-7, grab the normal colors, otherwise grab CB colors

		Gdiplus::Color middleColor(currColor.r * 255, currColor.g * 255, currColor.b * 255); // Notes

		Gdiplus::Color gradientColors[] = { Gdiplus::Color::Black, middleColor , Gdiplus::Color::White };
		LinearGradientBrush linGrBrush( // Base texture for note gradients (top / normal)
			Point(0, 0),
			Point(width, lineHeight),
			Gdiplus::Color::Black,
			Gdiplus::Color::White);
		LinearGradientBrush whiteCoverupBrush( // Coverup for some spotty gradients (top / normal)
			Point(width - 3, lineHeight * 5),
			Point(width, height),
			Gdiplus::Color::White,
			Gdiplus::Color::White);

		linGrBrush.SetInterpolationColors(gradientColors, blendPositions, 3);
		graphics.FillRectangle(&linGrBrush, 0, i * lineHeight, width, lineHeight);
		graphics.FillRectangle(&whiteCoverupBrush, width - 3, i * lineHeight, width, lineHeight); // Don't hate me for this hacky fix to the black bars.
	}

	// Uncomment if you want to save the generated texture
	/*CLSID pngClsid;
	CLSIDFromString(L"{557CF406-1A04-11D3-9A73-000F81EF32E}", &pngClsid); //for BMP: {557cf400-1a04-11d3-9a73-0000f81ef32e}
	bmp.Save(L"generatedTexture.png", &pngClsid); */

	BitmapData bitmapData;
	D3DLOCKED_RECT lockedRect;

	D3DXCreateTexture(pDevice, width, height, 1, 0, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED, ppTexture);

	(*ppTexture)->LockRect(0, &lockedRect, 0, 0);

	bmp.LockBits(&Rect(0, 0, width, height), ImageLockModeRead, PixelFormat32bppARGB, &bitmapData); // Strings

	unsigned char* pSourcePixels = (unsigned char*)bitmapData.Scan0;
	unsigned char* pDestPixels = (unsigned char*)lockedRect.pBits;

	for (unsigned int y = 0; y < height; ++y)
	{
		// copy a row
		memcpy(pDestPixels, pSourcePixels, width * 4);   // 4 bytes per pixel

		// advance row pointers
		pSourcePixels += bitmapData.Stride;
		pDestPixels += lockedRect.Pitch;
	}

	(*ppTexture)->UnlockRect(0);

	//D3DXSaveTextureToFileA("generatedTexture_d3d.dds", D3DXIFF_DDS, (*ppTexture), 0);

	D3D::SetCustomColors();
}

/// <summary>
/// Generate Texture Middleware.
/// </summary>
/// <param name="pDevice"> - Device Pointer</param>
/// <param name="type"> - What type of texture should be created? (enum D3D::TextureType)</param>
void D3D::GenerateTextures(IDirect3DDevice9* pDevice, TextureType type) {
	ColorList colorSet;

	if (type == Random || type == Random_Solid) {
		for (int textIdx = 0; textIdx < randomTextureCount;textIdx++) {
			if (type == Random_Solid) {
				RSColor iniColor = GenerateRandomColor();

				for (int i = 0; i < 16; i++) 
					colorSet.push_back(iniColor);
			}
			else {
				for (int i = 0; i < 16; i++)
					colorSet.push_back(GenerateRandomColor());
			}

			GenerateTexture(pDevice, &randomTextures[textIdx], colorSet);
			randomTextureColors.push_back(colorSet);

			colorSet.clear();
		}
	}
	else if (type == Rainbow) {
		float h = 0.0f, stringOffset = 20.0f;
		int currTexture = 0;

		Color c;
		ColorList colorsRainbow;

		while (h < 360.f) {
			h += rainbowSpeed;

			for (int i = 0; i < 6;i++) { // There's two extra colors per string, so we may need to think about this a bit more
				c.setH(h + (stringOffset * i));

				if (c.r > 1.0f)
					c.r = c.r - (c.r - 1.0f);
				if (c.r < .0f)
					c.r *= -1;

				if (c.g > 1.0f)
					c.g = c.g - (c.g - 1.0f);
				if (c.g < .0f)
					c.g *= -1;

				if (c.b > 1.0f)
					c.b = c.b - (c.b - 1.0f);
				if (c.b < .0f)
					c.b *= -1;

				colorsRainbow.push_back(c);
			}

			for (int i = 0; i < 2;i++)
				colorsRainbow.push_back(c);

			colorSet.insert(colorSet.begin(), colorsRainbow.begin(), colorsRainbow.end()); // Both CB and regular colors will still look the same in rainbow mode
			colorSet.insert(colorSet.end(), colorsRainbow.begin(), colorsRainbow.end());

			GenerateTexture(pDevice, &rainbowTextures[currTexture], colorSet);

			colorSet.clear();
			colorsRainbow.clear();

			currTexture++;
			//h += rainbowSpeed;
		}
	}
	else if (type == Strings) {
		ColorList colorsN = Settings::GetStringColors(false);
		ColorList colorsCB = Settings::GetStringColors(true);

		colorSet.insert(colorSet.begin(), colorsN.begin(), colorsN.end());
		colorSet.insert(colorSet.end(), colorsCB.begin(), colorsCB.end());

		GenerateTexture(pDevice, &customStringColorTexture, colorSet);
	}
	else if (type == Notes) {
		ColorList colorsN = Settings::GetNoteColors(false);
		ColorList colorsCB = Settings::GetNoteColors(true);

		colorSet.insert(colorSet.begin(), colorsN.begin(), colorsN.end());
		colorSet.insert(colorSet.end(), colorsCB.begin(), colorsCB.end());

		GenerateTexture(pDevice, &customNoteColorTexture, colorSet);
	}
	else if (type == Noteway) {
		colorSet.insert(colorSet.begin(), Settings::ConvertHexToColor(Settings::ReturnNotewayColor("CustomHighwayNumbered")));
		colorSet.insert(colorSet.end(), Settings::ConvertHexToColor(Settings::ReturnNotewayColor("CustomHighwayUnNumbered")));

		GenerateTexture(pDevice, &notewayTexture, colorSet, 256, 32, 16, 2);
	}
	else if (type == Gutter) {
		colorSet.insert(colorSet.begin(), Settings::ConvertHexToColor(Settings::ReturnNotewayColor("CustomHighwayGutter")));
		GenerateTexture(pDevice, &gutterTexture, colorSet, 256, 16, 16, 1);
	}
	else if (type == FretNums) {
		colorSet.insert(colorSet.begin(), Settings::ConvertHexToColor(Settings::ReturnNotewayColor("CustomFretNubmers")));
		GenerateTexture(pDevice, &fretNumTexture, colorSet, 256, 16, 16, 1);
	}
}

/// <summary>
/// Generate a texture with one color.
/// </summary>
/// <param name="pDevice"> - Device Pointer</param>
/// <param name="ppD3Dtex"> - Output Texture</param>
/// <param name="colour32"> - Color for Texture</param>
/// <returns>E_FAIL if a texture can't be created, S_OK if it was created.</returns>
HRESULT D3D::GenerateSolidTexture(IDirect3DDevice9* pDevice, IDirect3DTexture9** ppD3Dtex, DWORD colour32) {
	if (FAILED(pDevice->CreateTexture(8, 8, 1, 0, D3DFMT_A4R4G4B4, D3DPOOL_MANAGED, ppD3Dtex, NULL)))
		return E_FAIL;

	WORD colour16 = ((WORD)((colour32 >> 28) & 0xF) << 12)
		| (WORD)(((colour32 >> 20) & 0xF) << 8)
		| (WORD)(((colour32 >> 12) & 0xF) << 4)
		| (WORD)(((colour32 >> 4) & 0xF) << 0);

	D3DLOCKED_RECT d3dlr;
	(*ppD3Dtex)->LockRect(0, &d3dlr, 0, 0);
	WORD* pDst16 = (WORD*)d3dlr.pBits;

	for (int xy = 0; xy < 8 * 8; xy++)
		*pDst16++ = colour16;

	(*ppD3Dtex)->UnlockRect(0);

	return S_OK;
}
