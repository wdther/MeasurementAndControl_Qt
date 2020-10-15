//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: pidmodel.h
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
#ifndef RTW_HEADER_pidmodel_h_
#define RTW_HEADER_pidmodel_h_
#ifndef pidmodel_COMMON_INCLUDES_
# define pidmodel_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 // pidmodel_COMMON_INCLUDES_

#include "pidmodel_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

// Block states (default storage) for system '<Root>'
typedef struct {
  real_T Integrator_DSTATE;            // '<S31>/Integrator'
  real_T UD_DSTATE;                    // '<S26>/UD'
} DW_pidmodel_T;
typedef struct PID{
    float Kp;
    float Ki;
    float Kd;
   // float N; //pid参数

}Pidmodel;
// External inputs (root inport signals with default storage)
typedef struct {
  real_T error;                        // '<Root>/error'
} ExtU_pidmodel_T;

// External outputs (root outports fed by signals with default storage)
typedef struct {
  real_T u;                            // '<Root>/u'
} ExtY_pidmodel_T;

// Real-time Model Data Structure
struct tag_RTM_pidmodel_T {
  const char_T * volatile errorStatus;
};

// Class declaration for model pidmodel
class pidmodelModelClass {
  // public data and function members
 public:
  // External inputs
  ExtU_pidmodel_T pidmodel_U;

  // External outputs
  ExtY_pidmodel_T pidmodel_Y;
  //
  Pidmodel pid;

  // model initialize function
  void initialize();

  // model step function
  void step(float timeperiod);

  //参数设置
  void parainit(float Kp,float Ki,float Kd);
  // model terminate function
  void terminate();

  // Constructor
  pidmodelModelClass();

  // Destructor
  ~pidmodelModelClass();

  // Real-Time Model get method
  RT_MODEL_pidmodel_T * getRTM();

  // private data and function members
 private:
  // Block states
  DW_pidmodel_T pidmodel_DW;

  // Real-Time Model
  RT_MODEL_pidmodel_T pidmodel_M;
};

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S26>/DTDup' : Unused code path elimination
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
//  '<Root>' : 'pidmodel'
//  '<S1>'   : 'pidmodel/Discrete PID Controller'
//  '<S2>'   : 'pidmodel/Discrete PID Controller/Anti-windup'
//  '<S3>'   : 'pidmodel/Discrete PID Controller/D Gain'
//  '<S4>'   : 'pidmodel/Discrete PID Controller/Filter'
//  '<S5>'   : 'pidmodel/Discrete PID Controller/Filter ICs'
//  '<S6>'   : 'pidmodel/Discrete PID Controller/I Gain'
//  '<S7>'   : 'pidmodel/Discrete PID Controller/Ideal P Gain'
//  '<S8>'   : 'pidmodel/Discrete PID Controller/Ideal P Gain Fdbk'
//  '<S9>'   : 'pidmodel/Discrete PID Controller/Integrator'
//  '<S10>'  : 'pidmodel/Discrete PID Controller/Integrator ICs'
//  '<S11>'  : 'pidmodel/Discrete PID Controller/N Copy'
//  '<S12>'  : 'pidmodel/Discrete PID Controller/N Gain'
//  '<S13>'  : 'pidmodel/Discrete PID Controller/P Copy'
//  '<S14>'  : 'pidmodel/Discrete PID Controller/Parallel P Gain'
//  '<S15>'  : 'pidmodel/Discrete PID Controller/Reset Signal'
//  '<S16>'  : 'pidmodel/Discrete PID Controller/Saturation'
//  '<S17>'  : 'pidmodel/Discrete PID Controller/Saturation Fdbk'
//  '<S18>'  : 'pidmodel/Discrete PID Controller/Sum'
//  '<S19>'  : 'pidmodel/Discrete PID Controller/Sum Fdbk'
//  '<S20>'  : 'pidmodel/Discrete PID Controller/Tracking Mode'
//  '<S21>'  : 'pidmodel/Discrete PID Controller/Tracking Mode Sum'
//  '<S22>'  : 'pidmodel/Discrete PID Controller/postSat Signal'
//  '<S23>'  : 'pidmodel/Discrete PID Controller/preSat Signal'
//  '<S24>'  : 'pidmodel/Discrete PID Controller/Anti-windup/Passthrough'
//  '<S25>'  : 'pidmodel/Discrete PID Controller/D Gain/Internal Parameters'
//  '<S26>'  : 'pidmodel/Discrete PID Controller/Filter/Differentiator'
//  '<S27>'  : 'pidmodel/Discrete PID Controller/Filter ICs/Internal IC - Differentiator'
//  '<S28>'  : 'pidmodel/Discrete PID Controller/I Gain/Internal Parameters'
//  '<S29>'  : 'pidmodel/Discrete PID Controller/Ideal P Gain/Passthrough'
//  '<S30>'  : 'pidmodel/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S31>'  : 'pidmodel/Discrete PID Controller/Integrator/Discrete'
//  '<S32>'  : 'pidmodel/Discrete PID Controller/Integrator ICs/Internal IC'
//  '<S33>'  : 'pidmodel/Discrete PID Controller/N Copy/Disabled wSignal Specification'
//  '<S34>'  : 'pidmodel/Discrete PID Controller/N Gain/Passthrough'
//  '<S35>'  : 'pidmodel/Discrete PID Controller/P Copy/Disabled'
//  '<S36>'  : 'pidmodel/Discrete PID Controller/Parallel P Gain/Internal Parameters'
//  '<S37>'  : 'pidmodel/Discrete PID Controller/Reset Signal/Disabled'
//  '<S38>'  : 'pidmodel/Discrete PID Controller/Saturation/Passthrough'
//  '<S39>'  : 'pidmodel/Discrete PID Controller/Saturation Fdbk/Disabled'
//  '<S40>'  : 'pidmodel/Discrete PID Controller/Sum/Sum_PID'
//  '<S41>'  : 'pidmodel/Discrete PID Controller/Sum Fdbk/Disabled'
//  '<S42>'  : 'pidmodel/Discrete PID Controller/Tracking Mode/Disabled'
//  '<S43>'  : 'pidmodel/Discrete PID Controller/Tracking Mode Sum/Passthrough'
//  '<S44>'  : 'pidmodel/Discrete PID Controller/postSat Signal/Forward_Path'
//  '<S45>'  : 'pidmodel/Discrete PID Controller/preSat Signal/Forward_Path'

#endif                                 // RTW_HEADER_pidmodel_h_

//
// File trailer for generated code.
//
// [EOF]
//
