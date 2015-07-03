#include <iostream>

double sum(double a, double b)	// begin scope (a,b)
{
	return a + b;
}								// end scope (a,b)

int square(int i)				// begin scope (i)
{
	return i * i;
}								// end scope (i)

int main()
{
	for(int i = 0; i != 100; ++i)						// begin scope (i) (als iterationsvariable)
	{
		std::cout << "i² = " << square(i) << std::endl
		std::cout << "i+i = " << sum(i,i) << std::endl
	}													// end scope (i)
	return 0;
}


/*
	Signatur einer Funktion
	Zu der Signatur einer Funktion gehört der Name der Funktion (z.B square), die Anzahl und Reihenfolge der eingabe Parameter
	(z.B ...(int i)) und der Typ des Rückgabewertes (z.B int ...(...))

*/

