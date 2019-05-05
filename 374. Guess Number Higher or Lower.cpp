/*
https://leetcode.com/problems/guess-number-higher-or-lower/

We are playing the Guess Game. The game is as follows:
I pick a number from 1 to n. You have to guess which number I picked.
Every time you guess wrong, I'll tell you whether the number is higher or lower.
You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):

-1 : My number is lower
 1 : My number is higher
 0 : Congrats! You got it!

Example :
    Input: n = 10, pick = 6
    Output: 6
*/

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
#include <stdio.h>

int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int ltl = 0;
        int big = 0x7FFFFFFF;

        do {
            int ans = guess(n);
            printf ("(%d, %d) %d is %d\n", big, ltl, n, ans);
            if (ans == 0)   return n;
            if (ans < 0) { // lower
                big = n;
                // add unsigned int for int overflow
                n = ((unsigned int)n + (unsigned int)ltl) / 2 - 1;
            } else {  // bigger
                ltl = n;
                n = ((unsigned int)big + (unsigned int)n) / 2 + 1;  
            }
            if (big - ltl == 2) { // big 2, ltl 0
                n = ((unsigned int)big+(unsigned int)ltl) / 2;
            }
        } while (ltl < big);
        printf ("not found %d", n);
        return -1;
    }
};

/***********************************************/
class Solution {
public:
    int guessNumber(int n) {
        int l = 1, r = n;
        while (l < r) {
            int mid = l + (r - l) / 2;
            int g_ret = guess(mid);
            if (g_ret == 0)
                return mid;
            else if (g_ret == -1)
                r = mid - 1;
            else if (g_ret == 1)
                l = mid + 1;
        }
        return l;
    }
};

/***********************************************/
class Solution {
public:
    int guessNumber(int n) {
        
        int first = 1;
        int last = n;
        int result = -1;
        while( first <= last ) {
            int mid = first + (last-first)/2;
            int guessNum =  guess(mid);
            if( guessNum == 0 ) {
                result = mid;
                break;
            }
                
            else if(guessNum == -1 ) {
                last = mid -1;
            }
            else if( guessNum == 1) {
                first = mid + 1;
            }
        }
        return result;
    }
};