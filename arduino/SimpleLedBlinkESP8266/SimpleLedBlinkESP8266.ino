#define LED D0  // Led in NodeMCU at pin GPIO16 (D0).

#define REDi D1
#define GREi D2
#define BLUi D3
#define Hg D4


int i = 0;


void setup() {
  pinMode(LED, OUTPUT);  // LED pin as output.
}


void loop() {
  i++;
  switch(i % 5){
    case 0: 
      allOff();
      ledOn();
      break;
    case 1:
      redOn();
      ledOff();
      break;
    case 2:
      blueOn();
      ledOff();
      break;
    case 3:
      greenOn();
      ledOff();
      break;

  }
  delay(500);
}

void ledOn(){
  digitalWrite(LED, LOW);
}

void ledOff(){
  digitalWrite(LED, HIGH);
}

int maxVal = 255;

void redOn() {
  setBrightness(Hg, maxVal);
  setBrightness(REDi, 0);
  setBrightness(GREi, maxVal);
  setBrightness(BLUi, maxVal);
}

void greenOn() {
  setBrightness(Hg, maxVal);
  setBrightness(REDi, maxVal);
  setBrightness(GREi, 0);
  setBrightness(BLUi, maxVal);
}

void blueOn() {
  setBrightness(Hg, maxVal);
  setBrightness(REDi, maxVal);
  setBrightness(GREi, maxVal);
  setBrightness(BLUi, 0);
}

void allOff() {
  setBrightness(Hg, 0);
  setBrightness(REDi, 0);
  setBrightness(GREi, 0);
  setBrightness(BLUi, 0);
}

void setBrightness(int led, int brightness) {
  analogWrite(led, brightness);
}