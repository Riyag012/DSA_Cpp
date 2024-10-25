#include <iostream>
using namespace std;
class CircularQueue{
    int front;
    int rear;
    int size;
    int *arr;

    public:
        CircularQueue(int n){
            front = -1;
            rear = -1;
            size = n;
            arr = new int[n];
        }
    

    void enqueue(int val){
        if ((front==0 &&rear == size-1) || (rear == (front-1)%(size-1))){
            cout<<"Overflow";
            //return false;
        }
        else{

        }
    }
    int dequeue(){

    }
    bool isEmpty(){

    }
    int front(){

    }
};