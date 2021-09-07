//This program performs adding a node to the beginnning, end,at a location of a linked list AND deleting, updating a node
//Also displaying the linked list

#include <iostream>
using namespace std;

//Structure of nodes
struct node {
	int  val;
	node *next;
};
//prototyping functions

void begNode(node *&h); //pointer is passed by reference

/*
(node *&h) means taking an reference to a pointer....this expects the changes done to the pointer which is passed, 
affect the original location of the pointer as well
*/

void appendNode(node *&h); 
void addNodeLoc(node *&h, int loc );
void displayList(node *h);
void deleteNode(node *&h, int loc );
void updateNode(node *&h, int loc );

int main(){
	
	node *head =NULL;
	int choice, loc=0;;
	int exit = 0;
	while(exit==0){
	
		cout <<"1. Add a node to the beginning\n2. Append a node\n3. Add a node to a location\n4. Update a node\n5. Delete a node\n6. Display List\n7. Exit\nChoice: ";
		cin >> choice;
		
		switch (choice){
			case 1://Add a node to the beginning
				begNode(head); 
				break;
			case 2://Append a node
				appendNode(head); 
				break;
			case 3://Add a node to a location
				cout << "\nEnter the location you want to enter the node: ";
				cin >>loc;
				addNodeLoc(head,loc );
				break;
			case 4://Update a node
				cout << "\nEnter the location of the node you want to update: ";
				cin >> loc;
				updateNode(head,loc );
				break;
			case 5://Delete a node
				cout << "\nEnter the location of the node you want to delete: ";
				cin >> loc;
				deleteNode(head,loc );
				break;					
			case 6: //Display List
				displayList(head);
				break;
			default:
				exit=1;	//when exit is 1, the applicaiton closes
				break;
		}	
		cout << "\n";	
	} 
	return(0);	
}

void begNode(node *&h){  //Add a node to the beginning of the list
	
	/*
	(node *&h) means taking an reference to a pointer....this expects the changes done to the pointer which is passed, 
	affect the original location of the pointer as well
	*/
	
	node *temp = new node();
	cout << "\nEnter the value of the node: ";
	cin >> 	temp->val ;	
	temp->next = h;
	h = temp;

}

void appendNode(node *&h){  //Add a node to the end of the list
	
	/*
	(node *&h) means taking an reference to a pointer....this expects the changes done to the pointer which is passed, 
	affect the original location of the pointer as well
	*/
		
	node *temp = new node();
	cout << "\nEnter the value of the node: ";
	cin >> temp->val;
	temp->next = NULL;
	
	if (h == NULL){ //If there is no any node, the value entered is added to the head
		h = temp;
	}
	else{
		node *current = h; //current is a pointer which moves along the nodes
		while(current->next != NULL){
			current = current->next; //current pointer is moved along the nodes list
		}
		current->next= temp;
	}
} 

void addNodeLoc(node *&h, int loc ){
	
	/*
	(node *&h) means taking an reference to a pointer....this expects the changes done to the pointer which is passed, 
	affect the original location of the pointer as well
	*/
	
	if(loc==1){ //If the user enter location=1
		//The list is empty, so the begNode(h); is called so that the node can be added to the beginning
		begNode(h);//prototype is done in the beginning
	}
	else{
		node *temp = new node;
		cout << "Enter the value of the node: ";
		cin >> temp->val;
		
		loc--; //location-1
		node *current = h;
		while(loc !=1){
			current = current->next;
			loc--;	
		}
		temp->next = current->next;
		current->next = temp;
	}
}

void updateNode(node *&h, int loc ){
	
	/*
	(node *&h) means taking an reference to a pointer....this expects the changes done to the pointer which is passed, 
	affect the original location of the pointer as well
	*/
	
	if (h == NULL){ //If there is no any node
		cout << "The list is empty!\n";
	}
	else{
		int val;
		cout << "\nEnter the new value of the node: ";
		cin >> val;
		
		node *current = h;
		while(loc !=1){
			current = current->next;
			loc--;	
		}
		current->val = val;
	}
}

void deleteNode(node *&h, int loc ){
	
	/*
	(node *&h) means taking an reference to a pointer....this expects the changes done to the pointer which is passed, 
	affect the original location of the pointer as well
	*/
	
	node *current = h;
	node *prev = h;
	
	if (h == NULL){ //If there is no any node
		cout << "The list is empty!\n";
	}
	else if(h->next==NULL){ //If there is only one node
		current = h;
		h = NULL;
		delete(current);
	}
	else if (loc==1){ // if the first node is needed to be deleted
		h = h->next;
		current->next = NULL;
		delete(current);
	}
	else{ // delete a node at a location  
	//if location is 3,
		
		while(loc !=1){ 
			prev = current; //prev points to the place where current is pointing
			current = current->next; // current points to the next node
			loc--;	//location no decrements -> 3,2
		}
		//while loop stops at 1 and current is pointing to the 3rd node
		prev->next =NULL; //prev is pointing at the 2nd node and the 2nd node's next* is set to NULL
		prev->next = current->next; //then the *next of prev(2nd node) is now pointed to the next* of the 3rd node
		
		current->next = NULL; // next* of the 3rd node is set to NULL
		delete(current);
	}
	
	
}

void displayList(node *h){   //Display the list
	
	//As this function doesn't do any changes to the pointer which is passed, here the pointer is passed by value
	
	cout <<"\nThe List is: ";
	while(h!= NULL){
		cout << h->val << " ";
		h = h->next;
	}
	cout << "\n";
}	
	



