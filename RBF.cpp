#include "RBF.h"

double* initCreateRbf(int nbSamples) {
	double* weights = (double*)malloc(sizeof(double) * nbSamples);
	srand(time(NULL));
	for (int i = 0; i < nbSamples; i++)
	{
		weights[i] = generateDouble();
	}

	return weights;
}

void rbfClassicTraining(double* weights, double* inputs, double* output, int nbSamples, int width, double gamma) {
	int inputsSize = nbSamples / width;

	Eigen::MatrixXd xMatrix(inputsSize, inputsSize);

	for (int i = 0; i < inputsSize; i++)
	{
		for (int j = 0; j < inputsSize; j++)
		{
			double inputsPowX = pow(inputs[j * width] - inputs[i * width], 2);
			double inputsPowY = pow(inputs[j * (width + 1)] - inputs[i * (width + 1)], 2);
			double compute = -gamma * (inputsPowX + inputsPowY);
			xMatrix(i, j) = exp(compute);
		}
	}

	Eigen::MatrixXd yMatrix(inputsSize, 1);

	for (int i = 0; i < inputsSize; i++)
	{
		yMatrix(i, 0) = output[i];
	}

	Eigen::MatrixXd wMatrix = xMatrix.inverse() * yMatrix;

	for (int i = 0; i < inputsSize; i++)
	{
		weights[i] = wMatrix(i, 0);
	}
}

double rbfClassicClassify(double* weights, double* inputs, double* testInput, int nbSamples, int width, double gamma) {
	int inputSize = nbSamples / width;
	
	double sumOutput = 0.0;

	for (int i = 0; i < inputSize; i++)
	{
		double inputsPowX = pow(inputs[i * width] - testInput[0], 2);
		double inputsPowY = pow(inputs[i * (width + 1)] - testInput[1], 2);
		double compute = -gamma * (inputsPowX + inputsPowY);
		sumOutput += weights[i] * exp(compute);
	}

	return sumOutput >= 0.0 ? 1.0 : -1.0;
}