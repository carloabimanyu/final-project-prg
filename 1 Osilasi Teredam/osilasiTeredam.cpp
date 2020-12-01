#include <iostream>
#include <fstream>
using namespace std;
float dx(float v);
float dv(float x, float v, float m, float k, float c);

int main() {
	float m, k, c, x0, h;
	int n;
	cout << "Masukkan massa benda (m): "; cin >> m;
	cout << "Masukkan konstanta pegas (k): "; cin >> k;
	cout << "Masukkan konstanta redaman (c): "; cin >> c;
	cout << "Masukkan simpangan awal (x0): "; cin >> x0;
	cout << "Masukkan step size (h): "; cin >> h;
	cout << "Masukkan jumlah iterasi (n): "; cin >> n;
	
	float data_t[n], data_x[n], data_v[n];
	float t0 = 0, v0 = 0;
	float t1, x1, v1;
	
	ofstream berkasT("data_t.txt"), berkasX("data_x.txt");
	for (int i = 0; i < n; i++) {
		data_t[i] = t0; data_x[i] = x0; data_v[i] = v0;
		berkasT << data_t[i] << endl;
		berkasX << data_x[i] << endl;
		t1 = t0 + h;
		x1 = x0 + dx(v0) * h;
		v1 = v0 + dv(x0, v0, m, k, c) * h;
		t0 = t1; x0 = x1; v0 = v1;
	}
	berkasT.close(); berkasX.close();
	
	cout << endl;
	cout << "Hasil pendekatan Metode Euler telah tersimpan pada berkas 'data_t.txt' dan 'data_x.txt'." << endl;
	cout << "Untuk memvisualisasikan hasil, silakan run berkas 'plotOsilasiTeredam.py'.";
	return 0;
}

float dx(float v) {
	return v;
}
float dv(float x, float v, float m, float k, float c) {
	return - k / m * x - c / m * v;
}
