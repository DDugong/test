#include <iostream>
#include "myMatrix.h"
#include "myVector.h"
#include <ctime>



vector4D operator*(const Matrix4D &m1, Matrix4D &m2) {
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

float num(const vector4D& v, const int n) {
	if (n == 0) return v.x;
	else if (n == 1) return v.y;
	else if (n == 2) return v.w;
	else if (n == 3) return v.z;
	else
		return 0;
}

vector4D operator*(const Matrix4D& m, const vector4D& v) {
	vector4D tmp;
	float sum(0);
	float n(0);
	for (int i = 0; i < 4; i++) {
		n = num(v, i);
		sum += m.value_[0][i] * n;
		tmp.x = sum;
	}
	sum = 0;
	n = 0;
	for (int i = 0; i < 4; i++) {
		n = num(v, i);
		sum += m.value_[1][i] * n;
		tmp.y = sum;
	}
	sum = 0;
	n = 0;
	for (int i = 0; i < 4; i++) {
		n = num(v, i);
		sum += m.value_[2][i] * n;
		tmp.w = sum;

	}
	sum = 0;
	n = 0;
	for (int i = 0; i < 4; i++) {
		n = num(v, i);
		sum += m.value_[3][i] * n;
		tmp.z = sum;
	}

	return tmp;
}

int main(void)
{
	Matrix4D m1, m2;
	vector4D v1;
	vector4D v2;

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
	v1 = m1 * m2;
	cout << "two matrix multiply v1" << endl;
	v1.show();
	
	v2 = m1 * v1;
	cout << "vector & matrix operator*(operator overloading)" << endl;
	v2.show();

	return 0;
}


