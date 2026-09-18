/*
 * Copyright (c) 2026 Lautaro Vera
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <fsl_clock.h>

void board_early_init_hook(void)
{
	/*
	 * The SoC layer only calls SystemInit(); it does not route any clock to
	 * FLEXCOMM4. Without this the console LPUART has no clock at all.
	 * Runs before device initialization, so the UART driver finds it ready.
	 */
	CLOCK_EnableClock(kCLOCK_Scg);

	/* Pin the core to FRO12M explicitly instead of relying on reset state. */
	CLOCK_AttachClk(kFRO12M_to_MAIN_CLK);
	CLOCK_SetClkDiv(kCLOCK_DivAhbClk, 1u);

	CLOCK_SetClkDiv(kCLOCK_DivFlexcom4Clk, 1u);
	CLOCK_AttachClk(kFRO12M_to_FLEXCOMM4);
}

void board_late_init_hook(void)
{
	/*
	 * Runs after POST_KERNEL (console is up) and before boot_banner(),
	 * the APPLICATION init level and main().
	 */
	printk("Board Initialized\n");
}
