#include <SoftwareSerial.h>
#include <QueueList.h>

// create a queue of int messages.
QueueList <int> queue1;
QueueList <int> queue2;

SoftwareSerial mySerial(2, 3); // RX, TX

void setup() {
// Open serial communications and wait for port to open:
Serial.begin(9600);



// set the data rate for the SoftwareSerial port
mySerial.begin(4800);
}

void loop() { // run over and over


//// read from port 1, send to port 0:
 if (mySerial.available()>0) {
 int inByte = mySerial.read();

 queue1.push (inByte);

}
 if (Serial.available()>0) {
 int inByte = Serial.read();

 queue2.push (inByte);

}
if (!queue1.isEmpty ()){
 Serial.write(queue1.pop ());

}

// read from port 0, send to port 1:
 if (!queue2.isEmpty ()){
 mySerial.write(queue2.pop ());

}





}



void serialEvent() {

if (mySerial.available()>0) {
 int inByte = mySerial.read();

 queue1.push (inByte);

}

if (Serial.available()>0) {
 int inByte = Serial.read();

 queue2.push (inByte);

}


}