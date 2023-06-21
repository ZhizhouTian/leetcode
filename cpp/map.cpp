#include <iostream>
#include <vector>
#include <map>

using namespace std;

static void testMapAdd(void)
{
	map<int, int> map;

	vector<int> vec = {1,2,3,4,5,6};

	for (auto v: vec) {
		cout << v << " ";
		map[v] = 9 - v;
	}

	cout << endl;

	for (auto m: map) {
		cout << m.first << "," << m.second << " ";
	}
	cout << endl;
}

static void testMapKeyExists(void)
{
	// 1. find
	// 2. count
}

int main(void)
{
	testMapAdd();
	return 0;
}
