#include<iostream>
using namespace std;

struct node{
	int data;
	node *next;
};

void display(node *front, node *rear);
void enqueue(node *&front, node *&rear);
void dequeue(node *&front, node *&rear);
void peek(node *&front, node *&rear);
bool isEmpty(node *&front, node *&rear);

int main(){
	
	int exit = 1, choice;  //declaring the variables used in the main function
	
	node *front = NULL;
	node *rear = NULL;
	
	while(exit == 1){
		cout << "1.Enqueue value" <<endl;
		cout << "2.Dequeue value" << endl;
		cout << "3.peek value" << endl;
		cout << "4.Display value" << endl;
		cout << "5.Exit" << endl;
		cout << "Enter your choice: " ;
		cin >> choice;
		cout << "\n" << endl;
		
		switch(choice){
			case 1:
				enqueue(front, rear);
				break;
			case 2:
				dequeue(front, rear);
				break;
			case 3:
				peek(front, rear);
				break;
			case 4:
				display(front, rear);
				break;
			case 5:
				exit = 0 ;
				break;
			default: 
				cout << "Invalid choice.";			
		}
		cout << "\n" << endl; ;
	}
	return(0);
}

void display(node *front, node *rear){
	
	node *temp = new node(); //declaring a ne node to hold the values of the queue
	
	if(isEmpty(front, rear)){
		cout <<"The queue is Empty." << endl;
	}
	else{
		temp = front ;
		cout <<"\nThe List is: ";
		while(temp!= NULL){
			cout << temp->data << " ";
			temp = temp->next;
		}
	}
	cout << "\n";
}

void enqueue(node *&front, node *&rear){
	
	node *temp = new node(); //Declaring a node to keep the data and the pointer part for the new value
	
	cout << "\nEnter the value of the node: ";
	cin >> 	temp->data;	
	temp->next =NULL;
	
	if(isEmpty(front, rear)){ //If the queue is NULL (only in the beginning), front should start pointing at the first node(At the moment the temp)
		front = temp;
		rear = temp;
	}
	else{
		rear->next = temp;
		rear = temp;
	}
	
	/*If the user is entering the first node to the stack, the *next of the temp node should be made as NULL. so that it doesn't 
	point at anywhere. in the beginning top==NULL. So this covers the first node intance also*/
				  
	cout << "The data is enqueued." << endl;
}

void dequeue(node *&front, node *&rear){
	
	node *temp = new node(); //declaring a node to keep the data and pointer part of the value to be deleted
	
	temp = front;
	if(isEmpty(front, rear)){
		cout << "The Queue is empty." << endl;
	}
	else if(front==rear){ 
		cout << "Dequed value is: " << temp->data << endl;
		delete(temp);
		front = rear = NULL;/*If the front and rear is equal; there's only one node. If proceed with the else part, 
		front-> next of the only node in the queue is NULL, so front will get NULL but rear will still point to the 
		same node. It also should be made equal to NULL*/
	}
	else{
		cout << "Dequed value is: " << temp->data << endl;
		front= front->next; //In the first iteration, only the front is made NULL, bz, front->next of the first node is NULL
		delete(temp);
	}
}

void peek(node *&front, node *&rear){
	
	if(isEmpty(front, rear)){
		cout << "The queue is empty." << endl;
	}
	else{ //Display the last entered value of the queue
		cout << "The peeked value is: " << rear->data << endl;
	}
}

bool isEmpty(node *&front, node *&rear){ //Checking whether the queue is Empty
	
	if(rear==NULL && front == NULL){
		return true;
	}
	else{
		return false;
	}
	
}






