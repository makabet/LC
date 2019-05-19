/*
https://leetcode.com/problems/add-binary/

Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:
    Input: a = "11", b = "1"
    Output: "100"
Example 2:
    Input: a = "1010", b = "1011"
    Output: "10101"
*/

char * addBinary(char * a, char * b) {
	int flag = 0;
	int tempa, tempb;
	int lena = strlen(a);
	int lenb = strlen(b);
    int max = (lena>lenb) ? lena : lenb;
	char* sum = (char*)malloc(1 + max * sizeof(char));

	for (int i = 0; i < lena || i < lenb; i++) {
        // char to Int
		tempa = (i < lena) ? a[lena - 1 - i] - '0' : 0;
		tempb = (i < lenb) ? b[lenb - 1 - i] - '0' : 0;

		sum[i] = (tempa + tempb + flag) % 2 + '0';
        // carry flag
		flag = (tempa + tempb + flag) / 2;
	}

    // last carry flag
    if (flag == 1) {
//		sum = (char*)realloc(sum, strlen(sum) + 1); // not working
		max = max + 1;
        sum = (char*)realloc(sum, max * sizeof(char) + 1);
		sum[max-1] = '1';
	}

    // change order
    for (int i = 0; i < max / 2; i++) {
		char tem;
		tem = sum[i];
		sum[i] = sum[max -1- i];
		sum[max -1 - i] = tem;
	}
    // end chars
	sum[max] = '\0';
	return sum;
}
