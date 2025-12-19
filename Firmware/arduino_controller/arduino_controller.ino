#include <Wire.h>
#include <SPI.h>
#include <MFRC522.h>
#include <Adafruit_PWMServoDriver.h>

/* ---------------- Servo Driver ---------------- */
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVO_BASE_CH   0
#define SERVO_L1_CH     1
#define SERVO_L2_CH     2

#define SERVO_MIN 150
#define SERVO_MAX 600
#define SERVO_STEP 2

/* ---------------- RFID ---------------- */
#define RFID_SS   10
#define RFID_RST  8

MFRC522 rfid(RFID_SS, RFID_RST);

/* ---------------- Servo State ---------------- */
int currBase = 90, currL1 = 90, currL2 = 90;
int tgtBase  = 90, tgtL1  = 90, tgtL2  = 90;

unsigned long lastUpdate = 0;
String inputBuffer = "";

/* ---------------- Utility ---------------- */
uint16_t angleToPulse(int angle) {
  angle = constrain(angle, 0, 180);
  return map(angle, 0, 180, SERVO_MIN, SERVO_MAX);
}

void smoothMove(uint8_t ch, int &current, int target) {
  if (current < target) current += SERVO_STEP;
  else if (current > target) current -= SERVO_STEP;

  pwm.setPWM(ch, 0, angleToPulse(current));
}

/* ---------------- Setup ---------------- */
void setup() {
  Serial.begin(115200);

  Wire.begin();
  pwm.begin();
  pwm.setPWMFreq(50);

  SPI.begin();
  rfid.PCD_Init();
}

/* ---------------- Main Loop ---------------- */
void loop() {
  readSerial();
  updateServos();
  checkRFID();
}

/* ---------------- Serial Handling ---------------- */
void readSerial() {
  while (Serial.available()) {
    char c = Serial.read();

    if (c == '>') {
      parsePacket(inputBuffer);
      inputBuffer = "";
    } else if (c != '<') {
      inputBuffer += c;
    }
  }
}

void parsePacket(String data) {
  int values[4];
  int index = 0;

  char buf[50];
  data.toCharArray(buf, sizeof(buf));
  char *token = strtok(buf, ",");

  while (token != NULL && index < 4) {
    values[index++] = atoi(token);
    token = strtok(NULL, ",");
  }

  if (index == 4) {
    tgtBase = values[0];
    tgtL1   = values[1];
    tgtL2   = values[2];
  }
}

/* ---------------- Servo Update ---------------- */
void updateServos() {
  if (millis() - lastUpdate >= 20) {
    smoothMove(SERVO_BASE_CH, currBase, tgtBase);
    smoothMove(SERVO_L1_CH,   currL1,   tgtL1);
    smoothMove(SERVO_L2_CH,   currL2,   tgtL2);
    lastUpdate = millis();
  }
}

/* ---------------- RFID ---------------- */
void checkRFID() {
  if (!rfid.PICC_IsNewCardPresent()) return;
  if (!rfid.PICC_ReadCardSerial()) return;

  Serial.print("<RFID,");
  for (byte i = 0; i < rfid.uid.size; i++) {
    Serial.print(rfid.uid.uidByte[i], HEX);
  }
  Serial.println(">");

  rfid.PICC_HaltA();
}
