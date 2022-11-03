/*Bạn được cung cấp một mảng A gồm N giá trị nguyên dương. Một mảng con của mảng này được gọi là mảng con Chẵn lẻ nếu số lượng các số nguyên lẻ trong mảng con này bằng số lượng các số nguyên chẵn trong mảng con này.

Tìm số mảng con Lẻ-Chẵn cho mảng đã cho.

Input Format

Dòng đầu chứa N; Dòng thứ 2 chứa N số nguyên trong dãy

Constraints

1<=N<=2.10^5; 1<=A[i]<=10^9;

Output Format

In ra đáp án của bài toán

Sample Input 0

4
1 2 1 2
Sample Output 0

4
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MOD = 1e9 + 7;

int main()
{
    map<int,int>mp;
    int n ; cin >> n;
    mp[0] = 1;
    int chan = 0 , le = 0 , res = 0;
    for(int i = 1 ; i <= n ; i++)
    {
        int x ; cin >> x;
        if(x % 2 == 0) ++chan;
        else ++le;
        if(mp.find(chan - le) != mp.end())
        {
            res +=  mp[chan - le];
        }
        mp[chan - le]++;
    }
    cout << res;
    return 0;
}