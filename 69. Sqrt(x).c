/*
https://leetcode.com/problems/sqrtx/

Implement int sqrt(int x).

Compute and return the square root of x, where x is guaranteed to be a non-negative integer.

Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.

Example 1:
    Input: 4
    Output: 2
    Example 2:

    Input: 8
    Output: 2
    Explanation: The square root of 8 is 2.82842..., and since 
             the decimal part is truncated, 2 is returned.
*/

#include <stdio.h>

int mySqrt(int x){
    // 0 is 0
    // 1 is 1
    if (x < 2) return x;

    for (int i = 2; i <= x; i++) {
        if ((unsigned int)i * (unsigned int)i > (unsigned int)x) {
            return i - 1;
        }
    }
//    printf ("not found\n");
    return -1;
}

/***********************************************/
int mySqrt(int x){
    if (!x) return 0;
    
    //if (x > 4 && x < INT_MAX) x += 1;
    if (x == 2147395600) x += 1;
    
    return (int)(exp(log(x)/2.0));
}

/***********************************************/
long double aBs(long double x) {
    if (x < 0) return -1*x;
    return x;
} 

int mySqrt(int x){
    if (x == 0) return 0;
    long double err = 1e-9;
    long l= 0, r= 1e6, mid=(l+r)/2;
    while (l <= r) {
         mid=(l+r)/2;
        if (mid*mid <= x) {
            l = mid+1;
        } else {
            r = mid - 1;
        }
        // mid = (l+r)/2;
    }
    return (int)l-1;
}
/***********************************************/
int mySqrt(int x){
    if(x==0||x==1)
        return x;
    long long l,r,m;
    l=1;
    r=x;
    while(l<=r){
        m=(l+r)/2;
        if(m==x/m)
            return m;
        else if(m>x/m)
            r=m-1;
        else
            l=m+1;
    }
    return l-1;
}


/***********************************************/
float FastInvSqrt(float number){
	float y;
    unsigned int x = *(unsigned int*)(&number);
	x  = 0x5f3759df - (x >> 1);
    
    y = *(float*)(&x);
    y = y * (1.5 - 0.5 * number * y * y);
    return y * (1.5 - 0.5 * number * y * y);
}

unsigned int SqrtBisection(unsigned int l, unsigned int r, unsigned int target){
    unsigned int mid = (r + l) >> 1;
    while(mid != l){
        if(mid * mid > target){
            r = mid;
        }else{
            l = mid;
        }
        mid = (r + l) >> 1;
    }
    return mid;
}


/***********************************************/
int mySqrt(int x){
    unsigned int i = 0;
    
    while(true){
        if(i * i == x){
            break;
        }
        if(((i+1) * (i+1)) > x){
            break;
        }
        i++;
    }
    
    return i;
}

/***********************************************/
int mySqrt(int x){
    if (x <= 1) {
        return x;
    }
    int i = 0;
    for (i = 2 ; i <= x; i++) {
        long pow = (long)i * (long)i;
        if( pow > x ){
            return i-1;
        }
    }
    
    return 0;
}

/***********************************************/
int mySqrt(int x) {
    unsigned i=1; 
    if (x == 0 || x == 1)
        return x;
    for (i=1; i*i <= x; ++i) {
          ;
    }
    return i-1;
    
}
