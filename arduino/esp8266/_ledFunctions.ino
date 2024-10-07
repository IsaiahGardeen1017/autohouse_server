#define LED D0  // Led in NodeMCU at pin GPIO16 (D0).

#define REDi D1
#define GREi D2
#define BLUi D3
#define Hg D4

int maxVal = 255;

void ledSetup(){
  pinMode(LED, OUTPUT);
  pinMode(REDi, OUTPUT);
  pinMode(GREi, OUTPUT);
  pinMode(BLUi, OUTPUT);
  pinMode(Hg, OUTPUT);
}


void ledOn(){
  digitalWrite(LED, LOW);
}

void ledOff(){
  digitalWrite(LED, HIGH);
}

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