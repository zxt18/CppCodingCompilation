
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>


using namespace std;




int main() {
		vector<int> values = { 1,2,3,67,23412,31 };

		auto it = find_if(values.begin(), values.end(), [](int value) {return value > 2300; });
		cout << *it << endl;

		[](int value) { return value > 2300;  }

		return 0;



	} 