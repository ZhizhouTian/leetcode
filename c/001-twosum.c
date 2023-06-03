int* twoSum(int* nums, int numsSize, int target) {
	int* ret;
	int i, j;
	int founded = 0;

	ret = malloc(sizeof(int)*2);
	memset(ret, 0, sizeof(int)*2);

	for(i=0; i<numsSize; i++) {
		for(j=i+1; j<numsSize; j++) {
			if(nums[i]+nums[j] == target) {
				ret[0] = i;
				ret[1] = j;
				founded = 1;
			}
		}
	}

	if (founded != 1) {
		ret[0] = -1;
		ret[1] = -1;
	}

	return ret;
}
