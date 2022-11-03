/*Cho bảng A[] kích thước N x M (N hàng, M cột). Bạn được phép đi xuống dưới, đi sang phải và đi xuống ô chéo dưới về bên phải. Khi đi qua ô (i, j), điểm nhận được bằng A[i][j]. Hãy tìm đường đi từ ô (1, 1) tới ô (N, M) sao cho tổng điểm là lớn nhất.

Input Format

Dòng 1 gồm số nguyên dương N và M; N dòng tiếp theo, mỗi dòng gồm M số nguyên A[i][j];

Constraints

1<=N,M<=500; 1<=A[i][j]<=1000;

Output Format

In ra kết quả của bài toán

Sample Input 0

5 5
1 0 31 5 25 
28 26 32 46 7 
26 40 36 13 16 
7 26 14 6 11 
42 45 11 10 21 
Sample Output 0

208
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n , m ; cin >> n >> m;
    int a[n][m];
    for(int i = 0 ; i < n ;i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            cin >> a[i][j];
        }
    }
    for(int i = 0 ; i < n ;i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            if(i == 0 && j == 0)
            {
                a[i][j] = a[i][j];
            }
            else if(i == 0)
            {
                a[i][j] += a[i][j - 1];
            }
            else if(j == 0)
            {
                a[i][j] += a[i - 1][j];
            }
            else
            {
                a[i][j] += max(a[i - 1][j] , max(a[i][j - 1] , a[i - 1][j - 1]));
            }
        }
    }
    cout << a[n - 1][m - 1];
}