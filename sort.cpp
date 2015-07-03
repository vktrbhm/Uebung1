#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include <cmath>
#include <iostream>
#include <string>
#define anzahl 3										// Es gibt 3 zu sortierende Zahlen


using namespace std;									// Damit nicht immer std:: geschrieben werden muss 
//int a_new, b_new, c_new;								// Globale Definition der Ergebnissvariablen

// Bubble Sort
int* sort (int a,int b,int c)				
{
	int zahlen[3] = {a,b,c}, mem;						// Initialiesierung Array "Zahlen" mit Eingabewerten; Definition Zwischenspeicher
	int a_new, b_new, c_new;							// Definition Ergebnissvariablen

	for (int i=0;i<anzahl;i++)							// Beginn Iteration_1; Von Array[0] bis Array[2] -> Alle zu sortierenden Werte 					
	{
		for(int j=0;j<anzahl-i;j++)						// Beginn Iteration_2; Anzahl-i weil der größte Wert ja schon am Ende steht
		{
			if(zahlen[j]>zahlen[j+1])					// Vergleich ob Wert > als nachfolge Wert
			{
				mem = zahlen[j];						// Zwischenspeicher der größeren Zahl
				zahlen[j] = zahlen[j+1];				// Tausch_1 -> Kleiner nach Vorne
				zahlen[j+1] = mem;						// Tausch_2 -> Größer nach hinten
			}
		}
	}
	// Frage: Wie gebe ich Arrays zurück? 
	a_new = zahlen[1];									
	b_new = zahlen[2];
	c_new = zahlen[3];
	cout << "Die Zahlen nach ihrer Größe sortiert lauten : " << a_new <<" "<< b_new<< " " << c_new <<endl;
	return 0;
	//return a_new, b_new, c_new;
	//return zahlen;
}

int main(int argc, char* argv[])
{
	int a, b, c;
	
	cout << "**--Zahlen-Sortierer--**" <<endl;
	cout << "**------------------------------**" <<endl;
	cout << "Bitte geben Sie die drei Zahlen ein, die Sie sortieren möchten : " <<endl;
	cout << "Zahl 1 :" <<endl; cin >> a ;
	cout << "Zahl 2 :" <<endl; cin >> b ;
	cout << "Zahl 3 :" <<endl; cin >> c ;
	sort(a,b,c);
	//cout << "Die Zahlen nach ihrer Größe sortiert lauten : " << a_new <<" "<< b_new<< " " << c_new <<endl;
	int* var=sort(a,b,c);
	for (int i=0;i<anzahl;i++)
	{
		cout << *var[i] << endl;
 	}
	
	
}