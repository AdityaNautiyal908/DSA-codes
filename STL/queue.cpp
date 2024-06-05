#include <iostream>
#include <queue>
using namespace std;

int main(){
    queue<string> q;
    q.push("love");
    q.push("babber");
    q.push("Kumar");

    cout<<"Size before pop->"<<q.size()<<endl;

    cout<<"First Element->"<<q.front()<<endl;

    q.pop();

    cout<<"First Element->"<<q.front()<<endl;

    cout<<"Size of->"<<q.size()<<endl;
    
    cout<<"Empty or not->"<<q.empty()<<endl;

return 0;
}