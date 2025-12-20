// Investment.cpp
#include "Investment.h"
#include <iomanip>

using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;
using std::left;
using std::right;
using std::setw;

// Default constructor
Investment::Investment()
    : m_initialInvestment(0.0),
    m_monthlyDeposit(0.0),
    m_annualInterestRate(0.0),
    m_years(0) {
}

// Overloaded constructor
Investment::Investment(double initial, double monthly, double annualRate, int years)
    : m_initialInvestment(initial),
    m_monthlyDeposit(monthly),
    m_annualInterestRate(annualRate),
    m_years(years) {
}

void Investment::setInvestmentValues(double initial, double monthly, double annualRate, int years) {
    m_initialInvestment = initial;
    m_monthlyDeposit = monthly;
    m_annualInterestRate = annualRate;
    m_years = years;
}

// Report without additional monthly deposits
void Investment::printReportWithoutMonthlyDeposits() const {
    double currentBalance = m_initialInvestment;
    double annualRateDecimal = m_annualInterestRate / 100.0;

    cout << endl;
    cout << "  Balance and Interest Without Additional Monthly Deposits" << endl;
    cout << "==================================================================" << endl;
    cout << left << setw(8) << "Year"
        << right << setw(20) << "Year End Balance"
        << right << setw(26) << "Year End Earned Interest" << endl;
    cout << "------------------------------------------------------------------" << endl;

    cout << fixed << setprecision(2);

    for (int year = 1; year <= m_years; ++year) {
        double yearInterest = currentBalance * annualRateDecimal;
        double yearEndBalance = currentBalance + yearInterest;

        cout << left << setw(8) << year
            << right << setw(20) << yearEndBalance
            << right << setw(26) << yearInterest << endl;

        currentBalance = yearEndBalance;
    }
}

// Report with additional monthly deposits
void Investment::printReportWithMonthlyDeposits() const {
    double currentBalance = m_initialInvestment;
    double monthlyRateDecimal = (m_annualInterestRate / 100.0) / 12.0;

    cout << endl;
    cout << "  Balance and Interest With Additional Monthly Deposits" << endl;
    cout << "==================================================================" << endl;
    cout << left << setw(8) << "Year"
        << right << setw(20) << "Year End Balance"
        << right << setw(26) << "Year End Earned Interest" << endl;
    cout << "------------------------------------------------------------------" << endl;

    cout << fixed << setprecision(2);

    for (int year = 1; year <= m_years; ++year) {
        double yearInterest = 0.0;

        for (int month = 1; month <= 12; ++month) {
            // Opening amount is current balance at the start of the month
            double openingAmount = currentBalance;
            double depositedAmount = m_monthlyDeposit;

            // Total of opening balance + deposit
            double totalForMonth = openingAmount + depositedAmount;

            // Interest for this month:
            // (Opening Amount + Deposited Amount) * (AnnualRate/100/12)
            double interestForMonth = totalForMonth * monthlyRateDecimal;

            // Closing balance = total + interest
            double closingBalance = totalForMonth + interestForMonth;

            yearInterest += interestForMonth;
            currentBalance = closingBalance;
        }

        double yearEndBalance = currentBalance;

        cout << left << setw(8) << year
            << right << setw(20) << yearEndBalance
            << right << setw(26) << yearInterest << endl;
    }
}
