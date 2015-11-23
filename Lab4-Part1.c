#include <stdio.h>
#include <stdlib.h>

int main(void) {

   int inputCents, quarter, leftover1, dime, leftover2, nickel, leftover3, cent;

	//getting the amount to change
	printf("Please give an amount in cents less than 100: ");
	scanf("%d", &inputCents);

	while (inputCents> 0 && inputCents<100){

		//calculations
		quarter = inputCents / 25;
		leftover1 = inputCents % 25;
		dime = leftover1 / 10;
		leftover2 = leftover1 % 10;
		nickel = leftover2 / 5;
		leftover3 = leftover2 % 5;
		cent = leftover3;


		if (quarter == 0)
			printf("%d cents: ", inputCents);
		else if (quarter == 1)
			printf("%d cents: %d quarter, ", inputCents, quarter);
		else if (quarter > 1)
			printf("%d cents: %d quarters, ", inputCents, quarter);

		if (dime == 0)
			printf("");
		else if (dime == 1)
			printf("%d dime, ", dime);
		else if (dime > 1)
			printf("%d dimes, ", dime);

		if (nickel == 0)
			printf("");
		else if (nickel == 1)
			printf("%d nickel, ", nickel);
		else if (nickel > 1)
			printf("%d dimes, ", nickel);

		if (cent == 0)
			printf("\b\b.");
		else if (cent == 1)
			printf("%d cent.", cent);
		else if (cent > 1)
			printf("%d cents.", cent);

		printf("Please give an amount in cents less than 100: ");
		scanf("%d", &inputCents);
	}

	printf ("Goodbye");

    return (0);
}
