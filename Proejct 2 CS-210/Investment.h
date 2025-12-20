#pragma once
// investment.h
#ifndef INVESTMENT_H
#define INVESTMENT_H

#include <iostream>

class Investment {
private:
    double m_initialInvestment;
    double m_monthlyDeposit;
    double m_annualInterestRate; // percentage, e.g. 5 for 5%
    int    m_years;

public:
    // Constructors
    Investment();
    Investment(double initial, double monthly, double annualRate, int years);

    // Set all values at once
    void setInvestmentValues(double initial, double monthly, double annualRate, int years);

    // Reports
    void printReportWithoutMonthlyDeposits() const;
    void printReportWithMonthlyDeposits() const;
};

#endif 