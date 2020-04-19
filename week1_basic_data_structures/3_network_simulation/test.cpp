#include<bits/stdc++.h>
using namespace std;
/*2 5 0 417 0 842 0 919 0 732 418 414*/
int main() {
    int s,n;
    long long time=0,time1=0;
    queue<int>q;
    cin>>s>>n;
    vector<pair<long long,long long>>v (n);
    vector<int>out(n);
    for(int i=0;i<n;++i){
        cin>>v[i].first>>v[i].second;
    }
    for(int i=0;i<n;){
        if(q.size()<s){
            if(v[i].first>=time){
                out[i]=max(time1,v[i].first);
                q.push(v[i].second);
                time1+=v[i].second;
            }
            else{
                out[i]=-1;
            }
            ++i;
        }
        else{
            time+=q.front();
            q.pop();
        }
    }
    for(int i=0;i<n;++i){
        cout<<out[i]<<endl;
    }
    return 0;
}
