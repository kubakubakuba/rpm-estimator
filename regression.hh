// https://www.geeksforgeeks.org/regression-analysis-and-the-best-fitting-line-using-c/
// C++ program to implement
// the above approach
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
class Regression {
	public:
	// Dynamic array which is going
	// to contain all (i-th x)
	vector<float> x;

	// Dynamic array which is going
	// to contain all (i-th y)
	vector<float> y;

	// Store the coefficient/slope in
	// the best fitting line
	float coeff;

	// Store the constant term in
	// the best fitting line
	float constTerm;

	// Contains sum of product of
	// all (i-th x) and (i-th y)
	float sum_xy;

	// Contains sum of all (i-th x)
	float sum_x;

	// Contains sum of all (i-th y)
	float sum_y;

	// Contains sum of square of
	// all (i-th x)
	float sum_x_square;

	// Contains sum of square of
	// all (i-th y)
	float sum_y_square;

	Regression();
	void calculateCoefficient();
	void calculateConstantTerm();
	int sizeOfData();
	float coefficient();
	float constant();
	void PrintBestFittingLine();
	void takeInput(int n, std::pair<std::vector<int>,std::vector<int>> pixels);
	void showData();
	float predict(float x);
	float errorSquare();
	float errorIn(float num);
};

