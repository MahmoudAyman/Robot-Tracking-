#include <OneSheeld.h>

boolean check =true;
int count =-1;
int s=0;
int sw=0;
int w=0;
int nw=0;
int n=0;
int ne=00;
int e=0;
int se=0;
/*
void intialize ()
{
  int count =-1;
  
}
*/
void setup() 
{
  /* Start communication. */
  OneSheeld.begin();
}

void loop()
{
 if (count == -1)
      {
        Serial.println("Intializing.., Please Wait!");
        Serial.println("follow the instructions...");
        Serial.println("Put the phone on 0 degree, and press *");
        count++;
      }
  
      if(Keypad.isRowPressed(3) && Keypad.isColumnPressed(0))
      {  
        if (count == 0)
        { 
          e=OrientationSensor.getX();
          Serial.print("0 degree: "), Serial.println(e);
          count++;
      Serial.println("Put the phone on 45 degree, and press *");
      delay(100); 
    }
    else if (count ==1)
    {
      ne=OrientationSensor.getX();
      Serial.print("45 degree: "), Serial.println(ne);
      count++;
      Serial.println("Put the phone on 90 degree, and press *");
      delay(100); 
    }
    else if (count ==2)
    {
      n=OrientationSensor.getX();
      Serial.print("90 degree: "), Serial.println(n);
      count++;
      Serial.println("Put the phone on 135 degree, and press *");
      delay(100); 
    }
    else if (count ==3)
    {
      nw=OrientationSensor.getX();
      Serial.print("135 degree: "), Serial.println(nw);
      count++;
      Serial.println("Put the phone on 180 degree, and press *");
      delay(100); 
    }
    else if (count ==4)
    {
      w=OrientationSensor.getX();
      Serial.print("180 degree: "), Serial.println(w);
      count++;
      Serial.println("Put the phone on 225 degree, and press *");
      delay(100); 
    }
    else if (count ==5)
    {
      sw=OrientationSensor.getX();
      Serial.print("225 degree: "), Serial.println(sw);
      count++;
      Serial.println("Put the phone on 270 degree, and press *");
      delay(100); 
    }
    else if (count ==6)
    {
      w=OrientationSensor.getX();
      Serial.print("270 degree: "), Serial.println(w);
      count++;
      Serial.println("Put the phone on 315 degree, and press *");
      delay(100); 
    }
    else if (count ==7)
    {
      se=OrientationSensor.getX();
      Serial.print("315 degree: "), Serial.println(se);
      count++;
    }
    else if (count == 8)
    {
      Serial.println("Intialization Process Complete");
      count++;
    }
    
  } 
}
