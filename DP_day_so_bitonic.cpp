/*Một dãy số được gọi là Bi-tonic nếu nó được chia thành hai dãy đầu tăng dần và dãy tiếp theo giảm dần. Nhiệm vụ của bạn là tìm tổng lớn nhất dãy con Bi-tonic của dãy số A[]. Ví dụ với dãy A[] = {1, 15, 51, 45, 33, 100, 12, 18, 9} ta có kết quả là 194 tương ứng với dãy Bi-tonic {1, 15, 51, 100, 18, 9}.

Input Format

Dòng đầu tiên đưa vào N là số phần tử của dãy A[]; Dòng tiếp theo đưa vào N số A[i]; các số được viết cách nhau một vài khoảng trống

Constraints

1<=N<=100; 1<=A[i]<=100;

Output Format

In ra kết quả của bài toán

Sample Input 0

8
7 8 8 19 3 6 2 15 
Sample Output 0

49
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main()
{
    int n ; cin >> n;
    int a[n];
    for(int i = 0 ; i < n;i++)
    {
        cin >> a[i];
    }
    int dp1[n + 1] , dp2[n + 1];
    for(int i = 0 ; i < n ; i++)
    {
        dp1[i] = a[i];
        for(int j = 0 ; j < i ; j++)
        {
            if(a[i] > a[j])
            {
                dp1[i] = max(dp1[i] , dp1[j] + a[i]);
            }
        }
    }
    for(int i = n - 1 ; i >= 0 ; i--)
    {
        dp2[i] = a[i];
        for(int j = n - 1 ; j > i ; j--)
        {
            if(a[i] > a[j])
            {
                dp2[i] = max(dp2[i] , dp2[j] + a[i]);
            }
        }
    }
    int res = 0;
    for(int i = 0 ; i < n ; i++)
    {
        res = max(res , dp1[i] + dp2[i] - a[i]);
    }
    cout << res;
    return 0;
}