#include <list>
#include <iterator>
#include <iostream>
#include <vector>

using namespace std;


static void test1(void) {
	list<char> l;
	auto it = l.begin();

	for (char c: "hello")
		l.insert(it, c);

	cout << "(l.begin() == it) == " << (l.begin() == it) << endl;
	// why l.begin() not equal to it?
	// because it always insert before it
	// and it maybe point to the end()

	for (char c: l)
		cout << c << " ";
	cout << endl;
}

static void test2(void) {
	list<char> l;
	auto begin = l.begin();
	auto end = l.end();
	cout << "l.begin() equals to l.end()?" << (begin == end) << endl;

	auto pv = prev(l.begin());
	auto f = --begin;
	cout << "pv == begin? " << (pv == begin) << endl;
}

int main(void)
{
	test1();
	test2();
	return 0;
}
