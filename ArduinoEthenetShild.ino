#include <SPI.h>
#include <Ethernet.h>

byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
byte ip[] = {192,168,1,18};
byte gateway[] = {192,168,1,1};
byte subnet[] = {255,255,255,0};

int LED = 4;
int Lamp = 5;
int POT = A0;
int reading;

//------------------
EthernetServer server(80);
String readString;
//------------------

void setup() {
  Serial.begin(9600);
  pinMode(LED,OUTPUT);
  pinMode(Lamp,OUTPUT);

  while(!Serial){
    ;
  }

  Ethernet.begin(mac,ip,gateway,subnet);
  server.begin();
  Serial.println("IP Address Is :");
  Serial.println(Ethernet.localIP());
}

void loop() {
  EthernetClient client = server.available();
  if (client)
  {
    while(client.connected())
    {
      if (client.available())
      {
        char c = client.read();
        //--------------------
        if (readString.length()<100)
        {
          readString += c;
          Serial.print(c);
        }
        //--------------------

        if(c=='\n')
        {
          //-------------------
          Serial.println(readString);

          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println();

          //-------------------
          client.println("<META HTTP-EQUIV=REFRESH CONTENT=5");
          //-------------------

          client.println("<HTML>");
          client.println("<HEAD>");
          client.println("<TITLE>Control Device With Network</TITLE>");
          client.println("<style> body{ margin:60px 0px; padding:0px; text-align:center; background-color:#4caf50; }  h1,h2,h3{ text-align:center; font-family:tahoma; }  a{ text-decoration:none; width:200px; height:150px; border-color:green; border-top:2px solid; border-bottom:2px solid; border-right:2px solid; border-left:2px solid; border-radius:10px 10px 10px; font-family:tahoma; text-align:center; padding:8px; background-color:#ff5722; }  a:hover{ color:#ffee58; font-style:bold; }  </style>");
          client.println("</HEAD>");

          client.println("<BODY>");
          //client.println("<br />");
          client.println("<H1><font color = red>Babak Stars</font></H1>");
          client.println("<hr />");
          client.println("<br />");
          client.println("<H2>Arduino With Ethernet Shield</H2>");
          //client.println("<br />");
          //-------------------

          //-------------------
          reading = analogRead(POT);
          client.println("<p><h2>Analog Sensor Value = <font color=Blue>");
          client.println(reading,DEC);
          client.println("</font></h2></p>");
          //-------------------

          client.println("<a href=\"/?button1on\"\">Turn On LED</a>");
          client.println("<a href=\"/?button1off\"\">Turn Off LED</a>");

          client.println("<br />");
          client.println("<br />");

          client.println("<br />");
          //client.println("<br />");
          client.println("</BODY>");
          client.println("</HTML>");

          delay(1);
          client.stop();

          if(readString.indexOf("?button1on")>0)
          {
            digitalWrite(LED,HIGH);
            digitalWrite(Lamp,LOW);
          }
          if(readString.indexOf("?button1off")>0)
          {
            digitalWrite(LED,LOW);
            digitalWrite(Lamp,HIGH);
          }
          readString="";
        }
      }
    }
  }
}
