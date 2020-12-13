#include <stdio.h>
#include <stdlib.h>
#include "GPIO.h"

int main (int argc, char **argv) {
    
    char pin[2];
    char dir[3];
    char val[1];

    printf("Eneter pin # ");
    scanf("%s", pin);
    char gpio_folder[7];
    sprintf(gpio_folder, "gpio%s", pin);
    printf("(%s)\n", gpio_folder); 

    printf("\nEnter gpio direction function: ");
    scanf("%s", dir);
    set_direction(get_gpio_pin(gpio_folder), dir);
    get_direction(get_gpio_pin(gpio_folder));

    printf("\nEnter gpio value function: ");
    scanf("%s", val);
    set_value(get_gpio_pin(gpio_folder), val);
    get_value(get_gpio_pin(gpio_folder));
    
    return 0;
}
