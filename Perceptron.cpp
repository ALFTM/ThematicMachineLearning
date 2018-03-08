#include <cstdlib>
#include <cmath>
#include "Perceptron.h"

using namespace std;

double* initTraining(int width) {
	double* weights = (double*)malloc(sizeof(double) * (width + 1));

	/*for (int i = 0; i < width + 1; i++) {
		weights[i] = generateDouble();
		cout << " W : " << weights[i] << endl;
	}*/

	weights[0] = 0.5;
	weights[1] = -2.0;
	weights[2] = 1.0;

	return weights;
}

double generateDouble() {
	double high = 0.99;
	double low = -0.99;
	double range = (high - low);
	double num = fmod(rand(), range) + low;
	return num;
}

double* startTraining(double* weights, double* inputs, double* outputs, int height, int width) {
	training(weights, inputs, outputs, height, width);

	return weights;
}

void training(double* weights, double* inputs, double* outputs, int height, int width) {
	double globalError = 0;
	int loop = 0;
	int j = 0;

	do {
		globalError = 0;
		j = 0;
		for (int i = 0; i < height * width; i += width) {

			double output = 0;

			output = computeOutput(weights, inputs, width, i);

			double error = outputs[j] - output;

			if (error != 0.0) {
				// Update weights
				updateWeights(weights, inputs, error, width, i);
			}

			globalError += abs(error);
			j++;
		}

		loop++;
		cout << "Loop : " << loop << " Error : " << globalError << endl;
	} while (globalError != 0 && loop < 100000);

	cout << "DONE!" << endl;
}

double computeOutput(double* weights, double* inputs, int width, int index) {
	double sum = weights[0]; 

	for (int i = 1; i < width + 1; i++) {
		sum += (inputs[index + i - 1] * weights[i]);
	}

	return sum >= 0.0 ? 1.0 : -1.0;
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

double* linearRegressionTrain(double* inputsX, double* inputsY, int sizeInputs) {
	double avgX = sumInputs(inputsX, sizeInputs);
	double avgY = sumInputs(inputsY, sizeInputs);

	double sum_pow_XSubstractAvgX = 0.0;
	for (int i = 0; i < sizeInputs; i++) {
		sum_pow_XSubstractAvgX += (inputsX[i] - avgX) * (inputsX[i] - avgX);
	}

	double sum_XSubstractAvgX_YSubstractAvgY = 0.0;
	for (int i = 0; i < sizeInputs; i++) {
		sum_XSubstractAvgX_YSubstractAvgY += (inputsX[i] - avgX) * (inputsY[i] - avgY);
	}

	double a = sum_XSubstractAvgX_YSubstractAvgY / sum_pow_XSubstractAvgX;

	double b = avgY - (a * avgX);

	return new double[2]{ a, b };
}

int linearRegressionPredict(double* equation, double x, double y) {
	double a = equation[0];
	double b = equation[1];
	
	double yPredicted = (a * x) + b;

	return yPredicted >= y ? -1 : 1;
}

double sumInputs(double* inputs, int size) {
	double sum = 0.0;
	
	for (int i = 0; i < size; i++) {
		sum += inputs[i];
	}

	return sum / size;
}