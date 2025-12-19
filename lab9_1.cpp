#include<iostream>
#include<iomanip> //For using setw(), setprecision(), ...
using namespace std;

double interest (double PB, double In) {
	return (PB * In) / 100.0;
}

int main(){	
	double init, inter, pay;
	int count = 0;

	cout << "Enter initial loan: ";
	cin >> init;

	cout << "Enter interest rate per year (%): ";
	cin >> inter;

	cout << "Enter amount you can pay per year: ";
	cin >> pay;

	//use 'setw' to set width of table and 'left' to set left-alignment
	//you can change input argument of 'setw()' to see the effect
	//Try to change from 'left' to 'right' and see the effect
	cout << setw(13) << left << "EndOfYear#"; 
	cout << setw(13) << left << "PrevBalance"; 
	cout << setw(13) << left << "Interest"; 
	cout << setw(13) << left << "Total";
	cout << setw(13) << left << "Payment";
	cout << setw(13) << left << "NewBalance";
	cout << "\n";
	
	//use 'fixed' and 'setprecision' to fix the number of decimal digits for displaying
	//you can change input argument of 'setprecision()' to see the effect
	cout << fixed << setprecision(2); 

	while (true) {
		count++;

		cout << setw(13) << left << count; 
		cout << setw(13) << left << init;
		cout << setw(13) << left << interest(init, inter);
        cout << setw(13) << left << init + interest(init, inter);

        //total cal
        if (init + interest(init, inter) < pay) {
            pay = init + interest(init, inter);
        }

		cout << setw(13) << left << pay;
		cout << setw(13) << left << (init + interest(init, inter)) - pay;
		cout << "\n";
		
		init = (init + interest(init, inter)) - pay;

        if (init == 0) {
            break;
        }
	}	
	return 0;
}
