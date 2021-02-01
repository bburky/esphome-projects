#include <BleKeyboard.h>

#include "esphome.h"

class Esp32BLEKeyboard : public PollingComponent {
   public:
    BleKeyboard bleKeyboard;
    BinarySensor *connected_binarysensor = new BinarySensor();
    TextSensor *textsensor = new TextSensor();

    Esp32BLEKeyboard(std::string name, std::string manufacturer) : PollingComponent(1000), bleKeyboard(name, manufacturer, 100) {}

    void setup() override {
        ESP_LOGD("Esp32BLEKeyboard", "Setting up BLE Keyboard...");
        bleKeyboard.begin();
        bleKeyboard.releaseAll();
        this->textsensor->add_on_state_callback(
            [this](std::string value) {
                ESP_LOGD("Esp32BLEKeyboard", "Sending text %s", value.c_str());
                this->bleKeyboard.print(value.c_str());
            });
    }

    void update() override {
        connected_binarysensor->publish_state(bleKeyboard.isConnected());
    }
};
