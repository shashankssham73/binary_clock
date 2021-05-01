#include <DS3231.h>

// Init the DS3231 using the hardware interface
DS3231  rtc(SDA, SCL);

// Init a Time-data structure
Time  t;

void setup()
{
  pinMode(22,OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  // Setup Serial connection
  Serial.begin(115200);
  // Uncomment the next line if you are using an Arduino Leonardo
  //while (!Serial) {}

  // Initialize the rtc object
  rtc.begin();

  // The following lines can be uncommented to set the date and time
  //rtc.setDOW(WEDNESDAY);     // Set Day-of-Week to SUNDAY
  //rtc.setTime(17, 27, 0);     // Set the time to 12:00:00 (24hr format)
  //rtc.setDate(11, 1, 2017);   // Set the date to January 1st, 2014
}

void loop()
{
  // Get data from the DS3231
   t= rtc.getTime();

  // date
  Serial.print(t.date, DEC);
  Serial.print("/");
  Serial.print(rtc.getMonthStr());
  Serial.print("/");
  Serial.print(t.year, DEC);
  Serial.println(".");

  // Day-of-Week and time
  Serial.print(t.dow, DEC);
  Serial.println("  -  -  -  -  -");
  Serial.print(t.hour, DEC);
  Serial.print(":");
  Serial.print(t.min, DEC);
  Serial.print(":");
  Serial.print(t.sec, DEC);
  Serial.println(".");

  // This is for readability
  Serial.println("  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -");

  int munit=0;
  int miunit=0;
  int hunit=0;
  int hounit=0;
   munit=t.min%10;
   miunit=t.min;
   Serial.println(munit);
   Serial.println(miunit);
   //minutes units digit
  if(munit == 1 || munit == 3 || munit == 5 || munit == 7 || munit == 9)
  {
    digitalWrite(22,HIGH);
  }
  else
  {
    digitalWrite(22,LOW);
  }
 if(munit == 2 || munit == 3 || munit == 6 || munit == 7)
 {
  digitalWrite(2,HIGH);
  }
  else
  {
    digitalWrite(2,LOW);
    }
 if(munit == 4 || munit == 5 || munit == 6 || munit == 7)
 {
  digitalWrite(3,HIGH);
  }
  else
  {
    digitalWrite(3,LOW);
    }
 if(munit == 8 || munit == 9)
 {
  digitalWrite(4,HIGH);
  }
  else
  {
    digitalWrite(4,LOW);
  }

 //minutes tens digit
 if((miunit >= 10 && miunit < 20) || (miunit >= 30 && miunit < 40) || (miunit >= 50 && miunit < 60))
 {
  digitalWrite(5, HIGH);
  }
  else
  {
    digitalWrite(5,LOW);
    }
 if(miunit >= 20 && miunit < 40)
 {
  digitalWrite(6, HIGH);
 }
 else
 {
  digitalWrite(6,LOW);
  }
 if(miunit >= 40 && miunit < 60)
 {
  digitalWrite(7, HIGH);
  }
  else
  {
    digitalWrite(7,LOW);
    }

    //Hours
    hunit=t.hour%10;
   hounit=t.hour;
    Serial.println(hunit);
    Serial.println(hounit);
 //hour units digit
 if(hunit == 1 || hunit == 3 || hunit == 5 || hunit == 7 || hunit == 9)
 {
  digitalWrite(8, HIGH);
  }
  else
  {
    digitalWrite(8,LOW);
    }
 if(hunit == 2 || hunit == 3 || hunit == 6 || hunit == 7)
 {
  digitalWrite(9, HIGH);
  }
  else
  {
    digitalWrite(9,LOW);
    }
 if(hunit == 4 || hunit == 5 || hunit == 6 || hunit == 7)
 {
  digitalWrite(10, HIGH);
  }
  else
  {
    digitalWrite(10,LOW);
    }
 if(hunit == 8 || hunit == 9)
 {
  digitalWrite(11, HIGH);
  }
  else
  {
    digitalWrite(11,LOW);
    }

 //hour tens digit
 if(hounit >= 10 && hounit < 20)
 {
  digitalWrite(12, HIGH);
  }
  else
  {
    digitalWrite(12,LOW);
    }
 if(hounit >= 20 && hounit < 24)
 {
  digitalWrite(13, HIGH);
  }
  else
  {
    digitalWrite(13,LOW);
    }


  // Wait one second before repeating :)
  delay (1000);
}
