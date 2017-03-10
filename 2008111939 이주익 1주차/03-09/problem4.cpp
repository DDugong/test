#include <iostream>
#include "myMatrix.h"
#include "myVector.h"
#include <ctime>

const float PI(3.14);

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

float mySin(float angle) {
	return sin(angle * PI / 180.0);
}
float myCos(float angle) {
	return cos(angle * PI / 180.0);
}

vector4D ComputeAngleMandM(Matrix4D& m1, Matrix4D& m2) {
	vector4D tmp;
	float angle1;
	float angle2;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			m1.value_[i][j] = 0;
			m2.value_[i][j] = 0;
		}
	}
	cout << "input angle1: ";
	cin >> angle1;
	cout << "input angle2: ";
	cin >> angle2;

	m1.value_[0][0] = myCos(angle1);
	m1.value_[0][1] = -(mySin(angle1));
	m1.value_[1][0] = mySin(angle1);
	m1.value_[1][1] = myCos(angle1);
	m1.value_[2][2] = 1;
	m1.value_[3][3] = 1;

	m2.value_[0][0] = myCos(angle2);
	m2.value_[0][1] = -(mySin(angle2));
	m2.value_[1][0] = mySin(angle2);
	m2.value_[1][1] = myCos(angle2);
	m2.value_[2][2] = 1;
	m2.value_[3][3] = 1;

	tmp = m1 *m2;
	return tmp;
}


int main(void)
{
	Matrix4D m1, m2;
	vector4D v1, v2;
	float result(0);
	v1 = ComputeAngleMandM(m1, m2);
	v2.assign(1, 0, 0, 0);
	
	result = dotProduct(v1, v2);
	
	cout << "result: " << result << endl;

	return 0;
}
