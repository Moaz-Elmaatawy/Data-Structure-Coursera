#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    int check=0;
    string text;
    cin>>text;
    int count0=0;
    stack<char> s;
    stack<int>n;
    for (int i=0;i<text.size();++i){
        ++ count0;
        if (text[i]=='['||text[i]=='{'||text[i]=='('){
            s.push(text[i]);
            n.push(count0);
        }
        else if((s.empty()==1&&text[i]==']')||(s.empty()==1&&text[i]==')')||(s.empty()==1&&text[i]=='}')){
            cout<<count0;
            check =5;
            break;
        }
        else if(text[i]==']'||text[i]=='}'||text[i]==')'){
            if ((s.top()=='['&&text[i]!=']')||(s.top()=='{'&&text[i]!='}')||(s.top()=='('&&text[i]!=')')){
                cout<<count0;
                check=5;
                break;

            }
            else{
                s.pop();
                n.pop();
            }
        }
    }
    if(s.empty()==1&&check!=5){
        cout<<"Success";
    }
    else{
        if(check!=5){
            cout<<n.top();
        }
    }
    return 0;
}
