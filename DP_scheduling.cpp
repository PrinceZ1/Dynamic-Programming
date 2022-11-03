/*Có n dự án bạn có thể tham dự. Đối với mỗi dự án, bạn biết ngày bắt đầu và ngày kết thúc của dự án và số tiền bạn sẽ nhận được khi hoàn thành nó. Bạn chỉ có thể tham dự một dự án trong một ngày. Số tiền tối đa bạn có thể kiếm được là bao nhiêu?

Input Format

Dòng đầu tiên chứa số nguyên n: số lượng dự án. Sau đó, có n dòng. Mỗi dòng như vậy có ba số nguyên ai, bi và pi: ngày bắt đầu, ngày kết thúc và tiền thưởng.

Constraints

1≤n≤2⋅10^5; 1≤ai≤bi≤10^9; 1≤pi≤10^9;

Output Format

In ra đáp án của bài toán

Sample Input 0

4
2 4 4
3 6 6
6 8 2
5 7 3
Sample Output 0

7
*/

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define mpr make_pair
#define all(a) a.begin(),a.end()
#define ms(a,n) memset(a , n , sizeof(a))
#define FOR(i,a,b) for(int i = a ; i <= b ;i++)
#define RFOR(i,a,b) for(int i = b ; i >= a ; i--)
#define factphuongdz() ios::sync_with_stdio(NULL);cout.tie(NULL);

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll>pl;
typedef vector<ll>vll;
typedef vector<int>vii;
typedef pair<int,int>pi;
const int MOD = 1e9 + 7;

struct Fly
{
    int f , s , w;
};

int flyCamp(Fly a[] , int n)
{
    int l = 0 , r = n - 1 , res = -1;
    while(l <= r)
    {
        int m = (l + r) / 2;
        if(a[m].s < a[n].f)
        {
            res = m;
            l = m + 1;
        }
        else r = m - 1;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(NULL);cout.tie(NULL);
    int n ; cin >> n;
    Fly a[n];
    for(int i = 0 ;i < n ;i++)
    {
        cin >> a[i].f >> a[i].s >> a[i].w;
    }
    sort(a , a + n , [](Fly a , Fly b)->bool
    {
        return a.s < b.s;    
    });
    ll ans[n];
    ans[0] = a[0].w;
    for(int i = 1 ; i < n ; i++)
    {
        ll res = a[i].w;
        int l = flyCamp(a , i);
        if(l != -1)
        {
            res += ans[l];
        }
        ans[i] = max(res , ans[i - 1]);
    }
    ll kq = ans[n - 1];
    cout << kq;
    return 0;
}