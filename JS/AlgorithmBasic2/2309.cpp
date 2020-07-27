#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	vector<int> v, answer;

	int K, a, b;
	int sum = 0;
	for (int i = 0; i < 9; i++) {
		cin >> K;
		v.push_back(K);
		sum += K;
	}

	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (sum - v[i] - v[j] == 100) {
				if (i > j) {
					v.erase(v.begin() + i);
					v.erase(v.begin() + j);
				}

				else {
					v.erase(v.begin() + j);
					v.erase(v.begin() + i);
				}

				i = 8;
				break;
			}
		}
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}

	return 0;

}