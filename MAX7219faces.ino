#include <LedControl.h>

// Pin definitions
const int dataIn = 12;
const int clk = 11;
const int load = 10;
const int numDevices = 1;  // Number of MAX7219 devices connected

// Create the LedControl object
LedControl lc = LedControl(dataIn, clk, load, numDevices);

// Define the face patterns (8x8 matrix)

byte happyFace[8] = {
  0b00000000,
  0b01100110,
  0b01100110,
  0b00000000,
  0b01000010,
  0b01111110,
  0b00000000,
  0b00000000
};

byte blankFace[8] = {
  0b00000000,
  0b01100110,
  0b01100110,
  0b00000000,
  0b00000000,
  0b01111110,
  0b00000000,
  0b00000000
};

byte sadFace[8] = {
  0b00000000,
  0b01100110,
  0b01100110,
  0b00000000,
  0b01111110,
  0b01000010,
  0b00000000,
  0b00000000
};

void setup() {
  // Initialize the MAX7219
  for (int i = 0; i < numDevices; i++) {
    lc.shutdown(i, false);  // Wake up MAX7219
    lc.setIntensity(i, 8);   // Set brightness (0-15)
    lc.clearDisplay(i);      // Clear display
  }
}

void loop() {
  // Display the faces
  displayFace(happyFace);
  delay(2000);  // Delay for 2 seconds
  
  displayFace(blankFace);
  delay(2000);  // Delay for 2 seconds
  
  displayFace(sadFace);
  delay(2000);  // Delay for 2 seconds
}

// Function to display a face on the LED matrix
void displayFace(byte face[8]) {
  for (int row = 0; row < 8; row++) {
    lc.setRow(0, row, face[row]);  // Display each row on the LED matrix
  }
}

