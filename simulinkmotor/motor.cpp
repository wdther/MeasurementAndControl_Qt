//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: motor.cpp
//
// Code generated for Simulink model 'motor'.
//
// Model version                  : 1.25
// Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
// C/C++ source code generated on : Fri Jun  5 21:24:33 2020
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "motor.h"
#include "motor_private.h"

//
// This function updates continuous states using the ODE3 fixed-step
// solver algorithm
//
void To_CdcIntrocompleteModelClass::rt_ertODEUpdateContinuousStates
  (RTWSolverInfo *si )
{
  // Solver Matrices
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = static_cast<ODE3_IntgData *>(rtsiGetSolverData(si));
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  // Save the state values at time t in y, we'll use x as ynew.
  (void) std::memcpy(y, x,
                     static_cast<uint_T>(nXc)*sizeof(real_T));

  // Assumes that rtsiSetT and ModelOutputs are up-to-date
  // f0 = f(t,y)
  rtsiSetdX(si, f0);
  motor_derivatives();

  // f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*));
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  this->step();
  motor_derivatives();

  // f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*));
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  this->step();
  motor_derivatives();

  // tnew = t + hA(3);
  // ynew = y + f*hB(:,3);
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

// Model step function
void To_CdcIntrocompleteModelClass::step()
{
  if (rtmIsMajorTimeStep((&motor_M))) {
    // set solver stop time
    rtsiSetSolverStopTime(&(&motor_M)->solverInfo,(((&motor_M)
      ->Timing.clockTick0+1)*(&motor_M)->Timing.stepSize0));
  }                                    // end MajorTimeStep

  // Update absolute time of base rate at minor time step
  if (rtmIsMinorTimeStep((&motor_M))) {
    (&motor_M)->Timing.t[0] = rtsiGetT(&(&motor_M)->solverInfo);
  }

  // SignalConversion generated from: '<S1>/State-Space' incorporates:
  //   Constant: '<Root>/Torque '
  //   Inport: '<Root>/Voltage'

  motor_B.TmpSignalConversionAtStateSpace[0] = motor_U.Voltage;
  motor_B.TmpSignalConversionAtStateSpace[1] = 0.0;

  // Outport: '<Root>/Outspeed' incorporates:
  //   StateSpace: '<S1>/State-Space'

  motor_Y.Outspeed = motor_X.StateSpace_CSTATE[0];
  if (rtmIsMajorTimeStep((&motor_M))) {
    rt_ertODEUpdateContinuousStates(&(&motor_M)->solverInfo);

    // Update absolute time for base rate
    // The "clockTick0" counts the number of times the code of this task has
    //  been executed. The absolute time is the multiplication of "clockTick0"
    //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
    //  overflow during the application lifespan selected.

    ++(&motor_M)->Timing.clockTick0;
    (&motor_M)->Timing.t[0] = rtsiGetSolverStopTime(&(&motor_M)->solverInfo);

    {
      // Update absolute timer for sample time: [0.02s, 0.0s]
      // The "clockTick1" counts the number of times the code of this task has
      //  been executed. The resolution of this integer timer is 0.02, which is the step size
      //  of the task. Size of "clockTick1" ensures timer will not overflow during the
      //  application lifespan selected.

      (&motor_M)->Timing.clockTick1++;
    }
  }                                    // end MajorTimeStep
}

// Derivatives for root system: '<Root>'
void To_CdcIntrocompleteModelClass::motor_derivatives()
{
  XDot_motor_T *_rtXdot;
  _rtXdot = ((XDot_motor_T *) (&motor_M)->derivs);

  // Derivatives for StateSpace: '<S1>/State-Space'
  _rtXdot->StateSpace_CSTATE[0] = 0.0;
  _rtXdot->StateSpace_CSTATE[1] = 0.0;
  _rtXdot->StateSpace_CSTATE[0] += -10.0 * motor_X.StateSpace_CSTATE[0];
  _rtXdot->StateSpace_CSTATE[0] += motor_X.StateSpace_CSTATE[1];
  _rtXdot->StateSpace_CSTATE[1] += -0.02 * motor_X.StateSpace_CSTATE[0];
  _rtXdot->StateSpace_CSTATE[1] += -2.0 * motor_X.StateSpace_CSTATE[1];
  _rtXdot->StateSpace_CSTATE[0] += -100.0 *
    motor_B.TmpSignalConversionAtStateSpace[1];
  _rtXdot->StateSpace_CSTATE[1] += 2.0 *
    motor_B.TmpSignalConversionAtStateSpace[0];
}

// Model initialize function
void To_CdcIntrocompleteModelClass::initialize()
{
  // Registration code
  {
    // Setup solver object
    rtsiSetSimTimeStepPtr(&(&motor_M)->solverInfo, &(&motor_M)
                          ->Timing.simTimeStep);
    rtsiSetTPtr(&(&motor_M)->solverInfo, &rtmGetTPtr((&motor_M)));
    rtsiSetStepSizePtr(&(&motor_M)->solverInfo, &(&motor_M)->Timing.stepSize0);
    rtsiSetdXPtr(&(&motor_M)->solverInfo, &(&motor_M)->derivs);
    rtsiSetContStatesPtr(&(&motor_M)->solverInfo, (real_T **) &(&motor_M)
                         ->contStates);
    rtsiSetNumContStatesPtr(&(&motor_M)->solverInfo, &(&motor_M)
      ->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&(&motor_M)->solverInfo, &(&motor_M)
      ->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&(&motor_M)->solverInfo, &(&motor_M)
      ->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&(&motor_M)->solverInfo, &(&motor_M)
      ->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&(&motor_M)->solverInfo, (&rtmGetErrorStatus((&motor_M))));
    rtsiSetRTModelPtr(&(&motor_M)->solverInfo, (&motor_M));
  }

  rtsiSetSimTimeStep(&(&motor_M)->solverInfo, MAJOR_TIME_STEP);
  (&motor_M)->intgData.y = (&motor_M)->odeY;
  (&motor_M)->intgData.f[0] = (&motor_M)->odeF[0];
  (&motor_M)->intgData.f[1] = (&motor_M)->odeF[1];
  (&motor_M)->intgData.f[2] = (&motor_M)->odeF[2];
  (&motor_M)->contStates = ((X_motor_T *) &motor_X);
  rtsiSetSolverData(&(&motor_M)->solverInfo, static_cast<void *>(&(&motor_M)
    ->intgData));
  rtsiSetSolverName(&(&motor_M)->solverInfo,"ode3");
  rtmSetTPtr((&motor_M), &(&motor_M)->Timing.tArray[0]);
  (&motor_M)->Timing.stepSize0 = 0.02;

  // block I/O
  {
    motor_B.TmpSignalConversionAtStateSpace[0] = 0.0;
    motor_B.TmpSignalConversionAtStateSpace[1] = 0.0;
  }

  // states (continuous)
  {
    (void) std::memset(static_cast<void *>(&motor_X), 0,
                       sizeof(X_motor_T));
  }

  // external inputs
  motor_U.Voltage = 0.0;

  // external outputs
  motor_Y.Outspeed = 0.0;

  // InitializeConditions for StateSpace: '<S1>/State-Space'
  motor_X.StateSpace_CSTATE[0] = 0.0;
  motor_X.StateSpace_CSTATE[1] = 0.0;
}

// Model terminate function
void To_CdcIntrocompleteModelClass::terminate()
{
  // (no terminate code required)
}

// Constructor
To_CdcIntrocompleteModelClass::To_CdcIntrocompleteModelClass() : motor_M()
{
  // Currently there is no constructor body generated.
}

// Destructor
To_CdcIntrocompleteModelClass::~To_CdcIntrocompleteModelClass()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
RT_MODEL_motor_T * To_CdcIntrocompleteModelClass::getRTM()
{
  return (&motor_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
