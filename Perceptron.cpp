#include <cstdlib>
#include <cmath>
#include "Perceptron.h"

using namespace std;

double* initTraining(int height, int width) {
	double* weights = (double*)malloc(sizeof(double) * (width + 1));

	for (int i = 0; i < width + 1; i++) {
		weights[i] = generateDouble();
		cout << " W : " << weights[i] << endl;
	}

	return weights;
}

double generateDouble() {
	double high = 0.99;
	double low = -0.99;
	double range = (high - low);
	double num = fmod(rand(), range) + low;
	return num;
}

double* startTraining(double* weights, double* inputs, int* outputs, int height, int width) {
	training(weights, inputs, outputs, height, width);

	return weights;
}

void training(double* weights, double* inputs, int* outputs, int height, int width) {
	double globalError = 0;
	int loop = 0;
	int j = 0;

	do {
		globalError = 0;
		j = 0;
		for (int i = 0; i < height - width; i += width) {

			int output = 0;

			output = computeOutput(weights, inputs, width, i);

			double error = outputs[j] - output;

			if (error != 0) {
				// Update weights
				updateWeights(weights, inputs, error, width, i);
			}

			globalError += abs(error);
			j++;
		}

		loop++;
		cout << "Loop : " << loop << " Error : " << globalError << endl;
	} while (globalError != 0);

	cout << "DONE!" << endl;
}

int computeOutput(double* weights, double* inputs, int width, int index) {
	double sum = weights[0]; 

	for (int i = 1; i < width + 1; i++) {
		sum += (inputs[index + i - 1] * weights[i]);
	}

	return sum >= 0.0 ? 1 : -1;
}

int output(double* weights, double* inputs, int width) {
	double sum = weights[0];

	for (int i = 1; i < width + 1; i++) {
		sum += (inputs[i - 1] * weights[i]);
	}

	return sum >= 0.0 ? 1 : -1;
}

void updateWeights(double* weights, double* inputs, double error, int width, int index) {
	for (int i = 1; i < width + 1; i++) {
		weights[i] += 0.1 * error * inputs[index + i - 1];
	}

	weights[0] += 0.1 * error * 1;
}

void freeWeights(double* weights) {
	if (NULL != weights)
		free(weights);
}