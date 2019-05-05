/*
https://leetcode.com/problems/find-pivot-index/

Given an array of integers nums, write a method that returns the "pivot" index of this array.
We define the pivot index as the index where the sum of the numbers to the left of the index is equal to the sum of the numbers to the right of the index.
If no such index exists, we should return -1. If there are multiple pivot indexes, you should return the left-most pivot index.

Example 1:
    Input:  nums = [1, 7, 3, 6, 5, 6]
    Output: 3
    Explanation: 
    The sum of the numbers to the left of index 3 (nums[3] = 6) is equal to the sum of numbers to the right of index 3.
    Also, 3 is the first index where this occurs.
 
Example 2:
    Input:  nums = [1, 2, 3]
    Output: -1
    Explanation: 
    There is no index that satisfies the conditions in the problem statement.
 

Note:

The length of nums will be in the range [0, 10000].
Each element nums[i] will be an integer in the range [-1000, 1000].

*/
#include <stdio.h>
int pivotIndex(int* nums, int numsSize){
    if (nums == NULL) return -1;
    if (numsSize < 2) return -1;

    int rsum = 0;
//    int* val = nums;
//    for (int i = 0; i < numsSize; i++) rsum += *val++;
    for (int i = 0; i < numsSize; i++) rsum += nums[i];
    int lsum = 0;
//    val = nums;
    for (int i = 0; i < numsSize; i++) {
#if 1
        if (rsum - nums[i] == lsum) {
            return i;
        }
        rsum -= nums[i];
        lsum += nums[i];
#else
        if (rsum - *val == lsum) {
            return i;
        }
        rsum -= *val;
        lsum += *val;
        ++val;
#endif
//        printf ("%d %d %d\n", i, rsum, lsum);
    }
    return -1;
}


/***********************************************/
int pivotIndex(int* nums, int numsSize) {
    int i=0,sum1=0;
    int j=0,sum2=0;
    for(i=0;i<numsSize;i++){
        sum2+=nums[i];
    }
    for(j=0;j<numsSize-1;j++){
        sum1=sum1+nums[j];
     
        if(sum2-nums[0]==0){
            return 0;
        }
        else if(nums[j+1]+(sum1*2)==sum2){
            return j+1;
        }
    }
    return -1;
}

/***********************************************/
int pivotIndex(int* nums, int numsSize) {
    
    if(!nums) return -1;
    
    int leftSum = 0, rightSum = 0;
    
    for(int i = 0; i < numsSize; i++) rightSum += nums[i];
    
    
    for(int i = 0; i < numsSize; i++){
        rightSum -= nums[i];
        
        if(rightSum == leftSum) return i;
        
        
        leftSum += nums[i];
    }
    
    return -1;
}


/***********************************************/
int pivotIndex(int* nums, int numsSize) {
    int i;
    int temp_sum = 0;
    int return_val= -1;  
    int j, sum = 0;
    
    for(j = 0 ; j < numsSize; j++){
        sum += nums[j];
    }
    
    int left_sum = 0;
    int right_sum = 0; 
    for(i = 0; i < numsSize; i ++){
        right_sum = sum - nums[i] -left_sum;
        if(left_sum == right_sum){
            return_val = i;     
            break;          
        }
        left_sum += nums[i];       
    }
    return return_val;    
}


/***********************************************/
int pivotIndex(int* nums, int numsSize){
    register int i;
    int osum[4096*3];
    register int os;
    
    if(numsSize == 0) return -1;
    
//    osum = (int *)calloc(numsSize, sizeof(int));

    os = 0;
    for(i=0; i<numsSize; i++) {
        osum[i] = os;
        os += nums[i];
    }
#if 0
for(i=0; i<numsSize; i++) {
    printf("%d, ", osum[i]);
}
printf("\n");
#endif

#if 0
for(i=0; i<numsSize; i++) {
    printf("%d, ", rsum[i]);
}
printf("\n");
#endif
    
    for(i=0; i<numsSize; i++) {
        if(osum[i] + osum[i] + nums[i] == os) break;
    }

    if(i == numsSize) return -1;
    
    return i;
}