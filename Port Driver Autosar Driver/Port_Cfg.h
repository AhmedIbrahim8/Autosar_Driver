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

/* As Required in PORT SWS in page 44                                          */
/* Note: DIO mode & ADC mode are the same mode number so, we need              *
         to differentiate between them in the code                             *
 * In TivaC Data Sheet Page (1330 to 1352), there is the multiple modes        *
 * Supported by TivaC Which are:                                               *
 *                              - UART Mode                                    *
 *                              - DIO Mode                                     *
 *                              - SPI Mode                                     *
 *                              - I2C Mode                                     *
 *                              - ICU Mode-Capture Compare PWM pins(CCP)       *
 *                              - QEI Mode(Quadrature Encoder Interface)       *
 *                              - PWM Mode                                     *
 *                              - USB Mode (Analog signal or Digital)          *
 *                              - CAN Mode                                     *
 *                              - ADC Mode (Analog)                            *
 *                              - Non Maskable Interrupt Mode(NMI)             *
 *                              - Analog comparator MODE (Analog or Digital)   *
 *                              - Trace Data Mode                              */
#define PORT_PIN_MODE_DIO                         (Port_PinModeType)0
#define PORT_PIN_MODE_UART                        (Port_PinModeType)1
#define PORT_PIN_MODE_SPI                         (Port_PinModeType)2
#define PORT_PIN_MODE_I2C                         (Port_PinModeType)3
#define PORT_PIN_MODE_DIO_GPT                     (Port_PinModeType)4
#define PORT_PIN_MODE_QEI                         (Port_PinModeType)5
#define PORT_PIN_MODE_PWM                         (Port_PinModeType)6
#define PORT_PIN_MODE_USB                         (Port_PinModeType)7
#define PORT_PIN_MODE_CAN                         (Port_PinModeType)8
#define PORT_PIN_MODE_ADC                         (Port_PinModeType)9
#define PORT_PIN_MODE_NMI                         (Port_PinModeType)10
#define PORT_PIN_MODE_COMPARATOR                  (Port_PinModeType)11
#define PORT_PIN_MODE_TRACE_DATA                  (Port_PinModeType)12

/************************************************************
 *       Channel Index in the Array of the Structure        *
 * Note: the pin index must be as its position in the array *
 *       because at this position, there is all information *
 *       of the pin.
 ************************************************************/ 
      /* PORTA has 8-pins */
#define PORTA_PIN0_ID_INDEX    (uint8)0
#define PORTA_PIN1_ID_INDEX    (uint8)1
#define PORTA_PIN2_ID_INDEX    (uint8)2
#define PORTA_PIN3_ID_INDEX    (uint8)3
#define PORTA_PIN4_ID_INDEX    (uint8)4
#define PORTA_PIN5_ID_INDEX    (uint8)5
#define PORTA_PIN6_ID_INDEX    (uint8)6
#define PORTA_PIN7_ID_INDEX    (uint8)7
      /* PORTB has 8-pins */
#define PORTB_PIN0_ID_INDEX    (uint8)8
#define PORTB_PIN1_ID_INDEX    (uint8)9
#define PORTB_PIN2_ID_INDEX   (uint8)10
#define PORTB_PIN3_ID_INDEX   (uint8)11
#define PORTB_PIN4_ID_INDEX   (uint8)12
#define PORTB_PIN5_ID_INDEX   (uint8)13
#define PORTB_PIN6_ID_INDEX   (uint8)14
#define PORTB_PIN7_ID_INDEX   (uint8)15
      /* PORTC has 8-pins */
#define PORTC_PIN0_ID_INDEX   (uint8)16
#define PORTC_PIN1_ID_INDEX   (uint8)17
#define PORTC_PIN2_ID_INDEX   (uint8)18
#define PORTC_PIN3_ID_INDEX   (uint8)19
#define PORTC_PIN4_ID_INDEX   (uint8)20
#define PORTC_PIN5_ID_INDEX   (uint8)21
#define PORTC_PIN6_ID_INDEX   (uint8)22
#define PORTC_PIN7_ID_INDEX   (uint8)23
      /* PORTD has 8-pins */
#define PORTD_PIN0_ID_INDEX   (uint8)24
#define PORTD_PIN1_ID_INDEX   (uint8)25
#define PORTD_PIN2_ID_INDEX   (uint8)26
#define PORTD_PIN3_ID_INDEX   (uint8)27
#define PORTD_PIN4_ID_INDEX   (uint8)28
#define PORTD_PIN5_ID_INDEX   (uint8)29
#define PORTD_PIN6_ID_INDEX   (uint8)30
#define PORTD_PIN7_ID_INDEX   (uint8)31
      /* PORTE has 6-pins */
#define PORTE_PIN0_ID_INDEX   (uint8)32
#define PORTE_PIN1_ID_INDEX   (uint8)33
#define PORTE_PIN2_ID_INDEX   (uint8)34
#define PORTE_PIN3_ID_INDEX   (uint8)35
#define PORTE_PIN4_ID_INDEX   (uint8)36
#define PORTE_PIN5_ID_INDEX   (uint8)37
      /* PORTF has 5-pins */
#define PORTF_PIN0_ID_INDEX   (uint8)38
#define PORTF_PIN1_ID_INDEX   (uint8)39
#define PORTF_PIN2_ID_INDEX   (uint8)40
#define PORTF_PIN3_ID_INDEX   (uint8)41
#define PORTF_PIN4_ID_INDEX   (uint8)42

/***********************************************
 *     Choosen Configuration By the Tool       *
 *      "Pins Direction for all Pins"          *
 *             PORT SWS Page 42                *
 *      Default Direction is Input Pin         *
 ***********************************************/
/* PORTA ( 8 Pins ) */
#define PORTA_PIN0_DIRECTION  PORT_PIN_IN
#define PORTA_PIN1_DIRECTION  PORT_PIN_IN
#define PORTA_PIN2_DIRECTION  PORT_PIN_IN
#define PORTA_PIN3_DIRECTION  PORT_PIN_IN
#define PORTA_PIN4_DIRECTION  PORT_PIN_IN
#define PORTA_PIN5_DIRECTION  PORT_PIN_IN
#define PORTA_PIN6_DIRECTION  PORT_PIN_IN
#define PORTA_PIN7_DIRECTION  PORT_PIN_IN
/* PORTB ( 8 Pins ) */
#define PORTB_PIN0_DIRECTION  PORT_PIN_IN
#define PORTB_PIN1_DIRECTION  PORT_PIN_IN
#define PORTB_PIN2_DIRECTION  PORT_PIN_IN
#define PORTB_PIN3_DIRECTION  PORT_PIN_IN
#define PORTB_PIN4_DIRECTION  PORT_PIN_IN
#define PORTB_PIN5_DIRECTION  PORT_PIN_IN
#define PORTB_PIN6_DIRECTION  PORT_PIN_IN
#define PORTB_PIN7_DIRECTION  PORT_PIN_IN
/* PORTC ( 8 Pins ) */
#define PORTC_PIN0_DIRECTION  PORT_PIN_IN
#define PORTC_PIN1_DIRECTION  PORT_PIN_IN
#define PORTC_PIN2_DIRECTION  PORT_PIN_IN
#define PORTC_PIN3_DIRECTION  PORT_PIN_IN
#define PORTC_PIN4_DIRECTION  PORT_PIN_IN
#define PORTC_PIN5_DIRECTION  PORT_PIN_IN
#define PORTC_PIN6_DIRECTION  PORT_PIN_IN
#define PORTC_PIN7_DIRECTION  PORT_PIN_IN
/* PORTD ( 8 Pins ) */
#define PORTD_PIN0_DIRECTION  PORT_PIN_IN
#define PORTD_PIN1_DIRECTION  PORT_PIN_IN
#define PORTD_PIN2_DIRECTION  PORT_PIN_IN
#define PORTD_PIN3_DIRECTION  PORT_PIN_IN
#define PORTD_PIN4_DIRECTION  PORT_PIN_IN
#define PORTD_PIN5_DIRECTION  PORT_PIN_IN
#define PORTD_PIN6_DIRECTION  PORT_PIN_IN
#define PORTD_PIN7_DIRECTION  PORT_PIN_IN
/* PORTE ( 6 Pins ) */
#define PORTE_PIN0_DIRECTION  PORT_PIN_IN
#define PORTE_PIN1_DIRECTION  PORT_PIN_IN
#define PORTE_PIN2_DIRECTION  PORT_PIN_IN
#define PORTE_PIN3_DIRECTION  PORT_PIN_IN
#define PORTE_PIN4_DIRECTION  PORT_PIN_IN
#define PORTE_PIN5_DIRECTION  PORT_PIN_IN
/* PORTF ( 5 Pins ) */
#define PORTF_PIN0_DIRECTION  PORT_PIN_IN
#define PORTF_PIN1_DIRECTION  PORT_PIN_OUT /* Led pin Should be output pin*/
#define PORTF_PIN2_DIRECTION  PORT_PIN_IN
#define PORTF_PIN3_DIRECTION  PORT_PIN_IN
#define PORTF_PIN4_DIRECTION  PORT_PIN_IN /* Switch pin should be input pin */

/****************************************************
 *     Choosen Configuration By the Tool            *
 *  "Pins Direction Changeable for all Pins"        *
 *             PORT SWS Page 42                     *
 *   Default Direction changeable is STD_OFF(0)     *
 ****************************************************/
/* PORTA ( 8 Pins ) */
#define PORTA_PIN0_DIRECTION_CHANGEABLE STD_OFF
#define PORTA_PIN1_DIRECTION_CHANGEABLE STD_OFF
#define PORTA_PIN2_DIRECTION_CHANGEABLE STD_OFF
#define PORTA_PIN3_DIRECTION_CHANGEABLE STD_OFF
#define PORTA_PIN4_DIRECTION_CHANGEABLE STD_OFF
#define PORTA_PIN5_DIRECTION_CHANGEABLE STD_OFF
#define PORTA_PIN6_DIRECTION_CHANGEABLE STD_OFF
#define PORTA_PIN7_DIRECTION_CHANGEABLE STD_OFF
/* PORTB ( 8 Pins ) */
#define PORTB_PIN0_DIRECTION_CHANGEABLE STD_OFF
#define PORTB_PIN1_DIRECTION_CHANGEABLE STD_OFF
#define PORTB_PIN2_DIRECTION_CHANGEABLE STD_OFF
#define PORTB_PIN3_DIRECTION_CHANGEABLE STD_OFF
#define PORTB_PIN4_DIRECTION_CHANGEABLE STD_OFF
#define PORTB_PIN5_DIRECTION_CHANGEABLE STD_OFF
#define PORTB_PIN6_DIRECTION_CHANGEABLE STD_OFF
#define PORTB_PIN7_DIRECTION_CHANGEABLE STD_OFF
/* PORTC ( 8 Pins ) */
#define PORTC_PIN0_DIRECTION_CHANGEABLE STD_OFF
#define PORTC_PIN1_DIRECTION_CHANGEABLE STD_OFF
#define PORTC_PIN2_DIRECTION_CHANGEABLE STD_OFF
#define PORTC_PIN3_DIRECTION_CHANGEABLE STD_OFF
#define PORTC_PIN4_DIRECTION_CHANGEABLE STD_OFF
#define PORTC_PIN5_DIRECTION_CHANGEABLE STD_OFF
#define PORTC_PIN6_DIRECTION_CHANGEABLE STD_OFF
#define PORTC_PIN7_DIRECTION_CHANGEABLE STD_OFF
/* PORTD ( 8 Pins ) */
#define PORTD_PIN0_DIRECTION_CHANGEABLE STD_OFF
#define PORTD_PIN1_DIRECTION_CHANGEABLE STD_OFF
#define PORTD_PIN2_DIRECTION_CHANGEABLE STD_OFF
#define PORTD_PIN3_DIRECTION_CHANGEABLE STD_OFF
#define PORTD_PIN4_DIRECTION_CHANGEABLE STD_OFF
#define PORTD_PIN5_DIRECTION_CHANGEABLE STD_OFF
#define PORTD_PIN6_DIRECTION_CHANGEABLE STD_OFF
#define PORTD_PIN7_DIRECTION_CHANGEABLE STD_OFF
/* PORTE ( 6 Pins ) */
#define PORTE_PIN0_DIRECTION_CHANGEABLE STD_OFF
#define PORTE_PIN1_DIRECTION_CHANGEABLE STD_OFF
#define PORTE_PIN2_DIRECTION_CHANGEABLE STD_OFF
#define PORTE_PIN3_DIRECTION_CHANGEABLE STD_OFF
#define PORTE_PIN4_DIRECTION_CHANGEABLE STD_OFF
#define PORTE_PIN5_DIRECTION_CHANGEABLE STD_OFF
/* PORTF ( 5 Pins ) */
#define PORTF_PIN0_DIRECTION_CHANGEABLE STD_OFF
#define PORTF_PIN1_DIRECTION_CHANGEABLE STD_ON  /* Led Pin Direction Changeable is off */
#define PORTF_PIN2_DIRECTION_CHANGEABLE STD_OFF
#define PORTF_PIN3_DIRECTION_CHANGEABLE STD_OFF
#define PORTF_PIN4_DIRECTION_CHANGEABLE STD_OFF /* Switch Pin Direction Changeable is off */

/****************************************************
 *     Choosen Configuration By the Tool            *
 *          "Pins IDs for all Pins"                 *
 *           PORT SWS Page 42 & 43                  *
 ****************************************************/
/* PORTA ( 8 Pins ) */
#define PORTA_PIN0_ID (Port_PinType)0
#define PORTA_PIN1_ID (Port_PinType)1
#define PORTA_PIN2_ID (Port_PinType)2
#define PORTA_PIN3_ID (Port_PinType)3
#define PORTA_PIN4_ID (Port_PinType)4
#define PORTA_PIN5_ID (Port_PinType)5
#define PORTA_PIN6_ID (Port_PinType)6
#define PORTA_PIN7_ID (Port_PinType)7
/* PORTB ( 8 Pins ) */
#define PORTB_PIN0_ID (Port_PinType)0
#define PORTB_PIN1_ID (Port_PinType)1
#define PORTB_PIN2_ID (Port_PinType)2
#define PORTB_PIN3_ID (Port_PinType)3
#define PORTB_PIN4_ID (Port_PinType)4
#define PORTB_PIN5_ID (Port_PinType)5
#define PORTB_PIN6_ID (Port_PinType)6
#define PORTB_PIN7_ID (Port_PinType)7
/* PORTC ( 8 Pins ) */
#define PORTC_PIN0_ID (Port_PinType)0
#define PORTC_PIN1_ID (Port_PinType)1
#define PORTC_PIN2_ID (Port_PinType)2
#define PORTC_PIN3_ID (Port_PinType)3
#define PORTC_PIN4_ID (Port_PinType)4
#define PORTC_PIN5_ID (Port_PinType)5
#define PORTC_PIN6_ID (Port_PinType)6
#define PORTC_PIN7_ID (Port_PinType)7
/* PORTD ( 8 Pins ) */
#define PORTD_PIN0_ID (Port_PinType)0
#define PORTD_PIN1_ID (Port_PinType)1
#define PORTD_PIN2_ID (Port_PinType)2
#define PORTD_PIN3_ID (Port_PinType)3
#define PORTD_PIN4_ID (Port_PinType)4
#define PORTD_PIN5_ID (Port_PinType)5
#define PORTD_PIN6_ID (Port_PinType)6
#define PORTD_PIN7_ID (Port_PinType)7
/* PORTE ( 6 Pins ) */
#define PORTE_PIN0_ID (Port_PinType)0
#define PORTE_PIN1_ID (Port_PinType)1
#define PORTE_PIN2_ID (Port_PinType)2
#define PORTE_PIN3_ID (Port_PinType)3
#define PORTE_PIN4_ID (Port_PinType)4
#define PORTE_PIN5_ID (Port_PinType)5
/* PORTF ( 5 Pins ) */
#define PORTF_PIN0_ID (Port_PinType)0
#define PORTF_PIN1_ID (Port_PinType)1  /* Led Pin ID */
#define PORTF_PIN2_ID (Port_PinType)2
#define PORTF_PIN3_ID (Port_PinType)3
#define PORTF_PIN4_ID (Port_PinType)4  /* Switch Pin ID */

/****************************************************
 *     Choosen Configuration By the Tool            *
 *         "Pins Modes for all Pins"                *
 *             PORT SWS Page 43                     *
 *         Default Mode is DIO Mode                 *
 ****************************************************/
/* PORTA ( 8 Pins ) */
#define PORTA_PIN0_INITIAL_MODE  PORT_PIN_MODE_DIO
#define PORTA_PIN1_INITIAL_MODE  PORT_PIN_MODE_DIO
#define PORTA_PIN2_INITIAL_MODE  PORT_PIN_MODE_DIO
#define PORTA_PIN3_INITIAL_MODE  PORT_PIN_MODE_DIO
#define PORTA_PIN4_INITIAL_MODE  PORT_PIN_MODE_DIO
#define PORTA_PIN5_INITIAL_MODE  PORT_PIN_MODE_DIO
#define PORTA_PIN6_INITIAL_MODE  PORT_PIN_MODE_DIO
#define PORTA_PIN7_INITIAL_MODE  PORT_PIN_MODE_DIO
/* PORTB ( 8 Pins ) */
#define PORTB_PIN0_INITIAL_MODE  PORT_PIN_MODE_DIO
#define PORTB_PIN1_INITIAL_MODE  PORT_PIN_MODE_DIO
#define PORTB_PIN2_INITIAL_MODE  PORT_PIN_MODE_DIO
#define PORTB_PIN3_INITIAL_MODE  PORT_PIN_MODE_DIO
#define PORTB_PIN4_INITIAL_MODE  PORT_PIN_MODE_DIO
#define PORTB_PIN5_INITIAL_MODE  PORT_PIN_MODE_DIO
#define PORTB_PIN6_INITIAL_MODE  PORT_PIN_MODE_DIO
#define PORTB_PIN7_INITIAL_MODE  PORT_PIN_MODE_DIO
/* PORTC ( 8 Pins ) */
#define PORTC_PIN0_INITIAL_MODE  PORT_PIN_MODE_DIO
#define PORTC_PIN1_INITIAL_MODE  PORT_PIN_MODE_DIO
#define PORTC_PIN2_INITIAL_MODE  PORT_PIN_MODE_DIO
#define PORTC_PIN3_INITIAL_MODE  PORT_PIN_MODE_DIO
#define PORTC_PIN4_INITIAL_MODE  PORT_PIN_MODE_DIO
#define PORTC_PIN5_INITIAL_MODE  PORT_PIN_MODE_DIO
#define PORTC_PIN6_INITIAL_MODE  PORT_PIN_MODE_DIO
#define PORTC_PIN7_INITIAL_MODE  PORT_PIN_MODE_DIO
/* PORTD ( 8 Pins ) */
#define PORTD_PIN0_INITIAL_MODE  PORT_PIN_MODE_DIO
#define PORTD_PIN1_INITIAL_MODE  PORT_PIN_MODE_DIO
#define PORTD_PIN2_INITIAL_MODE  PORT_PIN_MODE_DIO
#define PORTD_PIN3_INITIAL_MODE  PORT_PIN_MODE_DIO
#define PORTD_PIN4_INITIAL_MODE  PORT_PIN_MODE_DIO
#define PORTD_PIN5_INITIAL_MODE  PORT_PIN_MODE_DIO
#define PORTD_PIN6_INITIAL_MODE  PORT_PIN_MODE_DIO
#define PORTD_PIN7_INITIAL_MODE  PORT_PIN_MODE_DIO
/* PORTE ( 6 Pins ) */
#define PORTE_PIN0_INITIAL_MODE  PORT_PIN_MODE_DIO
#define PORTE_PIN1_INITIAL_MODE  PORT_PIN_MODE_DIO
#define PORTE_PIN2_INITIAL_MODE  PORT_PIN_MODE_DIO
#define PORTE_PIN3_INITIAL_MODE  PORT_PIN_MODE_DIO
#define PORTE_PIN4_INITIAL_MODE  PORT_PIN_MODE_DIO
#define PORTE_PIN5_INITIAL_MODE  PORT_PIN_MODE_DIO
/* PORTF ( 5 Pins ) */
#define PORTF_PIN0_INITIAL_MODE  PORT_PIN_MODE_DIO
#define PORTF_PIN1_INITIAL_MODE  PORT_PIN_MODE_DIO /* Led Pin Mode is DIO */
#define PORTF_PIN2_INITIAL_MODE  PORT_PIN_MODE_DIO
#define PORTF_PIN3_INITIAL_MODE  PORT_PIN_MODE_DIO
#define PORTF_PIN4_INITIAL_MODE  PORT_PIN_MODE_DIO /* Switch Pin Mode is DIO */

/****************************************************
 *     Choosen Configuration By the Tool            *
 *      "Pins Level Value for all Pins"             *
 *             PORT SWS Page 43                     *
 *         Default Level is Low Level               *
 ****************************************************/
/* PORTA ( 8 Pins ) */
#define PORTA_PIN0_LEVEL_VALUE      PORT_PIN_LEVEL_LOW
#define PORTA_PIN1_LEVEL_VALUE      PORT_PIN_LEVEL_LOW
#define PORTA_PIN2_LEVEL_VALUE      PORT_PIN_LEVEL_LOW
#define PORTA_PIN3_LEVEL_VALUE      PORT_PIN_LEVEL_LOW
#define PORTA_PIN4_LEVEL_VALUE      PORT_PIN_LEVEL_LOW
#define PORTA_PIN5_LEVEL_VALUE      PORT_PIN_LEVEL_LOW
#define PORTA_PIN6_LEVEL_VALUE      PORT_PIN_LEVEL_LOW
#define PORTA_PIN7_LEVEL_VALUE      PORT_PIN_LEVEL_LOW
/* PORTB ( 8 Pins ) */
#define PORTB_PIN0_LEVEL_VALUE      PORT_PIN_LEVEL_LOW
#define PORTB_PIN1_LEVEL_VALUE      PORT_PIN_LEVEL_LOW
#define PORTB_PIN2_LEVEL_VALUE      PORT_PIN_LEVEL_LOW
#define PORTB_PIN3_LEVEL_VALUE      PORT_PIN_LEVEL_LOW
#define PORTB_PIN4_LEVEL_VALUE      PORT_PIN_LEVEL_LOW
#define PORTB_PIN5_LEVEL_VALUE      PORT_PIN_LEVEL_LOW
#define PORTB_PIN6_LEVEL_VALUE      PORT_PIN_LEVEL_LOW
#define PORTB_PIN7_LEVEL_VALUE      PORT_PIN_LEVEL_LOW
/* PORTC ( 8 Pins ) */
#define PORTC_PIN0_LEVEL_VALUE      PORT_PIN_LEVEL_LOW
#define PORTC_PIN1_LEVEL_VALUE      PORT_PIN_LEVEL_LOW
#define PORTC_PIN2_LEVEL_VALUE      PORT_PIN_LEVEL_LOW
#define PORTC_PIN3_LEVEL_VALUE      PORT_PIN_LEVEL_LOW
#define PORTC_PIN4_LEVEL_VALUE      PORT_PIN_LEVEL_LOW
#define PORTC_PIN5_LEVEL_VALUE      PORT_PIN_LEVEL_LOW
#define PORTC_PIN6_LEVEL_VALUE      PORT_PIN_LEVEL_LOW
#define PORTC_PIN7_LEVEL_VALUE      PORT_PIN_LEVEL_LOW
/* PORTD ( 8 Pins ) */
#define PORTD_PIN0_LEVEL_VALUE      PORT_PIN_LEVEL_LOW
#define PORTD_PIN1_LEVEL_VALUE      PORT_PIN_LEVEL_LOW
#define PORTD_PIN2_LEVEL_VALUE      PORT_PIN_LEVEL_LOW
#define PORTD_PIN3_LEVEL_VALUE      PORT_PIN_LEVEL_LOW
#define PORTD_PIN4_LEVEL_VALUE      PORT_PIN_LEVEL_LOW
#define PORTD_PIN5_LEVEL_VALUE      PORT_PIN_LEVEL_LOW
#define PORTD_PIN6_LEVEL_VALUE      PORT_PIN_LEVEL_LOW
#define PORTD_PIN7_LEVEL_VALUE      PORT_PIN_LEVEL_LOW
/* PORTE ( 6 Pins ) */
#define PORTE_PIN0_LEVEL_VALUE      PORT_PIN_LEVEL_LOW
#define PORTE_PIN1_LEVEL_VALUE      PORT_PIN_LEVEL_LOW
#define PORTE_PIN2_LEVEL_VALUE      PORT_PIN_LEVEL_LOW
#define PORTE_PIN3_LEVEL_VALUE      PORT_PIN_LEVEL_LOW
#define PORTE_PIN4_LEVEL_VALUE      PORT_PIN_LEVEL_LOW
#define PORTE_PIN5_LEVEL_VALUE      PORT_PIN_LEVEL_LOW
/* PORTF ( 5 Pins ) */
#define PORTF_PIN0_LEVEL_VALUE      PORT_PIN_LEVEL_LOW
#define PORTF_PIN1_LEVEL_VALUE      PORT_PIN_LEVEL_LOW /* Led Pin initial value is low */
#define PORTF_PIN2_LEVEL_VALUE      PORT_PIN_LEVEL_LOW
#define PORTF_PIN3_LEVEL_VALUE      PORT_PIN_LEVEL_LOW
/* switch Pin initial value is low (will not be affected because it is input pin)*/
#define PORTF_PIN4_LEVEL_VALUE      PORT_PIN_LEVEL_LOW 

/****************************************************
 *     Choosen Configuration By the Tool            *
 *     "Pins Mode Changeable for all Pins"          *
 *             PORT SWS Page 44                     *
 *    Default Mode changeable is STD_OFF(0)         *
 ****************************************************/
/* PORTA ( 8 Pins ) */
#define PORTA_PIN0_MODE_CHANGEABLE    STD_OFF
#define PORTA_PIN1_MODE_CHANGEABLE    STD_OFF
#define PORTA_PIN2_MODE_CHANGEABLE    STD_OFF
#define PORTA_PIN3_MODE_CHANGEABLE    STD_OFF
#define PORTA_PIN4_MODE_CHANGEABLE    STD_OFF
#define PORTA_PIN5_MODE_CHANGEABLE    STD_OFF
#define PORTA_PIN6_MODE_CHANGEABLE    STD_OFF
#define PORTA_PIN7_MODE_CHANGEABLE    STD_OFF
/* PORTB ( 8 Pins ) */
#define PORTB_PIN0_MODE_CHANGEABLE    STD_OFF
#define PORTB_PIN1_MODE_CHANGEABLE    STD_OFF
#define PORTB_PIN2_MODE_CHANGEABLE    STD_OFF
#define PORTB_PIN3_MODE_CHANGEABLE    STD_OFF
#define PORTB_PIN4_MODE_CHANGEABLE    STD_OFF
#define PORTB_PIN5_MODE_CHANGEABLE    STD_OFF
#define PORTB_PIN6_MODE_CHANGEABLE    STD_OFF
#define PORTB_PIN7_MODE_CHANGEABLE    STD_OFF
/* PORTC ( 8 Pins ) */
#define PORTC_PIN0_MODE_CHANGEABLE    STD_OFF
#define PORTC_PIN1_MODE_CHANGEABLE    STD_OFF
#define PORTC_PIN2_MODE_CHANGEABLE    STD_OFF
#define PORTC_PIN3_MODE_CHANGEABLE    STD_OFF
#define PORTC_PIN4_MODE_CHANGEABLE    STD_OFF
#define PORTC_PIN5_MODE_CHANGEABLE    STD_OFF
#define PORTC_PIN6_MODE_CHANGEABLE    STD_OFF
#define PORTC_PIN7_MODE_CHANGEABLE    STD_OFF
/* PORTD ( 8 Pins ) */
#define PORTD_PIN0_MODE_CHANGEABLE    STD_OFF
#define PORTD_PIN1_MODE_CHANGEABLE    STD_OFF
#define PORTD_PIN2_MODE_CHANGEABLE    STD_OFF
#define PORTD_PIN3_MODE_CHANGEABLE    STD_OFF
#define PORTD_PIN4_MODE_CHANGEABLE    STD_OFF
#define PORTD_PIN5_MODE_CHANGEABLE    STD_OFF
#define PORTD_PIN6_MODE_CHANGEABLE    STD_OFF
#define PORTD_PIN7_MODE_CHANGEABLE    STD_OFF
/* PORTE ( 6 Pins ) */
#define PORTE_PIN0_MODE_CHANGEABLE    STD_OFF
#define PORTE_PIN1_MODE_CHANGEABLE    STD_OFF
#define PORTE_PIN2_MODE_CHANGEABLE    STD_OFF
#define PORTE_PIN3_MODE_CHANGEABLE    STD_OFF
#define PORTE_PIN4_MODE_CHANGEABLE    STD_OFF
#define PORTE_PIN5_MODE_CHANGEABLE    STD_OFF
/* PORTF ( 5 Pins ) */
#define PORTF_PIN0_MODE_CHANGEABLE    STD_OFF
#define PORTF_PIN1_MODE_CHANGEABLE    STD_OFF /* Led Mode Changeable is off */
#define PORTF_PIN2_MODE_CHANGEABLE    STD_OFF
#define PORTF_PIN3_MODE_CHANGEABLE    STD_OFF
#define PORTF_PIN4_MODE_CHANGEABLE    STD_OFF /* Switch Mode Changeable is off */




#endif