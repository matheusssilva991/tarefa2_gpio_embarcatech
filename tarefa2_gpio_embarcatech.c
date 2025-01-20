#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "pico/bootrom.h"
#include "hardware/pwm.h"
#include "hardware/clocks.h"

#define GREEN_LED_PIN 11
#define BLUE_LED_PIN 12
#define RED_LED_PIN 13
#define BUZZER_PIN 21

// Configuração da frequência do buzzer (em Hz)
#define BUZZER_FREQUENCY 100

// Função para inicializar o PWM no pino do buzzer
void pwm_init_buzzer(uint pin) {
    // Configurar o pino como saída de PWM
    gpio_set_function(pin, GPIO_FUNC_PWM);

    // Obter o slice do PWM associado ao pino
    uint slice_num = pwm_gpio_to_slice_num(pin);

    // Configurar o PWM com a frequência desejada
    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, clock_get_hz(clk_sys) / (BUZZER_FREQUENCY * 4096)); // Divisor de clock
    pwm_init(slice_num, &config, true);

    // Iniciar o PWM no nível baixo
    pwm_set_gpio_level(pin, 0);
}

// Função para emitir um beep com duração especificada
void beep(uint pin, uint duration_ms) {
    // Obter o slice do PWM associado ao pino
    uint slice_num = pwm_gpio_to_slice_num(pin);

    // Configurar o duty cycle para 50% (ativo)
    pwm_set_gpio_level(pin, 2048);

    // Temporização
    sleep_ms(duration_ms);

    // Desativar o sinal PWM (duty cycle 0)
    pwm_set_gpio_level(pin, 0);

    // Pausa entre os beeps
    sleep_ms(100); // Pausa de 100ms
}

int main()
{
    char word[20];

    stdio_init_all();

    // Configuração dos pinos
    gpio_init(RED_LED_PIN);
    gpio_set_dir(RED_LED_PIN, GPIO_OUT);
    

    // Configuração do pino do buzzer
    pwm_init_buzzer(BUZZER_PIN);

    while (true) {
        scanf("%19s", word);

        if (strcmp(word, "green") == 0 || strcmp(word, "verde") == 0) {
            // Ligar o LED verde e desligar os outros
            printf("ON: GREEN\n");
           
        } else if (strcmp(word, "blue") == 0 || strcmp(word, "azul") == 0) {
            // Ligar o LED azul e desligar os outros
            printf("ON: BLUE\n");
        } else if (strcmp(word, "red") == 0 || strcmp(word, "vermelho") == 0) {
            // Ligar o LED vermelho e desligar os outros
            printf("ON: RED\n");
            gpio_put(GREEN_LED_PIN, 0);
            gpio_put(BLUE_LED_PIN, 0);
            gpio_put(RED_LED_PIN, 1);
        } else if (strcmp(word, "white") == 0 || strcmp(word, "branco") == 0) {
            // Ligar todos os LEDs
            printf("ON: WHITE\n");
          
        } else if (strcmp(word, "off") == 0 || strcmp(word, "desligar") == 0) {
            // Desligar todos os LEDs
            printf("SYSTEM: OFF\n");
      
        } else if (strcmp(word, "buzzer") == 0 || strcmp(word, "buzina") == 0) {
            // Ligar o buzzer por 2 segundos
            printf("ON: BUZZER\n");
            beep(BUZZER_PIN, 2000);  // Emitir o beep por 2 segundos
        } else if (strcmp(word, "bootsel") == 0) {
            printf("SYSTEM: BOOTSEL\n");
            reset_usb_boot(0, 0);
        } else {
            printf("SYSTEM: INVALID COMMAND\n");
        }
    }

    return 0;
}
