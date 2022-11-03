/*Có hoa hồng trong một cửa hàng. Mỗi bông hồng được chỉ định một ID. Những bông hồng này được sắp xếp theo thứ tự 1, 2, 3... n. Mỗi bông hồng có một hệ số mùi được ký hiệu là smell[i] . Bạn muốn mua hoa hồng ở cửa hàng này với điều kiện phải mua hoa hồng theo phân khúc. Nói cách khác, bạn có thể mua hoa hồng từ đến l đến r. Bạn có thể loại bỏ nhiều nhất một hoa hồng khỏi phân đoạn hoa hồng này. Như vậy, chiều dài cuối cùng của hoa hồng là n hoặc n - 1. Nhiệm vụ của bạn là tính toán độ dài tối đa có thể có của dãy liền kề tăng dần các hệ số mùi của những bông hoa hồng này.

Input Format

Dòng 1 chứa số nguyên n; Dòng thứ 2 chứa n số smell[1], smell[2], .. smell[n]

Constraints

2<=n<=2.10^5; 1<=smell[i]<=10^9

Output Format

In ra đáp án của bài toán

Sample Input 0

5
1 2 5 3 4
Sample Output 0

4
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n ; cin >> n ; 
    int a[n];
    for(int i = 0 ; i < n;i++) cin >> a[i];
    vector<int>job1(n , 1) ; vector<int>job2(n , 1);
    int ans = 0;
    for(int i = 1 ; i < n  ;i++)
    {
        if(a[i - 1] < a[i])
        {
            job1[i] = job1[i - 1] + 1;
        }
        ans = max(ans , job1[i]);
    }
    for(int i = n - 2 ; i >= 0 ; i--)
    {
        if(a[i] < a[i + 1])
        {
            job2[i] = job2[i + 1] + 1;
        }
        ans = max(ans , job2[i]);
    }
    for(int i = 1 ; i < n - 1 ; i++)
    {
        if(a[i -1] < a[i + 1])
        {
            ans = max(ans , job1[i - 1] + job2[i + 1]);
        }
    }
    cout << ans;
}