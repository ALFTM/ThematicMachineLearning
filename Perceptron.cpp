#include <cstdlib>
#include <cmath>
#include "Perceptron.h"
#include "Eigen/Eigen/Dense"

using namespace std;

double* initTraining(int width) {
	double* weights = (double*)malloc(sizeof(double) * (width + 1));

	/*for (int i = 0; i < width + 1; i++) {
		weights[i] = generateDouble();
		cout << " W : " << weights[i] << endl;
	}*/

	weights[0] = 0.0;
	weights[1] = 1.0;
	weights[2] = 2.0;

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

double* linearRegressionCreate(int width) {
	double* weights = (double*)malloc(sizeof(double) * (width + 1));

	for (int i = 0; i < width + 1; i++) {
		weights[i] = 0.0;
	}

	return weights;
}

void linearRegressionTrain(double* weights, double* inputs, int width, int inputsLength, double* outputs, int outputsLength) {
	int wSize = width + 1;

	Eigen::MatrixXd xMatrix(inputsLength / width, width + 1);

	for (int i = 0; i < inputsLength / width; i++) {
		xMatrix(i, 0) = 1;
		for (int j = 0; j < width; j++) {
			xMatrix(i, j + 1) = inputs[i * width + j];
		}
	}

	Eigen::MatrixXd yMatrix(outputsLength, 1);
	for (int i = 0; i < outputsLength; i++) {
		yMatrix(i, 0) = outputs[i];
	}

	Eigen::MatrixXd xTransposed = xMatrix.transpose();
	Eigen::MatrixXd wMatrix = ((xTransposed * xMatrix).inverse() * xTransposed) * yMatrix;

	for (int i = 0; i < wSize; i++) {
		weights[i] = wMatrix(i, 0);
	}
}

double linearRegressionPredict(double* weight, double* inputs) {
	return weight[0] + (weight[1] * inputs[0]) + (weight[2] * inputs[1]);
}