#include<bits/stdc++.h>
using namespace std;
class Queue{
    private:
    int front,rear,capacity;
    int*arr;
    public:
    Queue(int cap)
    {
        this->arr=new int[cap];
        this->capacity=cap;
        this->front=this->rear=-1;
    }
    bool isEmpty()
    {
     return this->front==-1;
    }
    bool isFull()
    {
        return (this->rear+1)%this->capacity==this->front;
    }
    int size(){
        if(this->isEmpty())
        return 0;
        else
        return (this->capacity-this->front+this->rear+1)%this->capacity;
    }
    void enQueue(int n){
        if(!this->isFull())
        {
            this->rear=(this->rear+1)%this->capacity;
            this->arr[this->rear]=n;
            if(this->front==-1)
            this->front=this->rear;
        }
        
    }
    int deQueue(){
        int data=INT_MAX;
        if(!this->isEmpty())
        {
           data=this->arr[this->front];
           if(this->front==this->rear)
           this->front=this->rear=-1;
           else
           this->front=(this->front+1)%this->capacity;
        }
        return data;
    }
    int getCapacity()
    {
        return this->capacity;
    }
    ~Queue()
    {
       delete []this->arr; 
    }
    void display()
    {
        int cur=this->front;
        while(1)
        {
            if(cur==this->rear)
            {
                cout<<this->arr[cur]<<endl;
                break;
            }
            cout<<this->arr[cur]<<" <-- ";
            cur=(cur+1)%this->capacity;
        }
    }

};
int main()
{
    Queue*q=new Queue(10);
   int ar[7]={1,2,3,4,5,6,7};
   for(int i :ar){
       q->enQueue(i);
   }
cout<<"Initial Queue :\n"<<endl;
q->display();
int i=q->deQueue();
int j=q->deQueue();
cout<<"Queue after dequeueing two elements :\n"<<endl;
q->display();
cout<<"Dequeued elements : \n"<<i<<" , "<<j<<endl;
q->enQueue(8);
q->enQueue(9);
cout<<"Queue after enqueueing more two elements :\n"<<endl;
q->display();
delete q;
return 0;
}
