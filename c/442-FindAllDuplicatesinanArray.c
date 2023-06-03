int cmpint(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

int* findDuplicates(int* nums, int numsSize, int* returnSize) {
	qsort(nums, numsSize, sizeof(*nums), cmpint);

	int i;
	int* ret = malloc(sizeof(int) * numsSize);
	int retSize = 0;

	for (i=0; i<numsSize-1; i++) {
		int flag = 0;
		while (nums[i+1] == nums[i] && i < numsSize-1) {
			flag = 1;
			i++;
		}

		if (flag)
			ret[retSize++] = nums[i];
	}

	*returnSize = retSize;
	return ret;
}
