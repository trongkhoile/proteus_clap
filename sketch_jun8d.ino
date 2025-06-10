const int testPin = 12;  
const int relay = 2;      
bool outputState = false; 
bool lastState = LOW; // Lưu trạng thái trước đó của TestPin

void setup() {
  pinMode(testPin, INPUT);
  pinMode(relay, OUTPUT);
  digitalWrite(relay, LOW);
  Serial.begin(9600);
}

void loop() {
  int sensorVal = digitalRead(testPin);
  Serial.println(sensorVal);

  // Chỉ kích hoạt khi có thay đổi từ LOW -> HIGH
  if (sensorVal == HIGH && lastState == LOW || sensorVal == LOW && lastState == HIGH) { 
    outputState = !outputState;
    digitalWrite(relay, outputState ? HIGH : LOW);
    Serial.println(outputState ? "ON" : "OFF");
  }
  
  lastState = sensorVal; // Cập nhật trạng thái trước đó
  delay(50); // Chống spam tín hiệu
}
