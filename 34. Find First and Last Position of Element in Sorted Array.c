/*
https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
*/

#include <stdio.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int* ret = (int*)malloc(sizeof(int) * 2);
    if (ret == NULL)
        return NULL;
    ret[0] = -1;
    ret[1] = -1;

    *returnSize = 2;

    if (nums == NULL)   return ret;
    if (numsSize < 1)  return ret;
    if (returnSize == NULL) return ret;

    int L = 0;
    int R = numsSize - 1;

    while (L < R) {
        int M = (L + R) / 2;
        if (nums[M] < target) {
            L = M + 1;
        } else {
            R = M;
        }
    }


    // get Start Position
    if (nums[R] == target) {
        ret[0] = R;
    } else if (nums[L] == target) {
        ret[0] = L;
    } else {
        return ret;
    }

    for (int i = ret[0]; i < numsSize; i++) {
//        printf ("%d %d\n", i, nums[i]);
        if (nums[i] == target) {
            ret[1] = i;
        } else {
            break;
        }
    }

//    printf("%d %d\n", ret[0], ret[1]);
    return ret;
}

/***********************************************/
int findLeft(int* nums, int numsSize, int target) {
    int result = -1;
    int index = numsSize / 2;
    if (numsSize == 1 && *nums == target) {
        result = 0;
    }
    else if (numsSize > 1) {  
        if (nums[index - 1] < target) {
            result = findLeft(&nums[index], numsSize - index, target);
            //printf("result in findLeft = %d\n", result);
            if (result != -1) {
                result += index;}
        }
        else {
            result = findLeft(nums, index, target);
        }
    }
    return result;
}

int findRight(int* nums, int numsSize, int target) {
    //printf("%d, %d\n", numsSize, target);
    int result = -1;
    int index = numsSize / 2;
    if (numsSize == 1 && *nums == target) {
        result = 0;
    }
    else if (numsSize > 1) {  
        if (nums[index] <= target) {
            result = findRight(&nums[index], numsSize - index, target);
            //printf("%d result in findRight = %d\n", nums[index], result);
            if (result != -1) {
                result += index;}
        }
        else {
            result = findRight(nums, index, target);
        }
    }
    return result;
}


int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int *result = malloc(2*sizeof(int));
    int index = 0;
    int left = -1;
    int right = -1;
    left = findLeft (nums, numsSize, target);
    right = findRight (nums, numsSize, target);
    //printf("left = %d, right = %d", left, right);
    result[0] = left;
    result[1] = right;
    *returnSize = 2;
    return result;
}
/***********************************************/
int binarySearch(int* nums, int numsSize, int target) {
	int left = 0;
	int right = numsSize - 1;
	while (left <= right) {
		int idx = (left + right) / 2;
		if (target == nums[idx])
			return idx;
		else if (target < nums[idx]) {
			right = idx - 1;
		}
		else
			left = idx + 1;
	}
	return -1;
}


int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
	int *result = malloc(sizeof(int)*2);
	if (binarySearch(nums, numsSize, target) == -1) {
		*returnSize = 2;
		result[0] = -1;
		result[1] = -1;
	}
	else {
		int left = binarySearch(nums, numsSize, target);
		int right = left;
		while (nums[left] == nums[right]) {
			if (left > 0 && nums[left] == nums[left - 1]) {
				left--;
			}
			else if (right < numsSize - 1 && nums[right] == nums[right + 1])
				right++;
			else
				break;
		}
		*returnSize = 2;
		result[0] = left;
		result[1] = right;
	}
	return result;
}