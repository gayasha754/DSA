#include <iostream>
using namespace std;

//Binary search is implemented here

//prototyping functions
void sortArray(int *array,int size);
void displayArray(int *array, int size);
int binarySearch(int *array, int num, int left, int right);

int main(){
	//original array
	int array[] = {20,16,15,12,11,10,8,6,2,1,0};
	int size = (sizeof(array))/4;
	cout << "Unsorted Array : \n" ;
	displayArray(array,size);
	
	//sorted array
	sortArray(array, size);
	
	//Displaying the sorted array
	cout << "\n\nSorted Array: \n";
	displayArray(array,size);
	
	//Binary search
	int num;
	cout << "\n\nEnter the number you want to search: " ;
	cin >> num;
	int index = binarySearch(array,num,0,size-1);
	
	if(index==(-1)){
		cout << "\nThe number entered is not in the array"<< endl;
	}
	else{
		cout << "\nThe position of the searched number is : " << index <<endl ;
	}
	
	return (0);
}

//selection sort
void sortArray(int *array, int size){
	
	for(int i=0 ; i <size ; i++){
		for(int j=1+i ; j <size ; j++){
			if(array[i] > array[j]){
				int temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
}

void displayArray(int *array, int size){
	for(int i=0; i<size; i++){
		cout << array[i] << " " ;
	}
}

//Binary Search
int binarySearch(int *array, int num, int left, int right){
	
	int  mid = (left+right)/2 ;     //0+9 = 9/2 = 4.5= 4    // 1 2 6 8    |10|    11 12 15 16 20    //(0+3)/2 =1.5 = 1  		//(3+3)/2 =3
	
	//There are two base cases here	
	
	if(left > right){               //0>9													        //0>1				       //0>3
		return (-1);
	}
	else if(array[mid] == num){     // 10==8												        // 8==2				       // 8==8
		return mid+1;																		 							       //return 3+1
	}
	else if(num < array[mid]){      // 8< 10 													   //8 < 2
		return binarySearch(array, num, left, mid-1);    //(array, 8, 0, 3)                
	}
	else{ //(num > array[mid])                                                                     // 8 > 2
		return binarySearch(array, num, mid+1, right);											   //(array, 8, 3, 3)
	}
	
	
}
