#pragma once

#include <iostream>
#include <vector>
#include "math.h"

using namespace std;

class Perceptron {
private:
	double inputs[10][3];
	double weights[3];
	int outputs[10];
	int iteration;

public:
	Perceptron();
	int computeOutput(double x, double y, double z);
	void startCompute();
	double generateDouble();
	void updateWeights(double error, int inputsIndex);
	
};

