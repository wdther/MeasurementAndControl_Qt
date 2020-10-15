//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: pidmodel.cpp
//
// Code generated for Simulink model 'pidmodel'.
//
// Model version                  : 1.24
// Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
// C/C++ source code generated on : Sat Jun  6 10:55:35 2020
//
// Target selection: ert.tlc
// Embedded hardware selection: 32-bit Generic
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "pidmodel.h"
#include "pidmodel_private.h"

// Model step function
void pidmodelModelClass::step(float timeperiod)
{
  real_T rtb_TSamp;

  // SampleTimeMath: '<S26>/TSamp' incorporates:
  //   Gain: '<S25>/Derivative Gain'
  //   Inport: '<Root>/error'
  //
  //  About '<S26>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  rtb_TSamp = pid.Kd * pidmodel_U.error * 1/timeperiod;

  // Outport: '<Root>/u' incorporates:
  //   Delay: '<S26>/UD'
  //   DiscreteIntegrator: '<S31>/Integrator'
  //   Gain: '<S36>/Proportional Gain'
  //   Inport: '<Root>/error'
  //   Sum: '<S26>/Diff'
  //   Sum: '<S40>/Sum'

  pidmodel_Y.u = (pid.Kp * pidmodel_U.error +
                  pidmodel_DW.Integrator_DSTATE) + (rtb_TSamp -
    pidmodel_DW.UD_DSTATE);

  // Update for DiscreteIntegrator: '<S31>/Integrator' incorporates:
  //   Gain: '<S28>/Integral Gain'
  //   Inport: '<Root>/error'

  pidmodel_DW.Integrator_DSTATE += pid.Ki * pidmodel_U.error *timeperiod;

  // Update for Delay: '<S26>/UD'
  pidmodel_DW.UD_DSTATE = rtb_TSamp;
}

// Model initialize function
void pidmodelModelClass::initialize()
{
  // Registration code

  // states (dwork)
  pidmodel_DW.Integrator_DSTATE = 0.0;
  pidmodel_DW.UD_DSTATE = 0.0;

  // external inputs
  pidmodel_U.error = 0.0;

  // external outputs
  pidmodel_Y.u = 0.0;
    pid.Kp=21.143;
    pid.Ki=53.956;
    pid.Kd=1.14170;
}
void pidmodelModelClass::parainit(float Kp,float Ki,float Kd)
{
    pid.Kp=Kp;
    pid.Ki=Ki;
    pid.Kd=Kd;
}

// Model terminate function
void pidmodelModelClass::terminate()
{
  // (no terminate code required)
}

// Constructor
pidmodelModelClass::pidmodelModelClass() : pidmodel_M()
{
  // Currently there is no constructor body generated.
}

// Destructor
pidmodelModelClass::~pidmodelModelClass()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
RT_MODEL_pidmodel_T * pidmodelModelClass::getRTM()
{
  return (&pidmodel_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
