#include <iostream>
#include <math.h>
using namespace std;
#define EPSILON 0.001
void bisection(float a, float b);

int main() {
	float a, b;
	cout << "Masukkan nilai tebak awal a: "; cin >> a;
	cout << "Masukkan nilai tebak awal b: "; cin >> b;
	bisection(a, b);
	return 0;
}

float func(float x) {
	return cos(x);
}

void bisection(float a, float b) {
	if (func(a) * func(b) >= 0) {
		cout << "Coba nilai tebak a dan b yang lain (akar diluar interval yang Anda masukkan).";
		return;
	}
	float c = a;
	while ((b - a) >= EPSILON) {
		c = (a + b) / 2;
		if (func(c) == 0.0) break;
		else if (func(c) * func(a) < 0) b = c;
		else a = c;
	}
	cout << "Akar dari fungsi adalah: " << c;
}
