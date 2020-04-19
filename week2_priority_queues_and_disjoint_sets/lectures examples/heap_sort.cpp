#include<bits/stdc++.h>

using namespace std;

class priority{

public:
    int *v;
    int max_size;
    int curr_size;

    priority(int i){v=new int[i];curr_size=0;max_size=i;}
    int parent(int i){return (i-1)/2;}
    int left_child(int i){return 2*i+1;}
    int right_child(int i){return 2*i+2;}
    void sift_up(int i){
        while(i>-1&&v[i]>v[parent(i)]){
            swap(v[i],v[parent(i)]);
            i=parent(i);
        }
    }
    void push(int i){
        if(max_size==curr_size){
            cout<<"over flow"<<endl;
        }
        else{
            v[curr_size]=i;
            sift_up(curr_size);
            ++curr_size;
        }
    }
    void sift_down(int i){
        int max_index=i;
        int l=left_child(i);
        int r=right_child(i);
        if(l<curr_size && v[l]>v[i]){
            max_index=l;
        }
        if(r<curr_size && v[r]>v[max_index]){
            max_index=r;
        }
        if(i!=max_index){
            swap(v[i],v[max_index]);
            sift_down(max_index);
        }
    }
    int extract_max(){
        if(curr_size==0){
            cout<<"empty"<<endl;
        }
        else{
            int result=v[0];
            v[0]=v[curr_size-1];
            --curr_size;
            sift_down(0);
            return result;
        }
    }
    void Remove(int i){
        v[i]=INT_MAX;
        sift_up(i);
        extract_max();
    }
    void print(void){
        for(int i=0;i<curr_size;++i){cout<<v[i]<<",";}
        cout<<endl;
    }

    void change_priority(int i,int p){
        if(v[i]>p){
            v[i]=p;
            sift_down(i);
        }
        else if(v[i]<p){
            v[i]=p;
            sift_up(i);
        }
    }
    void build_heap(){
        int k=parent(curr_size);
        for(int i=k;i>-1;--i){
            sift_down(i);
        }
    }
    void heap_sort(){
        build_heap();
        while(curr_size){
            cout<<extract_max()<<"-";
        }
    }

};

int main(){
    int a[10]={10,8,7,6,3,555,4,2,9,1};
    priority koko(10);
    koko.v=a;
    koko.curr_size=10;
    koko.max_size=10;
    koko.heap_sort();


return 0;
}
