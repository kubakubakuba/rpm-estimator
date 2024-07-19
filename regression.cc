// https://www.geeksforgeeks.org/regression-analysis-and-the-best-fitting-line-using-c/
// C++ program to implement
// the above approach
#include <iostream>
#include <stdio.h>
#include <vector>
#include "regression.hh"
// Constructor to provide the default
// values to all the terms in the
// object of class regression
Regression::Regression()
{
	coeff = 0;
	constTerm = 0;
	sum_y = 0;
	sum_y_square = 0;
	sum_x_square = 0;
	sum_x = 0;
	sum_xy = 0;
}

// Function that calculate the coefficient/
// slope of the best fitting line
void Regression::calculateCoefficient()
{
	float N = x.size();
	float numerator
		= (N * sum_xy - sum_x * sum_y);
	float denominator
		= (N * sum_x_square - sum_x * sum_x);
	coeff = numerator / denominator;
}

// Member function that will calculate
// the constant term of the best
// fitting line
void Regression::calculateConstantTerm()
{
	float N = x.size();
	float numerator
		= (sum_y * sum_x_square - sum_x * sum_xy);
	float denominator
		= (N * sum_x_square - sum_x * sum_x);
	constTerm = numerator / denominator;
}

// Function that return the number
// of entries (xi, yi) in the data set
int Regression::sizeOfData()
{
	return x.size();
}

// Function that return the coefficient/
// slope of the best fitting line
float Regression::coefficient()
{
	if (coeff == 0)
		calculateCoefficient();
	return coeff;
}

// Function that return the constant
// term of the best fitting line
float Regression::constant()
{
	if (constTerm == 0)
		calculateConstantTerm();
	return constTerm;
}

// Function that print the best
// fitting line
void Regression::PrintBestFittingLine()
{
	if (coeff == 0 && constTerm == 0) {
		calculateCoefficient();
		calculateConstantTerm();
	}
	cout << "The best fitting line is y = "
		<< coeff << "x + " << constTerm << endl;
}

// Function to take input from the dataset
void Regression::takeInput(int n, std::pair<std::vector<int>,std::vector<int>> pixels)
{
	std::vector<int> xis = pixels.first;
	std::vector<int> yis = pixels.second;

	for (int i = 0; i < n; i++) {
		char comma;
		float xi = xis[n];
		float yi = yis[n];

		sum_xy += xi * yi;
		sum_x += xi;
		sum_y += yi;
		sum_x_square += xi * xi;
		sum_y_square += yi * yi;
		x.push_back(xi);
		y.push_back(yi);
	}
}

// Function to show the data set
void Regression::showData()
{
	for (int i = 0; i < 62; i++) {
		printf("_");
	}
	printf("\n\n");
	printf("|%15s%5s %15s%5s%20s\n",
		"X", "", "Y", "", "|");

	for (int i = 0; i < x.size(); i++) {
		printf("|%20f %20f%20s\n",
			x[i], y[i], "|");
	}

	for (int i = 0; i < 62; i++) {
		printf("_");
	}
	printf("\n");
}

// Function to predict the value
// corresponding to some input
float Regression::predict(float x)
{
	return coeff * x + constTerm;
}

// Function that returns overall
// sum of square of errors
float Regression::errorSquare()
{
	float ans = 0;
	for (int i = 0;
		i < x.size(); i++) {
		ans += ((predict(x[i]) - y[i])
				* (predict(x[i]) - y[i]));
	}
	return ans;
}

// Functions that return the error
// i.e the difference between the
// actual value and value predicted
// by our model
float Regression::errorIn(float num)
{
	for (int i = 0;
		i < x.size(); i++) {
		if (num == x[i]) {
			return (y[i] - predict(x[i]));
		}
	}
	return 0;
}

