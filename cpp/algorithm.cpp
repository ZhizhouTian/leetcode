#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static void __show(vector<int>& v)
{
	for (auto i: v)
		cout << i << " ";
	cout << endl;
}

int main(void)
{
	vector<int> v = {2, 1, 3, 1, 1, 5 ,4, 3, 3};
	sort(v.begin(), v.end());
	__show(v);
	auto ret = unique(v.begin(), v.end());
	__show(v);
	v.resize(ret - v.begin());
	__show(v);
}
