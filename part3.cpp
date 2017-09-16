#include <math.h>
#include <fstream>

int main() {
	std::ofstream fout ("coins2.out");
	std::ifstream fin ("coins2.in");
	int N;
	int a[4];
	int t;
	fin >> N >> a[0] >> a[1] >> a[2] >> a[3];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (a[j] > a[j+1]) {
				t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
		}
	}
	int mincoins[N+1+a[3]];
	mincoins[a[3]] = 0;
	for (int i = 0; i < a[3]; i++) {
		mincoins[i] = 65535;
	}
	for (int i = a[3]+1; i<N+1+a[3]; i++) {
		mincoins[i] = std::min(std::min(mincoins[i-a[0]],mincoins[i-a[1]]),std::min(mincoins[i-a[2]],mincoins[i-a[3]]))+1;
	}
	fout << mincoins[N+a[3]];
	return 0;
}