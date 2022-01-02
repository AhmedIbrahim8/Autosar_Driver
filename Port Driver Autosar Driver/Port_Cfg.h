 /******************************************************************************
 *
 * Module      : Port
 *
 * File Name   : Port_Cfg.h
 *
 * Description : Pre-Compile Configuration Header file for TM4C123GH6PM Microcontroller - Port Driver
 *
 * Author      : Ahmed Ibrahim
 ******************************************************************************/

#ifndef PORT_CFG_H
#define PORT_CFG_H

/* SoftWare Module Version */
#define PORT_CFG_SW_MAJOR_VERSION           (1U)
#define PORT_CFG_SW_MINOR_VERSION           (0U)
#define PORT_CFG_SW_PATCH_VERSION           (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_CFG_AR_RELEASE_MAJOR_VERSION   (4U)
#define PORT_CFG_AR_RELEASE_MINOR_VERSION   (0U)
#define PORT_CFG_AR_RELEASE_PATCH_VERSION   (3U)

/* Pre-compile option for Development Error Detection         */
#define PORT_DEV_ERROR_DETECT         (STD_ON)

/* Pre-compile option to presence of Port_SetPinDirection Api */
#define PORT_SET_PIN_DIRECTION_API    (STD_ON)

/* Pre-compile option to presence of Port_SetPinMode Api      */
#define PORT_SET_PIN_MODE_API         (STD_ON)

/* Pre-compile option to presence of Port_VerionInfo Api      */
#define PORT_VERSION_INFO_API         (STD_ON)

/* Number of pins in the TM4C123GH6PM */
#define PORT_CONFIGURED_PINS   (43U)

/* As Required in PORT SWS in page 44 */
#define PORT_PIN_MODE_ADC
#define PORT_PIN_MODE_CAN
#define PORT_PIN_MODE_DIO
#define PORT_PIN_MODE_DIO_GPT
#define PORT_PIN_MODE_DIO_WDG
#define PORT_PIN_MODE_FLEXRAY
#define PORT_PIN_MODE_ICU
#define PORT_PIN_MODE_LIN
#define PORT_PIN_MODE_MEM
#define PORT_PIN_MODE_PWM
#define PORT_PIN_MODE_SPI


#endif