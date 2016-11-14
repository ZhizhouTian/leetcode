int maxProfit(int* prices, int pricesSize) {
	int i, j;
	int max = 0;

	for (i=0; i<pricesSize; i++) {
		for (j=i+1; j<pricesSize; j++) {
			int delta = - (prices[i] - prices[j]);
			if (delta > max)
				max = delta;
		}
	}

	return max;
}

/* 7,1,5,3,6,4 */
int maxProfit2(int* prices, int pricesSize) {
	int i;
	int min = prices[0];
	int max = 0;

	for (i=0; i+1<pricesSize; i++) {
		if (prices[i] < min)
			min = prices[i];
		if (prices[i+1]-min > max)
			max = prices[i+1] - min;
	}

	return max;
}
