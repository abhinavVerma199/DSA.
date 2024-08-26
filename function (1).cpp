#include <iostream>
using namespace std;

// void printName(string name) {
// 	for(int i=0; i<5; i++) {
// 		cout << name << endl;
// 	}
// }


//function delclaration
// void printLine();

// void printA() {
// 	cout << "i am inside A" << endl;
// }

// void printSum(int a, int b, int c) {
// 	int answer = a + b + c;
// 	cout << "Sum is: " << answer << endl;
// }

// int printSum(int a, int b, int c) {
// 	int ans = a + b + c;
// 	return ans;
// }


// void messagePrint() {
// 	cout << "Msg 1" << endl;
	
// 	cout << "Msg 2" << endl;
// 	return;
// }

// void printMaximum(int num1, int num2, int num3) {
// 	if(num1 >= num2 && num1 >= num3) {
// 		cout << "Maximum is: " << num1 << endl;
// 	}
// 	else if(num2 >= num1 && num2 >= num3) {
// 		cout << "Maximum is: " << num2 << endl;
// 	}
// 	else {
// 		cout << "Maximum is: " << num3 << endl;
// 	}
	
// }

int printMaximum(int n1, int n2, int n3) {
	int ans1 = max(n1,n2);
	int finalAns = max(ans1, n3);
	// cout << "final Ans is: " << finalAns << endl;
	return finalAns;
 }


void printCounting(int n) {
	for(int i=1; i<=n; i++) {
		cout << i << endl;
	}
}

void checkEvenOdd(int num) {
	if(num % 2 == 0) {
		cout << "Even Number" << endl;
	}
	else {
		cout << "Odd Number" << endl;
	}
} 

void findSumUptoN(int n) {
	int sum = 0;

	for(int i=1; i<=n; i++) {
		sum = sum + i;
	}

	cout << "Final Sum: " << sum << endl;
	
}

void findSumEvenUptoN(int n) {
	int sum = 0;

	for(int i=1; i<=n; i++) {
		if(i%2 ==0) {
			sum = sum + i;
		}
		
	}

	cout << "Final Sum: " << sum << endl;
	
}

//return true -> if N is a prime no.
//return false -> if N is not a prime no.

bool checkPrime(int n) {

	for(int i=2; i<n; i++) {
		if(n%i == 0) {
			//remainder = 0 -> perfectly divisible
			//not a prime numbner
			return false;
		}
	}
	//yaha pr main keh skta hu
	//k [ 2,3,4,5 ------ n-1 ], koi bhi N ko perfectly divide 
	//nahi kar paya hoga

	//it means, N is a prime no.
	return true;
	
}



int main() {

	bool prime = checkPrime(1);

	if(prime) {
		cout << "its a prime number" << endl;
	}
	else {
		cout << "its not a prime number" << endl;
	}

	//findSumEvenUptoN(10);
	
	//checkEvenOdd(110);
	
	//printCounting(10);

	// int maximum = printMaximum(3, 30, 100);
	// cout << " Maximum is: " << maximum << endl;


	
	//messagePrint();

	// int sum = printSum(4, 4, 5);
	// cout << "Sum is: " << sum << endl;
	
	// printSum(1,2,7);

	//function call
	// printLine();
	// cout << "Hi" << endl;
	// printA();
	
    return 0;
}

// void printLine() {
// 	for(int i=0; i<10; i++) {
// 		cout << "Sundar ko Sundari pasand hai" << endl;
// 	}
// }

