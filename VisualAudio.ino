#include <Wire.h>
#include <SoftwareSerial.h>
#include "DFRobotDFPlayerMini.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <LedControl.h>

//Macros
//  Create the Player object
DFRobotDFPlayerMini player;
//  Use pins 2 and 3 to communicate with DFPlayer Mini
static const uint8_t PIN_MP3_TX  = 2; // Connects to module's RX 
static const uint8_t PIN_MP3_RX = 3; // Connects  to module's TX 
SoftwareSerial softwareSerial(PIN_MP3_RX, PIN_MP3_TX);

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Define pins for MAX72XX LED Matrix
#define DIN 12
#define CS 11
#define CLK 10

// Initialize LedControl object for MAX72XX LED Matrix
LedControl lc = LedControl(DIN, CLK, CS, 1);




// Define global variables
int visualizationMode; // Variable to store the current visualization mode
int trackNumber = 0;


void setup() {
  //Audio--------------------------------
  // Init USB serial port for debugging
  Serial.begin(9600);
  // Init serial  port for DFPlayer Mini
  softwareSerial.begin(9600);

  // Start communication  with DFPlayer Mini
  if (player.begin(softwareSerial)) {
   Serial.println("OK");

    // Set volume to maximum (0 to 30).
    player.volume(30);

    randomSeed(analogRead(0));
    trackNumber = 1;
    //random(1,4); // Assign a random value to trackNumber
 
    // ...
    // Play  
    player.play(trackNumber);
  } else {
    Serial.println("Connecting  to DFPlayer Mini failed!");
  }
  // Initiate the Wire library for I2C communication
  Wire.begin();

  //Display-----------------------------------
  // Initiate the OLED display
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }

  // Clear the display buffer
  display.clearDisplay();
  // Set text color to white
  display.setTextColor(SSD1306_WHITE);
  // Set text size
  display.setTextSize(1);
  // Set cursor position to (0,0)
  display.setCursor(0, 0);

  // Print the message on the screen
    switch (trackNumber) {
      case 1:
        display.println("21 Guns");
        display.println("Green Day");
        display.println("2010");
        display.println("Lay down your arms...");

        break;
      case 2:
        display.println("Sky is Over");
        display.println("Serj Tankian");
        display.println("2018");
        display.println("The sky is over...");
        break;
      case 3:
        display.println("Curse");
        display.println("XXX");
        display.println("2018");
        display.println("Check my clock...");
        break;
        default:
        break;
        
    }
  

  // Display the content on the screen
  display.display();
    // Initialize the MAX7219
  lc.shutdown(0, false);
  lc.setIntensity(0, 8);
  lc.clearDisplay(0);

Serial.println("TrackNumber:");
Serial.println(trackNumber);
}  

void loop() {
   //Update visualization based on current mode
    switch (trackNumber) {
    case 1:
        displayEqualizer();
      break;
    case 2:
        displaySpectrumAnalyzer();
      break;
    case 3:
        displayGun();
      break; // Add this break statement
    default:
      break;
  }
  }


//Visuals
void displayEqualizer() {
  // Example code for equalizer visualization on MAX72XX LED Matrix
  for (int i = 0; i < 8; i++) {
    lc.setRow(0, i, B11111111); // Turn on all LEDs in a row
    delay(50); // Adjust delay for desired animation speed
    lc.setRow(0, i, B00000000); // Turn off all LEDs in the same row
  }
}

//fix this
void displaySpectrumAnalyzer() {
  byte character[8] = {
  B00010000,
  B00010000,
  B10010000,
  B00010000,
  B00010000,
  B00010000,
  B00010000,
  B00010000
  };

  for (int row = 0; row < 8; row++) {
    lc.setRow(0, row, character[row]);
  }
 delay(1000);
  
  // Clear the display after the specified duration
  lc.clearDisplay(0);
  delay(1000); // Wait for the same duration before displaying again
}

void displayGun() {
  byte gun[8] = {
  B01111100,
  B00111110,
  B00011111,
  B00001111,
  B00011111,
  B00111110,
  B01111100,
  B00011000
  };

  for (int row = 0; row < 8; row++) {
    lc.setRow(0, row, gun[row]);
  }
  delay(1000);
  
  // Clear the display after the specified duration
  lc.clearDisplay(0);
  delay(1000); // Wait for the same duration before displaying again
}

