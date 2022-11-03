/*Cho một số tự nhiên N được biểu diễn như một xâu kí tự, bạn hãy tính tổng của tất cả các số tạo bởi các xâu con liên tiếp của N, ví dụ N = 235 thì ta có tổng = 2 + 3 + 5 + 23 + 35 + 235.

Input Format

Dòng duy nhất chứa số nguyên dương N

Constraints

1<=N<=10^12

Output Format

In ra kết quả của bài toán

Sample Input 0

1807
Sample Output 0

2915
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    string s ; cin >> s;
    int n = s.length();
    ll dp[n];
    dp[0] = s[0] - '0';
    for(int i = 1 ; i < n ; i++)
    {
        dp[i] = dp[i - 1] * 10 + (i + 1) * (s[i] - '0');
    }
    ll sum = 0;
    for(int i = 0 ; i < n ;i++)
    {
        sum += dp[i];
    }
    cout << sum;
}