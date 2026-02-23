#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

int main() {
  stdio_init_all();

  const int LED_PIN_1 = 5;
  const int LED_PIN_2 = 8;
  const int LED_PIN_3 = 11;
  const int LED_PIN_4 = 15;
  const int BTN_PIN = 28;


  gpio_init(BTN_PIN); // Inicia o botão 1
  gpio_set_dir(BTN_PIN, GPIO_IN); // entrada e saida do botão 1
  gpio_pull_up(BTN_PIN);

  gpio_init(LED_PIN_1); // Inicia o led 1
  gpio_set_dir(LED_PIN_1, GPIO_OUT); // entrada e saida do led 1
  gpio_put(LED_PIN_1, 0); //estado inicial

  gpio_init(LED_PIN_2); // Inicia o led 2
  gpio_set_dir(LED_PIN_2, GPIO_OUT); // entrada e saida do led 1
  gpio_put(LED_PIN_2, 0); //estado inicial

  gpio_init(LED_PIN_3); // Inicia o led 3
  gpio_set_dir(LED_PIN_3, GPIO_OUT); // entrada e saida do led 1
  gpio_put(LED_PIN_3, 0); //estado inicial

  gpio_init(LED_PIN_4); // Inicia o led 4
  gpio_set_dir(LED_PIN_4, GPIO_OUT); // entrada e saida do led 1
  gpio_put(LED_PIN_4, 0); //estado inicial
  while (true) {
    // Use delay de 300 ms entre os estados!
    


    if (!gpio_get(BTN_PIN)) {
      gpio_put(LED_PIN_1, 1);
      sleep_ms(300);
      gpio_put(LED_PIN_1, 0);
      gpio_put(LED_PIN_2, 1);
      sleep_ms(300);
      gpio_put(LED_PIN_2, 0);
      gpio_put(LED_PIN_3, 1);
      sleep_ms(300);
      gpio_put(LED_PIN_3, 0);
      gpio_put(LED_PIN_4, 1);
      sleep_ms(300);
      gpio_put(LED_PIN_4, 0);
      while (!gpio_get(BTN_PIN)) {
        sleep_ms(10);
      }
    }
  }
}
