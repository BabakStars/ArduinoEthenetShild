//#include<Sim800l.h>
#include<SoftwareSerial.h>
SoftwareSerial gsm (10,11);
//Sim800l Sim800l;
String txt1 = "";
String txt2 = "";
String num = "YOUR NUMBER";
String txtSmsR;
String numberSms;
bool ch1 = false;
bool ch2 = false;
bool ch3 = false;
bool ch4 = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  digitalWrite(2,1);
  digitalWrite(3,1);
  digitalWrite(4,1);
  digitalWrite(5,1);
  Serial.println("Testing Sim800l");
  gsm.begin(9600);
  gsm.println("AT");
  delay(100);
  if(gsm.available())
  {
    Serial.println(gsm.readString());
  }
    gsm.println("AT+CMGF=1");           //AT+CNMI=1,2,0,0,0
    delay(200);
    gsm.println("AT+CNMI=1,2,0,0,0");   //AT+CNMI=1,2,0,0,0
    delay(200);
  //Sim800l.begin();

  //error = Sim800l.delAllSms();
}

void loop() {
  // put your main code here, to run repeatedly:
   if(gsm.available())
  {
    txt1 = gsm.readString();
    Serial.println(txt1);

      String number = txt1.substring(9,22);
 if(number == "secound number")
 {     
        if(txt1.indexOf("ch1")!= -1)
    {
      Serial.println(txt1.substring(9,22));
          if(ch1 == false)
          {
            digitalWrite(2,0);
            ch1 = true;
                gsm.println("AT+CMGS=\"YOUR NUMBER\"");
                delay(200);
                gsm.println("ch1on");
                delay(200);
                gsm.write(26);
          }
          else
          {
            digitalWrite(2,1);
            ch1 = false;
                gsm.println("AT+CMGS=\"YOUR NUMBER\"");
                delay(200);
                gsm.println("ch1off");
                delay(200);
                gsm.write(26);
          }
    }
        if(txt1.indexOf("ch2")!= -1)
        {    Serial.println(txt1.substring(9,22));
            if(ch2 == false)
          {
            digitalWrite(3,0);
            ch2 = true;
                gsm.println("AT+CMGS=\"YOUR NUMBER\"");
                delay(200);
                gsm.println("ch2on");
                delay(200);
                gsm.write(26);
          }
          else
          {
            digitalWrite(3,1);
            ch2 = false;
                gsm.println("AT+CMGS=\"YOUR NUMBER\"");
                delay(200);
                gsm.println("ch2off");
                delay(200);
                gsm.write(26);
          }
        }
        if(txt1.indexOf("ch3")!= -1)
    {
      Serial.println(txt1.substring(9,22));
         if(ch3 == false)
          {
            digitalWrite(4,0);
            ch3 = true;
                gsm.println("AT+CMGS=\"YOUR NUMBER\"");
                delay(200);
                gsm.println("ch3on");
                delay(200);
                gsm.write(26);
          }
          else
          {
            digitalWrite(4,1);
            ch3 = false;
                gsm.println("AT+CMGS=\"YOUR NUMBER\"");
                delay(200);
                gsm.println("ch3off");
                delay(200);
                gsm.write(26);
          }
    }
        if(txt1.indexOf("ch4")!= -1)
    {
      Serial.println(txt1.substring(9,22));
        if(ch4 == false)
          {
            digitalWrite(5,0);
            ch4 = true;
                gsm.println("AT+CMGS=\"YOUR NUMBER\"");
                delay(200);
                gsm.println("ch4on");
                delay(200);
                gsm.write(26);
          }
          else
          {
            digitalWrite(5,1);
            ch4 = false;
                gsm.println("AT+CMGS=\"YOUR NUMBER\"");
                delay(200);
                gsm.println("ch4off");
                delay(200);
                gsm.write(26);
          }
    }
    delay(2000);
    return;
 }
}
   
    
    if(Serial.available())
  { 
    txt2 = Serial.readString();
    //gsm.println("AT+CMGS=\"09137392795\"");
    gsm.println("AT+CMGS=\"YOUR NUMBER\"");
    delay(200);
    gsm.println(txt2);
    delay(200);
    gsm.write(26);
  }
  
  
  
}
