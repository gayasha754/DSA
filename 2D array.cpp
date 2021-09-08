#include <iostream>
using namespace std;

void print(int (&array1)[2][3]){ // the way the function takes the arguments to the parameters
	
	//printing 2D array
	cout <<"printing 2D array\n" ;
	for(int i = 0; i < 2; i++){
		
		for(int j = 0; j < 3; j++){
			
			cout << array1[i][j] << " ";
		}
	} 
}


int main (){
	
	int numbers [2][3] = {{2,4,5},{10,12,15}}; //initializing array
	//Column should be always stated int numbers[][3]; this is also correct
	

	
	//printing 2D array
	print(numbers); //passing a 2D array to a function by referance
	
	int *ptr, *ptr1;
	ptr = &numbers[0][0];
	ptr1 = numbers[0];
	
	cout <<"\n\nptr = &numbers[0][0] : " <<ptr;
	cout << "\nptr1 = numbers[0] : " << ptr1 << endl;
	cout << "\n*ptr : " << *ptr  << endl;
	cout <<"\nnumbers : " << numbers;
	cout << "\n&numbers:" << &numbers;
	cout << "\nnumbers[0]: " << numbers[0];
	cout <<"\n*numbers[0] : " << *numbers[0];
	cout << "\n&numbers[0][0] : " << &numbers[0][0];
	cout << "\nnumbers[0][0] : " << numbers[0][0] <<endl;
	
	cout << "\n&numbers[1]: " << &numbers[1];
	cout << "\nnumbers+1 : " << numbers+1;
	cout << "\nnumbers[1] : " << numbers[1] << endl;
	
	cout << "\nnumbers[1]+1 : " << numbers[1]+1; // this will add 4 bytes to  the address of the first value of the array
	cout << "\n&numbers[1]+1 : " << &numbers[1]+1 ;
	/*This means.. &numbers gives the address to the whole array and adding 1 arithmatically means it returns the address of the element 
	after that whole array. That means the address of the next array which is numbers[2]  */
	cout << "\nnumbers[2] : " << numbers[2] << endl;
	
	
	//(number+1) is a complete array Then *(numbers+1) means value at (numbers+1). 
	//As it is a complete array this will return the address of the first element of the array. It is similar to   numbers[1] .
	cout << "\n*(numbers+1) : " << *(numbers+1) <<endl;
	
	/*number returns the address of the first element of the 1st array,
	number+1 returns the next element of the array, it is also a complete array so (number+1)
	returns the address of the first element of the 2nd sub array.
	*(number+1) returns the complete value of the  second array.... that means the address of first element of 2nd array
	adding 2 to it means in the same array pointing  to 2 elements away element 
	that means adding 8 byts (2x4bytes)
	*/
	
	cout << "\n*(numbers+1)+2 : " << *(numbers+1)+2 <<endl ;
	
	//value at *(number+1)+2
	cout << "\n*(*(numbers+1)+2 : " << *(*(numbers+1)+2);
	cout << "\n*(numbers[1]+2) : " << *(numbers[1]+2) <<endl;
	
	/*
	To print the value at the variable
	==================================
	if the row number is i and column number is j
		numbers[i][j] = *(*(numbers+1) +j) = *(numbers[i] +j)
	
	*/
	
	
	cout << "\n*(*numbers+1) : " << *(*numbers+1); //*numbers returns the address of the first element of the array.
	//(*numbers+1) means the next one added variable... 4 integers added to the address of numbers variable that means second variable of the first array
	
	
	
	cout <<"\n**numbers: "<< **numbers;
	//cout <<"\n**ptr: " << **ptr1 ; // jenny's lecture on 2d array.... this gives an error
	
	
	
	
	return(0);
}
