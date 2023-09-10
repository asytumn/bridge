/* SPDX-License-Identifier: MIT */

#ifndef __CONFIGS_OMBRES_K9LSGF_H__
#define __CONFIGS_OMBRES_K9LSGF_H__

#include <configs/rk3568_common.h>


#define CONFIG_SUPPORT_EMMC_RPMB

#undef	ROCKCHIP_DEVICE_SETTINGS
#define	ROCKCHIP_DEVICE_SETTINGS \
		"stdin=serial,usbkbd\0" \
		"stdout=serial,vidconsole\0" \
		"stderr=serial,vidconsole\0"

#define CONFIG_USB_OHCI_NEW
#define CONFIG_SYS_USB_OHCI_CPU_INIT			1
#define CONFIG_SYS_USB_OHCI_MAX_ROOT_PORTS		3


#endif // __CONFIGS_OMBRES_K9LSGF_H__


