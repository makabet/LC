/*
https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

Share
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.

Note:

Your returned answers (both index1 and index2) are not zero-based.
You may assume that each input would have exactly one solution and you may not use the same element twice.
Example:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
*/
#include <stdio.h>
int BinSerch(int* numbers, int numbersSize, int l, int target) {
    int L = l;
    int R = numbersSize;
    while (L < R) {
        int M = ((unsigned int)L + (unsigned int)R) / 2;
        if (numbers[M] == target) {
//            printf("%d", M);
            return M;
        }
        if (numbers[M] < target) {
            L = M + 1;
        } else {
            R = M;
        }
    }
    return -1;
}

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    *returnSize = 2;
    int* ret = (int*)malloc(sizeof(int) * 2);
    ret[0] = 0;
    ret[1] = 0;
    
    if (numbers == NULL)    return ret;
    if (numbersSize < 2)     return ret;

    for (int i = 0; i < numbersSize - 1; i++) {
        if (target < numbers[i])
            return ret;

        int answer = target - numbers[i];
//        printf ("%d %d\n", target, answer);
        int ans_ind = BinSerch(numbers, numbersSize, i + 1, answer);
        if (ans_ind > 0) {
            ret[0] = i + 1;
            ret[1] = ans_ind + 1;
            break;
        }
    }
    return ret;
}

/*****************************************************/
/* fastest */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    
    *returnSize = 2;
    
    int* addend = (int*)malloc(sizeof(int)*2);
    
    int i = 0;
    int j= numbersSize - 1;
    
    while(i < j)
    {
        if(numbers[i] + numbers[j] == target)
        {
            addend[0] = i+1;
            addend[1] = j+1;
            return addend;
        }
        
        if(numbers[i] + numbers[j] < target)
            i++;
        else
            j--;
    }
    
    return NULL;
}


/*****************************************************/
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize)
{
    int lo = 0, 
        hi = numbersSize - 1, 
        diff;
    int* result;// = (int*)malloc(2 * sizeof(int));

    (*returnSize) = 2;
    
    while(1)
    {
        if (lo == hi)
        {
            (*returnSize) = 0;
            result = NULL;
            break;
        }
        
        diff = *(numbers + lo) + *(numbers + hi) - target;
        
        if (diff == 0) 
        {
            result = (int*)malloc(2 * sizeof(int));
            *result = lo + 1;
            *(result + 1) = hi + 1;
            break;
        }
        else if (diff < 0) 
        {
            lo++;
        }
        else 
        {
            hi--;
        }
        
    }
    
    return result;
}

/*****************************************************/
/* O(n ^2 ) */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    *returnSize = 2;
    int* ret = (int*)malloc(sizeof(int) * 2);
    ret[0] = 0;
    ret[1] = 0;
    
    if (numbers == NULL)    return ret;
    if (numbersSize < 2)     return ret;

    for (int i = 0; i < numbersSize - 1; i++) {
        for (int j = i + 1; j < numbersSize; j++) {
            if (numbers[i] + numbers[j] > target) {
                // no answer
                break;
            }
            if (numbers[i] + numbers[j] == target) {
                ret[0] = i + 1;
                ret[1] = j + 1;
//                printf ("%d %d", numbers[i], numbers[j]);
                break;
            }
        }
    }
    return ret;
}

