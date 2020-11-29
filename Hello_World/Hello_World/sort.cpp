#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;


int main() {
	vector<int> values = {3, 4, 5, 1, 23, 11, 2, 2, 2, 2, 2, 2};
	sort(values.begin(), values.end);
	for (int v : values) {
		cout << v << endl;
	}


	return 0;


	
}