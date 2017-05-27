/*
                   Copyright (c) 2017 Conor Walsh
                  Website: http://www.conorwalsh.net
                GitHub:  https://github.com/conorwalsh
                        Project: LED Post Box
                              MIT LICENCE
    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:
    
    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.
    
    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
    _____      ____                        __        __    _     _       ____   ___  _ _____ 
   / ___ \    / ___|___  _ __   ___  _ __  \ \      / /_ _| |___| |__   |___ \ / _ \/ |___  |
  / / __| \  | |   / _ \| '_ \ / _ \| '__|  \ \ /\ / / _` | / __| '_ \    __) | | | | |  / / 
 | | (__   | | |__| (_) | | | | (_) | |      \ V  V / (_| | \__ \ | | |  / __/| |_| | | / /  
  \ \___| /   \____\___/|_| |_|\___/|_|       \_/\_/ \__,_|_|___/_| |_| |_____|\___/|_|/_/   
   \_____/                                                                                   
 */

//Declare switch Pin No
const int switchPin = 2;
//Declare Red LED Pin No
const int redLed =  3;
//Declare Green (or Blue) LED Pin No 
const int greenLed =  4;
//Declare the number of hours before reset
const int resetHours = 12;
//Calculate reset time in milliseconds
int resetTime = 1000 * 60 * 60 * resetHours;

void setup() {
  //Declare inputs and outputs
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(switchPin, INPUT);

  //Set the LED starting values
  digitalWrite(redLed, HIGH);
  digitalWrite(greenLed, LOW);
}

void loop() {
  //If the post box is open (Switch closed)
  if (digitalRead(switchPin) == HIGH) {
    //Wait for 500 milliseconds (debounce - prevent false positives)
    delay(500);
    //If the post box is still open (Switch closed)
    if (digitalRead(switchPin) == HIGH) {
      //Swap the LED values (Post in box)
      digitalWrite(redLed, LOW);
      digitalWrite(greenLed, HIGH);
      //Wait for the specified reset time
      delay(resetTime);
      //Swap the LED values (Reset)
      digitalWrite(redLed, HIGH);
      digitalWrite(greenLed, LOW);
    }
  }
  //Wait 500 milliseconds before running loop again (Prvent damage to microcontroller)
  delay(500);
}
