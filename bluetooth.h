#include <SoftwareSerial.h>

#define RxD 2
#define TxD 3


SoftwareSerial BTSerial(RxD, TxD);
bool BT_initialized = false;

void BT_init() {
  BTSerial.begin(38400);
  BT_initialized = true;
}

String BT_send(String command) {
  byte input_data;
  char input_char;
  String response;
  
  if (!BT_initialized) {
    return "";
  }

  BTSerial.print(command + "\n\r");

  delay(1000);

  while (BTSerial.available() > 0) {
    input_data = BTSerial.read();
    input_char = char(input_data);
    response = response + input_char;
  }
  
  Serial.println(response);
  return response;
}
