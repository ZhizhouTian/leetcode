#include <limits.h>

int thirdMax(int* nums, int numsSize) {
    int a1=0, a2=0, a3=0;
    int idx = 0;
    int i, j;
    int min =INT_MAX;
    int max = INT_MIN;
    
    for (i=0; i<numsSize; i++) {
        if (nums[i] < min)
            min = nums[i];
        if (nums[i] > max)
            max = nums[i];
    }
    
    a1 = a2 =a3 = min;
    
    for (i=0; i<numsSize; i++) {
        if (nums[i]==a1 || nums[i]==a2 || nums[i]==a3)
            continue;

        if (nums[i] > a3) {
            a1 = a2;
            a2 = a3;
            a3 = nums[i];
        } else if (nums[i] > a2) {
            a1 = a2;
            a2 = nums[i];
        } else if (nums[i] > a1) {
            a1 = nums[i];
        }
    }
    
    if ((a1 == a2) || (a2 == a3))
        return max;

    return a1;
}
