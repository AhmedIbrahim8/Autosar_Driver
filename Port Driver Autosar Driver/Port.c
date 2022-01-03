 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.c
 *
 * Description: Source file for TM4C123GH6PM Microcontroller - Port Driver
 *
 * Author: Ahmed Ibrahim
 ******************************************************************************/

#include "Port.h"
#include "Port_Regs.h"

/* If the development error is off, no need to include Det.h*/
#if (PORT_DEV_ERROR_DETECT == STD_HIGH)

#include "Det.h"
/* Check the Autosar Version Between Det.h and Port.h */
#if ((PORT_AR_RELEASE_MAJOR_VERSION != DET_AR_MAJOR_VERSION)\
  || (PORT_AR_RELEASE_MINOR_VERSION != DET_AR_MINOR_VERSION)\
  || (PORT_AR_RELEASE_PATCH_VERSION != DET_AR_PATCH_VERSION))
#error "The Autosar Version of Det.h doesn't match the version of Port.h.h"

#endif


STATIC const Port_ConfigChannel *Port_Channels =NULL_PTR;
/* Variable to store the condition of the port driver ( initialized or not )*/
uint8 Port_Status = PORT_NOT_INITIALIZED;

/************************************************************************************
* Service Name: Port_Init
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): ConfigPtr - Pointer to configuration data
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Initialize the Port module.
************************************************************************************/
void Port_Init( const Port_ConfigType* ConfigPtr )
{
  /* local variable used to loop of the configuration array       */
  uint8 counter;
  /* local variable to store the base address of the GPIO Register*/
  volatile uint32 *Port_Base_Address_Ptr = NULL_PTR;
  /* To wait three(3) seconds untill clock reach the Port */
  volatile uint8 dealy;
  
#if (PORT_DEV_ERROR_DETECT == STD_HIGH)
  if(ConfigPtr == NULL_PTR){
    Det_ReportError(PORT_MODULE_ID,
                    PORT_INSTANCE_ID,
                    PORT_INIT_SID,
                    PORT_E_PARAM_CONFIG);
  }
  else
#endif
  {
    /* Intializing the Port so, the status should be updated */
    Port_Status= PORT_INITIALIZED;
    /* Port_channels is variable from type Port_ConfigChannel             *
     * ConfigPtr is variable from type Port_ConfigType                    *
     * Here, Port_Channels will point to the first array in the structure */
    Port_Channels = ConfigPtr->channels;
    for(counter=FIRST_LOOP;counter<PORT_CONFIGURED_PINS;counter++)
    {
      switch(Port_Channels[counter].port_num)
      {
        /* PORTA Base Address */
      case PORTA_ID:
        Port_Base_Address_Ptr =(volatile uint32*)GPIO_PORTA_BASE_ADDRESS;
        break;
        /* PORTB Base Address */
      case PORTB_ID:
        Port_Base_Address_Ptr =(volatile uint32*)GPIO_PORTB_BASE_ADDRESS;
        break;
        /* PORTC Base Address */
      case PORTC_ID:
        Port_Base_Address_Ptr =(volatile uint32*)GPIO_PORTC_BASE_ADDRESS;
        break;
        /* PORTD Base Address */
      case PORTD_ID:
        Port_Base_Address_Ptr =(volatile uint32*)GPIO_PORTD_BASE_ADDRESS;
        break;
        /* PORTE Base Address */
      case PORTE_ID:
        Port_Base_Address_Ptr =(volatile uint32*)GPIO_PORTE_BASE_ADDRESS;
        break;
        /* PORTF Base Address */
      case PORTF_ID:
        Port_Base_Address_Ptr =(volatile uint32*)GPIO_PORTF_BASE_ADDRESS;
        break;
        /* (Misra Rules) */
      default:
        /* NO Action is needed (Misra Rules)*/
        break;
      }
      /* Initiate the clock of the Port*/
      SET_BIT(SYSCTL_REGCGC2_REG,Port_Channels[counter].port_num);
      /* To wait 3-seconds (Equal Operation takes 3-seconds )*/
      dealy=SYSCTL_REGCGC2_REG;
      /* Important check : In TivaC PC7 & PF0 are special pins which *
       *                   are needed to be unlocked first before    *
       *                   write in it                               */
      if(((Port_Channels[counter].port_num == PORTC_ID) && (Port_Channels[counter].pin_num == SPECIAL_PIN_PC7))\
       ||((Port_Channels[counter].port_num == PORTF_ID) && (Port_Channels[counter].pin_num == SPECIAL_PIN_PF0)))
      {
        /* To unlock the commit register we put the magic number which is defined in port.h */
        *(volatile uint32 *)((volatile uint8 *)Port_Base_Address_Ptr+PORT_LOCK_REG_OFFSET)= MAGIC_NUMBER;
        /* Commit the pin based on the pin_num */
        SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Base_Address_Ptr+PORT_COMMIT_REG_OFFSET),Port_Channels[counter].pin_num);
      }
      /* Misra Rules */
      else
      {
        /* No Action nedded */
      }
      
      /* Check the direction of the pins                                *
       * if input pin :it should determine pull-up internal resistor    *
       *               or pull-down internal resistor or off based on   *
       *               the configuration structure                      *
       * if output pin:it should initiate the pin with the initial value*
       *               based on the configuration structure             *
       ******************************************************************/
      if(Port_Channels[counter].direction == PORT_PIN_IN)
      {
        /* Pin is input so zero(0) should be put in the bit number at the Direction Register */
        CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Base_Address_Ptr+PORT_DIR_REG_OFFSET),Port_Channels[counter].pin_num);
        /* if Internal Resistor = Pull Down */
        if(Port_Channels[counter].resistor == PULL_DOWN)
        {
          SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Base_Address_Ptr+PORT_PULL_DOWN_REG_OFFSET),Port_Channels[counter].pin_num);
        }
        /* if Internal Resistor = Pull Up */
        else if(Port_Channels[counter].resistor == PULL_UP)
        {
          SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Base_Address_Ptr+PORT_PULL_UP_REG_OFFSET),Port_Channels[counter].pin_num);
        }
        /* if Internal Resistor = off */
        else
        {
          CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Base_Address_Ptr+PORT_PULL_UP_REG_OFFSET),Port_Channels[counter].pin_num);
          CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Base_Address_Ptr+PORT_PULL_DOWN_REG_OFFSET),Port_Channels[counter].pin_num);
        }
        
      }
      else if(Port_Channels[counter].direction == PORT_PIN_OUT)
      {
        /* Pin is output so one(1) should be put in the bit number at the Direction Register */
        SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Base_Address_Ptr+PORT_DIR_REG_OFFSET),Port_Channels[counter].pin_num);
        /* if initial value of the pin equal zero */
        if(Port_Channels[counter].initial_value == ZERO)
        {
          CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Base_Address_Ptr+PORT_DATA_REG_OFFSET),Port_Channels[counter].pin_num);
        }
        /* if initial value of the pin equal one */
        else if(Port_Channels[counter].initial_value == ONE)
        {
          SET_BIT(,Port_Channels[counter].pin_num);
        }
        /* Misra Rules */
        else
        {
          /* No Action Needed*/
        }
      }
      /* Misra Rules */
      else
      {
        /* No Action nedded*/
      }
      
      /* Check the modes to adjust : - Control Register           *
       *                             - Alernative Register        *
       *                             - Analog Register            *
       *                             - Digital Register           *
       ************************************************************/
     
      
    }/* End Of For Loop*/
  
  
  }  /* End Of else */
  
  
}    /* End of Port_Init() */



/************************************************************************************
* Service Name: Port_SetPinDirection
* Service ID[hex]: 0x01
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): - Pin       : Port Pin ID Number
*                  - Direction : Port Pin Direction
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to set the port pin direction at runtime.
************************************************************************************/
void Port_SetPinDirection( Port_PinType Pin, 
                           Port_PinDirectionType Direction )
{
  
  
}













/************************************************************************************
* Service Name: Port_RefreshPortDirection
* Service ID[hex]: 0x02
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to refresh port direction.
************************************************************************************/
void Port_RefreshPortDirection( void )
{
  
  
}

/************************************************************************************
* Service Name: Port_GetVersionInfo
* Service ID[hex]: 0x03
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): versioninfo : Pointer to where to store the version information 
*                                 of this module.
* Return value: None
* Description: Function to return the version information of the module.
************************************************************************************/
void Port_GetVersionInfo( Std_VersionInfoType* versioninfo )
{
  
}




/************************************************************************************
* Service Name: Port_SetPinMode
* Service ID[hex]: 0x04
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): - Pin  : Port Pin ID Number
*                  - Mode : New Port Pin mode to be set on port pin
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to set the port pin mode at runtime.
************************************************************************************/
void Port_SetPinMode( Port_PinType Pin, 
                     Port_PinModeType Mode )
{
  
  
}





#endif
