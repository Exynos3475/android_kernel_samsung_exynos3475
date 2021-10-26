/* linux/drivers/video/exynos_decon/panel/aid_dimming.h
 *
 * Header file for Samsung AID Dimming Driver.
 *
 * Copyright (c) 2013 Samsung Electronics
 * Minwoo Kim <minwoo7945.kim@samsung.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
*/

#ifndef __AID_DIMMING_H__
#define __AID_DIMMING_H__

#if defined(CONFIG_EXYNOS3475_DECON_LCD_S6E88A0)
#include "s6e88a0_dimming.h"
#elif defined(CONFIG_EXYNOS3475_DECON_LCD_S6E8AA5X01)
#include "s6e8aa5x01_dimming.h"
#elif defined(CONFIG_EXYNOS3475_DECON_LCD_EA8061S_J1)
#include "ea8061s_dimming_j1.h"
#else
#error "ERROR !! Check LCD Panel Header File"
#endif

#define	DIMMING_METHOD_AID		0
#define DIMMING_METHOD_FILL_CENTER	1
#define DIMMING_METHOD_INTERPOLATION	2
#define DIMMING_METHOD_FILL_HBM		3
#define DIMMING_METHOD_MAX		4

#define W1	DIMMING_METHOD_AID
#define W2	DIMMING_METHOD_FILL_CENTER
#define W3	DIMMING_METHOD_INTERPOLATION
#define W4	DIMMING_METHOD_FILL_HBM

enum {
	CI_RED = 0,
	CI_GREEN,
	CI_BLUE,
	CI_MAX,
};

struct dim_data {
	int t_gamma[NUM_VREF][CI_MAX];
	int mtp[NUM_VREF][CI_MAX];
	int volt[MAX_GRADATION][CI_MAX];
	int volt_vt[CI_MAX];
	int vt_mtp[CI_MAX];
	int look_volt[NUM_VREF][CI_MAX];
};

struct SmtDimInfo {
	unsigned int br;
	const signed char *cTbl;
	const unsigned char *aid;
	const unsigned char *elvAcl;
	const unsigned char *elv;
	unsigned char *m_gray;
	unsigned char gamma[OLED_CMD_GAMMA_CNT];
	unsigned int way;
};

#endif

