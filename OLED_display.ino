void oledSetup(){  //Necessary code to set up OLED's connections to the Feather
  Serial.println("OLED FeatherWing test");
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  Serial.println("OLED begun");
  display.display();
  delay(10);

  // Refreshes the screen of the OLED
  display.clearDisplay();
  display.display();
  
  Serial.println("IO test");


  // Sets up the text style, color, and intro text (GNG kinemADdicts)
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.print("GnG KinemAddicts");
  display.setCursor(0,0);
  display.display();
}

void oledPrint(){  //Print the values of Omega and RPS on the OLED screen
  //Text settings
  display.setTextSize(2);
  display.clearDisplay();
  display.setCursor(0,0);
  
  display.print("OMG:");display.println(omega,2); //Print the Omega Value
  display.print("RPS:"); display.println(omega/theta,2);  //Print the RPS value
  display.display();  //Sends commands to OLED (otherwise won't)

}
