#include <cstdlib>
#include <cmath>
#include "Perceptron.h"


// region Coord implementation
Coord3d::Coord3d() {

};

Coord3d::Coord3d(double x, double y, double z) {
	this->x = x;
	this->y = y;
	this->z = z;
};

void Coord3d::setCoord(double x, double y, double z) {
	this->x = x;
	this->y = y;
	this->z = z;
};

double Coord3d::X() {
	return this->x;
};

double Coord3d::Y() {
	return this->y;
};

double Coord3d::Z() {
	return this->z;
};
// endregion



Perceptron::Perceptron() {
	int i = 0;
	/*
	for (i = 0; i < 10; i++) {
		for (int j = 0; j < 3; j++) {
			this->inputs[i][j] = this->generateDouble();
		}
	}
	*/

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

	/*
	for (i = 0; i < 3; i++) {
	this->weights[i] = this->generateDouble();
	}
	*/

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

		cout << "ARRAY INIT INDEX : " << i << " VALUE : " << this->outputs[i] << endl;
	}
};

void Perceptron::startCompute() {
	int inputsLength = sizeof(this->inputs) / sizeof(double);
	cout << "ARRAY SIZE : " << inputsLength << endl;
	double globalError = 0;

	do {
		globalError = 0;
		for (int i = 0; i < 10; i++) {
			int output = 0;
			double x = this->inputs[i][0];
			double y = this->inputs[i][1];
			double z = this->inputs[i][2];
			output = this->computeOutput(x, y, z);

			cout << "OUTPUT  : " << output << endl;

			double error = this->outputs[i] - output;

			cout << "ERROR  : " << error << endl;

			if (error != 0) {
				// Update weights
				this->updateWeights(error, i);
			}

			globalError += abs(error);

			cout << "Global Error : " << globalError << endl;
		}
	} while (globalError != 0);

	cout << "Compute done" << endl;

};

void Perceptron::updateWeights(double error, int inputsIndex) {

	int i = 0;

	for (; i < 3; i++) {
		this->weights[i] += 0.1 * error * this->inputs[inputsIndex][i];
	}

};

int Perceptron::computeOutput(double x, double y, double z) {
	int sum = 0; 
	sum = (x * this->weights[0]) + (y * this->weights[1]) + (z * this->weights[2]);

	return sum >= 0 ? 1 : -1;
};

double Perceptron::generateDouble() {
	double fMin = 0.5;
	double fMax = 4.5;
	double f;


	f = (double)rand() / RAND_MAX;
	return fMin + f * (fMax - fMin);
};

