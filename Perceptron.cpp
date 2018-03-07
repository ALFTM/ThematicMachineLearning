#include <cstdlib>
#include <cmath>
#include "Perceptron.h"

using namespace std;

Perceptron::Perceptron() {

}

Perceptron::Perceptron(double* inputs, int* outputs, int height, int width) {
	this->height = height;
	this->width = width;
	this->inputs = inputs;
	this->outputs = outputs;

	this->weights = (double*)malloc(sizeof(double) * (this->width + 1));

	for (int i = 0; i < this->width + 1; i++) {
		this->weights[i] = this->generateDouble();
		cout << " W : " << this->weights[i] << endl;
	}
}

Perceptron::~Perceptron() {
	free(this->weights);
}

void Perceptron::startCompute() {
	double globalError;
	int loop = 0;
	int j = 0;

	do {
		globalError = 0;
		j = 0;
		for (int i = 0; i < this->height - this->width; i += this->width) {

			int output = 0;


			output = this->computeOutput(i);

			double error = this->outputs[j] - output;


			if (error != 0) {
				// Update weights
				this->updateWeights(error, i);
			}

			globalError += abs(error);
			j++;
		}

	loop++;
	cout << "Loop : " << loop << " Error : " << globalError << endl;
	} while (globalError != 0);

	cout << "DONE!" << endl;
}

void Perceptron::updateWeights(double error, int index) {
	for (int i = 1; i < this->width + 1; i++) {
		this->weights[i] += 0.1 * error * this->inputs[index + i - 1];
	}

	this->weights[0] += 0.1 * error * 1;
}

void Perceptron::updateWeights(double error, double x, double y) {
	this->weights[0] += 0.1 * error * x;
	this->weights[1] += 0.1 * error * y;


}

int Perceptron::computeOutput(int index) {
	double sum = this->weights[0]; 

	for (int i = 1; i < this->width + 1; i++) {
		sum += (this->inputs[index + i - 1] * this->weights[i]);
	}

	return sum >= 0.0 ? 1 : -1;
}

double Perceptron::generateDouble() {
	double high = 0.99;
	double low = -0.99;
	double range = (high- low);
	double num = fmod(rand(), range) + low;
	return num;
}

