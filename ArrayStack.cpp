#include<iostream>
#include<cstdio>

using namespace std;

#define MIN -10000000;

typedef int elementtype;

const int maxlength = 2;

class Stos{
    private:
    elementtype elements[maxlength];
	int top;    
    public:
        Stos(); 
        ~Stos();
        void Push(int element);
        int Pop();
        int TopElement();
        void Makenull();
        bool Empty();

};

Stos::Stos(){
    top = -1;
}
 
Stos:: ~Stos(){

}

void Stos::Push(int element){
    if (top<maxlength-1){
        top++;
        elements[top] = element;
    } else {
        cout<<"(Push)Stack is full!"<<endl;  
    }
        
}

int Stos:: Pop(){
    if(top!=-1){
        top--;
        return elements[top];
    } else {
        cout<<"(Pop)Stack is empty!"<<endl;
        return -1;
    }
}

int Stos::TopElement(){
    if(top!=-1) {
        cout<<"Top element: "<<elements[top]<<endl;
        return elements[top];}
    else {
        cout<<"(Top)Stack is empty"<<endl;
        return -1;
    }

}

void Stos::Makenull(){
    top=-1;
}

bool Stos::Empty(){
    if(top==-1){
        cout<<"(Empty)Stack is empty!"<<endl;
        return true;
    } else {
        cout<<"(Empty)Stack is not empty!"<<endl;
        return false;
    }
    
}


int main()
{
   Stos s;
   
    s.Empty();
    s.Push(5);
    s.TopElement();
    s.Empty();
    s.Pop();
    s.Empty();
    s.Push(2);
    s.Push(3);
    s.TopElement();
    s.Makenull();
    s.Empty();



    return 0;
}
