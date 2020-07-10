const int trigPin = 2;
const int echoPin1 = 3;
const int echoPin2 = 5;
const int echoPin3 = 9;
const int echoPin4 = 10;
const int ledpin1 = 0;
#define ledpin2 6
const int ledpin3 = 4;
const int ledpin4= 7;
const int ledpin5= 8;
const int ledpin6=11;
const int ledpin7=12;
const int ledpin8=13;
#define ledpin9 A0
#define ledpin10 A1
#define ledpin11 A2
#define ledpin12 A3

float duration1,duration2,duration3,duration4, distance1,distance2,distance3,distance4;

void setup() {
 pinMode(trigPin, OUTPUT);
  pinMode(echoPin1, INPUT);
   pinMode(echoPin2, INPUT);
   pinMode(echoPin3, INPUT);
   pinMode(echoPin4, INPUT);
   pinMode(ledpin1,OUTPUT);
   pinMode(ledpin2,OUTPUT);
   pinMode(ledpin3,OUTPUT);
   pinMode(ledpin4,OUTPUT);
   pinMode(ledpin5,OUTPUT);
   pinMode(ledpin6,OUTPUT);
   pinMode(ledpin7,OUTPUT);
   pinMode(ledpin8,OUTPUT);
   pinMode(ledpin9,OUTPUT);
   pinMode(ledpin10,OUTPUT);
   pinMode(ledpin11,OUTPUT);
   pinMode(ledpin12,OUTPUT);
  Serial.begin(9600);
}

void loop() {

  if(topcheck()==1 && rightcheck()==0 && bottomcheck()==0 && leftcheck()==0)
  {
    topledyellow();
    }
    else if(topcheck()==0 && rightcheck()==1 && bottomcheck()==0 && leftcheck()==0)
  {
    rightledyellow();
    }
   else if(topcheck()==0 && rightcheck()==0 && bottomcheck()==1 && leftcheck()==0)
  {
    bottomledyellow();
    }
    else if(topcheck()==0 && rightcheck()==0 && bottomcheck()==0 && leftcheck()==1)
  {
    leftledyellow();
    }

      if(topcheck()==1 && rightcheck()==-1 && bottomcheck()==-1 && leftcheck()==-1)
  {
    topledyellow();
    }
    else if(topcheck()==-1 && rightcheck()==1 && bottomcheck()==-1 && leftcheck()==-1)
  {
    rightledyellow();
    }
   else if(topcheck()==-1 && rightcheck()==-1 && bottomcheck()==1 && leftcheck()==-1)
  {
    bottomledyellow();
    }
   

    else if(topcheck()==1 && rightcheck()==1 && bottomcheck()==0 && leftcheck()==0)
  {
    topled();
    rightled();
    }
    else if(topcheck()==0 && rightcheck()==1 && bottomcheck()==1 && leftcheck()==0)
  {
    rightled();
    bottomled();
    }
   else if(topcheck()==0 && rightcheck()==0 && bottomcheck()==1 && leftcheck()==1)
  {
    bottomled();
    leftled();
    }
    else if(topcheck()==1 && rightcheck()==0 && bottomcheck()==0 && leftcheck()==1)
  {
    leftled();
    topled();
    }


       else if(topcheck()==1 && rightcheck()==0 && bottomcheck()==1 && leftcheck()==0)
  {
    topledalt();
    bottomledalt();
    }
    else if(topcheck()==0 && rightcheck()==1 && bottomcheck()==0 && leftcheck()==1)
  {
    rightledalt();
    leftledalt();
    }
   


       else if(topcheck()==1 && rightcheck()==1 && bottomcheck()==1 && leftcheck()==0)
  {
    topled();
    rightled();
    bottomled();
    }
    else if(topcheck()==0 && rightcheck()==1 && bottomcheck()==1 && leftcheck()==1)
  {
    rightled();
    bottomled();
    leftled();
    }
   else if(topcheck()==1 && rightcheck()==0 && bottomcheck()==1 && leftcheck()==1)
  {
    bottomled();
    leftled();
    topled();
    }
    else if(topcheck()==1 && rightcheck()==1 && bottomcheck()==0 && leftcheck()==1)
  {
    leftled();
    topled();
    rightled();
    }

    else if(topcheck()==-1 && rightcheck()==-1 && bottomcheck()==-1 && leftcheck()==-1)
  {
    noled();
    }


    
    else
  {
    topled();
  rightled();
  bottomled();
  leftled(); 
    }

  
}


int rightcheck()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = (duration2*.0343)/2;
  Serial.print("Distance2: ");
  Serial.println(distance2);
  delay(100);
  if(distance2<150 && distance2<300)
  {
    return 1;
    }
    else if(distance2>300)
    {
      return -1;
      }
    else
    {
      return 0;
      }
  
  }
int topcheck()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = (duration1*.0343)/2;
  Serial.print("Distance1: ");
  Serial.println(distance1);
  delay(100);
  if(distance1<150 && distance1<300)
  {
    return 1;
    }
    else if(distance1>300)
    {
      return -1;
      }
    else
    {
      return 0;
      }
  }

  int leftcheck()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration4 = pulseIn(echoPin4, HIGH);
  distance4 = (duration4*.0343)/2;
  Serial.print("Distance4: ");
  Serial.println(distance4);
  delay(100);

  if(distance4<150 && distance4<300)
  {
    return 1;
    }
    else if(distance4>300)
    {
      return -1;
      }
    else
    {
      return 0;
      }
  }
int bottomcheck()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration3 = pulseIn(echoPin3, HIGH);
  distance3 = (duration3*.0343)/2;
  Serial.print("Distance3: ");
  Serial.println(distance3);
  delay(100);
  if(distance3<150 && distance3<300)
  {
    return 1;
    }
    else if(distance3>300)
    {
      return -1;
      }
    else
    {
      return 0;
      }
  }

void rightled()
{
  digitalWrite(ledpin1, HIGH);
  digitalWrite(ledpin2, LOW);
  digitalWrite(ledpin3, LOW);
   digitalWrite(ledpin4, LOW);
  digitalWrite(ledpin5, LOW);
  digitalWrite(ledpin6, HIGH);
   digitalWrite(ledpin7, HIGH);
  digitalWrite(ledpin8, LOW);
  digitalWrite(ledpin9, LOW);
   digitalWrite(ledpin10, HIGH);
  digitalWrite(ledpin11, LOW);
  digitalWrite(ledpin12, LOW);
  delay(4000);
   digitalWrite(ledpin8, HIGH);
  delay(1000);

  }  

void topled()
{
   digitalWrite(ledpin1, LOW);
  digitalWrite(ledpin2, LOW);
  digitalWrite(ledpin3, HIGH);
   digitalWrite(ledpin4, HIGH);
  digitalWrite(ledpin5, LOW);
  digitalWrite(ledpin6, LOW);
   digitalWrite(ledpin7, HIGH);
  digitalWrite(ledpin8, LOW);
  digitalWrite(ledpin9, LOW);
   digitalWrite(ledpin10, HIGH);
  digitalWrite(ledpin11, LOW);
  digitalWrite(ledpin12, LOW);
  delay(4000);
 digitalWrite(ledpin5, HIGH);
  delay(1000);
  }  

void leftled()
{
   digitalWrite(ledpin1, HIGH);
  digitalWrite(ledpin2, LOW);
  digitalWrite(ledpin3, LOW);
   digitalWrite(ledpin4, HIGH);
  digitalWrite(ledpin5, LOW);
  digitalWrite(ledpin6, LOW);
   digitalWrite(ledpin7, HIGH);
  digitalWrite(ledpin8, LOW);
  digitalWrite(ledpin9, LOW);
   digitalWrite(ledpin10, LOW);
  digitalWrite(ledpin11, LOW);
  digitalWrite(ledpin12, HIGH);
  delay(4000);
   digitalWrite(ledpin2, HIGH);
  delay(1000);
  
  }  

void bottomled()
{
   digitalWrite(ledpin1, HIGH);
  digitalWrite(ledpin2, LOW);
  digitalWrite(ledpin3, LOW);
   digitalWrite(ledpin4, HIGH);
  digitalWrite(ledpin5, LOW);
  digitalWrite(ledpin6, LOW);
   digitalWrite(ledpin7, LOW);
  digitalWrite(ledpin8, LOW);
  digitalWrite(ledpin9, HIGH);
   digitalWrite(ledpin10, HIGH);
  digitalWrite(ledpin11, LOW);
  digitalWrite(ledpin12, LOW);
  delay(4000);
    digitalWrite(ledpin11, HIGH);
  delay(1000);
  }  
  void topledyellow()
{
   digitalWrite(ledpin1, LOW);
  digitalWrite(ledpin2, LOW);
  digitalWrite(ledpin3, HIGH);
   digitalWrite(ledpin4, HIGH);
  digitalWrite(ledpin5, LOW);
  digitalWrite(ledpin6, LOW);
   digitalWrite(ledpin7, HIGH);
  digitalWrite(ledpin8, LOW);
  digitalWrite(ledpin9, LOW);
   digitalWrite(ledpin10, HIGH);
  digitalWrite(ledpin11, LOW);
  digitalWrite(ledpin12, LOW);
  delay(4000);
  }  

  void rightledyellow()
{
  digitalWrite(ledpin1, HIGH);
  digitalWrite(ledpin2, LOW);
  digitalWrite(ledpin3, LOW);
   digitalWrite(ledpin4, LOW);
  digitalWrite(ledpin5, LOW);
  digitalWrite(ledpin6, HIGH);
   digitalWrite(ledpin7, HIGH);
  digitalWrite(ledpin8, LOW);
  digitalWrite(ledpin9, LOW);
   digitalWrite(ledpin10, HIGH);
  digitalWrite(ledpin11, LOW);
  digitalWrite(ledpin12, LOW);
  delay(4000);

  }  
  void bottomledyellow()
{
   digitalWrite(ledpin1, HIGH);
  digitalWrite(ledpin2, LOW);
  digitalWrite(ledpin3, LOW);
   digitalWrite(ledpin4, HIGH);
  digitalWrite(ledpin5, LOW);
  digitalWrite(ledpin6, LOW);
   digitalWrite(ledpin7, LOW);
  digitalWrite(ledpin8, LOW);
  digitalWrite(ledpin9, HIGH);
   digitalWrite(ledpin10, HIGH);
  digitalWrite(ledpin11, LOW);
  digitalWrite(ledpin12, LOW);
  delay(4000);
  } 
  
void leftledyellow()
{
   digitalWrite(ledpin1, HIGH);
  digitalWrite(ledpin2, LOW);
  digitalWrite(ledpin3, LOW);
   digitalWrite(ledpin4, HIGH);
  digitalWrite(ledpin5, LOW);
  digitalWrite(ledpin6, LOW);
   digitalWrite(ledpin7, HIGH);
  digitalWrite(ledpin8, LOW);
  digitalWrite(ledpin9, LOW);
   digitalWrite(ledpin10, LOW);
  digitalWrite(ledpin11, LOW);
  digitalWrite(ledpin12, HIGH);
  delay(4000);
  
  }   
void rightledalt()
{
  digitalWrite(ledpin1, HIGH);
  digitalWrite(ledpin2, LOW);
  digitalWrite(ledpin3, LOW);
   digitalWrite(ledpin4, LOW);
  digitalWrite(ledpin5, LOW);
  digitalWrite(ledpin6, HIGH);
   digitalWrite(ledpin7, HIGH);
  digitalWrite(ledpin8, LOW);
  digitalWrite(ledpin9, LOW);
   digitalWrite(ledpin10, HIGH);
  digitalWrite(ledpin11, LOW);
  digitalWrite(ledpin12, LOW);
  delay(4000);
   digitalWrite(ledpin11, HIGH);
  delay(1000);

  }  
  void topledalt()
{
   digitalWrite(ledpin1, LOW);
  digitalWrite(ledpin2, LOW);
  digitalWrite(ledpin3, HIGH);
   digitalWrite(ledpin4, HIGH);
  digitalWrite(ledpin5, LOW);
  digitalWrite(ledpin6, LOW);
   digitalWrite(ledpin7, HIGH);
  digitalWrite(ledpin8, LOW);
  digitalWrite(ledpin9, LOW);
   digitalWrite(ledpin10, HIGH);
  digitalWrite(ledpin11, LOW);
  digitalWrite(ledpin12, LOW);
  delay(4000);
 digitalWrite(ledpin8, HIGH);
  delay(1000);
  }  

void leftledalt()
{
   digitalWrite(ledpin1, HIGH);
  digitalWrite(ledpin2, LOW);
  digitalWrite(ledpin3, LOW);
   digitalWrite(ledpin4, HIGH);
  digitalWrite(ledpin5, LOW);
  digitalWrite(ledpin6, LOW);
   digitalWrite(ledpin7, HIGH);
  digitalWrite(ledpin8, LOW);
  digitalWrite(ledpin9, LOW);
   digitalWrite(ledpin10, LOW);
  digitalWrite(ledpin11, LOW);
  digitalWrite(ledpin12, HIGH);
  delay(4000);
   digitalWrite(ledpin5, HIGH);
  delay(1000);
  
  }  

void bottomledalt()
{
   digitalWrite(ledpin1, HIGH);
  digitalWrite(ledpin2, LOW);
  digitalWrite(ledpin3, LOW);
   digitalWrite(ledpin4, HIGH);
  digitalWrite(ledpin5, LOW);
  digitalWrite(ledpin6, LOW);
   digitalWrite(ledpin7, LOW);
  digitalWrite(ledpin8, LOW);
  digitalWrite(ledpin9, HIGH);
   digitalWrite(ledpin10, HIGH);
  digitalWrite(ledpin11, LOW);
  digitalWrite(ledpin12, LOW);
  delay(4000);
    digitalWrite(ledpin2, HIGH);
  delay(1000);
  }

  void noled()
{
   digitalWrite(ledpin1, LOW);
  digitalWrite(ledpin2, LOW);
  digitalWrite(ledpin3, LOW);
   digitalWrite(ledpin4, LOW);
  digitalWrite(ledpin5, LOW);
  digitalWrite(ledpin6, LOW);
   digitalWrite(ledpin7, LOW);
  digitalWrite(ledpin8, LOW);
  digitalWrite(ledpin9, LOW);
   digitalWrite(ledpin10, LOW);
  digitalWrite(ledpin11, LOW);
  digitalWrite(ledpin12, LOW);
  delay(4000);
}
  
  
  
