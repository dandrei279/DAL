  
String response;

void ELM_init() {
  BT_send("ATZ");
  
  delay(2000);
  Serial.println("recv: \"" + BT_read() + "\"");
  
  BT_send("atl1");  
  
  delay(2000);
  Serial.println("recv: \"" + BT_read() + "\"");
  BT_send("ath0");
  
  delay(2000);
  Serial.println("recv: \"" + BT_read() + "\"");
  BT_send("ATSP0");

  delay(2000);
  Serial.println("recv: \"" + BT_read() + "\"");
}

int convert_RPM(String value) {
  int A, B;
  A = hex_to_dec(value.substring(0, 2));
  B = hex_to_dec(value.substring(3));
  
  return (256 * A + B) / 4;
}

int get_RPM() {
  BT_send("010C");
  
  delay(1000);
  response = BT_read();
  if (response == "") {
    return -1;
  }
  return convert_RPM(response.substring(12, 17));
}

int get_speed() {
  BT_send("010D");
  
  delay(1000);
  response = BT_read();
  if (response == "") {
    return -1;
  }
  return hex_to_dec(response.substring(12, 14));
}
