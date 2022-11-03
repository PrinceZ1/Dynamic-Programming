/*Cho mảng số nguyên A[] gồm N phần tử và số nguyên dương S, nhiệm vụ của bạn hãy xác định xem có thể tạo ra một tập con các phần tử trong mảng có tổng bằng S hay không? Chú ý mỗi phần tử trong mảng chỉ được sử dụng một lần.

Input Format

Dòng đầu tiên gồm 2 số N và S; Dòng thứ 2 gồm N số của mảng A;

Constraints

1<=N<=200; 1<=S<=50000; 1<=A[i]<=500;

Output Format

In ra 1 nếu có tập con của A có tổng bằng S, ngược lại in ra 0

Sample Input 0

8 92
69 16 82 170 31 24 45 112 
Sample Output 0

1
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main()
{
    int n , s ; cin >> n >> s;
    int a[n]; 
    for(int i = 0 ; i < n ; i++)
    {
        cin >> a[i] ;
    }
    bool dp[s + 1];
    memset(dp, false, sizeof(dp));
    dp[0] = true;
    for(int i = 0 ; i < n ;i++)
    {
        for(int j = s ; j >= a[i] ; j--)
        {
            if(dp[j - a[i]])
            {
                dp[j] = true;
            }
        }
    }
    if(dp[s]) cout << 1;
    else cout << 0;
}