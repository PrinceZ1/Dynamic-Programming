/*Một tên trộm có 1 cái túi có thể mang các đố vật với trọng lượng tối đa là V. Hiện tại tên trộm muốn lựa chọn các đồ vật trong N đồ vật để ăn trộm, mỗi đồ vật có trọng lượng là w[i] và giá trị là v[i]. Hãy xác định tổng giá trị lớn nhất của các đồ vật mà tên trộm này lựa chọn sao cho trọng lượng của chúng không vượt quá V.

Input Format

Dòng đầu ghi 2 số N và V. Dòng tiếp theo ghi N số của mảng w. Sau đó là một dòng ghi N số của mảng v.

Constraints

V<=1000; N≤1000; 1<=w[i], c[i]<=500;

Output Format

In ra giá trị lớn nhất có thể đạt được.

Sample Input 0

6 22
39 44 4 59 91 70 
47 26 92 33 6 69 
Sample Output 0

92
Sample Input 1

7 22
10 3 22 50 83 16 41 
99 97 54 19 50 70 48 
Sample Output 1

196
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

struct bag
{
    int kg , gt;
};
int main()
{
    int n , m ; cin >> n >> m;
    bag a[n + 1]; 
    for(int i = 1 ; i <= n; i++) cin >> a[i].kg;
    for(int i = 1 ; i <= n ;i++) cin >> a[i].gt;
    int dp[n + 1][m + 1];
    memset(dp , 0 , sizeof(dp));
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 0 ; j <= m ; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if(j >= a[i].kg)
            {
                dp[i][j] = max(dp[i][j] , dp[i - 1][j - a[i].kg] + a[i].gt);
            }
        }
    }
    cout << dp[n][m];
}