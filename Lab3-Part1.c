#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int inputPurchasePrice, inputDownPayment, inputFinanceTerm;
    double inputMonthlyInterest, nominator, denominator, outputMonthlyPayment;

    //Getting the values from the user
    printf("Enter the purchase price: ");
    scanf("%d", &inputPurchasePrice);
    printf("Enter the amount of down payment: ");
    scanf("%d", &inputDownPayment);
    printf("Enter the finance term (in months): ");
    scanf("%d", &inputFinanceTerm);
    printf("Enter the monthly interest rate (in percentage): ");
    scanf("%lf", &inputMonthlyInterest);

    //Calculations
    nominator = (inputPurchasePrice - inputDownPayment) * (inputMonthlyInterest/100) * pow((1 + inputMonthlyInterest/100), inputFinanceTerm);
    denominator = pow((1 + inputMonthlyInterest/100), inputFinanceTerm) - 1;
    outputMonthlyPayment = nominator / denominator;

    //Printing out the results
    printf("The monthly payment is: %.2lf", outputMonthlyPayment);

    return (0);
}
