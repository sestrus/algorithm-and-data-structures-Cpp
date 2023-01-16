
#include <iostream>

using namespace std;



const int maxlength=50;
typedef int elementtype;
typedef int position;

class Kolejka{
    
    protected :
        elementtype Queue[maxlength];
        position Front; // Indeks elementu czołowego
        position Rear; // Indeks ostatniego elementu
    public:
        Kolejka();
        int AddOne(int i);
        void Enqueue(elementtype x);
        void Dequeue();
        elementtype FrontElem();
        void Makenull();
        bool Empty();
};

Kolejka::Kolejka(){
    Front = 0;
    Rear = maxlength-1;
}



int Kolejka::AddOne(int i) {
    return((i+1) % maxlength);
}

void Kolejka::Makenull(){
    cout<<"All queue elements removed!"<<endl;
    Front = 0;
    Rear = maxlength-1;
}

bool Kolejka::Empty(){
    if(AddOne(Rear)==Front) {
        cout<<"Queue is empty"<<endl;
        return true;
    }else {
        cout<<"Queue is not empty"<<endl;
        return false;}
}

void Kolejka::Enqueue(elementtype x) {
    if(AddOne(AddOne(Rear)) != Front){
        cout<<"Element "<<x<<" added to queue"<<endl;
        Rear = AddOne(Rear);
        Queue[Rear] = x;
    } else {
    cout<<"[Dequeue]Queue is empty!"<<endl;
    }
}

void Kolejka::Dequeue(){
    if(!(AddOne(Rear)==Front)){
        cout<<"Element "<<Queue[Front]<<" removed from queue"<<endl;
        Front = AddOne(Front);
    } else {
    cout<<"[Dequeue]Queue is empty!"<<endl;
    }
}

elementtype Kolejka::FrontElem(){
    if(!(AddOne(Rear)==Front)) {
        cout<<"Front element is: "<<Queue[Front]<<endl;
        return Queue[Front];
    } else {
    cout<<"[FrontElement]Queue is empty!"<<endl;
    return -1000;
    }
}

int main()
{
    Kolejka k;
    
    k.Empty();
    k.Enqueue(5);
    k.Empty();
    k.FrontElem();
    k.Dequeue();
    k.Empty();
    k.Enqueue(4);
    k.Enqueue(3);
    k.Enqueue(2);
    k.FrontElem();
    k.Enqueue(1);
    k.FrontElem();
    k.Dequeue();
    k.FrontElem();
    k.Enqueue(6);
    k.FrontElem();
    k.Dequeue();
    k.Dequeue();
    k.FrontElem();
    k.Dequeue();
    k.Makenull();
    k.Empty();


    
    return 0;
}
