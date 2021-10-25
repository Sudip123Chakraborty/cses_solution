#include <bits/stdc++.h>
#define lli long long int
#define p 1000000007

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    lli n, t;

    cin>>n;
    lli ans = n;
    for (int i = 2; i*i <= n; ++i)
    {
    	if (n%i==0)
    	{
    		ans /= i;
    		ans *= (i-1);
    		while(n%i==0){
    			n/=i;
    		}
    	}
    }

    if (n>1)
    {
    	ans/=n;
    	ans*=(n-1);
    }

    cout<<ans<<"\n";

}