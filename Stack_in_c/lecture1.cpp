#include <iostream>
#include <stack>
using namespace std;

// class Stack {
//     public:
//     int *arr;
//     int top;
//     int size;

//     Stack(int size){
//         this->size = size;
//         arr = new int(size);
//         top = -1;
//     }

//     void push(int element) {
//         if(size - top > 1){
//             top++;
//             arr[top] = element;
//         }
//         else {
//             cout << " Stack overflow " << endl;
//         }
//     }

//     void pop(){
//         if(top>=0) {
//             top--;
//         }
//         else {
//             cout << " Stack underflow " << endl;
//         }
//     }

//     int peek(){
//         if(top>=0 && top < size)
//         return arr[top];

//         else {
//             cout << " Stack is empty " << endl;
//             return -1;
//         }
//     }

//     bool isEmpty(){
//         if(top==-1){
//             return true;
//         }
//         else {
//             return false;
//         }
//     }
// };

int main() {
    // stack<int> s;
    // s.push(3);
    // s.push(5);
    // s.push(7);
    // s.push(9);
    // s.pop();
    // s.pop();
    // s.pop();
    // s.pop();
    

    // // Printing elements and popping them from the stack
    // while (s.empty()==0) {
    //     cout << s.top() << " ";
    //     s.pop();
    // }
    // cout << endl;
    // cout << " Stack size : " << s.size() << endl;
    // cout << " Empty or not : " << s.empty() << endl;
    // cout << " Top element of stack : " << s.top() << endl;

    stack<int> s;
    s.push(2);
    s.push(3);
    s.push(5);
    s.pop();
    s.pop();
    s.pop();
    
    cout << " Top element : " << s.top() << endl;
    cout << " Empty or not : " << s.empty() << endl;
    
    if(s.empty()){
        cout << " Stack is empty " << endl;
    }
    else {
        cout << " Stack is not empty " << endl;
    }

    // while(!s.empty()){
    //     cout << s.top() << " ";
    //     s.pop();
    // }
    // cout << " Top element of stack : " << s.top() << endl;
    

    // Stack st(5);
    // st.push(22);
    // st.push(42);
    // st.push(44);
    // st.push(45);
    // st.push(46);
    // st.push(47);
    // st.push(50);

    // cout << endl;
    // cout << st.peek() << endl;

    // st.pop();
    // cout << endl;
    // cout << st.peek() << endl;

    // st.pop();
    // cout << endl;
    // cout << st.peek() << endl;

    // st.pop();
    // cout << endl;
    // cout << st.peek() << endl;

    // if(st.isEmpty()){
    //     cout << " Stack is empty " << endl;
    // }
    // else {
    //     cout << " Stack is not empty " << endl;
    // }


    return 0;

}
