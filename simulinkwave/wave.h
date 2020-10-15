//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: wave.h
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
#ifndef RTW_HEADER_wave_h_
#define RTW_HEADER_wave_h_
#include <cmath>
#include <cstring>
#ifndef wave_COMMON_INCLUDES_
# define wave_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 // wave_COMMON_INCLUDES_

#include "wave_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

// External outputs (root outports fed by signals with default storage)
typedef struct {
  real_T SquareWaveOut;                // '<Root>/SquareWaveOut'
  real_T SinWaveOut;                   // '<Root>/SinWaveOut'
  real_T SawWaveOut;                   // '<Root>/SawWaveOut'
} ExtY_wave_T;

// Type definition for custom storage class: Struct
typedef struct Para_tag {
  real_T amplitude;                    // Referenced by:
                                          //  '<Root>/SawWave'
                                          //  '<Root>/SinWave'
                                          //  '<Root>/SquareWave'

  real_T frequency;                    // Referenced by:
                                          //  '<Root>/SawWave'
                                          //  '<Root>/SinWave'
                                          //  '<Root>/SquareWave'

} Para_type;

// Real-time Model Data Structure
struct tag_RTM_wave_T {
  const char_T * volatile errorStatus;
  RTWSolverInfo solverInfo;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    SimTimeStep simTimeStep;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

// Exported data declaration

// Declaration for custom storage class: Struct
extern Para_type Para;

// Class declaration for model wave
class waveModelClass {
  // public data and function members
 public:
  // External outputs
  ExtY_wave_T wave_Y;

  // model initialize function
  void initialize(float amp,float freq,float timeperiod);

  // model step function
  void step();
  Para_type Para;

  // model terminate function
  void terminate();

  // Constructor
  waveModelClass();

  // Destructor
  ~waveModelClass();

  // Real-Time Model get method
  RT_MODEL_wave_T * getRTM();

  // private data and function members
 private:
  // Real-Time Model
  RT_MODEL_wave_T wave_M;
};

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<Root>/Scope' : Unused code path elimination
//  Block '<Root>/Scope1' : Unused code path elimination


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'wave'

#endif                                 // RTW_HEADER_wave_h_

//
// File trailer for generated code.
//
// [EOF]
//
