#pragma once

#include <iostream>
#include <vector>
#include "math.h"

using namespace std;

class Perceptron {
private:
	double* inputs;
	double* weights;
	int* outputs;
	int width;
	int height;
	int iteration;

public:
	Perceptron();
	Perceptron(double* inputs, int* outputs, int height, int width);
	~Perceptron();
	int computeOutput(int index);
	void startCompute();
	double generateDouble();
	void updateWeights(double error, int index);
	void updateWeights(double error, double x, double y);
	
};

