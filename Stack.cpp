#include<iostream>
using namespace std;

//prototyping
void push(int data); //void push();
void pop();
void peek();
bool isFull();
bool isEmpty();
void display();

//initializing the maxSize...this is used in isFull function
int maxSize = 5;
int stack[5]; // can't initialize array like stack[maxSize]
int top = -1; //At the beginning the stack is empty and in the push top is incremented to 0 so here top should be 0-1 = -1

int main(){
	int choice,exit = 0 ;
	
	while(exit==0){
		
		cout << "1. Push data\n2. Pop data\n3. Peek\n4. Display data\n5. Exit\n\nEnter your choice: " ;
		cin >> choice;
		
		switch(choice){
			
			case 1: //push
				int data;
				if(isFull()){ //checking whether the stack is full
					cout << "The stack is full." << endl;
				}
				else {
					cout << "Enter the data: ";
					cin >> data;
					push(data);
				}
				//push();
				break;
			case 2: //pop
				if(isEmpty()){ // checking whether the stack is empty
					cout << "\nThe stack is empty." << endl;
				}
				else {
					pop();	
				}
				break;
			case 3: //peek
				if(isEmpty()){ // checking whether the stack is empty
					cout << "\nThe stack is empty." << endl;;
				}
				else {
					peek(); //This function prints the value of the top
				}
				break;
			case 4:
				if(isEmpty()){ // checking whether the stack is empty
					cout << "\nThe stack is empty." << endl;
				}
				else {
					display(); // Displaying the stack
				}
				break;
			case 5:
				exit = 1; // Exiting the application
				break;
			default: 
				cout << "Invalid choice." ; //When some other choice is entered, this is displayed
				break;
		}
		
		cout << "\n" <<endl;
	}	
	return 0 ;
}

void push(int data){ 
//void push(){
	top = top + 1;
	stack[top] = data;
	cout << "Data is pushed." << endl;
	
//	cout << "\ntop is: " << top << endl; // to check the top
	/*	int data;
		if(isFull()){
			cout << "The stack is full." << endl;
		}
		else {
			cout << "Enter the data: ";
			cin >> data;
			top = top + 1;
			stack[top] = data;
			cout << "\ntop is: " << top << endl;
		}
	*/
}
void pop(){ // removing the topmost value from the stack
	int item = stack[top]; // the current top is stored in a variable ->item
	top = top-1; //the top is decremented by 1... so that the previous top is a garbage value now
	cout << "\nThe popped item was: " << item << endl; // The stored previous top value can be displayed as it is the popped item
	//cout << "The top after pop is: " << top << endl; // to check the top
}
void peek(){
	int item = stack[top];
	cout << "The top item is: " << item << endl;	
}
bool isFull(){ // check whether the stack is full
	if(top == 4){
		return true;
	}
	else{
		return false;
	}
}
bool isEmpty(){ // checking whether the stack is empty
	if(top == -1){
		return true;
	}
	else{
		return false;
	}
}
void display(){ // displaying the stack
	
	int counter;
	cout << "The stack is: " << endl;
	for(int i= top ; i >=0 ; i--){
		cout << stack[i] << " " ;
		counter++;
	}
	
	cout <<"\nNmber of elements in the stack: " << counter << endl;
	
}
