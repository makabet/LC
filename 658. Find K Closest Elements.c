/*
https://leetcode.com/problems/find-k-closest-elements/

Given a sorted array, two integers k and x, find the k closest elements to x in the array. The result should also be sorted in ascending order. If there is a tie, the smaller elements are always preferred.

Example 1:
    Input: [1,2,3,4,5], k=4, x=3
    Output: [1,2,3,4]
Example 2:
    Input: [1,2,3,4,5], k=4, x=-1
    Output: [1,2,3,4]
Note:
    The value k is positive and will always be smaller than the length of the sorted array.
    Length of the given array is positive and will not exceed 104
    Absolute value of elements in the array and x will not exceed 104
UPDATE (2017/9/19):
    The arr parameter had been changed to an array of integers (instead of a list of integers). Please reload the code definition to get the latest changes.
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>

int diff(int x, int y){
    if (x < y) {
        return y - x;
    }
    return x - y;
}
int* findClosestElements(int* arr, int arrSize, int k, int x, int* returnSize){
    if (arr == NULL)    return NULL;
    if (arrSize < 1)    return NULL;
    if (k < 1)      return NULL;

    // for arrSize is 1
    if (arrSize == 1) {
        *returnSize = k;
        return arr;
    }

    // find x
    int L = 0;
    int R = arrSize - 1;
    int M;
    while (L < R) {
        M = (L + R) / 2;
        if (arr[M] < x) {
            L = M + 1;
        } else {
            R = M;
        }
    }

//    printf ("%d %d\n", L , R);
    if (L == R) {   // not found same value?
        if (0 < L)  // first select lower value
            L -= 1;
        else if (R < arrSize - 1)
            R += 1;
    }

    // if not found same x value, select closest value
    if (diff(arr[L], x) <= diff(arr[R], x)) {
        M = L;
    } else {
        M = R;
    }
//    printf("%d\n", M);

    // answer
    int* ret = (int*)malloc(sizeof(int) * k);
    if (ret == NULL)
        return NULL;
    *returnSize = k;

    // find closet value
    L = M - 1;
    R = M + 1;
    ret[0] = arr[M];

    for (int i = 1; i < k; i++) {
        if (arrSize - 1 < R) {
//            printf("RR %d %d, %d x\n", L, R, arr[L]);
            ret[i] = arr[L];
            L -= 1;            
        } else if (L < 0) {
//            printf("LL %d %d, x %d\n", L, R, arr[R]);
            ret[i] = arr[R];
            R += 1;
        } else if (diff(arr[L], x) <= diff(arr[R], x)) {
//           printf("L %d %d, %d %d\n", L, R, arr[L], arr[R]);
            ret[i] = arr[L];
            L -= 1;
        } else {
//            printf("R %d %d, %d %d\n", L, R, arr[L], arr[R]);
            ret[i] = arr[R];
            R += 1;
        }
    }
    
#if 0
    printf ("answer ");
    for (int i = 0; i < k; i++)
        printf("%d,", ret[i]);

    printf("\n");
#endif
    
    // sort
    for (int i = 0; i < k - 1; i++) {
        for (int j = i + 1; j < k; j++) {
            if (ret[i] > ret[j]) {
                int t = ret[i];
                ret[i] = ret[j];
                ret[j] = t;
            }
        }
    }
    
    return ret;
}

/***********************************************/
int* findClosestElements(int* arr, int arrSize, int k, int x, int* returnSize) {
    // arr == null, arrSize==0, ==1, 
    int l = 0;
    int r = arrSize-1;
    int m;
    int l_diff, r_diff;
    *returnSize = k;
    int *ret = malloc(k*sizeof(int));
    
    if (ret == NULL) return NULL;
    
    if (arr[0] >= x) {
        *returnSize = k;
        memcpy(ret, &arr[0],k*sizeof(int));
        return ret;
    } else if (arr[arrSize-1] <= x) {
        *returnSize = k;
        memcpy(ret, &arr[arrSize-k],k*sizeof(int));
        return ret;
    }
    
    while ( l+1 < r) {
        m = l + (r-l)/2;
        if ( arr[m] == x ) {
            r = m;
        } else if (arr[m] > x) {
            r = m;
        } else {
            l = m;
        }
    }
    
    if ( l!=r ) {
        l_diff = arr[l]-x; 
        if (l_diff < 0) l_diff=-l_diff;
        r_diff = arr[r]-x;
        if (r_diff < 0) r_diff=-r_diff;
        
        if (l_diff > r_diff) l = r;
        r = l;
    }
    
    int retSize = k;
    
    while(k > 1){
        if (r == (arrSize-1)) l--;
        else if (l == 0) r++;
        else {
            l_diff = arr[l-1]-x; 
            if (l_diff < 0) l_diff=-l_diff;
            r_diff = arr[r+1]-x;
            if (r_diff < 0) r_diff=-r_diff;
            
           if (l_diff <= r_diff) {
                l--;
            } else {
                r++;
            } 
        }
        k--;
    }
    
    memcpy(ret, &arr[l],retSize*sizeof(int));
 
    return ret;

}

/***********************************************/
int compare(const int *a, const int *b) {
    return *(int *)a > *(int *)b;
}

#define ABS(a) ((a > 0) ? (a) : ((long long)0 - (a)))
#define MAX(a, b) ((a > b) ? (a) : (b))
#define MIN(a, b) ((a < b) ? (a) : (b))

int _bs(int *arr, int val, int l, int r) {
    int mid = l + ((r-l) >> 1);
    
    if (l == r) {
        if (arr[l] <= val)
            return l;
        else
            return MAX(l-1, 0);
    }
    
    if (val == arr[mid])
        return mid;
    else  if (val < arr[mid])
        return _bs(arr, val, l, MAX(mid-1, l));
    else
        return _bs(arr, val, MIN(mid+1, r), r);
}

int* findClosestElements(int* arr, int arrSize, int k, int x, int* returnSize) {
    int i, j;
    int idx, cnt;
    int *ret;
    long long lx = (long long)x;
    long long id, jd;
    
    if (arrSize <= 0) {
        *returnSize = 0;
        return NULL;
    }
    
    ret = malloc(sizeof(*ret)*k);
    memset(ret, 0, sizeof(*ret)*k);
    
    
    idx = _bs(arr, x, 0, arrSize-1);
    printf("idx=%d\n", idx);
    
    if (idx == arrSize - 1) {
        i = MAX(idx-1, 0);
        j = idx;
    } else {
        i = idx;
        j = MIN(idx+1, arrSize-1);
    }
    
    // arrSize must be 1
    if (i == j) {
        *returnSize = k;
        if (k == 1)
            ret[0] = arr[0];
        return ret;
    }
    
    
    id = ABS(arr[i] - lx);
    jd = ABS(arr[j] - lx);
    cnt = 0;
    
    while (cnt < k) {
//        printf("%d %d, cnt=%d\n", i, j, cnt);
//        printf("%lld %lld\n", ABS((long long)arr[i] - lx), ABS((-6)));
        
        if (id > jd) {
            ret[cnt++] = arr[j];
            if (j + 1 <= arrSize - 1) {
                j++;
                jd = ABS(arr[j] - lx);
            } else
                jd = INFINITY;
        } else {
            ret[cnt++] = arr[i];
            if (i - 1 >= 0) {
                i--;
                id = ABS(arr[i] - lx);
            } else
                id = INFINITY;
        }
    }
    
    qsort(ret, cnt, sizeof(*ret), compare);
    *returnSize = cnt;
    return ret;
}
/***********************************************/
int* findClosestElements(int* ar, int n, int k, int x, int* returnSize) {
    int *res = (int*)malloc(sizeof(int)*k), l = 0, m, r = n - k, i;  
    while(l < r)
    {
        m = l + (r-l)/2;
        if(x - ar[m] > ar[m+k] - x) l = m + 1;
        else r = m;
    } 
    for(i = 0; i < k; i++) res[i] = ar[l++]; 
    *returnSize = k; return res;
}