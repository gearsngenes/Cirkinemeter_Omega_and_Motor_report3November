//--------------------------------------------------Calculate the angular velocity
void getRPS(){
  omega= theta/((float)(endTime-startTime)/1000.0);  //Angle traveled (2pi) over delta time (delta t/1000 to convert milliseconds to seconds)
  Serial.print("Omega(rad/sec):"); Serial.println(omega); //Print Omega value
}


//------------------------Timing the Revolution------------------------
void detectAndTime(){
  //Visual Indicator of the built in LED
  if(sensState1==HIGH){  //if transmitter detected, turn on LED
    digitalWrite(LEDPIN, HIGH);
  }

  else{
    digitalWrite(LEDPIN, LOW);  //else LED is off
  }
  
  //-------------------------Timing Logic----------------------------
  if (sensState1 && !lastState1) {  //If the Sensor CHANGES its signal (low to high) then record the time (endtime)
   endTime=millis();  //RECORD THE TIME in MILLISECONDS
   Serial.print("start: ");Serial.print(startTime);Serial.print(" end: "); Serial.println(endTime); //print times
   
   getRPS();  //CALCULATE OMEGA once the endtime is found
   oledPrint();  //PRINT OMEGA ON the OLED once entime is found
   Serial.println("--------------------------");
  } 
  
  if (!sensState1 && lastState1) {  //If the receiver does NOT change its digital value (stays low), do nothing
  }
  startTime=endTime;  //Every Time the Transmitter is detected, the NEXT starting time of the revolution becomes the CURRENT end time
  //NOTE: start time is initially set to 0, so the first reading will not be accurate, but succeeding revolutions WILL be
  
  lastState1 = sensState1;  //Everytime the Transmitter is detected, the sensor's previous state is set equal to the current state
}


