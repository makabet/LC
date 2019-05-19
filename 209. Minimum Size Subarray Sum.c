/*
https://leetcode.com/problems/minimum-size-subarray-sum/

Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.

Example: 

Input: s = 7, nums = [2,3,1,2,4,3]
Output: 2
    Explanation: the subarray [4,3] has the minimal length under the problem constraint.
Follow up:
    If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n). 
*/

#include <stdio.h>

/***************************************/
// slow
int minSubArrayLen(int s, int* nums, int numsSize){
    if (numsSize < 1)   return 0;
    if (nums == NULL)   return 0;

    int min_len = numsSize + 1;
    for (int i = 0; i < numsSize - 1; i++) {
        if (s <= nums [i]) {
            min_len = 1;
            break;
        }

        int sum = s - nums[i];
        for (int j = i + 1; j < numsSize; j++) {
            sum -= nums[j];
            if (sum <= 0) {
//                printf ("%d %d\n", i, j);
                if (j - i + 1 < min_len) {
                   min_len = j - i + 1; 
                }
                break;
            }
        }
    }
    if (min_len > numsSize)
        return 0;

    return min_len;
}

/***************************************/
// Speed UP, reducing calculate
int minSubArrayLen(int s, int* nums, int numsSize) {
    int i, j, min = numsSize + 1, sum = 0;
    
    for (i = 0, j = 0; i < numsSize; i++) {
        sum += nums[i];
        while (sum >= s) {
            if (min < i - j + 1) {
                min = i - j + 1;
            }
            sum -= nums[j];
            j++;
        }
    }
    if (min==numsSize + 1)
        return 0;
    return min;
}

/***************************************/
int min(int i, int j) {
    return j < i ? j :i;
}

int minSubArrayLen(int s, int* nums, int numsSize){
    
    if (numsSize==0 || nums==NULL) return 0;
    
    int i, j, sum, minlen=numsSize + 1, curlen;
    
    sum=nums[0];
    curlen=1;
    
    if (sum >= s) return 1;
    
    for (i=0, j=1; j < numsSize; j++) {
        sum += nums[j];
        curlen++;
        
        if (sum < s) {
            continue;
        }
        
        while (sum >= s) {
            minlen=min(minlen, curlen);
            sum -= nums[i++];
            curlen--;          
        }    
    }
    return minlen != numsSize + 1 ? minlen:0;
}

/*****************************************/
int minSubArrayLen(int s, int* nums, int numsSize)
{
    int head = 0;
    int tail = 0;
    int minRes = numsSize+1;
    int sum = 0;
    while (tail < numsSize)
    {        
        while (sum < s && tail < numsSize)
        {
            sum += nums[tail];
            tail++;
        }
        
        while (sum >= s)
        {
            if ((tail-head) < minRes)
            {
                minRes = (tail-head);
            }
            sum -= nums[head];
            head++;
        }
    }
    
    return ((numsSize+1) == minRes) ? 0 : minRes;
}