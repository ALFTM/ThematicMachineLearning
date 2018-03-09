#pragma warning(disable:4996)
#define _SCL_SECURE_NO_WARNINGS
#include <cstdlib>
#include "RBF.h"

int main() {
	double* inputs = (double*)malloc(sizeof(double) * 60);
	double* outputs = (double*)malloc(sizeof(double) * 30);

	double tests[60] = {
		0.72, 0.82 ,  0.91, -0.69 ,  0.46, 0.80 ,
		0.03, 0.93 , 0.12, 0.25 , 0.96, 0.47 ,
		0.79, -0.75 , 0.46, 0.98 , 0.66, 0.24 ,
		0.72, -0.15 , 0.35, 0.01 , -0.16, 0.84,
		-0.04, 0.68 ,  -0.11, 0.10 ,  0.31, -0.96 ,
		0.0, -0.26 ,  -0.43, -0.65 ,  0.57, -0.97 ,
		-0.47, -0.03 ,  -0.72, -0.64,  -0.57, 0.15 ,
		-0.25, -0.43 ,  0.47, -0.88 ,  -0.12, -0.90 ,
		-0.58, 0.62 ,  -0.48, 0.05 , -0.79, -0.92 ,
		-0.42, -0.09 ,  -0.76, 0.65 ,  -0.77, -0.76 };

	double expect[30] = {
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

	for (int i = 0; i < 60; i++) {
		inputs[i] = tests[i];
	}

	for (int j = 0; j < 30; j++) {
		outputs[j] = expect[j];
	}

	double* weight = initCreateRbf(30);

	rbfClassicTraining(weight, inputs, outputs, 60, 2, 0.1);

	double coord[2];

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "X Y Output" << std::endl;

	for (double x = -1.0; x < 1.0; x+= 0.5) {
		for (double y = -1.0; y < 1.0; y += 0.5) {
			coord[0] = x;
			coord[1] = y;
			double out = rbfClassicClassify(weight, inputs, coord, 30, 2, 0.1);

			std::cout << "X, " << x << " Y, " << y << " : " << (out == 1 ? "Blue" : "Red") << std::endl;
		}
	}

	free(inputs);
	free(outputs);
	free(weight);


}