int pinArray[] = {P1_0,P1_1,P1_2,P1_3,P1_4,P1_5,P2_6,P1_7};
int count = 0;
int timer = 30;
int ofset=0;
int flag=0;
int i=0;
volatile unsigned int mode=0;
/*
0:all on and middle on--DONE
1:breathing middle--DONE
2:flashing outer circle--knight-DONE
3:loader type all-on..all off--DONE
4:alt on alt off--DONE
5:morse:sos--done
6:morse:ilu--done
7:battery life----done
*/
#define pin P1_6
void breathe()
{
for (count=0;count<8;count++)   //turn on all 
    {
    digitalWrite(pinArray[count], HIGH);
  }

  for(i = 0 ; i <= 15; i+=1)
  {
    analogWrite(P1_6, i);
    delay(5);
  } 
  
  while(mode==1)
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
}

void dot()
{
  digitalWrite(pin, HIGH);
  delay(250);
  digitalWrite(pin, LOW);
  delay(250);
}

void dash()
{
  digitalWrite(pin, HIGH);
  delay(750);
  digitalWrite(pin, LOW);
  delay(250);
}
void space()
{
  delay(250);
}
void ilu()
{
 for (count=0;count<8;count++)   //turn on all 
    {
    digitalWrite(pinArray[count], HIGH);
    }
  dot(); dot(); space();space();space();
  dot();dash();dot();dot(); space();
  dot(); dot();dash();space();
  dot(); dot();dot();dash();space();space();space();
  dot();dot();dash();space();space();space();
}
void sos()
{
   for (count=0;count<8;count++)   //turn on all 
    {
    digitalWrite(pinArray[count], HIGH);
    }
   dot(); dot();dot();space();dash();dash();dash();space();dot(); dot();dot();
}
int readbattery()
{
            volatile float voltage;
            unsigned int value=0;
            ADC10CTL0=SREF_1+REFON+REF2_5V+ADC10ON+ADC10SHT_3; // Using internal reference of 2.5V
      ADC10CTL1=INCH_11+ADC10DIV_3;   // Internal Voltage
      __delay_cycles(1000);                   // Wait for ADC Ref to settle
      ADC10CTL0 |= ENC + ADC10SC;             // Sampling and conversion start
     while (ADC10CTL1 & BUSY);             //waiting for conversion to finish
          value = ADC10MEM;                    //fetching adc value
         ADC10CTL0&=~(ENC+ADC10ON);
          voltage=(value*2*2.5)/1023;           // Converting To Legit Voltage Values in Volts
          if(voltage>=4.0)                         // If Voltage is OK! Light Up Green LED
    {
    return 7;

    }
    else if (voltage>=3.7 && voltage<4.0 )
    {
     return 6;
    }
    else if (voltage>=3.5 && voltage<3.7)
    {
     return 5;
    }
    else if (voltage>=3.2 && voltage<3.5)
    {
     return 4;
    }
          else if (voltage>=2.9 && voltage<3.2)
    {
     return 3;
    }
          else if (voltage>=2.5 && voltage<2.9)
    {
     return 2;
    }
    else
    {
    return 1;
    }
  }
void showbattery()
{
  int val=0;
  pinMode(pin,LOW);
  for (count=0;count<8;count++)   //turn off all 
    {
    digitalWrite(pinArray[count], LOW);
  }
     val=readbattery();
     for (count=0;count<val;count++)   //turn on all 
    {
    digitalWrite(pinArray[count], HIGH);
  }
  
}
void allon()
{
 for (count=0;count<8;count++)   //turn on all 
    {
    digitalWrite(pinArray[count], HIGH);
  } 
digitalWrite(pin, HIGH);
}

void loader()
{
  digitalWrite(pin, HIGH);
  while(mode==3)
  {
    for (count=0;count<8;count++)   //turn on all 
    {
    digitalWrite(pinArray[count], HIGH);
    delay(250);
    }
    for (count=7;count>=0;count--)   //turn on all 
    {
    digitalWrite(pinArray[count], LOW);
    delay(250);
    }

  }
}
void altloader()
{
  digitalWrite(pin, HIGH);
  while(mode==4)
  {
    for (count=0;count<8;count++)   //turn on all 
    {
    digitalWrite(pinArray[count], HIGH);
    delay(250);
    }
    for (count=0;count<8;count++)   //turn on all 
    {
    digitalWrite(pinArray[count], LOW);
    delay(250);
    }

  }
}

void setup()
{
  for (count=0;count<8;count++) {
    pinMode(pinArray[count], OUTPUT);
  }
  pinMode(pin,OUTPUT);
  digitalWrite(pin,LOW);
  pinMode(P2_7,INPUT);
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
attachInterrupt(P2_7,modechange, FALLING); // Interrupt is fired whenever button is pressed
}


void loop() 
{ 
  
 switch (mode) {
     case 0:
              allon();
       break;
     case 1:  breathe();
       // do something
       break;
     case 2:digitalWrite(pin, HIGH);  
            for(count=0;count<8;count++) 
              {
                digitalWrite(pinArray[count], HIGH);
                delay(timer);
                digitalWrite(pinArray[count], LOW);
                delay(timer);
              }
       // do something
       break;
     case 3: loader();
       // do something
       break;
      case 4: altloader();
       // do something
       break;
     case 5: ilu();
       // do something
       break;
      case 6: sos();
       // do something
       break;
     case 7: showbattery();
       // do something
       break;
     default:           allon();
       // do something
 }

}  

void modechange()
{
  mode++;
  if(mode==8)
  mode=0;
}
