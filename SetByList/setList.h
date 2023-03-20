#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

class setList
{
    std::vector<int> vec;

public:

int getSize(){
    return vec.size();
}

    void printSet(){
        cout<<"[ ";
    copy(vec.begin(),
         vec.end(),
         ostream_iterator<int>(cout, " "));
        cout<<"]"<<endl;
    }
    void insert(int x){
        if(!isInSet(x)){
            vec.push_back(x);
        }
    }
    void withdraw(int x){
        if(isInSet(x)){
            vec.erase(find(vec.begin(),vec.end(),x));
        }
    }
    bool isInSet(int x){
        if(find(vec.begin(), vec.end(), x) != vec.end())
            return true;
        else 
            return false;
    }
    setList operator+(setList& obj){
        setList newUnion = setList();
        for(int i=0;i<obj.vec.size();i++){
            newUnion.insert(obj.vec[i]);
        }
        for(int i=0;i<this->vec.size();i++){
            newUnion.insert(this->vec[i]);
        }

        return newUnion;
    }
    setList operator*(setList& obj){
        setList newIntersection = setList();
        for(int i = 0; i < obj.vec.size();i++){
            if(this->isInSet(obj.vec[i]))
                newIntersection.insert(obj.vec[i]);
        }
        return newIntersection;
    }   
    setList operator-(setList& obj){
        setList newDifference = setList();
        for(int i = 0; i<this->vec.size();i++){
            if(!obj.isInSet(this->vec[i]))
                newDifference.insert(this->vec[i]);
        }
        return newDifference;
    }
    bool operator==(setList& obj){
        for(int i = 0; i<this->vec.size();i++){
            if(!obj.isInSet(this->vec[i]))
                return false;
        }
        for(int i = 0; i<obj.vec.size();i++){
            if(!this->isInSet(obj.vec[i]))
                return false;
        }
        return true;
    }  
    bool operator<=(setList& obj){
        for(int i = 0; i<this->vec.size();i++){
            if(!obj.isInSet(this->vec[i]))
                return false;
        }
        return true;
    }
    
};



