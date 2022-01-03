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

/************************************************************
 *       Channel Index in the Array of the Structure        *
 * Note: the pin index must be as its position in the array *
 *       because at this position, there is all information *
 *       of the pin.
 ************************************************************/ 
      /* PORTA has 8-pins */
#define PORT_PIN0_ID_INDEX    (uint8)0
#define PORT_PIN1_ID_INDEX    (uint8)1
#define PORT_PIN2_ID_INDEX    (uint8)2
#define PORT_PIN3_ID_INDEX    (uint8)3
#define PORT_PIN4_ID_INDEX    (uint8)4
#define PORT_PIN5_ID_INDEX    (uint8)5
#define PORT_PIN6_ID_INDEX    (uint8)6
#define PORT_PIN7_ID_INDEX    (uint8)7
      /* PORTB has 8-pins */
#define PORT_PIN8_ID_INDEX    (uint8)8
#define PORT_PIN9_ID_INDEX    (uint8)9
#define PORT_PIN10_ID_INDEX   (uint8)10
#define PORT_PIN11_ID_INDEX   (uint8)11
#define PORT_PIN12_ID_INDEX   (uint8)12
#define PORT_PIN13_ID_INDEX   (uint8)13
#define PORT_PIN14_ID_INDEX   (uint8)14
#define PORT_PIN15_ID_INDEX   (uint8)15
      /* PORTC has 8-pins */
#define PORT_PIN16_ID_INDEX   (uint8)16
#define PORT_PIN17_ID_INDEX   (uint8)17
#define PORT_PIN18_ID_INDEX   (uint8)18
#define PORT_PIN19_ID_INDEX   (uint8)19
#define PORT_PIN20_ID_INDEX   (uint8)20
#define PORT_PIN21_ID_INDEX   (uint8)21
#define PORT_PIN22_ID_INDEX   (uint8)22
#define PORT_PIN23_ID_INDEX   (uint8)23
      /* PORTD has 8-pins */
#define PORT_PIN24_ID_INDEX   (uint8)24
#define PORT_PIN25_ID_INDEX   (uint8)25
#define PORT_PIN26_ID_INDEX   (uint8)26
#define PORT_PIN27_ID_INDEX   (uint8)27
#define PORT_PIN28_ID_INDEX   (uint8)28
#define PORT_PIN29_ID_INDEX   (uint8)29
#define PORT_PIN30_ID_INDEX   (uint8)30
#define PORT_PIN31_ID_INDEX   (uint8)31
      /* PORTE has 6-pins */
#define PORT_PIN32_ID_INDEX   (uint8)32
#define PORT_PIN33_ID_INDEX   (uint8)33
#define PORT_PIN34_ID_INDEX   (uint8)34
#define PORT_PIN35_ID_INDEX   (uint8)35
#define PORT_PIN36_ID_INDEX   (uint8)36
#define PORT_PIN37_ID_INDEX   (uint8)37
      /* PORTF has 5-pins */
#define PORT_PIN38_ID_INDEX   (uint8)38
#define PORT_PIN39_ID_INDEX   (uint8)39
#define PORT_PIN40_ID_INDEX   (uint8)40
#define PORT_PIN41_ID_INDEX   (uint8)41
#define PORT_PIN42_ID_INDEX   (uint8)42




/* As Required in PORT SWS in page 44 */
/* Note: DIO mode & ADC mode are the same mode number so, we need
         to differentiate between them                           */
#define PORT_PIN_MODE_DIO      (uint8)0
#define PORT_PIN_MODE_CAN      (uint8)1
#define PORT_PIN_MODE_SPI      (uint8)2
#define PORT_PIN_MODE_I2C      (uint8)3
#define PORT_PIN_MODE_DIO_WDG  (uint8)4
#define PORT_PIN_MODE_DIO_GPT  (uint8)5
#define PORT_PIN_MODE_ICU      (uint8)6
#define PORT_PIN_MODE_LIN      (uint8)7
#define PORT_PIN_MODE_MEM      (uint8)8
#define PORT_PIN_MODE_PWM      (uint8)9
#define PORT_PIN_MODE_ADC      (uint8)10

#endif