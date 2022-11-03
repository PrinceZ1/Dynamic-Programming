/*Cho hai số nguyên lớn N và M có không quá 1000 chữ số. Người ta muốn tính xem liệu có thể lấy ra nhiều nhất bao nhiêu chữ số trong N (không cần liên tiếp) và giữ nguyên thứ tự của nó để tạo ra một số X sao cho ta cũng có thể tìm thấy X trong số M theo cách tương tự.

Input Format

Dòng thứ nhất ghi số N, dòng thứ 2 ghi số M

Constraints

1<=len(N), len(M) <= 1000

Output Format

In ra số chữ số nhiều nhất có thể của X

Sample Input 0

82619136359
5572555993152891122
Sample Output 0

5
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main()
{
    string s , t ; cin >> s >> t;
    int n = s.length() , m = t.length();
    int dp[n + 1][m + 1];
    s = "a" + s; t = "a" + t;
    memset(dp , 0 , sizeof(dp));
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= m ; j++)
        {
            if(s[i] == t[j])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);
            }
        }
    }
    cout << dp[n][m];
}