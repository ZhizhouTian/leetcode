int cmpint(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}

int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
	qsort(nums, numsSize, sizeof(*nums), cmpint);

	int i;
	int realSize = 0;
	int* ret = malloc(sizeof(int) * numsSize);
	int retSize = 0;
	int disNum;

	if (numsSize < 1) {
		*returnSize = 0;
		return ret;
	}

	if (numsSize < 2) {
		ret[0] = 2;
		*returnSize = 1;
		return ret;
	}

	nums[realSize++] = nums[0];
	for (i=1; i<numsSize; i++) {
		if (nums[i] != nums[i-1])
			nums[realSize++] = nums[i];
	}

	if (realSize < 2) {
		ret[0] = 2;
		*returnSize = 1;
		return ret;
	}

	disNum = nums[0];

	for (i=0; i<realSize; i++) {
		if (disNum != nums[i])
			ret[retSize++] = disNum;
		disNum++;
	}

	for (i+=retSize; i<numsSize; i++) {
		ret[retSize++] = disNum;
		disNum++;
	}

	*returnSize = retSize;
	return ret;
}
