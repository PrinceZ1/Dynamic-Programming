/*Cho 2 xâu kí tự S và T, hãy tìm xâu con chung dài nhất của S và T. Các kí tự của xâu con không nhất thiết phải liền kề nhau.

Input Format

Dòng đầu tiên là xâu S; Dòng thứ 2 là xâu T;

Constraints

S và T chỉ gồm các chữ cái in hoa và có độ dài không quá 1000

Output Format

In ra độ dài xâu con chung dài nhất của S và T

Sample Input 0

ZHFTDFHF
TFISHROV
Sample Output 0

3
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