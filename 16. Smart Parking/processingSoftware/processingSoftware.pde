import processing.serial.*;

PrintWriter data;
Serial myPort;


void setup() { 
  
  data = createWriter("data.txt");
  myPort = new Serial(this, "COM3", 9600);
}


void draw() {

  while(myPort.available() > 0) {
    
    String string = myPort.readString();
      
    if(string != null) {
      data.println(string);
    }
  }
}


void keyPressed() {

  data.flush();
  data.close();
  exit();
}
