#include <stdio.h>
#include <stdlib.h>

int main(void) {

    double inputMonthlyRate, inputServiceDuration, inputSwipeFeeRate, inputAppleFeeRate, outputCharge, outputSwipePayed, outputFeeApple;
    int outputFreeMonth;
    const double HST = 0.13;
    
    //Enter the monthly rate, service duration, total fee rate and Apple`s fee rate
    printf("Enter the monthly rate: ");
    scanf("%lf", &inputMonthlyRate);
    printf("Enter the service duration (in months): ");
    scanf("%lf", &inputServiceDuration);
    printf("Enter the swipe fee rate (in percentage): ");
    scanf("%lf", &inputSwipeFeeRate);
    printf("Enter the Apple Pay rate (in percentage): ");
    scanf("%lf", &inputAppleFeeRate);
    
    //After inputs, its time for calculations
    outputFreeMonth = inputServiceDuration / 4;
    outputCharge = (inputServiceDuration - outputFreeMonth) * inputMonthlyRate * (1 + HST);
    outputSwipePayed = (inputServiceDuration - outputFreeMonth) * inputMonthlyRate * (1 + HST)*(0.03);
    outputFeeApple = outputSwipePayed * (0.25);
    
    //Calculations are over. Time to print the results
    printf("Your total free month(s) using iBell's service is: %d\n", outputFreeMonth);
    printf("Your total charge including taxes is: %5.2lf\n", outputCharge);
    printf("The swipe fee paid to Mastercard is: %5.2lf\n", outputSwipePayed);
    printf("The fee paid to use Apple pay is: %5.2lf\n", outputFeeApple);
    //Program is terminated    
    return (0);
}
