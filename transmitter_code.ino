// 8 Channel Transmitter (No Trim) | 8 Kanal Verici (Trim Yok)
// Input pin A5
//by peter 
  #include <SPI.h>
  #include <nRF24L01.h>
  #include <RF24.h>
  const uint64_t pipeOut = 000322;         // NOTE: The same as in the receiver 000322 
  RF24 radio(9, 10);                       // select CE,CSN pin

  struct Signal {
  byte throttle;
  byte pitch;
  byte roll;
  byte yaw;
  byte aux1;
  byte aux2;
  byte aux3;
  byte aux4;
  
};
  Signal data;
  void ResetData() 
{
  data.throttle = 0;
  data.pitch = 127;
  data.roll = 127;
  data.yaw = 127;
  data.aux1 = 0;                       // Signal lost position 
  data.aux2 = 0;
  data.aux3 = 0;
  data.aux4 = 0;
}
  void setup()
{
                                       //Configure the NRF24 module  | NRF24 modül konfigürasyonu
  radio.begin();
  radio.openWritingPipe(pipeOut);
  radio.setChannel(100);
  radio.setAutoAck(false);
  radio.setDataRate(RF24_250KBPS);    // The lowest data rate value for more stable communication  
  radio.setPALevel(RF24_PA_MAX);      // Output power is set for maximum 
  radio.stopListening();              // Start the radio comunication for Transmitter 
  ResetData();
 
}
                                      // Joystick center and its borders 
  int Border_Map(int val, int lower, int middle, int upper, bool reverse)
{
  val = constrain(val, lower, upper);
  if ( val < middle )
  val = map(val, lower, middle, 0, 128);
  else
  val = map(val, middle, upper, 128, 255);
  return ( reverse ? 255 - val : val );
}
  void loop()
{
                                     // Control Stick Calibration for channels  | 

  // data.roll = Border_Map( analogRead(A0), 0, 512, 1023, true );        // "true" or "false" for signal direction | "true" veya "false" sinyal yönünü belirler
  // data.pitch = Border_Map( analogRead(A2), 0, 512, 1023, true );      
    data.throttle = Border_Map( analogRead(A7),570, 800, 1023, false );  // For Single side ESC | Tek yönlü ESC için
 // Read and map the throttle input from the joystick connected to A7
  // data.throttle = Border_Map(analogRead(A7), 0, 512, 1023, false);  // For Bidirectional ESC | Çift yönlü ESC için
  data.yaw = Border_Map( analogRead(A0), 0, 512, 1023, true );        
  //data.aux1 = Border_Map( analogRead(A7), 0, 512, 1023, true );        // "true" or "false" for change signal direction | "true" veya "false" sinyal yönünü değiştirir.
  // data.aux2 = Border_Map( analogRead(A5), 0, 512, 1023, true );        // "true" or "false" for change signal direction | "true" veya "false" sinyal yönünü değiştirir.
  // data.aux3 = digitalRead(7);
  // data.aux4 = digitalRead(8);

  radio.write(&data, sizeof(Signal));  
}