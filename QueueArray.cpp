#include <iostream>
using namespace std;

//implementation of queue using arrays

//prototyping the functions
void enqueue();
bool isFull();
bool isEmpty();
void dequeue();
int peek();
void display();


//declaring the array   rear-> _ _ _ _ _  <- front
//Global variables and array
int maxSize = 5;
int queue[5];
int front = -1 ;
int rear = -1; 


int main(){
	
	int exit = 1, choice,  peeking;  //declaring the variables used in the main function
	
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
			
			case 1:  //Enqueue
				enqueue();
				break;
			case 2:  //Dequeue
				dequeue();
				break;
			case 3: //Peek
				if(isEmpty()){
					cout << "The queue is empty or all the elements are dequeued." ;
					break;
				}
				else{
					peeking = peek();
					cout << "The peeked value is: " <<peeking << endl;
					break;
				}
			case 4: //Dosplay
				display();
				break;
			case 5: //Exit
				exit = 0;
				cout << "Thankyou!" << endl;			
				break;
			default:
				cout << "Choice is invalid!";	
		}
		cout << "\n" << endl;
	}	
	return (0);
}  

void enqueue(){ //Inserting a value to the queue
	
	int value;
	
	if(isFull()){ //Checking whether the queue is full
		cout << "\nThe queue is full." << endl;
	}
	else{
		cout << "Enter the value you need to enter: " ;
		cin >> value;
		if(isEmpty()){
			front = 0;
		}
		rear = rear + 1 ;
		queue[rear] = value;
	}
}

void dequeue(){ //Deleting the elements, according to the entered order first in first out
	
	int del; //a variable is declared to store the value of the deleting element
	
	if(isEmpty()){ //If the queue is empty, there's no element to delete
		cout << "The queue is empty or all the elements are dequeued." << endl;
	}
	else{
		del = queue[front];  // the element to be deleted is assigned into a variable
		queue[front] = 0;
		front = front + 1 ;   //front is increased to the next index, where there's a value in the variable
		cout << "The dequeued element is: " << del << endl; //The deleted element is printed, it was saved in del variable in 92line
	}
}

int peek(){
	int topVal = queue[rear]; //The last input value is assigned into a new variable and it is returned to the main function 
	return topVal;
}

void display(){
	
	if(isEmpty()){
		cout << "The queue is empty." << endl;
	}
	else{
		cout << "queue is:" << endl;
		/*if queue is not empty, the front is pointing to the current firstly entered element, and rear>0;	and rear 
		is pointing to the last entered element.*/
		for(int i = front; i <=rear; i++){  
			cout << queue[i] << " " ;
		}
		cout << "\n" << endl;
	}
}

/*in this queue, rear is indexing as 0,1,2,3,4 . Here maxsize is 5 becuase there are 5 elements.
when front reach the maximum size of the queue, its index is 4 and it is (maxSize-1). So here this is used to check the 
overflow condition of the queue,*/

bool isFull(){    

	if(rear == (maxSize-1)){
		return true;
	}
	else{
		return false;
	}
}

bool isEmpty(){
	
	//if((rear == -1 && front == -1)){
	
	/* here, in the websites front > rear was not available. so in this case if all the 
	elements are dequeued and after that dequeue or peek function is called, 0 is printed*/
	
	if((rear == -1 && front == -1) || front > rear){ 
		return true;
	}
	else{
		return false;
	}
	
		/* Also, (rear== -1 && front == -1) means that there is no element entered into the queue, it is an unoccupied queue,
		no element is enqueued or dequeued */
	
		/* here when all the elements are dequeued (queue is fully occupied but all the elements are dequeued) , and again when 
		the user ask to dequeue an element or peek the value, this will print queue is empty */
}



