int** generate(int numRows, int** columnSizes) {
	int i, j;

	int** ret = malloc(sizeof(int*)*(numRows+1));
	int* sizes = malloc(sizeof(int)*(numRows+1));

	ret[0] = malloc(sizeof(int)*2);
	memset(ret[0], 0, sizeof(int)*2);
	ret[0][0] = 1;
	sizes[0] = 1;

	for (i=1; i<numRows; i++) {
		ret[i] = malloc(sizeof(int)*(i+2));
		memset(ret[i], 0, sizeof(int)*(i+2));
		ret[i][0] = 1;
		sizes[i] = i+1;
		for (j=i; j>=1; j--)
			ret[i][j] += ret[i-1][j] + ret[i-1][j-1];
	}

	*columnSizes = sizes;
	return ret;
}
