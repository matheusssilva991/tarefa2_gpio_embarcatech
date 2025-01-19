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

int main()
{
    char *word;

    stdio_init_all();

    gpio_init(GREEN_LED_PIN);
    gpio_set_dir(GREEN_LED_PIN, GPIO_OUT);
    gpio_init(BLUE_LED_PIN);
    gpio_set_dir(BLUE_LED_PIN, GPIO_OUT);

    while (true) {
        scanf("%s", word);

        if (strcmp(word, "green") == 0 || strcmp(word, "verde") == 0) {
            // Ligar o LED verde e desligar os outros
            printf("ON: GREEN\n");
        } else if (strcmp(word, "blue") == 0 || strcmp(word, "azul") == 0) {
            // Ligar o LED azul e desligar os outros
            printf("ON: BLUE\n");
        } else if (strcmp(word, "red") == 0 || strcmp(word, "vermelho") == 0) {
            // Ligar o LED vermelho e desligar os outros
        } else if (strcmp(word, "white") == 0 || strcmp(word, "branco") == 0) {
            // Ligar todos os LEDs
            printf("ON: WHITE\n");
        } else if (strcmp(word, "off") == 0 || strcmp(word, "desligar") == 0) {
            // Desligar todos os LEDs
            turn_off_leds();
            printf("SYSTEM: OFF\n");
        } else if (strcmp(word, "buzzer") == 0 || strcmp(word, "buzina") == 0) {
            // Ligar o buzzer por 2 segundos
            printf("ON: BUZZER\n");
        } else if (strcmp(word, "bootsel") == 0) {
            printf("SYSTEM: BOOTSEL\n");
            reset_usb_boot(0, 0);
        } else {
            printf("SYSTEM: INVALID COMMAND\n");
        }
    }
}
