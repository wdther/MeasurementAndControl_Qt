//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ert_main.cpp
//
// Code generated for Simulink model 'pidmodel'.
//
// Model version                  : 1.24
// Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
// C/C++ source code generated on : Sat Jun  6 09:18:56 2020
//
// Target selection: ert.tlc
// Embedded hardware selection: 32-bit Generic
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include <stddef.h>
#include <stdio.h>                // This ert_main.c example uses printf/fflush
#include "pidmodel.h"                  // Model's header file
#include "rtwtypes.h"
#include<iostream>
using namespace  std;
static pidmodelModelClass pidmodel_Obj;// Instance of model class

//
// Associating rt_OneStep with a real-time clock or interrupt service routine
// is what makes the generated code "real-time".  The function rt_OneStep is
// always associated with the base rate of the model.  Subrates are managed
// by the base rate from inside the generated code.  Enabling/disabling
// interrupts and floating point context switches are target specific.  This
// example code indicates where these should take place relative to executing
// the generated code step function.  Overrun behavior should be tailored to
// your application needs.  This example simply sets an error status in the
// real-time model and returns from rt_OneStep.
//
void Pidrt_OneStep(float timeperiod);
void Pidrt_OneStep(float timeperiod)
{
  static boolean_T OverrunFlag = false;

  // Disable interrupts here

  // Check for overrun
  if (OverrunFlag) {
    rtmSetErrorStatus(pidmodel_Obj.getRTM(), "Overrun");
    return;
  }

  OverrunFlag = true;

  // Save FPU context here (if necessary)
  // Re-enable timer or interrupt here
  // Set model inputs here

  // Step the model
  pidmodel_Obj.step( timeperiod);

  // Get model outputs here

  // Indicate task complete
  OverrunFlag = false;

  // Disable interrupts here
  // Restore FPU context here (if necessary)
  // Enable interrupts here
}

//
// The example "main" function illustrates what is required by your
// application code to initialize, execute, and terminate the generated code.
// Attaching rt_OneStep to a real-time clock is target specific.  This example
// illustrates how you do this relative to initializing the model.
//
int_T main()
{

  pidmodel_Obj.initialize();

  // Attach rt_OneStep to a timer or interrupt service routine with
  //  period 0.02 seconds (the model's base sample time) here.  The
  //  call syntax for rt_OneStep is
  //

     for (int i=0 ;i<10;i++)
     {
         pidmodel_Obj.pidmodel_U.error=10;

         Pidrt_OneStep(0.02);
         cout<<pidmodel_Obj.pidmodel_Y.u;

     }

//  printf("Warning: The simulation will run forever. "
//         "Generated ERT main won't simulate model step behavior. "
//         "To change this behavior select the 'MAT-file logging' option.\n");

  // Terminate model
  pidmodel_Obj.terminate();
  return 0;
}

//
// File trailer for generated code.
//
// [EOF]
//
