/*
https://leetcode.com/problems/pascals-triangle/

Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > r(numRows);
        if(numRows == 0) return r;
        for(int i=0;i<numRows;i++) {
            vector<int> t(i+1); 
            for(int j=0; j <= i; j++) {
                if (j ==0 || j == i) {
                    t[j] = 1;
                    continue;
                }
                t[j] = r[i-1][j-1]+r[i-1][j];
            }
            r[i] = t;
        }
        return r;
        
/*
        vector<int> r1;
        r1.push_back(1);
        r[0]=r1;
        for(int i=1;i<numRows;i++) {
            int j=0;
            vector<int> t(i+1);
            t[j++]=1;
            for(;j<i;j++) {
                t[j] = r[i-1][j-1]+r[i-1][j];
            }
            t[j]=1;
            r[i] = t;
        }
        return r;
*/
    }    
};