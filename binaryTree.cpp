#include <iostream>
#include <cstdio>

using namespace std;



typedef int Telement;
typedef struct Node
{
 Telement info;
 Node * left;
 Node * right;
};
typedef Node *PNode;



class BinaryTree
{
protected:
PNode T;
public:

BinaryTree();
~BinaryTree();
PNode PARENT(PNode n);
PNode PARENT1(PNode n,PNode T);
PNode LEFT_CHILD(PNode n);
PNode RIGHT_CHILD(PNode n);
Telement GetLabel(PNode n);
PNode BuildTree1(int m);
void BuildTree(int m);
PNode ROOT();
void MAKENULL(PNode p);
void PreOrder(PNode t);
void InOrder(PNode t);
void PostOrder(PNode t);
void SetLabel(PNode n , Telement val);
};


BinaryTree::BinaryTree(){
    T=NULL;
}
BinaryTree::~BinaryTree(){
    MAKENULL(T);
}

PNode BinaryTree::BuildTree1(int m){
if(m==0) return NULL;
Node * newNode = new Node;
newNode->info = m;
newNode->left = BuildTree1((m/2));
newNode->right = BuildTree1(m-(m/2)-1);
return newNode;

}

void BinaryTree::BuildTree(int m){
    
    T = BuildTree1(m);
    
}

PNode BinaryTree::PARENT1(PNode n,PNode T){
    if(n == T->left || n == T->right){
        return T;
    } else {
        PARENT1(n,T->left);
        PARENT1(n,T->right);
    }
    return NULL;
}

PNode BinaryTree::PARENT(PNode n){
    if(n==ROOT())
      return NULL;  
        PARENT1(n,T);

}



void BinaryTree::PreOrder(PNode t){
    if (t == NULL) return;
    cout<<t->info<<" ";
    PreOrder(t->left);
    PreOrder(t->right);
    
}

void BinaryTree::InOrder(PNode t){
    if (t == NULL) return;
    InOrder(t->left);
    cout<<t->info<<" ";
    InOrder(t->right);
    
}

void BinaryTree::PostOrder(PNode t){
    if (t == NULL) return;
    PostOrder(t->left);
    PostOrder(t->right);
    cout<<t->info<<" ";
}
PNode BinaryTree::ROOT(){
    if(T==NULL) return NULL;
    return T;
}

Telement BinaryTree::GetLabel(PNode n){
    return n->info;
}

PNode BinaryTree::LEFT_CHILD(PNode n){
    return n->left;
}
PNode BinaryTree::RIGHT_CHILD(PNode n){
    return n->right;
}

void BinaryTree::MAKENULL(PNode p){
    p = NULL;
}

void BinaryTree::SetLabel(PNode n, Telement label){
    n->info = label;
}






int main(){
    //Tworzenie drzewa:
    BinaryTree t;
    t.BuildTree(9);
    
    /*Przypisywanie wezlom odpowiednich wartosci:
    /*
            5
           | \
          |   \
          3    8
         | \  | \
         2 4  7 9 
        |     |
        1     6
   
    */
    t.SetLabel(t.ROOT(),5);
    t.SetLabel(t.LEFT_CHILD(t.ROOT()),3);  
    t.SetLabel(t.RIGHT_CHILD(t.ROOT()),8);
    t.SetLabel(t.LEFT_CHILD(t.LEFT_CHILD(t.ROOT())),2);
    t.SetLabel(t.RIGHT_CHILD(t.LEFT_CHILD(t.ROOT())),4);
    t.SetLabel(t.LEFT_CHILD(t.LEFT_CHILD(t.LEFT_CHILD(t.ROOT()))),1);
    t.SetLabel(t.LEFT_CHILD(t.RIGHT_CHILD(t.ROOT())),7);
    t.SetLabel(t.RIGHT_CHILD(t.RIGHT_CHILD(t.ROOT())),9);
    t.SetLabel(t.LEFT_CHILD(t.LEFT_CHILD(t.RIGHT_CHILD(t.ROOT()))),6);
    
    cout<<"Wartosc korzenia: "<<t.GetLabel(t.ROOT())<<", Lewe dziecko: "
    <<t.GetLabel(t.LEFT_CHILD(t.ROOT()))<<", Prawe dziecko: "
    <<t.GetLabel(t.RIGHT_CHILD(t.ROOT()))<< endl;
    
    cout<<"Wartosc wezla, ktory jest rodzicem prawego dziecka korzenia: "
    <<t.GetLabel(t.PARENT(t.RIGHT_CHILD(t.ROOT())))<<endl;
    
    

    
    
    
    //Wypisywanie drzewa w roznych kolejnosciach:
    cout<<"Preorder: "<<endl;
    t.PreOrder(t.ROOT());
    cout<<endl;
    
    cout<<"Inorder: "<<endl;
    t.InOrder(t.ROOT());
        cout<<endl;

    cout<<"Postorder: "<< endl;
    t.PostOrder(t.ROOT());
    

    

}