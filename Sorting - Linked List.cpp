#include<iostream>
using namespace std;

void func(int *arr, int size){
	
	arr[2] = 10;
}

int main(){
	
	
	int array[6] = {6,2,5,8,1,3};
	int size = sizeof(array)/sizeof(array[0]);
	
	for(int i=0; i<size; i++){
		cout << array[i] << " " ;
	}
	
	func(array, size);
	
	cout <<"\n After :" << endl;
	for(int i=0; i<size; i++){
		cout << array[i] << " " ;
	}
	//cout << size;
	
	
	
	
	return (0);
}
