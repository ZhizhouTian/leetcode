#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// vector construct
static void testVectorConstruct(void)
{
	cout << "=== testVectorConstruct ===" << endl;
	vector<int> v1(3, 1);
	cout << "v1 size: " << v1.size() << ", v1[0]: " << v1[0] << endl;

	/* memset vector is forbidden
	memset(&v1, 0, sizeof(v1));
	cout << v1.size() << endl;
	*/

	/* not leagal, but will not crash?
	v1[100] = 1;
	cout << v1[100] << endl;
	*/

	/* copy from another vector*/
	v1[0] = 1;
	v1[1] = 2;
	vector<int> v2(v1);
	cout << "v2 size: " << v2.size() << ", v2[0]: " << v2[0] << endl;

	/* copy from start to end */
	vector<int> v3(v1.begin(), v1.end());
	cout << "v3 size: " << v3.size() << ", v3[v3.size() - 1]: " << v3[v3.size() - 1] << endl;
}

static void testVectorIterate(void)
{
	cout << "=== testVectorIterate ===" << endl;
	vector<int> vec(10, 3);
	vector<int>::iterator it;

	for (int i = 0 ; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout << endl;

	for (it = vec.begin(); it != vec.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

/* '&' is nessesary, or a new vector will create */
static void __show(vector<int>& vec)
{
	/* correct, but not smart
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		cout << *it << " ";
	*/
	for (int v: vec)
		cout << v << " ";
	cout << endl;
}

static void testVectorAdd(void)
{
	cout << "=== testVectorAdd ===" << endl;
	vector<int> vec(1, 1);
	__show(vec);

	vec.push_back(2);
	__show(vec);

	vec.insert(vec.begin() + 1, 3);
	__show(vec);
}

static void testVectorDel(void)
{
	cout << "=== testVectorDel ===" << endl;
	vector<int> vec = {1, 2, 2, 3, 4};
	__show(vec);

	/* remove 3th elem */
	vec.erase(vec.begin() + 3);
	__show(vec);

	/* remove all values equal 2 */
	vec.erase(std::remove(vec.begin(), vec.end(), 2), vec.end());
	__show(vec);

	/* remove last one*/
	vec.pop_back();
	__show(vec);
}

/* intend to forget '&' after vector<vector<int>> */
static void __testMatrix(vector<vector<int>> matrix)
{
	matrix[0][0] = 10;
}

static void testVector2D(void)
{
	cout << "=== testVector2D ===" << endl;
	vector<vector<int>> matrix1(3, vector<int>(4, 1));
	__show(matrix1[0]);

	vector<vector<int>> matrix2 =
	{
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9},
	}; 
	for (int i = 0; i < matrix2.size(); i++)
		__show(matrix2[i]);

	/* attention: matrix3(3) is wrong, push_back will add after 3 blank rows */
	vector<vector<int>> matrix3;
	for (int i = 0; i < 3; i++) {
		vector<int> row = {1*i, 2*i, 3*i};
		matrix3.push_back(row);
	}
	for (int i = 0; i < matrix3.size(); i++)
		__show(matrix3[i]);

	/* what will happend if pass matrix as a argument to function */
	__testMatrix(matrix2);
	cout << "after modified matrix2 with __testMatrix(): " << endl;
	for (int i = 0; i < matrix2.size(); i++)
		__show(matrix2[i]);
}

static vector<int> __testVectorArgAndRet(vector<int>& arg1, vector<int> arg2)
{
	printf("arg1 addr: %lx\n", (unsigned long) &arg1);
	printf("arg2 addr: %lx\n", (unsigned long) &arg2);

	vector<int> ret;
	printf("ret addr before return: %lx\n", (unsigned long) &ret);

	return ret;
}

static void testVectorArgAndRet()
{
	cout << "=== testVectorArgAndRet ===" << endl;
	vector<int> arg;

	printf("arg  addr: %lx\n", (unsigned long) &arg);
	vector<int> ret = __testVectorArgAndRet(arg, arg);
	printf("ret addr after return:  %lx\n", (unsigned long) &ret);
}

static void testVectorDeleteWhileIterating()
{
	cout << "=== testVectorDeleteWhileIterating ===" << endl;
	vector<int> v = {1,2,3,4,5,6};

	auto it = v.begin();
	while (it != v.end()) {
		if (*it == 2)
			v.erase(it);
		else
			it++;
	}

	for (auto n: v)
		cout << n;
	cout << endl;
}

static void testVectorIterator(void)
{
	cout << "=== testVectorDeleteWhileIterating ===" << endl;
	vector<int> v = {1,2,3,4,5,6};

	auto it1 = v.begin(), it2 = v.end();
	cout << it2 - it1 << endl;
}

static void testVectorCompare(void)
{
	cout << "=== testVectorCompare ===" << endl;
	vector<vector<int>> matrix;

	vector<int> t1 = {1, 2, 3};
	vector<int> t2 = {1, 3, 4};
	vector<int> t3 = {1, 2, 3};
	sort(t1.begin(), t1.end());
	sort(t2.begin(), t2.end());
	sort(t3.begin(), t3.end());
	matrix.push_back(t1);
	matrix.push_back(t2);
	matrix.push_back(t3);

	auto it = unique(matrix.begin(), matrix.end());
	cout << it - matrix.begin() << endl;
}

int main(void)
{
	testVectorConstruct();
	testVectorIterate();
	testVectorAdd();
	testVectorDel();
	testVector2D();
	testVectorArgAndRet();
	testVectorDeleteWhileIterating();
	testVectorIterator();
	testVectorCompare();
	return 0;
}
