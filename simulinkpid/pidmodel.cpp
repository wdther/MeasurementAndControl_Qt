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
// C/C++ source code generated on : Sat Jun  6 09:18:56 2020
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
  real_T rtb_FilterCoefficient;

  // Gain: '<S34>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S26>/Filter'
  //   Gain: '<S25>/Derivative Gain'
  //   Inport: '<Root>/error'
  //   Sum: '<S26>/SumD'

  rtb_FilterCoefficient = (pid.Kd* pidmodel_U.error -
    pidmodel_DW.Filter_DSTATE) * pid.N; //过滤系数,可以不加入

  // Outport: '<Root>/u' incorporates:
  //   DiscreteIntegrator: '<S31>/Integrator'
  //   Gain: '<S36>/Proportional Gain'
  //   Inport: '<Root>/error'
  //   Sum: '<S40>/Sum'

  pidmodel_Y.u = (pid.Kp * pidmodel_U.error +
                  pidmodel_DW.Integrator_DSTATE) + rtb_FilterCoefficient; //最终输出

  // Update for DiscreteIntegrator: '<S31>/Integrator' incorporates:
  //   Gain: '<S28>/Integral Gain'
  //   Inport: '<Root>/error'

  pidmodel_DW.Integrator_DSTATE += pid.Ki * pidmodel_U.error * timeperiod; //积分状态

  // Update for DiscreteIntegrator: '<S26>/Filter'
  pidmodel_DW.Filter_DSTATE += timeperiod * rtb_FilterCoefficient; //过滤器，可以忽略
}

// Model initialize function
void pidmodelModelClass::initialize()
{
  // Registration code

  // states (dwork)
  pidmodel_DW.Integrator_DSTATE = 0.0;
  pidmodel_DW.Filter_DSTATE = 0.0;

  // external inputs
  pidmodel_U.error = 0.0;

  // external outputs
  pidmodel_Y.u = 0.0;
  pid.Kp=21.143;
  pid.Ki=53.956;
  pid.Kd=1.14170;
  pid.N=81.23589;



}
void pidmodelModelClass::parainit()
{

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
