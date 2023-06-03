#include <stdio.h>
#include <stdlib.h>

int cmpint(const void* a, const void* b)
{
	return ( *(int*)a - *(int*)b);
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize) {
	int** ret;
	int retlen = 0;
	int i, j;
	int retsize = sizeof(&(*nums)) * numsSize * 4;


	ret = malloc(retsize);

	qsort(nums, numsSize, sizeof(*nums), cmpint);

	for (i=0; i<numsSize-3; i++) {
		if ((i!=0) && (nums[i-1] == nums[i]))
			continue;

		int t = target - nums[i];

		for (j=i+1; j<numsSize-2; j++) {
			if ((j!=i+1) && (nums[j-1] == nums[j]))
				continue;
			int lo = j+1, hi = numsSize-1;
			int delta = t - nums[j];

			while (lo < hi) {
				int sum = nums[lo] + nums[hi];
				if (sum == delta) {
					int* tmparr = malloc(sizeof(*nums) * 4);
					tmparr[0] = nums[i];
					tmparr[1] = nums[j];
					tmparr[2] = nums[lo];
					tmparr[3] = nums[hi];
					ret[retlen++] = tmparr;
					if (retlen >= retsize) {
						printf("need to extend retsize.\n");
						retsize = retsize * 2;
						ret = realloc(ret, retsize);
					}
					while ((lo < hi) && (nums[lo] == nums[lo+1]))
						lo++;
					while ((lo < hi) && (nums[hi] == nums[hi-1]))
						hi--;
					lo++;
					hi--;
				} else if (sum > delta)
					hi--;
				else
					lo++;
			}
		}
	}

	*returnSize = retlen;
	return ret;
}

void printarr(int* arr, int arr_size)
{
	int i;

	printf("[");
	for (i=0; i<arr_size; i++) {
		printf("%d, ", arr[i]);
	}
	printf("\b\b]\n");
}

int main(void)
{
	int x[] = {1,-5,-1,1,-6,-7,-5,-1,-1,2,-5,6,4,5,-8,1,3,-1,9};
	int retSize = 0;
	int** ret = fourSum(x, sizeof(x)/sizeof(*x), 0, &retSize);
	int i;

	for(i=0; i<retSize; i++) {
		printarr(ret[i], 4);
	}
	return 0;
}
