#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
 * Given an array S of n integers,
 * find three integers in S such that the sum is closest to a given number,target.
 * Return the sum of the three integers.
 * You may assume that each input would have exactly one solution.
 *
 * For example, given array S = {-1 2 1 -4}, and target = 1.
 *
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 */
void printarr(int* arr, int arrlen)
{
	int i;

	printf("[");
	for (i=0; i<arrlen; i++)
		printf("%d, ", arr[i]);
	printf("\b\b]\n");
}

static int cmpint(const void *a, const void* b)
{
	return ( *(int*)a - *(int*)b );
}

int threeSumClosest(int* nums, int numsSize, int target)
{
	int ret[2] = {INT_MAX, 0};
	int i;

	if (numsSize <= 3)
		return nums[0] + nums[1] + nums[2];

	qsort(nums, numsSize, sizeof(*nums), cmpint);

	for (i=0; i<numsSize-2; i++) {
		int lo = i+1, hi = numsSize-1;

		while (lo < hi) {
			int sum = nums[i] + nums[lo] + nums[hi];
			int abs_ret = abs(sum-target);
			if (!abs_ret)
				return sum;

			if (abs_ret < ret[0]) {
				ret[0] = abs_ret;
				ret[1] = sum;
			}
			if (sum > target)
				hi--;
			else
				lo++;
		}
	}

	return ret[1];
}

int threeSumClosestBak(int* nums, int numsSize, int target) {
	int i;
	int a1[2] = {INT_MAX, 0};
	int a2[2] = {INT_MAX, 0};
	int a3[2] = {INT_MAX, 0};

	for (i=0; i<numsSize; i++) {
		int n = abs(target-nums[i]);
		if (n < a3[0]) {
			a1[0] = a2[0];
			a1[1] = a2[1];
			a2[0] = a3[0];
			a2[1] = a3[1];
			a3[0] = n;
			a3[1] = nums[i];
		} else if (n < a2[0]) {
			a1[0] = a2[0];
			a1[1] = a2[1];
			a2[0] = n;
			a2[1] = nums[i];
		} else if (n < a1[0]) {
			a1[0] = n;
			a1[1] = nums[i];
		}
	}

	return a1[1] + a2[1] + a3[1];
}

int main(void)
{
	int x[] = {-1, 2, 1, -4};
	int ret = threeSumClosest(x, sizeof(x)/sizeof(*x), 1);
	printf("%d.\n", ret);
	return 0;
}
