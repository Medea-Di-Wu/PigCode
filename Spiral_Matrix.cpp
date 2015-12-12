class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int m = matrix.size();
        if(m == 0)  return result;
        int n = matrix[0].size();
        int left = 0;
        int right = n-1;
        int up = 0;
        int down = m-1;
        while(left <= right && up <= down) {
            for(int i = left; i <= right; i++) {
                result.push_back(matrix[up][i]);
            }
            for(int i = up + 1; i <= down; i++) {
                result.push_back(matrix[i][right]);
            }
            if(up != down) {
                for(int i = right-1; i >= left; i--) {
                    result.push_back(matrix[down][i]);
                }
            }
            if(left != right) {
                for(int i = down-1; i >= up + 1; i--) {
                    result.push_back(matrix[i][left]);
                }
            }
            left++;
            right--;
            up++;
            down--;
        }
        return result;
    }
};