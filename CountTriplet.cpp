#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    long n,r;
    cin >> n >> r;

    map<int,long> mp2, mp3;

    int val;
    long long res = 0;
    while(n--)
    {
        cin >> val;
        if (mp3.count(val))        
            res += mp3[val];
        if (mp2.count(val))      
            mp3[val*r] += mp2[val];
        mp2[val*r]++;           
    }

    cout << res << endl;

    return 0;
}