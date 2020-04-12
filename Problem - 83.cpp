#include <bits/stdc++.h>

using namespace std;

string mul(string num, int n)
{
    string ans;
    int carry = 0;
    for(int i = num.length()-1; i >= 0; i--)
    {
        int m = (num[i]-'0') * n + carry;
        if(m > 9)
        {
            m -= 10;
            carry = 1;
        }
        else carry = 0;
        ans.push_back(m + '0');
    }
    if(carry) ans.push_back(carry + '0');
    reverse(ans.begin(), ans.end());
    return ans;
}
bool isBig(string a, string b)
{
    int n1 = a.length(), n2 = b.length();
    if(n1 > n2) return 1;
    if(n2 > n1) return 0;
    for(int i = 0; i < n1; i++)
        if(b[i] > a[i]) return 0;
    return 1;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string num, ans = "1";
        cin>>num;
        while(1)
        {
            ans = mul(ans, 2);
            if((ans == num) || (num == "1"))
            {
                cout<<"It's a power of 2"<<endl;
                break;
            }
            else if(isBig(ans, num))
            {
                cout<<"Not a power of 2"<<endl;
                break;
            }
        }
    }
    return 0;
}
