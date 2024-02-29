#include "esphome.h"

#define LED_ON HIGH
#define LED_OFF LOW

class ESP01GateSwitch : public Component, public Switch {
public:
  int phone = 0;
  int lock = 2;

  void setup() override {
    pinMode(phone, OUTPUT);
    pinMode(lock, OUTPUT);
  }

  void write_state(bool state) override {
    if (state) {

      publish_state(state);

      // ESP_LOGD("gate_switch", "write_state START!");

      digitalWrite(phone, HIGH);
      delay(600);
      digitalWrite(lock, HIGH);
      delay(250);
      digitalWrite(lock, LOW);
      delay(1250);
      digitalWrite(phone, LOW);

      // ESP_LOGD("gate_switch", "write_state DONE!");

      delay(500);
      publish_state(false);

    }
  }
};
