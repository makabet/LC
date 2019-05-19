/*
https://leetcode.com/problems/implement-strstr/

Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().
*/
#include <stdio.h>

int strStr(char * haystack, char * needle){
    if (needle == NULL)   return 0;
    if (strlen(needle) == 0) return 0;
    if (haystack == NULL)   return -1;

    int lh = strlen(haystack);
    int ln = strlen(needle);
    int ret = -1;
    
    for (int i = 0; i < lh; i++) {
        if (ln > lh - i)
            break;

        if (haystack[i] == needle[0]) {
            int j = 1;
//            printf ("%s\n", &haystack[i]);

            for (int k = i + 1; j < ln && k < lh; j++, k++) {
                if (haystack[k] != needle[j]) {
//                    printf ("%s %s\n", &haystack[k], &needle[j]);
                    j = -1;
                    break;
                }
            }
            if (j > 0) {
                ret = i;
                break;
            }
        }
    }
    
    return ret;
}

/***************************************/
int strStr(char* haystack, char* needle) {
    int idx1 = 0;
    int idxbak = 0;
    if (*needle == '\0')
        return 0;

    while (haystack[idx1] != '\0') {
        if (haystack[idx1] == needle[0]) {
            int idx2 = 0;
            int idx1_tmp = idx1;
            bool valid = true;
            while (needle[idx2] != '\0') {
                if (haystack[idx1_tmp++] != needle[idx2++]) {
                    valid = false;
                    break;
                }
            }
            if (valid)
                return idx1;
        }
        idx1++;
    }
    return -1;
}

/***************************************/
int strStr(char * haystack, char * needle){
    
    if (strlen(needle) == 0)
        return 0;
    
    int size = strlen(haystack) - strlen(needle);
    int k, j;
    
    for (int i=0; i<=size; i++){
        
        for(j=i, k=0; needle[k] != 0 && haystack[j] == needle[k]; j++, k++);
        
        if(k == strlen(needle))
            return i;        
    }
    
    return -1;
}
