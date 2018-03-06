#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "GlaDOSInteractions.h"
#include "Perceptron.h"

/*
Start point to enter
*/

extern "C" {
	_declspec(dllexport)
	int glaDOS() {
		glaDOSStartTalking(1000);
		Perceptron toto;
		toto.startCompute();
		return 0;
	}
}
