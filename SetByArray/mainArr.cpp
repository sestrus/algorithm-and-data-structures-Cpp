#include <iostream>
#include <string>
#include "setArr.h"


using namespace std;

int main(){
    setArr arrA = setArr();
    setArr arrB = setArr();
    setArr arrC = setArr();



    arrA.insert(3);
    arrA.insert(8);
    arrA.insert(15);

    arrB.insert(3);
    arrB.insert(15);
    arrB.insert(35);
    arrB.insert(75);
    arrB.insert(99);


    arrC.insert(15);
    arrC.insert(75);
    arrC.insert(99);

    cout<<"Set A: "<<endl;
    arrA.printSet();    
    cout<<endl;
    cout<<"Set B: "<<endl;
    arrB.printSet();   
    cout<<endl; 
    cout<<"Set C: "<<endl;
    arrC.printSet();
    cout<<endl;

    cout<<"Union A + B:"<<endl;
    setArr setUnion = arrA + arrB;
    setUnion.printSet();
    cout<<endl;

    cout<<"Intersection A * B:"<<endl;
    setArr setIntersection = arrA * arrB;
    setIntersection.printSet();
    cout<<endl;

    cout<<"Difference A \\ B: "<<endl;
    setArr setDifference = arrA - arrB;
    setDifference.printSet();
    cout<<endl;

    
    arrA==arrB ? cout<<"A and B are equal!"<<endl : cout<<"A and B are not equal!"<<endl;
    cout<<endl;
    arrC<=arrB ? cout<<"C contains in B!"<<endl : cout<<"C does not contain in B!"<<endl;
    cout<<endl;
    arrB==arrC ? cout<<"B and C are equal!"<<endl : cout<<"B and C are not equal!"<<endl;
    cout<<"Adding 3 and 35 to set C"<<endl;
    arrC.insert(3);
    arrC.insert(35);
    cout<<endl;
    arrB==arrC ? cout<<"B and C are equal!"<<endl : cout<<"B and C are not equal!"<<endl;
    arrC<=arrB ? cout<<"C contains in B!"<<endl : cout<<"C does not contain in B!"<<endl;
    arrB<=arrC ? cout<<"B contains in C!"<<endl : cout<<"B does not contain in C!"<<endl;
    cout<<endl;
    cout<<"Removing 15 from C set"<<endl;
    arrC.withdraw(15);
    arrB==arrC ? cout<<"B and C are equal!"<<endl : cout<<"B and C are not equal!"<<endl;
    arrC<=arrB ? cout<<"C contains in B!"<<endl : cout<<"C does not contain in B!"<<endl;
    arrB<=arrC ? cout<<"B contains in C!"<<endl : cout<<"B does not contain in C!"<<endl;
    cout<<endl;


    arrA.isInSet(8) ? cout<<"There is 8 in the A set"<<endl : cout<<"There is no 8 in A set"<<endl;
    arrB.isInSet(7) ? cout<<"There is 7 in the B set"<<endl : cout<<"There is no 7 in B set"<<endl;
    cout<<endl;

    cout<<"Size of A set is: "<< arrA.getSize()<<endl;
    cout<<"Size of B set is: "<< arrB.getSize()<<endl;
    cout<<endl;
    cout<<endl;

    cout<<"Clear set C!"<<endl;
    arrC.clearSet();
    cout<<"Set C: "<<endl;
    arrC.printSet();
    cout<<"Size of C set is: "<<arrC.getSize()<<endl;

    return 0;
}