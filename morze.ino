int led = 2;
int DOT_DURATION = 500;
const int MAX_LETTER_LENGTH = 3;

enum MorseSymbols { 
  DASH = '-',
  DOT = '.',
};

MorseSymbols DICTIONARY[][MAX_LETTER_LENGTH] = {
  { DASH, DASH, DASH }, // O
  { DOT, DOT, DOT }, // S
};

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  sendLetter('S');
  delay(DOT_DURATION * 3);
  
  sendLetter('O');
  delay(DOT_DURATION * 3);

  sendLetter('S');
  delay(DOT_DURATION * 7);
}

void sendLetter(char letter) {
  int letterIndex;
  if (letter == 'S') {
    letterIndex = 1;
  } else {
    letterIndex = 0;
  }

  for (int i = 0; i < MAX_LETTER_LENGTH; i++) {
    sendSignal(DICTIONARY[letterIndex][i]);
    if (i != MAX_LETTER_LENGTH - 1) {
      delay(DOT_DURATION);
    }
  }
}

void sendSignal(MorseSymbols type) {
  switch(type) {
    case DASH:
      sendDash();
      break;
    case DOT:
      sendDot();
      break;
  }
}

void sendDash() {
  digitalWrite(led, HIGH);
  delay(DOT_DURATION * 3);
  digitalWrite(led, LOW);
}

void sendDot() {
  digitalWrite(led, HIGH);
  delay(DOT_DURATION);
  digitalWrite(led, LOW);
}
