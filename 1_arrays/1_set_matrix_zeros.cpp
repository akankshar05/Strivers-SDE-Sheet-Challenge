// ---------------------------------------------------------
// this is in o(1)
#include <vector>
#include <set>
using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {

        int n = matrix.size();
        int m = matrix[0].size();
        int col0 = 1;

        // using first row and first col and col0 for marking
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    if (j != 0)
                        matrix[0][j] = 0;
                    else
                        col0 = 0;
                }
            }
        }

        // other than first colmn and first row.. changing them first
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (matrix[i][j] != 0)
                {
                    if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    {
                        matrix[i][j] = 0;
                    }
                }
            }
        }

        // changing first row
        if (matrix[0][0] == 0)
        {
            for (int j = 0; j < m; j++)
            {
                matrix[0][j] = 0;
            }
        }
        // now changing first column
        if (col0 == 0)
        {
            for (int i = 0; i < n; i++)
            {
                matrix[i][0] = 0;
            }
        }
    }
};

// ---------------------------------------------------------
//// o(m+n)
// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
//         // vector<pair<int,int>> vec;
//         set<int> row;
//         set<int> col;

//         int r= matrix.size();
//         int c= matrix[0].size();

//         for(int i=0 ; i<r;i++){
//             for(int j=0 ; j<c;j++){
//                 if(matrix[i][j]==0){
//                     row.insert(i);
//                     col.insert(j);
//                 }
//             }
//         }

//         if(row.size()==0 && col.size()==0){
//             return;
//         }
//         if(col.size()!=c){

//             for(auto i : row){
//                 for(int j= 0 ; j<c;j++){
//                     matrix[i][j]=0;
//                 }
//             }

//         }

//         if(row.size()!=r){
//              for(auto i : col){
//                 for(int j= 0 ; j<r;j++){
//                     matrix[j][i]=0;
//                 }
//             }
//         }
//         if(row.size()==r && col.size()==c){
//              for(auto i : row){
//                 for(int j= 0 ; j<c;j++){
//                     matrix[i][j]=0;
//                 }
//             }
//         }

//     }
// };