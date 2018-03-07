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
	double* perceptronLinearInit(int height, int width) {
		double* weights = initTraining(height, width);
		return weights;
	}

	_declspec(dllexport)
	double* perceptronLinearTraining(double* weights, double* inputs, int* outputs, int height, int width) {
		srand(time(NULL));
		weights = startTraining(weights, inputs, outputs, height, width);
		return weights;
	}

	_declspec(dllexport)
	int perceptronLinearClassify(double* weights, double* inputs, int width) {
		int angle = output(weights, inputs, width);
		return angle;
	}

	_declspec(dllexport)
	void freePtr(double* weights) {
		freeWeights(weights);
	}
}