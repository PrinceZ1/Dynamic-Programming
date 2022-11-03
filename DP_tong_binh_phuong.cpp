/*Mọi số nguyên dương N đều có thể phân tích thành tổng các bình phương của các số nhỏ hơn N. Ví dụ số 100 = 10^2 hoặc 100 = 5^2 + 5^2 + 5^2 + 5^2. Cho số nguyên dương N. Nhiệm vụ của bạn là tìm số lượng ít nhất các số nhỏ hơn N mà có tổng bình phương bằng N.

Input Format

Một số tự nhiên N được viết trên 1 dòng.

Constraints

1≤N≤10000;

Output Format

Đưa ra kết quả của bài toán

Sample Input 0

100
Sample Output 0

1
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n ; cin >> n;
    int dp[n + 1];
    dp[0] = 0;
    for(int i = 1 ; i <= n ; i++)
    {
        dp[i] = i;
        for(int j = 1 ; j <= sqrt(i) ; j++)
        {
            dp[i] = min(dp[i] , dp[i - j*j] + 1);
        }
    }
    cout << dp[n];
}