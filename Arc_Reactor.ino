int pinArray[] = {P1_0,P1_1,P1_2,P1_3,P1_4,P1_5,P2_6,P1_7};
int count = 0;
int timer = 30;
int ofset=0;
int flag=0;
int i=0;
#define pin P1_6
void breathe()
{
  
  for(i = 15 ; i <= 255; i+=1)
  { 
    analogWrite(P1_6, i);
    if (i > 150) {
      delay(4);
    }
    if ((i > 125) && (i < 151)) {
      delay(5);
    }
    if (( i > 100) && (i < 126)) {
      delay(7);
    }
    if (( i > 75) && (i < 101)) {
      delay(10);
    }
    if (( i > 50) && (i < 76)) {
      delay(14);
    }
    if (( i > 25) && (i < 51)) {
      delay(18);
    }
    if (( i > 1) && (i < 26)) {
      delay(19);
    }
  }
  for(i = 255; i >=15; i-=1)
  {
    analogWrite(P1_6, i);
    if (i > 150) {
      delay(4);
    }
    if ((i > 125) && (i < 151)) {
      delay(5);
    }
    if (( i > 100) && (i < 126)) {
      delay(7);
    }
    if (( i > 75) && (i < 101)) {
      delay(10);
    }
    if (( i > 50) && (i < 76)) {
      delay(14);
    }
    if (( i > 25) && (i < 51)) {
      delay(18);
    }
    if (( i > 1) && (i < 26)) {
      delay(19);
    }
  }
  delay(970);
  
}

void dot()
{
  digitalWrite(pin, HIGH);
  delay(200);
  digitalWrite(pin, LOW);
  delay(200);
}

void dash()
{
  digitalWrite(pin, HIGH);
  delay(600);
  digitalWrite(pin, LOW);
  delay(200);
}
void space()
{
  delay(200);
}
void ilu()
{
  dot(); dot(); space();space();space();
  dot();dash();dot();dot(); space();
  dot(); dot();dash();space();
  dot(); dot();dot();dash();space();space();space();
  dot();dot();dash();space();space();space();
}
void sos()
{
   dot(); dot();dot();space();dash();dash();dash();space();dot(); dot();dot();
}
void setup()
{
  for (count=0;count<8;count++) {
    pinMode(pinArray[count], OUTPUT);
  }
}


void loop() 
{ 
  while(1)
  {
  for (count=0;count<8;count++) 
  {
   digitalWrite(pinArray[count], HIGH);
   delay(timer-ofset);
   digitalWrite(pinArray[count], LOW);
   if((timer-ofset)>0)
   {
     delay(timer-ofset);
    }
    else
    { flag=1;
      break;
    }
}
ofset++;
if(flag)
{
  flag=0;
  break;
}
}
for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=5) { 
    // sets the value (range from 0 to 255):
    analogWrite(P1_6, fadeValue);         
    // wait for 30 milliseconds to see the dimming effect    
    delay(30);                            
  } 
    for (count=0;count<8;count++) 
    {
    digitalWrite(pinArray[count], HIGH);
  }
 for(i = 0 ; i <= 15; i+=1)
  {
    analogWrite(P1_6, i);
    delay(5);
  } 
 breathe();
 breathe();
 breathe();
for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=5) { 
    // sets the value (range from 0 to 255):
    analogWrite(P1_6, fadeValue);         
    // wait for 30 milliseconds to see the dimming effect    
    delay(30);                            
  } 
  
  ilu();
  for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=5) { 
    // sets the value (range from 0 to 255):
    analogWrite(P1_6, fadeValue);         
    // wait for 30 milliseconds to see the dimming effect    
    delay(30);                            
  } 

while(1);

}  

