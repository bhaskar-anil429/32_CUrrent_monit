///////////////// test code for current monitoring/////////////////////
//Include Wire I2C Library
#include  <Wire.h>
int address = 42; // I2C address

void setup()
{
 
  Serial.begin(9600);  // Create Serial Object (9600 Baud)
  Wire.begin();
}

///////////////////////////////////////////////////////////////////////////
int read_current(int channel_number)
{
   if ( 0 < channel_number &&  channel_number < 13)
  {
    for ( byte i = channel_number; i<= channel_number; i++)
    { 
    Wire.beginTransmission(address); // Start communication
    Wire.write(146); // Command header 
    Wire.write(106); // Command header 
    Wire.write(1);  // Command 1
    Wire.write(i);  // Start Channel no 
    Wire.write(i);  // End Channel no 
    Wire.write(0); 
    Wire.write(0); 
    Wire.write((146 + 106 + 1 + i + i + 0 + 0) & 255); // CheckSum
    Wire.endTransmission(); // Complete Transmission
    Wire.requestFrom(address, 3); 
    unsigned long MSB1 = Wire.read();
     MSB1= MSB1*65536;
    unsigned long MSB = Wire.read();
    MSB=MSB*256;
    unsigned long LSB = Wire.read();
   MSB1=MSB1+MSB+LSB;
    double current = ((double)MSB1)/(double)1000; 
    Serial.print("new updated current values For channel   "); 
    Serial.print(channel_number);
    Serial.print("  ");
    Serial.print(current,3);
    Serial.print("  ");
    Serial.print("Amp"); 
    Serial.print("\t");
    Serial.print("\n");
//    Serial.print("I am here at 42"); 
    Wire.endTransmission(); // Complete Transmission
    }
}

//////////////////////////////////////
  if ( 12 < channel_number && channel_number < 25)
  {
    for ( byte i = channel_number; i<= channel_number; i++)
    { 
      i = channel_number - 12;
    Wire.beginTransmission(43); // Start communication
    Wire.write(146); // Command header 
    Wire.write(106); // Command header 
    Wire.write(1);  // Command 1
    Wire.write(i);  // Start Channel no 
    Wire.write(i);  // End Channel no 
    Wire.write(0); 
    Wire.write(0); 
    Wire.write((146 + 106 + 1 + i + i + 0 + 0) & 255); // CheckSum
    Wire.endTransmission(); // Complete Transmission
    Wire.requestFrom(43, 3); 
    unsigned long MSB1 = Wire.read();
     MSB1= MSB1*65536;
    unsigned long MSB = Wire.read();
    MSB=MSB*256;
    unsigned long LSB = Wire.read();
   MSB1=MSB1+MSB+LSB;
    double current = ((double)MSB1)/(double)1000; 
     Serial.print("new updates current values For channel   "); 
    Serial.print(channel_number);
    Serial.print("  ");
    Serial.print(current,3);
    Serial.print("  ");
    Serial.print("Amp"); 
    Serial.print("\t");
    Serial.print("\n");
    Wire.endTransmission(); // Complete Transmission
//    Serial.print("I am here at 43"); 
    }
  }
//////////////////////////////////////////////////////////
  if ( 24 < channel_number && channel_number < 37)
  {
    for ( byte i = channel_number; i<= channel_number; i++)
    { 
      i = channel_number - 24;
     
    Wire.beginTransmission(44); // Start communication
    Wire.write(146); // Command header 
    Wire.write(106); // Command header 
    Wire.write(1);  // Command 1
    Wire.write(i);  // Start Channel no 
    Wire.write(i);  // End Channel no 
    Wire.write(0); 
    Wire.write(0); 
    Wire.write((146 + 106 + 1 + i + i + 0 + 0) & 255); // CheckSum
    Wire.endTransmission(); // Complete Transmission
    Wire.requestFrom(44, 3); 
    unsigned long MSB1 = Wire.read();
     MSB1= MSB1*65536;
    unsigned long MSB = Wire.read();
    MSB=MSB*256;
    unsigned long LSB = Wire.read();
   MSB1=MSB1+MSB+LSB;
    double current = ((double)MSB1)/(double)1000; 
    Serial.print("new updates current values For channel   "); 
    Serial.print(channel_number);
    Serial.print("  ");
    
    Serial.print(current,3);
    Serial.print("  ");
    Serial.print("Amp"); 
    Serial.print("\t");
    Serial.print("\n");
   // delay(500);
    Wire.endTransmission(); // Complete Transmission
//    Serial.print("I am here at 44"); 
   
    }
}
//////////////////////////////////////////////////////////
}
void loop()
{
  ///////////////////////// enter the channel number///////////////
  read_current(1);
     delay(3000);
}
