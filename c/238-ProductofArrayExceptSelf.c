int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
	int* nums1 = malloc(sizeof(int) * numsSize);
	int* nums2 = malloc(sizeof(int) * numsSize);
	int* ret = malloc(sizeof(int) * numsSize);
	nums1[0] = 1;
	nums2[numsSize - 1] = 1;

	int i;
	for (i=0; i+1<numsSize; i++) {
		nums1[i+1] = nums1[i] * nums[i];
		nums2[numsSize-1-i-1] = nums2[numsSize-1-i]*nums[numsSize-1-i];
	}

	for (i=0; i<numsSize; i++)
		ret[i] = nums1[i]*nums2[i];
	*returnSize = numsSize;
	free(nums1);
	free(nums2);
	return ret;
}
