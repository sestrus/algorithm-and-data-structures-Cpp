#include <iostream>
#include <string>
#include "setList.h"


using namespace std;

int main(){
    setList listA = setList();
    setList listB = setList();
    setList listC = setList();



    listA.insert(3);
    listA.insert(8);
    listA.insert(15);

    listB.insert(3);
    listB.insert(15);
    listB.insert(35);
    listB.insert(75);
    listB.insert(99);


    listC.insert(15);
    listC.insert(75);
    listC.insert(99);

    cout<<"Set A: "<<endl;
    listA.printSet();    
    cout<<endl;
    cout<<"Set B: "<<endl;
    listB.printSet();   
    cout<<endl; 
    cout<<"Set C: "<<endl;
    listC.printSet();
    cout<<endl;

    cout<<"Union A + B:"<<endl;
    setList setUnion = listA + listB;
    setUnion.printSet();
    cout<<endl;

    cout<<"Intersection A * B:"<<endl;
    setList setIntersection = listA * listB;
    setIntersection.printSet();
    cout<<endl;

    cout<<"Difference A \\ B: "<<endl;
    setList setDifference = listA - listB;
    setDifference.printSet();
    cout<<endl;

    
    listA==listB ? cout<<"A and B are equal!"<<endl : cout<<"A and B are not equal!"<<endl;
    cout<<endl;
    listC<=listB ? cout<<"C contains in B!"<<endl : cout<<"C does not contain in B!"<<endl;
    cout<<endl;
    listB==listC ? cout<<"B and C are equal!"<<endl : cout<<"B and C are not equal!"<<endl;
    cout<<"Adding 3 and 35 to set C"<<endl;
    listC.insert(3);
    listC.insert(35);
    cout<<endl;
    listB==listC ? cout<<"B and C are equal!"<<endl : cout<<"B and C are not equal!"<<endl;
    listC<=listB ? cout<<"C contains in B!"<<endl : cout<<"C does not contain in B!"<<endl;
    listB<=listC ? cout<<"B contains in C!"<<endl : cout<<"B does not contain in C!"<<endl;
    cout<<endl;
    cout<<"Removing 15 from C set"<<endl;
    listC.withdraw(15);
    listB==listC ? cout<<"B and C are equal!"<<endl : cout<<"B and C are not equal!"<<endl;
    listC<=listB ? cout<<"C contains in B!"<<endl : cout<<"C does not contain in B!"<<endl;
    listB<=listC ? cout<<"B contains in C!"<<endl : cout<<"B does not contain in C!"<<endl;
    cout<<endl;


    listA.isInSet(8) ? cout<<"There is 8 in the A set"<<endl : cout<<"There is no 8 in A set"<<endl;
    listB.isInSet(7) ? cout<<"There is 7 in the B set"<<endl : cout<<"There is no 7 in B set"<<endl;
    cout<<endl;
    cout<<endl;

    cout<<"Size of A set is: "<< listA.getSize()<<endl;
    cout<<"Size of B set is: "<< listB.getSize()<<endl;
    
      return 0;
}