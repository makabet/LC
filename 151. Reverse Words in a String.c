/*
https://leetcode.com/problems/reverse-words-in-a-string/

Given an input string, reverse the string word by word.

 

Example 1:

Input: "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: "  hello world!  "
Output: "world! hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 

Note:

A word is defined as a sequence of non-space characters.
Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or trailing spaces.
You need to reduce multiple spaces between two words to a single space in the reversed string.
 

Follow up:

For C programmers, try to solve it in-place in O(1) extra space.
*/
#include <stdio.h>
enum{
    STATE_BEGIN,
    STATE_SPACE,
    STATE_CAPITAL
};

void  remove_duplicate_space(char *s)
{
    if(s == NULL || *s == '\0')
        return;

    int len = strlen(s);
    int index = 0;
    int state = STATE_BEGIN;    // delate 1st space
    for(int i = 0; i < len; i++) {
        if(s[i] == ' ') {
            if(state == STATE_CAPITAL) {
                state = STATE_SPACE;
            }
        } else {
            if (state == STATE_SPACE){
                s[index++] = ' ';
            }
            s[index++] = s[i];
            state = STATE_CAPITAL;
        }
    }
    s[index] = '\0';        // last char
}

void _reverse(char *pStart, char *pEnd)
{
    if(pStart >= pEnd)
        return;

    // delate last space
    while ((*pEnd == ' ') && (pEnd >= pStart))
        pEnd--;

    // reverce order
    while(pStart < pEnd){
        char c = *pStart;
        *pStart++ = *pEnd;
        *pEnd-- = c;
    }
}

char * reverseWords(char * s) {
    remove_duplicate_space(s);
//    printf("%s", s);
    
    int len = strlen(s);
    if(len <= 1)
        return s;
    
    printf("%s", s);
    char *pStart = s;
    char *pEnd = s + len - 1;
    _reverse(pStart, pEnd);
    printf("%s", s);
    
    while(pStart < pEnd){
        while (*pStart == ' ')
            pStart++;

        char* p = pStart;
        while(*p != ' ' && *p != '\0')
            p++;

        _reverse(pStart, p - 1);
        pStart = p++;
    }
    return s;
}


/*********************************/
void reverse(char *s, int start, int end)
{
    char ch;
    
    while (start < end) {
        ch = s[start];
        s[start] = s[end];
        s[end] = ch;
        start++;
        end--;
    }
}

char* string_shift_left(char *end_shift, char *start_shift, char *end_str, int space_cnt)
{
    char *start_word = start_shift;
    int len = 0;
    while (*start_word != ' ' && start_word <= end_str) {
        len++;
        start_word++;
    }
    
    memmove(end_shift, start_shift, len);
    
    end_shift = end_shift + len;
    memset(end_shift, ' ', space_cnt - 1);
    
    if (end_shift + space_cnt - 2 == end_str)
        *(end_shift) = '\0';

    return end_shift;
}
char * reverseWords(char * s){
    
    char *start, *end, *end_shift;
    int e, i, j, len, space_cnt;
    
    if (!s || !strlen(s))
        return s;
    
    len = strlen(s) - 1;
    
    /* remove leading and trailing spaces first */
    start = s;
    end = s + len;

    while (*end == ' ' && end != start)
        end--;
    
    /* string with white space only */
    if (0 && start == end)
        return "";
   
    *(end + 1) = '\0';
     
    while (*start == ' ' && *start)
        start++;

    
    i = end - start;
    e = i;
    /* revers all words */
    while (i >= 0) {
        if (start[i] == ' ') {
            reverse(start, i + 1, e);
            i--;
            e  = i;
        } else {
            i--;
        }    
    }
    reverse(start, i + 1, e);

    j = 0;
    i = end - start;
    reverse(start, j, i);
    printf("%s \n", start);
    space_cnt = 0;
    end_shift = NULL;
    /* reduce spaces in between */
    while (j <= i) {
        if (start[j] == ' ') {
            space_cnt++;
            if (space_cnt > 1 && !end_shift)
                end_shift = start + j;
            j++;
            continue;
        }
        
        if (end_shift) {
            end_shift = string_shift_left(end_shift, start + j, end, space_cnt);
            j = end_shift - start - 1;
            space_cnt = 0;
            end_shift = NULL;
        } else {
            space_cnt = 0;
        }
        j++;
    }

    return start;
}