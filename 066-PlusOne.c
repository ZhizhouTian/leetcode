/*
 * Given a non-negative number represented as an array of digits, plus one to the number.
 *
 * The digits are stored such that the most significant digit is at the head of the list.
 * */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
	int i;
	int carry = 0;

	carry = !!((digits[digitsSize-1] + 1) / 10);
	digits[digitsSize-1] = (digits[digitsSize-1] + 1) % 10;

	*returnSize = digitsSize;

	if (carry==0)
		return digits;

	for (i=digitsSize-2; i>=0; i--) {
		int sum = carry + digits[i];
		digits[i] = sum % 10;
		carry = !!(sum / 10);
	}

	if (carry) {
		digits = realloc(digits, sizeof(int)*digitsSize*2);
		for(i=digitsSize; i-1>=0; i--)
			digits[i] = digits[i-1];
		digits[0] = carry;
		*returnSize = digitsSize+1;
	}

	return digits;
}
