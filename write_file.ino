// Josh Higgins
const unsigned int ledPin = 13;
const unsigned int delayTime = 1500;

void setup() {
  // put your setup code here, to run once:
  delay(1000);
  // Setup LED
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  turnCapsOff();
  // start doing things
  robot();
}

// this function turns off caps lock
void turnCapsOff() {
    while (!(keyboard_leds & 2))
    {
        key(KEY_CAPS_LOCK, 0);
    }
    if (keyboard_leds & 2)
    {
        key(KEY_CAPS_LOCK, 0);
    }
}

// Open an application on Windows via Run
void openapp(String app) {
  // Windows Key + R to open Run
  key(KEY_R , MODIFIERKEY_RIGHT_GUI);
  delay(delayTime);
  // Type the App you want to open
  Keyboard.print(app);
  key(KEY_ENTER, 0);
  Keyboard.send_now();
  delay(delayTime);
}

void key(int KEY, int MODIFIER) {
  Keyboard.set_modifier(MODIFIER);
  Keyboard.set_key1(KEY);
  Keyboard.send_now();
  delay(20);
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
  delay(20);
 }

// this is my main function
void robot() {
  openapp("cmd");
}

void loop() {
  // put your main code here, to run repeatedly:
  // Blink -> IT'S DONE
  digitalWrite(ledPin, HIGH);
  delay(80);
  digitalWrite(ledPin, LOW);
  delay(80);
}
