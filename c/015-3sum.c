#include <stdlib.h>
#include <stdio.h>

void printarr(int* arr, int arr_size)
{
	int i;

	printf("[");
	for (i=0; i<arr_size; i++) {
		printf("%d, ", arr[i]);
	}
	printf("\b\b]\n");
}

int cmpint(const void* p1, const void* p2)
{
	int a = *((int*)p1);
	int b = *((int*)p2);
	if (a > b) return 1;
	if (b < b) return -1;
	return 0;
}

int** threeSum(int* nums, int numsSize, int* returnSize)
{
	int** retarr;
	int retsize = 0;
	int i, start, end;

	qsort(nums, sizeof(nums)/sizeof(*nums), sizeof(*nums), cmpint);
	retarr = malloc(sizeof(&(*nums)) * numsSize * 3);

	for (i=0; i<numsSize-2; i++) {
		if ((i==0) || (i > 0 && nums[i] != nums[i-1])) {
			start = i + 1;
			end = numsSize - 1;
			int delta = 0 - nums[i];

			while (start < end) {
				int sum = nums[start] + nums[end];
				if (sum == delta) {
					int* tmparr = malloc(sizeof(*nums) * 3);
					tmparr[0] = nums[i];
					tmparr[1] = nums[start];
					tmparr[2] = nums[end];
					retarr[retsize] = tmparr;
					retsize++;
					while (start < end && nums[start] == nums[start+1])
						start++;
					while (end > start && nums[end] == nums[end-1])
						end--;
					start++;
					end--;

				} else if (sum > delta)
					end--;
				else
					start++;
			}
		}
	}

	*returnSize = retsize;
	return retarr;
}

int main(void)
{
	int x[] = {-1,0,1,2,-1,-4};
	printarr(x, sizeof(x)/sizeof(*x));

	qsort(x, sizeof(x)/sizeof(*x), sizeof(*x), cmpint);
	printarr(x, sizeof(x)/sizeof(*x));

	int retsize = 0;
	int** ret = threeSum(x, sizeof(x)/sizeof(*x), &retsize);
	int i;

	for (i=0; i<retsize; i++)
		printarr(ret[i], 3);
	return 0;
}
