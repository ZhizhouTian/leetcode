int cmpint(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}

int firstMissingPositive(int* nums, int numsSize) {
	int ret = 1;
	int i;

	qsort(nums, numsSize, sizeof(*nums), cmpint);

	if (nums[0] > 1)
		return 1;

	for (i=0; i<numsSize; i++) {
		if (nums[i] < ret)
			continue;
		if (nums[i] != ret && ret > 0)
			break;
		ret++;
	}

	return ret;
}
