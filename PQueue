#include <iostream>
#include <string>
#include <stack>
using namespace std;


int returnValue;	// register to hold function's return value

bool showStack = false;

#define call_0(A,B)         s.push(AR(B));			goto A  // no parameter function
#define call_1(A,B,C)	   	s.push(AR(C,B));        goto A  // one parameter function
#define call_2(A,B,C,D)	   	s.push(AR(D,B,C));      goto A  // two parameter function
#define call_3(A,B,C,D,E)  	s.push(AR(E,B,C,D));    goto A  // three parameter function
#define call_4(A,B,C,D,E,F) s.push(AR(F,B,C,D,E));	goto A  // four parameter function


// j, k, m and n are fixed names for function parameters. These can't be changed.
#define j s.top().param1
#define k s.top().param2
#define m s.top().param3
#define n s.top().param4


// var1 ,var2  etc are fixed names for function local variables. These can't be changed.
#define var1 s.top().localVar1
#define var2 s.top().localVar2
#define var3 s.top().localVar3
#define var4 s.top().localVar4

int label;			// a temp
#define RETURN(X) returnValue = X; label = s.top().returnAddress; s.pop(); \
if		(label == 0) goto END;      \
else if (label == 1) goto L1;       \
else if (label == 2) goto L2;       \
else if (label == 3) goto L3;       \
else if (label == 4) goto L4;       \
else if (label == 5) goto L5;       \
else if (label == 6) goto L6;       \
else if (label == 7) goto L7;       \
else if (label == 8) goto L8;       \
else if (label == 9) goto L9



// Each AR object represents an activation record
class AR {
	friend ostream& operator<<(ostream & out, const AR & a) {
		out << "return address: " << a.returnAddress << "\tparameters: "
			<< a.param1 << " " << a.param2 << " "
			<< a.param3 << " " << a.param4 << "\tlocalVars: "
			<< a.localVar1 << " " << a.localVar2;
		return out;
	}
public:
	int returnAddress, param1, param2, param3, param4, localVar1, localVar2, localVar3, localVar4;

	AR(int returnAddress = 0, int param1 = 0, int param2 = 0, int param3 = 0, int param4= 0) {
		this->returnAddress = returnAddress;
		this->param1 = param1;
		this->param2 = param2;
		this->param3 = param3;
		this->param4 = param4;
		localVar1 = localVar2 = localVar3 = localVar4 = 0;
	}
};

stack<AR> s  ;

void printStackHelper(stack<AR> t) {
	if (!t.empty()) {
		AR a = t.top();
		t.pop();
		cout << a << endl;
		printStackHelper(t);
	}

}

void printStack(string message) {
	if (!showStack) return;

	cout << "<TOP OF STACK> \t" << message << endl << endl;
	printStackHelper(s);
	cout << "_______________________________________________________________________" << endl;


}




int main() {
	cout << "Show the stack (y/n)? ";
	char response;
	cin >> response;
	showStack = response == 'y';

	call_0(fake_main, 0);  // 0 as a return address maps to label END



// fake_main function
fake_main:
	printStack("begin fake_main");
	call_0(menu, 1);
	L1: cout << "BYE" << endl;
	printStack("end fake_main");
	RETURN(0);
	// end fake_main


// menu function
menu:

	while (true) {
		printStack("begin loop in menu");
		cout << endl << "Choose one..." << endl;
		cout << "\t" << "1 factorial." << endl;
		cout << "\t" << "2 fibonacci." << endl;
		cout << "\t" << "3 hanoi." << endl;
		cout << "\t" << "4 exit." << endl;
		cin >> var1;
		if (var1 >= 1 && var1 <= 3) {
			cout << "Enter a parameter value: ";
			cin >> var2;
		}
		else{ RETURN(0); }   // on any number < 1 or > 3 we exit

		if		(var1 == 1)	{ call_1(factorial, var2, 8); }
		else if (var1 == 2) { call_1(fib,		var2, 8); }
		else if (var1 == 3) { call_1(hanoi,		var2, 8); }


		L8: cout << "Return value is " << returnValue << endl << endl;
	}
// end menu





	/*
		// precondition j >= 0
		int factorial(int j) {
			if (j == 0) return 1;
			int var1 = factorial(j-1);
			return var1 * j;
		}
	*/

// factorial(j)
factorial:
	printStack("begin factorial");
	if (j == 0) {RETURN(1); }
	else {
		call_1(factorial, j-1, 2);  // the 2 represents the return address = L2 (below)
		L2:	var1 = returnValue;
		printStack("end of factorial");
		RETURN(var1 * j);
	}
// end factorial




	/*
		int fib(int j) {
			if (j == 0) return 0;
			if (j == 1) return 1;
			int var1 = fib(j-1);
			int var2 = fib(j-2);
			return var1 + var2;
		}

	*/


// fib(j)
fib:
	printStack("begin fib");
    if (j == 0)
        {RETURN(0);}
    else if (j ==1)
        {RETURN(1);}
    else{call_1(fib,j-1, 3);

	L3:var1 = returnValue;
	call_1(fib,j-2,4);

	L4:var2 = returnValue;
	printStack("end fib");
	RETURN(var1 + var2);
    }
// end fib



	/*
		void hanoi(int j) {
			hanoiHelper(j,1,3,2);
			return;
		}

	*/

// hanoi(j)
hanoi:
	printStack("Begin hanoi");
	call_4(hanoiHelper,j,1,3,2,7);  //  1, 3 and 2 represent the three towers
	L7: printStack("End hanoi");
	RETURN(returnValue);
// end hanoi



	/*
		void hanoiHelper(int j, int k, int n, int m) {
			hanoiHelper(j - 1, k, n, m);
			cout << "Move disk " << j << " from tower " << k << " to tower " << m << endl;
			hanoiHelper(j - 1, n, m, k);
			return;
		}

	*/

// hanoiHelper(j,k,m,n)
hanoiHelper:
	printStack("Begin hanoiHelper");
	if (j <= 0) { RETURN(returnValue); }
	else {
        call_4(hanoiHelper,j-1,k,n,m,5);
		L5:
            returnValue++;
		    cout << "Move disk " << j << " from tower " << k << " to tower " << m << endl;
		    call_4(hanoiHelper,j-1,n,m,k,6);

		L6:
		RETURN(returnValue);
	}
// end hanoiHelper

END: printStack("end of program");
// we've exited simulated program.





L9:		// not used
return 0;


}
