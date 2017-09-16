#include <math.h>
#include <fstream>

using namespace std;

int main() {
	ofstream fout ("coins.out");
	ifstream fin ("coins.in");
	float N;
	fin >> N;
	int value = 100*N;
	int coins = 0;
	int denominations[4] = {25, 10, 5, 1};
	for (int i = 0; i < 4; i++) {
		while (value > denominations[i]-1) {
			value -= denominations[i];
			coins++;
		}
	}
	fout << coins;
	return 0;
}