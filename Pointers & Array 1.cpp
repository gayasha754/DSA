#include <iostream>
using namespace std;


int main(){
	
	int a[5] = {2,4,6,9,10};	
	int *q = a;
	cout << "q: "  << q  << endl;
	cout << "*q: " << *q << endl;
	cout << "*a: " << *a << endl;
	cout << "*(a+1): " << *(a+1) <<endl;
	cout << "*a+1 : "  << *a+1   <<endl;
	//*a means the value of thefirst element of the array, and *a+1 means adding 1 to the value of the first elemnt of the array
	
	cout << "\n2[a]: " << 2[a] << endl;
	cout << "a[2]: "   << a[2] << endl; 
	cout << "\na[1]: " << a[1] << endl;
	cout << "1[a]: "   << 1[a] << endl;
	cout << "1[q]: "   << 1[q] << endl; 
	cout << "*(1+a): " << *(1+a) << endl;  
	
	cout << "\nPrinting the array:" <<endl;
	cout << "\n\nIn the format of a[i]: " <<endl;
	for(int i=0; i<5; i++){
		cout<< a[i] << " ";	
	}
	
	cout << "\n\nIn the format of *(q+i): " <<endl;
	
	for(int i=0; i<5; i++){
		cout << *(q+i) << " ";
		//q points for the 0th element->address of that element
        //q+1 means 4 is added to the address of the 1st element of the array  
	}
	
	return(0);
}
