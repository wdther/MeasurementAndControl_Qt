#include <stddef.h>
#include <stdio.h>                // This ert_main.c example uses printf/fflush
#include "motor.h"                     // Model's header file
#include "rtwtypes.h"
#include <iostream>
using namespace std;

static To_CdcIntrocompleteModelClass motor_Obj;// Instance of model class


void rt_OneStep(void);
void rt_OneStep(void)
{
    static boolean_T OverrunFlag = false;

    // Disable interrupts here

    // Check for overrun
    if (OverrunFlag) {
        rtmSetErrorStatus(motor_Obj.getRTM(), "Overrun");
        return;
    }

    OverrunFlag = true;

    // Save FPU context here (if necessary)
    // Re-enable timer or interrupt here
    // Set model inputs here

    // Step the model
    motor_Obj.step();

    // Get model outputs here

    // Indicate task complete
    OverrunFlag = false;

    // Disable interrupts here
    // Restore FPU context here (if necessary)
    // Enable interrupts here
}

int_T main() //int_T argc, const char *argv[]
{
  // Unused arguments
//  (void)(argc);
//  (void)(argv);

  // Initialize model
  motor_Obj.initialize();



/*  while ((rtmGetErrorStatus(motor_Obj.getRTM()) == (NULL)) &&
         !rtmGetStopRequested(motor_Obj.getRTM())) {*/
  for(int i=0;i<2;i++)
  {

      motor_Obj.motor_U.Voltage=2000;

      rt_OneStep();//
      cout<<motor_Obj.motor_Y.Outspeed<<endl;

  }

  motor_Obj.terminate();//model terminate function
  return 0;
}
