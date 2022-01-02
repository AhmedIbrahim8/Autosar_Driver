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
 *                              API Service Id                                *
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


#endif
