#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
	int lo=0, hi=numsSize-1;
	int* ret = malloc(sizeof(int)*2);

	ret[0] = -1;
	ret[1] = -1;
	*returnSize = 2;

	while (lo<=hi) {
		int mid = (lo + hi) / 2;
		if (nums[mid] < target)
			lo=mid+1;
		else
			hi=mid-1;
	}

	if (nums[lo] != target)
		return ret;

	ret[0] = lo;
	hi=numsSize-1;
	while (lo<=hi) {
		int mid = (lo + hi + 1) / 2;
		if (nums[mid] > target)
			hi=mid-1;
		else
			lo=mid+1;
	}

	ret[1] = hi;
	return ret;
}

int binary_search(int* nums, int size, int target)
{
	int lo = 0, hi = size - 1;

	while (lo <= hi) {
		int mid = (lo + hi) / 2;

		if (target < nums[mid])
			hi = mid - 1;
		else if (target > nums[mid])
			lo = mid + 1;
		else
			return mid;
	}

	return -1;
}

int main(void)
{
	//int x[] = {1, 2, 3, 4, 4, 4, 5, 6, 7, 8, 9, 10, 11};
	int x[] = {0};
	int target = 0;

	int ret = binary_search(x, sizeof(x)/sizeof(*x), target);

	if (ret == -1)
		printf("not found.\n");
	else
		printf("[%d]==%d.\n", ret, target);
	return 0;
}

