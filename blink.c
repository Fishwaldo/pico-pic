/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "image_info.h"
#include "pico/stdlib.h"


void blink_fn() {
    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    while (true) {
        gpio_put(LED_PIN, 1);
        sleep_ms(250);
        gpio_put(LED_PIN, 0);
        sleep_ms(250);
        printf(".");
    }
}


int main() {
#ifndef PICO_DEFAULT_LED_PIN
#warning blink ecorexample requires a board with a regular LED
#else
    stdio_init_all();
    typedef void (*blink_t)(void);
    blink_t blinkptr = blink_fn;
    blinkptr();
#endif
}
