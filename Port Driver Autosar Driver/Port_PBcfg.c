 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port_PBcfg.c
 *
 * Description: Post Build Configuration Source file for TM4C123GH6PM Microcontroller - Port Driver
 *
 * Author: Ahmed Ibrahim
 ******************************************************************************/

#include "Port.h"

/* SoftWare Module Version */
#define PORT_PBCFG_SW_MAJOR_VERSION           (1U)
#define PORT_PBCFG_SW_MINOR_VERSION           (0U)
#define PORT_PBCFG_SW_PATCH_VERSION           (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_PBCFG_AR_RELEASE_MAJOR_VERSION   (4U)
#define PORT_PBCFG_AR_RELEASE_MINOR_VERSION   (0U)
#define PORT_PBCFG_AR_RELEASE_PATCH_VERSION   (3U)


/* Check The Software Version between Port.h and Port_PBcfg.c */
#if ((PORT_SW_MAJOR_VERSION!=PORT_PBCFG_SW_MAJOR_VERSION)\
  || (PORT_SW_MINOR_VERSION!=PORT_PBCFG_SW_MINOR_VERSION)\
  || (PORT_SW_PATCH_VERSION!=PORT_PBCFG_SW_PATCH_VERSION))
   #error "The Software Version of Port_PBcfg.c doesn't match the version of Port.h driver"
#endif


/* Check The Autosar Version between Port.h and Port_PBcfg.c */
#if ((PORT_AR_RELEASE_MAJOR_VERSION!=PORT_PBCFG_AR_RELEASE_MAJOR_VERSION)\
  || (PORT_AR_RELEASE_MINOR_VERSION!=PORT_PBCFG_AR_RELEASE_MINOR_VERSION)\
  || (PORT_AR_RELEASE_PATCH_VERSION!=PORT_PBCFG_AR_RELEASE_PATCH_VERSION))
   #error "The Autosar Version of Port_PBcfg.c doesn't match the version of Port.h driver"
#endif
   
   
