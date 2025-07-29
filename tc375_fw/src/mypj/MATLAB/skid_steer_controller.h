/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: skid_steer_controller.h
 *
 * Code generated for Simulink model 'skid_steer_controller'.
 *
 * Model version                  : 1.15
 * Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
 * C/C++ source code generated on : Tue Jul 29 01:31:25 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef skid_steer_controller_h_
#define skid_steer_controller_h_
#ifndef skid_steer_controller_COMMON_INCLUDES_
#define skid_steer_controller_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                              /* skid_steer_controller_COMMON_INCLUDES_ */

#include "skid_steer_controller_types.h"
#include "rt_nonfinite.h"
#include <stddef.h>
//#include "TriCore0_Ifx_STM.h"
//#include "TriCore0_tc3xx_init.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Integrator_DSTATE;            /* '<S44>/Integrator' */
  real_T Filter_DSTATE;                /* '<S39>/Filter' */
  real_T Integrator_DSTATE_h;          /* '<S100>/Integrator' */
  real_T Filter_DSTATE_m;              /* '<S95>/Filter' */
  int32_T UnitDelay_DSTATE;            /* '<S3>/Unit Delay' */
  int32_T UnitDelay1_DSTATE;           /* '<S3>/Unit Delay1' */
} DW_skid_steer_controller_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T v_target;                     /* '<Root>/v_target' */
  real_T w_target;                     /* '<Root>/w_target' */
  int32_T enc_pulse_L;                 /* '<Root>/enc_pulse_L' */
  int32_T enc_pulse_R;                 /* '<Root>/enc_pulse_R' */
} ExtU_skid_steer_controller_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  uint8_T pwm_L;                       /* '<Root>/pwm_L' */
  boolean_T dir_L;                     /* '<Root>/dir_L' */
  boolean_T brake_L;                   /* '<Root>/brake_L' */
  uint8_T pwm_R;                       /* '<Root>/pwm_R' */
  boolean_T dir_R;                     /* '<Root>/dir_R' */
  boolean_T brake_R;                   /* '<Root>/brake_R' */
} ExtY_skid_steer_controller_T;

/* Real-time Model Data Structure */
struct tag_RTM_skid_steer_controller_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_skid_steer_controller_T skid_steer_controller_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_skid_steer_controller_T skid_steer_controller_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_skid_steer_controller_T skid_steer_controller_Y;

/* Model entry point functions */
extern void skid_steer_controller_initialize(void);
extern void skid_steer_controller_step(void);
extern void skid_steer_controller_terminate(void);

/* Real-time Model object */
extern RT_MODEL_skid_steer_controller_T *const skid_steer_controller_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'skid_steer_controller'
 * '<S1>'   : 'skid_steer_controller/UUT_Skid_Steer_Controller'
 * '<S2>'   : 'skid_steer_controller/UUT_Skid_Steer_Controller/Inverse_Kinematics'
 * '<S3>'   : 'skid_steer_controller/UUT_Skid_Steer_Controller/Velocity_Estimator'
 * '<S4>'   : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_L'
 * '<S5>'   : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_R'
 * '<S6>'   : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_L/Arduino_Shield_Driver_Logic'
 * '<S7>'   : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_L/Discrete PID Controller'
 * '<S8>'   : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_L/Arduino_Shield_Driver_Logic/Compare To Constant'
 * '<S9>'   : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_L/Arduino_Shield_Driver_Logic/Compare To Zero'
 * '<S10>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_L/Discrete PID Controller/Anti-windup'
 * '<S11>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_L/Discrete PID Controller/D Gain'
 * '<S12>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_L/Discrete PID Controller/External Derivative'
 * '<S13>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_L/Discrete PID Controller/Filter'
 * '<S14>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_L/Discrete PID Controller/Filter ICs'
 * '<S15>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_L/Discrete PID Controller/I Gain'
 * '<S16>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_L/Discrete PID Controller/Ideal P Gain'
 * '<S17>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_L/Discrete PID Controller/Ideal P Gain Fdbk'
 * '<S18>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_L/Discrete PID Controller/Integrator'
 * '<S19>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_L/Discrete PID Controller/Integrator ICs'
 * '<S20>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_L/Discrete PID Controller/N Copy'
 * '<S21>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_L/Discrete PID Controller/N Gain'
 * '<S22>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_L/Discrete PID Controller/P Copy'
 * '<S23>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_L/Discrete PID Controller/Parallel P Gain'
 * '<S24>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_L/Discrete PID Controller/Reset Signal'
 * '<S25>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_L/Discrete PID Controller/Saturation'
 * '<S26>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_L/Discrete PID Controller/Saturation Fdbk'
 * '<S27>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_L/Discrete PID Controller/Sum'
 * '<S28>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_L/Discrete PID Controller/Sum Fdbk'
 * '<S29>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_L/Discrete PID Controller/Tracking Mode'
 * '<S30>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_L/Discrete PID Controller/Tracking Mode Sum'
 * '<S31>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_L/Discrete PID Controller/Tsamp - Integral'
 * '<S32>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_L/Discrete PID Controller/Tsamp - Ngain'
 * '<S33>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_L/Discrete PID Controller/postSat Signal'
 * '<S34>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_L/Discrete PID Controller/preInt Signal'
 * '<S35>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_L/Discrete PID Controller/preSat Signal'
 * '<S36>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_L/Discrete PID Controller/Anti-windup/Passthrough'
 * '<S37>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_L/Discrete PID Controller/D Gain/Internal Parameters'
 * '<S38>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_L/Discrete PID Controller/External Derivative/Error'
 * '<S39>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_L/Discrete PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S40>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_L/Discrete PID Controller/Filter ICs/Internal IC - Filter'
 * '<S41>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_L/Discrete PID Controller/I Gain/Internal Parameters'
 * '<S42>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_L/Discrete PID Controller/Ideal P Gain/Passthrough'
 * '<S43>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_L/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S44>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_L/Discrete PID Controller/Integrator/Discrete'
 * '<S45>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_L/Discrete PID Controller/Integrator ICs/Internal IC'
 * '<S46>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_L/Discrete PID Controller/N Copy/Disabled'
 * '<S47>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_L/Discrete PID Controller/N Gain/Internal Parameters'
 * '<S48>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_L/Discrete PID Controller/P Copy/Disabled'
 * '<S49>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_L/Discrete PID Controller/Parallel P Gain/Internal Parameters'
 * '<S50>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_L/Discrete PID Controller/Reset Signal/Disabled'
 * '<S51>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_L/Discrete PID Controller/Saturation/Enabled'
 * '<S52>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_L/Discrete PID Controller/Saturation Fdbk/Disabled'
 * '<S53>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_L/Discrete PID Controller/Sum/Sum_PID'
 * '<S54>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_L/Discrete PID Controller/Sum Fdbk/Disabled'
 * '<S55>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_L/Discrete PID Controller/Tracking Mode/Disabled'
 * '<S56>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_L/Discrete PID Controller/Tracking Mode Sum/Passthrough'
 * '<S57>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_L/Discrete PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S58>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_L/Discrete PID Controller/Tsamp - Ngain/Passthrough'
 * '<S59>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_L/Discrete PID Controller/postSat Signal/Forward_Path'
 * '<S60>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_L/Discrete PID Controller/preInt Signal/Internal PreInt'
 * '<S61>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_L/Discrete PID Controller/preSat Signal/Forward_Path'
 * '<S62>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_R/Arduino_Shield_Driver_Logic'
 * '<S63>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_R/Discrete PID Controller'
 * '<S64>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_R/Arduino_Shield_Driver_Logic/Compare To Constant'
 * '<S65>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_R/Arduino_Shield_Driver_Logic/Compare To Zero'
 * '<S66>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_R/Discrete PID Controller/Anti-windup'
 * '<S67>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_R/Discrete PID Controller/D Gain'
 * '<S68>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_R/Discrete PID Controller/External Derivative'
 * '<S69>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_R/Discrete PID Controller/Filter'
 * '<S70>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_R/Discrete PID Controller/Filter ICs'
 * '<S71>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_R/Discrete PID Controller/I Gain'
 * '<S72>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_R/Discrete PID Controller/Ideal P Gain'
 * '<S73>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_R/Discrete PID Controller/Ideal P Gain Fdbk'
 * '<S74>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_R/Discrete PID Controller/Integrator'
 * '<S75>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_R/Discrete PID Controller/Integrator ICs'
 * '<S76>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_R/Discrete PID Controller/N Copy'
 * '<S77>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_R/Discrete PID Controller/N Gain'
 * '<S78>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_R/Discrete PID Controller/P Copy'
 * '<S79>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_R/Discrete PID Controller/Parallel P Gain'
 * '<S80>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_R/Discrete PID Controller/Reset Signal'
 * '<S81>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_R/Discrete PID Controller/Saturation'
 * '<S82>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_R/Discrete PID Controller/Saturation Fdbk'
 * '<S83>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_R/Discrete PID Controller/Sum'
 * '<S84>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_R/Discrete PID Controller/Sum Fdbk'
 * '<S85>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_R/Discrete PID Controller/Tracking Mode'
 * '<S86>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_R/Discrete PID Controller/Tracking Mode Sum'
 * '<S87>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_R/Discrete PID Controller/Tsamp - Integral'
 * '<S88>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_R/Discrete PID Controller/Tsamp - Ngain'
 * '<S89>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_R/Discrete PID Controller/postSat Signal'
 * '<S90>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_R/Discrete PID Controller/preInt Signal'
 * '<S91>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_R/Discrete PID Controller/preSat Signal'
 * '<S92>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_R/Discrete PID Controller/Anti-windup/Passthrough'
 * '<S93>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_R/Discrete PID Controller/D Gain/Internal Parameters'
 * '<S94>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_R/Discrete PID Controller/External Derivative/Error'
 * '<S95>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_R/Discrete PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S96>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_R/Discrete PID Controller/Filter ICs/Internal IC - Filter'
 * '<S97>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_R/Discrete PID Controller/I Gain/Internal Parameters'
 * '<S98>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_R/Discrete PID Controller/Ideal P Gain/Passthrough'
 * '<S99>'  : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_R/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S100>' : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_R/Discrete PID Controller/Integrator/Discrete'
 * '<S101>' : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_R/Discrete PID Controller/Integrator ICs/Internal IC'
 * '<S102>' : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_R/Discrete PID Controller/N Copy/Disabled'
 * '<S103>' : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_R/Discrete PID Controller/N Gain/Internal Parameters'
 * '<S104>' : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_R/Discrete PID Controller/P Copy/Disabled'
 * '<S105>' : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_R/Discrete PID Controller/Parallel P Gain/Internal Parameters'
 * '<S106>' : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_R/Discrete PID Controller/Reset Signal/Disabled'
 * '<S107>' : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_R/Discrete PID Controller/Saturation/Enabled'
 * '<S108>' : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_R/Discrete PID Controller/Saturation Fdbk/Disabled'
 * '<S109>' : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_R/Discrete PID Controller/Sum/Sum_PID'
 * '<S110>' : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_R/Discrete PID Controller/Sum Fdbk/Disabled'
 * '<S111>' : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_R/Discrete PID Controller/Tracking Mode/Disabled'
 * '<S112>' : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_R/Discrete PID Controller/Tracking Mode Sum/Passthrough'
 * '<S113>' : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_R/Discrete PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S114>' : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_R/Discrete PID Controller/Tsamp - Ngain/Passthrough'
 * '<S115>' : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_R/Discrete PID Controller/postSat Signal/Forward_Path'
 * '<S116>' : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_R/Discrete PID Controller/preInt Signal/Internal PreInt'
 * '<S117>' : 'skid_steer_controller/UUT_Skid_Steer_Controller/Wheel_Controller_R/Discrete PID Controller/preSat Signal/Forward_Path'
 */
#endif                                 /* skid_steer_controller_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
