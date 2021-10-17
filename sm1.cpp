#include <bits/stdc++.h>
#define lli long long int
#define p 1000000007

using namespace std;
lli n;
lli dp[1000010][4];
lli rec(lli level, lli pos){
	if (level==1000001)
	{
		return 1;
	}

	if (dp[level][pos]!=-1)
	{
		return dp[level][pos];
	}

	lli ans = 0;
	if (pos==0)
	{
		ans+=rec(level+1, 0);
		ans%=p;
		ans+=rec(level+1, 1);
		ans%=p;
	}
	if (pos==1)
	{
		ans+=rec(level+1, 1);
		ans%=p;
		ans+=rec(level+1, 2);
		ans%=p;
	}
	if (pos==2)
	{
		ans+=rec(level+1, 3);
		ans%=p;
		ans+=rec(level+1, 0);
		ans%=p;
	}
	if (pos==3)
	{
		ans+=rec(level+1, 2);
		ans%=p;
	}

	return (dp[level][pos]=ans);
}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    lli t;
    cin>>t;
    memset(dp,-1,sizeof(dp));
    //cout<<"hi"<<endl;
    rec(0,0);

    while(t--){
    	cin>>n;
    	cout<<dp[1000001-n][0]<<"\n";

    
    }

}