#include <vector>
#include <iostream>

using namespace std;

double mean(vector<int> numbers) {
	double x = 0;
	unsigned int y = 0;
	for (unsigned int i = 0; i < numbers.size(); i++){
		if (numbers[i] == 0)
			y++;
		x += numbers[i];
	}
	return x / (numbers.size() - y);

}

int main(){
	vector<int> v;

	v.push_back(1);
	v.push_back(2);
	v.push_back(0);
	v.push_back(0);
	v.push_back(3);



	cout << mean(v) << endl;
	cin.get();

	return 0;
}