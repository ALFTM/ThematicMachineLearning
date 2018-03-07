#pragma once

#include <iostream>
#include <vector>
#include "math.h"

double* initTraining(int, int);
double generateDouble();
double* startTraining(double*, double*, int*, int, int);
void training(double*, double*, int*, int, int);
int computeOutput(double*, double*, int, int);
int output(double*, double*, int);
void updateWeights(double*, double*, double, int, int);
void freeWeights(double*);