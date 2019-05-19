/*
https://leetcode.com/problems/pascals-triangle-ii/

Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.

Note that the row index starts from 0.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 3
Output: [1,3,3,1]
Follow up:

Could you optimize your algorithm to use only O(k) extra space?
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize){
    *returnSize = rowIndex + 1;

    int** pascal = (int**)malloc(sizeof(int*) * *returnSize);
    for (int i = 0; i <= rowIndex; i++) {
        int* pas_row = (int*)malloc(sizeof(int) * (i + 1));
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                pas_row[j] = 1;
                continue;
            }
            pas_row[j] = pascal[i - 1][j - 1] + pascal[i -1][j];
        }
        pascal[i] = pas_row;
    }
/*
    for (int i = 0; i <= rowIndex; i++) {
        printf ("%d,", pascal[rowIndex][i]);
    }
*/
    return pascal[rowIndex];
}

/************************************************/
void ans(int *ret,int rowIndex,int i)
{
        if(i>rowIndex) return;
        int a,b;
        ret[0]=1;
        ret[i]=1;
        for(int j=1,a=ret[0];j<i;j++)
        {
            b=ret[j];
            ret[j]=a+ret[j];     
            a=b;

        }
        ans(ret,rowIndex,++i);

}
int* getRow(int rowIndex, int* returnSize){
    *returnSize=rowIndex+1;
    int *ret=calloc((*returnSize),sizeof(int));
    ans(ret,rowIndex,0);
    return ret;
    
}

/************************************************/
static int* getRow(int rowIndex, int* returnSize)
{
    int *row = malloc((rowIndex + 1) * sizeof(int));
    *returnSize = rowIndex + 1;

    int num = rowIndex + 1;
    if (rowIndex < 1) {
        row[0] = 1;
        return row;
    }

    int i, j;
    for (i = 1; i <= rowIndex; i++) {
        num = i + 1;
        row[0] = 1;
        row[num - 1] = 1;
        for (j = num - 2; j >= 1; j--) {
            row[j] = row[j - 1] + row[j];
        }
    }

    return row;
}