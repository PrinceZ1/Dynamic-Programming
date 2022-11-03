/*Một con ếch có thể nhảy 1, 2, 3 bước để có thể lên đến một đỉnh cần đến. Hãy đếm số các cách con ếch có thể nhảy đến đỉnh.

Input Format

Số nguyên dương N mô tả số bước con ếch cần di chuyển để nhảy tới đỉnh

Constraints

1<=N<=40

Output Format

In ra kết quả của bài toán

Sample Input 0

5
Sample Output 0

13
Sample Input 1

10
Sample Output 1

274
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main()
{
    int n , k ; cin >> n;
    int dp[n + 1];
    memset(dp , 0 , sizeof(dp));
    dp[0] = 1;
    for(int i = 1 ; i <= n ;i++)
    {
        for(int j = 1 ; j <= min(i , 3) ; j++)
        {
            dp[i] += dp[i - j];
            dp[i] %= MOD;
        }
    }
    cout << dp[n];
}