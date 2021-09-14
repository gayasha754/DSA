#include<iostream>
using namespace std;

struct node{
	int val;
	node * next;
};

//prototyping
void push(node *&top); 
void pop(node *&top);
int peek(node *&top);
bool isEmpty(node *&top);
void display(node *top);

int main(){
	
	node *top = NULL;
	int choice,exit = 0 ;
	
	while(exit==0){
		
		cout << "1. Push data\n2. Pop data\n3. Peek\n4. Display data\n5. Exit\n\nEnter your choice: " ;
		cin >> choice;
		
		switch(choice){
			
			case 1: //push
				push(top);
				break;
			case 2: //pop
				if(isEmpty(top)){ // checking whether the stack is empty
					cout << "\nThe stack is empty." << endl;
				}
				else {
					pop(top);	
				}
				break;
			case 3: //peek
				if(isEmpty(top)){ // checking whether the stack is empty
					cout << "\nThe stack is empty." << endl;
				}
				else {
					cout << "The value at the top is : " << peek(top); //This function prints the value of the top
				}
				break;
			case 4:
				if(isEmpty(top)){ // checking whether the stack is empty
					cout << "\nThe stack is empty." << endl;
				}
				else {
					display(top); // Displaying the stack
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
	
	return(0);
	
}

void push(node *&top){ 
	
	node *temp = new node();
	cout << "\nEnter the value of the node: ";
	cin >> 	temp->val ;	
	
	temp->next = top;  //If the user is entering the first node to the stack, the *next of the temp node 
	top = temp;		  // should be made as NULL. so that it doesn't point at anywhere. in the beginning top==NULL. So this covers the
					  // first node intance also
	cout << "The data is pushed." << endl;
	/*
	cout << "\ntop "<< top ;
	cout << "\n&top: " <<&top;
	cout << "\ntemp: " << temp;
	*/	
}

void pop(node *&top){
	
	node *ptr =top; // another pointer of node type to keep the track of the current top before deleting
	top = top->next;
	
	ptr->next =NULL;
	delete(ptr);
	
	cout << "Data is popped. " << endl;
	
}

int peek(node *&top){
	
	int data = top->val; //current top's value is returned
	return data;
}

bool isEmpty(node *&top){
	
	if(top==NULL){ //if top is NULL that means the stack is empty
		return true;
	}
	else{
		return false;
	}
}

void display(node *top){ //printing the stack
	
	int counter = 0;
	cout <<"\nThe list is :";
	
	while(top!=NULL){
		cout << top->val << " " ;
		top = top->next;
		counter = counter+1;
	}
	cout << endl;
	
	cout << "Number of nodes: " << counter <<endl;
}


