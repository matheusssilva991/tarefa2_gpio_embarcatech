#include <stdio.h> 
#include <string.h>
#include "pico/stdlib.h"
#include "pico/bootrom.h"

#define GREEN_LED_PIN 11
#define BLUE_LED_PIN 12
#define RED_LED_PIN 13

#define BUZZER_PIN 21

void turn_off_leds() {
    gpio_put(GREEN_LED_PIN, 0); // Desliga o LED verde
    gpio_put(BLUE_LED_PIN, 0);  // Desliga o LED azul
    gpio_put(RED_LED_PIN, 0);   // Desliga o LED vermelho
}