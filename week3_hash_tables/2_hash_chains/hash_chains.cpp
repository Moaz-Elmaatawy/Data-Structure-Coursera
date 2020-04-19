#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

struct Query {
    string type, s;
    size_t ind;
};

class QueryProcessor {
    int bucket_count;
    // store all strings in one vector
    vector<list<string>> elems;
    size_t hash_func(const string& s) const {
        static const size_t multiplier = 263;
        static const size_t prime = 1000000007;
        unsigned long long hash = 0;
        for (int i = static_cast<int> (s.size()) - 1; i >= 0; --i)
            hash = (hash * multiplier +(int)s[i]) % prime;
        return hash % bucket_count;
    }

public:
    explicit QueryProcessor(int bucket_count): bucket_count(bucket_count) {elems.resize(bucket_count);}

    Query readQuery() const {
        Query query;
        cin >> query.type;
        if (query.type != "check")
            cin >> query.s;
        else
            cin >> query.ind;
        return query;
    }

    void processQuery(const Query& query) {
        if (query.type == "check") {
            int n= query.ind;
            list<string> ::iterator it=elems[n].begin();
            for (;it !=elems[n].end();++it)
                cout<<*it<<" ";
            cout<<"\n";
        }
        else if (query.type == "find"){
            int n=hash_func(query.s);
            list<string> ::iterator it=elems[n].begin();
            for (;it!=elems[n].end();++it)
            if(*it==query.s){
                cout<<"yes\n";
                return;
            }
            cout<<"no\n";
        }
        else if (query.type == "add") {
            int n=hash_func(query.s);
            list<string> ::iterator it=elems[n].begin();
            for (;it!=elems[n].end();++it)
            if(*it==query.s){
                return;
            }
            elems[n].push_front(query.s);
        }
        else if (query.type == "del") {
            int n=hash_func(query.s);
            elems[n].remove(query.s);
        }

    }


    void processQueries() {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
            processQuery(readQuery());
    }
};

int main() {
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    std::ios_base::sync_with_stdio(false);
    int bucket_count;
    cin >> bucket_count;
    QueryProcessor proc(bucket_count);
    proc.processQueries();
    return 0;
}
