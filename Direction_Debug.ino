void directiontest(){ //Test to see if the input from the Joystick is working
  if(xval>700){
    Serial.println("counterclockwise");
  }
  else if(xval<300){
    Serial.println("clockwise");
  }
}

