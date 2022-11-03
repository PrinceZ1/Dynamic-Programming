/*Bạn được cung cấp một ma trận nhị phân có N dòng và M cột chỉ bao gồm các số 0 và 1, hãy tìm hình vuông lớn nhất trong ma trận mà chỉ chứa toàn số 1.

Input Format

Dòng đầu tiên gồm 2 số N và M; N dòng tiếp theo mỗi dòng M số nguyên;

Constraints

1<=N,M<=500; 0<=A[i][j]<=1;

Output Format

In ra kết quả đáp án của bài toán

Sample Input 0

4 4
1 1 0 0
1 1 1 1
1 1 0 1
1 0 1 0
Sample Output 0

2
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n , m ; cin >> n >> m;
    int a[n][m];
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            cin >> a[i][j];
        }
    }
    int dp[n][m], res = 0;
    memset(dp , 0 , sizeof(dp));
    for(int i = 0 ; i < n ;i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            if(i == 0 || j == 0)
            {
                dp[i][j] = a[i][j];
            }
            else
            {
                if(a[i][j])
                {
                    dp[i][j] = min(dp[i - 1][j] , min(dp[i - 1][j - 1] , dp[i][j - 1])) + 1;
                }
                else 
                {
                    dp[i][j] = 0;
                }
            }
            res = max(dp[i][j] , res);
        }
    }
    cout << res;
}