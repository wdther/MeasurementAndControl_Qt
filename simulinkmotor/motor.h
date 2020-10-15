//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: motor.h
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
#ifndef RTW_HEADER_motor_h_
#define RTW_HEADER_motor_h_
#include <cstring>
#ifndef motor_COMMON_INCLUDES_
# define motor_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 // motor_COMMON_INCLUDES_

#include "motor_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

// Block signals (default storage)
typedef struct {
  real_T TmpSignalConversionAtStateSpace[2];
} B_motor_T;

// Continuous states (default storage)
typedef struct {
  real_T StateSpace_CSTATE[2];         // '<S1>/State-Space'
} X_motor_T;

// State derivatives (default storage)
typedef struct {
  real_T StateSpace_CSTATE[2];         // '<S1>/State-Space'
} XDot_motor_T;

// State disabled
typedef struct {
  boolean_T StateSpace_CSTATE[2];      // '<S1>/State-Space'
} XDis_motor_T;

#ifndef ODE3_INTG
#define ODE3_INTG

// ODE3 Integration Data
typedef struct {
  real_T *y;                           // output
  real_T *f[3];                        // derivatives
} ODE3_IntgData;

#endif

// External inputs (root inport signals with default storage)
typedef struct {
  real_T Voltage;                      // '<Root>/Voltage'
} ExtU_motor_T;

// External outputs (root outports fed by signals with default storage)
typedef struct {
  real_T Outspeed;                     // '<Root>/Outspeed'
} ExtY_motor_T;

// Real-time Model Data Structure
struct tag_RTM_motor_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_motor_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[2];
  real_T odeF[3][2];
  ODE3_IntgData intgData;

  //
  //  Sizes:
  //  The following substructure contains sizes information
  //  for many of the model attributes such as inputs, outputs,
  //  dwork, sample times, etc.

  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

// Class declaration for model motor
class To_CdcIntrocompleteModelClass {
  // public data and function members
 public:
  // External inputs
  ExtU_motor_T motor_U;

  // External outputs
  ExtY_motor_T motor_Y;

  // model initialize function
  void initialize();

  // model step function
  void step();

  // model terminate function
  void terminate();

  // Constructor
  To_CdcIntrocompleteModelClass();

  // Destructor
  ~To_CdcIntrocompleteModelClass();

  // Real-Time Model get method
  RT_MODEL_motor_T * getRTM();

  // private data and function members
 private:
  // Block signals
  B_motor_T motor_B;
  X_motor_T motor_X;                   // Block continuous states

  // Real-Time Model
  RT_MODEL_motor_T motor_M;

  // Continuous states update member function
  void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si );

  // Derivatives member function
  void motor_derivatives();
};

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<Root>/Scope3' : Unused code path elimination
//  Block '<Root>/Scope' : Unused code path elimination
//  Block '<Root>/Scope1' : Unused code path elimination
//  Block '<Root>/Scope2' : Unused code path elimination


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
//  '<Root>' : 'motor'
//  '<S1>'   : 'motor/DCMotor'

#endif                                 // RTW_HEADER_motor_h_

//
// File trailer for generated code.
//
// [EOF]
//
