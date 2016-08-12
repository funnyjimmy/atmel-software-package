/**
 * \page sama5d2_xult_board_desc sama5d2-XULT - Board Description
 *
 * \section Purpose
 *
 * This file is dedicated to describe the sama5d2-XULT board.
 *
 * \section Contents
 *
 *  - sama5d2-XULT
 *  - For sama5d2-XULT information, see \subpage sama5d2_xult_board_info.
 *  - For operating frequency information, see \subpage sama5d2_xult_opfreq.
 *  - For using portable PIO definitions, see \subpage sama5d2_xult_piodef.
 *  - For on-board memories, see \subpage sama5d2_xult_mem.
 *  - Several USB definitions are included here, see \subpage sama5d2_xult_usb.
 *  - For External components, see \subpage sama5d2_xult_extcomp.
 *  - For Individual chip definition, see \subpage sama5d2_xult_chipdef.
 *
 * To get more software details and the full list of parameters related to the
 * sama5d2-XULT board configuration, please have a look at the source file:
 * \ref board.h\n
 *
 * \section Usage
 *
 *  - The code for booting the board is provided by board_cstartup_xxx.c and
 *    board_lowlevel.c.
 *  - For using board PIOs, board characteristics (clock, etc.) and external
 *    components, see board.h.
 *  - For manipulating memories, see board_memories.h.
 *
 * This file can be used as a template and modified to fit a custom board, with
 * specific PIOs usage or memory connections.
 */

/**
 *  \file board.h
 *
 *  Definition of sama5d2-XULT
 *  characteristics, sama5d4-dependant PIOs and external components interfacing.
 */

#ifndef _BOARD_D2_H
#define _BOARD_D2_H

/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/

#include "chip.h"

#include "board_support.h"

/*----------------------------------------------------------------------------
 *        HW BOARD Definitions
 *----------------------------------------------------------------------------*/

/* Uncomment next line to use early prototype versions of SAMA5D2-XULT. */
//#define CONFIG_BOARD_SAMA5D2_XPLAINED_PROTO

/**
 * \page sama5d2_xult_board_info "sama5d2-XULT - Board informations"
 * This page lists several definition related to the board description.
 *
 * \section Definitions
 * - \ref BOARD_NAME
 */

/** Name of the board */
#define BOARD_NAME "sama5d2-xult"

/*----------------------------------------------------------------------------*/

/** Frequency of the board slow clock oscillator */
#define BOARD_SLOW_CLOCK_EXT_OSC 32768

/** Frequency of the board main clock oscillator */
#define BOARD_MAIN_CLOCK_EXT_OSC 12000000

/** /def Definition of DDRAM's type */
#define BOARD_DDRAM_TYPE         MT41K128M16

/** \def Board DDR memory size in bytes */
#define BOARD_DDR_MEMORY_SIZE    512*1024*1024

/** \def Board PIT tick resolution */
#define BOARD_TIMER_RESOLUTION    1000

/* =================== PIN CONSOLE definition ================== */

/** CONSOLE pin definition: use UART1 IOSET1 */
/* Note that these definitions could be omitted if the console is configured in
 * the active boot config word. */
#define BOARD_CONSOLE_PINS     PINS_UART1_IOS1
#define BOARD_CONSOLE_ADDR     UART1
#define BOARD_CONSOLE_BAUDRATE 115200

/* =================== PIN LED definition ====================== */

/* RGB LED index */
#define LED_RED   0
#define LED_GREEN 1
#define LED_BLUE  2

/** LED #0 pin definition (Red). */
#ifndef CONFIG_BOARD_SAMA5D2_XPLAINED_PROTO
#define PIN_LED_0 { PIO_GROUP_B, PIO_PB6, PIO_OUTPUT_1, PIO_OPENDRAIN }
#else
/* on prototype board, LED_0 shares a pin with SDMMC0 (eMMC) card detect */
#define PIN_LED_0 { PIO_GROUP_A, PIO_PA13, PIO_OUTPUT_0, PIO_OPENDRAIN }
#endif

/** LED #1 pin definition (Green). */
#define PIN_LED_1 { PIO_GROUP_B, PIO_PB5, PIO_OUTPUT_1, PIO_OPENDRAIN }

/** LED #2 pin definition (Blue). */
#define PIN_LED_2 { PIO_GROUP_B, PIO_PB0, PIO_OUTPUT_1, PIO_OPENDRAIN }

/** List of all LEDs definitions. */
#define PINS_LEDS { PIN_LED_0, PIN_LED_1, PIN_LED_2 }

#define NUM_LEDS  3

/* =================== LWM LED definition ====================== */

/** LED #1 PWM Channel */
#define PWM_LED_CH_0 2

/** LED #2 PWM Channel */
#define PWM_LED_CH_1 1

/** LED #1 pin definition (Green). */
#define PIN_PWM_LED_0 { PIO_GROUP_B, PIO_PB5C_PWMH2, PIO_PERIPH_C, PIO_PULLUP }

/** LED #2 pin definition (Blue). */
#define PIN_PWM_LED_1 { PIO_GROUP_B, PIO_PB0D_PWMH1, PIO_PERIPH_D, PIO_PULLUP }

/** List of all PWM LED channels */
#define PWM_LEDS_CH { PWM_LED_CH_0, PWM_LED_CH_1 }

/** List of all LEDs definitions in PWM mode (red LED is not on a PWM pin) */
#define PINS_PWM_LEDS { PIN_PWM_LED_0, PIN_PWM_LED_1 }

/* =================== PIN PUSH BUTTON definition ============== */

#define PIO_CFG_PB  (PIO_PULLUP | PIO_DEBOUNCE)

#ifndef CONFIG_BOARD_SAMA5D2_XPLAINED_PROTO
#define PIN_PUSHBUTTON_1 { PIO_GROUP_B, PIO_PB9, PIO_INPUT, PIO_CFG_PB }
#else
#define PIN_PUSHBUTTON_1 { PIO_GROUP_B, PIO_PB6, PIO_INPUT, PIO_CFG_PB }
#endif

/** List of all push button definitions. */
#define PINS_PUSHBUTTONS { PIN_PUSHBUTTON_1 }

/** Push button index. */
#define PUSHBUTTON_BP1 0

/* ================== TWI bus definition ====================== */

#define BOARD_TWI_BUS0      TWI4
#define BOARD_TWI_BUS0_FREQ 400000
#define BOARD_TWI_BUS0_PINS PINS_FLEXCOM4_TWI_IOS3

#define BOARD_TWI_BUS1      ((Twi*)TWIHS1)
#define BOARD_TWI_BUS1_FREQ 400000
#define BOARD_TWI_BUS1_PINS PINS_TWI1_IOS2

/* ================== ACT8945A PMIC definition ====================== */

#define BOARD_ACT8945A_TWI_BUS    0
#define BOARD_ACT8945A_TWI_ADDR   0x5b
#define BOARD_ACT8945A_PIN_CHGLEV { PIO_GROUP_A, PIO_PA12, PIO_OUTPUT_0, PIO_PULLUP }
#define BOARD_ACT8945A_PIN_IRQ    { PIO_GROUP_B, PIO_PB13, PIO_INPUT, PIO_PULLUP | PIO_IT_FALL_EDGE }
#ifndef CONFIG_BOARD_SAMA5D2_XPLAINED_PROTO
#define BOARD_ACT8945A_PIN_LBO    { PIO_GROUP_C, PIO_PC8, PIO_INPUT, PIO_PULLUP | PIO_IT_FALL_EDGE }
#else
/* on prototype board, ACT8945A_LBO shares a pin with ACT8945A_IRQ */
#define BOARD_ACT8945A_PIN_LBO    { PIO_GROUP_B, PIO_PB13, PIO_INPUT, PIO_PULLUP | PIO_IT_FALL_EDGE }
#endif

/* ================== PIN USB definition ======================= */

/** USB VBus pin */
#define PIN_USB_VBUS \
	{ PIO_GROUP_A, PIO_PA31, PIO_INPUT, PIO_DEBOUNCE | PIO_IT_BOTH_EDGE }

/** USB OverCurrent detection*/
#define PIN_USB_OVCUR \
	{ PIO_GROUP_A, PIO_PA29, PIO_INPUT, PIO_DEFAULT }

/** USB Power Enable A, Active high */
#define PIN_USB_POWER_ENA \
	{ PIO_GROUP_B, PIO_PB9, PIO_OUTPUT_0, PIO_DEFAULT }

/** USB Power Enable B, Active high  */
#define PIN_USB_POWER_ENB \
	{ PIO_GROUP_B, PIO_PB10, PIO_OUTPUT_0, PIO_DEFAULT }

/**
 * USB attributes configuration descriptor (bus or self powered,
 * remote wakeup)
 */
#define BOARD_USB_BMATTRIBUTES \
	USBConfigurationDescriptor_SELFPOWERED_NORWAKEUP

/* =================== PIN ISC definition ======================= */

#define BOARD_ISC_TWI_BUS  1
#define BOARD_ISC_PINS     PINS_ISC_IOS3
#define BOARD_ISC_PIN_RST  { PIO_GROUP_B, PIO_PB11, PIO_OUTPUT_1, PIO_DEFAULT }
#define BOARD_ISC_PIN_PWD  { PIO_GROUP_B, PIO_PB12, PIO_OUTPUT_1, PIO_DEFAULT }

/* =================== PIN ClassD definition ==================== */

#define BOARD_CLASSD_PINS      { PIN_CLASSD_R0_IOS1, PIN_CLASSD_R1_IOS1,\
                                 PIN_CLASSD_R2_IOS1, PIN_CLASSD_R3_IOS1 }
#define BOARD_CLASSD_MODE      CLASSD_OUTPUT_FULL_BRIDGE
#define BOARD_CLASSD_MONO      true
#define BOARD_CLASSD_MONO_MODE CLASSD_MONO_MIXED

/* =================== SDMMC device definition ==================== */

#define BOARD_SDMMC0_PINS { PIN_SDMMC0_CD_IOS1, PIN_SDMMC0_CK_IOS1,\
                            PIN_SDMMC0_CMD_IOS1, PIN_SDMMC0_RSTN_IOS1,\
                            PIN_SDMMC0_VDDSEL_IOS1, PINS_SDMMC0_DATA8B_IOS1 }

/* Deviation from the SD Host Controller Specification: we use the Voltage
 * Support capabilities to indicate the supported signaling levels (VCCQ),
 * rather than the power supply voltage (VCC). */
#define BOARD_SDMMC0_CAPS0 (SDMMC_CA0R_V33VSUP | \
                            SDMMC_CA0R_V18VSUP | \
                            SDMMC_CA0R_SLTYPE_EMBEDDED | \
                            SDMMC_CA0R_ED8SUP)

#define BOARD_SDMMC1_PINS { PIN_SDMMC1_CD_IOS1, PIN_SDMMC1_CK_IOS1,\
                            PIN_SDMMC1_CMD_IOS1, PINS_SDMMC1_DATA4B_IOS1 }

#define BOARD_SDMMC1_CAPS0 (SDMMC_CA0R_V33VSUP | \
                            SDMMC_CA0R_SLTYPE_REMOVABLECARD)

/* =================== AT24 device definition =================== */

#define BOARD_AT24_TWI_BUS        1
#define BOARD_AT24_DESC           {"AT24MAC402", 0xFF, 16}
#define BOARD_AT24_EEP_ADDR       (0x50 | 0x4)
#define BOARD_AT24_SN_ADDR        (0x58 | 0x4)
#define BOARD_AT24_SN_OFFSET      0x80        // 0x80-0x8F
#define BOARD_AT24_EUI48_OFFSET   0x9A        // 0x9A-0x9F

/* =================== AT25 device definition =================== */

#define BOARD_AT25_PINS     PINS_SPI0_NPCS0_IOS1
#define BOARD_AT25_ADDR     SPI0
#define BOARD_AT25_CS       0
#define BOARD_AT25_ATTRS    (SPI_MR_MODFDIS | SPI_MR_WDRBT | SPI_MR_MSTR)
#define BOARD_AT25_FREQ     40000 /* (value in KHz) */
#define BOARD_AT25_DLYBS    0
#define BOARD_AT25_DLYCT    0
#define BOARD_AT25_SPI_MODE (SPI_CSR_NCPHA | SPI_CSR_BITS_8_BIT)

/* =================== QSPI serial flashdevice definition ======= */

#define QSPIFLASH_PINS     PINS_QSPI0_IOS3
#define QSPIFLASH_ADDR     QSPI0
#define QSPIFLASH_BAUDRATE 50000000 /* 50 MHz */

/* =================== CAN device definition ==================== */
/* Both ports are wired to the J9 connector:
 * CANTX0 = PC10 = J9:8
 * CANRX0 = PC11 = J9:7
 * CANTX1 = PC26 = J9:6
 * CANRX1 = PC27 = J9:5 */

#define CAN0_PINS          PINS_CAN0_IOS1
#define CAN1_PINS          PINS_CAN1_IOS0

/* =================== GMAC/PHY definition =================== */

#define GMAC0_ADDR        GMAC0
#define GMAC0_PINS        PINS_GMAC_RMII_IOS3
#define GMAC0_PHY_ADDR    0
#define GMAC0_PHY_IRQ_PIN PIN_GTSUCOM_IOS1
#define GMAC0_PHY_RETRIES PHY_DEFAULT_RETRIES

/* ======================== LCD definition ======================== */

/** PIO pins for LCD */
#define BOARD_LCD_PINS              PINS_LCD_IOS2

/** Display width in pixels. */
#define BOARD_LCD_WIDTH             480
/** Display height in pixels. */
#define BOARD_LCD_HEIGHT            272
/** Frame rate in Hz. */
#define BOARD_LCD_FRAMERATE         40

/** Vertical front porch in number of lines. */
#define BOARD_LCD_TIMING_VFP        22
/** Vertical back porch in number of lines. */
#define BOARD_LCD_TIMING_VBP        21
/** Vertical pulse width in number of lines. */
#define BOARD_LCD_TIMING_VPW        2
/** Horizontal front porch in LCDDOTCLK cycles. */
#define BOARD_LCD_TIMING_HFP        64
/** Horizontal back porch in LCDDOTCLK cycles. */
#define BOARD_LCD_TIMING_HBP        64
/** Horizontal pulse width in LCDDOTCLK cycles. */
#define BOARD_LCD_TIMING_HPW        128

#endif /* #ifndef _BOARD_D2_H */
