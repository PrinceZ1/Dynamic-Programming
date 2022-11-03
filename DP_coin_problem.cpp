/*Ngân hàng XYZ hiện có N tờ tiền có mệnh giá khác nhau được lưu vào mảng C[], bạn hãy tìm cách đổi số tiền là S sao cho số tờ tiền cần dùng là ít nhất. Bạn được sử dụng một mệnh giá không giới hạn số lần.

Input Format

Dòng đầu tiên chứa 2 số N và S; Dòng thứ 2 chưa N số là mệnh giá các tờ tiền;

Constraints

1<=N<=100; 1<=S<=10^6; 1<=C[i]<=10^6;

Output Format

In ra số tờ tiền nhỏ nhất cần đổi. Nếu không thể đổi được số tiền đúng bằng S thì in ra -1.

Sample Input 0

3 10
4 5 8
Sample Output 0

2
*/

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int MOD = 1e9;

int main()
{
    int n , m ; cin >> n >> m;
    int a[n] ,arr[m+1] = {0};
    for(int &x : a) cin >> x;
    arr[0] = 0;
    for(int i = 1 ; i <= m ; i++)
    {
        arr[i] = MOD;
        for(int j = 0 ; j < n ; j++)
        {
            if(i >= a[j])
            {
                arr[i] = min(arr[i] , arr[i - a[j]] + 1);
            }
        }
    }
    if(arr[m] >= MOD) cout <<-1;
    else cout << arr[m];
    return 0;
}