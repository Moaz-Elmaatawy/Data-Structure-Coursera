#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class HeapBuilder {
 private:
  vector<int> data_;
  vector< pair<int, int> > swaps_;

  void WriteResponse() const {
    cout << swaps_.size() << "\n";
    for (int i = 0; i < swaps_.size(); ++i) {
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
  }

  void ReadData() {
    int n;
    cin >> n;
    data_.resize(n);
    for(int i = 0; i < n; ++i)
      cin >> data_[i];
  }

  void sift_down(int i){
    int n=data_.size();
    int l=2*i+1;
    int r=2*i+2;
    int max_index=i;
    if(l<n&&data_[l]<data_[i]){
        max_index=l;
    }
    if(r<n&&data_[r]<data_[max_index]){
        max_index=r;
    }
    if(i!=max_index){
        swaps_.push_back(make_pair(i,max_index));
        swap(data_[i],data_[max_index]);
        sift_down(max_index);
    }
  }
  void build_heap(){
    int n=data_.size();
    n=(n-2)/2;
    for(int i=n;i>=0;--i){
        sift_down(i);
    }
  }

  void GenerateSwaps() {
    swaps_.clear();
    build_heap();
  }

 public:
  void Solve() {
    ReadData();
    GenerateSwaps();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}
