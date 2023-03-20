#include <iostream>
using namespace std;
class setArr
{
int size;
const int universeSize = 100;
bool* table;
bool checkRangeCorrectness(int x);
public:
	setArr(){
		table = new bool[universeSize];
		clearSet();
		size=0;
	}
	void insert(int x){
		if(table[x] == false){
			size++;
			table[x] = true;
		}
	}
	void withdraw(int x){
		if(table[x] == true){
			size--;
			table[x]=false;
		}
	}
	bool isInSet(int i){
		if(table[i] == true)
			return true;
		else return false;
	}
	int getSize(){
		return size;
	}
	void clearSet(){
		for(int i = 0; i < universeSize; i++){
			table[i] = false;
		}
		size = 0;
	}
	void printSet(){
		cout<<"[ ";
		for(int i = 0; i < universeSize; i++){
			if(table[i] == true){
				cout << i << " "; 
			}
		}
		cout<<"]"<<endl;
	}
	setArr operator+(setArr& object){
		setArr newUnion = setArr();
		for(int i = 0; i < universeSize;i++){
			if(object.isInSet(i) || this->isInSet(i)){
				newUnion.insert(i);
			}
			
		}
		return newUnion;
	}
	setArr operator*(setArr& object){
		setArr newIntersection = setArr();
		for(int i = 0; i < universeSize;i++){
			if(object.isInSet(i) && this->isInSet(i)){
				newIntersection.insert(i);
			}
		}
		return newIntersection;
	}

	setArr operator-(setArr& object){

		setArr newDifference = setArr();
		for(int i = 0; i < universeSize;i++){
			if(!object.isInSet(i) && this->isInSet(i)){
				newDifference.insert(i);
			}
		}
		return newDifference;
	}

	bool operator==(setArr& object){
		for(int i = 0; i < universeSize;i++){
			if(object.isInSet(i) != this->isInSet(i)){
				return false;
			}
		}
		return true;
	}
	bool operator <= (setArr& object){
		for(int i = 0; i < universeSize; i++){
			if(!object.isInSet(i) && this->isInSet(i)){
				return false;
			}
		}
		return true;
	}
};

