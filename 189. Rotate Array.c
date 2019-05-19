/*
https://leetcode.com/problems/rotate-array/

Given an array, rotate the array to the right by k steps, where k is non-negative.

Example 1:

Input: [1,2,3,4,5,6,7] and k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: [-1,-100,3,99] and k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
Note:

Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
Could you do it in-place with O(1) extra space?

*/
#include <stdio.h>

void rotate(int* nums, int numsSize, int k){
    if (numsSize < 1)   return;
    if (nums == NULL)   return;

    k = k % numsSize;
    if (k == 0)
        return;

    int* temp = (int*)malloc(sizeof(int) * numsSize);

    memcpy(temp, nums, sizeof(int) * numsSize);
    memcpy(nums, &temp[numsSize - k], sizeof(int) * k);
    memcpy(&nums[k], &temp[0], sizeof(int) * (numsSize - k));
/*
    for (int i = 0; i < numsSize; i++) {
        printf("%d,", nums[i]);
    }
//*/
}



/****************************************/
void rotate(int* nums, int numsSize, int k){
    k = k%numsSize;
    int count=0;
    
    for(int start =0;count<numsSize; start++){
        int current = start;
        int prev = nums[start];
        
        do{
            int next = (current + k )% numsSize;
            int temp = nums[next];
            nums[next] = prev;
            prev = temp;
            current = next;
            count++;
        }while(start!=current);
        
    }
}

/****************************************/
void rotate(int* nums, int numsSize, int k){
    int temp_array[100000];
    int i;
    
    if( k>numsSize)
     k = k-numsSize ;
        
    if(k<100000)
    {
        for ( i= 0;i<k;i++)
            temp_array[i] = nums[numsSize-k+i];
    
        for (i=0;i<numsSize-k;i++) {
            nums[numsSize-i-1]= nums[numsSize-k-i-1];
        }
    
        for ( i= 0;i<k;i++)
            nums[i] = temp_array[i];
    }
}