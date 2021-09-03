#include<iostream>
using namespace std;

// this program implements the Selection sort

/* 
	repetedly finding the minimum element(considering ascending order) from the unsorted part and puttting it at the beginning
	algorithm maintains 2 subarrays 
    1.The subarray which is already sorted	
	2. Remaining subarray which is unsorted.
	in every itertion of selsction sort, the minimum element from the unsorted subarrray s picked and moved to the sorted subarray 

*/

void selectionSort(int *array , int size);
void print(int *array, int size);

int main(){
	
	int list[] = {20,18,24,33,60,10,2};
	int size = sizeof(list)/4;
	
	cout << "The unsorted list is: \n" ;
	print(list,size);
	
	selectionSort(list, size);
	
	return (0);
}

// first & second iteration are commented

void selectionSort(int *array, int size){
	
	int min;  //index of temporary minimum value
	int temp; //Tepmorary variable used for swapping
																
								 //first iteration												 //second iteration
	for(int i=0; i<size-1; i++){ // i=0                                                          //i=1
		min = i; // min = 0                                                                      // min=1
		for(int j=i+1; j < size; j++){	//j=0+1=1												//j = 1+1 =2
			if(array[j] < array[min]){ // ?(array[1] < array[0])...... ? (18<20)->true         // ?(array[2] <array[1])...?(24<18)->false
				min = j;	// min = 1														   //won't go into if	
			}																
		}						
		
		//then comes here.... if i = j then its the same index...no swapping can be done																//directly comes here  min=1 & i=1
		if(min!=i){   // ? min= j = 1 ; ?(1 != 0) ->true...									//this if statement also false
			//swaping
			temp = array[min]; 
			array[min] = array[i];														    //No swapping
			array[i] = temp;
		}
	}
	
	cout << "\nSorted list(Selection Sort) is: \n";
	print(array,size);
	
}

void print(int *array, int size){
	for(int k=0; k<size; k++){
		cout << array[k] << " " ;
	}
	cout << endl;
}

