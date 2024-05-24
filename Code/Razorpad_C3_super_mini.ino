//  Bluetooth Controller for ESP32
//    Based on work by NordicRally, Martin Romero @MartinRV84, Thomas Styles @StylesRallyIndustries, JaxeADV

// Include Libraries
#include "esp_bt_main.h"
#include "esp_bt_device.h"
#include "esp_gap_bt_api.h"
#include <BleKeyboard.h>                                       // bleKeyboard
#include <Bounce2.h>                                           // Bounce


// Set Bluetooth Device Name
BleKeyboard BleKeyboard("DMD2 CTL 8K", "Razorbac", 69);
// BleKeyboard BleKeyboard("PutHereTheNameYouLike", "Razorbac", 69); the DMD2 remote selection settings seems to be back, so you can now choose the name of remote

// ESP32 DEVKITV1
int Button1 = 5; //UP
int Button2 = 6; //DOWN
int Button3 = 7; //LEFT
int Button4 = 2; //RIGHT
int Button5 = 9; //ENTER
int Button6 = 10; //F5 / BACK
int Button7 = 4; //F6 / ZOOM +
int Button8 = 3; //F7 / ZOOM -


// 0 to view all bonded devices addresses, 1 to remove
#define REMOVE_BONDED_DEVICES 0
// default 3, max 9
#define PAIR_MAX_DEVICES 9
// Buttons and position {0, 1, 2, 3}
#define NUM_BUTTONS 8
const uint8_t BUTTON_PINS[NUM_BUTTONS] = {Button1, Button2, Button3, Button4, Button5, Button6, Button7, Button8};

int period = 1000;
unsigned long time_now = 0;

const int delayBetweenHIDReports = 5; // Additional delay in milliseconds between HID reports
const int debounceDelay = 10;        // Delay in milliseconds between button press

int previousButton1State = HIGH;
int previousButton2State = HIGH;
int previousButton3State = HIGH;
int previousButton4State = HIGH;
int previousButton5State = HIGH;
int previousButton6State = HIGH;
int previousButton7State = HIGH;
int previousButton8State = HIGH;


// BT Initialisation
bool initBluetooth() {
  if (!btStart()) {
    Serial.println("! Failed to initialise btStart !");
    return false;
  }

  if (esp_bluedroid_init() != ESP_OK) {
    Serial.println("! Failed to initialise bluedroid !");
    return false;
  }

  if (esp_bluedroid_enable() != ESP_OK) {
    Serial.println("! Failed to enable bluedroid !");
    return false;
  }
  return true;
}

// Format BT Device Addresses
uint8_t pairedDeviceBtAddr[PAIR_MAX_DEVICES][6];
char bda_str[18];
char *bda2str(const uint8_t* bda, char *str, size_t size) {
  if (bda == NULL || str == NULL || size < 18) {
    return NULL;
  }
  sprintf(str, "%02x:%02x:%02x:%02x:%02x:%02x",
          bda[0], bda[1], bda[2], bda[3], bda[4], bda[5]);
  return str;
}

// Bounce config
Bounce * buttons = new Bounce[NUM_BUTTONS];

// Setup, runs once
void setup() {
  // Serial
  Serial.begin(115200);
  Serial.println("Avvio RazorPad C3");
  // bleKeyboard
  BleKeyboard.begin();
  Serial.println("Componente BleKeyboard Avviato");
  // Set pullup mode and bounce interval in ms
  for (int i = 0; i < NUM_BUTTONS; i++) {
    buttons[i].attach( BUTTON_PINS[i] , INPUT_PULLUP  );
    buttons[i].interval(100);
  }
  Serial.println("RazorPad C3 Avviato");
}

// Loop, runs constantly
void loop() {

 
  if (BleKeyboard.isConnected()) {
	  
    int currentButton1State = digitalRead(Button1);
    int currentButton2State = digitalRead(Button2);
    int currentButton3State = digitalRead(Button3);
    int currentButton4State = digitalRead(Button4);
    int currentButton5State = digitalRead(Button5);
    int currentButton6State = digitalRead(Button6);
    int currentButton7State = digitalRead(Button7);
    int currentButton8State = digitalRead(Button8);

    if (currentButton1State != previousButton1State) { 
      if (currentButton1State == LOW) {
        BleKeyboard.press(KEY_UP_ARROW);
        Serial.println("Su Premuto");
    }
      else
        BleKeyboard.release(KEY_UP_ARROW);
    }
    previousButton1State = currentButton1State;

    if (currentButton2State != previousButton2State) {
      if (currentButton2State == LOW) {
        BleKeyboard.press(KEY_DOWN_ARROW);
        Serial.println("Giù Premuto");
      }
      else
        BleKeyboard.release(KEY_DOWN_ARROW);
    }
    previousButton2State = currentButton2State;

    if (currentButton3State != previousButton3State) {
      if (currentButton3State == LOW) {
        BleKeyboard.press(KEY_LEFT_ARROW);
        Serial.println("Sinistra Premuto");
      }
      else
        BleKeyboard.release(KEY_LEFT_ARROW);
    }
    previousButton3State = currentButton3State;

    if (currentButton4State != previousButton4State) {
      if (currentButton4State == LOW){
        BleKeyboard.press(KEY_RIGHT_ARROW);
        Serial.println("Destra Premuto");
      }
      else
        BleKeyboard.release(KEY_RIGHT_ARROW);
    }
    previousButton4State = currentButton4State;

    if (currentButton5State != previousButton5State) {
      if (currentButton5State == LOW) {
        BleKeyboard.press(KEY_RETURN);
        Serial.println("Enter Premuto");
      }
      else
        BleKeyboard.release(KEY_RETURN);
    }
    previousButton5State = currentButton5State;

    if (currentButton6State != previousButton6State) {
      if (currentButton6State == LOW) {
        BleKeyboard.press(KEY_F5);
        Serial.println("Back / F5 Premuto");
      }
      else
        BleKeyboard.release(KEY_F5);
    }
    previousButton6State = currentButton6State;

    if (currentButton7State != previousButton7State) {
      if (currentButton7State == LOW) {
        BleKeyboard.press(KEY_F6);
        Serial.println("F6 Zoom + Premuto");
      }
      else
        BleKeyboard.release(KEY_F6);
    }
    previousButton7State = currentButton7State;

    if (currentButton8State != previousButton8State) {
      if (currentButton8State == LOW) {
        BleKeyboard.press(KEY_F7);
        Serial.println("F7 Zoom - Premuto");
      }
      else
        BleKeyboard.release(KEY_F7);
    }
    previousButton8State = currentButton8State;
  }
  // Update the Bounce instance
  for (int i = 0; i < NUM_BUTTONS; i++)  {
    buttons[i].update();
  }
}
