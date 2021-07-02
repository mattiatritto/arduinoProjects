import processing.serial.*;                                                 //Importa la libreria per la comunicazione seriale
import java.awt.event.KeyEvent;                                             //Importa la libreria per leggere i dati dalla porta seriale
import java.io.IOException;

Serial myPort;

String angle = "";
String distance = "";
String data = "";
String noObject;
float pixsDistance;
int intAngle, intDistance;
int index1 = 0, index2 = 0;
PFont orcFont;


void setup() {
 
 size (700, 420);                                                           //Imposta la risoluzione dello schermo
 smooth();
 myPort = new Serial(this, "COM3", 9600);                                   //Inizia la comunicazione seriale
 myPort.bufferUntil('.');                                                   //Legge i dati dalla porta seriale fino al punto(.). Dunque legge angolo e distanza
 orcFont = loadFont("OCRAExtended-30.vlw");                                 //Utilizza il font di caratteri "OCRAExtended"
}


void draw() {
  
  fill(98, 245, 31);                                                        //Colore verde
  textFont(orcFont);                                                       
  noStroke();                                                              //Disabilita il contorno
  fill(0, 4);                                                               //Colore nero
  rect(0, 0, width, height-height*0.065);                                 //Disegna un rettangolo
  
  fill(98,245,31);                                                          //Verde
                                                                            
  drawRadar();                                                         //Chiama la funzione per disegnare il radar
  drawLine();                                                          //Chiama la funzione per disegnare le linee
  drawObject();                                                        //Chiama la funzione per disegnare l'oggetto
  drawText();                                                          //Chiama la funzione per scrivere il testo
}


void serialEvent (Serial myPort) {                                          //Funzione che inizia a leggere dati dalla porta seriale

  data = myPort.readStringUntil('.');                                       //Legge i dati dalla porta seriale fino al punto (.) e lo pone nella variabile "data"
  data = data.substring(0, data.length() - 1);
  
  index1 = data.indexOf(",");                                               //Trova la virgola e mette l'indice della virgola nella variabile "index1"
  angle = data.substring(0, index1);                                        //Legge la stringa dall'elemento 0 all'elemento index1 (valore dell'angolo)
  distance = data.substring(index1 + 1, data.length());                     //Legge la stringa che parte dall'indice successivo di "index1" fino alla fine della stringa
  
  intAngle = int(angle);                                                    //Converte le variabili di tipo stringa in variabili di tipo intero
  intDistance = int(distance);
}


void drawRadar() {
  
  pushMatrix();                                                             //Salva le coordinate precedenti
  translate(width/2, height-height*0.074);
  noFill();
  strokeWeight(2);                                                          //Imposta la larghezza del tratto
  stroke(98, 245, 31);                                                      
  
  arc(0, 0, (width-width*0.0625), (width-width*0.0625), PI, TWO_PI);
  arc(0, 0, (width-width*0.27), (width-width*0.27), PI, TWO_PI);
  arc(0, 0, (width-width*0.479), (width-width*0.479), PI, TWO_PI);
  arc(0, 0, (width-width*0.687), (width-width*0.687), PI, TWO_PI);

  line(-width/2,0, width/2,0);
  line(0,0,(-width/2)*cos(radians(30)),(-width/2)*sin(radians(30)));
  line(0,0,(-width/2)*cos(radians(60)),(-width/2)*sin(radians(60)));
  line(0,0,(-width/2)*cos(radians(90)),(-width/2)*sin(radians(90)));
  line(0,0,(-width/2)*cos(radians(120)),(-width/2)*sin(radians(120)));
  line(0,0,(-width/2)*cos(radians(150)),(-width/2)*sin(radians(150)));
  line((-width/2)*cos(radians(30)),0,width/2,0);
  popMatrix();                                                                                //Ripristina le coordinate precedenti
}


void drawObject() {
  
  pushMatrix();                                                                                //Salva le coordinate precedenti
  translate(width/2, height-height*0.074);                                                     //Muove le coordinate iniziali alla posizione specificata
  strokeWeight(9);                                                                               //Imposta lo spessore dei tratti
  stroke(255, 10, 10);                                                                             //Colore rosso
  pixsDistance = intDistance*((height-height*0.1666)*0.025);                                     //Converte la distanza del sensore da cm a pixel
                                                                                                 //Limita il range a 40 cm
  if(intDistance < 40){                                                                            //Disegna l'oggetto tenendo conto della distanza e dell'angolo
    line(pixsDistance*cos(radians(intAngle)), -pixsDistance*sin(radians(intAngle)),(width-width*0.505)*cos(radians(intAngle)), -(width-width*0.505)*sin(radians(intAngle)));
  }
  
  popMatrix();                                                                                  //Ripristina le coordinate precedenti
}


void drawLine() {
  
  pushMatrix();                                                                                 //Salva le coordinate precedenti
  strokeWeight(9);                                                                              //Imposta lo spessore dei tratti
  stroke(30, 250, 60);
  translate(width/2, height-height*0.074);                                                       //Muove le coordinate alla nuova posizione
  line(0, 0, (height-height*0.12)*cos(radians(intAngle)), -(height-height*0.12)*sin(radians(intAngle))); //Disegna la linea in accordo con l'angolo
  popMatrix();                                                                                  //Ripristina le coordinate precedenti
}

void drawText() {                                                                  //Visualizza il testo sullo schermo
  
  pushMatrix();                                                                    //Salva le coordinate precedenti
  
  if (intDistance > 40) {                                                          //Se la distanza è maggiore di 40 cm scrive "Fuori dal range"...
    noObject = "Fuori dal range";
  }
  
  else {                                                                          //...altrimenti scrive "Nel range"
    noObject = "Nel range";
  }
  
  fill(0, 0, 0);
  noStroke();
  rect(0, height-height*0.0648, width, height);                                  //Disegna un rettangolo
  fill(98, 245, 31);
  textSize(18);                                                                  //Imposta la grandezza dei caratteri a 18 pixel
  
  text("10cm", width-width*0.3854, height-height*0.0833);
  text("20cm", width-width*0.281, height-height*0.0833);
  text("30cm",width-width*0.177, height-height*0.0833);
  text("40cm",width-width*0.0729, height-height*0.0833);
  textSize(18);                                                                  //Imposta la grandezza dei caratteri a 18 pixel
  text("Oggetto: " + noObject, width-width*0.875, height-height*0.0277);         //"Oggetto: Fuori/Nel range"
  text("Angolo: " + intAngle +"°", width-width*0.48, height-height*0.0277);     //"Angolo: (angolo)"
  text("Distanza: ", width-width*0.26, height-height*0.0277);                    //"Distanza: (distanza)"
  
  if(intDistance < 40) {                                                        //Se la distanza è minore di 40 cm
    text("        " + intDistance +" cm", width-width*0.225, height-height*0.0277);
  }
  
  textSize(18);                                                                  //Imposta la grandezza del font a 18 pixel
  fill(98, 245, 60);
  translate((width-width*0.4994)+width/2*cos(radians(30)), (height-height*0.0907)-width/2*sin(radians(30)));
  rotate(-radians(-60));
  text("30°",0,0);
  resetMatrix();
  translate((width-width*0.503)+width/2*cos(radians(60)),(height-height*0.0888)-width/2*sin(radians(60)));
  rotate(-radians(-30));
  text("60°",0,0);
  resetMatrix();
  translate((width-width*0.507)+width/2*cos(radians(90)),(height-height*0.0833)-width/2*sin(radians(90)));
  rotate(radians(0));
  text("90°",0,0);
  resetMatrix();
  translate(width-width*0.513+width/2*cos(radians(120)),(height-height*0.07129)-width/2*sin(radians(120)));
  rotate(radians(-30));
  text("120°",0,0);
  resetMatrix();
  translate((width-width*0.5104)+width/2*cos(radians(150)),(height-height*0.0574)-width/2*sin(radians(150)));
  rotate(radians(-60));
  text("150°",0,0);
  popMatrix();                                                                   //Ripristina le coordinate precedenti
}
