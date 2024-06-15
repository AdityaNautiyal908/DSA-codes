#include <iostream>
#include <string>
using namespace std;

string Remove_Occur(string Occ, string part) {
    while(Occ.length() !=0 && Occ.find(part) < Occ.length() ) {
        Occ.erase(Occ.find(part),part.length());
    }
    return Occ;

}

int main(){
    string Occ = "daabcbaabcbc";
    string part = "abc";

    cout << Occ << endl;

    cout << Remove_Occur(Occ,part);
return 0;
}