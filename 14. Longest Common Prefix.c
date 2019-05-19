/*
https://leetcode.com/problems/longest-common-prefix/
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
*/
#include <stdio.h>

char * longestCommonPrefix(char ** strs, int strsSize){
    char* ec = (char*)malloc(sizeof(char) * 1);
    *ec = '\0';
    
    if (strsSize == 0)  return ec;
    if (strsSize == 1)  return strs[0];
    printf("%d\n", strsSize);

    if (strs == NULL)   return ec;
    if (*strs == NULL)   return ec;
    if (**strs == NULL)   return ec;

    int j = 0;
    int i;
    for (; j < strlen(strs[0]); j++) {
        i = 1;
        for (; i < strsSize; i++) {
            if (strlen(strs[i]) == j - 1)
                break;

            printf("%d,%d %c %c\n", i,j, strs[0][j], strs[i][j]);

            if (strs[0][j] != strs[i][j])
                break;
        }
        if (i != strsSize)
            break;
    }

    printf("%d\n", i);
    
    char* r = (char*)malloc(sizeof(char) * j + 1);
    memcpy(r, strs[0], j);
    r[j] = '\0';
    return r;
}

/*******************************************/
char * longestCommonPrefix(char ** strs, int strsSize){
    if(strsSize==0)
    {
        return "";
    }
    int length=0;
    while(strs[0][length]!='\0')
    {
        length++;
    }
    char *str;
    str = strs[0];
    int flag=0;
    for(int i=0;i<length;i++)
    {
        for(int j=1;j<strsSize;j++)
        {
            if(strs[0][i]!=strs[j][i])
            {
                str[i]='\0';
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            break;
        }
    }
    return str;
}
