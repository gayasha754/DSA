#include <iostream>
using namespace std;

//here the buble sort function is optimized

void sort (int *array, int size);
void print(int *array, int size);

int main(){
	
	int list[] = {20,18,15,12,10,7,6,4,3,0};
	//.................................j j+1
	//...............................j j+1
	
	int size =(sizeof(list)/4);//10
	
	cout << "The unsorted List is :\n" ;
	print(list,size);
	
	sort(list,size);
	
	//Displaying the sorted array
	cout << "\nthe sorted List is :\n" ;
	print(list, size);
	
	return (0);
}

void sort(int *array, int size){
	
	int temp =0;
		
	for(int i=0; i<size-1; i++){// here size-1 is taken beacuse, the smallest one(last element) is already sorted with one before that
		for (int j = 0; j<size-1-i ; j++){
			//.......1st....j<=8 || j<9....size-1-0...bz i=0
			//.......2nd............j<8....size-1-1...bz i=1
			//.......3rd............j<7....size-1-2...bz i=2
			if (array[j]> array[j+1]){
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}	
	}
}

void print(int *array, int size){
	
	for (int i=0; i < size; i++){
		cout << array[i] << " ";
	}
}
