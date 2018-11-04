#define PHONE_PIN 8
#define ACC_PIN 12
#define STARTER_PIN 4

#define STATE_LOCK 111
#define STATE_ACC 222 // Включено зажигание
#define STATE_STARTER 333 // Работа стартера
#define STATE_WORK 444 // Двигатель заведен

int state = STATE_LOCK;

void setup() {
  // put your setup code here, to run once:
  pinMode(PHONE_PIN, INPUT);
  pinMode(ACC_PIN, OUTPUT);
  pinMode(STARTER_PIN, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  if (state == STATE_WORK) {
    return;  
  }
  
  int analogValue = analogRead(0);
  if (analogValue > 100) {
    delay(20000);
    digitalWrite(LED_BUILTIN, HIGH);
    digitalWrite(ACC_PIN, HIGH);
    delay(10000);
    
    digitalWrite(LED_BUILTIN, LOW);
    delay(200);
    digitalWrite(LED_BUILTIN, HIGH);
    
    digitalWrite(STARTER_PIN, HIGH);
    delay(3000);
    digitalWrite(STARTER_PIN, LOW);
    digitalWrite(LED_BUILTIN, LOW);
    state = STATE_WORK;
  }
}
