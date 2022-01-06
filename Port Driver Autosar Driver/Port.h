/******************************************************
*
* Module      : Port
*
* File Name   : Port.h
*
* Description : Header file for TM4C123GH6PM Microcontroller - Port Driver
*
*Author       : Ahmed Ibrahim
*******************************************************/

#ifndef PORT_H
#define PORT_H

/* ID of the Company in the Autosar */
#define PORT_VENDOR_ID            (1000U)

/* Port Module ID*/
#define PORT_MODULE_ID            (124U)

/* Port Instance ID */
#define PORT_INSTANCE_ID          (0U)

/* SoftWare Module Version */
#define PORT_SW_MAJOR_VERSION     (1U)
#define PORT_SW_MINOR_VERSION     (0U)
#define PORT_SW_PATCH_VERSION     (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_AR_RELEASE_MAJOR_VERSION   (4U)
#define PORT_AR_RELEASE_MINOR_VERSION   (0U)
#define PORT_AR_RELEASE_PATCH_VERSION   (3U)

/* Defines for Port status */
#define PORT_INITIALIZED               (1U)
#define PORT_NOT_INITIALIZED           (0U)

#include "Std_Types.h"
/* Check The Autosar Version between Port.h and Std_Types.h */
#if ((PORT_AR_RELEASE_MAJOR_VERSION!=STD_TYPES_AR_RELEASE_MAJOR_VERSION)\
  || (PORT_AR_RELEASE_MINOR_VERSION!=STD_TYPES_AR_RELEASE_MINOR_VERSION)\
  || (PORT_AR_RELEASE_PATCH_VERSION!=STD_TYPES_AR_RELEASE_PATCH_VERSION))
   #error "The Autosar Version of Std_Types.h doesn't match the version of Port.h driver"
#endif

#include "Port_Cfg.h"
/* The Autosar Version and Software Version between Port.h and Port_Cfg.h must be the same 
   Because Port_Cfg.h belongs to the Port.h so it must be the same 2 version               */

/* Check The Software Version between Port.h and Port_Cfg.h */
#if ((PORT_SW_MAJOR_VERSION!=PORT_CFG_SW_MAJOR_VERSION)\
  || (PORT_SW_MINOR_VERSION!=PORT_CFG_SW_MINOR_VERSION)\
  || (PORT_SW_PATCH_VERSION!=PORT_CFG_SW_PATCH_VERSION))
   #error "The Software Version of Port_Cfg.h doesn't match the version of Port.h driver"
#endif

/* Check The Autosar Version between Port.h and Port_Cfg.h */
#if ((PORT_AR_MAJOR_VERSION!=PORT_CFG_AR_MAJOR_VERSION)\
  || (PORT_AR_MINOR_VERSION!=PORT_CFG_AR_MINOR_VERSION)\
  || (PORT_AR_PATCH_VERSION!=PORT_CFG_AR_PATCH_VERSION))
   #error "The Autosar Version of Port_Cfg.h doesn't match the version of Port.h driver"
#endif


/* Not Autosar File */
#include "Common_Macros.h"


/******************************************************************************
 *                              API Service IDs                                *
 ******************************************************************************/
/* Service ID of Port_Init */
#define PORT_INIT_SID                                (uint8)0x00

/* Sercive ID of Port_SetPinDirection Function      */
#define PORT_SET_PIN_DIRECTION_SID                   (uint8)0x01

/* Sercive ID of Port_RefreshPortDirection Function */
#define PORT_REFRESH_PORT_DIRECTION_SID              (uint8)0x02

/* Sercive ID of Port_GetVersionInfo Function       */
#define PORT_GET_VERSION_INFO_SID                    (uint8)0x03

/* Sercive ID of Port_SetPinMode Function           */
#define PORT_SET_PIN_MODE_SID                        (uint8)0x04

/*******************************************************************************
 *                               DET Error IDs                                 *
 *******************************************************************************/
/* Det ID incase of invalid port pin id                             */
#define  PORT_E_PARAM_PIN                  (uint8)0x0A

/* Det ID incase of port pin direction not configured as changeable */
#define  PORT_E_DIRECTION_UNCHANGEABLE     (uint8)0x0B

/* Det ID incase of Port_Init Function is called with NULL pointer  */
#define  PORT_E_PARAM_CONFIG               (uint8)0x0C

/* Det ID incase of Port_SetPinMode is called with wrong mode       */
#define  PORT_E_PARAM_INVALID_MODE         (uint8)0x0D

/* Det ID incase of Port pin mode not configured as changeable      */
#define  PORT_E_MODE_UNCHANGEABLE          (uint8)0x0E

/* Det ID incase of API service is called without initialization    */
#define  PORT_E_UNINIT                     (uint8)0x0F

/* Det ID incase of APIs called with a Null Pointer                 */
#define  PORT_E_PARAM_POINTER              (uint8)0x10


/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/
/* Data type for the symbolic name of a port pin */
typedef uint8 Port_PinType;

/* Possible directions of a port pin             */
typedef enum{
  PORT_PIN_IN,PORT_PIN_OUT
}Port_PinDirectionType;

/* Different port pin modes                      */
typedef uint8 Port_PinModeType;

/* Not Autosar Type */
typedef uint8 Port_PortType;

/* Not Autosar Type */
typedef enum{
  OFF,PULL_UP,PULL_DOWN
}Port_InternalResistor;

/* Not Autosar Type */
typedef enum{
  PORT_PIN_LEVEL_LOW,PORT_PIN_LEVEL_HIGH
}Port_PinLevelValue;
/* Not Autosar Type */
typedef struct{
  Port_PinDirectionType direction;
  Port_InternalResistor resistor;
  Port_PinLevelValue initial_value;
  Port_PortType port_num;
  Port_PinType pin_num;
  Port_PinModeType mode;
  boolean direction_changeable;
  boolean mode_changeable;
}Port_ConfigChannel;

/* Data structure containing the initialization data for the PORT Driver */
typedef struct{
  Port_ConfigChannel channels[PORT_CONFIGURED_PINS];
}Port_ConfigType;



/*******************************************************************************
 *                                Nedded #s                                    *
 * These #s is needed in the configuration structure to indicate which port is *
 * used.                                                                       *
 *******************************************************************************/
#define PORTA_ID       (Port_PortType)0 
#define PORTB_ID       (Port_PortType)1
#define PORTC_ID       (Port_PortType)2
#define PORTD_ID       (Port_PortType)3
#define PORTE_ID       (Port_PortType)4
#define PORTF_ID       (Port_PortType)5
/********************************************************************************
 *  #s needed for Misra rules (No number in the Codes)                          *                                                  *
 ********************************************************************************/
#define FIRST_LOOP              (0U)
#define MAGIC_NUMBER        (0x4C4F434B)
#define SPECIAL_PIN_PC7         (7U)
#define SPECIAL_PIN_PF0         (0U)
#define JTAG_PIN_PC0            (0U)
#define JTAG_PIN_PC1            (1U)
#define JTAG_PIN_PC2            (2U)
#define JTAG_PIN_PC3            (3U)
#define CONTROL_REGISTER_MASK  0x0000000F
#define BIT_SHIFT               (4U)
#define CAN_MODE_8              0x00000008
#define CAN_MODE_3              0x00000003
#define I2C_MODE                0x00000003
#define DIO_GPT_MODE            0x00000007
#define DIGITAL_COMPARATOR_MODE 0x00000009
#define USB_DIGITAL_MODE        0x00000008
#define NMI_MODE                0x00000008
#define TRACE_DATA_MODE         0x0000000E /* Number 14 in hexa is E */
#define QEI_MODE                0x00000006
#define SPI_MODE_1              0x00000001
#define SPI_MODE_2              0x00000002
#define PWM0_MODE               0x00000004
#define PWM1_MODE               0x00000005
#define UART_MODE               0x00000001
/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

/* The function Port_Init shall initialize ALL ports and port pins 
   with the configuration set pointed to by the parameter ConfigPtr                  */
void Port_Init( const Port_ConfigType* ConfigPtr );


/* The function Port_RefreshPortDirection shall refresh the direction of 
   all configured ports to the configured direction (PortPinDirection)               */
void Port_RefreshPortDirection( void );

#if (PORT_VERSION_INFO_API == STD_ON)
/* The function Port_GetVersionInfo shall return the version information of this module. 
   The version information includes:
                                   - Module Id
                                   - Vendor Id
                                   - Vendor specific version numbers (BSW00407)      */
void Port_GetVersionInfo( Std_VersionInfoType* versioninfo );
#endif

#if (PORT_SET_PIN_MODE_API == STD_ON)
/* The function Port_SetPinMode shall set the port pin mode of 
   the referenced pin during runtime                                                 */
void Port_SetPinMode( Port_PinType Pin, 
                      Port_PinModeType Mode );
#endif


#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
/* The function Port_SetPinDirection shall set the port pin direction during runtime */
void Port_SetPinDirection( Port_PinType Pin,
                           Port_PinDirectionType Direction );
#endif

/*******************************************************************************
 *                              External Variables                             *
 *******************************************************************************/
extern const Port_ConfigType Port_Configuration;

#endif
