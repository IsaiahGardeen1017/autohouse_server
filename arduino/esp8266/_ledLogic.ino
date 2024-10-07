
void ledLoop(int itr){
  switch(itr % 4){
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
}