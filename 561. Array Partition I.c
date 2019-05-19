/*
https://leetcode.com/problems/array-partition-i/

Given an array of 2n integers, your task is to group these integers into n pairs of integer, say (a1, b1), (a2, b2), ..., (an, bn) which makes sum of min(ai, bi) for all i from 1 to n as large as possible.
Example 1:
Input: [1,4,3,2]

Output: 4
    Explanation: n is 2, and the maximum sum of pairs is 4 = min(1, 2) + min(3, 4).
Note:
    n is a positive integer, which is in the range of [1, 10000].
    All the integers in the array will be in the range of [-10000, 10000].
*/

int partition(int* nums, int l, int r) {
    int i = l;

    for (int j = l; j < r; j++) {
        if (nums[j] < nums[r]) {
            int t = nums[i];
            nums[i] = nums[j];
            nums[j] = t;
            ++i;
        }
    }
    // swap pivot
    int t = nums[i];
    nums[i] = nums[r];
    nums[r] = t;
    return i;
}

void quickSort(int* nums, int l, int r) {
    if (l < r) {
        int p = partition(nums, l, r);
        quickSort(nums, l, p - 1);
        quickSort(nums, p + 1, r);
    }
}

int arrayPairSum(int* nums, int numsSize){
    if (numsSize < 1)    return -1;

    // sort
    quickSort(nums, 0, numsSize - 1);
/*
    for (int i = 0; i < numsSize; i++) {
        printf ("%d ", nums[i]);
    }
    printf ("\n");
//*/
    int sum = 0;
    for (int i = 0; i < numsSize; i += 2) {
//        printf ("%d ", nums[i]);
        sum += nums[i];
    }

    return sum;
}

/*****************************************************/
int arrayPairSum(int* nums, int numsSize) {
    int ret = 0;
    
    int array[20001] = {0};
    for (int i = 0; i < numsSize; i++) {
        array[nums[i] + 10000]++;
    }
    
    int index = 0;
    int count = 0;
    bool flag = true;
    
    while ((index < 20001) && (count < (numsSize/2))) {
        if (array[index] > 0) {
            if (flag) {
                ret += (index - 10000);
                flag = false;
                array[index]--;
                count++;
            } else {
                flag = true;
                array[index]--;
            }
        } else {
            index++;
        }
    }
    
    return ret;
}

/*****************************************************/
void sort(int *nums,int l,int r)
{
    if(l>=r)
        return;
    int i=l,j=r;
    int k=nums[l];
    while(i<j)
    {
        while(i<j&&nums[j]>=k)
            j--;
        if(i<j)
        {
            nums[i]=nums[j];
            i++;
        }
        while(i<j&&nums[i]<k)
            i++;
        if(i<j)
        {
            nums[j]=nums[i];
            j--;
        }
    }
    nums[i]=k;
    sort(nums,l,i-1);
    sort(nums,i+1,r);
}

int arrayPairSum(int* nums, int numsSize) {
    int sum=0;
    sort(nums,0,numsSize-1);
    for(int i=0;i<numsSize;i+=2)
    {
            sum+=nums[i];
    } 
     return sum;                     
}