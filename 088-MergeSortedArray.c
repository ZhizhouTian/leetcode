void merge(int* nums1, int m, int* nums2, int n) {
	int i=0, j=0, idx=0;
	int* nums = malloc(sizeof(int)*(m+n));

	while (i<m && j<n) {
		if (nums1[i]<nums2[j])
			nums[idx++] = nums1[i++];
		else
			nums[idx++] = nums2[j++];
	}

	while (i<m)
		nums[idx++] = nums1[i++];

	while (j<n)
		nums[idx++] = nums2[j++];

	memcpy(nums1, nums, sizeof(int) * (m+n));
	free(nums);
}
