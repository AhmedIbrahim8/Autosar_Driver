#include "Port.h"
#include "Det.h"
#include <assert.h>
/* # used in Test Case 3 and 4 */
#define PORT_PIN_INDEX_OUT_OF_RANGE          (100U)
#define PORT_PIN_MODE_NO_THING               (100U)

boolean Det_TestLastReportError(uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId) 
{
    boolean result = (Det_ModuleId == ModuleId) && (Det_InstanceId == InstanceId) && 
                     (Det_ApiId == ApiId) && (Det_ErrorId == ErrorId);
    Det_ModuleId = 0;
    Det_InstanceId = 0;
    Det_ApiId = 0;
    Det_ErrorId = 0;
    
    return result;
}
  /************************************************************************************
* Test ID :TestCase1
* Description: Test for Port_Init and Port_GetVersionInfo API's report the correct DET 
*              error in case the API called with NULL pointer.
* Pre-requisits: No Need
* Test Procedure : 1. Call Dio_Init DET error DIO_E_PARAM_CONFIG should be reported.
*                  2. Call Dio_GetVersionInfo DET error DIO_E_PARAM_POINTER should be reported.
*************************************************************************************/
void TestCase1(){
  Port_Init(NULL_PTR);
  assert(Det_TestLastReportError(PORT_MODULE_ID,PORT_INSTANCE_ID,PORT_INIT_SID,PORT_E_PARAM_CONFIG));
#if (PORT_VERSION_INFO_API == STD_ON)
  Port_GetVersionInfo(NULL_PTR);
  assert(Det_TestLastReportError(PORT_MODULE_ID,PORT_INSTANCE_ID,PORT_GET_VERSION_INFO_SID,PORT_E_PARAM_POINTER));
#endif
}

  /********************************************************************************************************
* Test ID :TestCase2
* Description: Test for Port_SetPinDirection, Port_SetPinMode and Port_RefreshPortDirection API's report
               the correct DET error in case Port_Init is not initialized .
* Pre-requisits: Port_Init must not initialized and TestCase1 is done.
* Test Procedure : 1. Call Port_SetPinDirection, DET error PORT_E_UNINIT should be reported.
*                  2. Call Port_SetPinMode, DET error PORT_E_UNINIT should be reported.
*                  3. Call Port_RefreshPortDirection. DET error PORT_E_UNINIT should be reported.
***********************************************************************************************************/
void TestCase2()
{
  Port_SetPinDirection(PORTA_PIN0_ID_INDEX,PORT_PIN_OUT);
  assert(Det_TestLastReportError(PORT_MODULE_ID,PORT_INSTANCE_ID,PORT_SET_PIN_DIRECTION_SID,PORT_E_UNINIT));
  Port_SetPinMode(PORTA_PIN0_ID_INDEX,PORT_PIN_MODE_UART);
  assert(Det_TestLastReportError(PORT_MODULE_ID,PORT_INSTANCE_ID,PORT_SET_PIN_MODE_SID,PORT_E_UNINIT));
  Port_RefreshPortDirection();
  assert(Det_TestLastReportError(PORT_MODULE_ID,PORT_INSTANCE_ID,PORT_REFRESH_PORT_DIRECTION_SID,PORT_E_UNINIT));
}

  /********************************************************************************************************
* Test ID :TestCase3
* Description: Test for Port_SetPinDirection and Port_SetPinMode API's to report the correct DET error in 
*              case of Pin Index is equal or greater than the PORT_CONFIGURED_PINS .
* Pre-requisits: Port_Init must be initialized and TestCase2 is done.
* Test Procedure : 1. Call Port_SetPinDirection, DET error PORT_E_PARAM_PIN should be reported.
*                  2. Call Port_SetPinMode, DET error PORT_E_PARAM_PIN should be reported.
***********************************************************************************************************/
void TestCase3()
{  
  Port_SetPinDirection(PORT_PIN_INDEX_OUT_OF_RANGE,PORT_PIN_OUT);
  assert(Det_TestLastReportError(PORT_MODULE_ID,PORT_INSTANCE_ID,PORT_SET_PIN_DIRECTION_SID,PORT_E_PARAM_PIN));
  Port_SetPinMode(PORT_PIN_INDEX_OUT_OF_RANGE,PORT_PIN_MODE_ADC);
  assert(Det_TestLastReportError(PORT_MODULE_ID,PORT_INSTANCE_ID,PORT_SET_PIN_MODE_SID,PORT_E_PARAM_PIN));
}

  /********************************************************************************************************
* Test ID :TestCase4
* Description: Test for Port_SetPinMode API to report the correct DET error in case of Invalid Pin Mode. 
* Pre-requisits: Port_Init must be initialized and TestCase2 is done.
* Test Procedure : 1. Call Port_SetPinMode, DET error PORT_E_PARAM_INVALID_MODE should be reported.
***********************************************************************************************************/
void TestCase4()
{  
  Port_SetPinMode(PORTA_PIN0_ID_INDEX,PORT_PIN_MODE_NO_THING);
  assert(Det_TestLastReportError(PORT_MODULE_ID,PORT_INSTANCE_ID,PORT_SET_PIN_MODE_SID,PORT_E_PARAM_INVALID_MODE));
}


  /********************************************************************************************************
* Test ID :TestCase5
* Description: Test for Port_SetPinDirection and Port_SetPinMode API's to report the correct DET error in 
*              case of Mode or Direction are unchangeable (STD_OFF)
* Pre-requisits: Port_Init must be initialized and TestCase4 is done.
* Test Procedure : 1. Call Port_SetPinDirection, DET error PORT_E_DIRECTION_UNCHANGEABLE should be reported.
*                  2. Call Port_SetPinMode, DET error PORT_E_MODE_UNCHANGEABLE should be reported.
***********************************************************************************************************/
void TestCase5()
{
  Port_SetPinDirection(PORTA_PIN0_ID_INDEX,PORT_PIN_OUT);
  assert(Det_TestLastReportError(PORT_MODULE_ID,PORT_INSTANCE_ID,PORT_SET_PIN_DIRECTION_SID,PORT_E_DIRECTION_UNCHANGEABLE));
  Port_SetPinMode(PORTA_PIN0_ID_INDEX,PORT_PIN_MODE_UART);
  assert(Det_TestLastReportError(PORT_MODULE_ID,PORT_INSTANCE_ID,PORT_SET_PIN_MODE_SID,PORT_E_MODE_UNCHANGEABLE));
  
}


int main()
{
  TestCase1();
  TestCase2();
  
  Port_Init(&Port_Configuration);
  TestCase3();
  TestCase4();
  TestCase5();
  
  
  while(1)
  {
    
  }
  
}
