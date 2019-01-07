/*
 * Copyright (c) 2015 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ZEPHYR_INCLUDE_ZEPHYR_H_
#define ZEPHYR_INCLUDE_ZEPHYR_H_

/*
 * Applications can identify whether they are built for Zephyr by
 * macro below. (It may be already defined by a makefile or toolchain.)
 */
#ifndef __ZEPHYR__
#define __ZEPHYR__
#endif

#include <kernel.h>

#define DBG_PORT_0    "GPIO_0"
#define DBG_PIN_30    30
#define DBG_PIN_31    31
#define DBG_PIN_29    29
#define DBG_PIN_28    28
#define DBG_PIN_04    04

void debug_gpio_tgl(uint8_t pin_nr);

#endif /* ZEPHYR_INCLUDE_ZEPHYR_H_ */
