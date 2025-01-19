#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"

#define GREEN_LED_PIN 11
#define BLUE_LED_PIN 12
#define RED_LED_PIN 13

#define BUZZER_PIN 21

int main()
{
    char *word;

    stdio_init_all();

    while (true) {
        word = scanf("%s", word);

        if (strcmp(word, "green") == 0 || strcmp(word, "verde") == 0) {
            // Ligar o LED verde e desligar os outros
            printf("ON: RED\n");
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
            printf("SYSTEM: OFF\n");
        } else if (strcmp(word, "buzzer") == 0 || strcmp(word, "buzina") == 0) {
            // Ligar o buzzer por 2 segundo
            printf("ON: BUZZER\n");
        } else if (strcmp(word, "bootsel") == 0) {
            printf("SYSTEM: BOOTSEL\n");
            // Entrar no modo Bootsel
        } else {
            printf("SYSTEM: INVALID COMMAND\n");
        }

    }
}
