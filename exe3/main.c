#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN_PIN_1 = 28;
const int BTN_PIN_2 = 26;
const int LED_PIN_1 = 4;
const int LED_PIN_2 = 6;

int main() {
  stdio_init_all();

  gpio_init(BTN_PIN_1);
  gpio_set_dir(BTN_PIN_1, GPIO_IN);
  gpio_pull_up(BTN_PIN_1);

  gpio_init(BTN_PIN_2);
  gpio_set_dir(BTN_PIN_2, GPIO_IN);
  gpio_pull_up(BTN_PIN_2);

  gpio_init(LED_PIN_1);
  gpio_set_dir(LED_PIN_1, GPIO_OUT);
  gpio_put(LED_PIN_1, 0);

  gpio_init(LED_PIN_2);
  gpio_set_dir(LED_PIN_2, GPIO_OUT);
  gpio_put(LED_PIN_2, 0);

  while (true) {
    if (!gpio_get(BTN_PIN_1)) {
      uint8_t current_state = gpio_get(LED_PIN_1);
      gpio_put(LED_PIN_1, !current_state);
      while (!gpio_get(BTN_PIN_1)) {
        sleep_ms(10);
      }
      sleep_ms(20);
    }
    
    if (!gpio_get(BTN_PIN_2)) {
      uint8_t current_state = gpio_get(LED_PIN_2);
      gpio_put(LED_PIN_2, !current_state);    
      while (!gpio_get(BTN_PIN_2)) {
        sleep_ms(10);
      }
      sleep_ms(20);
    }
  }
}
