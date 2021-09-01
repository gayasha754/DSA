#include<iostream>
using namespace std;

//Printing the factorials for an user entered integer
void fac(int n);

//Printing the factorial value
int facNum(int n);

int main(){

    int n;
    cout << "Enter an integer: " ;
    cin >> n;
    cout << "Factorials are: \n" ;
    fac(n);
	cout << "\n!" << n << " : " << facNum(n);
	    
	return(0);
}

void fac(int a){         //Printing the factorials for an user entered integer
    // 5.4.3.2.1
    int b =1;
    if(a > 0){
      // 5, 4, 
    	b= b * a;
      // 1 * 5
      // 5 * 4
    	cout << b << " ";
    	fac(a-1);
	}
}

int facNum(int n){     //Printing the factorial value
	
	if (n==1 || n==0){
		return 1;
	}
	else{
		return n*facNum(n-1);
	}
	
}


