#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>
#include <stack>

using namespace std;



int main() {
    int num_queries = 0;
    cin >> num_queries;

    string query;
    string value;

    stack<int> a;
    stack<int> b;


    int max0=-1;

    for (int i = 0; i < num_queries; ++i) {
        cin >> query;
        if (query == "push") {
            cin >> value;
            a.push(stoi(value));
            if (stoi(value)>max0){
                b.push(stoi(value));
                max0=stoi(value);
            }
            else{
                b.push(max0);
            }
        }
        else if (query == "pop") {
            a.pop();
            b.pop();
        }
        else if (query == "max") {
            cout << b.top() << "\n";
        }
        else {
            assert(0);
        }
    }
    return 0;
}
