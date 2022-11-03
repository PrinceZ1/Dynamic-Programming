/*Bạn biết rằng một mảng có n số nguyên chỉ gồm các số từ 1 đến m và độ lệch giữa 2 phần tử liền kề trong mảng không được vượt quá 1 đơn vị. Bài toán đặt ra đó là cho bạn một mảng trong đó một số giá trị trong mảng chưa được xác định giá trị, nhiệm vụ của bạn là đếm số mảng phù hợp với mô tả, đó là các số liền kề trong mảng không lệch nhau quá 1 đơn vị và các giá trị trong mảng chỉ được nằm trong đoạn từ 1 tới m.

Input Format

Dòng nhập đầu tiên có hai số nguyên n và m: kích thước mảng và giới hạn trên cho mỗi giá trị.

Dòng tiếp theo có n số nguyên x1, x2,…, xn: nội dung của mảng. Giá trị 0 biểu thị một giá trị không xác định.

Constraints

1≤n≤10^5;
1≤m≤100; 0≤xi≤m;

Output Format

In ra số lượng mảng phù hợp sau khi chia dư cho 1e9 + 7

Sample Input 0

3 5
2 0 2
Sample Output 0

3
Explanation 0

Các mảng có thể thỏa mãn : [2, 1, 2], [2, 2, 2], [2, 3, 2]
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll v[100001][100];
const int MOD = 1e9 + 7;
int main()
{
    int n , m ; cin >> n >> m;
    int a[n + 1];
    for(int i = 0 ; i < n ;i++) cin >> a[i];
    
    if(a[0] != 0)
    {
        v[0][a[0]] = 1;
    }
    else
    {
        for(int i = 1 ; i <= m ; i++)
        {
            v[0][i] = 1;
        }
    }
    for(int i = 1 ; i < n ; i++)
    {
        if(a[i] == 0)
        {
            for(int j = 1 ; j <= m ; j++)
            {
                for(int k = -1 ; k <= 1 ; k++)
                {
                    int ans = j + k;
                    if(ans >= 1 && ans <= m)
                    {
                        v[i][j] += v[i - 1][ans];
                         v[i][j] %= MOD;
                    }
                }
            }
        }
        else
        {
            for(int k = -1 ; k <= 1 ; k++)
            {
                int ans = a[i] + k;
                if(ans >= 1 && ans <= m)
                {
                    v[i][a[i]] += v[i - 1][ans];
                    v[i][a[i]] %= MOD;
                }
            }
        }
    }
    ll sum = 0;
    for(int i = 1 ; i <= m ; i++)
    {
        sum += v[n - 1][i];
        sum %= MOD;
    }
    cout << sum;
}