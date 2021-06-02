# Smart_Dustbin
A smart dustbin who automatically segregate dry and wet garbage and notify authority when the dustbin is full. 
Features:
1. It has IR and moisture sensor for detecting garbage and its type.
2. It contains  LCD for displaying current status and type of garbage to local people.
3. It contains Ultrasonic sensor(2) to check the level of garbage in the dustbin.
4. It contains ServoMotor for flipping garbage in wet/dry dustbin. 
5. It contains Wifi Module NodeMCU ESP8266 for sending notifications when a dustbin gets full. 
6. It is also linked with the Blynk app.

Functioning:
With the help of an IR sensor our smart dustbin will detect whether garbage has been kept or not, after detecting garbage with the help of a moisture sensor it will detect the type of garbage. 
After detecting the type of garbage with the help of a servo motor our smart dustbin will flip the garbage in respective wet or dry dustbin, simultaneously showing all information on LCD Screen as well.
For observing the level of garbage we have used ultrasonic sensors.
We will get notified with the help of ESP8266 nodeMCU module and also with the Blynk app.
