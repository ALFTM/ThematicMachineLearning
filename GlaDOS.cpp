#include <time.h>
#include "GlaDOSInteractions.h"
#include "Perceptron.h"
#include "RBF.h"

/*
Start point to enter
*/

extern "C" {
	_declspec(dllexport)
	double* perceptronLinearInit(int width) {
		double* weights = initTraining(width);
		return weights;
	}

	_declspec(dllexport)
	double* perceptronLinearTraining(double* weights, double* inputs, double* outputs, int height, int width) {
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

	_declspec(dllexport)
	void perceptronLinearRegressionTrain(double* weights, double* inputs, int width, int inputsLength, double* outputs, int outputsLength) {
		linearRegressionTrain(weights, inputs, width, inputsLength, outputs, outputsLength);
	}

	_declspec(dllexport)
	double perceptronLinearRegressionPredict(double* weights, double* inputs) {
		return linearRegressionPredict(weights, inputs);
	}

	_declspec(dllexport)
	double* perceptronLinearRegressionCreate(int width) {
		double* weight = linearRegressionCreate(width);
		return weight;
	}

	_declspec(dllexport)
	double* rbfNaiveClassicCreate(int nbSamples) {
		double* weight = initCreateRbf(nbSamples);
		return weight;
	}

	_declspec(dllexport)
	void rbfNaiveClassicTraining(double* weights, double* inputs, double* output, int nbSamples, int width, double gamma) {
		rbfClassicTraining(weights, inputs, output, nbSamples, width, gamma);
	}

	_declspec(dllexport)
	double rbfNaiveClassicClassify(double* weights, double* inputs, double* testInput, int nbSamples, int width, double gamma) {
		return rbfClassicClassify(weights, inputs, testInput, nbSamples, width, gamma);
	}
}