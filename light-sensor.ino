int data0=0;

void setup() {
Serial.begin(9600);
}

void loop() {
data0=analogRead(A1);
Serial.print(data0);
Serial.println();
delay(500);
}