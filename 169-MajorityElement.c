int majorityElement(int* nums, int numsSize) {
	int* cnts = malloc(sizeof(int)*numsSize);
	int* values = malloc(sizeof(int)*numsSize);
	memset(cnts, 0, sizeof(int)*numsSize);
	memset(values, 0, sizeof(int)*numsSize);
	int idx = 0;

	int i, j;
	for (i=0; i<numsSize; i++) {
		int f = 0;
		for (j=0; j<idx; j++)
			if (values[j] == nums[i]) {
				f = 1;
				cnts[j]++;
				break;
			}

		if (!f) {
			values[idx] = nums[i];
			cnts[idx]++;
			idx++;
		}
	}

	int max_cnt = cnts[0];
	int max_cnt_idx = 0;
	for (i=1; i<idx; i++)
		if (cnts[i] > max_cnt) {
			max_cnt = cnts[i];
			max_cnt_idx = i;
		}

	int max_val = values[max_cnt_idx];
	free(cnts);
	free(values);

	return max_val;
}
