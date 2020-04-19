#include<bits/stdc++.h>
using namespace std;

class JobQueue {
 private:
  long long n;
  vector<long long> v;
  vector<pair<long long ,long long>> out;

  void WriteResponse() const {
    for (long long i = 0; i < v.size(); ++i) {
      cout << -out[i].first << " " << out[i].second << "\n";
    }
  }

  void ReadData() {
    long long m;
    cin >> n>> m;
    v.resize(m);
    for(long long i = 0; i < m; ++i){
      cin >> v[i];
      v[i]=-v[i];
    }
  }

  void AssignJobs() {
    pair<long long,pair<long long,long long>>g;
    long long m=v.size();
    long long time=0;
    int name=0;
    out.resize(m);
    priority_queue<pair<long long,pair<long long,long long>>> pq;
    int counter=0;
    for(long long i=0;(i<n&&i<m);++i){

        if(v[i]!=0){
            pq.push(make_pair(v[i],make_pair(-name,time)));
            out[i].first=-name;
            out[i].second=0;
            ++name;
        }
        else{
            //pq.pop();
            out[i].first=-name;
            out[i].second=0;
            ++n;
        }
        ++counter;
    }
    //cout<<"n= "<<n<<" pq= "<<pq.size()<<endl;
    int s=pq.size();
    int temp=s;
    for(long long i=n;i<m;++i){
        g=pq.top();
        pq.pop();
        --s;
        time=-g.first;
        name=g.second.first;
//        if(s<0){
//            out[counter]=g.second;
//        }
        pq.push(make_pair(v[i]-time,make_pair(name,time)));
        out[counter].first=name;
        out[counter].second=time;
        ++counter;

    }
  }

 public:
  void Solve() {
    ReadData();
    AssignJobs();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}
