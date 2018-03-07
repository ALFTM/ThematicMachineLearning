#include <cstdlib>
#include <cmath>
#include "Perceptron.h"


Perceptron::Perceptron() {
	int i = 0;

	this->weights[0] = 0.831085516061208;
	this->weights[1] = 0.454390437088157;
	this->weights[2] = 0.454390437088157;


	for (i = 0; i < 30; i++) {
		if (i < 13) {
			this->outputs[i] = -1;
		}
		else {
			this->outputs[i] = 1;
		}

		std::cout << "ARRAY INIT INDEX : " << i << " VALUE : " << this->outputs[i] << endl;
	}
}

Perceptron::~Perceptron() {

}

void Perceptron::startCompute() {
	double globalError;
	int loop = 0;

	double tab[30][2] = {
		{ 0.72, 0.82 },{ 0.91, -0.69 },{ 0.46, 0.80 },
		{ 0.03, 0.93 },{ 0.12, 0.25 },{ 0.96, 0.47 },
		{ 0.79, -0.75 },{ 0.46, 0.98 },{ 0.66, 0.24 },
		{ 0.72, -0.15 },{ 0.35, 0.01 },{ -0.16, 0.84 },
		{ -0.04, 0.68 },{ -0.11, 0.10 },{ 0.31, -0.96 },
		{ 0.00, -0.26 },{ -0.43, -0.65 },{ 0.57, -0.97 },
		{ -0.47, -0.03 },{ -0.72, -0.64 },{ -0.57, 0.15 },
		{ -0.25, -0.43 },{ 0.47, -0.88 },{ -0.12, -0.90 },
		{ -0.58, 0.62 },{ -0.48, 0.05 },{ -0.79, -0.92 },
		{ -0.42, -0.09 },{ -0.76, 0.65 },{ -0.77, -0.76 } 
	};

	do {
		globalError = 0;
		for (int i = 0; i < 30; i++) {

			int output = 0;
			/*
			double x = this->inputs[i][0];
			double y = this->inputs[i][1];
			double z = this->inputs[i][2];
			*/

			double x = tab[i][0];
			double y = tab[i][1];

			output = this->computeOutput(x, y, 0.0);

			//std::cout << "Output value : " << output << endl;
			//std::cout << "Current output value : " << this->outputs[i] << endl;

			int error = this->outputs[i] - output;

			//std::cout << "Error value : " << error << endl;


			if (error != 0) {
				// Update weights
				// this->updateWeights(error, i);
				this->updateWeights(error, x, y);
			}

			globalError += abs(error);
		}

	loop++;
	cout << "Loop : " << loop << " Error : " << globalError << endl;
	// system("PAUSE");
	} while (globalError != 0);

	cout << "DONE!" << endl;
}

void Perceptron::updateWeights(double error, int inputsIndex) {
	for (int i = 0; i < 2; i++) {
	}
}

void Perceptron::updateWeights(double error, double x, double y) {
	this->weights[0] += 0.1 * error * x;
	this->weights[1] += 0.1 * error * y;


}

int Perceptron::computeOutput(double x, double y, double z) {
	double sum = 0; 
	sum = (x * this->weights[0]) + (y * this->weights[1]);

	//std::cout << "weights x : " << this->weights[0] << endl;
	//std::cout << "weights y : " << this->weights[1] << endl;

	//std::cout << " x : " << x << endl;
	//std::cout << " y : " << y << endl;

	return sum >= 0.0 ? 1 : -1;
}

double Perceptron::generateDouble() {
	double fMin = 0.5;
	double fMax = 4.5;
	double f;


	f = (double)rand() / RAND_MAX;
	return fMin + f * (fMax - fMin);
}

