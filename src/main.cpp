#include <main.hpp>

void setup() {
  Serial.begin(9600);
  Wire.begin();
  if (!tcs.attach(Wire))
    Serial.println("ERROR: TCS34725 NOT FOUND !!!");
  tcs.integrationTime(2.4); // ms
  tcs.gain(TCS34725::Gain::X01);
  ledcSetup(0, 5000, 12);
  ledcAttachPin(PWM_PIN_L_A, 0);
  ledcSetup(1, 5000, 12);
  ledcAttachPin(PWM_PIN_L_B, 1);
  ledcSetup(2, 5000, 12);
  ledcAttachPin(PWM_PIN_R_A, 2);
  ledcSetup(3, 5000, 12);
  ledcAttachPin(PWM_PIN_R_B, 3);
  pinMode(7, INPUT_PULLUP);
  pinMode(PWM_PIN_L_A, OUTPUT);
  pinMode(PWM_PIN_L_B, OUTPUT);
  pinMode(PWM_PIN_R_A, OUTPUT);
  pinMode(PWM_PIN_R_B, OUTPUT);
  digitalWrite(PWM_PIN_L_A, LOW);
  digitalWrite(PWM_PIN_L_B, LOW);
  digitalWrite(PWM_PIN_R_A, LOW);
  digitalWrite(PWM_PIN_R_B, LOW);
  pinMode(W_LED, OUTPUT);
  // digitalWrite(W_LED, LOW);
  digitalWrite(W_LED, HIGH);
  pinMode(IR_LED, OUTPUT);
  // digitalWrite(IR_LED, LOW); 
  digitalWrite(IR_LED, HIGH);
}

void loop() {
  if (tcs.available()) {
    TCS34725::Color color = tcs.color();
    colorVals.temp = tcs.colorTemperature();
    colorVals.lux = tcs.lux();
    colorVals.r = color.r;
    colorVals.g = color.g;
    colorVals.b = color.b;
    // printColor();
  }
  getError();
  calculateOutput();
  // Serial.println(irArray,BIN);
  // print5digitBIN(0);


  // printIR();
}
