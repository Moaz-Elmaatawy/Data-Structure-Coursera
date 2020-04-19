#include<bits/stdc++.h>
using namespace std;

class Solver {
	string s;
	long long x=1111;
	long long p1=1000000007;
	long long p2=1000000009;
public:
    vector<long long>h1;
    vector<long long>h2;
    vector<long long>pow1;
    vector<long long>pow2;
	Solver(string s) : s(s) {
		int n=s.size();
		h1.resize(n+1);
		h2.resize(n+1);
		pow1.resize(n+1);
		pow2.resize(n+1);
		h1[0]=0;h2[0]=0;
		pow1[0]=1;pow2[0]=1;
		for(int i=1;i<=n;++i){
            h1[i]=(h1[i-1]*x+(int)s[i-1])%p1;
            h2[i]=(h2[i-1]*x+(int)s[i-1])%p2;
		}
		for(int i=1;i<=n;++i){
            pow1[i]=pow1[i-1]*x%p1;
            pow2[i]=pow2[i-1]*x%p2;
		}
	}

	bool ask(int a, int b, int l) {
		long long hash_1=(h1[a+l]-(pow1[l]*h1[a])%p1+p1)%p1;
		long long hash_2=(h1[b+l]-(pow1[l]*h1[b])%p1+p1)%p1;

		long long hash_1_2=(h2[a+l]-(pow2[l]*h2[a])%p2+p2)%p2;
		long long hash_2_2=(h2[b+l]-(pow2[l]*h2[b])%p2+p2)%p2;
		cout<<hash_1<<","<<hash_2<<endl<<hash_1_2<<","<<hash_2_2<<endl;
		if(hash_1==hash_2&&hash_1_2==hash_2_2)
            return true;
        return false;
	}
};

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	string s;
	int q;
	cin >> s >> q;
	Solver solver(s);
	for (int i = 0; i < q; i++) {
		int a, b, l;
		cin >> a >> b >> l;
		cout << (solver.ask(a, b, l) ? "Yes\n" : "No\n");
	}
}
