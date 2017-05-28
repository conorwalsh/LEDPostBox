# LED Post Box

Description
-----------

This project uses an Arduino Nano to add LEDs to a post box to alert the user to when there is post in the box. An Post (Ireland's National Mail Carrier) recently introduced the new "<a href="http://anpost.ie/deliverybox" target="_blank">DeliveryBox</a>" which is a post box that can take parcels as well as letters. The post worker puts all your post in the box and scans the box which sends you an email. However I wanted a quick visual indicator to alert me when I passed the postbox that there was post that day. This project uses a limit switch to determine when the box is opened (post delivered) and then lights LEDs according. The LEDs are reset after a specified period of time. This project was specifically designed for an Irish "DeliveryBox" but the project could be adapted for most international mail boxes.

Project Steps
---------
1. Build the circuit using the schematics provided below.
2. Download the Arduino code from the "arduino_code" folder.
3. If you want you can edit <a href="https://github.com/conorwalsh/LEDPostBox/blob/master/arduino_code/arduinopostbox.ino#L39">Line 39</a> and specify your preferred reset time in the Arduino code.
4. Upload Arduino code to the Arduino.
5. Fit the device to your postbox.

Schematics
-----------

Breadboard View:<br/>
<img src="https://github.com/conorwalsh/LEDPostBox/blob/master/schematics/postbox_bb.png" width="350"/>

Schematic View:<br/>
<img src="https://github.com/conorwalsh/LEDPostBox/blob/master/schematics/postbox_schem.png" width="350"/></br>
NOTE: The diode on the power connector is used to prevent reverse voltage. If a barrel connector is used the diode may not be required but I designed my connectors with header pins because it is an easy way to quickly make connectors but it is easy to accidently plug the power in incorrectly. This diode is included to protect the Arduino however it can be ommitted if you desire.

Operation
-----------------------
The system uses a normally closed limit switch, so that when the box is closed the switch is pushed in and the circuit is broken but when the box opens the switch is no longer pushed in and the switch closes.<br/>
When the Arduino detects that the switch has been closed for more than 500 milliseconds it turns on a green (or blue) LED to alert the user.<br/>
After a specified length of time the Arduino resets the system with a red LED on and the other LED off, to indicate that there is no post. Hopefully the residents will have removed the post before then.<br/>
You could change the code so that it toggles the LEDs when the box is opened but if the post is not collected the same day it will interfere with the system.<br/>

Possible Improvements
-----------------------
* Add a Real Time Clock (RTC) and have it reset at a specified time e.g. 2 am (I didn't have an RTC available when I built this).
* Add "Smart" capabilities to send an email or SMS when post is delivered (I didn't have to do this as the carrier already sends an email when post is delivered).
* Rechargeable battery system, possibly using a solar panel (I had to run power to my postbox!). I measured the power usage from my system and it was 1.4 Watts (Yours may be less as this included the AC -> DC transformer). This system uses 12.264kWh per year which would cost roughly between €1.50 and €2 to run for the year (depending on your unit price).
* I couldn't find bright green LEDs that's why the colours are red and blue as I had bright LEDs in those colours.

Circuitry Photos
-----------------------
Arduino Nano (Chinese Clone) with soldered connectors:<br/>
<img src="https://github.com/conorwalsh/LEDPostBox/blob/master/images/IMG_20170518_085043155_BURST000_COVER_TOP.jpg" width="400"/>
<img src="https://github.com/conorwalsh/LEDPostBox/blob/master/images/IMG_20170518_085048447.jpg" width="400"/>

Arduino Nano in project box:<br/>
<img src="https://github.com/conorwalsh/LEDPostBox/blob/master/images/IMG_20170518_085028335.jpg" width="400"/>

LEDs and Switch soldered with connectors:<br/>
<img src="https://github.com/conorwalsh/LEDPostBox/blob/master/images/IMG_20170518_085109958.jpg" width="400"/>

Transformer fitted with new cable and connector to get power from attic through duct to the postbox:<br/>
<img src="https://github.com/conorwalsh/LEDPostBox/blob/master/images/IMG_20170518_085113832.jpg" width="400"/>

Photos of fully fitted project
-----------------------
LEDs fitted in the side of the postbox:<br/>
<img src="https://github.com/conorwalsh/LEDPostBox/blob/master/images/IMG_20170527_162059568-s.jpg" width="400"/>

Switch fitted in postbox:<br/>
<img src="https://github.com/conorwalsh/LEDPostBox/blob/master/images/IMG_20170527_162239818.jpg" height="400"/>
<img src="https://github.com/conorwalsh/LEDPostBox/blob/master/images/IMG_20170527_162222991-s.jpg" width="400"/>

Project box and wires taped to the inside of the postbox:<br/>
<img src="https://github.com/conorwalsh/LEDPostBox/blob/master/images/IMG_20170527_162246335-s.jpg" width="400"/>

Postbox in operation:<br/>
<img src="https://github.com/conorwalsh/LEDPostBox/blob/master/images/IMG_20170527_162116038.jpg" height="400"/>
<img src="https://github.com/conorwalsh/LEDPostBox/blob/master/images/IMG_20170527_162302764.jpg" height="400"/>

License (MIT)
------
Copyright (c) 2017 Conor Walsh 

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

Thanks
------

Thank you for taking the time to look at this project I hope that it is of use to you,<br/>
<img src="http://conorwalsh.net/sig.png" /><br/>
Conor Walsh.
