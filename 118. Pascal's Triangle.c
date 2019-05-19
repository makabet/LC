
/*
https://leetcode.com/problems/pascals-triangle/

Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    int** pascal = (int**)malloc(sizeof(int*) * numRows);
    *returnSize = numRows;
    // for return arrays
    *returnColumnSizes = (int*)malloc(sizeof(int) * numRows);

    for (int i = 0; i < numRows; i++) {
        pascal[i] = (int*)malloc(sizeof(int) * (i + 1));
        (*returnColumnSizes)[i] = i + 1;

        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {   // first and last
                pascal[i][j] = 1;
            } else {
                pascal[i][j] = pascal[i-1][j -1] + pascal[i-1][j];
            }
//            printf("%d ", pascal[i][j]);
        }
//        printf("\n");
    }
/*
    printf("end\n");
    
    for (int i = 0; i < *returnSize; i++) {
        for (int j = 0; j < i + 1; j++) {
            printf(" %d ", pascal[i][j]);
        }
        printf ("[%d]\n", (*returnColumnSizes)[i]);
    }
*/
    return pascal;
}

/*************************************************/
void gen(int **ret, int numRows, int i, int** returnColumnSizes)
{
    if(i>=numRows) return;
    ret[i]=malloc(sizeof(int) * (i + 1));
    ret[i][0]=1;
    ret[i][i]=1;
    *(*returnColumnSizes + i) = i + 1;
    for(int j = 1;j < i; j++)
        ret[i][j] = ret[i-1][j-1] + ret[i-1][j]; 
    gen(ret, numRows, ++i, returnColumnSizes);

}

int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    int **ret = malloc(sizeof(int*) * numRows);
    *returnColumnSizes = malloc(sizeof(int) * numRows);
    gen(ret, numRows, 0, returnColumnSizes);
    *returnSize = numRows;
    return ret;
}
/*************************************************/
=================================================================
==30==ERROR: AddressSanitizer: heap-buffer-overflow on address 0x6040000000b8 at pc 0x000000401f9a bp 0x7fff04c30f50 sp 0x7fff04c30f48
READ of size 8 at 0x6040000000b8 thread T0
    #2 0x7f87c74382e0 in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x202e0)

0x6040000000b8 is located 0 bytes to the right of 40-byte region [0x604000000090,0x6040000000b8)
allocated by thread T0 here:
    #0 0x7f87c88c22b0 in malloc (/usr/local/lib64/libasan.so.5+0xe82b0)
    #3 0x7f87c74382e0 in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x202e0)

Shadow bytes around the buggy address:
  0x0c087fff7fc0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c087fff7fd0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c087fff7fe0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c087fff7ff0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c087fff8000: fa fa 00 00 00 00 00 fa fa fa 00 00 00 00 00 fa
=>0x0c087fff8010: fa fa 00 00 00 00 00[fa]fa fa fa fa fa fa fa fa
  0x0c087fff8020: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c087fff8030: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c087fff8040: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c087fff8050: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c087fff8060: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
Shadow byte legend (one shadow byte represents 8 application bytes):
  Addressable:           00
  Partially addressable: 01 02 03 04 05 06 07 
  Heap left redzone:       fa
  Freed heap region:       fd
  Stack left redzone:      f1
  Stack mid redzone:       f2
  Stack right redzone:     f3
  Stack after return:      f5
  Stack use after scope:   f8
  Global redzone:          f9
  Global init order:       f6
  Poisoned by user:        f7
  Container overflow:      fc
  Array cookie:            ac
  Intra object redzone:    bb
  ASan internal:           fe
  Left alloca redzone:     ca
  Right alloca redzone:    cb
==30==ABORTING
stdout

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    if (numRows <= 0)
        return NULL;

    int** RR = (int**)malloc(sizeof(int*) * numRows);
    returnSize = (int*)malloc(sizeof(int*) * numRows);
    returnColumnSizes = (int*)malloc(sizeof(int*) * numRows);

    *returnSize = 0;
    for (int i = 0; i < numRows; i++) {
        RR[i] = (int*)malloc(sizeof(int) * (i + 1));
        returnColumnSizes[i] = (i + 1);

        for (int j=0; j<(i+1); j++) {
            if (j == 0 || j == i) {   // first and last
                RR[i][j] = 1;
            } else {
                RR[i][j] = RR[i-1][j -1] + RR[i-1][j];
            }
            printf("%d ", RR[i][j]);
            ++*returnSize;
        }
        printf("\n");
    }

    printf("end");
    printf("returnSize %d\n", *returnSize);
    
    for (int i = 0; i< *returnSize; i++) {
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d ",RR[i][j]);
        }
        printf ("\n");
    }
    return RR;
}
