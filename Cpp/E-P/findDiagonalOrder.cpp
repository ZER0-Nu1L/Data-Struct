#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;
vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
    //
    int flag, i = 0, j = 0;
    int n = matrix.size(), m = matrix[0].size();
    vector<int> ans;
    // 1. special

    while(1) {
        if(flag) {
            while(i >= 0 && j < m) {
                ans.push_back(matrix[i--][j++]);
            }
            if(i == n-2 && j == m)
                break;
            if (j == m) {
                i++;
                j--;
            }
            i++;
            flag = 0;
        } else {
            while(j >= 0 && i < n) {
                ans.push_back(matrix[i++][j--]);
            }
            if(i == n && j == m-2)
                break;
            if (i == n) {
                i--;
                j++;
            }
            j++;
            flag = 1;
        }
    }

    return ans;
}
int main() {
    vector<int> a, b, c;
    a.push_back(1), a.push_back(2), a.push_back(3);
    b.push_back(4), b.push_back(5), b.push_back(6);
    c.push_back(4), c.push_back(5), c.push_back(6);
    vector< vector<int> > matrix;
    matrix.push_back(a), matrix.push_back(b), matrix.push_back(c);
    vector<int> ans = findDiagonalOrder(matrix);
    for(int i = 0; i < (int)ans.size(); i++){
            printf("%d", ans[i]);
    }
    getchar();
    return 0;
}