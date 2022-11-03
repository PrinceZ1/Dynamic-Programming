/*Bạn được cung cấp một mảng chứa n số nguyên. Nhiệm vụ của bạn là xác định dãy con dài nhất tăng dần trong mảng, tức là dãy con dài nhất mà mọi phần tử đều lớn hơn phần tử trước đó. Một dãy con là một dãy có thể được dẫn xuất từ mảng bằng cách xóa một số phần tử mà không làm thay đổi thứ tự của các phần tử còn lại.

Input Format

Dòng đầu tiên chứa số nguyên n: kích thước của mảng. Sau đó có n số nguyên x1, x2,…, xn: nội dung của mảng.

Constraints

1≤n≤2⋅10^5; 1≤xi≤10^9;

Output Format

In ra chiều dài của dãy con tăng dài nhất

Sample Input 0

6
1 2 4 1 5 2
Sample Output 0

4
Sample Input 1

5
1 1 1 1 1
Sample Output 1

1
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n ; cin >> n;
    int a[n];
    for(int i = 0 ; i < n ;i++) cin >> a[i];
    vector<int>v(1 , 1e9 + 1);
    for(int i = 0 ; i < n ; i++)
    {
        auto l = lower_bound(v.begin() , v.end() , a[i]);
        if(l != v.end())
        {
            *l = a[i];
        }
        else v.push_back(a[i]);
    }
    cout << v.size();
}