#pragma once
#include <iostream>
using namespace std;

class Matrix4D {
public:
	//recommeded for fixed size of matrix
	//row & col
	float value_[4][4];
	//float *values_ = new float[3 * 3];

	void print() {
		for (int col = 0; col < 4; col++) {
			for (int row = 0; row < 4; row++) {
				cout << value_[col][row] << "  ";
			}
			cout << endl;
		}
	}
};

