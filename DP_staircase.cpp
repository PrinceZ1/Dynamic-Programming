/*Một chiếc cầu thang có N bậc. Mỗi bước, bạn được phép bước lên trên tối đa K bước. Hỏi có tất cả bao nhiêu cách bước để đi hết cầu thang? (Tổng số bước đúng bằng N).

Input Format

Dòng duy nhất chứa 2 số nguyên N và K

Constraints

1<=N<=100000; 1<=K<=100;

Output Format

In ra đáp án tìm được trên một dòng theo modulo 10^9+7.

Sample Input 0

7 3
Sample Output 0

44
Sample Input 1

4 2
Sample Output 1

5
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main()
{
    int n , k ; cin >> n >> k;
    int dp[n + 1];
    memset(dp , 0 , sizeof(dp));
    dp[0] = 1;
    for(int i = 1 ; i <= n ;i++)
    {
        for(int j = 1 ; j <= min(i , k) ; j++)
        {
            dp[i] += dp[i - j];
            dp[i] %= MOD;
        }
    }
    cout << dp[n];
}