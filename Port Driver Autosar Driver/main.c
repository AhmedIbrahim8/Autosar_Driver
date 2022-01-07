#include "Port.h"
#include "Det.h"
#include <assert.h>

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

void TestCase1(void)
{

}

int main()
{
  
  Port_Init(&Port_Configuration);
  
  while(1)
  {
    
  }
  
}
