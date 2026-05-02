#include <LiquidCrystal.h>
#include <Adafruit_NeoPixel.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#define PIXEL_PIN 10
#define PIXEL_COUNT 12

Adafruit_NeoPixel ring(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800);

const int tempPin = A0;

const int ledCold = 6;
const int ledNormal = 7;
const int ledWarm = 8;
const int ledHot = 9;

void clearStatusLeds() {
  digitalWrite(ledCold, LOW);
  digitalWrite(ledNormal, LOW);
  digitalWrite(ledWarm, LOW);
  digitalWrite(ledHot, LOW);
}

void setRingColor(int count, int r, int g, int b) {
  ring.clear();

  for (int i = 0; i < count; i++) {
    ring.setPixelColor(i, ring.Color(r, g, b));
  }

  ring.show();
}

void printPadded(const char* text) {
  lcd.print(text);

  int length = strlen(text);
  for (int i = length; i < 16; i++) {
    lcd.print(" ");
  }
}

void startupAnimation() {
  ring.clear();

  for (int i = 0; i < PIXEL_COUNT; i++) {
    ring.clear();
    ring.setPixelColor(i, ring.Color(0, 0, 255));
    ring.show();
    delay(80);
  }

  for (int i = 0; i < PIXEL_COUNT; i++) {
    ring.clear();
    ring.setPixelColor(i, ring.Color(0, 255, 0));
    ring.show();
    delay(80);
  }

  for (int i = 0; i < PIXEL_COUNT; i++) {
    ring.clear();
    ring.setPixelColor(i, ring.Color(255, 0, 0));
    ring.show();
    delay(80);
  }

  for (int i = 0; i < PIXEL_COUNT; i++) {
    ring.setPixelColor(i, ring.Color(255, 255, 255));
  }

  ring.show();
  delay(300);

  ring.clear();
  ring.show();
}

void setup() {
  Serial.begin(9600);

  lcd.begin(16, 2);

  ring.begin();
  ring.show();

  pinMode(ledCold, OUTPUT);
  pinMode(ledNormal, OUTPUT);
  pinMode(ledWarm, OUTPUT);
  pinMode(ledHot, OUTPUT);

  lcd.setCursor(0, 0);
  printPadded("System Booting");
  lcd.setCursor(0, 1);
  printPadded("Please wait");

  startupAnimation();

  lcd.clear();
}

void loop() {
  int sensorValue = analogRead(tempPin);

  float voltage = sensorValue * (5.0 / 1023.0);
  float temperature = (voltage - 0.5) * 100.0;

  clearStatusLeds();

  const char* state;

  if (temperature < 16) {
    digitalWrite(ledCold, HIGH);
    state = "Cold";
    setRingColor(3, 0, 0, 255);
  }
  else if (temperature < 26) {
    digitalWrite(ledNormal, HIGH);
    state = "Normal";
    setRingColor(6, 0, 255, 0);
  }
  else if (temperature < 33) {
    digitalWrite(ledWarm, HIGH);
    state = "Warm";
    setRingColor(9, 255, 150, 0);
  }
  else {
    digitalWrite(ledHot, HIGH);
    state = "Hot";
    setRingColor(12, 255, 0, 0);
  }

  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature, 1);
  lcd.print((char)223);
  lcd.print("C     ");

  lcd.setCursor(0, 1);
  lcd.print("State: ");
  lcd.print(state);
  lcd.print("       ");

  Serial.print("ADC: ");
  Serial.print(sensorValue);
  Serial.print(" | Voltage: ");
  Serial.print(voltage);
  Serial.print(" V | Temperature: ");
  Serial.print(temperature);
  Serial.print(" C | State: ");
  Serial.println(state);

  delay(1000);
}
