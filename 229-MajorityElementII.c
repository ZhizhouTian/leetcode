int* majorityElement(int* nums, int numsSize, int* returnSize) {
	int* times = malloc(sizeof(int)*numsSize);
	int* values = malloc(sizeof(int)*numsSize);
	int idx = 0;

	int* ret = malloc(sizeof(int)*numsSize);
	int ret_idx = 0;

	memset(times, 0, sizeof(int)*numsSize);

	int i, j;
	for (i=0; i<numsSize; i++) {
		int flag = 0;
		for (j=0; j<idx; j++) {
			if (values[j] == nums[i]) {
				flag = 1;
				times[j]++;
				break;
			}
		}

		if (!flag) {
			values[idx] = nums[i];
			times[idx]++;
			idx++;
		}
	}

	for (i=0; i<idx; i++) {
		if (times[i] > numsSize/3)
			ret[ret_idx++] = values[i];
	}
	*returnSize = ret_idx;

	free(times);
	free(values);
	return ret;
}
