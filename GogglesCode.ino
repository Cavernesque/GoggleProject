// the setup function runs once when you press reset or power the board
void setup() {
  // PIN 2 IS TA1
  pinMode(2, OUTPUT);
  // PIN 3 IS TA2
  pinMode(3, OUTPUT);
  // PIN 4 IS TA3
  pinMode(4, OUTPUT);
  // PIN 5 IS TA4
  pinMode(5, OUTPUT);
  // PIN 6 IS TA5
  pinMode(6, OUTPUT);
  /*
  */
  // PIN 8 IS TC1
  pinMode(8, OUTPUT);
  // PIN 9 IS TC2
  pinMode(9, OUTPUT);
  // PIN 10 IS TC3
  pinMode(10, OUTPUT);
  // PIN 11 IS TC4
  pinMode(11, OUTPUT);
  // PIN 12 IS TC5
  pinMode(12, OUTPUT);
}

void ledOn(int ta, int tc, unsigned long dly){
  digitalWrite(ta, HIGH);
  digitalWrite(tc, HIGH);
  delayMicroseconds(dly);
  digitalWrite(ta, LOW);
  digitalWrite(tc, LOW);
}

// Set this value to a maximum of 100, or else stroboscopic effect is somewhat visible. Below 100 is fine.
unsigned long dlytime = 100;

/* segOn functions 
 *  
 *  
*/
void seg1On(){
  ledOn(2,8,dlytime);
  //
  ledOn(3,8,dlytime);
  //
  ledOn(4,8,dlytime);
  //
  ledOn(5,8,dlytime);
  //
  ledOn(6,8,dlytime);
}

void seg2On(){
  ledOn(2,9,dlytime);
  //
  ledOn(3,9,dlytime);
  //
  ledOn(4,9,dlytime);
  //
  ledOn(5,9,dlytime);
  //
  ledOn(6,9,dlytime);
}

void seg3On(){
  ledOn(2,10,dlytime);
  //
  ledOn(3,10,dlytime);
  //
  ledOn(4,10,dlytime);
  //
  ledOn(5,10,dlytime);
  //
  ledOn(6,10,dlytime);
}

void seg4On(){
  ledOn(2,11,dlytime);
  //
  ledOn(3,11,dlytime);
  //
  ledOn(4,11,dlytime);
  //
  ledOn(5,11,dlytime);
  //
  ledOn(6,11,dlytime);
}

void seg5On(){
  ledOn(2,12,dlytime);
  //
  ledOn(3,12,dlytime);
  //
  ledOn(4,12,dlytime);
  //
  ledOn(5,12,dlytime);
  //
  ledOn(6,12,dlytime);
}

void seg6On(){
  ledOn(2,8,dlytime);
  //
  ledOn(2,9,dlytime);
  //
  ledOn(2,10,dlytime);
  //
  ledOn(2,11,dlytime);
  //
  ledOn(2,12,dlytime);
}

void seg7On(){
  ledOn(3,8,dlytime);
  //
  ledOn(3,9,dlytime);
  //
  ledOn(3,10,dlytime);
  //
  ledOn(3,11,dlytime);
  //
  ledOn(3,12,dlytime);
}

void seg8On(){
  ledOn(4,8,dlytime);
  //
  ledOn(4,9,dlytime);
  //
  ledOn(4,10,dlytime);
  //
  ledOn(4,11,dlytime);
  //
  ledOn(4,12,dlytime);
}

void seg9On(){
  ledOn(5,8,dlytime);
  //
  ledOn(5,9,dlytime);
  //
  ledOn(5,10,dlytime);
  //
  ledOn(5,11,dlytime);
  //
  ledOn(5,12,dlytime);
}

void seg10On(){
  ledOn(6,8,dlytime);
  //
  ledOn(6,9,dlytime);
  //
  ledOn(6,10,dlytime);
  //
  ledOn(6,11,dlytime);
  //
  ledOn(6,12,dlytime);
}

void led1On(){
  ledOn(2,8,dlytime);
}

void led2On(){
  ledOn(3,8,dlytime);
}

void led3On(){
  ledOn(4,8,dlytime);
}

void led4On(){
  ledOn(5,8,dlytime);
}

void led5On(){
  ledOn(6,8,dlytime);
}

void led6On(){
  ledOn(2,9,dlytime);
}

void led7On(){
  ledOn(3,9,dlytime);
}

void led8On(){
  ledOn(4,9,dlytime);
}

void led9On(){
  ledOn(5,9,dlytime);
}

void led10On(){
  ledOn(6,9,dlytime);
}

void led11On(){
  ledOn(2,10,dlytime);
}

void led12On(){
  ledOn(3,10,dlytime);
}

void led13On(){
  ledOn(4,10,dlytime);
}

void led14On(){
  ledOn(5,10,dlytime);
}

void led15On(){
  ledOn(6,10,dlytime);
}

void led16On(){
  ledOn(2,11,dlytime);
}

void led17On(){
  ledOn(3,11,dlytime);
}

void led18On(){
  ledOn(4,11,dlytime);
}

void led19On(){
  ledOn(5,11,dlytime);
}

void led20On(){
  ledOn(6,11,dlytime);
}

void led21On(){
  ledOn(2,12,dlytime);
}

void led22On(){
  ledOn(3,12,dlytime);
}

void led23On(){
  ledOn(4,12,dlytime);
}

void led24On(){
  ledOn(5,12,dlytime);
}

void led25On(){
  ledOn(6,12,dlytime);
}

/* Turns all LEDs in all segments on at a fast enough frequency to be seamless
* 
*/
void segAllOn1(int timeOn){
  unsigned long inittime = millis();
  unsigned long fintime = inittime + timeOn;
  unsigned long currtime  = 0;
  while(currtime < fintime){
  seg1On();
  seg2On();
  seg3On();
  seg4On();
  seg5On();
  currtime = millis();
  }
}

void segAllOn2(int timeOn){
  unsigned long inittime = millis();
  unsigned long fintime = inittime + timeOn;
  unsigned long currtime  = 0;
  while(currtime < fintime){
  seg6On();
  seg7On();
  seg8On();
  seg9On();
  seg10On();
  currtime = millis();
  }
}

/* Flash pattern 1 enables each the first LED in each cathode transistor in sequence. Doing it fast enough makes it look simultaneous. On master diagram, this is a left to right move.
* EX: Anode 1 leds, each cathode on in order - LED1,6,11,16,21
* Anode 2 - LED2,7,12,17,22
* etc.
* Argument: flashtime is used to separate out each cathode enable. Will determine length between each "pulse".
*     Format: time in milliseconds
*     Recommended input: 250 and higher. Lower settings can be used for another strobe effect.
* Argument: newdelay is used in the segOn functions to determine length of light on pulse.
*     Function call reference: segOn will enable the LED for that duration, then turn the output off. Increasing the value of newdelay above 3 will introduce stagger.
*     Format: time in milliseconds (can specify to decimal places) Cannot be higher than 16.2.
*     Recommended input: 2.5 - brightest and doesn't impede other function parts.
* Fun settings:
* flashPattern1(250,2.5) - Fun, bouncy chain.
* flashPattern1(30, 2.5) - "The runners". Lights chase each other very quickly.
* flashPattern1(10, 2.5) - A crazy wild strobe.
* flashPattern1(500, 2.5) - Fire alarm strobe.
* flashPattern1(2000, 2.5) - Heartbeat. Very slow, almost feels random when segment finally lights.
*/
void flashPattern1(int flashtime, float newdelay){
  delay(flashtime);
  dlytime = newdelay * 1000;
  seg6On();
  delay(flashtime);
  seg7On();
  delay(flashtime);
  seg8On();
  delay(flashtime);
  seg9On();
  delay(flashtime);
  seg10On();
  delay(flashtime);
  dlytime = 100;
}

/* Flash pattern 2 enables each the first LED in each anode transistor in sequence. Doing it fast enough makes it look simultaneous. On master diagram, this is a top to bottom move.
* EX: Cathode 1 leds, each anode on in order - LED1,2,3,4,5
* Cathode 2 leds, each anode on in order - LED6,7,8,9,10
* etc.
* Argument: flashtime is used to separate out each cathode enable. Will determine length between each "pulse".
*     Format: time in milliseconds
*     Recommended input: 250 and higher. Lower settings can be used for another strobe effect.
* Argument: newdelay is used in the segOn functions to determine length of light on pulse.
*     Function call reference: segOn will enable the LED for that duration, then turn the output off. Increasing the value of newdelay above 3 will introduce stagger.
*     Format: time in milliseconds (can specify to decimal places) Cannot be higher than 16.2. Lower than 1 dims leds substantially.
*     Recommended input: 2.5 - brightest and doesn't impede other function parts
* Fun settings: 
* (100, 2.5) - Skippy and bouncy segment line
* (30, 2.5) - Super fast line
* (10, 2.5) - Another strobe
* (500,2.5) - Bright, slow segment jumps
* (2000, 2.5) - Snails pace progression, almost feels random when the segment lights.
*/
void flashPattern2(int flashtime, float newdelay){
  delay(flashtime);
  dlytime = newdelay * 1000;
  seg1On();
  delay(flashtime);
  seg2On();
  delay(flashtime);
  seg3On();
  delay(flashtime);
  seg4On();
  delay(flashtime);
  seg5On();
  dlytime = 100;
}

/* flash pattern 3 enables all the leds across the array on, then off.
* Argument: timeOn is used to control the flash on time.
*   Format: time in milliseconds. Highest value is 32762 (But why, though?)
*   Recommended input: 500. A nice satisfying on cycle.
* Argument: timeOff is used to control the flash off time.
*   Format: time in milliseconds.  Lowest value is 1 (But why, though?)
*   Recommended input: 100. A brief off time, just enough to register.
* Argument: duration is used to control the duration of the pattern.
*   Format: time in milliseconds.
* Fun settings:
* (500,100,1000) - A brief flash, does it twice.
* (500,100,2000) - 4 times.
* (50, 50, 2000) - Fuck everything around you, I guess?
*/
void flashPattern3(int timeOn, int timeOff, int duration){
  unsigned long inittime = millis();
  unsigned long fintime = inittime + duration;
  unsigned long currtime  = 0;
  while(currtime < fintime){
  segAllOn1(timeOn);
  delay(timeOff);
  currtime = millis();
  }
}

/* Strobe pattern 1 enables each led across the cathode transistors.
* EX: LED 1,2,3,4,5,6,7,8,9,10
* Argument: timeOn is used to control duration of the whole function.
*   Format: time in milliseconds
*   Recommended input: 400 or higher. Any lower, and you will only get 1 strobe across the array. (Could be desirable. Set to 100 to ensure 1 pass on fastest strobe setting)
* Argument: strobespeed is used to control how fast the function moves across the array.
*   Format: time in milliseconds (can specify decimal places) Cannot be higher than 16.2. Lower than 5 is asking for an epileptic seizure.
*   Recommended input: 15. A reasonable pace across the array. Takes about 300 ms to complete.
* Fun settings:
* (100, 15) - Snaking line across all leds, 1 cycle.
* (500, 15) - Snaking line, 2 cycles.
* (500, 5) - FAST line, 3 cycles.
* (1000, 10) - Clipping line, 4 cycles.
* (3000, 4) - Fuck you, be blind.
*/
void strobePattern1(int timeOn, float strobespeed){
  dlytime = strobespeed * 1000;
  segAllOn1(timeOn);
  // set dlytime back to normal for the next function
  dlytime = 100;
}

/* Strobe pattern 2 enables each led across the anode transistors.
* EX:  LED 1,6,11,16,21,2,7,12,17,22.
* Argument: timeOn is used to control duration of the whole function.
*   Format: time in milliseconds
*   Recommended input: 400 or higher. Any lower, and you will only get 1 strobe across the array. (Could be desirable. Set to 100 to ensure 1 pass on fastest strobe setting)
* Argument: strobespeed is used to control how fast the function moves across the array.
*   Format: time in milliseconds (can specify decimal places) Cannot be higher than 16.2.
*   Recommended input: 5. The lower the input on this function, the less obvious the stroboscopic effect.
* Fun settings:
* (100,5) - "Shuffle". Every led moves once.
* (500, 4) - Snaking line, 2 cycles.
* (500, 15) - Exaggerated snaking line, 2 cycles.
* (1000, 3) - Buzzing line.
* (1000, 1.5) - Vibrating line.
* (3000, 15) - I guess you didn't want friends, then, did you?
*/
void strobePattern2(int timeOn, float strobespeed){
  dlytime = strobespeed * 1000;
  segAllOn2(timeOn);
  // set dlytime back to normal for the next function
  dlytime = 100;
}

void innerEyeOnFull(unsigned long duration){
  unsigned long inittime = millis();
  unsigned long fintime = inittime + duration;
  unsigned long currtime  = 0;
  while(currtime < fintime){
  led11On();
  led12On();
  led13On();
  led14On();
  led15On();
  led16On();
  led17On();
  led18On();
  led19On();
  currtime = millis();
  }
}

void outerEyeOnFull(unsigned long duration){
  unsigned long inittime = millis();
  unsigned long fintime = inittime + duration;
  unsigned long currtime  = 0;
  while(currtime < fintime){
  led1On();
  led2On();
  led3On();
  led4On();
  led5On();
  led6On();
  led7On();
  led8On();
  led9On();
  led10On();
  currtime = millis();
  }
}

void edgesOnFull(unsigned long duration){
  unsigned long inittime = millis();
  unsigned long fintime = inittime + duration;
  unsigned long currtime  = 0;
  while(currtime < fintime){
  led20On();
  led21On();
  led22On();
  led23On();
  led24On();
  led25On();
  currtime = millis();
  }
}


// Turns on the whole outer eye in sequence.
void outerEyeOnInSequence(word duration, word tbetween){
  unsigned long inittime = millis();
  unsigned long fintime = inittime + duration;
  unsigned long currtime = 0;
  while(currtime < fintime){
  led1On();
  if(millis() > (inittime + (tbetween * 1))){
    led2On();
  }
  if(millis() > (inittime + (tbetween * 2))){
    led3On();
  }
  if(millis() > (inittime + (tbetween * 3))){
    led4On();
  }
  if(millis() > (inittime + (tbetween * 4))){
    led5On();
  }
  if(millis() > (inittime + (tbetween * 5))){
    led6On();
  }
  if(millis() > (inittime + (tbetween * 6))){
    led7On();
  }
  if(millis() > (inittime + (tbetween * 7))){
    led8On();
  }
  if(millis() > (inittime + (tbetween * 8))){
    led9On();
  }
  if(millis() > (inittime + (tbetween * 9))){
    led10On();
  }
  currtime = millis();
  }
}

// Turns on the entire inner eye in sequence.
void innerEyeOnInSequence(word duration, word tbetween){
  unsigned long inittime = millis();
  unsigned long fintime = inittime + duration;
  unsigned long currtime = 0;
  while(currtime < fintime){
  led11On();
  if(millis() > (inittime + (tbetween * 1))){
    led12On();
  }
  if(millis() > (inittime + (tbetween * 2))){
    led13On();
  }
  if(millis() > (inittime + (tbetween * 3))){
    led14On();
  }
  if(millis() > (inittime + (tbetween * 4))){
    led15On();
  }
  if(millis() > (inittime + (tbetween * 5))){
    led16On();
  }
  if(millis() > (inittime + (tbetween * 6))){
    led17On();
  }
  if(millis() > (inittime + (tbetween * 7))){
    led18On();
  }
  if(millis() > (inittime + (tbetween * 8))){
    led19On();
  }
  currtime = millis();
  }
}

// Turns on the edges in sequence.
void edgesOnInSequence(word duration, word tbetween){
  unsigned long inittime = millis();
  unsigned long fintime = inittime + duration;
  unsigned long currtime = 0;
  while(currtime < fintime){
  led20On();
  if(millis() > (inittime + (tbetween * 1))){
    led21On();
  }
  if(millis() > (inittime + (tbetween * 2))){
    led22On();
  }
  if(millis() > (inittime + (tbetween * 3))){
    led23On();
  }
  if(millis() > (inittime + (tbetween * 4))){
    led24On();
  }
  if(millis() > (inittime + (tbetween * 5))){
    led25On();
  }
  currtime = millis();
  }
}

void fullEyeOnInSequence(word duration, word tbetween){
  unsigned long inittime = millis();
  unsigned long fintime = inittime + duration;
  unsigned long currtime = 0;
  while(currtime < fintime){
  led1On();
  if(millis() > (inittime + (tbetween * 1))){
    led2On();
  }
  if(millis() > (inittime + (tbetween * 2))){
    led3On();
  }
  if(millis() > (inittime + (tbetween * 3))){
    led4On();
  }
  if(millis() > (inittime + (tbetween * 4))){
    led5On();
  }
  if(millis() > (inittime + (tbetween * 5))){
    led6On();
  }
  if(millis() > (inittime + (tbetween * 6))){
    led7On();
  }
  if(millis() > (inittime + (tbetween * 7))){
    led8On();
  }
  if(millis() > (inittime + (tbetween * 8))){
    led9On();
  }
  if(millis() > (inittime + (tbetween * 9))){
    led10On();
  }
  if(millis() > (inittime + (tbetween * 10))){
    led11On();
  }
  if(millis() > (inittime + (tbetween * 11))){
    led12On();
  }
  if(millis() > (inittime + (tbetween * 12))){
    led13On();
  }
  if(millis() > (inittime + (tbetween * 13))){
    led14On();
  }
  if(millis() > (inittime + (tbetween * 14))){
    led15On();
  }
  if(millis() > (inittime + (tbetween * 15))){
    led16On();
  }
  if(millis() > (inittime + (tbetween * 16))){
    led17On();
  }
  if(millis() > (inittime + (tbetween * 17))){
    led18On();
  }
  if(millis() > (inittime + (tbetween * 18))){
    led19On();
  }
  currtime = millis();
  }
}

void spiralPattern1(int repeats){
  int repcnt = 0;
  while(repcnt < repeats){
    flashPattern1(30, 2.5);
    segAllOn1(100);
    repcnt += 1;
  }
}

void winkPatternExteriorFull(word duration, word tbetween){
  unsigned long inittime = millis();
  unsigned long fintime = inittime + duration;
  unsigned long currtime  = 0;
  while(currtime < fintime){
    led11On();
    led12On();
    led13On();
    led14On();
    led15On();
    led16On();
    led17On();
    led18On();
    led19On();
  if(millis() < (inittime + (tbetween * 1))){
    led1On();
    led2On();
    led3On();
    led4On();
    led5On();
    led6On();
    led7On();
    led8On();
    led9On();
    led10On();
  }
  if(millis() < (inittime + (tbetween * 2))){
    led2On();
    led3On();
    led4On();
    led5On();
    led6On();
    led7On();
    led8On();
    led9On();
    led10On();
  }
  if(millis() < (inittime + (tbetween * 3))){
    led3On();
    led4On();
    led5On();
    led6On();
    led7On();
    led8On();
    led9On();
  }
  if(millis() < (inittime + (tbetween * 4))){
    led4On();
    led5On();
    led6On();
    led7On();
    led8On();
  }
  if(millis() < (inittime + (tbetween * 5))){
    led5On();
    led6On();
    led7On();
  }
  if(millis() < (inittime + (tbetween * 6))){
    led6On();
  }
  if(millis() > (inittime + (tbetween * 7))){
    led5On();
    led6On();
    led7On();
  }
  if(millis() > (inittime + (tbetween * 8))){
    led4On();
    led5On();
    led6On();
    led7On();
    led8On();
  }
  if(millis() > (inittime + (tbetween * 9))){
    led3On();
    led4On();
    led5On();
    led6On();
    led7On();
    led8On();
    led9On();
  }
  if(millis() > (inittime + (tbetween * 10))){
    led2On();
    led3On();
    led4On();
    led5On();
    led6On();
    led7On();
    led8On();
    led9On();
    led10On();
  }
  if(millis() > (inittime + (tbetween * 11))){
    led1On();
    led2On();
    led3On();
    led4On();
    led5On();
    led6On();
    led7On();
    led8On();
    led9On();
    led10On();
  }
  currtime = millis();
  }
}

void winkPatternHalf(word duration, word tbetween){
  unsigned long inittime = millis();
  unsigned long fintime = inittime + duration;
  unsigned long currtime  = 0;
  while(currtime < fintime){
  if(millis() < (inittime + (tbetween * 1))){
    led2On();
    led3On();
    led4On();
    led5On();
    led6On();
    led7On();
    led8On();
    led9On();
    led10On();
    led11On();
    led12On();
    led13On();
    led14On();
    led15On();
    led16On();
    led17On();
    led18On();
    led19On();
  }
  if(millis() < (inittime + (tbetween * 2))){
    led3On();
    led4On();
    led5On();
    led6On();
    led7On();
    led8On();
    led9On();
    led11On();
    led12On();
    led13On();
    led14On();
    led15On();
    led16On();
    led17On();
    led18On();
    led19On();
  }
  if(millis() < (inittime + (tbetween * 3))){
    led3On();
    led4On();
    led5On();
    led6On();
    led7On();
    led8On();
    led9On();
    led12On();
    led13On();
    led14On();
    led15On();
    led16On();
    led17On();
    led18On();
    led19On();
  }
  if(millis() < (inittime + (tbetween * 4))){
    led4On();
    led5On();
    led6On();
    led7On();
    led8On();
    led13On();
    led14On();
    led15On();
    led16On();
    led17On();
    led19On();
  }
  if(millis() < (inittime + (tbetween * 5))){
    led4On();
    led5On();
    led6On();
    led7On();
    led8On();
    led14On();
    led15On();
    led16On();
  }
  if(millis() < (inittime + (tbetween * 6))){
    led5On();
    led6On();
    led7On();
    led15On();
  }
  if(millis() < (inittime + (tbetween * 7))){
    led5On();
    led6On();
    led7On();
  }
  if(millis() < (inittime + (tbetween * 8))){
    led6On();
  } 
  currtime = millis();
  }
}


/* Arguments: LEDNo - The address of the LED to be used
 *  duration - length of time on in milliseconds
 */
void indLEDOn(byte LEDNo, word duration){
  unsigned long inittime = millis();
  unsigned long fintime = inittime + duration;
  unsigned long currtime  = 0;
  switch(LEDNo){
    case 1:
    while(currtime < fintime){
      led1On();
      currtime = millis();
    }
    break;
    case 2:
    while(currtime < fintime){
      led2On();
      currtime = millis();
    }
    break;
    case 3:
    while(currtime < fintime){
      led3On();
      currtime = millis();
    }
    break;
    case 4:
    while(currtime < fintime){
      led4On();
      currtime = millis();
    }
    break;
    case 5:
    while(currtime < fintime){
      led5On();
      currtime = millis();
    }
    break;
    case 6:
    while(currtime < fintime){
      led6On();
      currtime = millis();
    }
    break;
    case 7:
    while(currtime < fintime){
      led7On();
      currtime = millis();
    }
    break;
    case 8:
    while(currtime < fintime){
      led8On();
      currtime = millis();
    }
    break;
    case 9:
    while(currtime < fintime){
      led9On();
      currtime = millis();
    }
    break;
    case 10:
     while(currtime < fintime){
      led10On();
      currtime = millis();
    }
    break;
    case 11:
     while(currtime < fintime){
      led11On();
      currtime = millis();
    }
    break;
    case 12:
     while(currtime < fintime){
      led12On();
      currtime = millis();
    }
    break;
    case 13:
     while(currtime < fintime){
      led13On();
      currtime = millis();
    }
    break;
    case 14:
     while(currtime < fintime){
      led14On();
      currtime = millis();
    }
    break;
    case 15:
     while(currtime < fintime){
      led15On();
      currtime = millis();
    }
    break;
    case 16:
     while(currtime < fintime){
      led16On();
      currtime = millis();
    }
    break;
    case 17:
     while(currtime < fintime){
      led17On();
      currtime = millis();
    }
    break;
    case 18:
     while(currtime < fintime){
      led18On();
      currtime = millis();
    }
    break;
    case 19:
     while(currtime < fintime){
      led19On();
      currtime = millis();
    }
    break;
    case 20:
     while(currtime < fintime){
      led20On();
      currtime = millis();
    }
    break;
    case 21:
     while(currtime < fintime){
      led21On();
      currtime = millis();
    }
    break;
    case 22:
     while(currtime < fintime){
      led22On();
      currtime = millis();
    }
    break;
    case 23:
     while(currtime < fintime){
      led23On();
      currtime = millis();
    }
    break;
    case 24:
     while(currtime < fintime){
      led24On();
      currtime = millis();
    }
    break;
    case 25:
     while(currtime < fintime){
      led25On();
      currtime = millis();
    }
    break;
  }
}

void writeX(word duration){
  unsigned long inittime = millis();
  unsigned long fintime = inittime + duration;
  unsigned long currtime  = 0;
  while(currtime < fintime){
    led2On();
    led5On();
    led12On();
    led19On();
    led16On();
    led7On();
    led10On();
    led14On();
    led18On();
    currtime = millis();
  }
}

void sideWipeRL(word duration, word tbetween){
  unsigned long inittime = millis();
  unsigned long fintime = inittime + duration;
  unsigned long currtime  = 0;
  while(currtime < fintime){
  if(millis() > (inittime) && millis() < (inittime + (tbetween * 1))){
    led3On();
    led4On();
  }
  if(millis() > (inittime + (tbetween * 1)) && millis() < (inittime + (tbetween * 2))){
    led2On();
    led5On();
    led13On();
  }
  if(millis() > (inittime + (tbetween * 2)) && millis() < (inittime + (tbetween * 3))){
    led12On();
    led14On();
  }
  if(millis() > (inittime + (tbetween * 3)) && millis() < (inittime + (tbetween * 4))){
    led1On();
    led11On();
    led19On();
    led15On();
    led6On();
  }
  if(millis() > (inittime + (tbetween * 4)) && millis() < (inittime + (tbetween * 5))){
    led16On();
    led18On();
  }
  if(millis() > (inittime + (tbetween * 5)) && millis() < (inittime + (tbetween * 6))){
    led10On();
    led17On();
    led7On();
  }
  if(millis() > (inittime + (tbetween * 6)) && millis() < (inittime + (tbetween * 7))){
    led8On();
    led9On();
  } 
  currtime = millis();
  }
}

void sideWipeLR(word duration, word tbetween){
  unsigned long inittime = millis();
  unsigned long fintime = inittime + duration;
  unsigned long currtime  = 0;
  while(currtime < fintime){
  if(millis() > (inittime) && millis() < (inittime + (tbetween * 1))){
    led8On();
    led9On();
  }
  if(millis() > (inittime + (tbetween * 1)) && millis() < (inittime + (tbetween * 2))){
    led7On();
    led10On();
    led17On();
  }
  if(millis() > (inittime + (tbetween * 2)) && millis() < (inittime + (tbetween * 3))){
    led16On();
    led18On();
  }
  if(millis() > (inittime + (tbetween * 3)) && millis() < (inittime + (tbetween * 4))){
    led1On();
    led11On();
    led19On();
    led15On();
    led6On();
  }
  if(millis() > (inittime + (tbetween * 4)) && millis() < (inittime + (tbetween * 5))){
    led12On();
    led14On();
  }
  if(millis() > (inittime + (tbetween * 5)) && millis() < (inittime + (tbetween * 6))){
    led2On();
    led5On();
    led13On();
  }
  if(millis() > (inittime + (tbetween * 6)) && millis() < (inittime + (tbetween * 7))){
    led3On();
    led4On();
  } 
  currtime = millis();
  }
}

void indLEDLoop(word duration){
  indLEDOn(1,duration);
  indLEDOn(2,duration);
  indLEDOn(3,duration);
  indLEDOn(4,duration);
  indLEDOn(5,duration);
  indLEDOn(6,duration);
  indLEDOn(7,duration);
  indLEDOn(8,duration);
  indLEDOn(9,duration);
  indLEDOn(10,duration);
  indLEDOn(11,duration);
  indLEDOn(12,duration);
  indLEDOn(13,duration);
  indLEDOn(14,duration);
  indLEDOn(15,duration);
  indLEDOn(16,duration);
  indLEDOn(17,duration);
  indLEDOn(18,duration);
  indLEDOn(19,duration);
  indLEDOn(20,duration);
  indLEDOn(21,duration);
  indLEDOn(22,duration);
  indLEDOn(23,duration);
  indLEDOn(24,duration);
  indLEDOn(25,duration);
}

void loop() {
  segAllOn1(2000);
  sideWipeRL(400,40);
  sideWipeLR(400,40);
  spiralPattern1(3);
  segAllOn1(500);
  flashPattern1(10, 2.5);
  segAllOn1(2000);
  flashPattern2(100,2.5);
  flashPattern2(100,2.5);
  segAllOn1(2000);
  outerEyeOnFull(1000);
  innerEyeOnFull(2000);
  segAllOn1(500);
  winkPatternHalf(1200,75);
  innerEyeOnInSequence(750,25);
  winkPatternExteriorFull(3000,100);
  fullEyeOnInSequence(1500,50);
  strobePattern2(3000, 15);
  flashPattern3(400,100,1000);
  segAllOn1(2000);
  strobePattern1(3000, 10);
  segAllOn1(1000);
  strobePattern2(100, 5);
  segAllOn1(1000);
  outerEyeOnInSequence(1500,100);
  strobePattern1(3000, 4);
  flashPattern1(10, 2.5);
  flashPattern2(100, 2.5);
  flashPattern2(10, 2.5);
  indLEDOn(19,3000);
  innerEyeOnFull(500);
  segAllOn1(500);
  indLEDOn(19,500);
  innerEyeOnFull(500);
  segAllOn1(500);
  writeX(1000);
  outerEyeOnFull(1000);
  writeX(1000);
  outerEyeOnFull(1000);
  writeX(1000);
  outerEyeOnFull(1000);
  sideWipeRL(400,40);
  sideWipeLR(400,40);
  sideWipeRL(400,40);
  sideWipeLR(400,40);
  strobePattern2(3000, 15);
  segAllOn1(2000);
  winkPatternHalf(1200,75);
  indLEDLoop(50);
  indLEDLoop(50);
  indLEDLoop(50);
  winkPatternHalf(1200,75);
  flashPattern1(500, 2.5);
  flashPattern1(500, 2.5);
}
