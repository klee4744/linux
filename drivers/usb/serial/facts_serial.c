/***************************************************************************************************************


 Company:						    	FACTS Engineering, LLC
 Author:							Kwan Lee

 Project:						    	FACTS USB to Serial Driver



 Revision and Date:						V1.01 01-19-2021
 ****************************************************************************************************************
 ****************************************************************************************************************

 This document and the information disclosed herein are proprietary data of FACTS Engineering,LLC.
 Neither this document nor the information contained herein shall be reproduced, used or disclosed
 to others without the written authorization of FACTS Engineering,LLC
 ***************************************************************************************************************/

#include <linux/kernel.h>
#include <linux/tty.h>
#include <linux/module.h>
#include <linux/usb.h>
#include <linux/usb/serial.h>

#define DRIVER_DESC		"FACTS USB to Serial Driver"

/* Vendor ID */
#define FACTS_VID		0x1354
/* Product ID */
#define PHMI_BOOT_PID		0xfa00
#define PHMI_TS04_PID		0xfa01
#define PHMI_TS07_PID		0xfa02
#define PHMI_TS10_PID		0xfa03
/* USB Class Code */
#define CDC_DATA		0x0a

static const struct usb_device_id id_table[] = {
	{ USB_DEVICE_INTERFACE_CLASS(FACTS_VID, PHMI_BOOT_PID, CDC_DATA) },
	{ USB_DEVICE_INTERFACE_CLASS(FACTS_VID, PHMI_TS04_PID, CDC_DATA) },
	{ USB_DEVICE_INTERFACE_CLASS(FACTS_VID, PHMI_TS07_PID, CDC_DATA) },
	{ USB_DEVICE_INTERFACE_CLASS(FACTS_VID, PHMI_TS10_PID, CDC_DATA) },
	{ }	/* Terminating entry */
};
MODULE_DEVICE_TABLE(usb, id_table);

static struct usb_serial_driver facts_device = {
	.driver = {
		.owner =	THIS_MODULE,
		.name =		"facts",
	},
	.description =		"FACTS USB to Serial Driver",
	.id_table =		id_table,
	.num_ports =		1,
};

static struct usb_serial_driver * const serial_drivers[] = {
	&facts_device, NULL
};

module_usb_serial_driver(serial_drivers, id_table);

MODULE_DESCRIPTION(DRIVER_DESC);
MODULE_LICENSE("GPL");
