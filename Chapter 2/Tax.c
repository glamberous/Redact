/*write a program that does a * thing */
#include <stdio.h>

int main(void)
{
	float price;
	printf("Enter an amount: ");
	scanf("%f", &price);
	printf("With tax added: %.2f\n", price * 1.05);
	
	return 0;
}

