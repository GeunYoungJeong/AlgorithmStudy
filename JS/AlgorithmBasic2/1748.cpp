#include <iostream>

using namespace std;

int main(void) {
	int N, num;
	int sum = 0;

	cin >> N;

	for (int i = 1; i <= N; i++) {
		num = i;
		while (1) {
			if (num / 10 == 0) {
				sum++;
				break;
			}

			num /= 10;
			sum++;
		}
	}
	
	cout << sum << endl;

	return 0;

}