/*Nhiệm vụ của bạn là đếm số cách các số 1,2,…, n có thể chia thành hai tập có tổng bằng nhau. Các phần tử trong tập không xét đến thứ tự Ví dụ, nếu n = 7, có bốn nghiệm: {1,3,4,6} và {2,5,7}. {1,2,5,6} và {3,4,7}. {1,2,4,7} và {3,5,6}. {1,6,7} và {2,3,4,5}.

Input Format

Dòng duy nhất chứa số nguyên dương n

Constraints

1<=n<=500

Output Format

In ra kết quả sau khi chia dư với 10^9 + 7

Sample Input 0

7
Sample Output 0

4
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
int dp[501][100001];
int main()
{
    int n ; cin >> n;
    int sum = 0;
    for(int i = 1 ; i <= n ; i++) sum += i;
    if(sum % 2 != 0) 
    {
        cout << 0 << endl;
        return 0;
    }
    sum /= 2;
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1; j <= sum ; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if(j >= i)
            {
                dp[i][j] += dp[i - 1][j - i];
                dp[i][j] %= MOD;
            }
        }
    }
    cout << dp[n][sum] << endl;
}