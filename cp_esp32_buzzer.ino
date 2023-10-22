
//定义LED1管脚
#define CP_GPIO 25
#define BUTTON_PIN 26 // ESP32 GPIO16 pin connected to button's pin
#define BUTTON_PIN2 27 // ESP32 GPIO16 pin connected to button's pin

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP); // set ESP32 pin to input pull-up mode
  pinMode(BUTTON_PIN2, INPUT_PULLUP); // set ESP32 pin to input pull-up mode
  pinMode(CP_GPIO, OUTPUT);       // set ESP32 pin to output mode
}


void loop() {
  int buttonState = digitalRead(BUTTON_PIN); // read new state
  int buttonState2 = digitalRead(BUTTON_PIN2); // read new state
  if (buttonState == LOW) {
    Serial.println("The button is being pressed");
    digitalWrite(CP_GPIO, HIGH); // turn on
    delay(20);//延时200ms
    digitalWrite(CP_GPIO, LOW); // turn on
    delay(20);//延时200ms
  } else {
    Serial.println("The button is unpressed");
    if (buttonState2 == LOW) {
      Serial.println("The button2 is being pressed");
      digitalWrite(CP_GPIO, HIGH); // turn on
      delay(200);//延时200ms
      digitalWrite(CP_GPIO, LOW); // turn on
      delay(200);//延时200ms
    } else {
      Serial.println("The button2 is unpressed");      
    }
  }
}
