/*
https://leetcode.com/problems/reverse-string/

Write a function that reverses a string. The input string is given as an array of characters char[].

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

You may assume all the characters consist of printable ascii characters.

 

Example 1:

Input: ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:

Input: ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
*/
#include <stdio.h>
void reverseString(char* s, int sSize){
    if (s == NULL) return;

    int l = 0;
    int r = sSize - 1;
//  while (l < r)   , we are not able to use l++, r-- in this line
    for (;l < r; l++, r--) {
        char t = s[l];
        s[l] = s[r];
        s[r] = t;
//        ++l;
//        --r;
    }
//    printf ("%d", l);
}

/*
void reverseString(char* s, int sSize) {
    if (sSize == 0) return;
    char temp;
    unsigned int start = 0, end = sSize - 1;
    for(; start < end; start++, end--) {
       // s[start] = s[start] ^ s[end];
       // s[end] = s[start] ^ s[end];
       // s[start] = s[start] ^ s[end];
        temp = s[start];
        s[start] = s[end];
        s[end] = temp;
    }

}
*/

/*
void reverseString(char* s, int sSize){
    char tmp;
    for(int i = 0; i < sSize/2; i++) {
        tmp = s[i];
        s[i] = s[sSize - 1 - i];
        s[sSize - 1 - i] = tmp;
    }
}
*/