// Binary Search Tree - Implemenation in C++
// Simple program to create a BST of integers and search an element in it 

#include<iostream>
using namespace std;

//Definition of Node for Binary search tree
struct node{
	int data;
	node* rightChild;
	node* leftChild;	
};

// Function to create a new Node in heap
node* NewNode(int data){
	node* newNode = new node();
	newNode->data = data;
	newNode->leftChild = NULL;
	newNode->rightChild = NULL;
	return newNode;	
}

//Function to do inorder traversal of Binary Search Tree(BTS)
void inorder(node* root){
	//After the recurssive function of the lest sub tree...it goes to the root and then to the right sub tree.

	if(root!=NULL){
		inorder(root->leftChild); 
		cout << root->data << " ";
		inorder(root->rightChild);
	}
}

//Insert data in BST....returns address of root node....if the reference is passed, no need to return the root value
node* Insert(node* root, int data){
	
	if(root==NULL){ //If the tree is empty
		root = NewNode(data);
	}
	else if(data <= root->data){  // if data to be inserted is lesser, insert in left subtree
		root->leftChild =  Insert(root->leftChild,data);
	}
	else{ // else, insert in right subtree
		root->rightChild =Insert(root->rightChild, data);
	}
	return root;
}

//To search whether the user input element exists or not....if exists, return true
bool search(node* root, int data){
	
	if(root==NULL){
		return false;
	}
	else if(root->data == data){
		return true;
	}
	else if(data < root->data){
		return search(root->leftChild, data);
	}
	else{
		return search(root->rightChild, data);
	}
}

/* Given a non-empty binary search tree, return the node
with minimum key value found in that tree. Note that the
entire tree does not need to be searched. */
node* minValueNode(node* root)
{
    node* current = root;
 
    /* loop down to find the leftmost leaf */
    while (current && current->leftChild != NULL)
        current = current->leftChild;
 
    return current;
}


//this function deletes the key and returns the new root
node* deleteNode(node* root, int data){
	
	if(root==NULL){
		return root;
	}

	//If the data input is smaller than the root, it lies in the left subtree
	if(data <root->data){
		root->leftChild = deleteNode(root->leftChild, data);
	}
	else if(data > root->data){
		root->rightChild = deleteNode(root->rightChild, data);
	}	
	
	//if data is same as the root->data, then this is the node to be deleted
	else{ 	
		//if node has no child
		if(root->leftChild == NULL && root->rightChild == NULL){
			return NULL;
		}
		//if node has only one child or no child
		else if(root->leftChild == NULL){
			node* temp = root->rightChild;
			delete(root);
			return temp;
		}
		else if(root->rightChild == NULL){
			node* temp = root->leftChild;
			delete(root);
			return temp;
		}
		
		// node with two children: Get the inorder successor
        // (smallest in the right subtree)
        node* temp = minValueNode(root->rightChild);
 
        // Copy the inorder successor's content to this node
        root->data = temp->data;
 
        // Delete the inorder successor
        root->rightChild = deleteNode(root->rightChild, temp->data);
    }
    return root;
	
}


int main(){
	
	node* root = NULL;  //Creating an empty Tree
	node *min= NULL;	/*Creating an empty node...used to store the node which returns the minimum data 
						in node* minValueNode(node* root) function*/
	
	//As the Insert function returns the value of the root, root needs to be updated
	//Some data are inserted in to the tree already....
	root = Insert(root,15);
	root = Insert(root,10);	
	root = Insert(root,20);
	root = Insert(root,25);
	root = Insert(root,8);
	root = Insert(root,12);
	
	int numSearch, numDelete, numInsert, exit = 0, choice = 0;
 	
 	while (exit!=1){
 		
 		cout << "---BTS---Choices\n1. Search\n2. insert\n3. delete\n4. minvalue\n5. Inorder traversal of tree\n6. Exit" << endl;
 		cout << "Enter the choice: " ;
 		cin >> choice ;
 		
 		switch(choice){
 			
 			case 1:
 				cout << "Enter the number to be searched:";
				cin >> numSearch;
				cout << endl;
				
				if(search(root,numSearch)){
					cout << "Found" <<endl;
				}
				else{
					cout << "Not Found" << endl;
				}
				
				cout << "Inorder traversal of the given tree \n";
			    inorder(root);
			    break;
 			
			case 2:
				cout << "Enter the number to be inserted: " ;
				cin >> numInsert;
				root = Insert(root, numInsert);
				cout << "Inorder traversal of the modified tree \n";
				inorder(root);
				break;
				
			case 3:
				cout << "Enter the number to be deleted: " ;
				cin >> numDelete;
				root = deleteNode(root, numDelete);
				cout << "Inorder traversal of the modified tree \n";
				inorder(root);
				break;
				
			case 4:
				min = minValueNode(root);
				cout << "Minimum value is: " << min->data << endl;
				break;
				
			case 5:
				cout << "InOrder traversal of the tree :" << endl;
				inorder(root);
				break;
				
			case 6:
				exit = 1;
				break;
				
			default:
				cout << "Invalid Choice!" << endl; 
				
		}
		cout << "\n" << endl;
	 }
 	
	
	
	return(0);
}
