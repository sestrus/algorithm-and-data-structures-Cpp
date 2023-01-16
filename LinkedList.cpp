#include <iostream>

 
 
using namespace std; 
 
typedef int elementtype;
struct celltype{
    elementtype element;
    celltype * next;
};
typedef celltype * position;

class Lista{
    protected :
        position l; 
    public:
        Lista(); 
        ~Lista(); 
        void Insert(elementtype x, position p);
        void Delete(position p);
        elementtype Retrieve(position p);
        position Locate(elementtype x);
        position First();
        position Next(position p);
        position Previous(position p);
        position END();
};

 
Lista::Lista(){
    l = new celltype();
    l->next = NULL;
}
 
Lista:: ~Lista(){

}


 
void Lista:: Insert(elementtype x, position p){
    position tmp;
    tmp = p->next;
    p->next = new celltype;
    p->next->element = x;
    p->next->next = tmp;
}




position Lista::Locate(elementtype x){
    position temp;
    temp = l;
    while (temp->next != NULL){
        if (temp->next->element == x) return temp;
        temp = temp->next;
    }
return temp;
}

elementtype Lista::Retrieve(position p){
    if (p->next != NULL)
    return p->next->element;
return 0;
}
 
void Lista::Delete(position p){
    position tmp;
    tmp = p->next;
    p->next = p->next->next;
    delete tmp;
}
 


 
 
position Lista::First(){
return l;
}
 
position Lista::Next(position p){
return p->next;
}
 
position Lista::Previous(position p){
    position tmp;
    tmp = l;
    while (tmp->next != p){
        tmp = tmp->next;
    }
return tmp;
 
 
}
 
position Lista::END(){
position p = l;
while (p->next != NULL){
p = p->next;
}
return p;
}
 
 
void print(Lista l){
    position i = l.First();
    while (i != l.END()){
        cout << l.Retrieve(i)<<endl;
        i = l.Next(i);
    }
    cout<<endl;
}

 
 
int main()
{
    Lista l;
    l.Insert(5,l.First());
    cout<<l.Retrieve(l.First())<<endl<<endl;
    
    l.Insert(2,l.First());
    cout<<l.Retrieve(l.First())<<endl;
    cout<<l.Retrieve(l.Next(l.First()))<<endl<<endl;
    
    l.Insert(1,l.Next(l.First()));
    print(l);
    
     l.Insert(100,l.END());
     print(l);
    
     l.Delete(l.Previous(l.Locate(100)));
     print(l);
    



}