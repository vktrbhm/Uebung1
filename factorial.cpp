#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include <cmath>
#include <iostream>
#include <string>

using namespace std;									// Damit nicht immer std:: geschrieben werden muss 


/*--- FUNKTIONEN ---*/

// Funktion zur Berechnung der Fakultät einer Zahl 
unsigned factorial(unsigned n)
{	
	int result = 1;
	if (n==0){											// Fakultät, der Zahl 0 ist gleich 1
		result = 1;
		return result;
	}
	else{
		for (int i=1;i<=n;i++)							// Iteratiosschleife zur Fakultätsberechnung
		{
			result = result * i;
		
		}
		return result;
	}	
}

// Funktion zur Berechnung der Quersumme einer Zahl 
unsigned checksum(unsigned n)
{
	int result = 0;
	int rest;

	while (n>0)
	{
		rest = n % 10;									// Restmenge der Zahl mod 10 = hinterste Stelle der Zahl
		result = result + rest;		
		n = n / 10;										// Ausnutzen, dass n vom typ integer ist (n=123/10=12) 
	}
	return result;
}

// Funktion zur Überprufung einer Primzahl 
unsigned is_prime (unsigned n)
{
	for (int i=2;i<n;i++)
	{
		if (n%i==0)										// Zahl mod einer vorgehenden Zahl = 0 -> keine Primzahl
		{
			return false;
		}
	}
	return true;
}

// Funktion zur Ausgabe der Nachkommastellen einer Zahl 
double fract (double n)
{
	int sub = n;										// Ausnutzen des Datentyps
	double result = n - sub;							// double - int = Nachkommastellen

	return result;
}

// Funktion zur Berechnung eines Cylindervolumens
double cyl_vol (unsigned r , unsigned h)
{
	double result;
	if (r==0 || h==0)									// Fehler wenn einer der Werte eine Null sein sollte
	{
		return false;
	}
	result = M_PI * pow(r,2) * h;
	return result;
}

// Funktion zur Berechnung einer Cylinderoberfläche
double cyl_surf (unsigned r, unsigned h)
{
	double result;
	if (r==0 || h==0)									// Fehler wenn einer der Werte eine Null sein sollte
	{
		return false;
	}
	result = 2 * M_PI * pow(r,2) + 2 * M_PI * r * h;
	return result;
}

// Funktion zur Umwandlung von Milen in Kilometer
double mileTokilometer (double n)
{
	double result;
	const double fact = 1.609344;						// Konstanter Faktor
	result = n * fact;
	return result;	
}

/* --- TEST --- */

TEST_CASE("describe_factorial", "[factorial]")
{
	REQUIRE(factorial(0) == 1);
	REQUIRE(factorial(4) == 24);
	REQUIRE(checksum(0) == 0);
	REQUIRE(checksum(123) == 6);
	REQUIRE(is_prime(3) == true);
	REQUIRE(is_prime(9) == false);
	REQUIRE(fract(0.14159265359) == Approx(0.14159265359));
	REQUIRE(fract(-3.14159265359) == Approx(-0.14159265359));
	REQUIRE(cyl_vol(2,2) == Approx(25.13274123));
	REQUIRE(cyl_vol(0,1) == false);
	REQUIRE(cyl_surf(2,2) == Approx(50.26548246));
	REQUIRE(cyl_vol(0,1) == false);
	REQUIRE(mileTokilometer(1) == Approx(1.609344));
}


/* --- MAIN --- */

int main (int argc, char* argv[])
{
	double miles;
	cout << "**--Meilen in Kilometer Rechner--**" <<endl;
	cout << "**------------------------------**" <<endl;
	cout << "Wieviele Meilen möchten Sie in Kilometer umgerechnet bekommen? : " <<endl;
	cin >> miles ;
	cout << miles << " Meile(n) sind " << mileTokilometer(miles) << " Kilometer!" <<endl;

	return Catch::Session().run(argc, argv);

}
