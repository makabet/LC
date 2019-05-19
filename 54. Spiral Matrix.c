/*
https://leetcode.com/problems/spiral-matrix/

Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:

Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define PRINT
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    
    *returnSize = matrixSize * *matrixColSize;
    int* ret = (int*)malloc(sizeof(int) * *returnSize);

    int rmin = 0;
    int cmin = 0;
    int rmax = matrixSize - 1;
    int cmax = *matrixColSize - 1;
    
    printf("row %d col %d\n", matrixSize, *matrixColSize);

    for (int i = 0; i < *returnSize;) {
        for (int c = cmin, r = rmin; c <= cmax; c++) {
#ifdef PRINT
            printf ("%d,", matrix[r][c]);
#endif
            ret[i++] = matrix[r][c];
        }
        ++rmin;
#ifdef PRINT
        printf ("[%d]\n", i);
#endif
        for (int r = rmin, c = cmax; r <= rmax; r++) {
#ifdef PRINT
            printf ("%d,", matrix[r][c]);
#endif
            ret[i++] = matrix[r][c];            
        }
        --cmax;
        if (i >= *returnSize)
            break;
#ifdef PRINT
        printf ("[%d]\n", i);
#endif
        for (int c = cmax, r = rmax; cmin <= c; c--) {
#ifdef PRINT
            printf ("%d,", matrix[r][c]);
#endif
            ret[i++] = matrix[r][c];
        }
        --rmax;
#ifdef PRINT
        printf ("[%d]\n", i);
#endif
        for (int r = rmax, c = cmin; rmin <= r; r--) {
#ifdef PRINT
            printf ("%d,", matrix[r][c]);
#endif
            ret[i++] = matrix[r][c];
        }
        ++cmin;
#ifdef PRINT
        printf ("[%d]\n", i);
#endif
    }
/*
    for (int i = 0; i < *returnSize; i++) {
        printf ("%d,", ret[i]);
    }
//*/
    return ret;
}
/*****************************************************/
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){

    int* result = NULL ;
    *returnSize = 0 ;
    
    if( matrixSize == 0 )
        return NULL ;
    
    *returnSize = matrixSize * matrixColSize[0] ;
    result = (int*)malloc(sizeof(int) * (*returnSize)) ;
    
    int rowStart = 0 ;
    int rowEnd = matrixSize - 1 ;
    int colStart = 0 ;
    int colEnd = matrixColSize[0] - 1 ;
    
    int resultPos = 0 ;
    while ( (rowStart < rowEnd) && (colStart < colEnd) ) {
        
        //top layer except the last element, so i < colEnd
        for (int i = colStart; i < colEnd; i++) {
            result[resultPos++] = matrix[rowStart][i] ;
        }
        
        //right layer except the last element so i < rowEnd
        for (int i = rowStart; i < rowEnd; i++) {
            result[resultPos++] = matrix[i][colEnd] ;
        }
        
        //bottom layer except the first element so i > colStart
        for (int i = colEnd; i > colStart; i--) {
            result[resultPos++] = matrix[rowEnd][i] ;
        }
        
        //left layer except the first element so i > rowStart
        for (int i = rowEnd; i > rowStart; i--) {
            result[resultPos++] = matrix[i][colStart] ;
        }
        
        rowStart += 1 ;
        rowEnd -= 1 ;
        colStart += 1 ;
        colEnd -= 1 ;
    }
    
    if (rowStart == rowEnd) {
        for ( int i = colStart; i <= colEnd; i++) {
            result[resultPos++] = matrix[rowStart][i] ;
        }
    }
    else if(colStart == colEnd)
    {
        for ( int i = rowStart; i <= rowEnd; i++) {
            result[resultPos++] = matrix[i][colStart] ;
        }
    }
    
    return result ;
}
