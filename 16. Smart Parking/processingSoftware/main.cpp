#include <iostream>
#include <conio.h>
#include "prototypes.hpp"

using namespace std;



int main(int argc, char** argv) {
	
	recPark parking;
	int numParkings, sel;
	
	while (true){
		
		numParkings = loadData(parking);		//Carica le informazioni del file nella variabile parking e salva il numero di parcheggi disponibili
		
		do{
			system("cls");
			cout<<"\n\nScegliere l'opzione desiderata: ";
			cout<<"\n\n1) Visualizza mappa parcheggio;";
			cout<<"\n\n2) Prenota parcheggio;";
			cout<<"\n\n3) Esci dall'applicazione.";
			cout<<"\n\n\nInserisci la tua scelta: ";
			cin>>sel;
		}	while (sel <= 0 || sel > 3);
	
		switch(sel){
			
			case 1: {
				
				system("cls");
				
				cout<<"\n\n-------------------------PARCHEGGI DISPONIBILI "<<numParkings<<" su 4---------------------------\n\n"<<endl;
				
				printData(parking);						//Stampa le informazioni caricate dal file
				getch();
				break;
			}
			


			case 2: {
				
				system("cls");
				
				int place = allocateParking(parking);
				
				if (place > 0)
					cout<<"\n\nPrenotazione effettuata con successo!\n\nIl posto prenotato \212 il "<<place<<".";
				else
					cout<<"\n\nTutti i parcheggi sono occupati.";
				
				getch();
				break;
			}
				
				
				
			case 3: {
				
				return 0;
			}
				
				 
		}
	}
}
