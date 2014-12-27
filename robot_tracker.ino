/*
ROBOT TRACKER IS A PROJECT TO TRACK AND MONITOR THE MOTION
USING ARDUINO ADN 1SHEELD. 
CODE IMPLEMENTED BY MAHMOUD AYMAN <mahmoud.ayman@gmail.com>
ALL COPYRIGHTS RESERVED, THIS CODE WAS PUBLISHED IN THE PUBLIC DOMAIN
THIS IDEA OF THIS PROJECT IS TO CAPTURE THE VALUES OF THE SENSORS OF YOUR
SMARTPHONE USING 1SHEELD AND USE THE ARDUINO MAP THE MOTION OF THE ROBOT
FOLLOW THE COMMENTS
*/


#include <OneSheeld.h>


float Orient_x[100];  //array to save the data of mapping
float acce_y[100];    //array to save different values of acceleration

int state =-1;    //state of the keybad (1 or 2 pressed)      

int index =0;    //index value for Orient_x array
int index1=0;    //index value for acce_y array

int acc_n=200;    //intial value of the accelerometer

int s=335;        //intial values for orientation sensor, entered in intialization
int sw=29;        // n--> north, ne---> northease, nw-->northwest
int w=61;         // s--> south, se---> southeast, sw--->southwest
int nw=124;      //e--> east, w--> west
int n=159;
int ne=201;
int e=245;
int se=298;

int orient_val=0;  //current value of orientation sensor
int previous_dir=0;   //the current direction of the robot
int current_dir=0;    //the previous direction of the robot
int Orient_tolerance = 10;    //tolerance value of the orientation sensor
int Acce_tolerance=300;       //tolerance value of the accelerometer
int check=0;
unsigned long current_time=0;  //value to store time

//function to check value of orientation sensor
//return true if the val in the range of the currennt direction, otherwise returns false
boolean inRange (int x, int val)
{
  if (val >= x-Orient_tolerance && val <= x+Orient_tolerance)
  {
    return true;
  }
  else
  {
    return false;
  }
}

//function to compute the distance covered in certain direction
//takes two arguments, time and acceleration
//returns the distance in cm
float distance (unsigned long x, float acc)
{
  float test = float(0.5*acc*(float(x)/1000)*(float(x)/1000));
  //Serial.print("test"), Serial.println(test);
  return test;
}

//function to get the average acceleration
//takes two arguments array of accelerometer values and number of elements in the array
//return the average acceleration in cm/s^2
float average (float x[],int n)
{
  float temp= 0.0;
  for (int i=0; i<n; i++)
  {
    temp += x[i]*100;
    //Serial.print("***"), Serial.println(x[i]);
  }
  //Serial.println(temp/n);
  //Serial.println(n);
  return ((temp/n)-acc_n);
}

//function to add the value of the acceleration to Orient_x array
void getA ()
{
  Orient_x[index]=average(acce_y,index1+1);
  //Serial.print("acce"), Serial.println(Orient_x[index]);
  index++;
  int acce_y[100];
  index1=0;
}

//function to add the Time of the acceleration to Orient_x array
void getT()
{
  Orient_x[index]=(millis()-current_time)-1000;
  //Serial.print("time"), Serial.println(Orient_x[index]);
  index++;
  current_time=millis();
}

//function to add the Distance of the acceleration to Orient_x array
void getD()
{
  Orient_x[index]=abs(distance(Orient_x[index-1],Orient_x[index-2]));
  //Serial.print("dist"), Serial.println(Orient_x[index]);
  index++;
}

//function update Orient_x array
void updateOrient(int x)
{
  Orient_x[index] = x ;
  //out[index]=("Direction: " + String(int(Orient_x[index])));
  Serial.print("dir"),Serial.println(int(Orient_x[index]));
  index ++;
  previous_dir=current_dir;
}

//function acce_y array
void updateAcce ()
{
  if (index1 < 100)
  {
    if (index1 ==0)
     {
       acce_y[index1]=AccelerometerSensor.getY();
       index1++;
     } 
    float temp =AccelerometerSensor.getY();
    if (abs((acce_y[-1]*100)-(temp*100)) >= Acce_tolerance)
    {
      acce_y[index1]=temp;
      Serial.print("acceee"), Serial.println(acce_y[index1]);
      index1++; 
    }
  }
  else
  {
    Serial.println("Acce_y index full");
  }
  
}

void setup ()
{
  //begin communication with 1sheeld
  OneSheeld.begin();
    
}

void loop()
{
  //check state
  if(Keypad.isRowPressed(0) && Keypad.isColumnPressed(0))
  {
    if (state!=1)
    {
      Serial.println("1");
      state = 1; 
    }
  }
  else if (Keypad.isRowPressed(0) && Keypad.isColumnPressed(1))
  {
    if (state !=2 && state!=0)
    {
      Serial.println("2");
      state = 2; 
    }
  }
  //take_action
  if (state==1)
  {
    //capture the value of Orientation sensor
    orient_val=OrientationSensor.getX();
    
    //check direction
    if (inRange(n,orient_val))
    {
      current_dir=8;
      if (current_dir != previous_dir)
      {
        if (index < 100)
        {
          getA();
          getT();
          getD();
          updateOrient(8);
        }
        else
        {
          Serial.println("Orient_x index full");
        }
      }
      else
      {
        updateAcce();
      }
    }
    else if (inRange(ne,orient_val))
    {
      current_dir=9;
      if (current_dir != previous_dir)
      {
        if (index < 100)
        {
          getA();
          getT();
          getD();
          updateOrient(9);
        }
        else
        {
          Serial.println("Orient_x index full");
        }
      }
      else
      {
        updateAcce();
      }
    }
    else if (inRange(e,orient_val))
    {
      current_dir=6;
      if (current_dir != previous_dir)
      {
        if (index < 100)
        {
          getA();
          getT();
          getD();
          updateOrient(6);
        }
        else
        {
          Serial.println("Orient_x index full");
        }
      }
      else
      {
        updateAcce();
      }
    }
    else if (inRange(se,orient_val))
    {
      current_dir=3;
      if (current_dir != previous_dir)
      {
        if (index < 100)
        {
          getA();
          getT();
          getD();
          updateOrient(3);
        }
        else
        {
          Serial.println("Orient_x index full");
        }
      }
      else
      {
        updateAcce();
      }
    }
    else if (inRange(s,orient_val))
    {
      current_dir=2;
      if (current_dir != previous_dir)
      {
        if (index < 100)
        {
          getA();
          getT();
          getD();
          updateOrient(2);
        }
        else
        {
          Serial.println("Orient_x index full");
        }
      }
      else
      {
        updateAcce();
      }
    }
    else if (inRange(sw,orient_val))
    {
      current_dir=1;
      if (current_dir != previous_dir)
      {
        if (index < 100)
        {
          getA();
          getT();
          getD();
          updateOrient(1);
        }
        else
        {
          Serial.println("Orient_x index full");
        }
      }
      else
      {
        updateAcce();
      }
    }
    else if (inRange(w,orient_val))
    {
      current_dir=4;
      if (current_dir != previous_dir)
      {
        if (index < 100)
        {
          getA();
          getT();
          getD();
          updateOrient(4);
        }
        else
        {
          Serial.println("Orient_x index full");
        }
      }
      else
      {
        updateAcce();
      }
    }
    else if (inRange(nw,orient_val))
    {
      current_dir=7;
      if (current_dir != previous_dir)
      {
        if (index < 100)
        {
          getA();
          getT();
          getD();
          updateOrient(7);
        }
        else
        {
          Serial.println("Orient_x index full");
        }
      }
      else
      {
        updateAcce();
      }
    }
    //orient_val=0;
  }
  //print Orient_x array
  else if (state == 2)
  {
    getA();
    getT();
    getD();
    //print orient_x
    Serial.println("Orient_x");
    for (int i =3; i<index; i+=4)
    {
      Serial.print("Direction  : "), Serial.println(int(Orient_x[i]));
      Serial.print("Acceleration   : "), Serial.print(Orient_x[i+1]), Serial.println(" cm/s^2.");
      Serial.print("Time  : "), Serial.print(Orient_x[i+2]), Serial.println(" ms.");
      Serial.print("Distance   : "),Serial.print(Orient_x[i+3]), Serial.println(" cm.");
      Serial.println();
    }
    Serial.println();
    //reset orient_x
    
    float Orient_x[100];
    index=0;
    
    state=0; //reset state
  }
  delay(100);
}
