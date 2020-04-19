#include<bits/stdc++.h>
#define ll long long
ll p1=1000000007;
ll p2=1000000009;
ll x=911;
using namespace std;
vector<ll> h1;
vector<ll> h3;
vector<ll> pow1;
bool Equal(int t_s,int t_e,int p_s,int p_e){
    ll hash_1=((h1[t_e+1]-pow1[t_e-t_s+1]*h1[t_s])%p1+p1)%p1;
    ll hash_2=((h3[p_e+1]-pow1[p_e-p_s+1]*h3[p_s])%p1+p1)%p1;
    //cout<<t_s<<","<<t_e<<","<<p_s<<","<<p_e<<","<<endl;
    //cout<<hash_1<<","<<hash_2<<endl<<endl;
    if(hash_1==hash_2)
        return true;
    return false;
}

int Mismatch(int t_s,int t_e,int p_s,int p_e){
    if(t_e<t_s)
        return 0;
    if(Equal(t_s,t_e,p_s,p_e))
        return 0;
    else if(p_s==p_e&&t_s==t_e)
        return !Equal(t_s,t_e,p_s,p_e);
    else{
        //cout<<t_s<<","<<t_e<<","<<p_s<<","<<p_e<<","<<endl;
        int s1=(t_e+t_s)/2;
        int s2=(p_e+p_s)/2;
        return Mismatch(t_s,s1,p_s,s2)+Mismatch(s1+1,t_e,s2+1,p_e);
    }

}
vector<int> solve(int k, const string &t, const string &p) {
	vector<int> pos;
	int n=t.size();
	int m=p.size();
	h1.resize(n+1);
	h3.resize(m+1);
	pow1.resize(n+1);
	h1[0]=h3[0]=0;pow1[0]=1;
	for(int i=1;i<=n;++i){
        h1[i]=(h1[i-1]*x+(int)t[i-1])%p1;
        pow1[i]=pow1[i-1]*x%p1;
	}
    for(int i=1;i<=m;++i)
        h3[i]=(h3[i-1]*x+(int)p[i-1])%p1;


    //cout<<"k= "<<Mismatch(1,m,0,m-1)<<endl;

	for(int i=0;i<=n-m;++i){
        //cout<<"k= "<<Mismatch(i,m-1+i,0,m-1)<<endl;
        if((Mismatch(i,i+m-1,0,m-1))<=k)
            pos.push_back(i);
	}
	return pos;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int k;
	string t, p;
	while (cin >> k >> t >> p) {
		auto a = solve(k, t, p);
		cout << a.size();
		for (int x : a)
			cout << " " << x;
		cout << "\n";
	}
}
