#include<iostream>
using namespace std;

void mSort(int *array, int left, int right);
void m(int *array, int left, int right, int mid);
void display(int *array,int size);

int main(){
	int arr[]={5,4,3,1,9,6,7,18,0,2,8};
	int size = (sizeof(arr)) / (sizeof(arr[0]));
	cout << "Before Merge Sort: " << endl;
	display(arr, size);
	//int length = size-1;
	mSort(arr, 0,size-1); // rightmost element's index is 1 less than the length of the array.
	
	cout << "\nAfter Merge Sort: " << endl;
	display(arr, size);

	return 0;
}

void mSort(int *array, int left, int right){
	
	if(left < right){	
		int mid = (left + right)/2;
		mSort(array, left, mid);
		mSort(array, mid+1 , right);
		m(array, left,right,mid);
	}	
}

void m(int *array, int left, int right, int mid){
	
	int i=left; 
	int j = mid+1; 
	int k=left;
	int tempArray[right+1];
	while(i <= mid && j <=right){
		
		if(array[i] <= array[j]){
			tempArray[k] = array[i];
			i++;
		}
		else{  // array[i] > array[j] OR array[j] <= array[i]
			tempArray[k] = array[j];
			j++;
		}
		k++;
	}
	//if(i <= mid){
		while(i <= mid){
			tempArray[k] = array[i];
			i++; k++;
		}
	//}

	//if(i>mid){
		while(j <= right){
			tempArray[k] = array[j];
			j++; k++;
		}
	//}

	for(int n = left; n <= right; n++){
		array[n] = tempArray[n];
	}
}

void display(int *array, int size){
	for(int i=0; i <size; i++){
		cout << array[i] << " " ;
	}
	cout <<"\n" << endl;
}
