#define INT_LEN 10

char** summaryRanges(int* nums, int numsSize, int* returnSize) {
	int i;
	char** ret = malloc(sizeof(char*)*numsSize);
	int retSize = 0;

	if (numsSize==0)
		return ret;
	if (numsSize==1) {
		ret[0] = malloc(sizeof(char)*(INT_LEN*2*3));
		sprintf(ret[0], "%d", nums[0]);
		*returnSize = 1;
		return ret;
	}

	int start=0;
	for (i=1; i<numsSize; i++) {
		if (nums[i] != nums[i-1] + 1) {
			if (start == i-1) {
				ret[retSize] = malloc(sizeof(char)*INT_LEN);
				sprintf(ret[retSize], "%d", nums[start]);
			} else {
				ret[retSize] = malloc(sizeof(char)*(INT_LEN*2+3));
				sprintf(ret[retSize], "%d->%d", nums[start], nums[i-1]);
			}
			retSize++;

			start = i;
		}
	}

	if (start == i-1) {
		ret[retSize] = malloc(sizeof(char)*INT_LEN);
		sprintf(ret[retSize], "%d", nums[start]);
	} else {
		ret[retSize] = malloc(sizeof(char)*(INT_LEN*2+3));
		sprintf(ret[retSize], "%d->%d", nums[start], nums[i-1]);
	}
	retSize++;

	*returnSize = retSize;
	return ret;
}
