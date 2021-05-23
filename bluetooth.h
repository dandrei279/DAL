/*
 * Control the bluetooth connection
 */

#include <SoftwareSerial.h>

#define RxD 2
#define TxD 3


SoftwareSerial BTSerial(RxD, TxD);
bool BT_initialized = false;

void BT_init() {
  if (BT_initialized)
    return;

  BTSerial.begin(38400);
  BT_initialized = true;
  Serial.println("Bluetooth initialized");
}

void BT_send(String command) {
  
  if (!BT_initialized) {
    return "";
  }
  for (char c : command) {
    BTSerial.write((byte) c);
  }
  BTSerial.write((byte)'\r');
  BTSerial.write((byte)'\n');
}

String BT_read() {
  byte input_data;
  char input_char;
  String response = "";
  
  while (BTSerial.available() > 0) {
    input_data = BTSerial.read();
    input_char = char(input_data);
    response = response + input_char;
  }
  return response;
}
