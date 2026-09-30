/*
code source 3_All of the led effect functions

Author 1: DOAN HAI PHONG (TEDDY)
Author 2: ChatGPT =)))
Origin: Vietnamese
Date of finish: 20 July 2026
OPEN SOURCE, FREE FOR COMMUNITY

*/


#include <Arduino.h>
#include "Ledeffect.h"

//setting up the Layer pattern bit orders rule
byte layerTest[8] = {
  0b00000001, //i=0 layer 8 (top layer)
  0b00000010, //i=1 layer 1 (first bottom layer)
  0b00000100, //i=2 layer 2 (second layer)
  0b00001000, //i=3 layer 3 (third layer)
  0b00010000, //i=4 layer 4
  0b00100000, //i=5 layer 5
  0b01000000, //i=6 layer 6
  0b10000000  //i=7 layer 7
};


void writeColumns(byte columns[8]) //column controller
 {
  digitalWrite(LATCH_COL, LOW);

  for (int i = 0; i < 8; i++) {
    shiftOut(DATA_COL, CLOCK_COL, MSBFIRST, columns[i]);
  }

  digitalWrite(LATCH_COL, HIGH);
}

void writeLayer(byte layerData) //layer controller
 {
  digitalWrite(LATCH_LAY, LOW);
  shiftOut(DATA_LAY, CLOCK_LAY, MSBFIRST, layerData);
  digitalWrite(LATCH_LAY, HIGH);
}


void clearCube() //column and layer clear controller
{
  byte columns[8] = {
    0b00000000, //column[0] shift register 8
    0b00000000, //column[1] shift register 7
    0b00000000, //column[2] shift register 6
    0b00000000, //column[3] shift register 5
    0b00000000, //column[4] shift register 4
    0b00000000, //column[5] shift register 3
    0b00000000, //column[6] shift register 2
    0b00000000, //column[7] shift register 1
  };

  // Important: turn layers off first to prevent ghosting
  writeLayer(0x00);
  writeColumns(columns);
}


void LEDeffect1_numberdisplay_1 ()
{


 
  
  byte columns1A[8] = {
    0b00000000, //column[0] shift register 8
    0b00000010, //column[1] shift register 7
    0b00000010, //column[2] shift register 6
    0b00000010, //column[3] shift register 5
    0b00000010, //column[4] shift register 4
    0b00000010, //column[5] shift register 3
    0b00000010, //column[6] shift register 2
    0b00000000, //column[7] shift register 1
  };

writeColumns(columns1A);
writeLayer(layerTest[1]);
delayMicroseconds(1000); //delay 1ms
writeLayer(layerTest[2]);
delayMicroseconds(1000); //delay 1ms

  byte columns1B[8] = {
    0b00000000, //column[0] shift register 8
    0b00000000, //column[1] shift register 7
    0b00000000, //column[2] shift register 6
    0b00000010, //column[3] shift register 5
    0b00000010, //column[4] shift register 4
    0b00000000, //column[5] shift register 3
    0b00000000, //column[6] shift register 2
    0b00000000, //column[7] shift register 1
  };

writeColumns(columns1B);
writeLayer(layerTest[3]); //delay 1ms
delayMicroseconds(1000);
writeLayer(layerTest[4]); //delay 1ms
delayMicroseconds(1000);

  byte columns1C[8] = {
    0b00000000, //column[0] shift register 8
    0b00000000, //column[1] shift register 7
    0b00000000, //column[2] shift register 6
    0b00000010, //column[3] shift register 5
    0b00000010, //column[4] shift register 4
    0b00000010, //column[5] shift register 3
    0b00000010, //column[6] shift register 2
    0b00000000, //column[7] shift register 1
  };


writeColumns(columns1C);
writeLayer(layerTest[5]); //delay 1ms
delayMicroseconds(1000);
writeLayer(layerTest[6]); //delay 1ms
delayMicroseconds(1000);

 byte columns1D[8] = {
    0b00000000, //column[0] shift register 8
    0b00000000, //column[1] shift register 7
    0b00000000, //column[2] shift register 6
    0b00000010, //column[3] shift register 5
    0b00000010, //column[4] shift register 4
    0b00000010, //column[5] shift register 3
    0b00000000, //column[6] shift register 2
    0b00000000, //column[7] shift register 1
  };
writeColumns(columns1D);
writeLayer(layerTest[7]); //delay 1ms
delayMicroseconds(1000);
writeColumns(columns1B);
writeLayer(layerTest[0]); //delay 1ms
delayMicroseconds(1000);

}





void LEDeffect2_numberdisplay_2 ()
{


  
  
  byte columns2A[8] = {
    0b00000000, //column[0] shift register 8
    0b00000010, //column[1] shift register 7
    0b00000010, //column[2] shift register 6
    0b00000010, //column[3] shift register 5
    0b00000010, //column[4] shift register 4
    0b00000010, //column[5] shift register 3
    0b00000010, //column[6] shift register 2
    0b00000000, //column[7] shift register 1
  };

writeColumns(columns2A);
writeLayer(layerTest[1]);
delayMicroseconds(1000); //delay 1ms
writeLayer(layerTest[2]);
delayMicroseconds(1000); //delay 1ms

byte columns2B[8] = {
    0b00000000, //column[0] shift register 8
    0b00000000, //column[1] shift register 7
    0b00000000, //column[2] shift register 6
    0b00000000, //column[3] shift register 5
    0b00000010, //column[4] shift register 4
    0b00000010, //column[5] shift register 3
    0b00000000, //column[6] shift register 2
    0b00000000, //column[7] shift register 1
  };
writeColumns(columns2B);
writeLayer(layerTest[3]);
delayMicroseconds(1000); //delay 1ms

byte columns2C[8] = {
    0b00000000, //column[0] shift register 8
    0b00000000, //column[1] shift register 7
    0b00000000, //column[2] shift register 6
    0b00000010, //column[3] shift register 5
    0b00000010, //column[4] shift register 4
    0b00000000, //column[5] shift register 3
    0b00000000, //column[6] shift register 2
    0b00000000, //column[7] shift register 1
  };
writeColumns(columns2C);
writeLayer(layerTest[4]);
delayMicroseconds(1000); //delay 1ms

byte columns2D[8] = {
    0b00000000, //column[0] shift register 8
    0b00000000, //column[1] shift register 7
    0b00000010, //column[2] shift register 6
    0b00000010, //column[3] shift register 5
    0b00000000, //column[4] shift register 4
    0b00000000, //column[5] shift register 3
    0b00000000, //column[6] shift register 2
    0b00000000, //column[7] shift register 1
  };
writeColumns(columns2D);
writeLayer(layerTest[5]);
delayMicroseconds(1000); //delay 1ms

byte columns2E[8] = {
    0b00000000, //column[0] shift register 8
    0b00000010, //column[1] shift register 7
    0b00000010, //column[2] shift register 6
    0b00000000, //column[3] shift register 5
    0b00000000, //column[4] shift register 4
    0b00000010, //column[5] shift register 3
    0b00000010, //column[6] shift register 2
    0b00000000, //column[7] shift register 1
  };
writeColumns(columns2E);
writeLayer(layerTest[6]);
delayMicroseconds(1000); //delay 1ms

byte columns2F[8] = {
    0b00000000, //column[0] shift register 8
    0b00000010, //column[1] shift register 7
    0b00000010, //column[2] shift register 6
    0b00000010, //column[3] shift register 5
    0b00000010, //column[4] shift register 4
    0b00000010, //column[5] shift register 3
    0b00000010, //column[6] shift register 2
    0b00000000, //column[7] shift register 1
  };
writeColumns(columns2F);
writeLayer(layerTest[7]);
delayMicroseconds(1000); //delay 1ms

byte columns2G[8] = {
    0b00000000, //column[0] shift register 8
    0b00000000, //column[1] shift register 7
    0b00000010, //column[2] shift register 6
    0b00000010, //column[3] shift register 5
    0b00000010, //column[4] shift register 4
    0b00000010, //column[5] shift register 3
    0b00000000, //column[6] shift register 2
    0b00000000, //column[7] shift register 1
  };
writeColumns(columns2G);
writeLayer(layerTest[0]);
delayMicroseconds(1000); //delay 1ms


}




void LEDeffect3_numberdisplay_3 ()
{


  
  
  byte columns3A[8] = {
    0b00000000, //column[0] shift register 8
    0b00000000, //column[1] shift register 7
    0b00000010, //column[2] shift register 6
    0b00000010, //column[3] shift register 5
    0b00000010, //column[4] shift register 4
    0b00000010, //column[5] shift register 3
    0b00000000, //column[6] shift register 2
    0b00000000, //column[7] shift register 1
  };

writeColumns(columns3A);
writeLayer(layerTest[1]);
delayMicroseconds(1000); //delay 1ms

 byte columns3B[8] = {
    0b00000000, //column[0] shift register 8
    0b00000010, //column[1] shift register 7
    0b00000010, //column[2] shift register 6
    0b00000010, //column[3] shift register 5
    0b00000010, //column[4] shift register 4
    0b00000010, //column[5] shift register 3
    0b00000010, //column[6] shift register 2
    0b00000000, //column[7] shift register 1
  };
writeColumns(columns3B);
writeLayer(layerTest[2]);
delayMicroseconds(1000); //delay 1ms





byte columns3C[8] = {
    0b00000000, //column[0] shift register 8
    0b00000010, //column[1] shift register 7
    0b00000010, //column[2] shift register 6
    0b00000000, //column[3] shift register 5
    0b00000000, //column[4] shift register 4
    0b00000010, //column[5] shift register 3
    0b00000010, //column[6] shift register 2
    0b00000000, //column[7] shift register 1
  };
writeColumns(columns3C);
writeLayer(layerTest[3]);
delayMicroseconds(1000); //delay 1ms

byte columns3D[8] = {
    0b00000000, //column[0] shift register 8
    0b00000000, //column[1] shift register 7
    0b00000010, //column[2] shift register 6
    0b00000010, //column[3] shift register 5
    0b00000010, //column[4] shift register 4
    0b00000000, //column[5] shift register 3
    0b00000000, //column[6] shift register 2
    0b00000000, //column[7] shift register 1
  };
writeColumns(columns3D);
writeLayer(layerTest[4]);
delayMicroseconds(1000); //delay 1ms
writeLayer(layerTest[5]);
delayMicroseconds(1000); //delay 1ms

writeColumns(columns3C);
writeLayer(layerTest[6]);
delayMicroseconds(1000); //delay 1ms
writeColumns(columns3B);
writeLayer(layerTest[7]);
delayMicroseconds(1000); //delay 1ms
writeColumns(columns3A);
writeLayer(layerTest[0]);
delayMicroseconds(1000); //delay 1ms

}



void LEDeffect4_numberdisplay_4 ()
{


  
  
  byte columns4A[8] = {
    0b00000000, //column[0] shift register 8
    0b00000000, //column[1] shift register 7
    0b00000010, //column[2] shift register 6
    0b00000010, //column[3] shift register 5
    0b00000000, //column[4] shift register 4
    0b00000000, //column[5] shift register 3
    0b00000000, //column[6] shift register 2
    0b00000000, //column[7] shift register 1
  };

writeColumns(columns4A);
writeLayer(layerTest[1]);
delayMicroseconds(1000); //delay 1ms
writeLayer(layerTest[2]);
delayMicroseconds(1000); //delay 1ms
writeLayer(layerTest[3]);
delayMicroseconds(1000); //delay 1ms

  byte columns4B[8] = {
    0b00000000, //column[0] shift register 8
    0b00000010, //column[1] shift register 7
    0b00000010, //column[2] shift register 6
    0b00000010, //column[3] shift register 5
    0b00000010, //column[4] shift register 4
    0b00000010, //column[5] shift register 3
    0b00000010, //column[6] shift register 2
    0b00000000, //column[7] shift register 1
  };

writeColumns(columns4B);
writeLayer(layerTest[4]);
delayMicroseconds(1000); //delay 1ms
writeLayer(layerTest[5]);
delayMicroseconds(1000); //delay 1ms

  byte columns4C[8] = {
    0b00000000, //column[0] shift register 8
    0b00000000, //column[1] shift register 7
    0b00000010, //column[2] shift register 6
    0b00000010, //column[3] shift register 5
    0b00000000, //column[4] shift register 4
    0b00000010, //column[5] shift register 3
    0b00000000, //column[6] shift register 2
    0b00000000, //column[7] shift register 1
  };
writeColumns(columns4C);
writeLayer(layerTest[6]);
delayMicroseconds(1000); //delay 1ms

  byte columns4D[8] = {
    0b00000000, //column[0] shift register 8
    0b00000000, //column[1] shift register 7
    0b00000010, //column[2] shift register 6
    0b00000010, //column[3] shift register 5
    0b00000010, //column[4] shift register 4
    0b00000000, //column[5] shift register 3
    0b00000000, //column[6] shift register 2
    0b00000000, //column[7] shift register 1
  };
writeColumns(columns4D);
writeLayer(layerTest[7]);
delayMicroseconds(1000); //delay 1ms

  byte columns4E[8] = {
    0b00000000, //column[0] shift register 8
    0b00000000, //column[1] shift register 7
    0b00000010, //column[2] shift register 6
    0b00000010, //column[3] shift register 5
    0b00000000, //column[4] shift register 4
    0b00000000, //column[5] shift register 3
    0b00000000, //column[6] shift register 2
    0b00000000, //column[7] shift register 1
  };
writeColumns(columns4E);
writeLayer(layerTest[0]);
delayMicroseconds(1000); //delay 1ms


}








void LEDeffect5_numberdisplay_5 ()
{
  
  byte columns5A[8] = {
    0b00000000, //column[0] shift register 8
    0b00000000, //column[1] shift register 7
    0b00000010, //column[2] shift register 6
    0b00000010, //column[3] shift register 5
    0b00000010, //column[4] shift register 4
    0b00000010, //column[5] shift register 3
    0b00000000, //column[6] shift register 2
    0b00000000, //column[7] shift register 1
  };


writeColumns(columns5A);
writeLayer(layerTest[1]);
delayMicroseconds(1000); //delay 1ms

  byte columns5B[8] = {
    0b00000000, //column[0] shift register 8
    0b00000010, //column[1] shift register 7
    0b00000010, //column[2] shift register 6
    0b00000010, //column[3] shift register 5
    0b00000010, //column[4] shift register 4
    0b00000010, //column[5] shift register 3
    0b00000010, //column[6] shift register 2
    0b00000000, //column[7] shift register 1
  };

writeColumns(columns5B);
writeLayer(layerTest[2]);
delayMicroseconds(1000); //delay 1ms

  byte columns5C[8] = {
    0b00000000, //column[0] shift register 8
    0b00000010, //column[1] shift register 7
    0b00000010, //column[2] shift register 6
    0b00000000, //column[3] shift register 5
    0b00000000, //column[4] shift register 4
    0b00000010, //column[5] shift register 3
    0b00000010, //column[6] shift register 2
    0b00000000, //column[7] shift register 1
  };

writeColumns(columns5C);
writeLayer(layerTest[3]);
delayMicroseconds(1000); //delay 1ms

  byte columns5D[8] = {
    0b00000000, //column[0] shift register 8
    0b00000010, //column[1] shift register 7
    0b00000010, //column[2] shift register 6
    0b00000010, //column[3] shift register 5
    0b00000000, //column[4] shift register 4
    0b00000000, //column[5] shift register 3
    0b00000000, //column[6] shift register 2
    0b00000000, //column[7] shift register 1
  };

writeColumns(columns5D);
writeLayer(layerTest[4]);
delayMicroseconds(1000); //delay 1ms

  byte columns5E[8] = {
    0b00000000, //column[0] shift register 8
    0b00000010, //column[1] shift register 7
    0b00000010, //column[2] shift register 6
    0b00000010, //column[3] shift register 5
    0b00000010, //column[4] shift register 4
    0b00000010, //column[5] shift register 3
    0b00000010, //column[6] shift register 2
    0b00000000, //column[7] shift register 1
  };

writeColumns(columns5E);
writeLayer(layerTest[5]);
delayMicroseconds(1000); //delay 1ms

  byte columns5F[8] = {
    0b00000000, //column[0] shift register 8
    0b00000000, //column[1] shift register 7
    0b00000000, //column[2] shift register 6
    0b00000000, //column[3] shift register 5
    0b00000000, //column[4] shift register 4
    0b00000010, //column[5] shift register 3
    0b00000010, //column[6] shift register 2
    0b00000000, //column[7] shift register 1
  };

writeColumns(columns5F);
writeLayer(layerTest[6]);
delayMicroseconds(1000); //delay 1ms


writeColumns(columns5E);
writeLayer(layerTest[7]);
delayMicroseconds(1000); //delay 1ms
writeLayer(layerTest[0]);
delayMicroseconds(1000); //delay 1ms

}







void LEDeffect6_numberdisplay_6 ()
{
  
  byte columns6A[8] = {
    0b00000000, //column[0] shift register 8
    0b00000000, //column[1] shift register 7
    0b00000010, //column[2] shift register 6
    0b00000010, //column[3] shift register 5
    0b00000010, //column[4] shift register 4
    0b00000010, //column[5] shift register 3
    0b00000000, //column[6] shift register 2
    0b00000000, //column[7] shift register 1
  };

writeColumns(columns6A);
writeLayer(layerTest[1]);
delayMicroseconds(1000); //delay 1ms

  byte columns6B[8] = {
    0b00000000, //column[0] shift register 8
    0b00000010, //column[1] shift register 7
    0b00000010, //column[2] shift register 6
    0b00000010, //column[3] shift register 5
    0b00000010, //column[4] shift register 4
    0b00000010, //column[5] shift register 3
    0b00000010, //column[6] shift register 2
    0b00000000, //column[7] shift register 1
  };

writeColumns(columns6B);
writeLayer(layerTest[2]);
delayMicroseconds(1000); //delay 1ms


  byte columns6C[8] = {
    0b00000000, //column[0] shift register 8
    0b00000010, //column[1] shift register 7
    0b00000010, //column[2] shift register 6
    0b00000000, //column[3] shift register 5
    0b00000000, //column[4] shift register 4
    0b00000010, //column[5] shift register 3
    0b00000010, //column[6] shift register 2
    0b00000000, //column[7] shift register 1
  };

writeColumns(columns6C);
writeLayer(layerTest[3]);
delayMicroseconds(1000); //delay 1ms

writeColumns(columns6B);
writeLayer(layerTest[4]);
delayMicroseconds(1000); //delay 1ms

  byte columns6D[8] = {
    0b00000000, //column[0] shift register 8
    0b00000000, //column[1] shift register 7
    0b00000010, //column[2] shift register 6
    0b00000010, //column[3] shift register 5
    0b00000010, //column[4] shift register 4
    0b00000010, //column[5] shift register 3
    0b00000010, //column[6] shift register 2
    0b00000000, //column[7] shift register 1
  };

writeColumns(columns6D);
writeLayer(layerTest[5]);
delayMicroseconds(1000); //delay 1ms

  byte columns6E[8] = {
    0b00000000, //column[0] shift register 8
    0b00000000, //column[1] shift register 7
    0b00000000, //column[2] shift register 6
    0b00000000, //column[3] shift register 5
    0b00000000, //column[4] shift register 4
    0b00000010, //column[5] shift register 3
    0b00000010, //column[6] shift register 2
    0b00000000, //column[7] shift register 1
  };

writeColumns(columns6E);
writeLayer(layerTest[6]);
delayMicroseconds(1000); //delay 1ms

  byte columns6F[8] = {
    0b00000000, //column[0] shift register 8
    0b00000010, //column[1] shift register 7
    0b00000010, //column[2] shift register 6
    0b00000010, //column[3] shift register 5
    0b00000010, //column[4] shift register 4
    0b00000010, //column[5] shift register 3
    0b00000010, //column[6] shift register 2
    0b00000000, //column[7] shift register 1
  };

writeColumns(columns6F);
writeLayer(layerTest[7]);
delayMicroseconds(1000); //delay 1ms

  byte columns6G[8] = {
    0b00000000, //column[0] shift register 8
    0b00000010, //column[1] shift register 7
    0b00000010, //column[2] shift register 6
    0b00000010, //column[3] shift register 5
    0b00000010, //column[4] shift register 4
    0b00000010, //column[5] shift register 3
    0b00000000, //column[6] shift register 2
    0b00000000, //column[7] shift register 1
  };

writeColumns(columns6G);
writeLayer(layerTest[0]);
delayMicroseconds(1000); //delay 1ms

}




void LEDeffect7_numberdisplay_7 ()
{
  

  
  byte columns7A[8] = {
    0b00000000, //column[0] shift register 8
    0b00000000, //column[1] shift register 7
    0b00000000, //column[2] shift register 6
    0b00000000, //column[3] shift register 5
    0b00000000, //column[4] shift register 4
    0b00000010, //column[5] shift register 3
    0b00000010, //column[6] shift register 2
    0b00000000, //column[7] shift register 1
  };

writeColumns(columns7A);
writeLayer(layerTest[1]);
delayMicroseconds(1000); //delay 1ms
writeLayer(layerTest[2]);
delayMicroseconds(1000); //delay 1ms

  byte columns7B[8] = {
    0b00000000, //column[0] shift register 8
    0b00000000, //column[1] shift register 7
    0b00000000, //column[2] shift register 6
    0b00000000, //column[3] shift register 5
    0b00000010, //column[4] shift register 4
    0b00000010, //column[5] shift register 3
    0b00000000, //column[6] shift register 2
    0b00000000, //column[7] shift register 1
  };
writeColumns(columns7B);
writeLayer(layerTest[3]);
delayMicroseconds(1000); //delay 1ms

  byte columns7C[8] = {
    0b00000000, //column[0] shift register 8
    0b00000000, //column[1] shift register 7
    0b00000000, //column[2] shift register 6
    0b00000010, //column[3] shift register 5
    0b00000010, //column[4] shift register 4
    0b00000000, //column[5] shift register 3
    0b00000000, //column[6] shift register 2
    0b00000000, //column[7] shift register 1
  };
writeColumns(columns7C);
writeLayer(layerTest[4]);
delayMicroseconds(1000); //delay 1ms

  byte columns7D[8] = {
    0b00000000, //column[0] shift register 8
    0b00000000, //column[1] shift register 7
    0b00000010, //column[2] shift register 6
    0b00000010, //column[3] shift register 5
    0b00000000, //column[4] shift register 4
    0b00000000, //column[5] shift register 3
    0b00000000, //column[6] shift register 2
    0b00000000, //column[7] shift register 1
  };
writeColumns(columns7D);
writeLayer(layerTest[5]);
delayMicroseconds(1000); //delay 1ms

  byte columns7E[8] = {
    0b00000000, //column[0] shift register 8
    0b00000010, //column[1] shift register 7
    0b00000010, //column[2] shift register 6
    0b00000000, //column[3] shift register 5
    0b00000000, //column[4] shift register 4
    0b00000000, //column[5] shift register 3
    0b00000000, //column[6] shift register 2
    0b00000000, //column[7] shift register 1
  };
writeColumns(columns7E);
writeLayer(layerTest[6]);
delayMicroseconds(1000); //delay 1ms

  byte columns7F[8] = {
    0b00000000, //column[0] shift register 8
    0b00000010, //column[1] shift register 7
    0b00000010, //column[2] shift register 6
    0b00000010, //column[3] shift register 5
    0b00000010, //column[4] shift register 4
    0b00000010, //column[5] shift register 3
    0b00000010, //column[6] shift register 2
    0b00000000, //column[7] shift register 1
  };
writeColumns(columns7F);
writeLayer(layerTest[7]);
delayMicroseconds(1000); //delay 1ms
writeLayer(layerTest[0]);
delayMicroseconds(1000); //delay 1ms

}





void LEDeffect8_numberdisplay_8 ()
{
  
  byte columns8A[8] = {
    0b00000000, //column[0] shift register 8
    0b00000000, //column[1] shift register 7
    0b00000010, //column[2] shift register 6
    0b00000010, //column[3] shift register 5
    0b00000010, //column[4] shift register 4
    0b00000010, //column[5] shift register 3
    0b00000000, //column[6] shift register 2
    0b00000000, //column[7] shift register 1
  };

writeColumns(columns8A);
writeLayer(layerTest[1]);
delayMicroseconds(1000); //delay 1ms

  byte columns8B[8] = {
    0b00000000, //column[0] shift register 8
    0b00000010, //column[1] shift register 7
    0b00000010, //column[2] shift register 6
    0b00000010, //column[3] shift register 5
    0b00000010, //column[4] shift register 4
    0b00000010, //column[5] shift register 3
    0b00000010, //column[6] shift register 2
    0b00000000, //column[7] shift register 1
  };

writeColumns(columns8B);
writeLayer(layerTest[2]);
delayMicroseconds(1000); //delay 1ms

  byte columns8C[8] = {
    0b00000000, //column[0] shift register 8
    0b00000010, //column[1] shift register 7
    0b00000010, //column[2] shift register 6
    0b00000000, //column[3] shift register 5
    0b00000000, //column[4] shift register 4
    0b00000010, //column[5] shift register 3
    0b00000010, //column[6] shift register 2
    0b00000000, //column[7] shift register 1
  };

writeColumns(columns8C);
writeLayer(layerTest[3]);
delayMicroseconds(1000); //delay 1ms  

writeColumns(columns8A);
writeLayer(layerTest[4]);
delayMicroseconds(1000); //delay 1ms
writeLayer(layerTest[5]);
delayMicroseconds(1000); //delay 1ms

writeColumns(columns8C);
writeLayer(layerTest[6]);
delayMicroseconds(1000); //delay 1ms  

writeColumns(columns8B);
writeLayer(layerTest[7]);
delayMicroseconds(1000); //delay 1ms

writeColumns(columns8A);
writeLayer(layerTest[0]);
delayMicroseconds(1000); //delay 1ms

}




void LEDeffect9_numberdisplay_9 ()
{
  
  byte columns9A[8] = {
    0b00000000, //column[0] shift register 8
    0b00000000, //column[1] shift register 7
    0b00000010, //column[2] shift register 6
    0b00000010, //column[3] shift register 5
    0b00000010, //column[4] shift register 4
    0b00000010, //column[5] shift register 3
    0b00000000, //column[6] shift register 2
    0b00000000, //column[7] shift register 1
  };

writeColumns(columns9A);
writeLayer(layerTest[1]);
delayMicroseconds(1000); //delay 1ms  

  byte columns9B[8] = {
    0b00000000, //column[0] shift register 8
    0b00000010, //column[1] shift register 7
    0b00000010, //column[2] shift register 6
    0b00000010, //column[3] shift register 5
    0b00000010, //column[4] shift register 4
    0b00000010, //column[5] shift register 3
    0b00000010, //column[6] shift register 2
    0b00000000, //column[7] shift register 1
  };

writeColumns(columns9B);
writeLayer(layerTest[2]);
delayMicroseconds(1000); //delay 1ms 

  byte columns9C[8] = {
    0b00000000, //column[0] shift register 8
    0b00000010, //column[1] shift register 7
    0b00000010, //column[2] shift register 6
    0b00000000, //column[3] shift register 5
    0b00000000, //column[4] shift register 4
    0b00000000, //column[5] shift register 3
    0b00000000, //column[6] shift register 2
    0b00000000, //column[7] shift register 1
  };

writeColumns(columns9C);
writeLayer(layerTest[3]);
delayMicroseconds(1000); //delay 1ms  

  byte columns9D[8] = {
    0b00000000, //column[0] shift register 8
    0b00000010, //column[1] shift register 7
    0b00000010, //column[2] shift register 6
    0b00000010, //column[3] shift register 5
    0b00000010, //column[4] shift register 4
    0b00000010, //column[5] shift register 3
    0b00000000, //column[6] shift register 2
    0b00000000, //column[7] shift register 1
  };

writeColumns(columns9D);
writeLayer(layerTest[4]);
delayMicroseconds(1000); //delay 1ms  

writeColumns(columns9B);
writeLayer(layerTest[5]);
delayMicroseconds(1000); //delay 1ms 

  byte columns9E[8] = {
    0b00000000, //column[0] shift register 8
    0b00000010, //column[1] shift register 7
    0b00000010, //column[2] shift register 6
    0b00000000, //column[3] shift register 5
    0b00000000, //column[4] shift register 4
    0b00000010, //column[5] shift register 3
    0b00000010, //column[6] shift register 2
    0b00000000, //column[7] shift register 1
  };

writeColumns(columns9E);
writeLayer(layerTest[6]);
delayMicroseconds(1000); //delay 1ms

writeColumns(columns9B);
writeLayer(layerTest[7]);
delayMicroseconds(1000); //delay 1ms

writeColumns(columns9A);
writeLayer(layerTest[0]);
delayMicroseconds(1000); //delay 1ms

}




void LEDeffect10_numberdisplay_0 ()
{
 
  byte columns0A[8] = {
    0b00000000, //column[0] shift register 8
    0b00000000, //column[1] shift register 7
    0b00000010, //column[2] shift register 6
    0b00000010, //column[3] shift register 5
    0b00000010, //column[4] shift register 4
    0b00000010, //column[5] shift register 3
    0b00000000, //column[6] shift register 2
    0b00000000, //column[7] shift register 1
  };

writeColumns(columns0A);
writeLayer(layerTest[1]);
delayMicroseconds(1000); //delay 1ms

  byte columns0B[8] = {
    0b00000000, //column[0] shift register 8
    0b00000010, //column[1] shift register 7
    0b00000010, //column[2] shift register 6
    0b00000010, //column[3] shift register 5
    0b00000010, //column[4] shift register 4
    0b00000010, //column[5] shift register 3
    0b00000010, //column[6] shift register 2
    0b00000000, //column[7] shift register 1
  };

writeColumns(columns0B);
writeLayer(layerTest[2]);
delayMicroseconds(1000); //delay 1ms

  byte columns0C[8] = {
    0b00000000, //column[0] shift register 8
    0b00000010, //column[1] shift register 7
    0b00000010, //column[2] shift register 6
    0b00000000, //column[3] shift register 5
    0b00000000, //column[4] shift register 4
    0b00000010, //column[5] shift register 3
    0b00000010, //column[6] shift register 2
    0b00000000, //column[7] shift register 1
  };

writeColumns(columns0C);
writeLayer(layerTest[3]);
delayMicroseconds(1000); //delay 1ms
writeLayer(layerTest[4]);
delayMicroseconds(1000); //delay 1ms
writeLayer(layerTest[5]);
delayMicroseconds(1000); //delay 1ms
writeLayer(layerTest[6]);
delayMicroseconds(1000); //delay 1ms

writeColumns(columns0B);
writeLayer(layerTest[7]);
delayMicroseconds(1000); //delay 1ms

writeColumns(columns0A);
writeLayer(layerTest[0]);
delayMicroseconds(1000); //delay 1ms

}




//Below is the Rain drop effect function

// Convert normal z height to your layerTest index
// z = 0 bottom, z = 7 top
byte zToLayerIndex[8] = {
  1, // z=0 -> layer 1 bottom
  2, // z=1 -> layer 2
  3, // z=2 -> layer 3
  4, // z=3 -> layer 4
  5, // z=4 -> layer 5
  6, // z=5 -> layer 6
  7, // z=6 -> layer 7
  0  // z=7 -> layer 8 top
};

// =======================
// Rain drop data
// =======================

#define MAX_DROPS 20 //increase the number (maximum 64) to increase the density of the rain effect

struct RainDrop {
  int x;        // shift register direction, 0 to 7
  int y;        // bit position, 0 to 7
  int z;        // layer height, 0 bottom to 7 top
  bool active;  // true = this drop exists
};

RainDrop drops[MAX_DROPS];

int maxDropsNow = 5;

// =======================
// Rain helper functions
// =======================

int countActiveDrops() //checking the drop number to avoid overcrowded
{
  int count = 0;

  for (int i = 0; i < MAX_DROPS; i++) {
    if (drops[i].active) {
      count++;
    }
  }

  return count;
}

void createRandomDrop() //create the random drops
{
  if (countActiveDrops() >= maxDropsNow) {
    return;
  }

  for (int i = 0; i < MAX_DROPS; i++) {
    if (!drops[i].active) {
      drops[i].x = random(0, 8);
      drops[i].y = random(0, 8);

      // Start just below the top cloud layer.
      // Top layer z=7 is already fully ON.
      drops[i].z = 6;

      drops[i].active = true;
      return;
    }
  }
}

void updateRainDrops() //Move raindrops down
 {
  for (int i = 0; i < MAX_DROPS; i++) {
    if (drops[i].active) {
      drops[i].z--;

      if (drops[i].z < 0) {
        drops[i].active = false; //when the drop goes below the bottom layer, it disappears
      }
    }
  }
}

void buildColumnsForLayer(int z, byte columns[8]) {
  // Clear this layer first
  for (int i = 0; i < 8; i++) {
    columns[i] = 0x00;
  }

  // Top layer always full ON to create the "top rain cloud"
  if (z == 7) {
    for (int i = 0; i < 8; i++) {
      columns[i] = 0xFF;
    }
  }

  // Add raindrops that belong to this layer
  for (int i = 0; i < MAX_DROPS; i++) {
    if (drops[i].active && drops[i].z == z) {

      // Your shift register order is reversed:
      // x = 0 means physical shift register 1 = columns[7]
      // x = 7 means physical shift register 8 = columns[0]
      int registerIndex = 7 - drops[i].x;

      // Turn on one bit in that register
      columns[registerIndex] |= (1 << drops[i].y);
    }
  }
}

void showRainLayer(int z) {
  byte columns[8];

  buildColumnsForLayer(z, columns);

  byte layerIndex = zToLayerIndex[z];

  // Safe multiplexing order
  writeLayer(0x00);
  delayMicroseconds(80);

  writeColumns(columns);
  delayMicroseconds(80);

  writeLayer(layerTest[layerIndex]);
  delayMicroseconds(600);

  writeLayer(0x00);
}

void refreshRainOnce() {
  // Scan from bottom to top
  for (int z = 0; z < 8; z++) {
    showRainLayer(z);
  }
}

// =======================
// Main rain effect
// =======================

void LEDeffect11_TheRain() {
  static unsigned long lastMoveTime = 0;
  static unsigned long lastSpawnTime = 0;
  static unsigned long lastDensityChangeTime = 0;

  static int nextSpawnDelay = 100;

  unsigned long now = millis();

  // Change rain density every 3 seconds
  // random(2, 11) gives 2 to 10
  if (now - lastDensityChangeTime >= 3000) {
    maxDropsNow = random(7, 21); //change the value range in the bracket (,) to increase the density of the rain effect
    lastDensityChangeTime = now;
  }

  // Randomly create new drops
  if (now - lastSpawnTime >= nextSpawnDelay) {
    createRandomDrop();

    // Next drop appears after random time
    nextSpawnDelay = random(40, 120); //decrease the value in the bracket (,) to increase the density of the rain effect
    lastSpawnTime = now;
  }

  // Move drops down every 120 ms
  if (now - lastMoveTime >= 120) {
    updateRainDrops();
    lastMoveTime = now;
  }

  // Always refresh display
  refreshRainOnce();
}

//end of the Rain drop function






// =====================================================
// Fireworks effect
// Rocket starts at layer 1, shoots to layer 5,
// then explosion grows from the middle outward.
// Sparks are stored, so the explosion does not disappear.
// =====================================================


// Add one LED into the explosion storage
void addSpark(byte explosion[8][8], int columnIndex, int bitIndex, int layerIndex)
{
  // Safety check
  if (columnIndex < 0 || columnIndex > 7) return;
  if (bitIndex < 0 || bitIndex > 7) return;
  if (layerIndex < 0 || layerIndex > 7) return;

  // Store this LED without deleting old LEDs
  explosion[layerIndex][columnIndex] |= (1 << bitIndex);
}


// Clear the stored explosion
void clearExplosion(byte explosion[8][8])
{
  for (int layer = 0; layer < 8; layer++) {
    for (int col = 0; col < 8; col++) {
      explosion[layer][col] = 0x00;
    }
  }
}


// Show the stored explosion for a short time
void showExplosionFrame(byte explosion[8][8], int durationMs)
{
  unsigned long startTime = millis();

  while (millis() - startTime < durationMs) {

    // Scan layer 1 to layer 7
    // layerTest[0] is your top layer 8, so we skip it here
    for (int layerIndex = 1; layerIndex <= 7; layerIndex++) {

      // Turn all layers OFF first
      writeLayer(0x00);
      delayMicroseconds(80);

      // Load columns for this layer
      writeColumns(explosion[layerIndex]);
      delayMicroseconds(80);

      // Turn ON this layer briefly
      writeLayer(layerTest[layerIndex]);
      delayMicroseconds(700);

      // Turn layer OFF before next layer
      writeLayer(0x00);
    }
  }
}


// Explosion grows from center outward
void explodeStoredOneByOne(int centerColumn, int centerBit, int centerLayer)
{
  byte explosion[8][8];

  clearExplosion(explosion);

  const int maxSparks = 120;

  // 6x6x6 explosion limit
  // column 1 to 6 = 6 columns
  // bit 1 to 6    = 6 bits
  // layer 2 to 7  = 6 layers
  int minColumn = 1;
  int maxColumn = 6;

  int minBit = 1;
  int maxBit = 6;

  int minLayer = 2;
  int maxLayer = 7;

  int sparksDone = 0;

  // First spark: explosion center
  addSpark(explosion, centerColumn, centerBit, centerLayer);
  sparksDone++;

  showExplosionFrame(explosion, 30);

  // Radius 1, 2, 3
  // The explosion slowly spreads outward
  for (int radius = 1; radius <= 3; radius++) {

    int sparksThisRadius = 0;
    int attempts = 0;

    while (sparksThisRadius < 16 && sparksDone < maxSparks && attempts < 300) {
      attempts++;

      int dx = random(-radius, radius + 1);
      int dy = random(-radius, radius + 1);
      int dz = random(-radius, radius + 1);

      // Make the spark appear on the outside shell of this radius
      int biggestDistance = max(max(abs(dx), abs(dy)), abs(dz));

      if (biggestDistance != radius) {
        continue;
      }

      int sparkColumn = centerColumn + dx;
      int sparkBit    = centerBit + dy;
      int sparkLayer  = centerLayer + dz;

      // Keep spark inside 6x6x6 area
      if (sparkColumn < minColumn || sparkColumn > maxColumn) continue;
      if (sparkBit < minBit || sparkBit > maxBit) continue;
      if (sparkLayer < minLayer || sparkLayer > maxLayer) continue;

      // Add one new spark into the stored explosion
      addSpark(explosion, sparkColumn, sparkBit, sparkLayer);

      sparksThisRadius++;
      sparksDone++;

      // Show updated explosion.
      // Old sparks stay because they are stored in explosion[][]
      showExplosionFrame(explosion, 30);
    }

    // Pause after each expansion radius
    showExplosionFrame(explosion, 30);
  }

  // Keep final explosion visible
  showExplosionFrame(explosion, 700);

  clearCube();
  delay(250);
}


// Main fireworks effect
void LEDeffect12_Fireworks()
{
  byte columns[8] = {
    0b00000000, // column[0] shift register 8
    0b00000000, // column[1] shift register 7
    0b00000000, // column[2] shift register 6
    0b00000000, // column[3] shift register 5
    0b00000000, // column[4] shift register 4
    0b00000000, // column[5] shift register 3
    0b00000000, // column[6] shift register 2
    0b00000000  // column[7] shift register 1
  };

  // Choose random starting position near the middle
  int randomColumn = random(2, 6);
  // possible values: 2, 3, 4, 5

  int randomBit = random(3, 7);
  // possible values: 3, 4, 5, 6

  // Rocket LED position
  columns[randomColumn] = 1 << randomBit;


  // =======================
  // Firework blinks twice at layer 1
  // =======================

  writeLayer(0x00);
  delayMicroseconds(100);
  writeColumns(columns);
  delayMicroseconds(100);
  writeLayer(layerTest[1]);   // layer 1 bottom
  delay(400);

  clearCube();
  delay(400);

  writeLayer(0x00);
  delayMicroseconds(100);
  writeColumns(columns);
  delayMicroseconds(100);
  writeLayer(layerTest[1]);   // layer 1 bottom
  delay(400);

  clearCube();
  delay(120);


  // =======================
  // Shooting up to layer 5
  // =======================

  writeLayer(0x00);
  delayMicroseconds(100);
  writeColumns(columns);
  delayMicroseconds(100);

  writeLayer(layerTest[2]);   // layer 2
  delay(120);

  writeLayer(0x00);
  delayMicroseconds(100);
  writeColumns(columns);
  delayMicroseconds(100);
  writeLayer(layerTest[3]);   // layer 3
  delay(120);

  writeLayer(0x00);
  delayMicroseconds(100);
  writeColumns(columns);
  delayMicroseconds(100);
  writeLayer(layerTest[4]);   // layer 4
  delay(120);

  writeLayer(0x00);
  delayMicroseconds(100);
  writeColumns(columns);
  delayMicroseconds(100);
  writeLayer(layerTest[5]);   // layer 5
  delay(120);

  clearCube();
  delay(80);


  // =======================
  // Explosion
  // Start from layer 5
  // Spread outward in 6x6x6 range
  // Stored sparks stay visible
  // =======================

  explodeStoredOneByOne(randomColumn, randomBit, 5);
}



void LEDeffect13_layerchecking (){
//Turn off every LED at first
digitalWrite(LATCH_COL, LOW);
for (int i = 0; i < 8; i++) {
  shiftOut(DATA_COL, CLOCK_COL, MSBFIRST, 0b00000000); //0x00
}
digitalWrite(LATCH_COL, HIGH);

//Turn on every column of LED
digitalWrite(LATCH_COL, LOW);
for (int i = 0; i < 8; i++) {
  shiftOut(DATA_COL, CLOCK_COL, MSBFIRST, 0b11111111); //0xFF
}
digitalWrite(LATCH_COL, HIGH);

//Controlling the pattern
for (int i = 1; i < 8; i++) {
  digitalWrite(LATCH_LAY, LOW);
  shiftOut(DATA_LAY, CLOCK_LAY, MSBFIRST, layerTest[i]);
  digitalWrite(LATCH_LAY, HIGH);
  delay(500);
    if(i > 6 && i < 8) //when it reach layer i=7, this code below will be executed to turn on layer i=8
     {
      digitalWrite(LATCH_LAY, LOW);
      shiftOut(DATA_LAY, CLOCK_LAY, MSBFIRST, layerTest[0]);
      digitalWrite(LATCH_LAY, HIGH);
      delay(500);
  
  }
}

}


void LEDeffect14_512LEDs ()
{
  byte columns[8] = {
    0b11111111, //column[0] shift register 8
    0b11111111, //column[1] shift register 7
    0b11111111, //column[2] shift register 6
    0b11111111, //column[3] shift register 5
    0b11111111, //column[4] shift register 4
    0b11111111, //column[5] shift register 3
    0b11111111, //column[6] shift register 2
    0b11111111, //column[7] shift register 1
  };

writeColumns(columns);
writeLayer(layerTest[1]);
delayMicroseconds(1000); //delay 1ms
writeLayer(layerTest[2]);
delayMicroseconds(1000); //delay 1ms
writeLayer(layerTest[3]);
delayMicroseconds(1000); //delay 1ms
writeLayer(layerTest[4]);
delayMicroseconds(1000); //delay 1ms
writeLayer(layerTest[5]);
delayMicroseconds(1000); //delay 1ms
writeLayer(layerTest[6]);
delayMicroseconds(1000); //delay 1ms
writeLayer(layerTest[7]);
delayMicroseconds(1000); //delay 1ms
writeLayer(layerTest[0]);
delayMicroseconds(1000); //delay 1ms
}