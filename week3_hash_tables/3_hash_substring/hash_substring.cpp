#include<bits/stdc++.h>
using namespace std;
typedef  long long ull;

struct Data {
    string pattern, text;
};

Data read_input() {
    Data data;
    cin >> data.pattern >> data.text;
    return data;
}

void print_occurrences(const vector<int>& output) {
    for (ull i = 0; i < output.size(); ++i)
        cout << output[i] << " ";
    cout << "\n";
}

ull polyhash(string s){
    ull x=263;
    ull p=1000000007;
    ull Hash=0;
    int n=s.size();
    for(int i=n-1;i>=0;--i)
        Hash=(Hash*x+(int)s[i])%p;
    return Hash;
}
vector<ull> precompute(string t,int p_size){
    ull x=263;
    ull P=1000000007;
    int n=t.size()-p_size+1;
    vector<ull>h(n);
    h[n-1]=polyhash(t.substr(t.size()-p_size,p_size));
    ull y=1;
    for(int i=0;i<p_size;++i)
            y=(y*x)%P;
    for(int i=n-2;i>=0;--i){
        h[i]=((((ull)t[i]+x*h[i+1])-((ull)t[i+p_size])*y)%P+P)%P;
        //cout<<(ull)t[i]<<" , "<<(ull)t[i+p_size]<<" i= "<<i<<" ,y= "<<y<<" ans= "<<((ull)t[i]+x*h[i+1]-((ull)t[i+p_size])*y)<<" h[i+1]= "<<h[i+1]<<endl;
    }

    return h;
}

vector<int> get_occurrences(const Data& input) {
    const string& s = input.pattern, t = input.text;
    vector<int> ans;
    ull p_hash=polyhash(s);
    //cout<<p_hash<<endl;
    vector<ull>h=precompute(t,s.size());
   // cout<<h.back()<<endl;
    //cout<<polyhash(t.substr(0,s.size()))<<"--->"<<h[0]<<endl;

    int n=t.size()-s.size()+1;
    for(int i=0;i<n;++i){
        if(p_hash!=h[i]){
                //cout<<"i= "<<i<<"--> h[i]= "<<h[i]<<"\n";
            continue;
        }
        if(!s.compare(t.substr(i,s.size())))
            ans.push_back(i);
    }
    return ans;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    print_occurrences(get_occurrences(read_input()));
    return 0;
}
