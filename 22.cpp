#include <bits/stdc++.h>
using namespace std;

string removeOuterParentheses(string s){
    int count = 0;
    string result = "";
    for(int i = 0;i<string.length();i++){
     if(s[i]==')')count--;

     if(count!=0)result.push_back(s[i]);

     if(s[i] == '(')count++;
}
return result;
}
int main(){
    string s;
    cin>>s;
    string ans = removeOuterParentheses(s);
    cout<<ans<<endl;
    return 0;
}