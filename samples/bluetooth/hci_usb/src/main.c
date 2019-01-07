/*
 * Copyright (c) 2018 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr.h>
#include <misc/printk.h>
#include <gpio.h>

struct device *gpio_dbg_04;
struct device *gpio_dbg_28;
struct device *gpio_dbg_29;
struct device *gpio_dbg_30;
struct device *gpio_dbg_31;

volatile uint8_t gpio_state_04 = 0;
volatile uint8_t gpio_state_28 = 0;
volatile uint8_t gpio_state_29 = 0;
volatile uint8_t gpio_state_30 = 0;
volatile uint8_t gpio_state_31 = 0;


void main(void)
{
	printk("Bluetooth over USB sample\n");

    gpio_dbg_04 = device_get_binding(DBG_PORT_0);
    gpio_pin_configure(gpio_dbg_04, DBG_PIN_04, GPIO_DIR_OUT);
    gpio_pin_write(gpio_dbg_04, DBG_PIN_04, 0);

    gpio_dbg_28 = device_get_binding(DBG_PORT_0);
    gpio_pin_configure(gpio_dbg_28, DBG_PIN_28, GPIO_DIR_OUT);
    gpio_pin_write(gpio_dbg_28, DBG_PIN_28, 0);

    gpio_dbg_29 = device_get_binding(DBG_PORT_0);
    gpio_pin_configure(gpio_dbg_29, DBG_PIN_29, GPIO_DIR_OUT);
    gpio_pin_write(gpio_dbg_29, DBG_PIN_29, 0);

    gpio_dbg_30 = device_get_binding(DBG_PORT_0);
    gpio_pin_configure(gpio_dbg_30, DBG_PIN_30, GPIO_DIR_OUT);
    gpio_pin_write(gpio_dbg_30, DBG_PIN_30, 0);

    gpio_dbg_31 = device_get_binding(DBG_PORT_0);
    gpio_pin_configure(gpio_dbg_31, DBG_PIN_31, GPIO_DIR_OUT);
    gpio_pin_write(gpio_dbg_31, DBG_PIN_31, 0);


	printk("Debug pins init complete\n");
}


void debug_gpio_tgl(uint8_t pin_nr)
{
    switch(pin_nr)
    {
        case DBG_PIN_04:
        {
            gpio_state_04 ^= 0x01;
            gpio_pin_write(gpio_dbg_04, DBG_PIN_04, gpio_state_04);
            break;
        }

        case DBG_PIN_28:
        {
            gpio_state_28 ^= 0x01;
            gpio_pin_write(gpio_dbg_28, DBG_PIN_28, gpio_state_28);
            break;
        }

        case DBG_PIN_29:
        {
            gpio_state_29 ^= 0x01;
            gpio_pin_write(gpio_dbg_29, DBG_PIN_29, gpio_state_29);
            break;
        }

        case DBG_PIN_30:
        {
            gpio_state_30 ^= 0x01;
            gpio_pin_write(gpio_dbg_30, DBG_PIN_30, gpio_state_30);
            break;
        }

        case DBG_PIN_31:
        {
            gpio_state_31 ^= 0x01;
            gpio_pin_write(gpio_dbg_31, DBG_PIN_31, gpio_state_31);
            break;
        }

        default:
        {
            printk("Debug ERROR\n");
            break;
        }
    }
}