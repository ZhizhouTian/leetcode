int removeDuplicates(int* nums, int numsSize) {
    int i = 0;
    int ret = 0;
    int num = 0;

    for (i=0; i<numsSize; i++) {
        if (i==0 && nums[i] == num) {
            num++;
        }

        if (num == nums[i])
            continue;
        else {
            num = nums[i];
            nums[ret] = num;
            ret++;
        }
    }
    
    return ret;
}
