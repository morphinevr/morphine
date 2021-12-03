#include <iostream>
#include "PSMovePair.h"

// rename the main method using some fuckery as seen in psmoveapi/src/utils/psmovecli.cpp
#define main psmovepair_main
extern "C" {
#include "vendor/psmoveapi/src/utils/psmovepair.c"
}
#undef main


namespace Morphine {

	/*
	* Pairs a PS Move using psmoveapi
	*/
	int PairPSMove() {

		return pair(NULL);
	}
}