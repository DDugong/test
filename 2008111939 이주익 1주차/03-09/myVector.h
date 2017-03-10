
#include <iostream>
using namespace std;

class vector4D {
public:
	float x, y, w, z;

	vector4D()
		:x(0.0), y(0.0), w(0.0), z(0.0)
	{	}

	void assign(const float& x_, const float& y_, const float& w_, const float& z_) {
		x = x_;
		y = y_;
		z = z_;
		w = w_;
	}

	void show() {
		cout << x << "  ";
		cout << y << "  ";
		cout << w << "  ";
		cout << z << endl;

	}

	vector4D& operator+=(const vector4D& v_input) {
		x += v_input.x;
		y += v_input.y;
		z += v_input.w;
		w += v_input.z;
		return *this;
	}
};

float dotProduct(const vector4D& v0, const vector4D& v1) {
	return (v0.x * v1.x) + (v0.y * v1.y) + (v0.w * v1.w) + (v0.z * v1.z);
}



