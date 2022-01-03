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

/* Name of the pins as it said in Sws page 43 PortPinId : This value will be assigned 
 * to the symbolic name derived from the port pin container short name               
 * Every pin has its own name and id so, the names are included below
 */ 
      /* PORTA has 8-pins */
#define PORT_PIN0_ID    (Port_PinType)0
#define PORT_PIN1_ID    (Port_PinType)1
#define PORT_PIN2_ID    (Port_PinType)2
#define PORT_PIN3_ID    (Port_PinType)3
#define PORT_PIN4_ID    (Port_PinType)4
#define PORT_PIN5_ID    (Port_PinType)5
#define PORT_PIN6_ID    (Port_PinType)6
#define PORT_PIN7_ID    (Port_PinType)7
      /* PORTB has 8-pins */
#define PORT_PIN8_ID    (Port_PinType)0
#define PORT_PIN9_ID    (Port_PinType)1
#define PORT_PIN10_ID   (Port_PinType)2
#define PORT_PIN11_ID   (Port_PinType)3
#define PORT_PIN12_ID   (Port_PinType)4
#define PORT_PIN13_ID   (Port_PinType)5
#define PORT_PIN14_ID   (Port_PinType)6
#define PORT_PIN15_ID   (Port_PinType)7
      /* PORTC has 8-pins */
#define PORT_PIN16_ID   (Port_PinType)0
#define PORT_PIN17_ID   (Port_PinType)1
#define PORT_PIN18_ID   (Port_PinType)2
#define PORT_PIN19_ID   (Port_PinType)3
#define PORT_PIN20_ID   (Port_PinType)4
#define PORT_PIN21_ID   (Port_PinType)5
#define PORT_PIN22_ID   (Port_PinType)6
#define PORT_PIN23_ID   (Port_PinType)7
      /* PORTD has 8-pins */
#define PORT_PIN24_ID   (Port_PinType)0
#define PORT_PIN25_ID   (Port_PinType)1
#define PORT_PIN26_ID   (Port_PinType)2
#define PORT_PIN27_ID   (Port_PinType)3
#define PORT_PIN28_ID   (Port_PinType)4
#define PORT_PIN29_ID   (Port_PinType)5
#define PORT_PIN30_ID   (Port_PinType)6
#define PORT_PIN31_ID   (Port_PinType)7
      /* PORTE has 6-pins */
#define PORT_PIN32_ID   (Port_PinType)0
#define PORT_PIN33_ID   (Port_PinType)1
#define PORT_PIN34_ID   (Port_PinType)2
#define PORT_PIN35_ID   (Port_PinType)3
#define PORT_PIN36_ID   (Port_PinType)4
#define PORT_PIN37_ID   (Port_PinType)5
      /* PORTF has 5-pins */
#define PORT_PIN38_ID   (Port_PinType)0
#define PORT_PIN39_ID   (Port_PinType)1
#define PORT_PIN40_ID   (Port_PinType)2
#define PORT_PIN41_ID   (Port_PinType)3
#define PORT_PIN42_ID   (Port_PinType)4


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