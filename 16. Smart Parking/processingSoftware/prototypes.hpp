const int MAX_LEN = 256;

struct recPark {						//Definisce una struttura per definire una variabile di tipo recPark
	
	int park1;
	int park2;
	int park3;
	int park4;
};

int loadData (recPark&);
void printData (recPark&);
int allocateParking (recPark&);
