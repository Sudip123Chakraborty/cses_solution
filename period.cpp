#include <bits/stdc++.h>
#define lli long long int
#define p 1000000007

using namespace std;

string s;
lli n;
lli kmp[100010];

void get_kmp(){
	lli i,j;
	i=0;j=-1;kmp[0]=-1;
	while(i<n){
		while(j!=-1 && s[i]!=s[j]){
			j=kmp[j];
		}
		i++,j++;
		kmp[i]=j;
	}
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    lli t, T;

    cin>>T;
    t=1;
    while(t<=T){
    	cin>>n;
    	cin>>s;

    	get_kmp();
    	vector<pair<lli,lli>> ans;
    	for (int i = 2; i <= n; ++i)
    	{
    		lli size = i - kmp[i];
    		if (i%size==0 && size!=i)
    		{
    			ans.push_back({i,i/size});
    		}
    	}
    	cout<<"Test case #"<<t<<"\n";
    	// print answer after this
    	for (int i = 0; i < ans.size(); ++i)
    	{
    		cout<<ans[i].first<<" "<<ans[i].second<<"\n";
    	}

    	t++;
    	cout<<"\n";
    
    }

}