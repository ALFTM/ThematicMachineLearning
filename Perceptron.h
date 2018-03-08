#pragma once

#include <iostream>
#include <vector>
#include "math.h"

double* initTraining(int);
double generateDouble();
double* startTraining(double*, double*, double*, int, int);
void training(double*, double*, double*, int, int);
double computeOutput(double*, double*, int, int);
int output(double*, double*, int);
void updateWeights(double*, double*, double, int, int);
void freeWeights(double*);

double* linearRegressionCreate(int);
void linearRegressionTrain(double*, double*, int, int, double*, int);
double linearRegressionPredict(double*, double*);