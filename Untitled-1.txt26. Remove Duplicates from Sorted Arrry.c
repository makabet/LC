/*
https://leetcode.com/problems/remove-duplicates-from-sorted-array/

Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example 1:

Given nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.

It doesn't matter what you leave beyond the returned length.
Example 2:

Given nums = [0,0,1,1,1,2,2,3,3,4],

Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively.

It doesn't matter what values are set beyond the returned length.
Clarification:

Confused why the returned value is an integer but your answer is an array?

Note that the input array is passed in by reference, which means modification to the input array will be known to the caller as well.

Internally you can think of this:

// nums is passed in by reference. (i.e., without making a copy)
int len = removeDuplicates(nums);

// any modification to nums in your function would be known by the caller.
// using the length returned by your function, it prints the first len elements.
for (int i = 0; i < len; i++) {
    print(nums[i]);
}
*/
#include <stdio.h>

int removeDuplicates(int* nums, int numsSize){
    if (nums == NULL)   return 0;
    if (numsSize < 1)   return numsSize;

    int len = 0;
    for (int i = 0; i < numsSize; i++) {
        int j = i + 1;
        while (j < numsSize && nums[j] == nums[i]) {
            ++j;
        }
//        printf ("%d %d\n", i, j);
        nums[len++] = nums[i];
        i = j - 1;
    }
    return len;
}

/*****************************************/
int removeDuplicates(int* nums, int numsSize)
{
    if(numsSize == 0)
        return 0;
    int i = 0;
    for(int j = 1; j < numsSize; j++)
    {
        if(nums[i] != nums[j])
        {
            nums[++i] = nums[j];
        }
    }
    return i + 1;
}

/*****************************************/
int removeDuplicates(int* nums, int numsSize){
    if ( !numsSize) {
        return 0;
    }
    
    int *newNums = calloc(numsSize, sizeof(int));
    if (!newNums) {
        return 0;
    }
    
    int j=1;
    int pre=nums[0];
    for (int i=1; i<numsSize; i++) {
        if (nums[i] != pre) {
            if (i != j){
                nums[j] = nums[i];
            }
            pre = nums[i];
            j++;
        }
    }
    return (j);
}