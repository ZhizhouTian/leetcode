int* getRow(int rowIndex, int* returnSize) {
	int i, j;
	int retSize = rowIndex+1;
	int* ret = malloc(sizeof(int)*retSize);

	memset(ret, 0, sizeof(int)*retSize);
	ret[0] = 1;

	for (i=1; i<=rowIndex; i++)
		for (j=i; j>=1; j--)
			ret[j] = ret[j]+ret[j-1];

	*returnSize = retSize;
	return ret;
}
