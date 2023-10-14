const int BUTTON1 = 7;
const int BUTTON2 = 6;
const int LED1 = 13;
const int LED2 = 12;
const int LED3 = 11;
const int LED4 = 10;
const int LED5 = 9;
const int LED6 = 8;

int BUTTONstate1 = 0;
int BUTTONstate2 = 0;

const int LEDs[6] = {LED1, LED2, LED3, LED4, LED5, LED6};

void led_off() {
    for (int i = 0; i < 6; i++){
        digitalWrite(LEDs[i], LOW);
    }
}

void setup() {
  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);
  for (int i = 0; i < 6; i++){
    pinMode(LEDs[i], OUTPUT);
  }
}

void loop() {
  BUTTONstate1 = digitalRead(BUTTON1);
  if (BUTTONstate1 == HIGH){
    for (int i = 0; i < 6; i++){
      if (BUTTONstate1 == HIGH){
        digitalWrite(LEDs[i], HIGH);
        digitalWrite(LEDs[(i+5) % 6], LOW);
        delay(1000);
        BUTTONstate1 = digitalRead(BUTTON1);
      }
      else{
        break;
      }
    }
  }
  
  else{
    led_off();
  }

  BUTTONstate2 = digitalRead(BUTTON2);
  int status = HIGH;
  if(BUTTONstate2 == HIGH){
    for(int i = 0; i < 6; i++){
        if(i % 2 == 0){
          digitalWrite(LEDs[i], status);
        }
        else{
          digitalWrite(LEDs[i], !status);
        }
        if (i == 5 && digitalRead(BUTTON2)){
              delay(1000);
              status = !status;
              i = -1;
        }
      }
  }
  else{
    led_off();
  }
}
