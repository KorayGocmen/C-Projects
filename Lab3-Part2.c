#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
     int inputOBP, inputThreshold;

	//Getting the inputs
	printf("Enter the threshold in celsius: ");
	scanf("%d", &inputThreshold);
	printf("Enter the observed boiling point in celsius: ");
	scanf("%d", &inputOBP);

	//decisions
	if ((inputOBP >= 100 - inputThreshold) && (inputOBP <= 100 + inputThreshold))
    	printf("The substance you tested is: Water");

	else if ((inputOBP >= 357 - inputThreshold) && (inputOBP <= 357 + inputThreshold))
    	printf("The substance you tested is: Mercury");

	else if ((inputOBP >= 1187 - inputThreshold) && (inputOBP <= 1187 + inputThreshold))
    	printf("The substance you tested is: Copper");

	else if ((inputOBP >= 2193 - inputThreshold) && (inputOBP <= 2193 + inputThreshold))
    	printf("The substance you tested is: Silver");

	else if ((inputOBP >= 2660 - inputThreshold) && (inputOBP <= 2660 + inputThreshold))
    	printf("The substance you tested is: Gold");


	else
    	printf("Substance unknown.");


    return (0);
}
