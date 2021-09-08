#include<iostream>
using namespace std;

void insertionSort(int *array, int size);
void print(int *array, int size);

//The array is searched sequentially and unsorted items are moved and inserted into the sorted sub-list (in the same array).
//the element at the 2nd place of the array is taken as the key at first and then it increases to the right...3rd place, 4th place....
//the key is compared with its previous elements and swapped if it is a smaller value 

int main(){
	int list[] = {5,2,3,1,6,4};
	int size = sizeof(list)/4;
	cout << "Unsorted array is: \n" ;
	print (list, size);
	insertionSort(list,size);
	
	//displaying the sorted array 
	cout << "\nSorted Array is :\n" ;
	print(array, size);
	
	return(0);
}

void insertionSort(int *array, int size){
	
	int key,i,j;
	
	for (i = 1; i <size; i++){
		key = array[i];
		j=i-1;
	//----------------------------------------	
		while(j>=0 && key < array[j]){
			array[j+1] = array[j];
			j--;
		}
		/*A for Loop can be also used for this
		for(j=i-1; (j>=0 && array[j] > key); j--){
			array[j+1] = array[j];
		}*/
	//-----------------------------------------	
		array[j+1] = key;
	}
}

//Function for Printing the array
void print(int *array, int size){
	
	for(int j=0; j<size; j++){
		cout << array[j] <<" ";
	}
	cout << endl;
}


