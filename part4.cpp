#include <math.h>
#include <fstream>

int main() {
	std::ofstream fout ("sum.out");
	std::ifstream fin ("sum.in");
	int r, c;
	fin >> r >> c;
	int values[c][r];
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			fin >> values[i][j];
		}
	}
	int minsum[c][r];
	minsum[0][0] = values[0][0];
	for (int i = 1; i < r; i++) {
		minsum[0][i] = minsum[0][i-1] + values[0][i];
	}
	for (int i = 1; i < c; i++) {
		minsum[i][0] = minsum[i-1][0] + values[i][0];
	}
	for (int i = 1; i < r; i++) {
		for (int j = 1; j < c; j++) {
			minsum[i][j] = std::min(minsum[i-1][j], minsum[i][j-1]) + values[i][j];
		}
	}
	fout << minsum[c-1][r-1];
	return 0;
}