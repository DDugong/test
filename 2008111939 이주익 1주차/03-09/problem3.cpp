#include <iostream>	
#include <cmath>
#include "myMatrix.h"
#include "myVector.h"
using namespace std;

const float PI(3.14);

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
	n=0;
	for (int i = 0; i < 4; i++) {
		n = num(v, i);
		sum += m.value_[1][i] * n;
		tmp.y = sum;
	}
	sum = 0;
	n=0;
	for (int i = 0; i < 4; i++) {
		n = num(v, i);
		sum += m.value_[2][i] * n;
		tmp.w = sum;

	}
	sum = 0;
	n=0;
	for (int i = 0; i < 4; i++) {
		n = num(v, i);
		sum += m.value_[3][i] * n;
		tmp.z = sum;
	}

	return tmp;
}


float mySin(float angle) {
	return sin(angle * PI / 180.0);
}
float myCos(float angle) {
	return cos(angle * PI / 180.0);
}

int main(void)
{
	Matrix4D m1;
	vector4D v1, v2;
	v1.assign(1, 0, 0, 0);
	while (1) {
		float angle;

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				m1.value_[i][j] = 0;
			}
		}
		cout << "input angle: ";
		cin >> angle;
		
		m1.value_[0][0] = myCos(angle);
		m1.value_[0][1] = -(mySin(angle));
		m1.value_[1][0] = mySin(angle);
		m1.value_[1][1] = myCos(angle);
		m1.value_[2][2] = 1;
		m1.value_[3][3] = 1;
		
		v2 = m1*v1;
		v2.show();
	}
	return 0;

}