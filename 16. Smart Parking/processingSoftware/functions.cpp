#include <iostream>
#include <fstream>
#include "prototypes.hpp"

using namespace std;



/*Questa funzione carica gli stati scritti da Arduino sul file
  nel programma in C++ per la visualizzazione.*/

int loadData (recPark &parking){
	
	ifstream data;										//Apre il file "data.txt" come input
	data.open("data.txt");
	
	char element[MAX_LEN];								//Definisce una stringa dove mettere le righe lette dal file
	int numParkings = 0;								//Inizializza il numero di parcheggi disponibili a 0
	
	if (!data.fail()){									//Se il file è stato aperto correttamente...
				
		data.getline(element, 2);						//Acquisisci la riga dal file
		parking.park1 = element[0] - 48;				//Lo stato del parcheggio è dato dal codice ASCII meno lo spiazzamento (48)
		
		if (parking.park1 == 0)							//Se lo stato del parcheggio è uguale a 0 il numero di parcheggi disponibili viene incrementato
			numParkings++;
			
			
		//Ripeti le stesse operazioni per gli altri parcheggi
		
		
		data.getline(element, 2);				
		parking.park2 = element[0] - 48;			
		
		if (parking.park2 == 0)
			numParkings++;
			
		
		data.getline(element, 2);
		parking.park3 = element[0] - 48;
		
		if (parking.park3 == 0)
			numParkings++;
		
		
		data.getline(element, 2);
		parking.park4 = element[0] - 48;
		
		if (parking.park4 == 0)
			numParkings++;
	}
	
	else 												//Se il file non è stato aperto correttamente stampa a schermo il seguente messaggio di errore
		cout<<"\n\nFile ""data.txt"" was not found.";
		
	data.close();										//Chiude il file
	
	return numParkings;									//Restituisce il numero di parcheggi disponibili
}



/*Questa funzione visualizza gli stati dei parcheggi
  mediante una tabella.*/
  
void printData (recPark &parking){
	
	char flag1, flag2, flag3, flag4;					//Dichiara variabili di stato per essere visualizzate
	
	int i, r;											
	
	char aas = 218, aad = 191, abas = 192, abd = 217, ta = 193, tb = 194, ts = 195, td = 180, cr = 197, lo = 196 , lv = 179;		//Inizializza delle variabili per definire la tabella di visualizzazione
		
	if (parking.park1 == 1)								//Se il primo parcheggio è uguale a 1...
		flag1 = 'S';									//Assegna al primo flag la lettera "S" (Sì)
	else
		flag1 = 'N';									//Altrimenti assegna al primo flag la lettera "N" (No)
		
		
	//Ripeti le stesse operazioni per gli altri parcheggi
	
	
	if (parking.park2 == 1)
		flag2 = 'S';
	else
		flag2 = 'N';
	
	
	if (parking.park3 == 1)
		flag3 = 'S';
	else
		flag3 = 'N';
	
	
	if (parking.park4 == 1)
		flag4 = 'S';
	else
		flag4 = 'N';
	
	
	//Stampa la tabella
	
	
	cout<<"    "<<aas;	
		
	for(r = 0; r < 4; r++){
		for (i = 0; i < 14; i++){
			cout<<lo;
		}
		if (r == 3)
			break;
		cout<<tb;
	}
	cout<<aad<<endl;									//Stampa la prima linea della tabella
		
	cout<<"    "<<lv<<" Parcheggio 1 "<<lv<<" Parcheggio 2 "<<lv<<" Parcheggio 3 "<<lv<<" Parcheggio 4 "<<lv<<endl;				//Intestazione della tabella
	
	cout<<"    "<<ts;
	for(r = 0; r < 4; r++){
		for (i = 0; i < 14; i++){
			cout<<lo;
		}
		if (r == 3)
			break;
		cout<<cr;
	}
	cout<<td<<endl;										//Stampa la seconda linea della tabella
	
	cout<<"    "<<lv<<"       "<<flag1<<"      "<<lv<<"       "<<flag2<<"      "<<lv<<"       "<<flag3<<"      "<<lv<<"       "<<flag4<<"      "<<lv<<endl;			//Riga con gli stati dei parcheggi
		
	cout<<"    "<<abas;
	for(r = 0; r < 4; r++){
		for (i = 0; i < 14; i++){
			cout<<lo;
		}
		if (r == 3)
			break;
		cout<<ta;
	}
	cout<<abd<<endl;									//Stampa la liena finale della tabella
	
	return;
}



int allocateParking (recPark &parking){
	
	ofstream data;
	data.open("data.txt");
	
	if (parking.park1 == 0){
		
		data<<"1"<<endl;
		data<<parking.park2<<endl;
		data<<parking.park3<<endl;
		data<<parking.park4;
		
		return 1;
	}
	
	else if (parking.park2 == 0){
		
		data<<parking.park1<<endl;
		data<<"1"<<endl;
		data<<parking.park3<<endl;
		data<<parking.park4;
		
		return 2;
	}
	
	else if (parking.park3 == 0){
		
		data<<parking.park1<<endl;
		data<<parking.park2<<endl;
		data<<"1"<<endl;
		data<<parking.park4;
		
		return 3;
	}
	
	else if (parking.park4 == 0){
		
		data<<parking.park1<<endl;
		data<<parking.park2<<endl;
		data<<parking.park3<<endl;
		data<<"1";
		
		return 4;
	}
	
	else return -1;
}
