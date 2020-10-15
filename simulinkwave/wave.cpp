//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: wave.cpp
//
// Code generated for Simulink model 'wave'.
//
// Model version                  : 1.0
// Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
// C/C++ source code generated on : Sat Jun  6 21:46:40 2020
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "wave.h"
#include "wave_private.h"

// Includes for objects with custom storage classes.
#include "wave.h"

// Exported data definition

// Definition for custom storage class: Struct
//Para_type Para = {
//  // amplitude
//  10.2,
//
//  // frequency
//  10.3
//};

// Model step function
void waveModelClass::step()
{
  real_T temp;
  real_T temp_tmp;

  // SignalGenerator: '<Root>/SquareWave' incorporates:
  //   SignalGenerator: '<Root>/SinWave'

  temp_tmp = (&wave_M)->Timing.t[0];
  temp = Para.frequency * temp_tmp;
  if (temp - std::floor(temp) >= 0.5) {
    // Outport: '<Root>/SquareWaveOut'
    wave_Y.SquareWaveOut = Para.amplitude;
  } else {
    // Outport: '<Root>/SquareWaveOut'
    wave_Y.SquareWaveOut = -Para.amplitude;
  }

  // End of SignalGenerator: '<Root>/SquareWave'

  // Outport: '<Root>/SinWaveOut' incorporates:
  //   SignalGenerator: '<Root>/SinWave'

  wave_Y.SinWaveOut = std::sin(6.2831853071795862 * temp_tmp * Para.frequency) *
    Para.amplitude;

  // SignalGenerator: '<Root>/SawWave'
  temp = Para.frequency * (&wave_M)->Timing.t[0];

  // Outport: '<Root>/SawWaveOut' incorporates:
  //   SignalGenerator: '<Root>/SawWave'

  wave_Y.SawWaveOut = (1.0 - (temp - std::floor(temp)) * 2.0) * Para.amplitude;

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The absolute time is the multiplication of "clockTick0"
  //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
  //  overflow during the application lifespan selected.

  (&wave_M)->Timing.t[0] =
    (++(&wave_M)->Timing.clockTick0) * (&wave_M)->Timing.stepSize0;

  {
    // Update absolute timer for sample time: [0.02s, 0.0s]
    // The "clockTick1" counts the number of times the code of this task has
    //  been executed. The resolution of this integer timer is 0.02, which is the step size
    //  of the task. Size of "clockTick1" ensures timer will not overflow during the
    //  application lifespan selected.

    (&wave_M)->Timing.clockTick1++; //记录个数
  }
}

// Model initialize function
void waveModelClass::initialize(float amp,float freq,float timeperiod)
{
  // Registration code
  {
      Para.amplitude=amp;
      Para.frequency=freq;
    // Setup solver object
    rtsiSetSimTimeStepPtr(&(&wave_M)->solverInfo, &(&wave_M)->Timing.simTimeStep);
    rtsiSetTPtr(&(&wave_M)->solverInfo, &rtmGetTPtr((&wave_M)));
    rtsiSetStepSizePtr(&(&wave_M)->solverInfo, &(&wave_M)->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&(&wave_M)->solverInfo, ((const char_T **)
      (&rtmGetErrorStatus((&wave_M)))));
    rtsiSetRTModelPtr(&(&wave_M)->solverInfo, (&wave_M));
  }

  rtsiSetSimTimeStep(&(&wave_M)->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&(&wave_M)->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr((&wave_M), &(&wave_M)->Timing.tArray[0]);
  (&wave_M)->Timing.stepSize0 =  timeperiod;

  // external outputs
  (void) std::memset(static_cast<void *>(&wave_Y), 0,
                     sizeof(ExtY_wave_T));
}

// Model terminate function
void waveModelClass::terminate()
{
  // (no terminate code required)
}

// Constructor
waveModelClass::waveModelClass() : wave_M()
{
  // Currently there is no constructor body generated.
}

// Destructor
waveModelClass::~waveModelClass()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
RT_MODEL_wave_T * waveModelClass::getRTM()
{
  return (&wave_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
