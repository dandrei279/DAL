
String response;

void ELM_init() {
  BT_send("ATZ");
  BT_send("atl1");  
  BT_send("ath1");
  BT_send("ATSP0");
}

int get_RPM() {
  response = BT_send("010C");
  if (response == "") {
    return -1;
  }
//  Serial.println(response);
  return 0;
}
