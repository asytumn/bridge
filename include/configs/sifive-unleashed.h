/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright (c) 2019 Western Digital Corporation or its affiliates.
 *
 * Authors:
 *   Anup Patel <anup.patel@wdc.com>
 */

#ifndef __CONFIG_H
#define __CONFIG_H

#include <linux/sizes.h>

#ifdef CONFIG_SPL

#define CONFIG_SPL_MAX_SIZE		0x00100000
#define CONFIG_SPL_BSS_START_ADDR	0x85000000
#define CONFIG_SPL_BSS_MAX_SIZE		0x00100000
#define CONFIG_SYS_SPL_MALLOC_START	(CONFIG_SPL_BSS_START_ADDR + \
					 CONFIG_SPL_BSS_MAX_SIZE)
#define CONFIG_SYS_SPL_MALLOC_SIZE	0x00100000

#define CONFIG_SPL_STACK	(0x08000000 + 0x001D0000 - \
				 GENERATED_GBL_DATA_SIZE)

#endif

#define CONFIG_SYS_SDRAM_BASE		0x80000000
#define CONFIG_SYS_INIT_SP_ADDR		(CONFIG_SYS_SDRAM_BASE + SZ_2M)

#define CONFIG_SYS_BOOTM_LEN		SZ_64M

#define CONFIG_STANDALONE_LOAD_ADDR	0x80200000

#define RISCV_MMODE_TIMERBASE		0x2000000
#define RISCV_MMODE_TIMER_FREQ		1000000

#define RISCV_SMODE_TIMER_FREQ		1000000

/* Environment options */

#ifndef CONFIG_SPL_BUILD
#define BOOT_TARGET_DEVICES(func) \
	func(MMC, mmc, 0) \
	func(SF, sf, 0) \
	func(DHCP, dhcp, na)

#include <config_distro_bootcmd.h>
#include <environment/distro/sf.h>

#define TYPE_GUID_LOADER1	"5B193300-FC78-40CD-8002-E86C45580B47"
#define TYPE_GUID_LOADER2	"2E54B353-1271-4842-806F-E436D6AF6985"
#define TYPE_GUID_SYSTEM	"0FC63DAF-8483-4772-8E79-3D69D8477DE4"

#define PARTS_DEFAULT \
	"name=loader1,start=17K,size=1M,type=${type_guid_gpt_loader1};" \
	"name=loader2,size=4MB,type=${type_guid_gpt_loader2};" \
	"name=system,size=-,bootable,type=${type_guid_gpt_system};"

#define CONFIG_EXTRA_ENV_SETTINGS \
	"fdt_high=0xffffffffffffffff\0" \
	"initrd_high=0xffffffffffffffff\0" \
	"kernel_addr_r=0x84000000\0" \
	"kernel_comp_addr_r=0x88000000\0" \
	"kernel_comp_size=0x4000000\0" \
	"fdt_addr_r=0x8c000000\0" \
	"scriptaddr=0x8c100000\0" \
	"script_offset_f=0x1fff000\0" \
	"script_size_f=0x1000\0" \
	"pxefile_addr_r=0x8c200000\0" \
	"ramdisk_addr_r=0x8c300000\0" \
	"type_guid_gpt_loader1=" TYPE_GUID_LOADER1 "\0" \
	"type_guid_gpt_loader2=" TYPE_GUID_LOADER2 "\0" \
	"type_guid_gpt_system=" TYPE_GUID_SYSTEM "\0" \
	"partitions=" PARTS_DEFAULT "\0" \
	"fdtfile=" CONFIG_DEFAULT_FDT_FILE "\0" \
	BOOTENV \
	BOOTENV_SF
#endif

#endif /* __CONFIG_H */
