#include<bits/stdc++.h>
using namespace std;
class disjoint{
    vector<int>parent;
    vector<int>Rank;
    vector<int>Max;
    int n, m,maxz;
	vector<int>rows;
	vector<pair<int ,int>>pairs;
    public:

    void read_data(){
        cin >> n >> m;
        rows.resize(n);
        parent.resize(n);
        Rank.resize(n);
        Max.resize(n);
        pairs.resize(m);
        for(int i=0;i<n;++i){
            cin>>rows[i];
            Max[i]=rows[i];
            Rank[i]=0;
            parent[i]=i;
        }
        for(int i=0;i<m;++i){
            cin>>pairs[i].first>>pairs[i].second;
            --pairs[i].first;--pairs[i].second;
        }
        maxz=*max_element(Max.begin(),Max.end());
    }
    void solve(){
        for(int i=0;i<m;++i){
            cout<<Union(pairs[i].first,pairs[i].second)<<endl;
        }
    }
    int Find(int i){
        if(i!=parent[i]){
            parent[i]=Find(parent[i]);
        }
        return parent[i];
    }

    int Union(int i,int j){
        int i_id=Find(i);
        int j_id=Find(j);
        if(i_id==j_id)
            return maxz;

        if(Rank[i_id]<Rank[j_id]){
            parent[i_id]=j_id;
            //cout<<"---->"<<Max[j_id]<<" ->"<<i_id<<","<<Max[i_id]<<" ->"<<j_id<<endl;
            Max[j_id]+=Max[i_id];
            maxz=max(maxz,Max[j_id]);
        }
        else{
            parent[j_id]=i_id;
            //cout<<"---->"<<Max[j_id]<<" ->"<<i_id<<","<<Max[i_id]<<" ->"<<j_id<<endl;
            Max[i_id]+=Max[j_id];
            maxz=max(maxz,Max[i_id]);
            if(Rank[i_id]==Rank[j_id])
                ++Rank[i_id];
        }
        return maxz;
    }
};

int main() {
    disjoint ans;
    ans.read_data();
    ans.solve();

	return 0;
}
