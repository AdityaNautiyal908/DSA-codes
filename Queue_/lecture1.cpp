#include <bits/stdc++.h>
using namespace std;

int main(){
    queue<int> Q;
    Q.push(3);
    Q.push(5);
    Q.push(10);
    Q.push(19);
    Q.emplace(22);
    // Q.pop();
    // Q.pop();

    cout << " Empty or not : " << Q.empty() << endl;
    cout << " Size of Queue : " << Q.size() << endl;
    cout << " Front element : " << Q.front() << endl;
    cout << " Back element : " << Q.back() << endl;
    
}