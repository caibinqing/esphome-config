#include "esphome.h"

#define LED_ON HIGH
#define LED_OFF LOW

class GateSwitch : public Component, public Switch {
public:
  int phone = 25;
  int lock = 26;
  int led = 2;

  void setup() override {
    pinMode(phone, OUTPUT);
    pinMode(lock, OUTPUT);
    pinMode(led, OUTPUT);
    digitalWrite(led, LED_OFF);
  }

  void write_state(bool state) override {
    if (state) {

      publish_state(state);

      // ESP_LOGD("gate_switch", "write_state START!");

      digitalWrite(led, LED_ON);
      digitalWrite(phone, HIGH);
      delay(600);
      digitalWrite(led, LED_OFF);
      digitalWrite(lock, HIGH);
      delay(250);
      digitalWrite(led, LED_ON);
      digitalWrite(lock, LOW);
      delay(1250);
      digitalWrite(led, LED_OFF);
      digitalWrite(phone, LOW);

      // ESP_LOGD("gate_switch", "write_state DONE!");

      delay(500);
      publish_state(false);

    }
  }
};
