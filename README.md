# Dynamic Ambient Lighting

This device is used to create a dynamic ambient inside the car.
It connects to the ECU and retrieves the RPM and set the interior light according to the reading.

### Setting up the HC-05

  __STEP 0:__ Enter the AT mode<br>
  __STEP 1:__ Reset the module to factory settings: `AT+ORGL`<br>
  __STEP 2:__ Set master mode: `AT+ROLE=1`<br>
  __STEP 3:__ Set inquire parameters: `AT+INQM=1,9,48`<br>
  __STEP 4:__ Search for device: `AT+INQ`; Note the MAC address of your ELM327<br>
  __STEP 5:__ Set HC-05 to connect only to the ELM327: `AT_CMODE=0`<br>
  __STEP 6:__ Bind to the address: `AT+BIND=1234,56,ABCDEF`; Replace with the MAC address from ___STEP 4___<br>
  __STEP 7:__ Pair to the address: `AT+PAIR=1234,56,ABCDEF,20`; Replace with the MAC address from ___STEP 4___; Last parameter is the timeout<br>
  __STEP 8:__ Pair to the address: `AT+LINK=1234,56,ABCDEF`; Replace with the MAC address from ___STEP 4___<br>

#### Useful links:
[Demo](https://youtu.be/XGqhdCEtTjM)<br>
[Complete presentation](https://youtu.be/HCErRKVjjb4)<br>
[HC-05 AT commands](https://s3-sa-east-1.amazonaws.com/robocore-lojavirtual/709/HC-05_ATCommandSet.pdf)<br>
