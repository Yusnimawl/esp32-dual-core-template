#include <WiFi.h>
void iddle(){delay(1000);}
long loops1 = 1200;
long loops2 = 1200;
long qq;
float t1;
int t2, t3;

TaskHandle_t Task0, Task1;

void blink(byte pin, int duration) {

  digitalWrite(pin, HIGH);
  delay(duration);
  digitalWrite(pin, LOW);
  delay(duration);
}
void artificialLoad () {
  for ( long i = 0; i <= loops1; i++) {
    for (long  j = 1; j <= loops2; j++) {
      qq++;
      t1 = 6000.0 * i;
      t2 = 120 * 1200 * i;
      t3 = j % 600 ;
    }
  }
}
void speedtestatcore(){
  long start = millis();
  artificialLoad();
  Serial.print("Finish Loop Task which runs on Core ");
  Serial.print( xPortGetCoreID());
  Serial.print(" Time ");
  Serial.println(millis() - start);
  delay(10);
}


void bootcore(){
    xTaskCreatePinnedToCore(
    loopCore1,
    "core1",
    8000,
    NULL,
    1,
    &Task1,
    1);

delay(500);  

  xTaskCreatePinnedToCore(
    loopCore0,
    "core0",
    1000,
    NULL,
    1,
    &Task0,
    0);
delay(500);

}


void setup() {

  
init4051(12,13,14);

analogReadResolution(9);
analogSetWidth(9);  
analogSetCycles(2); //i got 55-56uS for 6 ADC
  Serial.begin(115200);
  bootcore();
  WiFi.begin();
}


void loop() {
iddle(); // don't add anything
}

long m;
long t;
int a;
int b;
int c;
int d;
int e;
int f;
int g;

void loopCore0( void * parameter ){for (;;) {
Serial.print(a);
Serial.print(", ");
Serial.print(b);

Serial.print(" time = ");
Serial.println(t);

delay(1000);
}}

void loopCore1( void * parameter ){for (;;) { //core 1 sensor dan hitungan
m=micros();
a= readadc(0);
b= readadc(1);
c= readadc(2);
d= readadc(3);
e= readadc(4);
f= readadc(5);
g= readadc(6);
h= readadc(7);
i= readadc(8);
j= readadc(9);
k= readadc(10);
l= readadc(11);
m= readadc(12);
n= readadc(13);

t=micros()-m;
}}

int readadc(int channel){
selectchannel(n);
kiri=analogRead(36);
kanan=analogRead(39);
if(channel%2=0){return kanan;}
else return kiri;
}

void selectchannel(int ch){
  int msb=0<<ch;
  int tsb=1<<ch;
  int lsb=2<<ch;
  
  digitalWrite(a,lsb);
  digitalWrite(b,tsb);
  digitalWrite(c,msb);
  
}

void init4051(int a, int b, int c){
  pinMode(a,INPUT);
  pinMode(b,INPUT);
  pinMode(c,INPUT);
  
}

