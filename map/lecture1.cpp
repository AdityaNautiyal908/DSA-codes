#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;

int main(){
    // creation
    unordered_map<string,int> m;

    //insertion
    // 1
    pair<string,int> p = make_pair("babber",3);
    m.insert(p);

    // 2
    pair<string,int> pair2("love",2);
    m.insert(pair2);

    // 3
    m["mera"] = 1;

    // what will happen
    m["mera"] = 2;

    // Search
    cout << m["mera"] << endl;
    cout << m.at("babber") << endl;

    cout << m["Unknownkey"] << endl;
    cout << m.at("Unknownkey") << endl;

    cout << m.size() << endl;

    // to check present
    cout << m.count("bro") << endl;
    cout << m.count("love") << endl;

    //erase 
    m.erase("love");
    cout << m.size() << endl;

    // for ( auto i: m){
    //     cout << i.first << " " << i.second << " ";
    // }cout << endl;

    // iterator
    unordered_map <string,int> :: iterator it = m.begin();
    while(it != m.end()){
        cout << it->first << " " << it->second << " " << endl;
        it++;
    }

return 0;
}

