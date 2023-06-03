#include <stdio.h>
#include <stdlib.h>

int cmpint(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}

int removeElement(int* nums, int numsSize, int val)
{
	qsort(nums, numsSize, sizeof(*nums), cmpint);

	int i;
	int lo = -1, hi = -1;
	int ret = 0;

	for(i=0; i<numsSize; i++) {
		if (nums[i] == val && lo == -1)
			lo = i;
		if (nums[numsSize-1-i] == val && hi == -1)
			hi = numsSize-1-i;
	}

	if (lo == -1 || hi == -1)
		return numsSize;
	
	ret = numsSize - (hi - lo + 1);
	for(hi=hi+1; hi<numsSize; hi++)
		nums[lo++] = nums[hi];

	return ret;
}

#include "printarr.c"

int main(void)
{
	int x[] = {3,2,2,3};
	int len = removeElement(x, sizeof(x)/sizeof(*x), 3);
	printarr(x, len);
	return 0;
}
