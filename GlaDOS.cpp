#include <time.h>
#include "GlaDOSInteractions.h"
#include "Perceptron.h"

/*
Start point to enter
*/

extern "C" {
	_declspec(dllexport)
	int glaDOS() {
		glaDOSStartTalking(1000);
		return 0;
	}

	_declspec(dllexport)
		double perceptron(double* inputs, int* outputs, int height, int width) {
		srand(time(NULL));
		Perceptron perceptron(inputs, outputs, height, width);
		perceptron.startCompute();
		return 0.0;
	}
}
