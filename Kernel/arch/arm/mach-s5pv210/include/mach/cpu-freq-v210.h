﻿/* arch/arm/mach-s5pv210/include/mach/cpu-freq-v210.h
 *
 *  Copyright (c) 2010 Samsung Electronics Co., Ltd.
 *
 * S5PV210/S5PC110 CPU frequency scaling support
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
*/

#ifndef __ASM_ARCH_CPU_FREQ_H
#define __ASM_ARCH_CPU_FREQ_H

#include <linux/cpufreq.h>

/*
 * APLL M,P,S value for target frequency
 **/
#define APLL_VAL_1600	((1<<31)|(200<<16)|(3<<8)|(1))
#define APLL_VAL_1500	((1<<31)|(375<<16)|(6<<8)|(1))
#define APLL_VAL_1400	((1<<31)|(175<<16)|(3<<8)|(1))
#define APLL_VAL_1300	((1<<31)|(325<<16)|(6<<8)|(1))
#define APLL_VAL_1200	((1<<31)|(150<<16)|(3<<8)|(1))
#define APLL_VAL_1100	((1<<31)|(125<<16)|(3<<8)|(1))
#define APLL_VAL_1000	((1<<31)|(125<<16)|(3<<8)|(1))
#define APLL_VAL_800	((1<<31)|(100<<16)|(3<<8)|(1))
#define APLL_VAL_600    ((1<<31)|(75<<16)|(3<<8)|(1))

enum perf_level {
	L0 = 0,	// 1.6GHz
	L1,	// 1.5GHz
	L2,	// 1.4GHz
	L3,	// 1.3GHz
	L4,	// 1.2GHz
	L5,	// 1.1GHz
	L6,	// 1.0GHz
	L7,	// 800MHz
	L8,	// 600MHz
	L9,	// 400MHz
	L10,	// 200MHz
	L11,	// 100MHz
	MAX_PERF_LEVEL = L11,
};

#define SLEEP_FREQ      (600 * 1000) /* Use 600MHz when entering sleep */
#define ULP_FREQ	(400 * 1000)

/* additional symantics for "relation" in cpufreq with pm */
#define DISABLE_FURTHER_CPUFREQ         0x10
#define ENABLE_FURTHER_CPUFREQ          0x20
#define MASK_FURTHER_CPUFREQ            0x30
/* With 0x00(NOCHANGE), it depends on the previous "further" status */

#ifdef CONFIG_DVFS_LIMIT
enum {
	DVFS_LOCK_TOKEN_1 = 0,	//	(MFC)
	DVFS_LOCK_TOKEN_2,	//	(FIMC)
	DVFS_LOCK_TOKEN_3,	// SND_RP
	DVFS_LOCK_TOKEN_4,	//	(TV)
	DVFS_LOCK_TOKEN_5,	//	(early suspend)
	DVFS_LOCK_TOKEN_6,	// APPS by sysfs
	DVFS_LOCK_TOKEN_7,	// for the touch event
	DVFS_LOCK_TOKEN_8,	// USB
	DVFS_LOCK_TOKEN_9,	// BT
	DVFS_LOCK_TOKEN_NUM
};

extern int s5pv210_lock_dvfs_high_level(uint nToken, uint perf_level);
extern int s5pv210_unlock_dvfs_high_level(unsigned int nToken);
#endif

#endif /* __ASM_ARCH_CPU_FREQ_H */
