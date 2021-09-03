//Selection sort Method 2 (Sir)
//=============================
#include <iostream>
using namespace std;


void sortArray(int[], int);

int main(){
	int arr[]={8, 7, 6, 5, 4, 3, 2, 1};
	
	int length=sizeof(arr)/sizeof(arr[0]);
	
	cout << "Unsorted Array : ";
	for(int i=0; i<length; i++){
		cout << arr[i] << " ";
	}
	cout << endl <<endl;
	
	sortArray(arr, length);
	
	cout << "Sorted Array : ";
	for(int i=0; i<length; i++){
		cout << arr[i] << " ";
	}
	cout << endl <<endl;
	return 0;
}


void sortArray(int arr[], int length){
	// selection sort technique - method 2
	
	int index, temp;
	// index - index of temporary maximum value
	// temp - temp variable used for swapping
	
	for(int i=length-1; i>0; i--){
		
		index=i;
		for(int j=i-1; j>=0; j--){
			if(arr[index]<arr[j]){
				index=j;
			}
		}
		temp=arr[i];
		arr[i]=arr[index];
		arr[index]=temp;
		
	}
}
