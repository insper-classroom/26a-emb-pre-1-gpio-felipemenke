#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN_PIN_1 = 28;
const int BTN_PIN_2 = 26;
const int LED_PIN_1 = 4;
const int LED_PIN_2 = 6;

int main() {
  stdio_init_all();

  gpio_init(BTN_PIN_1); // Inicia o botão 1
  gpio_set_dir(BTN_PIN_1, GPIO_IN); // entrada e saida do botão 1
  gpio_pull_up(BTN_PIN_1); // ativa o pull-up para o botão 1, garantindo que ele leia HIGH quando não pressionado

  gpio_init(BTN_PIN_2); // Inicia o botão 2
  gpio_set_dir(BTN_PIN_2, GPIO_IN); // entrada e saida do botão 2
  gpio_pull_up(BTN_PIN_2); // ativa o pull-up para o botão 2, garantindo que ele leia HIGH quando não pressionado

  gpio_init(LED_PIN_1); 
  gpio_set_dir(LED_PIN_1, GPIO_OUT);
  gpio_put(LED_PIN_1, 0);

  gpio_init(LED_PIN_2);
  gpio_set_dir(LED_PIN_2, GPIO_OUT);
  gpio_put(LED_PIN_2, 0);
  
  bool led1_state = 0;
  bool led2_state = 0;
  
  while (true) {
    if (!gpio_get(BTN_PIN_1)) {
      led1_state = !led1_state;
      gpio_put(LED_PIN_1, led1_state);
      while (!gpio_get(BTN_PIN_1)) {
        sleep_ms(10);
      }
      sleep_ms(20);
    }
    
    if (!gpio_get(BTN_PIN_2)) {
      led2_state = !led2_state;
      gpio_put(LED_PIN_2, led2_state);    
      while (!gpio_get(BTN_PIN_2)) {
        sleep_ms(10);
      }
      sleep_ms(20);
    }
  }
}
