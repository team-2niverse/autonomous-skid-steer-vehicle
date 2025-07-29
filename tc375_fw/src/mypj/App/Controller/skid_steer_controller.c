/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: skid_steer_controller.c
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

#include "skid_steer_controller.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"

/* Block states (default storage) */
DW_skid_steer_controller_T skid_steer_controller_DW;

/* External inputs (root inport signals with default storage) */
ExtU_skid_steer_controller_T skid_steer_controller_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_skid_steer_controller_T skid_steer_controller_Y;

/* Real-time model */
static RT_MODEL_skid_steer_controller_T skid_steer_controller_M_;
RT_MODEL_skid_steer_controller_T *const skid_steer_controller_M =
  &skid_steer_controller_M_;

/* Model step function */
void skid_steer_controller_step(void)
{
  real_T rtb_Abs;
  real_T rtb_FilterCoefficient;
  real_T rtb_FilterCoefficient_h;
  real_T rtb_Filter_a;
  real_T rtb_Integrator_p;
  real_T tmp;

  /* Gain: '<S2>/Gain' incorporates:
   *  Inport: '<Root>/w_target'
   */
  rtb_Abs = 0.065 * skid_steer_controller_U.w_target;

  /* Sum: '<S4>/Sum' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion'
   *  Gain: '<S3>/Gain'
   *  Inport: '<Root>/enc_pulse_L'
   *  Inport: '<Root>/v_target'
   *  Sum: '<S2>/Sum'
   *  Sum: '<S3>/Sum'
   *  UnitDelay: '<S3>/Unit Delay'
   */
  rtb_Filter_a = (skid_steer_controller_U.v_target - rtb_Abs) - (real_T)
    (skid_steer_controller_U.enc_pulse_L -
     skid_steer_controller_DW.UnitDelay_DSTATE) * 0.010635600129340447;

  /* Gain: '<S47>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S39>/Filter'
   *  Gain: '<S37>/Derivative Gain'
   *  Sum: '<S39>/SumD'
   */
  rtb_FilterCoefficient = (-0.247354459228363 * rtb_Filter_a -
    skid_steer_controller_DW.Filter_DSTATE) * 1.70578345077793;

  /* Sum: '<S53>/Sum' incorporates:
   *  DiscreteIntegrator: '<S44>/Integrator'
   *  Gain: '<S49>/Proportional Gain'
   */
  rtb_Integrator_p = (1.23938501106676 * rtb_Filter_a +
                      skid_steer_controller_DW.Integrator_DSTATE) +
    rtb_FilterCoefficient;

  /* Saturate: '<S51>/Saturation' */
  if (rtb_Integrator_p > 1.0) {
    rtb_Integrator_p = 1.0;
  } else if (rtb_Integrator_p < -1.0) {
    rtb_Integrator_p = -1.0;
  }

  /* End of Saturate: '<S51>/Saturation' */

  /* Outport: '<Root>/dir_L' incorporates:
   *  Constant: '<S9>/Constant'
   *  RelationalOperator: '<S9>/Compare'
   */
  skid_steer_controller_Y.dir_L = (rtb_Integrator_p >= 0.0);

  /* Abs: '<S6>/Abs' */
  rtb_Integrator_p = fabs(rtb_Integrator_p);

  /* DataTypeConversion: '<S6>/Data Type Conversion' incorporates:
   *  Gain: '<S6>/Gain'
   */
  tmp = floor(255.0 * rtb_Integrator_p);
  if (rtIsNaN(tmp)) {
    /* Outport: '<Root>/pwm_L' */
    skid_steer_controller_Y.pwm_L = 0U;
  } else {
    /* Outport: '<Root>/pwm_L' */
    skid_steer_controller_Y.pwm_L = (uint8_T)tmp;
  }

  /* End of DataTypeConversion: '<S6>/Data Type Conversion' */

  /* Outport: '<Root>/brake_L' incorporates:
   *  Constant: '<S8>/Constant'
   *  RelationalOperator: '<S8>/Compare'
   */
  skid_steer_controller_Y.brake_L = (rtb_Integrator_p < 0.05);

  /* Sum: '<S5>/Sum' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion1'
   *  Gain: '<S3>/Gain1'
   *  Inport: '<Root>/enc_pulse_R'
   *  Inport: '<Root>/v_target'
   *  Sum: '<S2>/Sum1'
   *  Sum: '<S3>/Sum1'
   *  UnitDelay: '<S3>/Unit Delay1'
   */
  rtb_Integrator_p = (skid_steer_controller_U.v_target + rtb_Abs) - (real_T)
    (skid_steer_controller_U.enc_pulse_R -
     skid_steer_controller_DW.UnitDelay1_DSTATE) * 0.010635600129340447;

  /* Gain: '<S103>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S95>/Filter'
   *  Gain: '<S93>/Derivative Gain'
   *  Sum: '<S95>/SumD'
   */
  rtb_FilterCoefficient_h = (-0.247354459228363 * rtb_Integrator_p -
    skid_steer_controller_DW.Filter_DSTATE_m) * 1.70578345077793;

  /* Sum: '<S109>/Sum' incorporates:
   *  DiscreteIntegrator: '<S100>/Integrator'
   *  Gain: '<S105>/Proportional Gain'
   */
  rtb_Abs = (1.23938501106676 * rtb_Integrator_p +
             skid_steer_controller_DW.Integrator_DSTATE_h) +
    rtb_FilterCoefficient_h;

  /* Saturate: '<S107>/Saturation' */
  if (rtb_Abs > 1.0) {
    rtb_Abs = 1.0;
  } else if (rtb_Abs < -1.0) {
    rtb_Abs = -1.0;
  }

  /* End of Saturate: '<S107>/Saturation' */

  /* Outport: '<Root>/dir_R' incorporates:
   *  Constant: '<S65>/Constant'
   *  RelationalOperator: '<S65>/Compare'
   */
  skid_steer_controller_Y.dir_R = (rtb_Abs >= 0.0);

  /* Abs: '<S62>/Abs' */
  rtb_Abs = fabs(rtb_Abs);

  /* DataTypeConversion: '<S62>/Data Type Conversion' incorporates:
   *  Gain: '<S62>/Gain'
   */
  tmp = floor(255.0 * rtb_Abs);
  if (rtIsNaN(tmp)) {
    /* Outport: '<Root>/pwm_R' */
    skid_steer_controller_Y.pwm_R = 0U;
  } else {
    /* Outport: '<Root>/pwm_R' */
    skid_steer_controller_Y.pwm_R = (uint8_T)tmp;
  }

  /* End of DataTypeConversion: '<S62>/Data Type Conversion' */

  /* Outport: '<Root>/brake_R' incorporates:
   *  Constant: '<S64>/Constant'
   *  RelationalOperator: '<S64>/Compare'
   */
  skid_steer_controller_Y.brake_R = (rtb_Abs < 0.05);

  /* Update for UnitDelay: '<S3>/Unit Delay' incorporates:
   *  Inport: '<Root>/enc_pulse_L'
   */
  skid_steer_controller_DW.UnitDelay_DSTATE =
    skid_steer_controller_U.enc_pulse_L;

  /* Update for DiscreteIntegrator: '<S44>/Integrator' incorporates:
   *  Gain: '<S41>/Integral Gain'
   */
  skid_steer_controller_DW.Integrator_DSTATE += 0.236337475043715 * rtb_Filter_a
    * 0.01;

  /* Update for DiscreteIntegrator: '<S39>/Filter' */
  skid_steer_controller_DW.Filter_DSTATE += 0.01 * rtb_FilterCoefficient;

  /* Update for UnitDelay: '<S3>/Unit Delay1' incorporates:
   *  Inport: '<Root>/enc_pulse_R'
   */
  skid_steer_controller_DW.UnitDelay1_DSTATE =
    skid_steer_controller_U.enc_pulse_R;

  /* Update for DiscreteIntegrator: '<S100>/Integrator' incorporates:
   *  Gain: '<S97>/Integral Gain'
   */
  skid_steer_controller_DW.Integrator_DSTATE_h += 0.236337475043715 *
    rtb_Integrator_p * 0.01;

  /* Update for DiscreteIntegrator: '<S95>/Filter' */
  skid_steer_controller_DW.Filter_DSTATE_m += 0.01 * rtb_FilterCoefficient_h;
}

/* Model initialize function */
void skid_steer_controller_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
}

/* Model terminate function */
void skid_steer_controller_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
