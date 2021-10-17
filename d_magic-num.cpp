#include <bits/stdc++.h>
#define lli long long int
#define p 1000000007

using namespace std;

string a,b;
lli m, d, len,haa;

lli dp[2002][2][2][2002];
lli rec(lli level, lli lbo, lli rbo, lli sum){
	// base case
	if (level==len)
	{
		if (sum==0)
		{
			return 1;
		}
		return 0;
	}

	//memoisation
	if(dp[level][lbo][rbo][sum] != -1){
		return dp[level][lbo][rbo][sum];
	}


	//calculate ans
	lli tlo = 0;
	lli thi = 9;
	if (lbo)
	{
		tlo = (a[level]-'0');
	}
	if (rbo)
	{
		thi = (b[level]-'0');
	}
	lli ans = 0;
	if (level%2==1)
	{
		if (d>=tlo && d<=thi)
		{
			lli nlbo = lbo;
			lli nrbo = rbo;
			if (d!=tlo)
			{
				nlbo = 0;
			}
			if (d!=thi)
			{
				nrbo = 0;
			}
			ans += rec(level+1, nlbo, nrbo, (10*sum+d)%m);
			ans %= p;
		}
	}else{
		for (int i = tlo; i <= thi; ++i)
		{
			lli nlbo = lbo;
			lli nrbo = rbo;
			if (i!=tlo)
			{
				nlbo = 0;
			}
			if (i!=thi)
			{
				nrbo = 0;
			}
			if (i!=d)
			{
				//cout<<"hii"<<i<<endl;
				ans += rec(level+1, nlbo, nrbo, (10*sum+i)%m);
				ans %= p;
			}
			
		}

	}

	return (dp[level][lbo][rbo][sum] = ans);
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    lli n, t;
    cin>>t;

    while(t--){
    	cin>>m>>d;
    	cin>>a;
    	cin>>b;
    	len = a.length();

    	memset(dp,-1,sizeof(dp));

    	cout<<rec(0,1,1,0)<<"\n";
    
    }

}