#include <iostream>
#include <vector>
#include <deque>
using namespace std;


void max_sliding_window_naive(vector<int>  v, int k , int n) {
    deque<int>d;
    d.push_front(0);
    for(int i=1;i<k;++i){
        if(v[i]>v[d.back()]&&d.empty()!=1){
            while(d.empty()!=1&&v[i]>v[d.back()]){
                d.pop_back();
            }
            d.push_back(i);
        }
        else{
            d.push_back(i);
        }
    }
    cout<<v[d.front()];
    //cout<<endl<<d.size()<<endl;;
    /*for (int i=0;i<d.size();++i){
        cout<<v[d.front()]<<",";
        d.pop_front();
    }
    cout<<endl;*/

    for (int i=k;i<n;++i){
        if(v[i]>v[d.back()]){
            while(d.empty()!=1&&v[i]>v[d.back()]){
                d.pop_back();
            }
            d.push_back(i);
        }
        else{
            d.push_back(i);
        }
        if(d.front()<i-k+1){
            d.pop_front();
        }
        cout<<" "<<v[d.front()];
    }


    return ;
}


int main() {
    int n = 0;
    cin >> n;

    vector<int> A(n);
    for (size_t i = 0; i < n; ++i)
        cin >> A.at(i);

    int w = 0;
    cin >> w;

    max_sliding_window_naive(A, w ,n);

    return 0;
}
