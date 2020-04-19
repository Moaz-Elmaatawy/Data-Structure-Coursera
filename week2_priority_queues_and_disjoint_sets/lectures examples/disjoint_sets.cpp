#include<bits/stdc++.h>

using namespace std;
class disjoint{
    int *parent;
    int *Rank;
    public:
    disjoint(int i){
        parent=new int[i];
        Rank=new int[i];
    }

    void Make_set(int i){
        parent[i]=i;
        Rank[i]=0;
    }

    int Find(int i){
        if(i!=parent[i]){
            parent[i]=Find(parent[i]);
        }
        return parent[i];
    }
    void Union(int i,int j){
        int i_id=Find(i);
        int j_id=Find(j);
        if(i_id==j_id)
            return;
        if(Rank[i_id]<Rank[j_id]){
            parent[i_id]=j_id;
        }
        else{
            parent[j_id]=i_id;
            if(Rank[i_id]==Rank[j_id])
                ++Rank[i_id];
        }
    }
};


int main(){
    disjoint koko(10);
    koko.Make_set(1);
    koko.Make_set(2);
    koko.Make_set(3);
    koko.Make_set(4);
    koko.Union(2,3);
    koko.Union(2,1);
    koko.Union(4,1);
    cout<<koko.Find(3)<<","<<koko.Find(4)<<","<<koko.Find(1)<<",";
return 0;
}
