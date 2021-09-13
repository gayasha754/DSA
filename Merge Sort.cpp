#include<iostream>
using namespace std;

//Implementation of merge sort using recurssion 

void mergeSort(int *array, int lb, int ub);
void merge(int *array, int lb, int mid, int ub);

int main(){
	
	int array[9] = {15,5,24,8,1,3,16,10,20};
	
	cout << "Unsorted array:" ;
	
	for(int i=0; i <9; i++){
		cout << array[i] << " " ;
	}
	
	mergeSort(array, 0, 8);
	
	cout << "\n\n Sorted array:\n";
	
	for(int i=0; i <9; i++){
		cout << array[i] << " " ;
	}
	
	return (0);
}

//Dividing and Sorting using recurrssion 
void mergeSort(int *array, int lb, int ub){
	
	if(lb < ub) {
		int mid = (lb+ub)/2;
		mergeSort(array,lb,mid);
		mergeSort(array, mid+1, ub);
		merge(array, lb, mid, ub);
	}
}

void merge(int *array, int lb, int mid, int ub){
	
	int arraySort[9];
	int i,j,k;
	
	i =lb;     //left index for sub-sorted arrays in left side
	j = mid+1; //Left index for sub-sorted arrays in right side
	k = lb; // This is the main array index keeper....Full-sorted array
	
	while(i<=mid && j <=ub){
		
		if(array[i] <= array[j]){ 
			arraySort[k] = array[i];  //Storing to the main array
			i++;
		}
		else{
			arraySort[k] = array[j];  //Storing to the main array
			j++;
		}
		k++;
	}
	
	//Checking whether the current i is greater than the mid; if so elements remain in right array 
	if(i > mid){
		//If there are elements remaining in the final sub array of Right side
		while(j <= ub){
			arraySort[k] = array[j]; //they are directly stored in to main array
			j++;
			k++;
		}
	}
	else{
		//If there are elements remaining in the final sub array of left side
		while(i <= mid){
			arraySort[k] = array[i];
			i++;
			k++;
		}
	}
	
	//replacing the array named 'array' by the array 'arraySort'
	for(k = lb; k <= ub; k++){
		array[k] = arraySort[k];
	}
	
}
