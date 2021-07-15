SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);

#include "WatchDog_WCL.h"
WatchDog wd;

#include "oled-wing-adafruit.h"
OledWingAdafruit display;



// setup() runs once, when the device is first turned on.
void setup() {
  // Put initialization like pinMode and begin functions here.
  pinMode(D5, INPUT);
  wd.initialize(5000);

  display.setup();
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  
  display.display();
}


// loop() runs over and over again, as quickly as it can execute.
void loop() {
  display.loop();

  if (System.resetReason() == RESET_REASON_WATCHDOG){
    
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    display.display();
    display.println("Watchdog timer issue");
    display.display();
  }
  // The core of your code will likely live here.
  if (digitalRead(D5) == HIGH){
    wd.pet();
  }
  
}