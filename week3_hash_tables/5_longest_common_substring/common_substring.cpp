#include<bits/stdc++.h>
#define ll long long

using namespace std;

struct Answer {
	size_t i, j, len;
};
ll p1=1000000007;
ll p2=1000004249;
ll x=911;
Answer max_subsequence(string s,string t,int l){
    Answer ans = {0, 0, 0};
    int n=s.size();
    int m=t.size();
    vector<ll>h1(n+1);
    vector<ll>h2(n+1);
    vector<ll>h3(m+1);
    vector<ll>h4(m+1);
    vector<ll>pow1(max(n,m)+1);
    vector<ll>pow2(max(n,m)+1);

    unordered_map<int,int>m1;
    unordered_map<int,int>m2;

    h1[0]=h2[0]=h3[0]=h4[0]=0;pow1[0]=pow2[0]=1;

    for(int i=1;i<=n;++i){
        h1[i]=(h1[i-1]*x+s[i-1])%p1;
        h2[i]=(h2[i-1]*x+s[i-1])%p2;
    }
    //cout<<h1[1]<<","<<h1[2]<<","<<h1[3]<<","<<h1[4]<<endl;

    for(int i=1;i<=m;++i){
        h3[i]=(h3[i-1]*x+t[i-1])%p1;
        h4[i]=(h4[i-1]*x+t[i-1])%p2;
    }
    //cout<<h3[1]<<","<<h3[2]<<","<<h3[3]<<","<<h3[4]<<endl;

    for(int i=1;i<=max(n,m);++i){
        pow1[i]=pow1[i-1]*x%p1;
        pow2[i]=pow2[i-1]*x%p2;
    }

    for(int i=0;i<=n-l;++i){
        ll a=((h1[i+l]-pow1[l]*h1[i])%p1+p1)%p1;
        ll b=((h2[i+l]-pow2[l]*h2[i])%p2+p2)%p2;
        //cout<<a<<","<<b<<endl;
        m1.insert(make_pair(a,i+1));
        m2.insert(make_pair(b,i+1));
    }
    for(int i=0;i<=m-l;++i){
        ll c=((h3[i+l]-pow1[l]*h3[i])%p1+p1)%p1;
        ll d=((h4[i+l]-pow2[l]*h4[i])%p2+p2)%p2;
        //cout<<c<<","<<d<<endl;
        if(m1[c]!=0&&m2[d]!=0)
            return {m2[d]-1,i,l};

    }
    return {0,0,0};
}
Answer solve(const string &s, const string &t) {
    Answer ans = {0, 0, 0};
    int n=s.size();
    int m=t.size();
    int r=min(n,m);
    int l=0;
    int mid;
    while(l <=r){
        mid=(l+r)/2;
        ans=max_subsequence(s,t,mid);
        if(ans.len==0)
            r=mid-1;
        else
            l=mid+1;
    }
	return max_subsequence(s,t,r);
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	string s, t;
	while (cin >> s >> t) {
		auto ans = solve(s, t);
		cout << ans.i << " " << ans.j << " " << ans.len << "\n";
	}
}
