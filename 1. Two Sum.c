/*
https://leetcode.com/problems/two-sum/

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
    Given nums = [2, 7, 11, 15], target = 9,
    Because nums[0] + nums[1] = 2 + 7 = 9,
    return [0, 1].
*/
#include <stdio.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    if (nums == NULL) return NULL;
    if (numsSize < 0) return NULL;
    if (returnSize == NULL) return NULL;

    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (target == nums[i] + nums[j]) {
                *returnSize = 2;
                int *retval = (int *)malloc(sizeof(int) * *returnSize);
                if (retval == NULL) return NULL;
//                printf("%d + %d = %d\n", nums[i], nums[j], target);
                retval[0] = i;
                retval[1] = j;
//                printf("%d %d\n", retval[0], retval[1]);
                return retval;
            }       
        }
    }
    return NULL;
}

/***********************************************/
int* twoSum(int* nums, int numsSize, int target) {
    
    int min=0x7FFFFFFF; //INT_MAX; 
    int max=0; //INT_MIN;
    
    for (int i=0;i<numsSize;i++) {
        if (nums[i]<min) min=nums[i];
        if (nums[i]>max) max=nums[i];
    }
    
    int* map=calloc(max-min+1,sizeof(int));
    if (map==NULL) return NULL;
    
    int* result=malloc(2*sizeof(int));
    if (result==NULL) {free(map);return NULL;}
    
    for (int i=0;i<numsSize;i++) {
        int value=nums[i];
        long long searchvalue=(long long)target-value;
        if (!(searchvalue>max || searchvalue<min)) {
            //check map
            if (map[searchvalue-min]) {
                result[0]=map[searchvalue-min]-1;
                result[1]=i;
                free(map);
                return result;
            }
        }
        map[value-min]=i+1;
    }
    free(map);  
    free(result);  
    return NULL; 
}

/***********************************************/
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int l, r;
    
    int *copy = (int *)malloc(numsSize*sizeof(int));
    for (int i=0; i<numsSize; i++)
        copy[i] = nums[i];
    
    qsort((void *)copy, numsSize, sizeof(int), cmp);

    l = 0;
    r = numsSize-1;
    
    for (l=0, r=numsSize-1; l<r;) {
        if (copy[l] + copy[r] == target) {

            int *res = (int *)malloc(2*sizeof(int));
            for(res[0]=0; nums[res[0]] != copy[l]; res[0]++);
            for(res[1]=0; nums[res[1]] != copy[r] || res[0] == res[1]; res[1]++);
            qsort((void *)res, 2, sizeof(int), cmp);
            *returnSize = 2;
            return res;
        } else if (copy[l] + copy[r] < target) 
            l++;
        else
            r--;
    }
    
    *returnSize = 0;
    return NULL;
}


/***********************************************/
 void merge(int *array, int l, int m, int r) {
    int i;
    int j;
    int k;
    
    int n1 = m - l + 1; /* m included */
    int n2 = r - m; /* m excluded */
    
    int L[(const int)n1];
    int R[(const int)n2];
    
    for (i = 0; i < n1; i++) {
        L[i] = array[l + i];
    }
    
    for (i = 0; i < n2; i++) {
        R[i] = array[m + 1 + i];
    }
    
    i = 0; /* first array index */
    j = 0; /* second array index */
    k = l; /* third array index */
    
    while (i < n1 && j < n2) {
        if (L[i] < R[j]) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }
}

void sort(int *array, int low, int high) {
    int mid = 0;
    
    if (high <= low) {
        return;
    }
    
    mid = low + ((high - low) / 2);
    
    //printf("here %d %d %d\n", low, mid, high);
    
    sort(array, low, mid);
    sort(array, mid + 1, high);
    
    merge(array, low, mid, high);
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int start_index = 0;
    int end_index = numsSize - 1;
    int *array = NULL;
    int *result = NULL;
    
    
    if (nums == NULL || numsSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    
    result = (int *) malloc(sizeof(int) * numsSize);
    
    for (int i = 0; i < numsSize; i++) {
        result[i] = nums[i];
    }
    
    sort(result, 0, numsSize - 1);
    
        
    while (start_index < end_index) {
        if (result[start_index] + result[end_index] == target) {
            array = (int *) malloc(sizeof(int) * 2);
            
            //printf("\nindex %d %d\n", start_index, end_index);
            int s = 0;            
            for (int i = 0; i < numsSize; i++) {
                if (nums[i] == result[start_index] && s == 0) {
                    array[0] = i;      
                    s = 1;
                } else if (nums[i] == result[end_index]) {
                    array[1] = i;        
                }
            }
            *returnSize = 2;
            return array;
        } else if (result[start_index] + result[end_index] > target) {
            end_index--;    
        } else {
            start_index++;
        }
    }
    
    *returnSize = 0;
    
    return NULL;
}

/***********************************************/
typedef struct _ele Ele;

struct _ele
{
    int val;
    int index;
};

int cmp(const void *a, const void *b)
{
    return (((Ele *)a)->val - ((Ele *)b)->val);
};

Ele *cp_nums(int *nums, int numsSize)
{
    Ele *eles = (Ele *)malloc(numsSize * sizeof(Ele));
    for (int i = 0; i < numsSize; i++)
    {
        (eles + i)->val = *(nums + i);
        (eles + i)->index = i;
    }
    return eles;
}

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    Ele *eles = cp_nums(nums, numsSize);
    qsort(eles, numsSize, sizeof(Ele), cmp);

    int *res = malloc(2 * sizeof(int));
    int sum;
    *returnSize = 2;

    Ele *pl = eles;
    Ele *pr = eles+numsSize-1;
    while(pl!=pr){
        sum = pl->val + pr->val;
        if (sum==target)
            break;
        else if (sum < target)
            pl++;
        else
            pr--;
    }
    
    res[0] = pl->index;
    res[1] = pr->index;

    return res;
};