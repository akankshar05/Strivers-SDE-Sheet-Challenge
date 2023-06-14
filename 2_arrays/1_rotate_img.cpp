class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {

        // transpose the matrix
        //  swap the columns

        int row = matrix.size();
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < row; i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

// 5 2 13 15
// 1 4 3 14
// 9 8 6 12
// 11 10 7 16
