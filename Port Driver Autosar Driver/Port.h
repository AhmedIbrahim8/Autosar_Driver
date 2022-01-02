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
#define PORT_NOT_INITIALIZED               (0U)

#include "Std_Types"
#if ((PORT_AR_RELEASE_MAJOR_VERSION!=STD_TYPES_AR_RELEASE_MAJOR_VERSION)\
  || (PORT_AR_RELEASE_MINOR_VERSION!=STD_TYPES_AR_RELEASE_MINOR_VERSION)\
  || (PORT_AR_RELEASE_PATCH_VERSION!=STD_TYPES_AR_RELEASE_PATCH_VERSION))
   #error "The Autosar Version of Std_Types doesn't match the version of Port driver"
#endif

/* Not Autosar File */
#include "Common_Macros"


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

typedef struct{
  
}Port_ConfigChannel;


typedef struct{
  Port_ConfigChannel channels[43];
}Port_ConfigType,


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
void Port_SetPinMode( Port_PinType Pin, Port_PinModeType Mode );
#endif

#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
/* The function Port_SetPinDirection shall set the port pin direction during runtime */
void Port_SetPinDirection( Port_PinType Pin, Port_PinDirectionType Direction );
#endif


#endif
