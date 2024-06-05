#include <iostream>
#include <map>
using namespace std;

int main(){
    map<int,string> m;
    m[1] = "babber";
    m[2] = "love";
    m[13] = "kumar";

    for(auto i:m){
        cout<<i.first<<" ";
    }cout<<endl;

return 0;
}