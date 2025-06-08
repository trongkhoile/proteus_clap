const int SENSOR_PIN = 2;     // OUT của cảm biến âm thanh (hoặc nút nhấn trong Proteus)
const int OUTPUT_PIN = 12;    // relay (mạch thật) hoặc LED (Proteus)
bool outputState = false;     // Trạng thái relay hoặc LED

void setup() {
  pinMode(SENSOR_PIN, INPUT);           // Cài đặt SENSOR_PIN là đầu vào
  pinMode(OUTPUT_PIN, OUTPUT);          // Cài đặt OUTPUT_PIN là đầu ra
  digitalWrite(OUTPUT_PIN, LOW);        // Khởi đầu với trạng thái tắt
  Serial.begin(9600);                   // Bắt đầu Serial để debug với tốc độ 9600 baud
}

void loop() {
  int sensorVal = digitalRead(SENSOR_PIN);  // Đọc giá trị tại SENSOR_PIN
  Serial.println(sensorVal);                // In giá trị cảm biến ra Serial Monitor

  if (sensorVal == HIGH) {
    // đảo trạng thái đầu ra (bật/tắt)
    outputState = !outputState;
    digitalWrite(OUTPUT_PIN, outputState ? HIGH : LOW);
    Serial.println(outputState ? "ON" : "OFF");

    delay(500); // chờ debounce

    // đợi đến khi sensor trở về LOW mới tiếp tục
    int timeout = 1000; // Giới hạn thời gian đợi cảm biến về LOW
    int count = 0;
    while (digitalRead(SENSOR_PIN) == HIGH && count < timeout) {
      delay(10);
      count += 10;
    }
  }

  delay(50); // delay ngắn chống spam
}
