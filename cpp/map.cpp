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

static void testMapIterator(void)
{
	cout << "=== testMapIterator ===" << endl;

	map<int, int> m;

	m[1] = 1;
	m[2] = 2;
	m[3] = 3;

	map<int, int>::iterator it = m.begin();
	while (it != m.end()) {
		cout << it->first << "," << it->second << endl;
		it++;
	}
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
		cout << it->first << "," << it->second << endl;
	}
	for (auto n: m)
		cout << n.first << "," << n.second << endl;
	for (pair<int,int> n: m)
		cout << n.first << "," << n.second << endl;
}

int main(void)
{
	testMapAdd();
	testMapIterator();
	return 0;
}
