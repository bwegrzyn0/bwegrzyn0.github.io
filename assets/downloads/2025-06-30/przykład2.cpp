#include <bits/stdc++.h>

// warunki początkowe
float x = 0;
float v = 1;
float t_min = 0;
float t = t_min;
float t_max = 10; // jak daleko ma sięgać symulacja
float step = 0.2; // Delta x
// parametry układu
float omega_0 = 2;
float beta = 0.5;

// funkcja obliczająca dv/dt
float f(float t, float x, float v) {
	return -2*beta*m*v-omega_0*omega_0*x;
}

// funkcja obliczająca dx/dt
float g(float t, float x, float v) {
	return v;
}

// funkcja obliczająca następną wartość x  z użyciem metody Rungego-Kutty
void next(float t, float x, float v) {
	// obliczamy wszystkie k dla obu równań
	float k_1x = g(t, x, v);
	float k_1v = f(t, x, v);

	float k_2x = g(t+step/2, x+k_1x*step/2, v+k_1v*step/2);
	float k_2v = f(t+step/2, x+k_1x*step/2, v+k_1v*step/2);

	float k_3x = g(t+step/2, x+k_2x*step/2, v+k_2v*step/2);
	float k_3v = f(t+step/2, x+k_2x*step/2, v+k_2v*step/2);

	float k_4x = g(t+step, x+k_3x*step, v+k_3v*step);
	float k_4v = f(t+step, x+k_3x*step, v+k_3v*step);
	
	// obliczamy kolejne wartości dla x oraz v
	::x += step/6*(k_1x+2*k_2x+2*k_3x+k_4x);
	::v += step/6*(k_1v+2*k_2v+2*k_3v+k_4v);
}

int main() {

	std::ofstream file;
	file.open("przykład2.csv");
	file << t << ", " << x << ", " << v << "\n";
	for (int i = 1; i < (t_max-t_min)/step; i++) {
		t += step;
		next(t, x, v);
		file << t << ", " << x << ", " << v <<  "\n"; // zapisujemy wyniki do pliku
	}
	file.close();
}

