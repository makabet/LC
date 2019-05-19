/*
https://leetcode.com/problems/spiral-matrix/

Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:

Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
*/
#include <vector>

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty() || matrix[0].empty()) return res;
        int m = matrix.size(), n = matrix[0].size();
        int c = m > n ? (n + 1) / 2 : (m + 1) / 2;
        int p = m, q = n;
        for (int i = 0; i < c; ++i, p -= 2, q -= 2) {
            for (int col = i; col < i + q; ++col)
                res.push_back(matrix[i][col]);
            for (int row = i + 1; row < i + p; ++row)
                res.push_back(matrix[row][i + q - 1]);
            if (p == 1 || q == 1) break;
            for (int col = i + q - 2; col >= i; --col)
                res.push_back(matrix[i + p - 1][col]);
            for (int row = i + p - 2; row > i; --row)
                res.push_back(matrix[row][i]);
        }
        return res;
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m=matrix.size();
        if(m==0) return ans;
        int n=matrix[0].size();
        int k=0, i=0, j=0,p;
        int b=min(m,n);
        while(k<b)
        {
            p=n-j;
            for(;j<p; j++)
                ans.push_back(matrix[i][j]);
            j--;
            p=m-i; i++;
            for(;i<p; i++)
                ans.push_back(matrix[i][j]);
            i--;
            k++;
            if(k==b) break;
            p=n-j-1; j--;
            for(;j>=p; j--)
                ans.push_back(matrix[i][j]);
            j++;
            i--; p=m-i-1;
            for(;i>=p; i--)
                ans.push_back(matrix[i][j]);
            i++;
            j++;
            k++;
            
        }
        return ans;
        
    }
};
