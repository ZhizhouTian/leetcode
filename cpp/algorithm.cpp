#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

static void __show(vector<int>& v)
{
	for (auto i: v)
		cout << i << " ";
	cout << endl;
}

class SearchTestCase {
public:
	vector<int> arr;
	int target;
	int result;
};

class Search {
public:
	vector<SearchTestCase> tcs;

	/*
	 * RETURN:
	 * >0: correspodent index in arr equal target value
	 * -1: not found
	 */
	int binarySearch(vector<int> arr, int target) {
		int i = 0, j = arr.size() - 1, mid = (i + j) / 2;

		while (i <= j) {
			if (target == arr[mid])
				return mid;
			if (target > arr[mid])
				i = mid + 1;
			else
				j = mid - 1;
			mid = (i + j) / 2;
		}

		return -1;
	}

	bool test(void) {
		for (auto t: tcs) {
			if (binarySearch(t.arr, t.target) != t.result)
				return false;
		}
		return true;
	}
};

class PriorityQueueTest {
	priority_queue<int, vector<int>, greater<int>> min;
	priority_queue<int, vector<int>, less<int>> max;
public:

	void add(int value) {
		this->min.push(value);
		this->max.push(value);
	}

	int topmax(void) {
		return this->max.top();
	}

	int topmin(void) {
		return this->min.top();
	}
};

Search g_search = {
	.tcs = {
		{.arr = {2, 5, 8, 12, 19}, .target = 20, .result = -1},
		{.arr = {0, 1, 2, 3, 4, 5, 6}, .target = 6, .result = 6},
		{.arr = {0, 1, 2, 3, 4, 5, 6}, .target = 0, .result = 0},
		{.arr = {0, 1, 2, 3, 4, 5, 6}, .target = 3, .result = 3},
		{.arr = {0, 1, 2, 3, 4, 5, 6}, .target = -1, .result = -1},
		{.arr = {0, 1, 2, 3, 4, 5, 6}, .target = 7, .result = -1},
	},
};

int main(void)
{
	vector<int> v = {2, 1, 3, 1, 1, 5 ,4, 3, 3};
	sort(v.begin(), v.end());
	__show(v);
	auto ret = unique(v.begin(), v.end());
	__show(v);
	v.resize(ret - v.begin());
	__show(v);

	if (!g_search.test())
		cout << "search failed\n" << endl;

	PriorityQueueTest pqtest;
	pqtest.add(1);
	pqtest.add(2);
	pqtest.add(3);
	cout << "max: " << pqtest.topmax() << "min: " << pqtest.topmin() << endl;
}
