/*John có một đàn bò. Một ngày đẹp trời, anh ta quyết định mua xe tải với khả năng chở được C kg (1000 ≤ C ≤ 25000) để đưa những con bò đi xem phim. Cho số con bò là N (20 ≤ N ≤ 100) và khối lượng w[i] của từng con (đều nhỏ hơn C), hãy cho biết khối lượng bò lớn nhất mà John có thể đưa đi xem phim là bao nhiêu.

Input Format

Dòng 1: 2 số nguyên C và N cách nhau bởi dấu cách; Dòng 2: Ghi lần lượt các số nguyên: w[i]

Constraints

1000 ≤ C ≤ 25000; 20 ≤ N ≤ 100; w[i] <= C;

Output Format

Một số nguyên là tổng khối lượng bò lớn nhất mà John có thể mang đi xem phim.

Sample Input 0

259 5
81 58 42 33 61
Sample Output 0

242
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main()
{
    int m , n ; cin >> m >> n;
    int a[n];
    for(int i = 0 ; i < n ;i++) 
    {
        cin >> a[i];
    }
    bool dp[m + 1];
    memset(dp, false, sizeof(dp));
    dp[0] = true;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = m ; j >= a[i] ; j--)
        {
            if(dp[j - a[i]])
            {
                dp[j] = true;
            }
        }
    }
    for(int i = m ; i >= 1 ; i--)
    {
        if(dp[i])
        {
            cout << i ;
            return 0;
        }
    }
}