#include <bits/stdc++.h>

float y_0=1;
float y = y_0;
float x_min = 0;
float x_max = 30;
float step = 0.5;
float x = x_min;

float dy_dx(float y, float x) {
	return y*cos(x);
}

int main() {
	std::ofstream file;
	file.open("przykład1.csv");
	file << x << ", " << y << "\n";
		
	for (int i = 1; i < (x_max-x_min)/step; i++) {
		float k_1 = dy_dx(y, x);
		float k_2 = dy_dx(y+step/2*k_1, x+step/2);
		float k_3 = dy_dx(y+step/2*k_2, x+step/2);
		float k_4 = dy_dx(y+step*k_3, x+step);
		x = x_min+i*step;
		y+=step/6*(k_1+2*k_2+2*k_3+k_4);
		file << x << ", " << y << "\n";
	}

	file.close();
	
	return 0;
}
