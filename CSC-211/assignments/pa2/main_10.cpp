#include <iostream>

int main()
{
    long double initial_loan, monthly_interest, monthly_payment;
    std::cin >> initial_loan >> monthly_interest >> monthly_payment;
    if (initial_loan < 0 || initial_loan >= 10000000000)
    {
        std::cin >> initial_loan;
    }
    if (monthly_interest <= 0 || monthly_interest >= 0.5)
    {
        std::cin >> monthly_interest;
    }
    if (monthly_payment < 0 || monthly_payment >= initial_loan)
    {
        std::cin >> monthly_payment;
    }

    // monthly payment takes place AFTER LOAN ACCRUES INTEREST FOR MONTH. MINIMUM OF ONE MONTH REQUIRED TO PAY OFF A LOAN. PRINT NUM OF MONTHS TO PAY LOAN
    // 500.0 , 0.05 , 499.0  EO: 2

    int months_until_loan_paid = 0;
    long double current_loan = initial_loan;
    while (current_loan > 0)
    {
        current_loan = (current_loan + (current_loan * monthly_interest));
        current_loan = current_loan - monthly_payment;
        months_until_loan_paid++;
    }
    std::cout << months_until_loan_paid;
}