#include<iostream>

using namespace std;

int main(void) {
	int E, S, M, year;

	cin >> E >> S >> M;

	year = 1;
	while (1) {
		if ((year - E) % 15 == 0 && (year - S) % 28 == 0 && (year - M) % 19 == 0) {
			break;
		}

		year++;
	}

	cout << year << endl;
}