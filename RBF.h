#pragma once

#include <cstdlib>
#include <time.h>
#include <math.h>
#include "Perceptron.h"
#include "Eigen\Eigen\Dense"

double* initCreateRbf(int);
void rbfClassicTraining(double*, double*, double*, int, int, double);
double rbfClassicClassify(double*, double*, double*, int, int, double);
double rbfClassicPredict(double*, double*, double*, int, int, double);