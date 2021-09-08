//Insertion sort Method 2 (sir)
//=============================
#include <iostream>
using namespace std;

void sortArray(int[], int);

int main(){
	int arr[]={8, 7, 6, 5, 4, 3, 2, 1};
	int length=sizeof(arr)/sizeof(arr[0]);

	
	cout << "\nUnsorted Array : ";
	for(int i=0; i<length; i++){
		cout << arr[i] << " ";
	}
	
	
	sortArray(arr, length);

	cout << "\nSorted Array : ";
	for(int i=0; i<length; i++){
		cout << arr[i] << " ";
	}
	return 0;
}


void sortArray(int arr[], int length){
	int temp=0;
	
	for(int i=1; i<length; i++){
		for(int j=0; j<i; j++){
			if(arr[j]>arr[i]){
				temp=arr[i];
				for(int k=i; k>j; k--){
					arr[k]=arr[k-1];
				}
				arr[j]=temp;
				break;
			}
		}
	}	
}
