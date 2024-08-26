#include <iostream>
using namespace std;

int main() {

	int n;
	cin >> n;

	for(int row=0; row<n; row=row+1 ){
		for(int col=0; col<n-row; col=col+1) {
			cout << col+1<< " ";
		}
		cout << endl;
	}

	// for(int row=0; row<n; row=row+1) {
	// 	for(int col=0; col<row+1; col = col + 1) {
	// 		cout << col+1 << " ";
	// 	}
	// 	cout << endl;
	// }

	// for(int row=0; row<n; row=row+1) {
	// 	for(int col=0; col<n-row; col=col+1) {
	// 		cout << "* " ;
	// 	}
	// 	cout << endl;
	// }
	
	// int n;
	// cin >> n;

	// for(int row=0; row<n; row=row+1) {
	// 	for(int col=0; col<row+1; col=col+1) {
	// 		cout << "* ";
	// 	}
	// 	cout << endl;
	// }

	// int ROWS = 10;
	// int COLS = 7;
	// //outer loop
	// for(int row=0; row<ROWS; row=row+1 ) {
	// 	//inner loop
	// 	for(int col=0; col<COLS; col=col+1) {
	// 		//if zeroth or last row, then print star
	// 		if(row == 0 || row == ROWS-1) {
	// 			cout << "* ";
	// 		}
	// 		else {
	// 			if(col ==0 || col ==COLS-1) {
	// 				cout << "* ";
	// 			}
	// 			else {
	// 				cout << "  ";
	// 			}
	// 		}
	// 	}
	// 	cout << endl;
	// }


	
	//outer loop -> rows
	// for(int i=0; i<3; i=i+1) {
	// 	//for each row, print 5 star
	// 	//inner loop -> print 5 stars

	// 	for(int j=0; j<5; j=j+1) {
	// 		cout << "* ";
	// 	}
	// cout << endl;
		
	// }
	
	//outer loop -> rows
	// for(int i=0; i<4; i=i+1) {

	// 	//print 4 stars
	// 	for(int j=0; j<4; j=j+1) {
	// 		cout << "* ";
	// 	}
	// 	cout << endl;
	// }



	return 0;
}