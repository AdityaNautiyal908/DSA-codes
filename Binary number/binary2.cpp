#include <iostream>
using namespace std;

int main(){
    int firstTerm = 0;
    int secondTerm = 1;
    int n;

    cout<<"Enter the terms : ";
    cin>>n;

    cout<<firstTerm<<" "<<secondTerm;
    for(int i=0; i<n; i++){
        int nextNumber = 0;
        nextNumber = firstTerm + secondTerm;
        cout<<" "<<nextNumber;

        firstTerm = secondTerm;
        secondTerm = nextNumber;
    }

    return 0;
}