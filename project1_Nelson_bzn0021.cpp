/* FILE NAME: project1_Nelson_bzn0021.cpp
* AUTHOR: Blake Nelson
* Project 1 - program for calculating how long it would take to pay off a loan based off
* loan amount, interest rate, and monthly payments.
*
* I used the hints given by the instructor to help write this code.
*/

#include <iostream>
using namespace std;
int main() {
// VARIABLE INITIALIZATION
float loan = -1;
float interestRate = -1;
float monthlyPaid = -1;

// CURRENCY FORMATTING
cout.setf(ios::fixed);
cout.setf(ios::showpoint);
cout.precision(2);

// USER INPUT
// NOTE: For valid input, the loan, interest, and monthly payment must
// be positive. The monthly payment must also be large enough to
// terminate the loan.
do {
// Your program will not move forward until a positive load is entered
	cout << "\nLoan Amount: ";
	cin >> loan;
	if (loan <=0) {
		cout << "Invalid loan" << endl;
	}
} 

while (loan <= 0);

do {
// Your program will not move forward until a positive load is entered	
	cout << "Interest Rate (% per year): ";
	cin >> interestRate;
	if (interestRate < 0) {
		cout << "Invalid interest rate" << endl;
	}
}
while (interestRate < 0);


// GET PROPER INTEREST RATES FOR CALCULATIONS
interestRate /= 12;
float interestRateC = interestRate / 100;

do {
	cout << "Monthly Payments: ";
	cin >> monthlyPaid;
	if (monthlyPaid <= (interestRateC * loan)) {
		cout << "Insufficient payment" << endl;
	}
}
while (monthlyPaid < (interestRateC * loan));

cout << endl;

// AMORTIZATION TABLE
cout << "*****************************************************************\n"
	<< "\tAmortization Table\n"
	<< "*****************************************************************\n"
	<< "Month\tBalance\t Payment\tRate\tInterest\tPrincipal\n";

	// new variables?
	int currentMonth = 0;
	float interestTotal = 0;
	
	// LOOP TO FILL TABLE
	while (loan > 0) {
		if (currentMonth == 0) {
		cout << currentMonth++ << "\t$" << loan;
		if (loan < 1000) cout << "\t"; // Formatting MAGIC
cout << "\t" << "N/A\tN/A\tN/A\t\tN/A\n";
}
else {
	float monthlyInterestPayment = loan * interestRateC;
	float principal = monthlyPaid - monthlyInterestPayment;
	loan = loan - principal;
	interestTotal = interestTotal + monthlyInterestPayment;
	if (loan < 0) {
		principal = principal + loan;
		monthlyPaid = monthlyPaid + loan;
	}

	cout << currentMonth++ << "\t$" << loan;

	if (loan < 1000) {
		cout << "\t";
	}
	cout << "  $" << monthlyPaid << "\t" << interestRateC * 100 << "\t$" << monthlyInterestPayment << "\t\t$" << principal << "\n";
	}
}
cout << "****************************************************************\n";
cout << "\nIt takes " << --currentMonth << " months to pay off "
<< "the loan.\n"
<< "Total interest paid is: $" << interestTotal;
cout << endl << endl;
return 0;
}


