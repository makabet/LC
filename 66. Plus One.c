/*
https://leetcode.com/problems/plus-one/

Given a non-empty array of digits representing a non-negative integer, plus one to the integer.
The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.
You may assume the integer does not contain any leading zero, except the number 0 itself.

Example 1:
    Input: [1,2,3]
    Output: [1,2,4]
    Explanation: The array represents the integer 123.

Example 2:
    Input: [4,3,2,1]
    Output: [4,3,2,2]
    Explanation: The array represents the integer 4321.
*/


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    if (digits == NULL) return NULL;
    if (digitsSize == 0) return NULL;
    if (returnSize == NULL) return NULL;

    int num = 0;
    int* tmp = digits;
    for (int i = 0; i < digitsSize; i++) {
        if (tmp[digitsSize - 1 - i] == 9) {
            ++num;
        }
    }
    *returnSize = digitsSize;
    if (num == digitsSize) {
        ++*returnSize;
    }

    printf ("%d\n", *returnSize);
    int* ret = (int*)malloc(sizeof(int) * *returnSize);
    if (ret == NULL) return ret;

    bool up = true;
    tmp = digits;
    for (int i = 0; i < *returnSize; i++) {
        int t;
        if (i < digitsSize) {
            t = tmp[digitsSize - 1 - i];
        } else {
            t = 0;
        }
        if (t == 9 && up == true) {
            t = 0;
            up = true;
        } else if (up == true) {
            t += 1;
            up = false;
        }
        ret[*returnSize - 1 - i] = t;
    }
    
    return ret;
}

/***********************************************/
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int n = digitsSize + 1;
    int *ret = (int*)malloc(sizeof(int) * n);
   
    int carry = 1;
    for(int i = digitsSize - 1; i >= 0; i--){
        int sum = digits[i] + carry;
        carry = sum / 10;
        sum = sum % 10;
        ret[i + 1] = sum;
    }
    if(carry){
        ret[0] = carry;
        *returnSize = digitsSize + 1;
        return ret;
    }
    *returnSize = digitsSize;
    return ret + 1;
}
/***********************************************/

int* plusOne(int* digits, int digitsSize, int* returnSize){
    int temp = 1,size = digitsSize-1;
    
    while(temp && size >= 0){
        digits[size]+= temp;
        if(digits[size] >= 10){
            temp = 1;
            digits[size]-= 10;
        }
        else{
            temp = 0;
        }
        size--;
    }
    
    int* result;
    if(temp){
        *returnSize = digitsSize +1;
        result = (int*)malloc(sizeof(int)*(*returnSize));
        memcpy(result+1,digits,sizeof(int)*digitsSize);
        result[0]=1;
        
    }else{
        *returnSize = digitsSize;
        result = digits;
    }
    return result;
}

/***********************************************/
int* plusOne(int* digits, int digitSize, int* returnSize){
    int carry = 0,flag=0;
    int *returnArray;
    for(int i=0;i<digitSize;i++)
        if(digits[i]==9)
            flag++;
    if(flag==digitSize)
    {
        returnArray = (int *)malloc(sizeof(int)*(digitSize+1));
        returnArray[0]=1;
        for(int i=1;i<=digitSize;i++)
            returnArray[i]=0;
        *returnSize = digitSize+1;
        return returnArray;
                    
        
    }

    returnArray = (int *)malloc(sizeof(int)*digitSize);
    for(int i=digitSize-1;i>=0;i--)
    {
        if(i==digitSize-1)
        {
            returnArray[i]= digits[i]+1;
            carry = returnArray[i]/10;
            returnArray[i]= returnArray[i]%10;
            continue;
        }
        if(carry == 0)
        {
            returnArray[i] = digits[i];
        }
        if(carry!=0)
        {
            returnArray[i]= digits[i]+1;
            carry = returnArray[i]/10;
            returnArray[i]= returnArray[i]%10;
        }
    }
    *returnSize = digitSize;
    return returnArray;
}


/***********************************************/
Line 14: Char 20: runtime error: signed integer overflow: 2098573445 * 10 cannot be represented in type 'int' (solution.c)
Last executed input:
[9,8,7,6,5,4,3,2,1,0]

int* plusOne(int* digits, int digitsSize, int* returnSize){
    int val = 0;
    int num = 0;
    for (int i = 0; i < digitsSize; i++) {
        val += val * 10 + *digits++;            // be careful
        ++num;
    }
printf("%d %d\n", num, val);
    ++val;
    *returnSize = digitsSize;
    if (val > 10 ^ num)
        ++*returnSize;

printf("%d\n", *returnSize);
    int* ret = (int*)malloc(sizeof(int) * *returnSize);
    if (ret == NULL) return NULL;

    for (int i = 0; i < *returnSize; i++) {
        ret[*returnSize - 1 - i] = val % 10;
printf("[%d] %d %d\n", i, *ret, val);
        val /= 10;
    }
}
