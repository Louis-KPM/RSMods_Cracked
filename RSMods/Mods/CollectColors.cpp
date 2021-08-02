#include "CollectColors.hpp"

/*
This is probably pretty janky, but it's based on the research I did below
https://docs.google.com/spreadsheets/d/1X3UjY68Z5oOuZpV_UpckOy-G-XZe7lWaskc31C7FxOs/edit?usp=sharing

Feel free to modify this pile of shit, I don't know how we wanted it formatted.
*/


/// <summary>
/// Convert input color (from INI) to Ambient String Color
/// </summary>
/// <param name="stringHue"> - Hue of input color</param>
/// <param name="isColorBlindMode"> - Should we make a ColorBlind color</param>
Color CollectColors::GetAmbientStringColor(int stringHue, bool isColorBlindMode) {
	if (!isColorBlindMode)
		H = stringHue + 4;
	else
		H = stringHue - 1;

	S = 0.423f;
	L = 0.558f;

	return GetColor();
}

/// <summary>
/// Convert input color (from INI) to Disabled String Color
/// </summary>
/// <param name="stringHue"> - Hue of input color</param>
/// <param name="stringSaturation"> - Saturation of input color</param>
/// <param name="stringLightness"> - Lightness of input color</param>
/// <param name="isColorBlindMode"> - Should we make a ColorBlind color</param>
Color CollectColors::GetDisabledStringColor(int stringHue, float stringSaturation, float stringLightness, bool isColorBlindMode) {
	if (!isColorBlindMode) {
		S = stringSaturation - (float).144;
		L = stringLightness / (float)3.136;
	}
	else {
		S = stringSaturation - (float).428;
		L = stringLightness / (float)2.812;
	}

	H = stringHue;

	return GetColor();
}

/// <summary>
/// Convert input color (from INI) to Glow String Color
/// </summary>
/// <param name="stringHue"> - Hue of input color</param>
Color CollectColors::GetGlowStringColor(int stringHue) {
	H = stringHue - 4;
	S = 1.0f;
	L = 0.5f;

	return GetColor();
}

/// <summary>
/// Convert input color (from INI) to Tuning Peg Color
/// </summary>
/// <param name="stringHue"> - Hue of input color</param>
/// <param name="isColorBlindMode"> - Should we make a ColorBlind color</param>
Color CollectColors::GetTuningPegColor(int stringHue, bool isColorBlindMode) {
	if (!isColorBlindMode) {
		H = stringHue - 4;
		L = 0.3385f;
	}
	else {
		H = stringHue;
		L = 0.3453f;
	}

	S = 1.0f;

	return GetColor();
}

/// <summary>
/// Convert input color (from INI) to Peg Reset Color
/// </summary>
/// <returns>Always returns black</returns>
Color CollectColors::GetPegResetColor() {
	H = (int)0.0f;
	S = 0.0f;
	L = 0.0f;

	return GetColor();
}

/// <summary>
/// Convert input color (from INI) to Peg Success Color
/// </summary>
/// <param name="isColorBlindMode"> - Should we make a ColorBlind color</param>
/// <returns>Returns white if ColorBlind, black if not.</returns>
Color CollectColors::GetPegSuccessColor(bool isColorBlindMode) {
	if (!isColorBlindMode)
		L = 0.0f;
	else
		L = 1.0f;
	H = (int)0.0f;
	S = 0.0f;

	return GetColor();
}

/// <summary>
/// Convert input color (from INI) to Peg In-Tune Color
/// </summary>
/// <param name="stringHue"> - Hue of input color</param>
/// <param name="isColorBlindMode"> - Should we make a ColorBlind color</param>
Color CollectColors::GetPegInTuneColor(int stringHue, bool isColorBlindMode) {
	if (!isColorBlindMode)
		H = stringHue + 4;
	else
		H = stringHue - 1;

	S = 1.0f;
	L = 0.349f;

	return GetColor();
}

/// <summary>
/// Convert input color (from INI) to Peg Out-Tune Color
/// </summary>
/// <returns>Always returns white</returns>
Color CollectColors::GetPegOutTuneColor() {
	H = (int)0.0f;
	S = (int)0.0f;
	L = (int)1.0f;

	return GetColor();
}

/// <summary>
/// Convert input color (from INI) to Reg Text Indicator Color
/// </summary>
/// <param name="stringHue"> - Hue of input color</param>
/// <param name="isColorBlindMode"> - Should we make a ColorBlind color</param>
Color CollectColors::GetRegTextIndicatorColor(int stringHue, bool isColorBlindMode) {
	if (!isColorBlindMode) {
		H = stringHue + 3;
		L = 0.625f;
	}
	else {
		H = stringHue + 2;
		L = 0.624f;
	}

	S = 1.0f;

	return GetColor();
}

/// <summary>
/// Convert input color (from INI) to Fork Particles Color
/// </summary>
/// <param name="stringHue"> - Hue of input color</param>
/// <param name="isColorBlindMode"> - Should we make a ColorBlind color</param>
Color CollectColors::GetRegForkParticlesColor(int stringHue, bool isColorBlindMode) {
	if (!isColorBlindMode)
		L = 0.625f;
	else
		L = 0.624f;

	H = stringHue + 5;
	S = 1.0f;

	return GetColor();
}

/// <summary>
/// Convert input color (from INI) to Noteway Normal Color
/// </summary>
/// <param name="stringHue"> - Hue of input color</param>
/// <param name="stringSaturation"> - Saturation of input color</param>
/// <param name="stringLightness"> - Lightness of input color</param>
/// <param name="isColorBlindMode"> - Should we make a ColorBlind color</param>
Color CollectColors::GetNotewayNormalColor(int stringHue, float stringSaturation, float stringLightness, bool isColorBlindMode) {
	if (!isColorBlindMode) {
		H = stringHue + 5;
		S = 1.0f;
		L = .5f;
	}
	else {
		H = stringHue;
		S = stringSaturation;
		L = stringLightness;
	}

	return GetColor();
}

/// <summary>
/// Convert input color (from INI) to Noteway Accent Color
/// </summary>
/// <param name="stringHue"> - Hue of input color</param>
/// <param name="isColorBlindMode"> - Should we make a ColorBlind color</param>
Color CollectColors::GetNotewayAccentColor(int stringHue, bool isColorBlindMode) {
	if (!isColorBlindMode) {
		H = stringHue + 3;
		S = 0.909f;
		L = 0.761f;
	}
	else {
		H = (int)0.0f;
		S = 0.0f;
		L = 1.0f;
	}

	return GetColor();
}

/// <summary>
/// Convert input color (from INI) to Noteway Preview Color
/// </summary>
/// <param name="stringHue"> - Hue of input color</param>
/// <param name="isColorBlindMode"> - Should we make a ColorBlind color</param>
Color CollectColors::GetNotewayPreviewColor(int stringHue, bool isColorBlindMode) {
	if (!isColorBlindMode) {
		H = stringHue - 1;
		S = 0.219f;
		L = 0.206f;
	}
	else {
		H = stringHue;
		S = 0.212f;
		L = 0.204f;
	}

	return GetColor();
}

/// <summary>
/// Convert input color (from INI) to Guitarcade Main Color
/// </summary>
/// <param name="stringHue"> - Hue of input color</param>
/// <param name="stringNumber"> - String# from thickest to thinnest (zero-indexed)</param>
/// <param name="isColorBlindMode"> - Should we make a ColorBlind color</param>
Color CollectColors::GetGuitarcadeMainColor(int stringHue, int stringNumber, bool isColorBlindMode) {
	if (!isColorBlindMode)
		H = stringHue + 12;
	else
		H = stringHue - 4;

	S = 1.0f;

	if (stringNumber == 4) // B string (Normally lime green)
		L = 0.429f;
	else if (stringNumber == 5) // e string (Normally purple-ish)
		L = 0.375f;
	else // E, A, D, & G strings
		L = 0.50f;

	return GetColor();
}

/// <summary>
/// Convert input color (from INI) to Guitarcade Additive Color
/// </summary>
/// <param name="stringHue"> - Hue of input color</param>
/// <param name="stringNumber"> - String# from thickest to thinnest (zero-indexed)</param>
/// <param name="isColorBlindMode"> - Should we make a ColorBlind color</param>
Color CollectColors::GetGuitarcadeAdditiveColor(int stringHue, int stringNumber, bool isColorBlindMode) {
	if (!isColorBlindMode)
		H = stringHue + 12;
	else
		H = stringHue + 2;

	S = 1.0f;

	if (stringNumber == 4) // B string (Normally lime green)
		L = 0.429f;
	else if (stringNumber == 5) // e string (Normally purple-ish)
		L = 0.375f;
	else // E, A, D, & G strings
		L = 0.50f;

	return GetColor();
}

/// <summary>
/// Convert input color (from INI) to Guitarcade UI Color
/// </summary>
/// <param name="stringHue"> - Hue of input color</param>
/// <param name="stringNumber"> - String# from thickest to thinnest (zero-indexed)</param>
/// <param name="isColorBlindMode"> - Should we make a ColorBlind color</param>
Color CollectColors::GetGuitarcadeUIColor(int stringHue, int stringNumber, bool isColorBlindMode) {
	if (!isColorBlindMode)
		H = stringHue + 12;
	else
		H = stringHue + 2;

	S = 1.0f;

	if (stringNumber == 4) // B string (Normally lime green)
		L = 0.429f;
	else if (stringNumber == 5) // e string (Normally purple-ish)
		L = 0.375f;
	else // E, A, D, & G strings
		L = 0.50f;

	return GetColor();
}

// Functions

/// <param name="fR"> - Red</param>
/// <param name="fG"> - Green</param>
/// <param name="fB"> - Blue</param>
/// <returns>Lowest value</returns>
float CollectColors::Min(float fR, float fG, float fB) {
	float fMin = fR;
	if (fG < fMin)
	{
		fMin = fG;
	}
	if (fB < fMin)
	{
		fMin = fB;
	}
	return fMin;
}

/// <param name="fR"> - Red</param>
/// <param name="fG"> - Green</param>
/// <param name="fB"> - Blue</param>
/// <returns>Highest value</returns>
float CollectColors::Max(float fR, float fG, float fB) {
	float fMax = fR;
	if (fG > fMax)
	{
		fMax = fG;
	}
	if (fB > fMax)
	{
		fMax = fB;
	}
	return fMax;
}

/// <summary>
/// Convert RGB to HSL. From pseudocode in Agoston's Computer Graphics and Geometric Modeling: Implementation and Algorithms
/// </summary>
/// <param name="R"> - Red **INPUT**</param>
/// <param name="G"> - Green **INPUT**</param>
/// <param name="B"> - Blue **INPUT**</param>
/// <param name="H"> - Hue **OUTPUT**</param>
/// <param name="S"> - Saturation **OUTPUT**</param>
/// <param name="L"> - Lightness **OUTPUT**</param>
void CollectColors::RGB2HSL(float R, float G, float B, int& H, float& S, float& L) { //R,G,B [0,1], H [0,360], S,L [0,1] 
	float min = Min(R, G, B);
	float max = Max(R, G, B);
	float d, h;

	L = (min + max) / 2;

	if (max != min) {
		d = max - min;

		S = (L <= 0.5) ? (d / (min + max)) : (d / (2 - max - min));

		if (R == max)
			h = (G - B) / d;
		else if (G == max)
			h = 2 + (B - R) / d;
		else if (B == max)
			h = 4 + (R - G) / d;
		else
			h = 0.0f;

		H = 60 * h;

		if (H < 0)
			H += 360;
	}
}

/// <summary>
/// Convert HSL to RGB.  From pseudocode in Agoston's Computer Graphics and Geometric Modeling: Implementation and Algorithms
/// </summary>
/// <param name="H"> - Hue **INPUT**</param>
/// <param name="S"> - Saturation **INPUT**</param>
/// <param name="L"> - Lightness **INPUT**</param>
/// <param name="R"> - Red **OUTPUT**</param>
/// <param name="G"> - Green **OUTPUT**</param>
/// <param name="B"> - Blue **OUTPUT**</param>
void CollectColors::HSL2RGB(float H, float S, float L, float& R, float& G, float& B) {
	float v, min, sv, fract, vsf, mid1, mid2;
	int sextant;

	v = (float)(((double)L <= 0.5) ? ((double)L * (1.0 + (double)S)) : ((double)L + (double)S - (double)L * (double)S));

	if (v > 0) {
		min = 2 * L - v;
		sv = (v - min) / v;
		H = (H == 360) ? 0 : H / 60;

		sextant = (int)floor(H);
		fract = H - sextant;
		vsf = v * sv * fract;
		mid1 = min + vsf;
		mid2 = v - vsf;

		switch (sextant)
		{
			case 0: R = v; G = mid1; B = min; break;
			case 1: R = mid2; G = v; B = min; break;
			case 2: R = min; G = v; B = mid1; break;
			case 3: R = min; G = mid2; B = v; break;
			case 4: R = mid1; G = min; B = v; break;
			case 5: R = v; G = min; B = mid2; break;
		}
	}
	else {
		R = 0.0f;
		G = 0.0f;
		B = 0.0f;
	}
}

/// <summary>
/// Convert HSL to RGB
/// </summary>
Color CollectColors::GetColor() {
	HSL2RGB((float)H, S, L, R, G, B);
	return Color(R, G, B);
}

/// <summary>
/// Set Global Color
/// </summary>
void CollectColors::SetColors(RSColor color) {
	R = color.r;
	G = color.g;
	B = color.b;

	RGB2HSL(R, G, B, H, S, L);
}