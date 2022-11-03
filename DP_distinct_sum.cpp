/*Cho mảng A[] gồm N phần tử là số nguyên dương, xét tất cả các tập con của A[] và tính tổng các phần tử trong tập này (bao gồm cả tập rỗng), sau đó liệt kê các tổng khác nhau có thể tạo thành theo thứ tự tăng dần.

Input Format

Dòng đầu tiên là N : số lượng phần tử trong mảng; Dòng thứ 2 gồm N phần tử của mảng A[]

Constraints

1<=N<=100; 1<=A[i]<=100;

Output Format

In ra các tổng có thể tạo thành từ các tập con của A[]

Sample Input 0

3
4 1 2 
Sample Output 0

0 1 2 3 4 5 6 7 

*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n ; cin >> n;
    int a[n];
    for(int i = 0 ; i < n ;i++)
    {
        cin >>a[i];
    }
    int sum = accumulate(a , a + n , 0);
    int dp[sum + 1];
    memset(dp , false , sizeof(dp));
    dp[0] = true;
    for(int i = 0 ; i < n ;i++)
    {
        for(int j = sum ; j >= a[i] ; j--)
        {
            if(dp[j - a[i]])
            {
                dp[j] = true;
            }
        }
    }
    for(int i = 0 ; i <= sum ; i++)
    {
        if(dp[i])
        {
            cout << i << " ";
        }
    }
}