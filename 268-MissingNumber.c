int missingNumber(int* nums, int numsSize) {
	int n=0, i=0;
	int result = 0;

	for (n=0; n<numsSize; n++) {
		result ^= nums[n];
		result ^= i;
		i++;
	}

	return result;
}
