#pragma once

#include <iostream>
#include <vector>
#include "math.h"

using namespace std;

class Perceptron {
private:
	double weights[3];
	int outputs[30];
	int iteration;

public:
	Perceptron();
	~Perceptron();
	int computeOutput(double x, double y, double z);
	void startCompute();
	double generateDouble();
	void updateWeights(double error, int inputsIndex);
	void updateWeights(double error, double x, double y);
	
};

