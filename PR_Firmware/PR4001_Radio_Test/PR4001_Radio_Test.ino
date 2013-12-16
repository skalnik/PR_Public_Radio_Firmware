#include <PR_Header.h>
#include <Wire.h>

int resetPin = 2;
int SDIO = A4;
int SCLK = A5;

Public_Radio radio(resetPin, SDIO, SCLK);
int channel = 971;
int volume = 10;
char rdsBuffer[10];

void setup()
{
  Serial.begin(9600);
  Serial.println("RADIO TEST!!!");
  Serial.println("===========================");  
  Serial.println("+ -     Volume (max 15)");
  Serial.println("Send me a command letter.");
  

  radio.powerOn();
  radio.setVolume(volume);
  radio.setChannel(channel);
}

void loop()
{
  if (Serial.available())
  {
    char ch = Serial.read();
    if (ch == '+')
    {
      volume ++;
      if (volume > 15) volume = 15;
      radio.setVolume(volume);
      displayInfo();
    }
    else if (ch == '-') 
    {
      volume --;
      if (volume < 0) volume = 0;
      radio.setVolume(volume);
      displayInfo();
    } 
  }
}

void displayInfo()
{
   Serial.print("Channel:"); Serial.print(channel); 
   Serial.print(" Volume:"); Serial.println(volume); 
}
