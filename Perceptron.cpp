#include <cstdlib>
#include <cmath>
#include "Perceptron.h"


Perceptron::Perceptron() {
	int i = 0;

	for (i = 0; i < 10; i++) {
		if (i == 6) {
			this->inputs[i][0] = 3.0;
			this->inputs[i][1] = 4.0;
			this->inputs[i][2] = 0.0;
		}

		else if (i == 7) {
			this->inputs[i][0] = 2.0;
			this->inputs[i][1] = 4.0;
			this->inputs[i][2] = 0.0;
		}

		else if (i == 8) {
			this->inputs[i][0] = 2.0;
			this->inputs[i][1] = -4.0;
			this->inputs[i][2] = 0.0;
		}
		else {
			this->inputs[i][0] = 0.0;
			this->inputs[i][1] = 0.0;
			this->inputs[i][2] = 0.0;
		}
	}

	this->weights[0] = 0.831085516061208;
	this->weights[1] = 0.454390437088157;
	this->weights[2] = 0.454390437088157;


	for (i = 0; i < 10; i++) {
		if (i < 5) {
			this->outputs[i] = -1;
		}
		else {
			this->outputs[i] = 1;
		}

		std::cout << "ARRAY INIT INDEX : " << i << " VALUE : " << this->outputs[i] << endl;
	}
};

void Perceptron::startCompute() {
	double globalError;
	int loop = 0;

	do {
		globalError = 0;
		for (int i = 0; i < 10; i++) {

			int output = 0;
			double x = this->inputs[i][0];
			double y = this->inputs[i][1];
			double z = this->inputs[i][2];

			output = this->computeOutput(x, y, z);

			double error = this->outputs[i] - output;


			if (error != 0) {
				// Update weights
				this->updateWeights(error, i);
			}

			globalError += abs(error);
		}

		loop++;
	} while (globalError != 0);
};

void Perceptron::updateWeights(double error, int inputsIndex) {

	int i = 0;

	for (; i < 2; i++) {
		this->weights[i] += 0.1 * error * this->inputs[inputsIndex][i];
	}

};

int Perceptron::computeOutput(double x, double y, double z) {
	int sum = 0; 
	sum = (x * this->weights[0]) + (y * this->weights[1]);

	return sum >= 0 ? 1 : -1;
};

double Perceptron::generateDouble() {
	double fMin = 0.5;
	double fMax = 4.5;
	double f;


	f = (double)rand() / RAND_MAX;
	return fMin + f * (fMax - fMin);
};

