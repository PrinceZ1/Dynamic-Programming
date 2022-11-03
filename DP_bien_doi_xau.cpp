/*Cho hai xâu ký tự str1, str2 bao gồm các ký tự in thường và các thao tác dưới đây: Insert: chèn một ký tự bất kỳ vào str1. Delete: loại bỏ một ký tự bất kỳ trong str1. Replace: thay một ký tự bất kỳ trong str1. Nhiệm vụ của bạn là đếm số các phép Insert, Delete, Replace ít nhất thực hiện trên str1 để trở thành str2.

Input Format

Dòng 1 là xâu str1; Dòng 2 là xâu str2;

Constraints

1<=len(str1), len(str2)<=100;

Output Format

Đưa ra kết quả của bài toán

Sample Input 0

geek gesek
Sample Output 0

1
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    string s1 , s2 ; cin >> s1 >> s2;
    int n = s1.length() , m = s2.length();
    int dp[n + 1][m + 1];
    for(int i =0 ; i <= n ; i++)
    {
        for(int j = 0 ;j <= m ; j++)
        {
            if(i == 0 || j == 0)
            {
                dp[i][j] = i + j;
            }
            else if(s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = min(dp[i - 1][j - 1] , min(dp[i - 1][j] , dp[i][j - 1])) + 1;
            }
        }
    }
    cout << dp[n][m];
}