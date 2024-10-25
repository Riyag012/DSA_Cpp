// WORKS BUT REQUIRES IMP

#include <iostream>
using namespace std;
class Stack{
    public:
        int *arr;
        int top;
        int size;
    
    Stack(int size){
        this->size = size;
        top = -1;
        arr = new int[size];
    }

    void push(int val){
        if (top == size-1){
            cout<<"Stack overflow condition."<<endl;
        }
        else{
            top++;
            arr[top] = val;
        }
    }

    void pop(){
        if (top == -1){
            cout<< "Stack underflow condition."<<endl;
        }
        else{
            // arr[top] = NULL;
            top--;
        }
    }

    int peek(){
        return arr[top];
    }

    bool isempty(){
        if (top == -1){
            return true;
        }
        else{
            return false;
        }
    }

};
int main(){
    Stack st(10);
    st.push(2);
    st.push(3);
    cout<<st.peek();
    

}