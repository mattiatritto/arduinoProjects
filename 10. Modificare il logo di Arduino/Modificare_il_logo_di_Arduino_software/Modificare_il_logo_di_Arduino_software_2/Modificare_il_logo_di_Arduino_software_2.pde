import processing.serial.*;                                                                                  //Importa la libreria processing.serial.*
Serial myPort;                                                                                               //Crea un'istanza dell'oggetto seriale.

PImage Logo;                                                                                                 //Oggetto che contiene l'immagine.
int Colore_Sfondo = 0;

void setup()
{
  colorMode(HSB, 255);                                                                                       
   Logo = loadImage("https://www.arduino.cc/en/pub/skins/arduinoWide/img/logo.png");                         //Scarica il logo da utilizzare.
   size(Logo.width, Logo.height);                                                                            //Lo sketch si ridimensiona automaticamente alle dimensioni dell'immagine.
   
   println("Porte seriali disponibili: ");
   println(Serial.list());                                                                                   //Stampa un elenco di porte seriali dispinibili.
   myPort = new Serial(this, Serial.list()[0], 9600);                                                        //Fornisce le informazioni sulla connessione seriale.
   }
   
   void draw()
   {
     if (myPort.available() > 0)                                                                             //Controlla se ci sono informazioni da Arduino.
     {
       Colore_Sfondo = myPort.read();                                                                        //Se si' leggile e memorizzale nella variabile Colore_Sfondo.
       println(Colore_Sfondo);                                                                               //Stampa il valore nella finestra di debug.
       }
       
       background(Colore_Sfondo, 255, 255);                                                                  //Imposta il colore della finestra.
       image(Logo, 0, 0);                                                                                    //Disegna il logo tramite le coordinate.
       }
