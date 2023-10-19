#include <string>
#include <string.h>
#include <iostream>

using namespace std;

void testStringConstruct(void)
{
	cout << "Test String Construct" << endl;

	char hello[] = "hello world";

	string helloStr(hello);
	cout << helloStr << endl;
}

void testStringIterator(void)
{
	cout << "Test String Iterator" << endl;

	char hello[] = "hello world";
	string str = "hello world";

	for (auto c: str) {
		cout << c << " ";
	}
	cout << endl;


	for (int i = 0; i < str.size(); i++) {
		cout << str[i] << " ";
	}
	cout << endl;
}

void testStringSize(void)
{
	cout << "Test String Size" << endl;

	string hello = "hello world";
	cout << hello.size() << endl;
}

void testSplit(void)
{
	cout << "Test String Split" << endl;

	string s = "dog cat cat dog";
	char *split = strtok((char*)s.c_str(), " ");
	while (split) {
		cout << string(split) << endl;
		split = strtok(NULL, " ");
	}
}

int main(void)
{
	testStringConstruct();
	testStringIterator();
	testStringSize();
	testSplit();
	return 0;
}
