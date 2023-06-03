int cmpint(const void* a, const void* b) {
	long la = *(int*)a;
	long lb = *(int*)b;
	if (la > lb)
		return 1;
	else if(la < lb)
		return -1;
	else
		return 0;
}

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
	qsort(nums1, nums1Size, sizeof(*nums1), cmpint);
	qsort(nums2, nums2Size, sizeof(*nums2), cmpint);

	int i=0, j=0;
	int idx = 0;
	int retSize = (nums1Size<nums2Size)?nums1Size:nums2Size;
	int* ret = malloc(sizeof(int) * retSize);
	while(i<nums1Size && j<nums2Size) {
		if (nums1[i] == nums2[j]) {
			ret[idx++] = nums1[i];
			i++;
			j++;
		} else if (nums1[i] < nums2[j])
			i++;
		else
			j++;
	}
	
	*returnSize = idx;
	return ret;
}