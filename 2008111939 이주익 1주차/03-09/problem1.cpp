#include <iostream>
#include <time.h>
#include "myMatrix.h"
#include "myVector.h"
using namespace std;

vector4D dotProduct(Matrix4D& m1, Matrix4D& m2) {
	vector4D tmp;
	float sum(0);
	for (int i = 0; i < 4; i++) {
		sum += m1.value_[0][i] * m2.value_[i][0];
		tmp.x = sum;
	}
	sum = 0;
	for (int i = 0; i < 4; i++) {
		sum += m1.value_[1][i] * m2.value_[i][1];
		tmp.y = sum;
	}
	sum = 0;
	for (int i = 0; i < 4; i++) {
		sum += m1.value_[2][i] * m2.value_[i][2];
		tmp.w = sum;
	}
	sum = 0;
	for (int i = 0; i < 4; i++) {
		sum += m1.value_[3][i] * m2.value_[i][3];
		tmp.z = sum;
	}
	return tmp;
}

int main(void)
{
	Matrix4D m1, m2;
	vector4D v1;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			m1.value_[i][j] = rand() % 10;
			m2.value_[i][j] = rand() % 10;
		}
	}
	cout << "m1" << endl;
	m1.print();
	cout << "m2" << endl;
	m2.print();
	v1 = dotProduct(m1, m2);
	cout << "v1" << endl;
	v1.show();

	return 0;
}
