// main.cpp
#include <iostream>
#include <iomanip>
#include <limits>
#include "Investment.h"

using std::cin;
using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;

// Simple helper to pause
void waitForEnter() {
    cout << "Press ENTER to continue . . .";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    char again = 'Y';

    while (again == 'Y' || again == 'y') {
        double initialInvestment;
        double monthlyDeposit;
        double annualInterest;
        int    years;

        cout << "**********************************" << endl;
        cout << "*********** Data Input ***********" << endl;

        cout << "Initial Investment Amount: ";
        cin >> initialInvestment;

        cout << "Monthly Deposit: ";
        cin >> monthlyDeposit;

        cout << "Annual Interest (%): ";
        cin >> annualInterest;

        cout << "Number of years: ";
        cin >> years;

        // Clear leftover newline for the pause function
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // Show input summary screen
        cout << endl;
        cout << "**********************************" << endl;
        cout << "*********** Data Input ***********" << endl;
        cout << fixed << setprecision(2);
        cout << "Initial Investment Amount: $" << initialInvestment << endl;
        cout << "Monthly Deposit:           $" << monthlyDeposit << endl;
        cout << "Annual Interest:           " << annualInterest << "%" << endl;
        cout << "Number of years:           " << years << endl;
        waitForEnter();
        cout << endl << endl;

        // Create Investment object and print reports
        Investment invest(initialInvestment, monthlyDeposit, annualInterest, years);

        invest.printReportWithoutMonthlyDeposits();
        invest.printReportWithMonthlyDeposits();

        cout << endl << "Would you like to run another calculation? (Y/N): ";
        cin >> again;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << endl;
    }

    cout << "Thank you for using Airgead Banking Investment Calculator." << endl;
    return 0;
}
