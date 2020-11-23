#pragma once

#include "Windows.h"
#include <iostream>
#include <cstdlib>
#include <map>

#include "../Lib/Midi/RtMidi.h"

namespace Midi {
	void InitMidi();
	bool SendProgramChange(char programChange = '\000');
	bool SendControlChange(char toePosition = '\000');
};

// Midi Specifications
inline unsigned char programChangeStatus = 192, controlChangeStatus = 176, noteOnStatus = 144, noteOffStatus = 128;

// Pedal Specific

	// WHAMMY_DT
	inline int WHAMMY_DT_CC_CHANNEL = 11;
	inline std::map<char, char> WHAMMY_DT_activeBypassMap = {

		// Whammy
		{0, 21}, // +2 OCT
		{1, 22}, // +1 OCT
		{2, 23}, // +5th
		{3, 24}, // +4th
		{4, 25}, // -2nd
		{5, 26}, // -4th
		{6, 27}, // -5th
		{7, 28}, // -1 OCT
		{8, 29}, // -2 OCT
		{9, 30}, // Dive Bomb

		// Detune
		{10, 31}, // Deep
		{11, 32}, // Shallow

		// Harmony (Up Pos || Down Pos)
		{12, 33}, // +2nd || +3rd
		{13, 34}, // +b 3rd || +3rd
		{14, 35}, // +3rd || +4th
		{15, 36}, // +4th || +5th
		{16, 37}, // +5th || +6th
		{17, 38}, // +5th || +7th
		{18, 39}, // -4th || -3rd
		{19, 40}, // -5th || -4th
		{20, 41}, // -1 OCT || +1 OCT

		// Drop Tune Effect
		{42, 60}, // +1
		{43, 61}, // +2
		{44, 62}, // +3
		{45, 63}, // +4
		{46, 64}, // +5
		{47, 65}, // +6
		{48, 66}, // +7
		{49, 67}, // +OCT
		{50, 68}, // +OCT + Dry

		{51, 69}, // -OCT + Dry || Nice :eyes:
		{52, 70}, // -OCT
		{53, 71}, // -7
		{54, 72}, // -6
		{55, 73}, // -5
		{56, 74}, // -4
		{57, 75}, // -3
		{58, 76}, // -2
		{59, 77}, // -1
	};