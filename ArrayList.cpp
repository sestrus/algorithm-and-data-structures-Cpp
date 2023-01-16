#include<iostream>
#include<cstdio>
 
#define MIN -10000000;

using namespace std;


typedef int elementtype, position ;
const int maxlength=20;
struct List{
	elementtype elements[maxlength];
	int last;           //indeks ostatniego elementu listy
};

position END(List l){ 
    //zwraca pozycje ostatniego elementu
	return l.last + 1;
}

position First(List l){ 
    //zwraca pozycje pierwszego elementu
    return 0;
}

position Next(position p,List l){ 
    //zwraca ideks nastepnego elementu wzgledem p
    if (p<END(l)){
        return p + 1;	
    } else { 
        return -1;
    }
}


position Previous(position p,List l){
    //zwraca ideks poprzedniego elementu wzgledem p
    
    if((p>First(l)) && p<=END(l)){
        return p-1;
    } else {
        return -1;
    }
    
}



position Locate(elementtype x, List l){
//zwraca pozycje x w l, gdy nie ma x w l zwraca end(l)
    for(int i = 0; i<END(l); i++){
    if(l.elements[i] == x){
        return i;
        }
    }
    return END(l);
}

elementtype Retrieve(position p, List l){ 
    //zwraca element w liscie na pozycji p
    if((p>=First(l)) || (p<=END(l))) {
        return l.elements[p];
    }else {
        return MIN;
    }
}

bool Insert(int x, position p, List &l){
    //wstawia x do komorki p

   if(maxlength-1 > l.last){
    if(p==END(l)){
        l.elements[p] = x;
        l.last=l.last+1;
        return true;
    }
    if(p<END(l) && p>=First(l)){
        for(position k = END(l); k>p; k--){
            l.elements[k] = l.elements[k-1];
        }
        l.elements[p] = x;
        l.last=l.last+1;
        return true;
    }
        if((p<0) || (p>END(l))){
        return false;

    }
    
    } else{ 

        return false;
    }
    return false;
}




bool Delete(position p, List &l){
    //usuwa element z komorki p
    if(p>=0 && p<END(l)){
    while(p<END(l)-1){
        l.elements[p] = l.elements[p+1];
        p++;
    }
    l.last--;
    return true;
    } else return false;
    
}


void print(List l){

	position i=First(l);
	while (i!=END(l))
	{
		printf ("  %d,", Retrieve(i,l));
		i=Next(i,l);
	}
	printf("\n");

}

bool Duplicate(List &l){
    if(l.last>=0){
    int length = l.last;
    for(int i = 0; i<=length;i++){
        Insert(Retrieve(i,l),length+i+1,l);
    }
    return true;
    } else return false;
}

bool Purge(List &l){
    for(int i = 0; i<END(l);i++){
        for(int j =0;j<END(l);j++){
        if(l.elements[i] == l.elements[j] && i!=j){
            Delete(Locate(l.elements[j],l),l);
        }
            
        }
    }
    return true;
}




int main(){

    List l;
    l.last=-1;


    Insert(100,First(l),l);
    print (l);

    for (int i=0; i<3;i++)
    Insert(i,First(l),l);


    Insert (20,First(l) ,l);
    Delete( Locate(20,l),l);

    Insert(50,Next(Locate(0,l),l),l);
    Insert(0,5,l);
    print(l);




    ////////////


    // Duplicate(l);
    print(l);

     Purge(l);
      print(l);
           Purge(l);
      print(l);
      Insert(100,3,l);
    Insert(50,3,l);

      print(l);
      Purge(l);
      print(l);
    // /////////

  


}
