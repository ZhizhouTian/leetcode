#include <deque>
#include <iostream>

/* test case for double end queue in cpp */

using namespace std;

int main(void)
{
	deque<int> dq;

	dq.push_back(3);
	dq.push_front(2);
	dq.push_back(4);
	dq.push_front(1);

	cout << dq.front() << endl;
	cout << dq.back() << endl;

	dq.pop_front();
	dq.pop_back();

	cout << dq.front() << endl;
	cout << dq.back() << endl;
	return 0;
}
