const int SENSOR_PIN = 2;     // OUT của cảm biến âm thanh (hoặc nút nhấn trong Proteus)
const int OUTPUT_PIN = 12;    // relay (mạch thật) hoặc LED (Proteus)
bool outputState = false;     // Trạng thái relay hoặc LED

void setup() {
  pinMode(SENSOR_PIN, INPUT);
  pinMode(OUTPUT_PIN, OUTPUT);
  digitalWrite(OUTPUT_PIN, LOW);
  Serial.begin(9600); // debug
}

void loop() {
  int sensorVal = digitalRead(SENSOR_PIN);
  Serial.println(sensorVal); // in giá trị cảm biến

  if (sensorVal == HIGH) {
    // đảo trạng thái đầu ra (bật/tắt)
    outputState = !outputState;
    digitalWrite(OUTPUT_PIN, outputState ? HIGH : LOW);
    Serial.println(outputState ? "ON" : "OFF");

    delay(500); // chờ debounce

    // đợi đến khi sensor trở về LOW mới tiếp tục
    while (digitalRead(SENSOR_PIN) == HIGH) {
      delay(10);
    }
  }

  delay(50); // delay ngắn chống spam
}