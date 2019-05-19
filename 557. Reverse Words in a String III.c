/*
https://leetcode.com/problems/reverse-words-in-a-string-iii/

Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Note: In the string, each word is separated by single space and there will not be any extra space in the string.
*/


void reverse(char* s, char* e) {
    while (*e == ' ' && s <= e) {
        --e;
    }

    while (s < e) {
        char t = *e;
        *e-- = *s;
        *s++ = t;
    }
}

char * reverseWords(char * s){
    int len = strlen(s);

    char* ps = s;
    char* pe = s + len - 1;

//    printf ("[%s]", s);
    while (ps < pe) {
        while (*ps == ' ') {
            ++ps;
        }
//        printf ("[%s] ", ps);
        char* tp = ps;
        while (*tp != ' ' && *tp != '\0') {
            ++tp;
        }
        reverse(ps, tp - 1);
//        printf("[%s]\n", s);
        ps = tp;
    }
    return s;
}


/****************************************/
void reverseWord(char* s, int len)
{
    int len2 = len / 2;
    char temp;
    for(int i=0; i < len2; i++)
    {
        // Swap
        temp = s[len - i - 1];
        s[len - i - 1] = s[i];
        s[i] = temp;
    }
}

char * reverseWords(char * s){
    int prev = 0;
    int strSz = strlen(s);
    
    // Get the first word
    for(int i = 0; i <= strSz; i++)
    {
        if(s[i] == ' ' || s[i] == 0)
        {
            //printf("%c\n", s[i]);
            // This is one word
            reverseWord(&s[prev], i - prev);
            prev = i+1;
        }
    }

    return s;
}