#include<stdio.h>

/*print Fahrenheit-Celsius table
	for fahr = 0, 20, ..., 300; floating-point version */

int main(){

	float fahr, celsius;
	int lower, upper, step;
	
	lower = 0;		//lower limit of temperature table
	upper = 300;	// upper limit 
	step = 20;		// step size	
		

	printf("\tFAHR-CELSIUS CONVERTION\n\n");

	fahr = lower;
	
	while(celsius <= upper){
		fahr = (5.0/9.0) * (celsius-32.0);
		celsius = celsius + step;
		printf("%6.1f %3.0f\n", fahr, celsius);
	}

	return 0;

}

