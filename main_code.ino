#include "RTClib.h"
#include <Stepper.h>

//the stepper motor that we are using takes 200 steps per revolution
const int STEPSPERREV = 200;

//for the minute hand
//one revolution (200 steps) = 3600 seconds (60 min * 60 sec/min)
//one step = 3600/200 = 18 seconds
const int STEPINTERVAL_MINHAND = 3600/STEPSPERREV;

//for the hour hand
//one revolution (200 steps) = 43200 seconds (12 hrs * 60 min/hrs * 60 sec/min)
//one step = 43200/200 = 216 seconds
const int STEPINTERVAL_HOURHAND = 43200/STEPSPERREV; 

const int ZERO_POS_PIN_M = 4;
const int ZERO_POS_PIN_H = 5;

RTC_DS1307 rtc;

Stepper minuteHand (stepsPerRevolution, 8, 9, 10, 11);
Stepper hourHand (stepsPerRevolution, 2, 3, 7, 6);

//Use these Global Variables in your code
int currentTimeHours;
int currentTimeMinutes;
int currentTimeSeconds;

int startTimeHours;
int startTimeMinutes;
int startTimeSeconds;

int minuteHand_currPos;
int hourHand_currPos;

void setup () {
  //Power for the RTC
  pinMode(A3, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(ZERO_POS_PIN_M, INPUT);
  pinMode(ZERO_POS_PIN_H, INPUT);
  digitalWrite(A3,HIGH);
  digitalWrite(A2,LOW);
  Serial.begin(57600);

#ifndef ESP8266
  while (!Serial); // wait for serial port to connect. 
#endif

  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    abort();
  }

  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running, let's set the time!");
    
    // One-time local time adjustment
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
 
  }
  // minuteHand.setSpeed(60);
  // hourHand.setSpeed(60);

  while(digitalRead(ZERO_POS_PIN_M) != LOW){
    minuteHand.step(1);
  }

  while(digitalRead(ZERO_POS_PIN_H) != LOW){
    hourHand.step(1);
  }

  minuteHand_currPos = 0;
  hourHand_currPos = 0;

  DateTime start = rtc.now();
  startTimeHours = start.hour(); 
  startTimeMinutes = start.minute();
  startTimeSeconds = start.second(); 

  int totalSec = startTimeHours * 3600 + startTimeMinutes * 60 + startTimeSeconds

  int h_steps = (totalSec / STEPINTERVAL_HOURHAND) % STEPSPERREV;
  hourHand.step(h_steps);
  hourHand_currPos += h_steps;

  int m_steps = (totalSec / STEPINTERVAL_MINHAND) % STEPSPERREV; 
  minuteHand.step(m_steps);
  minuteHand_currPos += m_steps;
  
}

void loop () {
    //Re-assigning variables every second
    DateTime now = rtc.now();
    currentTimeHours = now.hour(); 
    currentTimeMinutes = now.minute();
    currentTimeSeconds = now.second(); 

    //number of seconds passed since the the clock was started to keep track of when to move the hour and the minute hands
    secondsPassedSinceStart = (currentTimeHours - startTimeHours) * 3600 + (currentTimeMinutes - startTimeMinutes) * 60 + (currentTimeSeconds - startTimeSeconds); 

    //this is to handle the cases when currentTimeHours < startTimeHours, which happens when a new day begins 
    //[eg, if start time is 23:00:00 yesterday and current time is 10:00:00 today]
    //since we are not keeping track of the day, calculating time difference like this gives us a negative value, 
    //assuming both times are of the same day and currentTime is behind startTime
    //so we need to manually add the total number of seconds in a day to this difference to mark that the day has changed
    //and to ensure that we get the actual time difference from startTime (of previous day) to currentTime
    if secondsPassedSinceStart <= 0){
      secondsPassedSinceStart = 24 * 3600 + secondsPassedSinceStart;
    }

    // the minute hand should move a step every 18 seconds as explained above 
    if (secondsPassedSinceStart % STEPINTERVAL_MINHAND == 0){
      minuteHand.step(1);
      if (minuteHand_currPos == 200){
        minuteHand_currPos = 0
      }
      minuteHand_currPos += 1;
    }

    // the hour hand should move a step every 216 seconds as explained above 
    if (secondsPassedSinceStart % STEPINTERVAL_HOURHAND == 0){
      hourHand.step(1);
      hourHand_currPos += 1;
      if (hourHand_currPos == 200){
        hourHand_currPos = 0
      }
      hourHand_currPos += 1;
    }
    delay(1000);
}




