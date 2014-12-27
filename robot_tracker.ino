#include <OneSheeld.h>


float Orient_x[100];
float acce_y[100];
int state =-1;
int dir =0;
int index =0;
int index1=0;
int acc_n=200;
int s=335;
int sw=29;
int w=61;
int nw=124;
int n=159;
int ne=201;
int e=245;
int se=298;

int orient_val=0;
int previous_dir=0;
int current_dir=0;
int Orient_tolerance = 10;
int Acce_tolerance=300;
int check=0;
unsigned long current_time=0;

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

float distance (unsigned long x, float acc)
{
  float test = float(0.5*acc*(float(x)/1000)*(float(x)/1000));
  //Serial.print("test"), Serial.println(test);
  return test;
}

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

void getA ()
{
  Orient_x[index]=average(acce_y,index1+1);
  //Serial.print("acce"), Serial.println(Orient_x[index]);
  index++;
  int acce_y[100];
  index1=0;
}

void getT()
{
  Orient_x[index]=(millis()-current_time)-1000;
  //Serial.print("time"), Serial.println(Orient_x[index]);
  index++;
  current_time=millis();
}

void getD()
{
  Orient_x[index]=abs(distance(Orient_x[index-1],Orient_x[index-2]));
  //Serial.print("dist"), Serial.println(Orient_x[index]);
  index++;
}

void updateOrient(int x)
{
  Orient_x[index] = x ;
  //out[index]=("Direction: " + String(int(Orient_x[index])));
  Serial.print("dir"),Serial.println(int(Orient_x[index]));
  index ++;
  previous_dir=current_dir;
}

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
    orient_val=OrientationSensor.getX();
    //Serial.println(orient_val);
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
