/*
 * ctrl_DP.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ctrl_DP".
 *
 * Model version              : 1.53
 * Simulink Coder version : 8.11 (R2016b) 25-Aug-2016
 * C source code generated on : Thu Jul 13 11:39:53 2017
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ctrl_DP.h"
#include "ctrl_DP_private.h"

/* Block signals (auto storage) */
B_ctrl_DP_T ctrl_DP_B;

/* Continuous states */
X_ctrl_DP_T ctrl_DP_X;

/* Block states (auto storage) */
DW_ctrl_DP_T ctrl_DP_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_ctrl_DP_T ctrl_DP_PrevZCX;

/* Real-time model */
RT_MODEL_ctrl_DP_T ctrl_DP_M_;
RT_MODEL_ctrl_DP_T *const ctrl_DP_M = &ctrl_DP_M_;

/*
 * This function updates continuous states using the ODE4 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE4_IntgData *id = (ODE4_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T temp;
  int_T i;
  int_T nXc = 21;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  ctrl_DP_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  ctrl_DP_output();
  ctrl_DP_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  ctrl_DP_output();
  ctrl_DP_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  ctrl_DP_output();
  ctrl_DP_derivatives();

  /* tnew = t + h
     ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/*
 * Output and update for atomic system:
 *    '<S25>/MATLAB Function'
 *    '<S27>/MATLAB Function'
 */
void ctrl_DP_MATLABFunction(real_T rtu_K_p1, real_T rtu_K_p1_e, real_T
  rtu_K_p1_f, B_MATLABFunction_ctrl_DP_T *localB)
{
  /* MATLAB Function 'Input/Control Gains/MATLAB Function': '<S28>:1' */
  /* '<S28>:1:4' */
  memset(&localB->K_p[0], 0, 9U * sizeof(real_T));

  /* SignalConversion: '<S28>/TmpSignal ConversionAt SFunction Inport1' */
  localB->K_p[0] = rtu_K_p1;
  localB->K_p[4] = rtu_K_p1_e;
  localB->K_p[8] = rtu_K_p1_f;
}

/*
 * Output and update for atomic system:
 *    '<S25>/MATLAB Function1'
 *    '<S27>/MATLAB Function1'
 */
void ctrl_DP_MATLABFunction1(real_T rtu_K_i1, real_T rtu_K_i1_m, real_T
  rtu_K_i1_n, B_MATLABFunction1_ctrl_DP_T *localB)
{
  /* MATLAB Function 'Input/Control Gains/MATLAB Function1': '<S29>:1' */
  /* '<S29>:1:4' */
  memset(&localB->K_i[0], 0, 9U * sizeof(real_T));

  /* SignalConversion: '<S29>/TmpSignal ConversionAt SFunction Inport1' */
  localB->K_i[0] = rtu_K_i1;
  localB->K_i[4] = rtu_K_i1_m;
  localB->K_i[8] = rtu_K_i1_n;
}

/*
 * Output and update for atomic system:
 *    '<S25>/MATLAB Function2'
 *    '<S27>/MATLAB Function2'
 */
void ctrl_DP_MATLABFunction2(real_T rtu_K_d1, real_T rtu_K_d1_p, real_T
  rtu_K_d1_i, B_MATLABFunction2_ctrl_DP_T *localB)
{
  /* MATLAB Function 'Input/Control Gains/MATLAB Function2': '<S30>:1' */
  /* '<S30>:1:4' */
  memset(&localB->K_d[0], 0, 9U * sizeof(real_T));

  /* SignalConversion: '<S30>/TmpSignal ConversionAt SFunction Inport1' */
  localB->K_d[0] = rtu_K_d1;
  localB->K_d[4] = rtu_K_d1_p;
  localB->K_d[8] = rtu_K_d1_i;
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

real_T rt_remd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T u1_0;
  if (!((!rtIsNaN(u0)) && (!rtIsInf(u0)) && ((!rtIsNaN(u1)) && (!rtIsInf(u1)))))
  {
    y = (rtNaN);
  } else {
    if (u1 < 0.0) {
      u1_0 = ceil(u1);
    } else {
      u1_0 = floor(u1);
    }

    if ((u1 != 0.0) && (u1 != u1_0)) {
      u1_0 = u0 / u1;
      if (fabs(u1_0 - rt_roundd_snf(u1_0)) <= DBL_EPSILON * fabs(u1_0)) {
        y = 0.0;
      } else {
        y = fmod(u0, u1);
      }
    } else {
      y = fmod(u0, u1);
    }
  }

  return y;
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T u0_0;
  int32_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2(u0_0, u1_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

/* Model output function */
void ctrl_DP_output(void)
{
  ZCEventType zcEvent;
  real_T tau[3];
  real_T A[81];
  real_T K[27];
  int32_T r1;
  int32_T r2;
  int32_T r3;
  int32_T rtemp;
  int8_T I[81];
  int8_T b_I[81];
  static const int8_T b[3] = { 0, 0, 1 };

  static const int8_T c[27] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0,
    0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const int8_T b_b[27] = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 };

  static const real_T R[9] = { 0.01, 0.0, 0.0, 0.0, 0.01, 0.0, 0.0, 0.0, 0.01 };

  static const real_T Q[81] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.1, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.1, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.1, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.1, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.1, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.1 };

  static const int8_T a[27] = { 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const int8_T d[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

  static const real_T a_0[9] = { 1.0, 0.0, 0.0, 0.0, 1.0, -0.4575, 0.0, 1.0,
    0.3875 };

  real_T D_NL[9];
  real_T x[9];
  real_T C_NL[9];
  real_T rtb_Row2;
  real_T rtb_Row1;
  real_T rtb_psi_dot;
  real_T rtb_Row1_o;
  real_T rtb_MatrixMultiply[3];
  real_T rtb_TmpSignalConversionAtSFu_pa[3];
  real_T rtb_w_d[9];
  real_T tmp[3];
  real_T tmp_0[54];
  real_T e[6];
  real_T A_0[9];
  real_T I_0[81];
  real_T I_1[81];
  real_T b_I_0[81];
  real_T K_0[27];
  real_T K_1[81];
  real_T tau_0[3];
  real_T tmp_1[3];
  real_T tmp_2[3];
  real_T rtb_y_l_0[3];
  real_T rtb_Row2_0[3];
  real_T u_idx_2;
  real_T u_idx_0;
  real_T u_idx_1;
  real_T tmp_3;
  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
    /* set solver stop time */
    if (!(ctrl_DP_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&ctrl_DP_M->solverInfo,
                            ((ctrl_DP_M->Timing.clockTickH0 + 1) *
        ctrl_DP_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&ctrl_DP_M->solverInfo,
                            ((ctrl_DP_M->Timing.clockTick0 + 1) *
        ctrl_DP_M->Timing.stepSize0 + ctrl_DP_M->Timing.clockTickH0 *
        ctrl_DP_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(ctrl_DP_M)) {
    ctrl_DP_M->Timing.t[0] = rtsiGetT(&ctrl_DP_M->solverInfo);
  }

  /* MATLAB Function: '<S25>/MATLAB Function' */
  ctrl_DP_MATLABFunction(ctrl_DP_B.K_p_x, ctrl_DP_B.K_p_y, ctrl_DP_B.K_p_psi,
    &ctrl_DP_B.sf_MATLABFunction);

  /* Gain: '<S10>/mm2m' */
  ctrl_DP_B.mm2m = ctrl_DP_P.mm2m_Gain * ctrl_DP_B.x;

  /* Gain: '<S10>/mm2m ' */
  ctrl_DP_B.mm2m_e = ctrl_DP_P.mm2m_Gain_i * ctrl_DP_B.y;

  /* Gain: '<S10>/Gain5' */
  rtb_Row2 = ctrl_DP_P.Gain5_Gain * ctrl_DP_B.psi;

  /* Saturate: '<S10>/Saturation' */
  if (rtb_Row2 > ctrl_DP_P.Saturation_UpperSat) {
    rtb_Row2 = ctrl_DP_P.Saturation_UpperSat;
  } else {
    if (rtb_Row2 < ctrl_DP_P.Saturation_LowerSat) {
      rtb_Row2 = ctrl_DP_P.Saturation_LowerSat;
    }
  }

  /* End of Saturate: '<S10>/Saturation' */

  /* Signum: '<S10>/Sign' */
  if (rtb_Row2 < 0.0) {
    rtb_psi_dot = -1.0;
  } else if (rtb_Row2 > 0.0) {
    rtb_psi_dot = 1.0;
  } else if (rtb_Row2 == 0.0) {
    rtb_psi_dot = 0.0;
  } else {
    rtb_psi_dot = rtb_Row2;
  }

  /* End of Signum: '<S10>/Sign' */

  /* Gain: '<S10>/Gain6' */
  rtb_Row1 = ctrl_DP_P.Gain6_Gain * rtb_psi_dot;

  /* Sum: '<S10>/Sum1' */
  rtb_Row2 += rtb_Row1;

  /* Math: '<S10>/Math Function' incorporates:
   *  Constant: '<S10>/Constant1'
   */
  rtb_Row2 = rt_remd_snf(rtb_Row2, ctrl_DP_P.Constant1_Value);

  /* Sum: '<S10>/Sum' */
  ctrl_DP_B.Sum = rtb_Row2 - rtb_Row1;

  /* Saturate: '<S17>/Saturation' incorporates:
   *  Fcn: '<S13>/yaw angle'
   */
  if (ctrl_DP_B.Sum > ctrl_DP_P.Saturation_UpperSat_n) {
    rtb_Row1 = ctrl_DP_P.Saturation_UpperSat_n;
  } else if (ctrl_DP_B.Sum < ctrl_DP_P.Saturation_LowerSat_d) {
    rtb_Row1 = ctrl_DP_P.Saturation_LowerSat_d;
  } else {
    rtb_Row1 = ctrl_DP_B.Sum;
  }

  /* End of Saturate: '<S17>/Saturation' */

  /* Signum: '<S17>/Sign' */
  if (rtb_Row1 < 0.0) {
    rtb_psi_dot = -1.0;
  } else if (rtb_Row1 > 0.0) {
    rtb_psi_dot = 1.0;
  } else if (rtb_Row1 == 0.0) {
    rtb_psi_dot = 0.0;
  } else {
    rtb_psi_dot = rtb_Row1;
  }

  /* End of Signum: '<S17>/Sign' */

  /* Gain: '<S17>/Gain' */
  rtb_Row2 = ctrl_DP_P.Gain_Gain * rtb_psi_dot;

  /* Sum: '<S17>/Sum1' */
  rtb_Row1 += rtb_Row2;

  /* Math: '<S17>/Math Function' incorporates:
   *  Constant: '<S17>/Constant'
   */
  rtb_Row1 = rt_remd_snf(rtb_Row1, ctrl_DP_P.Constant_Value);

  /* Sum: '<S17>/Sum' */
  rtb_Row1 -= rtb_Row2;

  /* MATLAB Function: '<S25>/MATLAB Function1' */
  ctrl_DP_MATLABFunction1(ctrl_DP_B.K_i_x, ctrl_DP_B.K_i_y, ctrl_DP_B.K_i_psi,
    &ctrl_DP_B.sf_MATLABFunction1);

  /* MATLAB Function: '<S25>/MATLAB Function2' */
  ctrl_DP_MATLABFunction2(ctrl_DP_B.K_d_x, ctrl_DP_B.K_d_y, ctrl_DP_B.K_d_psi,
    &ctrl_DP_B.sf_MATLABFunction2);
  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
    /* MATLAB Function: '<S27>/MATLAB Function2' incorporates:
     *  Constant: '<S27>/Constant6'
     *  Constant: '<S27>/Constant7'
     *  Constant: '<S27>/Constant8'
     */
    ctrl_DP_MATLABFunction2(ctrl_DP_P.Constant6_Value, ctrl_DP_P.Constant7_Value,
      ctrl_DP_P.Constant8_Value, &ctrl_DP_B.sf_MATLABFunction2_p);
  }

  /* MATLAB Function: '<S26>/diag' incorporates:
   *  SignalConversion: '<S31>/TmpSignal ConversionAt SFunction Inport1'
   */
  /* MATLAB Function 'Input/Guidance gains/diag': '<S31>:1' */
  /* '<S31>:1:4' */
  memset(&rtb_w_d[0], 0, 9U * sizeof(real_T));
  rtb_w_d[0] = ctrl_DP_B.w_d_x;
  rtb_w_d[4] = ctrl_DP_B.w_d_y;
  rtb_w_d[8] = ctrl_DP_B.w_d_psi;

  /* Integrator: '<S18>/Integrator1' */
  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,&ctrl_DP_PrevZCX.Integrator1_Reset_ZCE,
                       (ctrl_DP_B.reset));

    /* evaluate zero-crossings */
    if ((zcEvent != NO_ZCEVENT) || (ctrl_DP_DW.Integrator1_IWORK != 0)) {
      ctrl_DP_X.Integrator1_CSTATE[0] = ctrl_DP_B.mm2m;
      ctrl_DP_X.Integrator1_CSTATE[1] = ctrl_DP_B.mm2m_e;
      ctrl_DP_X.Integrator1_CSTATE[2] = ctrl_DP_B.Sum;
    }
  }

  ctrl_DP_B.Integrator1[0] = ctrl_DP_X.Integrator1_CSTATE[0];
  ctrl_DP_B.Integrator1[1] = ctrl_DP_X.Integrator1_CSTATE[1];
  ctrl_DP_B.Integrator1[2] = ctrl_DP_X.Integrator1_CSTATE[2];

  /* End of Integrator: '<S18>/Integrator1' */

  /* Saturate: '<S19>/Saturation' */
  if (ctrl_DP_B.Integrator1[2] > ctrl_DP_P.Saturation_UpperSat_j) {
    rtb_Row2 = ctrl_DP_P.Saturation_UpperSat_j;
  } else if (ctrl_DP_B.Integrator1[2] < ctrl_DP_P.Saturation_LowerSat_c) {
    rtb_Row2 = ctrl_DP_P.Saturation_LowerSat_c;
  } else {
    rtb_Row2 = ctrl_DP_B.Integrator1[2];
  }

  /* End of Saturate: '<S19>/Saturation' */

  /* Signum: '<S19>/Sign' */
  if (rtb_Row2 < 0.0) {
    rtb_psi_dot = -1.0;
  } else if (rtb_Row2 > 0.0) {
    rtb_psi_dot = 1.0;
  } else if (rtb_Row2 == 0.0) {
    rtb_psi_dot = 0.0;
  } else {
    rtb_psi_dot = rtb_Row2;
  }

  /* End of Signum: '<S19>/Sign' */

  /* Gain: '<S19>/Gain' */
  rtb_psi_dot *= ctrl_DP_P.Gain_Gain_j;

  /* Sum: '<S19>/Sum1' */
  rtb_Row2 += rtb_psi_dot;

  /* Math: '<S19>/Math Function' incorporates:
   *  Constant: '<S19>/Constant'
   */
  rtb_Row2 = rt_remd_snf(rtb_Row2, ctrl_DP_P.Constant_Value_f);

  /* Sum: '<S19>/Sum' */
  ctrl_DP_B.Sum_l = rtb_Row2 - rtb_psi_dot;

  /* SignalConversion: '<S18>/TmpSignal ConversionAtMatrix Multiply2Inport2' */
  rtb_TmpSignalConversionAtSFu_pa[0] = ctrl_DP_B.Integrator1[0];
  rtb_TmpSignalConversionAtSFu_pa[1] = ctrl_DP_B.Integrator1[1];
  rtb_TmpSignalConversionAtSFu_pa[2] = ctrl_DP_B.Sum_l;

  /* Sum: '<S13>/Sum2' incorporates:
   *  SignalConversion: '<S18>/TmpSignal ConversionAtMatrix Multiply2Inport2'
   */
  ctrl_DP_B.regulationerror[0] = ctrl_DP_B.mm2m - ctrl_DP_B.Integrator1[0];
  ctrl_DP_B.regulationerror[1] = ctrl_DP_B.mm2m_e - ctrl_DP_B.Integrator1[1];
  ctrl_DP_B.regulationerror[2] = ctrl_DP_B.Sum - ctrl_DP_B.Sum_l;

  /* Saturate: '<S16>/Saturation' */
  if (ctrl_DP_B.regulationerror[2] > ctrl_DP_P.Saturation_UpperSat_a) {
    rtb_psi_dot = ctrl_DP_P.Saturation_UpperSat_a;
  } else if (ctrl_DP_B.regulationerror[2] < ctrl_DP_P.Saturation_LowerSat_dy) {
    rtb_psi_dot = ctrl_DP_P.Saturation_LowerSat_dy;
  } else {
    rtb_psi_dot = ctrl_DP_B.regulationerror[2];
  }

  /* End of Saturate: '<S16>/Saturation' */

  /* Signum: '<S16>/Sign' */
  if (rtb_psi_dot < 0.0) {
    u_idx_1 = -1.0;
  } else if (rtb_psi_dot > 0.0) {
    u_idx_1 = 1.0;
  } else if (rtb_psi_dot == 0.0) {
    u_idx_1 = 0.0;
  } else {
    u_idx_1 = rtb_psi_dot;
  }

  /* End of Signum: '<S16>/Sign' */

  /* Gain: '<S16>/Gain' */
  rtb_Row2 = ctrl_DP_P.Gain_Gain_g * u_idx_1;

  /* Sum: '<S16>/Sum1' */
  rtb_psi_dot += rtb_Row2;

  /* Math: '<S16>/Math Function' incorporates:
   *  Constant: '<S16>/Constant'
   */
  rtb_psi_dot = rt_remd_snf(rtb_psi_dot, ctrl_DP_P.Constant_Value_p);

  /* Sum: '<S16>/Sum' */
  rtb_psi_dot -= rtb_Row2;

  /* SignalConversion: '<S13>/TmpSignal ConversionAtMatrix MultiplyInport2' incorporates:
   *  Fcn: '<S14>/Row1'
   *  Fcn: '<S14>/Row2'
   *  Fcn: '<S14>/Row3'
   */
  ctrl_DP_B.TmpSignalConversionAtMatrixMult[0] = cos(rtb_Row1) *
    ctrl_DP_B.regulationerror[0] + sin(rtb_Row1) * ctrl_DP_B.regulationerror[1];
  ctrl_DP_B.TmpSignalConversionAtMatrixMult[1] = -sin(rtb_Row1) *
    ctrl_DP_B.regulationerror[0] + cos(rtb_Row1) * ctrl_DP_B.regulationerror[1];
  ctrl_DP_B.TmpSignalConversionAtMatrixMult[2] = rtb_psi_dot;

  /* Integrator: '<S13>/Integrator' incorporates:
   *  Integrator: '<S8>/Integrator1'
   */
  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,&ctrl_DP_PrevZCX.Integrator_Reset_ZCE,
                       (ctrl_DP_B.reset));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT) {
      ctrl_DP_X.Integrator_CSTATE[0] = ctrl_DP_P.Integrator_IC;
      ctrl_DP_X.Integrator_CSTATE[1] = ctrl_DP_P.Integrator_IC;
      ctrl_DP_X.Integrator_CSTATE[2] = ctrl_DP_P.Integrator_IC;
    }

    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_DP_PrevZCX.Integrator1_Reset_ZCE_e,
                       (ctrl_DP_B.reset));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT) {
      ctrl_DP_X.Integrator1_CSTATE_g[0] = ctrl_DP_P.Integrator1_IC[0];
      ctrl_DP_X.Integrator1_CSTATE_g[1] = ctrl_DP_P.Integrator1_IC[1];
      ctrl_DP_X.Integrator1_CSTATE_g[2] = ctrl_DP_P.Integrator1_IC[2];
    }
  }

  /* Integrator: '<S8>/Integrator1' */
  ctrl_DP_B.Integrator1_g[0] = ctrl_DP_X.Integrator1_CSTATE_g[0];
  ctrl_DP_B.Integrator1_g[1] = ctrl_DP_X.Integrator1_CSTATE_g[1];
  ctrl_DP_B.Integrator1_g[2] = ctrl_DP_X.Integrator1_CSTATE_g[2];

  /* Integrator: '<S18>/Integrator3' */
  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,&ctrl_DP_PrevZCX.Integrator3_Reset_ZCE,
                       (ctrl_DP_B.reset));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT) {
      ctrl_DP_X.Integrator3_CSTATE[0] = ctrl_DP_P.Integrator3_IC;
      ctrl_DP_X.Integrator3_CSTATE[1] = ctrl_DP_P.Integrator3_IC;
      ctrl_DP_X.Integrator3_CSTATE[2] = ctrl_DP_P.Integrator3_IC;
    }
  }

  ctrl_DP_B.Integrator3[0] = ctrl_DP_X.Integrator3_CSTATE[0];
  ctrl_DP_B.Integrator3[1] = ctrl_DP_X.Integrator3_CSTATE[1];
  ctrl_DP_B.Integrator3[2] = ctrl_DP_X.Integrator3_CSTATE[2];

  /* End of Integrator: '<S18>/Integrator3' */

  /* Sum: '<S13>/Sum4' incorporates:
   *  Fcn: '<S15>/Row1'
   *  Fcn: '<S15>/Row2'
   *  Fcn: '<S15>/Row3'
   *  SignalConversion: '<S18>/TmpSignal ConversionAtMatrix Multiply2Inport2'
   */
  ctrl_DP_B.Sum4[0] = ctrl_DP_B.Integrator1_g[0] - (cos(ctrl_DP_B.Sum_l) *
    ctrl_DP_B.Integrator3[0] + sin(ctrl_DP_B.Sum_l) * ctrl_DP_B.Integrator3[1]);
  ctrl_DP_B.Sum4[1] = ctrl_DP_B.Integrator1_g[1] - (-sin(ctrl_DP_B.Sum_l) *
    ctrl_DP_B.Integrator3[0] + cos(ctrl_DP_B.Sum_l) * ctrl_DP_B.Integrator3[1]);
  ctrl_DP_B.Sum4[2] = ctrl_DP_B.Integrator1_g[2] - ctrl_DP_B.Integrator3[2];
  for (r2 = 0; r2 < 3; r2++) {
    /* Sum: '<S13>/Sum3' incorporates:
     *  Integrator: '<S13>/Integrator'
     *  Product: '<S13>/Matrix Multiply'
     *  Product: '<S13>/Matrix Multiply1'
     *  Product: '<S13>/Matrix Multiply2'
     */
    ctrl_DP_B.Sum3[r2] = ((0.0 - ((ctrl_DP_B.sf_MATLABFunction.K_p[r2 + 3] *
      ctrl_DP_B.TmpSignalConversionAtMatrixMult[1] +
      ctrl_DP_B.sf_MATLABFunction.K_p[r2] *
      ctrl_DP_B.TmpSignalConversionAtMatrixMult[0]) +
      ctrl_DP_B.sf_MATLABFunction.K_p[r2 + 6] *
      ctrl_DP_B.TmpSignalConversionAtMatrixMult[2])) -
                          (ctrl_DP_B.sf_MATLABFunction1.K_i[r2 + 6] *
      ctrl_DP_X.Integrator_CSTATE[2] + (ctrl_DP_B.sf_MATLABFunction1.K_i[r2 + 3]
      * ctrl_DP_X.Integrator_CSTATE[1] + ctrl_DP_B.sf_MATLABFunction1.K_i[r2] *
      ctrl_DP_X.Integrator_CSTATE[0]))) - ((ctrl_DP_B.sf_MATLABFunction2.K_d[r2
      + 3] * ctrl_DP_B.Sum4[1] + ctrl_DP_B.sf_MATLABFunction2.K_d[r2] *
      ctrl_DP_B.Sum4[0]) + ctrl_DP_B.sf_MATLABFunction2.K_d[r2 + 6] *
      ctrl_DP_B.Sum4[2]);
  }

  /* MATLAB Function: '<Root>/Thrust allocation' incorporates:
   *  Constant: '<Root>/Constant'
   */
  /* MATLAB Function 'Thrust allocation': '<S11>:1' */
  /* '<S11>:1:23' */
  /*  Forces and moments vector */
  /* '<S11>:1:4' */
  /*  Extended thrust configuration matrix */
  /*  Extended thrust coefficient matrix */
  /*  tau = T*K*u inverse */
  /* '<S11>:1:23' */
  u_idx_1 = ctrl_DP_B.Sum3[1] - ctrl_DP_B.Sum3[0] * 0.0;
  u_idx_2 = ((ctrl_DP_B.Sum3[2] - ctrl_DP_B.Sum3[0] * 0.0) - u_idx_1 * -0.4575) /
    0.7605;
  u_idx_1 -= u_idx_2 * 0.9;
  u_idx_1 /= 1.165;
  u_idx_0 = ((ctrl_DP_B.Sum3[0] - u_idx_2 * 0.0) - u_idx_1 * 0.0) / 1.165;

  /* '<S11>:1:25' */
  /* '<S11>:1:27' */
  /* '<S11>:1:28' */
  /* '<S11>:1:29' */
  /* '<S11>:1:30' */
  if (ctrl_DP_P.Constant_Value_l != 0.0) {
    /* '<S11>:1:33' */
    ctrl_DP_B.omega_VSP = 0.3;
  } else {
    /* '<S11>:1:35' */
    ctrl_DP_B.omega_VSP = 0.0;
  }

  ctrl_DP_B.u_BT = u_idx_2;
  ctrl_DP_B.u_VSP = sqrt(u_idx_0 * u_idx_0 + u_idx_1 * u_idx_1);
  ctrl_DP_B.alpha_VSP = rt_atan2d_snf(u_idx_1, u_idx_0);

  /* End of MATLAB Function: '<Root>/Thrust allocation' */
  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
    /* Memory: '<Root>/Memory' */
    memcpy(&ctrl_DP_B.Memory[0], &ctrl_DP_DW.Memory_PreviousInput[0], 81U *
           sizeof(real_T));

    /* Memory: '<Root>/Memory1' */
    memcpy(&ctrl_DP_B.Memory1[0], &ctrl_DP_DW.Memory1_PreviousInput[0], 9U *
           sizeof(real_T));
  }

  /* MATLAB Function: '<Root>/EKF INS' incorporates:
   *  Gain: '<S6>/Gain'
   *  Gain: '<S6>/Gain1'
   *  Gain: '<S6>/Gain2'
   *  SignalConversion: '<S3>/TmpSignal ConversionAt SFunction Inport3'
   */
  memcpy(&ctrl_DP_B.x_p[0], &ctrl_DP_B.Memory1[0], 9U * sizeof(real_T));
  memcpy(&ctrl_DP_B.P[0], &ctrl_DP_B.Memory[0], 81U * sizeof(real_T));

  /* MATLAB Function 'EKF INS': '<S3>:1' */
  /* '<S3>:1:14' */
  /* '<S3>:1:12' */
  /* '<S3>:1:11' */
  /* '<S3>:1:10' */
  /* '<S3>:1:19' */
  /* '<S3>:1:25' */
  /* '<S3>:1:20' */
  /* '<S3>:1:1' */
  /* '<S3>:1:2' */
  /* Rotating accelerations to body frame */
  /* '<S3>:1:4' */
  /* Gain */
  /* '<S3>:1:7' */
  /* System matrices */
  /* '<S3>:1:10' */
  C_NL[0] = cos(ctrl_DP_B.Sum);
  C_NL[3] = -sin(ctrl_DP_B.Sum);
  C_NL[6] = 0.0;
  C_NL[1] = sin(ctrl_DP_B.Sum);
  C_NL[4] = cos(ctrl_DP_B.Sum);
  C_NL[7] = 0.0;
  C_NL[2] = 0.0;
  C_NL[5] = 0.0;
  C_NL[8] = 1.0;
  for (r2 = 0; r2 < 9; r2++) {
    A[9 * r2] = c[3 * r2];
    A[1 + 9 * r2] = c[3 * r2 + 1];
    A[2 + 9 * r2] = c[3 * r2 + 2];
  }

  for (r2 = 0; r2 < 6; r2++) {
    A[3 + 9 * r2] = 0.0;
    A[4 + 9 * r2] = 0.0;
    A[5 + 9 * r2] = 0.0;
  }

  for (r2 = 0; r2 < 3; r2++) {
    A[3 + 9 * (r2 + 6)] = -C_NL[3 * r2];
    A[4 + 9 * (r2 + 6)] = -C_NL[3 * r2 + 1];
    A[5 + 9 * (r2 + 6)] = -C_NL[3 * r2 + 2];
  }

  /* '<S3>:1:13' */
  /* Measurement and process noise covariance matrices */
  /* '<S3>:1:19' */
  /* '<S3>:1:20' */
  /* EKF algorithm */
  /* Update */
  /* '<S3>:1:25' */
  for (r2 = 0; r2 < 9; r2++) {
    for (r1 = 0; r1 < 3; r1++) {
      A[(r1 + 9 * r2) + 6] = 0.0;
      K_0[r2 + 9 * r1] = 0.0;
      for (r3 = 0; r3 < 9; r3++) {
        K_0[r2 + 9 * r1] += ctrl_DP_B.P[9 * r3 + r2] * (real_T)b_b[9 * r1 + r3];
      }
    }
  }

  for (r2 = 0; r2 < 3; r2++) {
    for (r1 = 0; r1 < 9; r1++) {
      K[r2 + 3 * r1] = 0.0;
      for (r3 = 0; r3 < 9; r3++) {
        K[r2 + 3 * r1] += (real_T)a[3 * r3 + r2] * ctrl_DP_B.P[9 * r1 + r3];
      }
    }

    for (r1 = 0; r1 < 3; r1++) {
      rtb_Row1_o = 0.0;
      for (r3 = 0; r3 < 9; r3++) {
        rtb_Row1_o += K[3 * r3 + r2] * (real_T)b_b[9 * r1 + r3];
      }

      D_NL[r2 + 3 * r1] = R[3 * r1 + r2] + rtb_Row1_o;
    }
  }

  r1 = 0;
  r2 = 1;
  r3 = 2;
  rtb_psi_dot = fabs(D_NL[0]);
  rtb_Row2 = fabs(D_NL[1]);
  if (rtb_Row2 > rtb_psi_dot) {
    rtb_psi_dot = rtb_Row2;
    r1 = 1;
    r2 = 0;
  }

  if (fabs(D_NL[2]) > rtb_psi_dot) {
    r1 = 2;
    r2 = 1;
    r3 = 0;
  }

  D_NL[r2] /= D_NL[r1];
  D_NL[r3] /= D_NL[r1];
  D_NL[3 + r2] -= D_NL[3 + r1] * D_NL[r2];
  D_NL[3 + r3] -= D_NL[3 + r1] * D_NL[r3];
  D_NL[6 + r2] -= D_NL[6 + r1] * D_NL[r2];
  D_NL[6 + r3] -= D_NL[6 + r1] * D_NL[r3];
  if (fabs(D_NL[3 + r3]) > fabs(D_NL[3 + r2])) {
    rtemp = r2;
    r2 = r3;
    r3 = rtemp;
  }

  D_NL[3 + r3] /= D_NL[3 + r2];
  D_NL[6 + r3] -= D_NL[3 + r3] * D_NL[6 + r2];
  for (rtemp = 0; rtemp < 9; rtemp++) {
    K[rtemp + 9 * r1] = K_0[rtemp] / D_NL[r1];
    K[rtemp + 9 * r2] = K_0[9 + rtemp] - K[9 * r1 + rtemp] * D_NL[3 + r1];
    K[rtemp + 9 * r3] = K_0[18 + rtemp] - K[9 * r1 + rtemp] * D_NL[6 + r1];
    K[rtemp + 9 * r2] /= D_NL[3 + r2];
    K[rtemp + 9 * r3] -= K[9 * r2 + rtemp] * D_NL[6 + r2];
    K[rtemp + 9 * r3] /= D_NL[6 + r3];
    K[rtemp + 9 * r2] -= K[9 * r3 + rtemp] * D_NL[3 + r3];
    K[rtemp + 9 * r1] -= K[9 * r3 + rtemp] * D_NL[r3];
    K[rtemp + 9 * r1] -= K[9 * r2 + rtemp] * D_NL[r2];
  }

  /* '<S3>:1:26' */
  rtb_MatrixMultiply[0] = ctrl_DP_B.mm2m;
  rtb_MatrixMultiply[1] = ctrl_DP_B.mm2m_e;
  rtb_MatrixMultiply[2] = ctrl_DP_B.z_m;
  for (r2 = 0; r2 < 3; r2++) {
    tau[r2] = 0.0;
    for (r1 = 0; r1 < 9; r1++) {
      tau[r2] += (real_T)a[3 * r1 + r2] * ctrl_DP_B.x_p[r1];
    }

    tmp[r2] = rtb_MatrixMultiply[r2] - tau[r2];
  }

  for (r2 = 0; r2 < 9; r2++) {
    D_NL[r2] = ((K[r2 + 9] * tmp[1] + K[r2] * tmp[0]) + K[r2 + 18] * tmp[2]) +
      ctrl_DP_B.x_p[r2];
  }

  /* '<S3>:1:27' */
  memset(&I[0], 0, 81U * sizeof(int8_T));
  for (r1 = 0; r1 < 9; r1++) {
    I[r1 + 9 * r1] = 1;
  }

  memset(&b_I[0], 0, 81U * sizeof(int8_T));
  for (r1 = 0; r1 < 9; r1++) {
    b_I[r1 + 9 * r1] = 1;
  }

  /* '<S3>:1:29' */
  ctrl_DP_B.pos_est[0] = D_NL[0];
  ctrl_DP_B.pos_est[1] = D_NL[1];
  ctrl_DP_B.pos_est[2] = D_NL[2];

  /* Propagation */
  /* '<S3>:1:32' */
  for (r2 = 0; r2 < 6; r2++) {
    tmp_0[9 * r2] = 0.0;
    tmp_0[1 + 9 * r2] = 0.0;
    tmp_0[2 + 9 * r2] = 0.0;
  }

  tmp_0[3] = cos(ctrl_DP_B.Sum);
  tmp_0[12] = -sin(ctrl_DP_B.Sum);
  tmp_0[21] = 0.0;
  tmp_0[4] = sin(ctrl_DP_B.Sum);
  tmp_0[13] = cos(ctrl_DP_B.Sum);
  tmp_0[22] = 0.0;
  for (r2 = 0; r2 < 3; r2++) {
    tmp_0[5 + 9 * r2] = b[r2];
    tmp_0[3 + 9 * (r2 + 3)] = d[3 * r2];
    tmp_0[4 + 9 * (r2 + 3)] = d[3 * r2 + 1];
    tmp_0[5 + 9 * (r2 + 3)] = d[3 * r2 + 2];
  }

  for (r2 = 0; r2 < 6; r2++) {
    tmp_0[6 + 9 * r2] = 0.0;
    tmp_0[7 + 9 * r2] = 0.0;
    tmp_0[8 + 9 * r2] = 0.0;
  }

  e[0] = ctrl_DP_P.Gain_Gain_c * ctrl_DP_B.Acc_x;
  e[1] = -(ctrl_DP_P.Gain1_Gain * ctrl_DP_B.Acc_y);
  e[2] = -(ctrl_DP_P.Gain2_Gain * ctrl_DP_B.Acc_z);
  e[3] = 0.0;
  e[4] = 0.0;
  e[5] = -9.81;

  /* '<S3>:1:33' */
  for (r2 = 0; r2 < 9; r2++) {
    A_0[r2] = 0.0;
    for (r1 = 0; r1 < 9; r1++) {
      A_0[r2] += A[9 * r1 + r2] * D_NL[r1];
    }

    C_NL[r2] = 0.0;
    for (r1 = 0; r1 < 6; r1++) {
      C_NL[r2] += tmp_0[9 * r1 + r2] * e[r1];
    }

    ctrl_DP_B.x_p[r2] = (A_0[r2] + C_NL[r2]) * 0.01 + D_NL[r2];
    for (r1 = 0; r1 < 9; r1++) {
      I_0[r2 + 9 * r1] = (real_T)I[9 * r1 + r2] - (((real_T)a[3 * r1 + 1] * K[r2
        + 9] + (real_T)a[3 * r1] * K[r2]) + (real_T)a[3 * r1 + 2] * K[r2 + 18]);
    }

    for (r1 = 0; r1 < 9; r1++) {
      I_1[r2 + 9 * r1] = 0.0;
      for (r3 = 0; r3 < 9; r3++) {
        I_1[r2 + 9 * r1] += I_0[9 * r3 + r2] * ctrl_DP_B.P[9 * r1 + r3];
      }

      b_I_0[r2 + 9 * r1] = (real_T)b_I[9 * r2 + r1] - (((real_T)a[3 * r2 + 1] *
        K[r1 + 9] + (real_T)a[3 * r2] * K[r1]) + (real_T)a[3 * r2 + 2] * K[r1 +
        18]);
    }

    for (r1 = 0; r1 < 3; r1++) {
      K_0[r2 + 9 * r1] = 0.0;
      K_0[r2 + 9 * r1] += R[3 * r1] * K[r2];
      K_0[r2 + 9 * r1] += R[3 * r1 + 1] * K[r2 + 9];
      K_0[r2 + 9 * r1] += R[3 * r1 + 2] * K[r2 + 18];
    }
  }

  for (r2 = 0; r2 < 9; r2++) {
    for (r1 = 0; r1 < 9; r1++) {
      I_0[r2 + 9 * r1] = 0.0;
      for (r3 = 0; r3 < 9; r3++) {
        I_0[r2 + 9 * r1] += I_1[9 * r3 + r2] * b_I_0[9 * r1 + r3];
      }

      K_1[r2 + 9 * r1] = 0.0;
      K_1[r2 + 9 * r1] += K_0[r2] * K[r1];
      K_1[r2 + 9 * r1] += K_0[r2 + 9] * K[r1 + 9];
      K_1[r2 + 9 * r1] += K_0[r2 + 18] * K[r1 + 18];
    }
  }

  for (r2 = 0; r2 < 9; r2++) {
    for (r1 = 0; r1 < 9; r1++) {
      I_1[r1 + 9 * r2] = I_0[9 * r2 + r1] + K_1[9 * r2 + r1];
    }
  }

  for (r2 = 0; r2 < 9; r2++) {
    for (r1 = 0; r1 < 9; r1++) {
      I_0[r2 + 9 * r1] = 0.0;
      for (r3 = 0; r3 < 9; r3++) {
        I_0[r2 + 9 * r1] += A[9 * r3 + r2] * I_1[9 * r1 + r3];
      }
    }

    for (r1 = 0; r1 < 9; r1++) {
      rtb_Row1_o = 0.0;
      for (r3 = 0; r3 < 9; r3++) {
        rtb_Row1_o += I_0[9 * r3 + r2] * A[9 * r3 + r1];
      }

      ctrl_DP_B.P[r2 + 9 * r1] = Q[9 * r1 + r2] + rtb_Row1_o;
    }
  }

  /* End of MATLAB Function: '<Root>/EKF INS' */

  /* Integrator: '<S8>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,&ctrl_DP_PrevZCX.Integrator_Reset_ZCE_n,
                       (ctrl_DP_B.reset));

    /* evaluate zero-crossings */
    if ((zcEvent != NO_ZCEVENT) || (ctrl_DP_DW.Integrator_IWORK != 0)) {
      ctrl_DP_X.Integrator_CSTATE_l[0] = ctrl_DP_B.mm2m;
      ctrl_DP_X.Integrator_CSTATE_l[1] = ctrl_DP_B.mm2m_e;
      ctrl_DP_X.Integrator_CSTATE_l[2] = ctrl_DP_B.Sum;
    }
  }

  ctrl_DP_B.Integrator[0] = ctrl_DP_X.Integrator_CSTATE_l[0];
  ctrl_DP_B.Integrator[1] = ctrl_DP_X.Integrator_CSTATE_l[1];
  ctrl_DP_B.Integrator[2] = ctrl_DP_X.Integrator_CSTATE_l[2];

  /* End of Integrator: '<S8>/Integrator' */

  /* Saturate: '<S41>/Saturation' */
  if (ctrl_DP_B.Integrator[2] > ctrl_DP_P.Saturation_UpperSat_l) {
    rtb_Row1_o = ctrl_DP_P.Saturation_UpperSat_l;
  } else if (ctrl_DP_B.Integrator[2] < ctrl_DP_P.Saturation_LowerSat_cz) {
    rtb_Row1_o = ctrl_DP_P.Saturation_LowerSat_cz;
  } else {
    rtb_Row1_o = ctrl_DP_B.Integrator[2];
  }

  /* End of Saturate: '<S41>/Saturation' */

  /* Signum: '<S41>/Sign' */
  if (rtb_Row1_o < 0.0) {
    rtb_psi_dot = -1.0;
  } else if (rtb_Row1_o > 0.0) {
    rtb_psi_dot = 1.0;
  } else if (rtb_Row1_o == 0.0) {
    rtb_psi_dot = 0.0;
  } else {
    rtb_psi_dot = rtb_Row1_o;
  }

  /* End of Signum: '<S41>/Sign' */

  /* Gain: '<S41>/Gain' */
  rtb_psi_dot *= ctrl_DP_P.Gain_Gain_d;

  /* Sum: '<S41>/Sum1' */
  rtb_Row1_o += rtb_psi_dot;

  /* Math: '<S41>/Math Function' incorporates:
   *  Constant: '<S41>/Constant'
   */
  rtb_Row1_o = rt_remd_snf(rtb_Row1_o, ctrl_DP_P.Constant_Value_p4);

  /* Sum: '<S41>/Sum' */
  ctrl_DP_B.Sum_f = rtb_Row1_o - rtb_psi_dot;

  /* Saturate: '<S42>/Saturation' */
  if (ctrl_DP_B.Sum > ctrl_DP_P.Saturation_UpperSat_o) {
    rtb_Row1_o = ctrl_DP_P.Saturation_UpperSat_o;
  } else if (ctrl_DP_B.Sum < ctrl_DP_P.Saturation_LowerSat_j) {
    rtb_Row1_o = ctrl_DP_P.Saturation_LowerSat_j;
  } else {
    rtb_Row1_o = ctrl_DP_B.Sum;
  }

  /* End of Saturate: '<S42>/Saturation' */

  /* Signum: '<S42>/Sign' */
  if (rtb_Row1_o < 0.0) {
    rtb_psi_dot = -1.0;
  } else if (rtb_Row1_o > 0.0) {
    rtb_psi_dot = 1.0;
  } else if (rtb_Row1_o == 0.0) {
    rtb_psi_dot = 0.0;
  } else {
    rtb_psi_dot = rtb_Row1_o;
  }

  /* End of Signum: '<S42>/Sign' */

  /* Gain: '<S42>/Gain' */
  rtb_psi_dot *= ctrl_DP_P.Gain_Gain_h;

  /* Sum: '<S42>/Sum1' */
  rtb_Row1_o += rtb_psi_dot;

  /* Math: '<S42>/Math Function' incorporates:
   *  Constant: '<S42>/Constant'
   */
  rtb_Row1_o = rt_remd_snf(rtb_Row1_o, ctrl_DP_P.Constant_Value_i);

  /* Sum: '<S42>/Sum' */
  rtb_Row1_o -= rtb_psi_dot;

  /* Fcn: '<S8>/Fcn' */
  rtb_psi_dot = rtb_Row1_o;

  /* Integrator: '<S8>/Integrator2' */
  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,&ctrl_DP_PrevZCX.Integrator2_Reset_ZCE,
                       (ctrl_DP_B.reset));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT) {
      ctrl_DP_X.Integrator2_CSTATE[0] = ctrl_DP_P.Integrator2_IC[0];
      ctrl_DP_X.Integrator2_CSTATE[1] = ctrl_DP_P.Integrator2_IC[1];
      ctrl_DP_X.Integrator2_CSTATE[2] = ctrl_DP_P.Integrator2_IC[2];
    }
  }

  /* Sum: '<S8>/Sum' */
  u_idx_0 = ctrl_DP_B.mm2m - ctrl_DP_B.Integrator[0];
  u_idx_1 = ctrl_DP_B.mm2m_e - ctrl_DP_B.Integrator[1];
  u_idx_2 = rtb_Row1_o - ctrl_DP_B.Sum_f;
  for (r1 = 0; r1 < 3; r1++) {
    /* Integrator: '<S8>/Integrator2' */
    ctrl_DP_B.Integrator2[r1] = ctrl_DP_X.Integrator2_CSTATE[r1];

    /* Product: '<S8>/Matrix Multiply2' */
    rtb_MatrixMultiply[r1] = ctrl_DP_B.sf_MATLABFunction2_p.K_d[r1 + 6] *
      u_idx_2 + (ctrl_DP_B.sf_MATLABFunction2_p.K_d[r1 + 3] * u_idx_1 +
                 ctrl_DP_B.sf_MATLABFunction2_p.K_d[r1] * u_idx_0);
  }

  /* MATLAB Function: '<S48>/Bow thruster' */
  /* MATLAB Function 'u_2_tau/Thruster mapping/Bow thruster': '<S49>:1' */
  /* '<S49>:1:3' */
  /*  Thruster characteristics */
  if (ctrl_DP_B.u_BT > 0.0879) {
    /* '<S49>:1:5' */
    /* '<S49>:1:6' */
    /* '<S49>:1:7' */
    /* '<S49>:1:8' */
    /* '<S49>:1:9' */
    /* '<S49>:1:10' */
    rtb_Row2 = exp(0.1174 * ctrl_DP_B.u_BT) * 2.515 + exp(-1.131 *
      ctrl_DP_B.u_BT) * -2.807;
  } else if (ctrl_DP_B.u_BT < -0.059) {
    /* '<S49>:1:11' */
    /* '<S49>:1:12' */
    /* '<S49>:1:13' */
    /* '<S49>:1:14' */
    /* '<S49>:1:15' */
    /* '<S49>:1:16' */
    rtb_Row2 = exp(0.193 * ctrl_DP_B.u_BT) * -548.0 + exp(0.1992 *
      ctrl_DP_B.u_BT) * 548.2;
  } else {
    /* '<S49>:1:18' */
    rtb_Row2 = 0.0;
  }

  /* MATLAB Function: '<S12>/Thruster configuration matrix' incorporates:
   *  MATLAB Function: '<S48>/Bow thruster'
   *  MATLAB Function: '<S48>/VSP'
   */
  /*  Thruster losses due to forward speed */
  /* '<S49>:1:21' */
  /* '<S49>:1:22' */
  /* '<S49>:1:23' */
  /* '<S49>:1:24' */
  /* '<S49>:1:25' */
  /* MATLAB Function 'u_2_tau/Thruster mapping/VSP': '<S50>:1' */
  /*  Calculating the force in x-direction */
  /* '<S50>:1:4' */
  /* '<S50>:1:5' */
  /* '<S50>:1:6' */
  /* '<S50>:1:7' */
  /* '<S50>:1:8' */
  /* '<S50>:1:9' */
  /* '<S50>:1:10' */
  /* '<S50>:1:11' */
  /* '<S50>:1:12' */
  /* '<S50>:1:13' */
  /* '<S50>:1:14' */
  /* '<S50>:1:15' */
  /* '<S50>:1:16' */
  /* '<S50>:1:17' */
  /* '<S50>:1:18' */
  /* '<S50>:1:19' */
  /* '<S50>:1:20' */
  /* '<S50>:1:21' */
  /* '<S50>:1:22' */
  /*  Calculating the force in y-direction */
  /* '<S50>:1:29' */
  /* '<S50>:1:30' */
  /* '<S50>:1:31' */
  /* '<S50>:1:32' */
  /* '<S50>:1:33' */
  /* '<S50>:1:34' */
  /* '<S50>:1:35' */
  /* '<S50>:1:36' */
  /* '<S50>:1:37' */
  /* '<S50>:1:38' */
  /* '<S50>:1:39' */
  /* '<S50>:1:40' */
  /* '<S50>:1:41' */
  /* '<S50>:1:42' */
  /* '<S50>:1:43' */
  /* '<S50>:1:44' */
  /* '<S50>:1:45' */
  /* '<S50>:1:46' */
  /* '<S50>:1:47' */
  /* MATLAB Function 'u_2_tau/Thruster configuration matrix': '<S47>:1' */
  /* '<S47>:1:13' */
  /* '<S47>:1:7' */
  /* '<S47>:1:13' */
  rtb_Row1 = (((((sin(1.001 * ctrl_DP_B.alpha_VSP + 1.564) * 1.107 + sin(0.1397 *
    ctrl_DP_B.alpha_VSP + -1.599) * 0.3471) + sin(1.993 * ctrl_DP_B.alpha_VSP +
    1.886) * 0.1558) + sin(0.218 * ctrl_DP_B.alpha_VSP + 1.513) * 0.1599) + sin
               (2.986 * ctrl_DP_B.alpha_VSP + -1.601) * 0.08237) + sin(3.964 *
    ctrl_DP_B.alpha_VSP + 1.738) * 0.04641) * ctrl_DP_B.u_VSP;
  tmp_3 = (((((sin(1.001 * ctrl_DP_B.alpha_VSP + 0.01605) * 0.7936 + sin(1.997 *
    ctrl_DP_B.alpha_VSP + 0.03229) * 0.2112) + sin(2.991 * ctrl_DP_B.alpha_VSP +
    2.986) * 0.07608) + sin(3.999 * ctrl_DP_B.alpha_VSP + -0.8668) * 0.04817) +
            sin(4.904 * ctrl_DP_B.alpha_VSP + -2.622) * 0.01757) + sin(5.068 *
            ctrl_DP_B.alpha_VSP + 0.2548) * -0.02089) * ctrl_DP_B.u_VSP;
  rtb_Row2 = (atan(-10.22 * ctrl_DP_B.Integrator1_g[0] + 2.947) * 0.3075 +
              0.7561) * rtb_Row2 / 1.1385;
  for (r2 = 0; r2 < 3; r2++) {
    tau[r2] = a_0[r2 + 6] * rtb_Row2 + (a_0[r2 + 3] * tmp_3 + a_0[r2] * rtb_Row1);
  }

  /* MATLAB Function: '<S8>/D(nu)*nu' */
  /* '<S47>:1:15' */
  /* '<S47>:1:16' */
  /* '<S47>:1:17' */
  /* MATLAB Function 'Nonlinear Passisve Observer/D(nu)*nu': '<S37>:1' */
  /* '<S37>:1:3' */
  /* '<S37>:1:4' */
  /* '<S37>:1:5' */
  /* '<S37>:1:7' */
  /* D */
  /*     D = D(U,V,R) */
  /*     This function was generated by the Symbolic Math Toolbox version 7.1. */
  /*     13-Jul-2017 11:39:12 */
  rtb_Row2 = fabs(ctrl_DP_B.Integrator1_g[2]);
  rtb_Row1 = fabs(ctrl_DP_B.Integrator1_g[1]);
  x[0] = (ctrl_DP_B.Integrator1_g[0] * ctrl_DP_B.Integrator1_g[0] * 3.787 + fabs
          (ctrl_DP_B.Integrator1_g[0]) * -0.3545) + 0.6555;
  x[1] = 0.0;
  x[2] = 0.0;
  x[3] = 0.0;
  x[4] = ((rtb_Row2 * 0.805 + rtb_Row1 * 2.776) + ctrl_DP_B.Integrator1_g[1] *
          ctrl_DP_B.Integrator1_g[1] * 64.91) + 1.33;
  x[5] = rtb_Row2 * -0.13 + rtb_Row1 * 0.2088;
  x[6] = 0.0;
  x[7] = (rtb_Row2 * 3.45 + rtb_Row1 * 0.845) + 7.25;
  x[8] = (rtb_Row2 * 0.75 - rtb_Row1 * 0.08) + 1.9;
  memcpy(&D_NL[0], &x[0], 9U * sizeof(real_T));

  /* MATLAB Function: '<S8>/C(nu)*nu' */
  /* '<S37>:1:9' */
  /* MATLAB Function 'Nonlinear Passisve Observer/C(nu)*nu': '<S36>:1' */
  /* '<S36>:1:3' */
  /* '<S36>:1:4' */
  /* '<S36>:1:5' */
  /* '<S36>:1:7' */
  /* C */
  /*     C = C(U,V,R) */
  /*     This function was generated by the Symbolic Math Toolbox version 7.1. */
  /*     13-Jul-2017 11:39:13 */
  rtb_Row2 = ctrl_DP_B.Integrator1_g[0] * 16.11;
  x[0] = 0.0;
  x[1] = 0.0;
  x[2] = ctrl_DP_B.Integrator1_g[2] * 0.529125 + ctrl_DP_B.Integrator1_g[1] *
    24.11;
  x[3] = 0.0;
  x[4] = 0.0;
  x[5] = -rtb_Row2;
  x[6] = ctrl_DP_B.Integrator1_g[2] * -0.529125 - ctrl_DP_B.Integrator1_g[1] *
    24.11;
  x[7] = rtb_Row2;
  x[8] = 0.0;
  memcpy(&C_NL[0], &x[0], 9U * sizeof(real_T));

  /* Sum: '<S8>/Sum2' incorporates:
   *  Fcn: '<S39>/Row1'
   *  Fcn: '<S39>/Row2'
   *  Fcn: '<S39>/Row3'
   *  Fcn: '<S8>/Fcn'
   *  MATLAB Function: '<S12>/Thruster configuration matrix'
   */
  /* '<S36>:1:9' */
  rtb_y_l_0[0] = cos(rtb_Row1_o) * rtb_MatrixMultiply[0] + sin(rtb_Row1_o) *
    rtb_MatrixMultiply[1];
  rtb_y_l_0[1] = -sin(rtb_Row1_o) * rtb_MatrixMultiply[0] + cos(rtb_Row1_o) *
    rtb_MatrixMultiply[1];
  rtb_y_l_0[2] = rtb_MatrixMultiply[2];
  tau_0[0] = tau[0];
  tau_0[1] = tau[1];
  tau_0[2] = tau[2];

  /* Sum: '<S8>/Sum3' incorporates:
   *  Fcn: '<S40>/Row1'
   *  Fcn: '<S40>/Row2'
   *  Fcn: '<S40>/Row3'
   *  Fcn: '<S8>/Fcn'
   *  Gain: '<S8>/M^-1'
   *  MATLAB Function: '<S8>/C(nu)*nu'
   *  MATLAB Function: '<S8>/D(nu)*nu'
   *  Sum: '<S8>/Sum2'
   */
  tmp_1[0] = cos(rtb_Row1_o) * ctrl_DP_B.Integrator2[0] + sin(rtb_Row1_o) *
    ctrl_DP_B.Integrator2[1];
  tmp_1[1] = -sin(rtb_Row1_o) * ctrl_DP_B.Integrator2[0] + cos(rtb_Row1_o) *
    ctrl_DP_B.Integrator2[1];
  tmp_1[2] = ctrl_DP_B.Integrator2[2];
  for (r2 = 0; r2 < 3; r2++) {
    rtb_MatrixMultiply[r2] = (((rtb_y_l_0[r2] + tau_0[r2]) + tmp_1[r2]) -
      ((D_NL[r2 + 3] * ctrl_DP_B.Integrator1_g[1] + D_NL[r2] *
        ctrl_DP_B.Integrator1_g[0]) + D_NL[r2 + 6] * ctrl_DP_B.Integrator1_g[2]))
      - (C_NL[r2 + 6] * ctrl_DP_B.Integrator1_g[2] + (C_NL[r2 + 3] *
          ctrl_DP_B.Integrator1_g[1] + C_NL[r2] * ctrl_DP_B.Integrator1_g[0]));
  }

  /* End of Sum: '<S8>/Sum3' */

  /* Gain: '<S8>/M^-1' */
  for (r2 = 0; r2 < 3; r2++) {
    ctrl_DP_B.M1[r2] = 0.0;
    ctrl_DP_B.M1[r2] += ctrl_DP_P.M1_Gain[r2] * rtb_MatrixMultiply[0];
    ctrl_DP_B.M1[r2] += ctrl_DP_P.M1_Gain[r2 + 3] * rtb_MatrixMultiply[1];
    ctrl_DP_B.M1[r2] += ctrl_DP_P.M1_Gain[r2 + 6] * rtb_MatrixMultiply[2];
  }

  /* Integrator: '<S18>/Integrator2' */
  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_DP_PrevZCX.Integrator2_Reset_ZCE_m,
                       (ctrl_DP_B.reset));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT) {
      ctrl_DP_X.Integrator2_CSTATE_e[0] = ctrl_DP_P.Integrator2_IC_h;
      ctrl_DP_X.Integrator2_CSTATE_e[1] = ctrl_DP_P.Integrator2_IC_h;
      ctrl_DP_X.Integrator2_CSTATE_e[2] = ctrl_DP_P.Integrator2_IC_h;
    }
  }

  /* MATLAB Function: '<S18>/w_d^-2' */
  /* MATLAB Function 'Guidance/Reference model/w_d^3': '<S23>:1' */
  /* '<S23>:1:4' */
  /* MATLAB Function 'Guidance/Reference model/w_d^-2': '<S22>:1' */
  /* '<S22>:1:4' */
  for (r2 = 0; r2 < 3; r2++) {
    for (r1 = 0; r1 < 3; r1++) {
      D_NL[r1 + 3 * r2] = 0.0;
      D_NL[r1 + 3 * r2] += rtb_w_d[3 * r2] * rtb_w_d[r1];
      D_NL[r1 + 3 * r2] += rtb_w_d[3 * r2 + 1] * rtb_w_d[r1 + 3];
      D_NL[r1 + 3 * r2] += rtb_w_d[3 * r2 + 2] * rtb_w_d[r1 + 6];
    }
  }

  memcpy(&C_NL[0], &D_NL[0], 9U * sizeof(real_T));
  r1 = 0;
  r2 = 3;
  r3 = 6;
  rtb_Row2 = fabs(D_NL[0]);
  rtb_Row1 = fabs(D_NL[1]);
  rtb_Row1_o = fabs(D_NL[2]);
  if ((rtb_Row1 > rtb_Row2) && (rtb_Row1 > rtb_Row1_o)) {
    r1 = 3;
    r2 = 0;
    C_NL[0] = D_NL[1];
    C_NL[1] = D_NL[0];
    C_NL[3] = D_NL[4];
    C_NL[4] = D_NL[3];
    C_NL[6] = D_NL[7];
    C_NL[7] = D_NL[6];
  } else {
    if (rtb_Row1_o > rtb_Row2) {
      r1 = 6;
      r3 = 0;
      C_NL[0] = D_NL[2];
      C_NL[2] = D_NL[0];
      C_NL[3] = D_NL[5];
      C_NL[5] = D_NL[3];
      C_NL[6] = D_NL[8];
      C_NL[8] = D_NL[6];
    }
  }

  rtb_Row2 = C_NL[1] / C_NL[0];
  C_NL[1] /= C_NL[0];
  rtb_Row1 = C_NL[2] / C_NL[0];
  C_NL[2] /= C_NL[0];
  C_NL[4] -= rtb_Row2 * C_NL[3];
  C_NL[5] -= rtb_Row1 * C_NL[3];
  C_NL[7] -= rtb_Row2 * C_NL[6];
  C_NL[8] -= rtb_Row1 * C_NL[6];
  if (fabs(C_NL[5]) > fabs(C_NL[4])) {
    rtemp = r2;
    r2 = r3;
    r3 = rtemp;
    C_NL[1] = rtb_Row1;
    C_NL[2] = rtb_Row2;
    rtb_Row2 = C_NL[4];
    C_NL[4] = C_NL[5];
    C_NL[5] = rtb_Row2;
    rtb_Row2 = C_NL[7];
    C_NL[7] = C_NL[8];
    C_NL[8] = rtb_Row2;
  }

  rtb_Row2 = C_NL[5] / C_NL[4];
  C_NL[5] /= C_NL[4];
  C_NL[8] -= rtb_Row2 * C_NL[7];
  rtb_Row1 = (C_NL[5] * C_NL[1] - C_NL[2]) / C_NL[8];
  rtb_Row2 = -(C_NL[7] * rtb_Row1 + C_NL[1]) / C_NL[4];
  D_NL[r1] = ((1.0 - C_NL[3] * rtb_Row2) - C_NL[6] * rtb_Row1) / C_NL[0];
  D_NL[r1 + 1] = rtb_Row2;
  D_NL[r1 + 2] = rtb_Row1;
  rtb_Row1 = -C_NL[5] / C_NL[8];
  rtb_Row2 = (1.0 - C_NL[7] * rtb_Row1) / C_NL[4];
  D_NL[r2] = -(C_NL[3] * rtb_Row2 + C_NL[6] * rtb_Row1) / C_NL[0];
  D_NL[r2 + 1] = rtb_Row2;
  D_NL[r2 + 2] = rtb_Row1;
  rtb_Row1 = 1.0 / C_NL[8];
  rtb_Row2 = -C_NL[7] * rtb_Row1 / C_NL[4];
  D_NL[r3] = -(C_NL[3] * rtb_Row2 + C_NL[6] * rtb_Row1) / C_NL[0];
  D_NL[r3 + 1] = rtb_Row2;
  D_NL[r3 + 2] = rtb_Row1;

  /* End of MATLAB Function: '<S18>/w_d^-2' */

  /* Sum: '<S18>/Sum' */
  tmp_2[0] = ctrl_DP_B.x_ref;
  tmp_2[1] = ctrl_DP_B.y_ref;
  tmp_2[2] = ctrl_DP_B.psi_ref;
  for (r2 = 0; r2 < 3; r2++) {
    /* Product: '<S18>/Matrix Multiply1' incorporates:
     *  Sum: '<S18>/Sum'
     */
    rtb_y_l_0[r2] = 0.0;
    for (r1 = 0; r1 < 3; r1++) {
      /* MATLAB Function: '<S18>/w_d^3' */
      x[r2 + 3 * r1] = 0.0;
      x[r2 + 3 * r1] += rtb_w_d[3 * r1] * rtb_w_d[r2];
      x[r2 + 3 * r1] += rtb_w_d[3 * r1 + 1] * rtb_w_d[r2 + 3];
      x[r2 + 3 * r1] += rtb_w_d[3 * r1 + 2] * rtb_w_d[r2 + 6];

      /* Product: '<S18>/Matrix Multiply1' incorporates:
       *  Integrator: '<S18>/Integrator2'
       *  Sum: '<S18>/Sum'
       */
      rtb_y_l_0[r2] += D_NL[3 * r1 + r2] * ctrl_DP_X.Integrator2_CSTATE_e[r1];
    }
  }

  for (r2 = 0; r2 < 3; r2++) {
    /* MATLAB Function: '<S18>/w_d^3' incorporates:
     *  Product: '<S18>/Matrix Multiply'
     */
    for (r1 = 0; r1 < 3; r1++) {
      C_NL[r2 + 3 * r1] = 0.0;
      C_NL[r2 + 3 * r1] += x[3 * r1] * rtb_w_d[r2];
      C_NL[r2 + 3 * r1] += x[3 * r1 + 1] * rtb_w_d[r2 + 3];
      C_NL[r2 + 3 * r1] += x[3 * r1 + 2] * rtb_w_d[r2 + 6];
    }

    /* Sum: '<S18>/Sum' incorporates:
     *  Product: '<S18>/Matrix Multiply'
     */
    rtb_MatrixMultiply[r2] = tmp_2[r2] - rtb_y_l_0[r2];
  }

  /* Product: '<S18>/Matrix Multiply' */
  for (r2 = 0; r2 < 3; r2++) {
    ctrl_DP_B.MatrixMultiply[r2] = 0.0;
    ctrl_DP_B.MatrixMultiply[r2] += C_NL[r2] * rtb_MatrixMultiply[0];
    ctrl_DP_B.MatrixMultiply[r2] += C_NL[r2 + 3] * rtb_MatrixMultiply[1];
    ctrl_DP_B.MatrixMultiply[r2] += C_NL[r2 + 6] * rtb_MatrixMultiply[2];
  }

  /* SignalConversion: '<S32>/TmpSignal ConversionAt SFunction Inport1' incorporates:
   *  MATLAB Function: '<S26>/diag1'
   */
  /* MATLAB Function 'Guidance/Reference model/w_d*w_d': '<S20>:1' */
  /* '<S20>:1:4' */
  tau[0] = ctrl_DP_B.zeta_x;
  tau[1] = ctrl_DP_B.zeta_y;
  tau[2] = ctrl_DP_B.zeta_psi;

  /* MATLAB Function: '<S26>/diag1' */
  /* MATLAB Function 'Input/Guidance gains/diag1': '<S32>:1' */
  /* '<S32>:1:4' */
  memset(&D_NL[0], 0, 9U * sizeof(real_T));

  /* MATLAB Function 'Guidance/Reference model/w_d*w_d1': '<S21>:1' */
  /* '<S21>:1:4' */
  for (r1 = 0; r1 < 3; r1++) {
    D_NL[r1 + 3 * r1] = tau[r1];

    /* MATLAB Function: '<S18>/w_d*w_d' incorporates:
     *  Product: '<S18>/Matrix Multiply2'
     */
    for (r2 = 0; r2 < 3; r2++) {
      x[r1 + 3 * r2] = 0.0;
      x[r1 + 3 * r2] += rtb_w_d[3 * r2] * rtb_w_d[r1];
      x[r1 + 3 * r2] += rtb_w_d[3 * r2 + 1] * rtb_w_d[r1 + 3];
      x[r1 + 3 * r2] += rtb_w_d[3 * r2 + 2] * rtb_w_d[r1 + 6];
    }

    /* End of MATLAB Function: '<S18>/w_d*w_d' */
  }

  for (r2 = 0; r2 < 3; r2++) {
    /* Sum: '<S18>/Sum2' */
    rtb_Row1_o = 0.0;
    for (r1 = 0; r1 < 3; r1++) {
      /* MATLAB Function: '<S18>/w_d*w_d1' incorporates:
       *  Product: '<S18>/Matrix Multiply5'
       */
      C_NL[r2 + 3 * r1] = 0.0;
      C_NL[r2 + 3 * r1] += 2.0 * D_NL[r2] * rtb_w_d[3 * r1];
      C_NL[r2 + 3 * r1] += D_NL[r2 + 3] * 2.0 * rtb_w_d[3 * r1 + 1];
      C_NL[r2 + 3 * r1] += D_NL[r2 + 6] * 2.0 * rtb_w_d[3 * r1 + 2];

      /* Sum: '<S18>/Sum2' incorporates:
       *  Product: '<S18>/Matrix Multiply2'
       *  Sum: '<S18>/Sum5'
       */
      rtb_Row1_o += x[3 * r1 + r2] * rtb_TmpSignalConversionAtSFu_pa[r1];
    }

    /* Sum: '<S18>/Sum5' incorporates:
     *  Integrator: '<S18>/Integrator2'
     *  Product: '<S18>/Matrix Multiply2'
     *  Product: '<S18>/Matrix Multiply5'
     *  Sum: '<S18>/Sum2'
     */
    ctrl_DP_B.Sum5[r2] = (ctrl_DP_X.Integrator2_CSTATE_e[r2] - rtb_Row1_o) -
      (C_NL[r2 + 6] * ctrl_DP_B.Integrator3[2] + (C_NL[r2 + 3] *
        ctrl_DP_B.Integrator3[1] + C_NL[r2] * ctrl_DP_B.Integrator3[0]));
  }

  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
    /* MATLAB Function: '<S27>/MATLAB Function' incorporates:
     *  Constant: '<S27>/Constant'
     *  Constant: '<S27>/Constant1'
     *  Constant: '<S27>/Constant2'
     */
    ctrl_DP_MATLABFunction(ctrl_DP_P.Constant_Value_k,
      ctrl_DP_P.Constant1_Value_c, ctrl_DP_P.Constant2_Value,
      &ctrl_DP_B.sf_MATLABFunction_l);

    /* MATLAB Function: '<S27>/MATLAB Function1' incorporates:
     *  Constant: '<S27>/Constant3'
     *  Constant: '<S27>/Constant4'
     *  Constant: '<S27>/Constant5'
     */
    ctrl_DP_MATLABFunction1(ctrl_DP_P.Constant3_Value, ctrl_DP_P.Constant4_Value,
      ctrl_DP_P.Constant5_Value, &ctrl_DP_B.sf_MATLABFunction1_c);
  }

  /* Sum: '<S8>/Sum1' incorporates:
   *  Fcn: '<S38>/Fcn'
   *  Fcn: '<S38>/Fcn1'
   *  Fcn: '<S38>/Fcn2'
   */
  rtb_Row2_0[0] = cos(rtb_psi_dot) * ctrl_DP_B.Integrator1_g[0] - sin
    (rtb_psi_dot) * ctrl_DP_B.Integrator1_g[1];
  rtb_Row2_0[1] = sin(rtb_psi_dot) * ctrl_DP_B.Integrator1_g[0] + cos
    (rtb_psi_dot) * ctrl_DP_B.Integrator1_g[1];
  rtb_Row2_0[2] = ctrl_DP_B.Integrator1_g[2];
  for (r2 = 0; r2 < 3; r2++) {
    /* Product: '<S8>/Matrix Multiply1' */
    ctrl_DP_B.MatrixMultiply1[r2] = 0.0;
    ctrl_DP_B.MatrixMultiply1[r2] += ctrl_DP_B.sf_MATLABFunction1_c.K_i[r2] *
      u_idx_0;
    ctrl_DP_B.MatrixMultiply1[r2] += ctrl_DP_B.sf_MATLABFunction1_c.K_i[r2 + 3] *
      u_idx_1;
    ctrl_DP_B.MatrixMultiply1[r2] += ctrl_DP_B.sf_MATLABFunction1_c.K_i[r2 + 6] *
      u_idx_2;

    /* Sum: '<S8>/Sum1' incorporates:
     *  Product: '<S8>/Matrix Multiply'
     */
    ctrl_DP_B.Sum1[r2] = (ctrl_DP_B.sf_MATLABFunction_l.K_p[r2 + 6] * u_idx_2 +
                          (ctrl_DP_B.sf_MATLABFunction_l.K_p[r2 + 3] * u_idx_1 +
      ctrl_DP_B.sf_MATLABFunction_l.K_p[r2] * u_idx_0)) + rtb_Row2_0[r2];
  }

  /* Fcn: '<S24>/Row3' */
  ctrl_DP_B.Row3 = ctrl_DP_B.Integrator3[2];

  /* Fcn: '<S24>/Row1' */
  ctrl_DP_B.Row1 = cos(ctrl_DP_B.Sum_l) * ctrl_DP_B.Integrator3[0] + sin
    (ctrl_DP_B.Sum_l) * ctrl_DP_B.Integrator3[1];

  /* Fcn: '<S24>/Row2' */
  ctrl_DP_B.Row2 = -sin(ctrl_DP_B.Sum_l) * ctrl_DP_B.Integrator3[0] + cos
    (ctrl_DP_B.Sum_l) * ctrl_DP_B.Integrator3[1];
}

/* Model update function */
void ctrl_DP_update(void)
{
  /* Update for Integrator: '<S18>/Integrator1' */
  ctrl_DP_DW.Integrator1_IWORK = 0;
  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
    /* Update for Memory: '<Root>/Memory' */
    memcpy(&ctrl_DP_DW.Memory_PreviousInput[0], &ctrl_DP_B.P[0], 81U * sizeof
           (real_T));

    /* Update for Memory: '<Root>/Memory1' */
    memcpy(&ctrl_DP_DW.Memory1_PreviousInput[0], &ctrl_DP_B.x_p[0], 9U * sizeof
           (real_T));
  }

  /* Update for Integrator: '<S8>/Integrator' */
  ctrl_DP_DW.Integrator_IWORK = 0;
  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
    rt_ertODEUpdateContinuousStates(&ctrl_DP_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++ctrl_DP_M->Timing.clockTick0)) {
    ++ctrl_DP_M->Timing.clockTickH0;
  }

  ctrl_DP_M->Timing.t[0] = rtsiGetSolverStopTime(&ctrl_DP_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++ctrl_DP_M->Timing.clockTick1)) {
      ++ctrl_DP_M->Timing.clockTickH1;
    }

    ctrl_DP_M->Timing.t[1] = ctrl_DP_M->Timing.clockTick1 *
      ctrl_DP_M->Timing.stepSize1 + ctrl_DP_M->Timing.clockTickH1 *
      ctrl_DP_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void ctrl_DP_derivatives(void)
{
  XDot_ctrl_DP_T *_rtXdot;
  _rtXdot = ((XDot_ctrl_DP_T *) ctrl_DP_M->derivs);

  /* Derivatives for Integrator: '<S18>/Integrator1' */
  _rtXdot->Integrator1_CSTATE[0] = ctrl_DP_B.Integrator3[0];

  /* Derivatives for Integrator: '<S13>/Integrator' */
  _rtXdot->Integrator_CSTATE[0] = ctrl_DP_B.TmpSignalConversionAtMatrixMult[0];

  /* Derivatives for Integrator: '<S8>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_g[0] = ctrl_DP_B.M1[0];

  /* Derivatives for Integrator: '<S18>/Integrator3' */
  _rtXdot->Integrator3_CSTATE[0] = ctrl_DP_B.Sum5[0];

  /* Derivatives for Integrator: '<S8>/Integrator' */
  _rtXdot->Integrator_CSTATE_l[0] = ctrl_DP_B.Sum1[0];

  /* Derivatives for Integrator: '<S8>/Integrator2' */
  _rtXdot->Integrator2_CSTATE[0] = ctrl_DP_B.MatrixMultiply1[0];

  /* Derivatives for Integrator: '<S18>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_e[0] = ctrl_DP_B.MatrixMultiply[0];

  /* Derivatives for Integrator: '<S18>/Integrator1' */
  _rtXdot->Integrator1_CSTATE[1] = ctrl_DP_B.Integrator3[1];

  /* Derivatives for Integrator: '<S13>/Integrator' */
  _rtXdot->Integrator_CSTATE[1] = ctrl_DP_B.TmpSignalConversionAtMatrixMult[1];

  /* Derivatives for Integrator: '<S8>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_g[1] = ctrl_DP_B.M1[1];

  /* Derivatives for Integrator: '<S18>/Integrator3' */
  _rtXdot->Integrator3_CSTATE[1] = ctrl_DP_B.Sum5[1];

  /* Derivatives for Integrator: '<S8>/Integrator' */
  _rtXdot->Integrator_CSTATE_l[1] = ctrl_DP_B.Sum1[1];

  /* Derivatives for Integrator: '<S8>/Integrator2' */
  _rtXdot->Integrator2_CSTATE[1] = ctrl_DP_B.MatrixMultiply1[1];

  /* Derivatives for Integrator: '<S18>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_e[1] = ctrl_DP_B.MatrixMultiply[1];

  /* Derivatives for Integrator: '<S18>/Integrator1' */
  _rtXdot->Integrator1_CSTATE[2] = ctrl_DP_B.Integrator3[2];

  /* Derivatives for Integrator: '<S13>/Integrator' */
  _rtXdot->Integrator_CSTATE[2] = ctrl_DP_B.TmpSignalConversionAtMatrixMult[2];

  /* Derivatives for Integrator: '<S8>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_g[2] = ctrl_DP_B.M1[2];

  /* Derivatives for Integrator: '<S18>/Integrator3' */
  _rtXdot->Integrator3_CSTATE[2] = ctrl_DP_B.Sum5[2];

  /* Derivatives for Integrator: '<S8>/Integrator' */
  _rtXdot->Integrator_CSTATE_l[2] = ctrl_DP_B.Sum1[2];

  /* Derivatives for Integrator: '<S8>/Integrator2' */
  _rtXdot->Integrator2_CSTATE[2] = ctrl_DP_B.MatrixMultiply1[2];

  /* Derivatives for Integrator: '<S18>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_e[2] = ctrl_DP_B.MatrixMultiply[2];
}

/* Model initialize function */
void ctrl_DP_initialize(void)
{
  ctrl_DP_PrevZCX.Integrator1_Reset_ZCE = UNINITIALIZED_ZCSIG;
  ctrl_DP_PrevZCX.Integrator_Reset_ZCE = UNINITIALIZED_ZCSIG;
  ctrl_DP_PrevZCX.Integrator1_Reset_ZCE_e = UNINITIALIZED_ZCSIG;
  ctrl_DP_PrevZCX.Integrator3_Reset_ZCE = UNINITIALIZED_ZCSIG;
  ctrl_DP_PrevZCX.Integrator_Reset_ZCE_n = UNINITIALIZED_ZCSIG;
  ctrl_DP_PrevZCX.Integrator2_Reset_ZCE = UNINITIALIZED_ZCSIG;
  ctrl_DP_PrevZCX.Integrator2_Reset_ZCE_m = UNINITIALIZED_ZCSIG;

  /* InitializeConditions for Integrator: '<S18>/Integrator1' incorporates:
   *  InitializeConditions for Integrator: '<S8>/Integrator'
   */
  if (rtmIsFirstInitCond(ctrl_DP_M)) {
    ctrl_DP_X.Integrator1_CSTATE[0] = 0.0;
    ctrl_DP_X.Integrator1_CSTATE[1] = 0.0;
    ctrl_DP_X.Integrator1_CSTATE[2] = 0.0;
    ctrl_DP_X.Integrator_CSTATE_l[0] = 0.0;
    ctrl_DP_X.Integrator_CSTATE_l[1] = 0.0;
    ctrl_DP_X.Integrator_CSTATE_l[2] = 0.0;
  }

  ctrl_DP_DW.Integrator1_IWORK = 1;

  /* End of InitializeConditions for Integrator: '<S18>/Integrator1' */

  /* InitializeConditions for Integrator: '<S13>/Integrator' */
  ctrl_DP_X.Integrator_CSTATE[0] = ctrl_DP_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S8>/Integrator1' */
  ctrl_DP_X.Integrator1_CSTATE_g[0] = ctrl_DP_P.Integrator1_IC[0];

  /* InitializeConditions for Integrator: '<S18>/Integrator3' */
  ctrl_DP_X.Integrator3_CSTATE[0] = ctrl_DP_P.Integrator3_IC;

  /* InitializeConditions for Integrator: '<S13>/Integrator' */
  ctrl_DP_X.Integrator_CSTATE[1] = ctrl_DP_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S8>/Integrator1' */
  ctrl_DP_X.Integrator1_CSTATE_g[1] = ctrl_DP_P.Integrator1_IC[1];

  /* InitializeConditions for Integrator: '<S18>/Integrator3' */
  ctrl_DP_X.Integrator3_CSTATE[1] = ctrl_DP_P.Integrator3_IC;

  /* InitializeConditions for Integrator: '<S13>/Integrator' */
  ctrl_DP_X.Integrator_CSTATE[2] = ctrl_DP_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S8>/Integrator1' */
  ctrl_DP_X.Integrator1_CSTATE_g[2] = ctrl_DP_P.Integrator1_IC[2];

  /* InitializeConditions for Integrator: '<S18>/Integrator3' */
  ctrl_DP_X.Integrator3_CSTATE[2] = ctrl_DP_P.Integrator3_IC;

  /* InitializeConditions for Memory: '<Root>/Memory' */
  memcpy(&ctrl_DP_DW.Memory_PreviousInput[0], &ctrl_DP_P.Memory_X0[0], 81U *
         sizeof(real_T));

  /* InitializeConditions for Memory: '<Root>/Memory1' */
  memcpy(&ctrl_DP_DW.Memory1_PreviousInput[0], &ctrl_DP_P.Memory1_X0[0], 9U *
         sizeof(real_T));

  /* InitializeConditions for Integrator: '<S8>/Integrator' */
  ctrl_DP_DW.Integrator_IWORK = 1;

  /* InitializeConditions for Integrator: '<S8>/Integrator2' */
  ctrl_DP_X.Integrator2_CSTATE[0] = ctrl_DP_P.Integrator2_IC[0];

  /* InitializeConditions for Integrator: '<S18>/Integrator2' */
  ctrl_DP_X.Integrator2_CSTATE_e[0] = ctrl_DP_P.Integrator2_IC_h;

  /* InitializeConditions for Integrator: '<S8>/Integrator2' */
  ctrl_DP_X.Integrator2_CSTATE[1] = ctrl_DP_P.Integrator2_IC[1];

  /* InitializeConditions for Integrator: '<S18>/Integrator2' */
  ctrl_DP_X.Integrator2_CSTATE_e[1] = ctrl_DP_P.Integrator2_IC_h;

  /* InitializeConditions for Integrator: '<S8>/Integrator2' */
  ctrl_DP_X.Integrator2_CSTATE[2] = ctrl_DP_P.Integrator2_IC[2];

  /* InitializeConditions for Integrator: '<S18>/Integrator2' */
  ctrl_DP_X.Integrator2_CSTATE_e[2] = ctrl_DP_P.Integrator2_IC_h;

  /* set "at time zero" to false */
  if (rtmIsFirstInitCond(ctrl_DP_M)) {
    rtmSetFirstInitCond(ctrl_DP_M, 0);
  }
}

/* Model terminate function */
void ctrl_DP_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  ctrl_DP_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  ctrl_DP_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  ctrl_DP_initialize();
}

void MdlTerminate(void)
{
  ctrl_DP_terminate();
}

/* Registration function */
RT_MODEL_ctrl_DP_T *ctrl_DP(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)ctrl_DP_M, 0,
                sizeof(RT_MODEL_ctrl_DP_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&ctrl_DP_M->solverInfo, &ctrl_DP_M->Timing.simTimeStep);
    rtsiSetTPtr(&ctrl_DP_M->solverInfo, &rtmGetTPtr(ctrl_DP_M));
    rtsiSetStepSizePtr(&ctrl_DP_M->solverInfo, &ctrl_DP_M->Timing.stepSize0);
    rtsiSetdXPtr(&ctrl_DP_M->solverInfo, &ctrl_DP_M->derivs);
    rtsiSetContStatesPtr(&ctrl_DP_M->solverInfo, (real_T **)
                         &ctrl_DP_M->contStates);
    rtsiSetNumContStatesPtr(&ctrl_DP_M->solverInfo,
      &ctrl_DP_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&ctrl_DP_M->solverInfo,
      &ctrl_DP_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&ctrl_DP_M->solverInfo,
      &ctrl_DP_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&ctrl_DP_M->solverInfo,
      &ctrl_DP_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&ctrl_DP_M->solverInfo, (&rtmGetErrorStatus(ctrl_DP_M)));
    rtsiSetRTModelPtr(&ctrl_DP_M->solverInfo, ctrl_DP_M);
  }

  rtsiSetSimTimeStep(&ctrl_DP_M->solverInfo, MAJOR_TIME_STEP);
  ctrl_DP_M->intgData.y = ctrl_DP_M->odeY;
  ctrl_DP_M->intgData.f[0] = ctrl_DP_M->odeF[0];
  ctrl_DP_M->intgData.f[1] = ctrl_DP_M->odeF[1];
  ctrl_DP_M->intgData.f[2] = ctrl_DP_M->odeF[2];
  ctrl_DP_M->intgData.f[3] = ctrl_DP_M->odeF[3];
  ctrl_DP_M->contStates = ((real_T *) &ctrl_DP_X);
  rtsiSetSolverData(&ctrl_DP_M->solverInfo, (void *)&ctrl_DP_M->intgData);
  rtsiSetSolverName(&ctrl_DP_M->solverInfo,"ode4");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = ctrl_DP_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    ctrl_DP_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    ctrl_DP_M->Timing.sampleTimes = (&ctrl_DP_M->Timing.sampleTimesArray[0]);
    ctrl_DP_M->Timing.offsetTimes = (&ctrl_DP_M->Timing.offsetTimesArray[0]);

    /* task periods */
    ctrl_DP_M->Timing.sampleTimes[0] = (0.0);
    ctrl_DP_M->Timing.sampleTimes[1] = (0.01);

    /* task offsets */
    ctrl_DP_M->Timing.offsetTimes[0] = (0.0);
    ctrl_DP_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(ctrl_DP_M, &ctrl_DP_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = ctrl_DP_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    ctrl_DP_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(ctrl_DP_M, -1);
  ctrl_DP_M->Timing.stepSize0 = 0.01;
  ctrl_DP_M->Timing.stepSize1 = 0.01;
  rtmSetFirstInitCond(ctrl_DP_M, 1);

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    ctrl_DP_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(ctrl_DP_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(ctrl_DP_M->rtwLogInfo, (NULL));
    rtliSetLogT(ctrl_DP_M->rtwLogInfo, "tout");
    rtliSetLogX(ctrl_DP_M->rtwLogInfo, "");
    rtliSetLogXFinal(ctrl_DP_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(ctrl_DP_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(ctrl_DP_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(ctrl_DP_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(ctrl_DP_M->rtwLogInfo, 1);
    rtliSetLogY(ctrl_DP_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(ctrl_DP_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(ctrl_DP_M->rtwLogInfo, (NULL));
  }

  ctrl_DP_M->solverInfoPtr = (&ctrl_DP_M->solverInfo);
  ctrl_DP_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&ctrl_DP_M->solverInfo, 0.01);
  rtsiSetSolverMode(&ctrl_DP_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  ctrl_DP_M->blockIO = ((void *) &ctrl_DP_B);
  (void) memset(((void *) &ctrl_DP_B), 0,
                sizeof(B_ctrl_DP_T));

  /* parameters */
  ctrl_DP_M->defaultParam = ((real_T *)&ctrl_DP_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &ctrl_DP_X;
    ctrl_DP_M->contStates = (x);
    (void) memset((void *)&ctrl_DP_X, 0,
                  sizeof(X_ctrl_DP_T));
  }

  /* states (dwork) */
  ctrl_DP_M->dwork = ((void *) &ctrl_DP_DW);
  (void) memset((void *)&ctrl_DP_DW, 0,
                sizeof(DW_ctrl_DP_T));

  /* Initialize Sizes */
  ctrl_DP_M->Sizes.numContStates = (21);/* Number of continuous states */
  ctrl_DP_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  ctrl_DP_M->Sizes.numY = (0);         /* Number of model outputs */
  ctrl_DP_M->Sizes.numU = (0);         /* Number of model inputs */
  ctrl_DP_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  ctrl_DP_M->Sizes.numSampTimes = (2); /* Number of sample times */
  ctrl_DP_M->Sizes.numBlocks = (219);  /* Number of blocks */
  ctrl_DP_M->Sizes.numBlockIO = (66);  /* Number of block outputs */
  ctrl_DP_M->Sizes.numBlockPrms = (544);/* Sum of parameter "widths" */
  return ctrl_DP_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/

/*========================================================================*
 * NI VeriStand Model Framework code generation
 *
 * Model : ctrl_DP
 * Model version : 1.53
 * VeriStand Model Framework version : 2017.0.0.143 (2017)
 * Source generated on : Thu Jul 13 11:39:50 2017
 *========================================================================*/

/* This file contains automatically generated code for functions
 * to update the inports and outports of a Simulink/Realtime Workshop
 * model. Calls to these functions should be made before each step is taken
 * (inports, call SetExternalInputs) and after each step is taken
 * (outports, call SetExternalOutputs.)
 */
#ifdef NI_ROOTMODEL_ctrl_DP
#include "ni_modelframework_ex.h"
#include <stddef.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

unsigned char ReadSideDirtyFlag = 0, WriteSideDirtyFlag = 0;

/*========================================================================*
 * Function: NIRT_GetValueByDataType
 *
 * Abstract:
 *		Converting to and from double and datatypes used in the model
 *
 * Output Parameters
 *      ptr : address to the source
 *      subindex : index value if vector
 *      type   : the source's data type
 *      Complex : true if a complex data type
 *
 * Returns:
 *     Return value: 0 if no error
 *========================================================================*/
double NIRT_GetValueByDataType(void* ptr, int32_t subindex, int32_t type,
  int32_t Complex)
{
  switch (type)
  {
   case 0:
    return (double)(((real_T*)ptr)[subindex]);

   case 1:
    return (double)(((real32_T*)ptr)[subindex]);

   case 2:
    return (double)(((int8_T*)ptr)[subindex]);

   case 3:
    return (double)(((uint8_T*)ptr)[subindex]);

   case 4:
    return (double)(((int16_T*)ptr)[subindex]);

   case 5:
    return (double)(((uint16_T*)ptr)[subindex]);

   case 6:
    return (double)(((int32_T*)ptr)[subindex]);

   case 7:
    return (double)(((uint32_T*)ptr)[subindex]);

   case 8:
    return (double)(((boolean_T*)ptr)[subindex]);

   case 10:
    return NIRT_GetValueByDataType(ptr,subindex,6,Complex);

   case 13:
    return NIRT_GetValueByDataType(ptr,subindex,7,Complex);

   case 15:
    return NIRT_GetValueByDataType(ptr,subindex,6,Complex);

   case 16:
    return NIRT_GetValueByDataType(ptr,subindex,6,Complex);

   case 17:
    return NIRT_GetValueByDataType(ptr,subindex,3,Complex);

   case 18:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 19:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 20:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 21:
    return NIRT_GetValueByDataType(ptr,subindex,3,Complex);

   case 22:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 23:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 24:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 25:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 28:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 29:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 30:
    return NIRT_GetValueByDataType(ptr,subindex,8,Complex);

   case 31:
    return (( double *)ptr)[subindex];

   case 32:
    return (( double *)ptr)[subindex];

   case 33:
    return (( double *)ptr)[subindex];

   case 34:
    return (( double *)ptr)[subindex];

   case 35:
    return (( double *)ptr)[subindex];

   case 36:
    return (( double *)ptr)[subindex];

   case 37:
    return (( double *)ptr)[subindex];

   case 38:
    return (( double *)ptr)[subindex];

   case 39:
    return (( double *)ptr)[subindex];

   case 40:
    return (( double *)ptr)[subindex];

   case 41:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 42:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);
  }

  // return ((double *)ptr)[subindex];
  return rtNaN;
}

/*========================================================================*
 * Function: NIRT_SetValueByDataType
 *
 * Abstract:
 *		Converting to and from double and datatypes used in the model
 *
 * Output Parameters
 *      ptr : address to the destination
 *      subindex : index value if vector
 *      value : value to set on the destination
 *      type   : the destination's data type
 *      Complex : true if a complex data type
 *
 * Returns:
 *     Return value: 0 if no error
 *========================================================================*/
int32_t NIRT_SetValueByDataType(void* ptr, int32_t subindex, double value,
  int32_t type, int32_t Complex)
{
  //Complex is only used for R14.3 and down
  switch (type)
  {
   case 0:
    ((real_T *)ptr)[subindex] = (real_T)value;
    return NI_OK;

   case 1:
    ((real32_T *)ptr)[subindex] = (real32_T)value;
    return NI_OK;

   case 2:
    ((int8_T *)ptr)[subindex] = (int8_T)value;
    return NI_OK;

   case 3:
    ((uint8_T *)ptr)[subindex] = (uint8_T)value;
    return NI_OK;

   case 4:
    ((int16_T *)ptr)[subindex] = (int16_T)value;
    return NI_OK;

   case 5:
    ((uint16_T *)ptr)[subindex] = (uint16_T)value;
    return NI_OK;

   case 6:
    ((int32_T *)ptr)[subindex] = (int32_T)value;
    return NI_OK;

   case 7:
    ((uint32_T *)ptr)[subindex] = (uint32_T)value;
    return NI_OK;

   case 8:
    ((boolean_T *)ptr)[subindex] = (boolean_T)value;
    return NI_OK;

   case 10:
    //Type is renamed. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 6, Complex);

   case 13:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 7, Complex);

   case 15:
    //Type is enum. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 6, Complex);

   case 16:
    //Type is enum. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 6, Complex);

   case 17:
    //Type is renamed. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 3, Complex);

   case 18:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 19:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 20:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 21:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 3, Complex);

   case 22:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 23:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 24:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 25:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 28:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 29:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 30:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 8, Complex);

   case 31:
    //Type is struct. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 32:
    //Type is struct. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 33:
    //Type is struct. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 34:
    //Type is struct. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 35:
    //Type is struct. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 36:
    //Type is struct. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 37:
    //Type is struct. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 38:
    //Type is struct. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 39:
    //Type is struct. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 40:
    //Type is struct. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 41:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 42:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);
  }

  //No matching datatype conversion
  return NI_ERROR;
}

extern ctrl_DP_rtModel *S;
extern _SITexportglobals SITexportglobals;

/*========================================================================*
 * Function: SetExternalInputs
 *
 * Abstract:
 *		Set data to model ports on the specified task
 *
 * Input Parameters
 *      data : data to set
 *      TaskSampleHit : task id
 *
 * Returns:
 *     Return value: 0 if no error
 *========================================================================*/
void SetExternalInputs(double* data, int_T* TaskSampleHit)
{
  int index = 0, count = 0;

  // ctrl_DP/Input/Control Gains/K_p_x
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.K_p_x, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Input/Control Gains/K_p_y
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.K_p_y, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Input/Control Gains/K_p_psi
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.K_p_psi, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Input/Control Gains/K_i_psi
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.K_i_psi, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Input/Control Gains/K_i_x
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.K_i_x, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Input/Control Gains/K_i_y
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.K_i_y, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Input/Control Gains/K_d_psi
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.K_d_psi, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Input/Control Gains/K_d_x
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.K_d_x, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Input/Control Gains/K_d_y
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.K_d_y, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/POSE/x
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.x, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/POSE/y
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.y, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/POSE/psi
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.psi, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Input/reset
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.reset, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Input/Guidance gains/w_d_x
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.w_d_x, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Input/Guidance gains/w_d_y
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.w_d_y, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Input/Guidance gains/w_d_psi
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.w_d_psi, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Input/Guidance gains/zeta_psi
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.zeta_psi, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Input/Guidance gains/zeta_x
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.zeta_x, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Input/Guidance gains/zeta_y
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.zeta_y, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Input/psi_ref
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.psi_ref, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Input/x_ref
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.x_ref, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Input/y_ref
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.y_ref, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/z_m
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.z_m, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/IMU/Acc_x
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.Acc_x, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/IMU/Acc_y
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.Acc_y, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/IMU/Acc_z
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.Acc_z, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/IMU/Gyro_x
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.Gyro_x, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/IMU/Gyro_y
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.Gyro_y, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/IMU/Gyro_z
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.Gyro_z, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  UNUSED_PARAMETER(count);
}                                      /* of SetExternalInputs */

int32_t NumInputPorts(void)
{
  return 29;
}

int32_t NumOutputPorts(void)
{
  return 37;
}

double ni_extout[37];

/*========================================================================*
 * Function: SetExternalOutputs
 *
 * Abstract:
 *		Set data to model ports on the specified task
 *
 * Input Parameters
 *      data : data to set
 *      TaskSampleHit : task id
 *
 * Returns:
 *     Return value: 0 if no error
 *========================================================================*/
void SetExternalOutputs(double* data, int_T* TaskSampleHit)
{
  int index = 0, count = 0;

  // ctrl_DP/alpha_VSP2: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.alpha_VSP, 0, 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/omega_VSP1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.omega_VSP, 0, 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/omega_VSP2: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.omega_VSP, 0, 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/alpha_VSP1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.alpha_VSP, 0, 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/u_BT: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.u_BT, 0, 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/u_VSP1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.u_VSP, 0, 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/u_VSP2: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.u_VSP, 0, 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/x_est: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.pos_est, 0, 18, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/y_est: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.pos_est, 1, 18, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Observer output /eta_hat output/x_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Integrator, 0, 18, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Observer output /eta_hat output/y_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Integrator, 1, 18, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Observer output /eta_hat output/psi_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Sum_f, 0, 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Observer output /nu_hat output/u_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Integrator1_g, 0, 18,
      0);
  } else {
    index += 1;
  }

  // ctrl_DP/Observer output /nu_hat output/v_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Integrator1_g, 1, 18,
      0);
  } else {
    index += 1;
  }

  // ctrl_DP/Observer output /nu_hat output/r_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Integrator1_g, 2, 18,
      0);
  } else {
    index += 1;
  }

  // ctrl_DP/Observer output /nu_dot_hat output/u_dot_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.M1, 0, 18, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Observer output /nu_dot_hat output/v_dot_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.M1, 1, 18, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Observer output /nu_dot_hat output/r_dot_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.M1, 2, 18, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Observer output /b_hat output/b_x_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Integrator2, 0, 18,
      0);
  } else {
    index += 1;
  }

  // ctrl_DP/Observer output /b_hat output/b_y_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Integrator2, 1, 18,
      0);
  } else {
    index += 1;
  }

  // ctrl_DP/Observer output /b_hat output/b_psi_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Integrator2, 2, 18,
      0);
  } else {
    index += 1;
  }

  // ctrl_DP/z_est: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.pos_est, 2, 18, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Control output/tau_N: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Sum3, 2, 18, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Control output/tau_X: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Sum3, 0, 18, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Control output/tau_Y: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Sum3, 1, 18, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Control output/psi_tilde: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.regulationerror, 2,
      18, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Control output/x_tilde: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.regulationerror, 0,
      18, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Control output/y_tidle: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.regulationerror, 1,
      18, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Control output/r_tilde: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Sum4, 2, 18, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Control output/u_tilde: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Sum4, 0, 18, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Control output/v_tilde: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Sum4, 1, 18, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Guidance output/x_d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Integrator1, 0, 18,
      0);
  } else {
    index += 1;
  }

  // ctrl_DP/Guidance output/y_d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Integrator1, 1, 18,
      0);
  } else {
    index += 1;
  }

  // ctrl_DP/Guidance output/psi_d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Sum_l, 0, 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Guidance output/r_d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Row3, 0, 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Guidance output/u_d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Row1, 0, 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Guidance output/v_d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Row2, 0, 0, 0);
  } else {
    index += 1;
  }

  if (data != NULL) {
    memcpy(&data[0], &ni_extout[0], sizeof(ni_extout));
  }

  UNUSED_PARAMETER(count);
}

/*========================================================================*
 * Function: NI_InitExternalOutputs
 *
 * Abstract:
 *		Initialize model ports
 *
 * Output Parameters
 *
 * Returns:
 *     Return value: 0 if no error
 *========================================================================*/
int32_t NI_InitExternalOutputs()
{
  int index = 0, count = 0;

  // ctrl_DP/alpha_VSP2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.alpha_VSP, 0, 0, 0);

  // ctrl_DP/omega_VSP1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.omega_VSP, 0, 0, 0);

  // ctrl_DP/omega_VSP2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.omega_VSP, 0, 0, 0);

  // ctrl_DP/alpha_VSP1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.alpha_VSP, 0, 0, 0);

  // ctrl_DP/u_BT: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.u_BT, 0, 0, 0);

  // ctrl_DP/u_VSP1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.u_VSP, 0, 0, 0);

  // ctrl_DP/u_VSP2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.u_VSP, 0, 0, 0);

  // ctrl_DP/x_est: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.pos_est, 0, 18, 0);

  // ctrl_DP/y_est: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.pos_est, 1, 18, 0);

  // ctrl_DP/Observer output /eta_hat output/x_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Integrator, 0, 18, 0);

  // ctrl_DP/Observer output /eta_hat output/y_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Integrator, 1, 18, 0);

  // ctrl_DP/Observer output /eta_hat output/psi_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Sum_f, 0, 0, 0);

  // ctrl_DP/Observer output /nu_hat output/u_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Integrator1_g, 0, 18,
    0);

  // ctrl_DP/Observer output /nu_hat output/v_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Integrator1_g, 1, 18,
    0);

  // ctrl_DP/Observer output /nu_hat output/r_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Integrator1_g, 2, 18,
    0);

  // ctrl_DP/Observer output /nu_dot_hat output/u_dot_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.M1, 0, 18, 0);

  // ctrl_DP/Observer output /nu_dot_hat output/v_dot_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.M1, 1, 18, 0);

  // ctrl_DP/Observer output /nu_dot_hat output/r_dot_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.M1, 2, 18, 0);

  // ctrl_DP/Observer output /b_hat output/b_x_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Integrator2, 0, 18, 0);

  // ctrl_DP/Observer output /b_hat output/b_y_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Integrator2, 1, 18, 0);

  // ctrl_DP/Observer output /b_hat output/b_psi_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Integrator2, 2, 18, 0);

  // ctrl_DP/z_est: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.pos_est, 2, 18, 0);

  // ctrl_DP/Control output/tau_N: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Sum3, 2, 18, 0);

  // ctrl_DP/Control output/tau_X: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Sum3, 0, 18, 0);

  // ctrl_DP/Control output/tau_Y: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Sum3, 1, 18, 0);

  // ctrl_DP/Control output/psi_tilde: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.regulationerror, 2, 18,
    0);

  // ctrl_DP/Control output/x_tilde: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.regulationerror, 0, 18,
    0);

  // ctrl_DP/Control output/y_tidle: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.regulationerror, 1, 18,
    0);

  // ctrl_DP/Control output/r_tilde: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Sum4, 2, 18, 0);

  // ctrl_DP/Control output/u_tilde: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Sum4, 0, 18, 0);

  // ctrl_DP/Control output/v_tilde: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Sum4, 1, 18, 0);

  // ctrl_DP/Guidance output/x_d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Integrator1, 0, 18, 0);

  // ctrl_DP/Guidance output/y_d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Integrator1, 1, 18, 0);

  // ctrl_DP/Guidance output/psi_d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Sum_l, 0, 0, 0);

  // ctrl_DP/Guidance output/r_d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Row3, 0, 0, 0);

  // ctrl_DP/Guidance output/u_d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Row1, 0, 0, 0);

  // ctrl_DP/Guidance output/v_d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Row2, 0, 0, 0);
  UNUSED_PARAMETER(count);
  return NI_OK;
}

/* Undefine parameter macros. The undef allows us to access the real declarations.
   In the Simulink(R) generated code, the parameters are redefined to be the read-side of rtParameter.*/
#define _NI_UNDEFINE_PARAMS_DBL_BUFFER_
#include "ni_pglobals.h"

/* All elements by default (including scalars) have 2 dimensions [1,1] */
static NI_Parameter NI_ParamList[] DataSection(".NIVS.paramlist") =
{
  { 0, "ctrl_dp/POSE/mm2m/Gain", offsetof(P_ctrl_DP_T, mm2m_Gain), 41, 1, 2, 0,
    0 },

  { 1, "ctrl_dp/POSE/mm2m/Gain", offsetof(P_ctrl_DP_T, mm2m_Gain_i), 41, 1, 2, 2,
    0 },

  { 2, "ctrl_dp/POSE/Gain5/Gain", offsetof(P_ctrl_DP_T, Gain5_Gain), 41, 1, 2, 4,
    0 },

  { 3, "ctrl_dp/POSE/Saturation/UpperLimit", offsetof(P_ctrl_DP_T,
    Saturation_UpperSat), 41, 1, 2, 6, 0 },

  { 4, "ctrl_dp/POSE/Saturation/LowerLimit", offsetof(P_ctrl_DP_T,
    Saturation_LowerSat), 41, 1, 2, 8, 0 },

  { 5, "ctrl_dp/POSE/Gain6/Gain", offsetof(P_ctrl_DP_T, Gain6_Gain), 41, 1, 2,
    10, 0 },

  { 6, "ctrl_dp/POSE/Constant1/Value", offsetof(P_ctrl_DP_T, Constant1_Value),
    41, 1, 2, 12, 0 },

  { 7,
    "ctrl_dp/Control/DP Controller/[-inf inf] to [-pi pi]1/Saturation/UpperLimit",
    offsetof(P_ctrl_DP_T, Saturation_UpperSat_n), 41, 1, 2, 14, 0 },

  { 8,
    "ctrl_dp/Control/DP Controller/[-inf inf] to [-pi pi]1/Saturation/LowerLimit",
    offsetof(P_ctrl_DP_T, Saturation_LowerSat_d), 41, 1, 2, 16, 0 },

  { 9, "ctrl_dp/Control/DP Controller/[-inf inf] to [-pi pi]1/Gain/Gain",
    offsetof(P_ctrl_DP_T, Gain_Gain), 41, 1, 2, 18, 0 },

  { 10, "ctrl_dp/Control/DP Controller/[-inf inf] to [-pi pi]1/Constant/Value",
    offsetof(P_ctrl_DP_T, Constant_Value), 41, 1, 2, 20, 0 },

  { 11, "ctrl_dp/Input/Observer Gains/Constant6/Value", offsetof(P_ctrl_DP_T,
    Constant6_Value), 41, 1, 2, 22, 0 },

  { 12, "ctrl_dp/Input/Observer Gains/Constant7/Value", offsetof(P_ctrl_DP_T,
    Constant7_Value), 41, 1, 2, 24, 0 },

  { 13, "ctrl_dp/Input/Observer Gains/Constant8/Value", offsetof(P_ctrl_DP_T,
    Constant8_Value), 41, 1, 2, 26, 0 },

  { 14,
    "ctrl_dp/Guidance/Reference model/[-inf inf] to [-pi pi]1/Saturation/UpperLimit",
    offsetof(P_ctrl_DP_T, Saturation_UpperSat_j), 41, 1, 2, 28, 0 },

  { 15,
    "ctrl_dp/Guidance/Reference model/[-inf inf] to [-pi pi]1/Saturation/LowerLimit",
    offsetof(P_ctrl_DP_T, Saturation_LowerSat_c), 41, 1, 2, 30, 0 },

  { 16, "ctrl_dp/Guidance/Reference model/[-inf inf] to [-pi pi]1/Gain/Gain",
    offsetof(P_ctrl_DP_T, Gain_Gain_j), 41, 1, 2, 32, 0 },

  { 17,
    "ctrl_dp/Guidance/Reference model/[-inf inf] to [-pi pi]1/Constant/Value",
    offsetof(P_ctrl_DP_T, Constant_Value_f), 41, 1, 2, 34, 0 },

  { 18,
    "ctrl_dp/Control/DP Controller/[-inf inf] to [-pi pi]/Saturation/UpperLimit",
    offsetof(P_ctrl_DP_T, Saturation_UpperSat_a), 41, 1, 2, 36, 0 },

  { 19,
    "ctrl_dp/Control/DP Controller/[-inf inf] to [-pi pi]/Saturation/LowerLimit",
    offsetof(P_ctrl_DP_T, Saturation_LowerSat_dy), 41, 1, 2, 38, 0 },

  { 20, "ctrl_dp/Control/DP Controller/[-inf inf] to [-pi pi]/Gain/Gain",
    offsetof(P_ctrl_DP_T, Gain_Gain_g), 41, 1, 2, 40, 0 },

  { 21, "ctrl_dp/Control/DP Controller/[-inf inf] to [-pi pi]/Constant/Value",
    offsetof(P_ctrl_DP_T, Constant_Value_p), 41, 1, 2, 42, 0 },

  { 22, "ctrl_dp/Control/DP Controller/Integrator/InitialCondition", offsetof
    (P_ctrl_DP_T, Integrator_IC), 41, 1, 2, 44, 0 },

  { 23, "ctrl_dp/Nonlinear Passisve Observer/Integrator1/InitialCondition",
    offsetof(P_ctrl_DP_T, Integrator1_IC), 28, 3, 2, 46, 0 },

  { 24, "ctrl_dp/Guidance/Reference model/Integrator3/InitialCondition",
    offsetof(P_ctrl_DP_T, Integrator3_IC), 41, 1, 2, 48, 0 },

  { 25, "ctrl_dp/Constant/Value", offsetof(P_ctrl_DP_T, Constant_Value_l), 41, 1,
    2, 50, 0 },

  { 26, "ctrl_dp/IMU/Gain/Gain", offsetof(P_ctrl_DP_T, Gain_Gain_c), 41, 1, 2,
    52, 0 },

  { 27, "ctrl_dp/IMU/Gain1/Gain", offsetof(P_ctrl_DP_T, Gain1_Gain), 41, 1, 2,
    54, 0 },

  { 28, "ctrl_dp/IMU/Gain2/Gain", offsetof(P_ctrl_DP_T, Gain2_Gain), 41, 1, 2,
    56, 0 },

  { 29, "ctrl_dp/Memory/X0", offsetof(P_ctrl_DP_T, Memory_X0), 23, 81, 2, 58, 0
  },

  { 30, "ctrl_dp/Memory1/X0", offsetof(P_ctrl_DP_T, Memory1_X0), 29, 9, 2, 60, 0
  },

  { 31,
    "ctrl_dp/Nonlinear Passisve Observer/[-inf inf] to [-pi pi]/Saturation/UpperLimit",
    offsetof(P_ctrl_DP_T, Saturation_UpperSat_l), 41, 1, 2, 62, 0 },

  { 32,
    "ctrl_dp/Nonlinear Passisve Observer/[-inf inf] to [-pi pi]/Saturation/LowerLimit",
    offsetof(P_ctrl_DP_T, Saturation_LowerSat_cz), 41, 1, 2, 64, 0 },

  { 33, "ctrl_dp/Nonlinear Passisve Observer/[-inf inf] to [-pi pi]/Gain/Gain",
    offsetof(P_ctrl_DP_T, Gain_Gain_d), 41, 1, 2, 66, 0 },

  { 34,
    "ctrl_dp/Nonlinear Passisve Observer/[-inf inf] to [-pi pi]/Constant/Value",
    offsetof(P_ctrl_DP_T, Constant_Value_p4), 41, 1, 2, 68, 0 },

  { 35,
    "ctrl_dp/Nonlinear Passisve Observer/[-inf inf] to [-pi pi]1/Saturation/UpperLimit",
    offsetof(P_ctrl_DP_T, Saturation_UpperSat_o), 41, 1, 2, 70, 0 },

  { 36,
    "ctrl_dp/Nonlinear Passisve Observer/[-inf inf] to [-pi pi]1/Saturation/LowerLimit",
    offsetof(P_ctrl_DP_T, Saturation_LowerSat_j), 41, 1, 2, 72, 0 },

  { 37, "ctrl_dp/Nonlinear Passisve Observer/[-inf inf] to [-pi pi]1/Gain/Gain",
    offsetof(P_ctrl_DP_T, Gain_Gain_h), 41, 1, 2, 74, 0 },

  { 38,
    "ctrl_dp/Nonlinear Passisve Observer/[-inf inf] to [-pi pi]1/Constant/Value",
    offsetof(P_ctrl_DP_T, Constant_Value_i), 41, 1, 2, 76, 0 },

  { 39, "ctrl_dp/Nonlinear Passisve Observer/Integrator2/InitialCondition",
    offsetof(P_ctrl_DP_T, Integrator2_IC), 28, 3, 2, 78, 0 },

  { 40, "ctrl_dp/Nonlinear Passisve Observer/M^-1/Gain", offsetof(P_ctrl_DP_T,
    M1_Gain), 19, 9, 2, 80, 0 },

  { 41, "ctrl_dp/Guidance/Reference model/Integrator2/InitialCondition",
    offsetof(P_ctrl_DP_T, Integrator2_IC_h), 41, 1, 2, 82, 0 },

  { 42, "ctrl_dp/Input/Observer Gains/Constant/Value", offsetof(P_ctrl_DP_T,
    Constant_Value_k), 41, 1, 2, 84, 0 },

  { 43, "ctrl_dp/Input/Observer Gains/Constant1/Value", offsetof(P_ctrl_DP_T,
    Constant1_Value_c), 41, 1, 2, 86, 0 },

  { 44, "ctrl_dp/Input/Observer Gains/Constant2/Value", offsetof(P_ctrl_DP_T,
    Constant2_Value), 41, 1, 2, 88, 0 },

  { 45, "ctrl_dp/Input/Observer Gains/Constant3/Value", offsetof(P_ctrl_DP_T,
    Constant3_Value), 41, 1, 2, 90, 0 },

  { 46, "ctrl_dp/Input/Observer Gains/Constant4/Value", offsetof(P_ctrl_DP_T,
    Constant4_Value), 41, 1, 2, 92, 0 },

  { 47, "ctrl_dp/Input/Observer Gains/Constant5/Value", offsetof(P_ctrl_DP_T,
    Constant5_Value), 41, 1, 2, 94, 0 },
};

static int32_t NI_ParamListSize DataSection(".NIVS.paramlistsize") = 48;
static int32_t NI_ParamDimList[] DataSection(".NIVS.paramdimlist") =
{
  1, 1,                                /* Parameter at index 0 */
  1, 1,                                /* Parameter at index 1 */
  1, 1,                                /* Parameter at index 2 */
  1, 1,                                /* Parameter at index 3 */
  1, 1,                                /* Parameter at index 4 */
  1, 1,                                /* Parameter at index 5 */
  1, 1,                                /* Parameter at index 6 */
  1, 1,                                /* Parameter at index 7 */
  1, 1,                                /* Parameter at index 8 */
  1, 1,                                /* Parameter at index 9 */
  1, 1,                                /* Parameter at index 10 */
  1, 1,                                /* Parameter at index 11 */
  1, 1,                                /* Parameter at index 12 */
  1, 1,                                /* Parameter at index 13 */
  1, 1,                                /* Parameter at index 14 */
  1, 1,                                /* Parameter at index 15 */
  1, 1,                                /* Parameter at index 16 */
  1, 1,                                /* Parameter at index 17 */
  1, 1,                                /* Parameter at index 18 */
  1, 1,                                /* Parameter at index 19 */
  1, 1,                                /* Parameter at index 20 */
  1, 1,                                /* Parameter at index 21 */
  1, 1,                                /* Parameter at index 22 */
  3, 1,                                /* Parameter at index 23 */
  1, 1,                                /* Parameter at index 24 */
  1, 1,                                /* Parameter at index 25 */
  1, 1,                                /* Parameter at index 26 */
  1, 1,                                /* Parameter at index 27 */
  1, 1,                                /* Parameter at index 28 */
  9, 9,                                /* Parameter at index 29 */
  9, 1,                                /* Parameter at index 30 */
  1, 1,                                /* Parameter at index 31 */
  1, 1,                                /* Parameter at index 32 */
  1, 1,                                /* Parameter at index 33 */
  1, 1,                                /* Parameter at index 34 */
  1, 1,                                /* Parameter at index 35 */
  1, 1,                                /* Parameter at index 36 */
  1, 1,                                /* Parameter at index 37 */
  1, 1,                                /* Parameter at index 38 */
  3, 1,                                /* Parameter at index 39 */
  3, 3,                                /* Parameter at index 40 */
  1, 1,                                /* Parameter at index 41 */
  1, 1,                                /* Parameter at index 42 */
  1, 1,                                /* Parameter at index 43 */
  1, 1,                                /* Parameter at index 44 */
  1, 1,                                /* Parameter at index 45 */
  1, 1,                                /* Parameter at index 46 */
  1, 1,                                /* Parameter at index 47 */
};

static NI_Signal NI_SigList[] DataSection(".NIVS.siglist") =
{
  { 0, "ctrl_dp/Input/Control Gains/K_p_x", 0, "", offsetof(B_ctrl_DP_T, K_p_x)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 1, "ctrl_dp/Input/Control Gains/K_p_y", 0, "", offsetof(B_ctrl_DP_T, K_p_y)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 2, "ctrl_dp/Input/Control Gains/K_p_psi", 0, "", offsetof(B_ctrl_DP_T,
    K_p_psi) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 3, "ctrl_dp/Input/Control Gains/K_i_psi", 0, "", offsetof(B_ctrl_DP_T,
    K_i_psi) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 4, "ctrl_dp/Input/Control Gains/K_i_x", 0, "", offsetof(B_ctrl_DP_T, K_i_x)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 5, "ctrl_dp/Input/Control Gains/K_i_y", 0, "", offsetof(B_ctrl_DP_T, K_i_y)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 6, "ctrl_dp/Input/Control Gains/K_d_psi", 0, "", offsetof(B_ctrl_DP_T,
    K_d_psi) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 7, "ctrl_dp/Input/Control Gains/K_d_x", 0, "", offsetof(B_ctrl_DP_T, K_d_x)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 8, "ctrl_dp/Input/Control Gains/K_d_y", 0, "", offsetof(B_ctrl_DP_T, K_d_y)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 9, "ctrl_dp/POSE/x", 0, "", offsetof(B_ctrl_DP_T, x) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 10, "ctrl_dp/POSE/mm2m", 0, "", offsetof(B_ctrl_DP_T, mm2m) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 11, "ctrl_dp/POSE/y", 0, "", offsetof(B_ctrl_DP_T, y) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 12, "ctrl_dp/POSE/mm2m", 0, "", offsetof(B_ctrl_DP_T, mm2m_e) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 13, "ctrl_dp/POSE/psi", 0, "", offsetof(B_ctrl_DP_T, psi) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 14, "ctrl_dp/POSE/Sum", 0, "", offsetof(B_ctrl_DP_T, Sum) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 15, "ctrl_dp/Input/reset", 0, "", offsetof(B_ctrl_DP_T, reset) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 16, "ctrl_dp/Input/Guidance gains/w_d_x", 0, "", offsetof(B_ctrl_DP_T, w_d_x)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 17, "ctrl_dp/Input/Guidance gains/w_d_y", 0, "", offsetof(B_ctrl_DP_T, w_d_y)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 18, "ctrl_dp/Input/Guidance gains/w_d_psi", 0, "", offsetof(B_ctrl_DP_T,
    w_d_psi) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 19, "ctrl_dp/Input/Guidance gains/zeta_psi", 0, "", offsetof(B_ctrl_DP_T,
    zeta_psi) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 20, "ctrl_dp/Input/Guidance gains/zeta_x", 0, "", offsetof(B_ctrl_DP_T,
    zeta_x) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 21, "ctrl_dp/Input/Guidance gains/zeta_y", 0, "", offsetof(B_ctrl_DP_T,
    zeta_y) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 22, "ctrl_dp/Input/psi_ref", 0, "", offsetof(B_ctrl_DP_T, psi_ref) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 23, "ctrl_dp/Input/x_ref", 0, "", offsetof(B_ctrl_DP_T, x_ref) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 24, "ctrl_dp/Input/y_ref", 0, "", offsetof(B_ctrl_DP_T, y_ref) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 25, "ctrl_dp/Guidance/Reference model/Integrator1/(1, 1)", 0, "", offsetof
    (B_ctrl_DP_T, Integrator1) + (0*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0
  },

  { 26, "ctrl_dp/Guidance/Reference model/Integrator1/(1, 2)", 0, "", offsetof
    (B_ctrl_DP_T, Integrator1) + (1*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0
  },

  { 27, "ctrl_dp/Guidance/Reference model/Integrator1/(1, 3)", 0, "", offsetof
    (B_ctrl_DP_T, Integrator1) + (2*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0
  },

  { 28, "ctrl_dp/Guidance/Reference model/[-inf inf] to [-pi pi]1/Sum", 0, "",
    offsetof(B_ctrl_DP_T, Sum_l) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 29, "ctrl_dp/Control/DP Controller/Sum2", 0, "regulation error(1, 1)",
    offsetof(B_ctrl_DP_T, regulationerror) + (0*sizeof(real_T)), BLOCKIO_SIG, 18,
    1, 2, 0, 0 },

  { 30, "ctrl_dp/Control/DP Controller/Sum2", 0, "regulation error(1, 2)",
    offsetof(B_ctrl_DP_T, regulationerror) + (1*sizeof(real_T)), BLOCKIO_SIG, 18,
    1, 2, 0, 0 },

  { 31, "ctrl_dp/Control/DP Controller/Sum2", 0, "regulation error(1, 3)",
    offsetof(B_ctrl_DP_T, regulationerror) + (2*sizeof(real_T)), BLOCKIO_SIG, 18,
    1, 2, 0, 0 },

  { 32, "ctrl_dp/Nonlinear Passisve Observer/Integrator1/(1, 1)", 0, "",
    offsetof(B_ctrl_DP_T, Integrator1_g) + (0*sizeof(real_T)), BLOCKIO_SIG, 18,
    1, 2, 0, 0 },

  { 33, "ctrl_dp/Nonlinear Passisve Observer/Integrator1/(1, 2)", 0, "",
    offsetof(B_ctrl_DP_T, Integrator1_g) + (1*sizeof(real_T)), BLOCKIO_SIG, 18,
    1, 2, 0, 0 },

  { 34, "ctrl_dp/Nonlinear Passisve Observer/Integrator1/(1, 3)", 0, "",
    offsetof(B_ctrl_DP_T, Integrator1_g) + (2*sizeof(real_T)), BLOCKIO_SIG, 18,
    1, 2, 0, 0 },

  { 35, "ctrl_dp/Guidance/Reference model/Integrator3/(1, 1)", 0, "", offsetof
    (B_ctrl_DP_T, Integrator3) + (0*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0
  },

  { 36, "ctrl_dp/Guidance/Reference model/Integrator3/(1, 2)", 0, "", offsetof
    (B_ctrl_DP_T, Integrator3) + (1*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0
  },

  { 37, "ctrl_dp/Guidance/Reference model/Integrator3/(1, 3)", 0, "", offsetof
    (B_ctrl_DP_T, Integrator3) + (2*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0
  },

  { 38, "ctrl_dp/Control/DP Controller/Sum4/(1, 1)", 0, "", offsetof(B_ctrl_DP_T,
    Sum4) + (0*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 39, "ctrl_dp/Control/DP Controller/Sum4/(1, 2)", 0, "", offsetof(B_ctrl_DP_T,
    Sum4) + (1*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 40, "ctrl_dp/Control/DP Controller/Sum4/(1, 3)", 0, "", offsetof(B_ctrl_DP_T,
    Sum4) + (2*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 41, "ctrl_dp/Control/DP Controller/Sum3/(1, 1)", 0, "", offsetof(B_ctrl_DP_T,
    Sum3) + (0*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 42, "ctrl_dp/Control/DP Controller/Sum3/(1, 2)", 0, "", offsetof(B_ctrl_DP_T,
    Sum3) + (1*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 43, "ctrl_dp/Control/DP Controller/Sum3/(1, 3)", 0, "", offsetof(B_ctrl_DP_T,
    Sum3) + (2*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 44, "ctrl_dp/z_m", 0, "", offsetof(B_ctrl_DP_T, z_m) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 45, "ctrl_dp/IMU/Acc_x", 0, "", offsetof(B_ctrl_DP_T, Acc_x) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 46, "ctrl_dp/IMU/Acc_y", 0, "", offsetof(B_ctrl_DP_T, Acc_y) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 47, "ctrl_dp/IMU/Acc_z", 0, "", offsetof(B_ctrl_DP_T, Acc_z) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 48, "ctrl_dp/Memory/(1, 1)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 49, "ctrl_dp/Memory/(2, 1)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (1*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 50, "ctrl_dp/Memory/(3, 1)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (2*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 51, "ctrl_dp/Memory/(4, 1)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (3*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 52, "ctrl_dp/Memory/(5, 1)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (4*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 53, "ctrl_dp/Memory/(6, 1)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (5*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 54, "ctrl_dp/Memory/(7, 1)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (6*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 55, "ctrl_dp/Memory/(8, 1)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (7*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 56, "ctrl_dp/Memory/(9, 1)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (8*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 57, "ctrl_dp/Memory/(1, 2)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (9*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 58, "ctrl_dp/Memory/(2, 2)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (10*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 59, "ctrl_dp/Memory/(3, 2)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (11*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 60, "ctrl_dp/Memory/(4, 2)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (12*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 61, "ctrl_dp/Memory/(5, 2)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (13*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 62, "ctrl_dp/Memory/(6, 2)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (14*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 63, "ctrl_dp/Memory/(7, 2)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (15*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 64, "ctrl_dp/Memory/(8, 2)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (16*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 65, "ctrl_dp/Memory/(9, 2)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (17*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 66, "ctrl_dp/Memory/(1, 3)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (18*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 67, "ctrl_dp/Memory/(2, 3)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (19*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 68, "ctrl_dp/Memory/(3, 3)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (20*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 69, "ctrl_dp/Memory/(4, 3)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (21*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 70, "ctrl_dp/Memory/(5, 3)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (22*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 71, "ctrl_dp/Memory/(6, 3)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (23*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 72, "ctrl_dp/Memory/(7, 3)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (24*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 73, "ctrl_dp/Memory/(8, 3)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (25*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 74, "ctrl_dp/Memory/(9, 3)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (26*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 75, "ctrl_dp/Memory/(1, 4)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (27*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 76, "ctrl_dp/Memory/(2, 4)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (28*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 77, "ctrl_dp/Memory/(3, 4)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (29*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 78, "ctrl_dp/Memory/(4, 4)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (30*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 79, "ctrl_dp/Memory/(5, 4)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (31*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 80, "ctrl_dp/Memory/(6, 4)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (32*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 81, "ctrl_dp/Memory/(7, 4)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (33*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 82, "ctrl_dp/Memory/(8, 4)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (34*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 83, "ctrl_dp/Memory/(9, 4)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (35*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 84, "ctrl_dp/Memory/(1, 5)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (36*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 85, "ctrl_dp/Memory/(2, 5)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (37*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 86, "ctrl_dp/Memory/(3, 5)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (38*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 87, "ctrl_dp/Memory/(4, 5)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (39*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 88, "ctrl_dp/Memory/(5, 5)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (40*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 89, "ctrl_dp/Memory/(6, 5)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (41*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 90, "ctrl_dp/Memory/(7, 5)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (42*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 91, "ctrl_dp/Memory/(8, 5)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (43*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 92, "ctrl_dp/Memory/(9, 5)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (44*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 93, "ctrl_dp/Memory/(1, 6)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (45*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 94, "ctrl_dp/Memory/(2, 6)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (46*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 95, "ctrl_dp/Memory/(3, 6)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (47*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 96, "ctrl_dp/Memory/(4, 6)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (48*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 97, "ctrl_dp/Memory/(5, 6)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (49*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 98, "ctrl_dp/Memory/(6, 6)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (50*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 99, "ctrl_dp/Memory/(7, 6)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (51*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 100, "ctrl_dp/Memory/(8, 6)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (52*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 101, "ctrl_dp/Memory/(9, 6)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (53*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 102, "ctrl_dp/Memory/(1, 7)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (54*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 103, "ctrl_dp/Memory/(2, 7)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (55*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 104, "ctrl_dp/Memory/(3, 7)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (56*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 105, "ctrl_dp/Memory/(4, 7)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (57*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 106, "ctrl_dp/Memory/(5, 7)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (58*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 107, "ctrl_dp/Memory/(6, 7)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (59*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 108, "ctrl_dp/Memory/(7, 7)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (60*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 109, "ctrl_dp/Memory/(8, 7)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (61*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 110, "ctrl_dp/Memory/(9, 7)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (62*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 111, "ctrl_dp/Memory/(1, 8)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (63*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 112, "ctrl_dp/Memory/(2, 8)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (64*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 113, "ctrl_dp/Memory/(3, 8)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (65*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 114, "ctrl_dp/Memory/(4, 8)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (66*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 115, "ctrl_dp/Memory/(5, 8)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (67*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 116, "ctrl_dp/Memory/(6, 8)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (68*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 117, "ctrl_dp/Memory/(7, 8)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (69*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 118, "ctrl_dp/Memory/(8, 8)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (70*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 119, "ctrl_dp/Memory/(9, 8)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (71*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 120, "ctrl_dp/Memory/(1, 9)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (72*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 121, "ctrl_dp/Memory/(2, 9)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (73*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 122, "ctrl_dp/Memory/(3, 9)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (74*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 123, "ctrl_dp/Memory/(4, 9)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (75*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 124, "ctrl_dp/Memory/(5, 9)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (76*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 125, "ctrl_dp/Memory/(6, 9)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (77*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 126, "ctrl_dp/Memory/(7, 9)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (78*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 127, "ctrl_dp/Memory/(8, 9)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (79*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 128, "ctrl_dp/Memory/(9, 9)", 0, "", offsetof(B_ctrl_DP_T, Memory) + (80*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 129, "ctrl_dp/Memory1/(1, 1)", 0, "", offsetof(B_ctrl_DP_T, Memory1) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 130, "ctrl_dp/Memory1/(1, 2)", 0, "", offsetof(B_ctrl_DP_T, Memory1) + (1*
    sizeof(real_T)), BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 131, "ctrl_dp/Memory1/(1, 3)", 0, "", offsetof(B_ctrl_DP_T, Memory1) + (2*
    sizeof(real_T)), BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 132, "ctrl_dp/Memory1/(1, 4)", 0, "", offsetof(B_ctrl_DP_T, Memory1) + (3*
    sizeof(real_T)), BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 133, "ctrl_dp/Memory1/(1, 5)", 0, "", offsetof(B_ctrl_DP_T, Memory1) + (4*
    sizeof(real_T)), BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 134, "ctrl_dp/Memory1/(1, 6)", 0, "", offsetof(B_ctrl_DP_T, Memory1) + (5*
    sizeof(real_T)), BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 135, "ctrl_dp/Memory1/(1, 7)", 0, "", offsetof(B_ctrl_DP_T, Memory1) + (6*
    sizeof(real_T)), BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 136, "ctrl_dp/Memory1/(1, 8)", 0, "", offsetof(B_ctrl_DP_T, Memory1) + (7*
    sizeof(real_T)), BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 137, "ctrl_dp/Memory1/(1, 9)", 0, "", offsetof(B_ctrl_DP_T, Memory1) + (8*
    sizeof(real_T)), BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 138, "ctrl_dp/Nonlinear Passisve Observer/Integrator/(1, 1)", 0, "",
    offsetof(B_ctrl_DP_T, Integrator) + (0*sizeof(real_T)), BLOCKIO_SIG, 18, 1,
    2, 0, 0 },

  { 139, "ctrl_dp/Nonlinear Passisve Observer/Integrator/(1, 2)", 0, "",
    offsetof(B_ctrl_DP_T, Integrator) + (1*sizeof(real_T)), BLOCKIO_SIG, 18, 1,
    2, 0, 0 },

  { 140, "ctrl_dp/Nonlinear Passisve Observer/Integrator/(1, 3)", 0, "",
    offsetof(B_ctrl_DP_T, Integrator) + (2*sizeof(real_T)), BLOCKIO_SIG, 18, 1,
    2, 0, 0 },

  { 141, "ctrl_dp/Nonlinear Passisve Observer/[-inf inf] to [-pi pi]/Sum", 0, "",
    offsetof(B_ctrl_DP_T, Sum_f) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 142, "ctrl_dp/Nonlinear Passisve Observer/Integrator2/(1, 1)", 0, "",
    offsetof(B_ctrl_DP_T, Integrator2) + (0*sizeof(real_T)), BLOCKIO_SIG, 18, 1,
    2, 0, 0 },

  { 143, "ctrl_dp/Nonlinear Passisve Observer/Integrator2/(1, 2)", 0, "",
    offsetof(B_ctrl_DP_T, Integrator2) + (1*sizeof(real_T)), BLOCKIO_SIG, 18, 1,
    2, 0, 0 },

  { 144, "ctrl_dp/Nonlinear Passisve Observer/Integrator2/(1, 3)", 0, "",
    offsetof(B_ctrl_DP_T, Integrator2) + (2*sizeof(real_T)), BLOCKIO_SIG, 18, 1,
    2, 0, 0 },

  { 145, "ctrl_dp/Nonlinear Passisve Observer/M^-1/(1, 1)", 0, "", offsetof
    (B_ctrl_DP_T, M1) + (0*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 146, "ctrl_dp/Nonlinear Passisve Observer/M^-1/(1, 2)", 0, "", offsetof
    (B_ctrl_DP_T, M1) + (1*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 147, "ctrl_dp/Nonlinear Passisve Observer/M^-1/(1, 3)", 0, "", offsetof
    (B_ctrl_DP_T, M1) + (2*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 148, "ctrl_dp/Guidance/Reference model/Matrix Multiply/(1, 1)", 0, "",
    offsetof(B_ctrl_DP_T, MatrixMultiply) + (0*sizeof(real_T)), BLOCKIO_SIG, 18,
    1, 2, 0, 0 },

  { 149, "ctrl_dp/Guidance/Reference model/Matrix Multiply/(1, 2)", 0, "",
    offsetof(B_ctrl_DP_T, MatrixMultiply) + (1*sizeof(real_T)), BLOCKIO_SIG, 18,
    1, 2, 0, 0 },

  { 150, "ctrl_dp/Guidance/Reference model/Matrix Multiply/(1, 3)", 0, "",
    offsetof(B_ctrl_DP_T, MatrixMultiply) + (2*sizeof(real_T)), BLOCKIO_SIG, 18,
    1, 2, 0, 0 },

  { 151, "ctrl_dp/Guidance/Reference model/Sum5", 0, "(1, 1)", offsetof
    (B_ctrl_DP_T, Sum5) + (0*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 152, "ctrl_dp/Guidance/Reference model/Sum5", 0, "(1, 2)", offsetof
    (B_ctrl_DP_T, Sum5) + (1*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 153, "ctrl_dp/Guidance/Reference model/Sum5", 0, "(1, 3)", offsetof
    (B_ctrl_DP_T, Sum5) + (2*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 154, "ctrl_dp/IMU/Gyro_x", 0, "", offsetof(B_ctrl_DP_T, Gyro_x) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 155, "ctrl_dp/IMU/Gyro_y", 0, "", offsetof(B_ctrl_DP_T, Gyro_y) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 156, "ctrl_dp/IMU/Gyro_z", 0, "", offsetof(B_ctrl_DP_T, Gyro_z) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 157, "ctrl_dp/Nonlinear Passisve Observer/Matrix Multiply1/(1, 1)", 0, "",
    offsetof(B_ctrl_DP_T, MatrixMultiply1) + (0*sizeof(real_T)), BLOCKIO_SIG, 18,
    1, 2, 0, 0 },

  { 158, "ctrl_dp/Nonlinear Passisve Observer/Matrix Multiply1/(1, 2)", 0, "",
    offsetof(B_ctrl_DP_T, MatrixMultiply1) + (1*sizeof(real_T)), BLOCKIO_SIG, 18,
    1, 2, 0, 0 },

  { 159, "ctrl_dp/Nonlinear Passisve Observer/Matrix Multiply1/(1, 3)", 0, "",
    offsetof(B_ctrl_DP_T, MatrixMultiply1) + (2*sizeof(real_T)), BLOCKIO_SIG, 18,
    1, 2, 0, 0 },

  { 160, "ctrl_dp/Nonlinear Passisve Observer/Sum1/(1, 1)", 0, "", offsetof
    (B_ctrl_DP_T, Sum1) + (0*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 161, "ctrl_dp/Nonlinear Passisve Observer/Sum1/(1, 2)", 0, "", offsetof
    (B_ctrl_DP_T, Sum1) + (1*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 162, "ctrl_dp/Nonlinear Passisve Observer/Sum1/(1, 3)", 0, "", offsetof
    (B_ctrl_DP_T, Sum1) + (2*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 163, "ctrl_dp/Guidance output/Transposed rotation  matrix in yaw2/Row3", 0,
    "", offsetof(B_ctrl_DP_T, Row3) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 164, "ctrl_dp/Guidance output/Transposed rotation  matrix in yaw2/Row1", 0,
    "", offsetof(B_ctrl_DP_T, Row1) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 165, "ctrl_dp/Guidance output/Transposed rotation  matrix in yaw2/Row2", 0,
    "", offsetof(B_ctrl_DP_T, Row2) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 166, "ctrl_dp/Thrust allocation", 0, "", offsetof(B_ctrl_DP_T, u_BT) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 167, "ctrl_dp/Thrust allocation", 1, "", offsetof(B_ctrl_DP_T, u_VSP) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 168, "ctrl_dp/Thrust allocation", 2, "", offsetof(B_ctrl_DP_T, alpha_VSP) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 169, "ctrl_dp/Thrust allocation", 3, "", offsetof(B_ctrl_DP_T, omega_VSP) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 170, "ctrl_dp/EKF INS", 0, "(1, 1)", offsetof(B_ctrl_DP_T, pos_est) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 171, "ctrl_dp/EKF INS", 0, "(1, 2)", offsetof(B_ctrl_DP_T, pos_est) + (1*
    sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 172, "ctrl_dp/EKF INS", 0, "(1, 3)", offsetof(B_ctrl_DP_T, pos_est) + (2*
    sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 173, "ctrl_dp/EKF INS", 1, "(1, 1)", offsetof(B_ctrl_DP_T, P) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 174, "ctrl_dp/EKF INS", 1, "(2, 1)", offsetof(B_ctrl_DP_T, P) + (1*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 175, "ctrl_dp/EKF INS", 1, "(3, 1)", offsetof(B_ctrl_DP_T, P) + (2*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 176, "ctrl_dp/EKF INS", 1, "(4, 1)", offsetof(B_ctrl_DP_T, P) + (3*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 177, "ctrl_dp/EKF INS", 1, "(5, 1)", offsetof(B_ctrl_DP_T, P) + (4*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 178, "ctrl_dp/EKF INS", 1, "(6, 1)", offsetof(B_ctrl_DP_T, P) + (5*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 179, "ctrl_dp/EKF INS", 1, "(7, 1)", offsetof(B_ctrl_DP_T, P) + (6*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 180, "ctrl_dp/EKF INS", 1, "(8, 1)", offsetof(B_ctrl_DP_T, P) + (7*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 181, "ctrl_dp/EKF INS", 1, "(9, 1)", offsetof(B_ctrl_DP_T, P) + (8*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 182, "ctrl_dp/EKF INS", 1, "(1, 2)", offsetof(B_ctrl_DP_T, P) + (9*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 183, "ctrl_dp/EKF INS", 1, "(2, 2)", offsetof(B_ctrl_DP_T, P) + (10*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 184, "ctrl_dp/EKF INS", 1, "(3, 2)", offsetof(B_ctrl_DP_T, P) + (11*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 185, "ctrl_dp/EKF INS", 1, "(4, 2)", offsetof(B_ctrl_DP_T, P) + (12*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 186, "ctrl_dp/EKF INS", 1, "(5, 2)", offsetof(B_ctrl_DP_T, P) + (13*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 187, "ctrl_dp/EKF INS", 1, "(6, 2)", offsetof(B_ctrl_DP_T, P) + (14*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 188, "ctrl_dp/EKF INS", 1, "(7, 2)", offsetof(B_ctrl_DP_T, P) + (15*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 189, "ctrl_dp/EKF INS", 1, "(8, 2)", offsetof(B_ctrl_DP_T, P) + (16*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 190, "ctrl_dp/EKF INS", 1, "(9, 2)", offsetof(B_ctrl_DP_T, P) + (17*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 191, "ctrl_dp/EKF INS", 1, "(1, 3)", offsetof(B_ctrl_DP_T, P) + (18*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 192, "ctrl_dp/EKF INS", 1, "(2, 3)", offsetof(B_ctrl_DP_T, P) + (19*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 193, "ctrl_dp/EKF INS", 1, "(3, 3)", offsetof(B_ctrl_DP_T, P) + (20*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 194, "ctrl_dp/EKF INS", 1, "(4, 3)", offsetof(B_ctrl_DP_T, P) + (21*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 195, "ctrl_dp/EKF INS", 1, "(5, 3)", offsetof(B_ctrl_DP_T, P) + (22*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 196, "ctrl_dp/EKF INS", 1, "(6, 3)", offsetof(B_ctrl_DP_T, P) + (23*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 197, "ctrl_dp/EKF INS", 1, "(7, 3)", offsetof(B_ctrl_DP_T, P) + (24*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 198, "ctrl_dp/EKF INS", 1, "(8, 3)", offsetof(B_ctrl_DP_T, P) + (25*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 199, "ctrl_dp/EKF INS", 1, "(9, 3)", offsetof(B_ctrl_DP_T, P) + (26*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 200, "ctrl_dp/EKF INS", 1, "(1, 4)", offsetof(B_ctrl_DP_T, P) + (27*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 201, "ctrl_dp/EKF INS", 1, "(2, 4)", offsetof(B_ctrl_DP_T, P) + (28*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 202, "ctrl_dp/EKF INS", 1, "(3, 4)", offsetof(B_ctrl_DP_T, P) + (29*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 203, "ctrl_dp/EKF INS", 1, "(4, 4)", offsetof(B_ctrl_DP_T, P) + (30*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 204, "ctrl_dp/EKF INS", 1, "(5, 4)", offsetof(B_ctrl_DP_T, P) + (31*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 205, "ctrl_dp/EKF INS", 1, "(6, 4)", offsetof(B_ctrl_DP_T, P) + (32*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 206, "ctrl_dp/EKF INS", 1, "(7, 4)", offsetof(B_ctrl_DP_T, P) + (33*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 207, "ctrl_dp/EKF INS", 1, "(8, 4)", offsetof(B_ctrl_DP_T, P) + (34*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 208, "ctrl_dp/EKF INS", 1, "(9, 4)", offsetof(B_ctrl_DP_T, P) + (35*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 209, "ctrl_dp/EKF INS", 1, "(1, 5)", offsetof(B_ctrl_DP_T, P) + (36*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 210, "ctrl_dp/EKF INS", 1, "(2, 5)", offsetof(B_ctrl_DP_T, P) + (37*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 211, "ctrl_dp/EKF INS", 1, "(3, 5)", offsetof(B_ctrl_DP_T, P) + (38*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 212, "ctrl_dp/EKF INS", 1, "(4, 5)", offsetof(B_ctrl_DP_T, P) + (39*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 213, "ctrl_dp/EKF INS", 1, "(5, 5)", offsetof(B_ctrl_DP_T, P) + (40*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 214, "ctrl_dp/EKF INS", 1, "(6, 5)", offsetof(B_ctrl_DP_T, P) + (41*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 215, "ctrl_dp/EKF INS", 1, "(7, 5)", offsetof(B_ctrl_DP_T, P) + (42*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 216, "ctrl_dp/EKF INS", 1, "(8, 5)", offsetof(B_ctrl_DP_T, P) + (43*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 217, "ctrl_dp/EKF INS", 1, "(9, 5)", offsetof(B_ctrl_DP_T, P) + (44*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 218, "ctrl_dp/EKF INS", 1, "(1, 6)", offsetof(B_ctrl_DP_T, P) + (45*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 219, "ctrl_dp/EKF INS", 1, "(2, 6)", offsetof(B_ctrl_DP_T, P) + (46*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 220, "ctrl_dp/EKF INS", 1, "(3, 6)", offsetof(B_ctrl_DP_T, P) + (47*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 221, "ctrl_dp/EKF INS", 1, "(4, 6)", offsetof(B_ctrl_DP_T, P) + (48*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 222, "ctrl_dp/EKF INS", 1, "(5, 6)", offsetof(B_ctrl_DP_T, P) + (49*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 223, "ctrl_dp/EKF INS", 1, "(6, 6)", offsetof(B_ctrl_DP_T, P) + (50*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 224, "ctrl_dp/EKF INS", 1, "(7, 6)", offsetof(B_ctrl_DP_T, P) + (51*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 225, "ctrl_dp/EKF INS", 1, "(8, 6)", offsetof(B_ctrl_DP_T, P) + (52*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 226, "ctrl_dp/EKF INS", 1, "(9, 6)", offsetof(B_ctrl_DP_T, P) + (53*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 227, "ctrl_dp/EKF INS", 1, "(1, 7)", offsetof(B_ctrl_DP_T, P) + (54*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 228, "ctrl_dp/EKF INS", 1, "(2, 7)", offsetof(B_ctrl_DP_T, P) + (55*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 229, "ctrl_dp/EKF INS", 1, "(3, 7)", offsetof(B_ctrl_DP_T, P) + (56*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 230, "ctrl_dp/EKF INS", 1, "(4, 7)", offsetof(B_ctrl_DP_T, P) + (57*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 231, "ctrl_dp/EKF INS", 1, "(5, 7)", offsetof(B_ctrl_DP_T, P) + (58*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 232, "ctrl_dp/EKF INS", 1, "(6, 7)", offsetof(B_ctrl_DP_T, P) + (59*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 233, "ctrl_dp/EKF INS", 1, "(7, 7)", offsetof(B_ctrl_DP_T, P) + (60*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 234, "ctrl_dp/EKF INS", 1, "(8, 7)", offsetof(B_ctrl_DP_T, P) + (61*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 235, "ctrl_dp/EKF INS", 1, "(9, 7)", offsetof(B_ctrl_DP_T, P) + (62*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 236, "ctrl_dp/EKF INS", 1, "(1, 8)", offsetof(B_ctrl_DP_T, P) + (63*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 237, "ctrl_dp/EKF INS", 1, "(2, 8)", offsetof(B_ctrl_DP_T, P) + (64*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 238, "ctrl_dp/EKF INS", 1, "(3, 8)", offsetof(B_ctrl_DP_T, P) + (65*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 239, "ctrl_dp/EKF INS", 1, "(4, 8)", offsetof(B_ctrl_DP_T, P) + (66*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 240, "ctrl_dp/EKF INS", 1, "(5, 8)", offsetof(B_ctrl_DP_T, P) + (67*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 241, "ctrl_dp/EKF INS", 1, "(6, 8)", offsetof(B_ctrl_DP_T, P) + (68*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 242, "ctrl_dp/EKF INS", 1, "(7, 8)", offsetof(B_ctrl_DP_T, P) + (69*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 243, "ctrl_dp/EKF INS", 1, "(8, 8)", offsetof(B_ctrl_DP_T, P) + (70*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 244, "ctrl_dp/EKF INS", 1, "(9, 8)", offsetof(B_ctrl_DP_T, P) + (71*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 245, "ctrl_dp/EKF INS", 1, "(1, 9)", offsetof(B_ctrl_DP_T, P) + (72*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 246, "ctrl_dp/EKF INS", 1, "(2, 9)", offsetof(B_ctrl_DP_T, P) + (73*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 247, "ctrl_dp/EKF INS", 1, "(3, 9)", offsetof(B_ctrl_DP_T, P) + (74*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 248, "ctrl_dp/EKF INS", 1, "(4, 9)", offsetof(B_ctrl_DP_T, P) + (75*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 249, "ctrl_dp/EKF INS", 1, "(5, 9)", offsetof(B_ctrl_DP_T, P) + (76*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 250, "ctrl_dp/EKF INS", 1, "(6, 9)", offsetof(B_ctrl_DP_T, P) + (77*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 251, "ctrl_dp/EKF INS", 1, "(7, 9)", offsetof(B_ctrl_DP_T, P) + (78*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 252, "ctrl_dp/EKF INS", 1, "(8, 9)", offsetof(B_ctrl_DP_T, P) + (79*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 253, "ctrl_dp/EKF INS", 1, "(9, 9)", offsetof(B_ctrl_DP_T, P) + (80*sizeof
    (real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 254, "ctrl_dp/EKF INS", 2, "(1, 1)", offsetof(B_ctrl_DP_T, x_p) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 255, "ctrl_dp/EKF INS", 2, "(1, 2)", offsetof(B_ctrl_DP_T, x_p) + (1*sizeof
    (real_T)), BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 256, "ctrl_dp/EKF INS", 2, "(1, 3)", offsetof(B_ctrl_DP_T, x_p) + (2*sizeof
    (real_T)), BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 257, "ctrl_dp/EKF INS", 2, "(1, 4)", offsetof(B_ctrl_DP_T, x_p) + (3*sizeof
    (real_T)), BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 258, "ctrl_dp/EKF INS", 2, "(1, 5)", offsetof(B_ctrl_DP_T, x_p) + (4*sizeof
    (real_T)), BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 259, "ctrl_dp/EKF INS", 2, "(1, 6)", offsetof(B_ctrl_DP_T, x_p) + (5*sizeof
    (real_T)), BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 260, "ctrl_dp/EKF INS", 2, "(1, 7)", offsetof(B_ctrl_DP_T, x_p) + (6*sizeof
    (real_T)), BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 261, "ctrl_dp/EKF INS", 2, "(1, 8)", offsetof(B_ctrl_DP_T, x_p) + (7*sizeof
    (real_T)), BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 262, "ctrl_dp/EKF INS", 2, "(1, 9)", offsetof(B_ctrl_DP_T, x_p) + (8*sizeof
    (real_T)), BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 263, "ctrl_dp/Input/Observer Gains/MATLAB Function2", 0, "(1, 1)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction2_p.K_d) + (0*sizeof(real_T)), BLOCKIO_SIG,
    19, 1, 2, 0, 0 },

  { 264, "ctrl_dp/Input/Observer Gains/MATLAB Function2", 0, "(2, 1)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction2_p.K_d) + (1*sizeof(real_T)), BLOCKIO_SIG,
    19, 1, 2, 0, 0 },

  { 265, "ctrl_dp/Input/Observer Gains/MATLAB Function2", 0, "(3, 1)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction2_p.K_d) + (2*sizeof(real_T)), BLOCKIO_SIG,
    19, 1, 2, 0, 0 },

  { 266, "ctrl_dp/Input/Observer Gains/MATLAB Function2", 0, "(1, 2)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction2_p.K_d) + (3*sizeof(real_T)), BLOCKIO_SIG,
    19, 1, 2, 0, 0 },

  { 267, "ctrl_dp/Input/Observer Gains/MATLAB Function2", 0, "(2, 2)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction2_p.K_d) + (4*sizeof(real_T)), BLOCKIO_SIG,
    19, 1, 2, 0, 0 },

  { 268, "ctrl_dp/Input/Observer Gains/MATLAB Function2", 0, "(3, 2)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction2_p.K_d) + (5*sizeof(real_T)), BLOCKIO_SIG,
    19, 1, 2, 0, 0 },

  { 269, "ctrl_dp/Input/Observer Gains/MATLAB Function2", 0, "(1, 3)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction2_p.K_d) + (6*sizeof(real_T)), BLOCKIO_SIG,
    19, 1, 2, 0, 0 },

  { 270, "ctrl_dp/Input/Observer Gains/MATLAB Function2", 0, "(2, 3)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction2_p.K_d) + (7*sizeof(real_T)), BLOCKIO_SIG,
    19, 1, 2, 0, 0 },

  { 271, "ctrl_dp/Input/Observer Gains/MATLAB Function2", 0, "(3, 3)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction2_p.K_d) + (8*sizeof(real_T)), BLOCKIO_SIG,
    19, 1, 2, 0, 0 },

  { 272, "ctrl_dp/Input/Observer Gains/MATLAB Function1", 0, "(1, 1)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction1_c.K_i) + (0*sizeof(real_T)), BLOCKIO_SIG,
    19, 1, 2, 0, 0 },

  { 273, "ctrl_dp/Input/Observer Gains/MATLAB Function1", 0, "(2, 1)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction1_c.K_i) + (1*sizeof(real_T)), BLOCKIO_SIG,
    19, 1, 2, 0, 0 },

  { 274, "ctrl_dp/Input/Observer Gains/MATLAB Function1", 0, "(3, 1)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction1_c.K_i) + (2*sizeof(real_T)), BLOCKIO_SIG,
    19, 1, 2, 0, 0 },

  { 275, "ctrl_dp/Input/Observer Gains/MATLAB Function1", 0, "(1, 2)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction1_c.K_i) + (3*sizeof(real_T)), BLOCKIO_SIG,
    19, 1, 2, 0, 0 },

  { 276, "ctrl_dp/Input/Observer Gains/MATLAB Function1", 0, "(2, 2)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction1_c.K_i) + (4*sizeof(real_T)), BLOCKIO_SIG,
    19, 1, 2, 0, 0 },

  { 277, "ctrl_dp/Input/Observer Gains/MATLAB Function1", 0, "(3, 2)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction1_c.K_i) + (5*sizeof(real_T)), BLOCKIO_SIG,
    19, 1, 2, 0, 0 },

  { 278, "ctrl_dp/Input/Observer Gains/MATLAB Function1", 0, "(1, 3)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction1_c.K_i) + (6*sizeof(real_T)), BLOCKIO_SIG,
    19, 1, 2, 0, 0 },

  { 279, "ctrl_dp/Input/Observer Gains/MATLAB Function1", 0, "(2, 3)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction1_c.K_i) + (7*sizeof(real_T)), BLOCKIO_SIG,
    19, 1, 2, 0, 0 },

  { 280, "ctrl_dp/Input/Observer Gains/MATLAB Function1", 0, "(3, 3)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction1_c.K_i) + (8*sizeof(real_T)), BLOCKIO_SIG,
    19, 1, 2, 0, 0 },

  { 281, "ctrl_dp/Input/Observer Gains/MATLAB Function", 0, "(1, 1)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction_l.K_p) + (0*sizeof(real_T)), BLOCKIO_SIG, 19,
    1, 2, 0, 0 },

  { 282, "ctrl_dp/Input/Observer Gains/MATLAB Function", 0, "(2, 1)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction_l.K_p) + (1*sizeof(real_T)), BLOCKIO_SIG, 19,
    1, 2, 0, 0 },

  { 283, "ctrl_dp/Input/Observer Gains/MATLAB Function", 0, "(3, 1)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction_l.K_p) + (2*sizeof(real_T)), BLOCKIO_SIG, 19,
    1, 2, 0, 0 },

  { 284, "ctrl_dp/Input/Observer Gains/MATLAB Function", 0, "(1, 2)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction_l.K_p) + (3*sizeof(real_T)), BLOCKIO_SIG, 19,
    1, 2, 0, 0 },

  { 285, "ctrl_dp/Input/Observer Gains/MATLAB Function", 0, "(2, 2)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction_l.K_p) + (4*sizeof(real_T)), BLOCKIO_SIG, 19,
    1, 2, 0, 0 },

  { 286, "ctrl_dp/Input/Observer Gains/MATLAB Function", 0, "(3, 2)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction_l.K_p) + (5*sizeof(real_T)), BLOCKIO_SIG, 19,
    1, 2, 0, 0 },

  { 287, "ctrl_dp/Input/Observer Gains/MATLAB Function", 0, "(1, 3)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction_l.K_p) + (6*sizeof(real_T)), BLOCKIO_SIG, 19,
    1, 2, 0, 0 },

  { 288, "ctrl_dp/Input/Observer Gains/MATLAB Function", 0, "(2, 3)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction_l.K_p) + (7*sizeof(real_T)), BLOCKIO_SIG, 19,
    1, 2, 0, 0 },

  { 289, "ctrl_dp/Input/Observer Gains/MATLAB Function", 0, "(3, 3)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction_l.K_p) + (8*sizeof(real_T)), BLOCKIO_SIG, 19,
    1, 2, 0, 0 },

  { 290, "ctrl_dp/Input/Control Gains/MATLAB Function2", 0, "(1, 1)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction2.K_d) + (0*sizeof(real_T)), BLOCKIO_SIG, 19,
    1, 2, 0, 0 },

  { 291, "ctrl_dp/Input/Control Gains/MATLAB Function2", 0, "(2, 1)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction2.K_d) + (1*sizeof(real_T)), BLOCKIO_SIG, 19,
    1, 2, 0, 0 },

  { 292, "ctrl_dp/Input/Control Gains/MATLAB Function2", 0, "(3, 1)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction2.K_d) + (2*sizeof(real_T)), BLOCKIO_SIG, 19,
    1, 2, 0, 0 },

  { 293, "ctrl_dp/Input/Control Gains/MATLAB Function2", 0, "(1, 2)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction2.K_d) + (3*sizeof(real_T)), BLOCKIO_SIG, 19,
    1, 2, 0, 0 },

  { 294, "ctrl_dp/Input/Control Gains/MATLAB Function2", 0, "(2, 2)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction2.K_d) + (4*sizeof(real_T)), BLOCKIO_SIG, 19,
    1, 2, 0, 0 },

  { 295, "ctrl_dp/Input/Control Gains/MATLAB Function2", 0, "(3, 2)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction2.K_d) + (5*sizeof(real_T)), BLOCKIO_SIG, 19,
    1, 2, 0, 0 },

  { 296, "ctrl_dp/Input/Control Gains/MATLAB Function2", 0, "(1, 3)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction2.K_d) + (6*sizeof(real_T)), BLOCKIO_SIG, 19,
    1, 2, 0, 0 },

  { 297, "ctrl_dp/Input/Control Gains/MATLAB Function2", 0, "(2, 3)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction2.K_d) + (7*sizeof(real_T)), BLOCKIO_SIG, 19,
    1, 2, 0, 0 },

  { 298, "ctrl_dp/Input/Control Gains/MATLAB Function2", 0, "(3, 3)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction2.K_d) + (8*sizeof(real_T)), BLOCKIO_SIG, 19,
    1, 2, 0, 0 },

  { 299, "ctrl_dp/Input/Control Gains/MATLAB Function1", 0, "(1, 1)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction1.K_i) + (0*sizeof(real_T)), BLOCKIO_SIG, 19,
    1, 2, 0, 0 },

  { 300, "ctrl_dp/Input/Control Gains/MATLAB Function1", 0, "(2, 1)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction1.K_i) + (1*sizeof(real_T)), BLOCKIO_SIG, 19,
    1, 2, 0, 0 },

  { 301, "ctrl_dp/Input/Control Gains/MATLAB Function1", 0, "(3, 1)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction1.K_i) + (2*sizeof(real_T)), BLOCKIO_SIG, 19,
    1, 2, 0, 0 },

  { 302, "ctrl_dp/Input/Control Gains/MATLAB Function1", 0, "(1, 2)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction1.K_i) + (3*sizeof(real_T)), BLOCKIO_SIG, 19,
    1, 2, 0, 0 },

  { 303, "ctrl_dp/Input/Control Gains/MATLAB Function1", 0, "(2, 2)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction1.K_i) + (4*sizeof(real_T)), BLOCKIO_SIG, 19,
    1, 2, 0, 0 },

  { 304, "ctrl_dp/Input/Control Gains/MATLAB Function1", 0, "(3, 2)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction1.K_i) + (5*sizeof(real_T)), BLOCKIO_SIG, 19,
    1, 2, 0, 0 },

  { 305, "ctrl_dp/Input/Control Gains/MATLAB Function1", 0, "(1, 3)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction1.K_i) + (6*sizeof(real_T)), BLOCKIO_SIG, 19,
    1, 2, 0, 0 },

  { 306, "ctrl_dp/Input/Control Gains/MATLAB Function1", 0, "(2, 3)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction1.K_i) + (7*sizeof(real_T)), BLOCKIO_SIG, 19,
    1, 2, 0, 0 },

  { 307, "ctrl_dp/Input/Control Gains/MATLAB Function1", 0, "(3, 3)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction1.K_i) + (8*sizeof(real_T)), BLOCKIO_SIG, 19,
    1, 2, 0, 0 },

  { 308, "ctrl_dp/Input/Control Gains/MATLAB Function", 0, "(1, 1)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction.K_p) + (0*sizeof(real_T)), BLOCKIO_SIG, 19,
    1, 2, 0, 0 },

  { 309, "ctrl_dp/Input/Control Gains/MATLAB Function", 0, "(2, 1)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction.K_p) + (1*sizeof(real_T)), BLOCKIO_SIG, 19,
    1, 2, 0, 0 },

  { 310, "ctrl_dp/Input/Control Gains/MATLAB Function", 0, "(3, 1)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction.K_p) + (2*sizeof(real_T)), BLOCKIO_SIG, 19,
    1, 2, 0, 0 },

  { 311, "ctrl_dp/Input/Control Gains/MATLAB Function", 0, "(1, 2)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction.K_p) + (3*sizeof(real_T)), BLOCKIO_SIG, 19,
    1, 2, 0, 0 },

  { 312, "ctrl_dp/Input/Control Gains/MATLAB Function", 0, "(2, 2)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction.K_p) + (4*sizeof(real_T)), BLOCKIO_SIG, 19,
    1, 2, 0, 0 },

  { 313, "ctrl_dp/Input/Control Gains/MATLAB Function", 0, "(3, 2)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction.K_p) + (5*sizeof(real_T)), BLOCKIO_SIG, 19,
    1, 2, 0, 0 },

  { 314, "ctrl_dp/Input/Control Gains/MATLAB Function", 0, "(1, 3)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction.K_p) + (6*sizeof(real_T)), BLOCKIO_SIG, 19,
    1, 2, 0, 0 },

  { 315, "ctrl_dp/Input/Control Gains/MATLAB Function", 0, "(2, 3)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction.K_p) + (7*sizeof(real_T)), BLOCKIO_SIG, 19,
    1, 2, 0, 0 },

  { 316, "ctrl_dp/Input/Control Gains/MATLAB Function", 0, "(3, 3)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction.K_p) + (8*sizeof(real_T)), BLOCKIO_SIG, 19,
    1, 2, 0, 0 },

  { -1, "", -1, "", 0, 0, 0 }
};

static int32_t NI_SigListSize DataSection(".NIVS.siglistsize") = 317;
static int32_t NI_VirtualBlockSources[1];
static int32_t NI_SigDimList[] DataSection(".NIVS.sigdimlist") =
{ 1, 1
};

static int32_t NI_ExtListSize DataSection(".NIVS.extlistsize") = 66;
static NI_ExternalIO NI_ExtList[] DataSection(".NIVS.extlist") =
{
  { 1, "Input/Control Gains/K_p_x", 0, EXT_IN, 1, 1, 1 },

  { 2, "Input/Control Gains/K_p_y", 0, EXT_IN, 1, 1, 1 },

  { 3, "Input/Control Gains/K_p_psi", 0, EXT_IN, 1, 1, 1 },

  { 4, "Input/Control Gains/K_i_psi", 0, EXT_IN, 1, 1, 1 },

  { 5, "Input/Control Gains/K_i_x", 0, EXT_IN, 1, 1, 1 },

  { 6, "Input/Control Gains/K_i_y", 0, EXT_IN, 1, 1, 1 },

  { 7, "Input/Control Gains/K_d_psi", 0, EXT_IN, 1, 1, 1 },

  { 8, "Input/Control Gains/K_d_x", 0, EXT_IN, 1, 1, 1 },

  { 9, "Input/Control Gains/K_d_y", 0, EXT_IN, 1, 1, 1 },

  { 10, "POSE/x", 0, EXT_IN, 1, 1, 1 },

  { 11, "POSE/y", 0, EXT_IN, 1, 1, 1 },

  { 12, "POSE/psi", 0, EXT_IN, 1, 1, 1 },

  { 13, "Input/reset", 0, EXT_IN, 1, 1, 1 },

  { 14, "Input/Guidance gains/w_d_x", 0, EXT_IN, 1, 1, 1 },

  { 15, "Input/Guidance gains/w_d_y", 0, EXT_IN, 1, 1, 1 },

  { 16, "Input/Guidance gains/w_d_psi", 0, EXT_IN, 1, 1, 1 },

  { 17, "Input/Guidance gains/zeta_psi", 0, EXT_IN, 1, 1, 1 },

  { 18, "Input/Guidance gains/zeta_x", 0, EXT_IN, 1, 1, 1 },

  { 19, "Input/Guidance gains/zeta_y", 0, EXT_IN, 1, 1, 1 },

  { 20, "Input/psi_ref", 0, EXT_IN, 1, 1, 1 },

  { 21, "Input/x_ref", 0, EXT_IN, 1, 1, 1 },

  { 22, "Input/y_ref", 0, EXT_IN, 1, 1, 1 },

  { 23, "z_m", 0, EXT_IN, 1, 1, 1 },

  { 24, "IMU/Acc_x", 0, EXT_IN, 1, 1, 1 },

  { 25, "IMU/Acc_y", 0, EXT_IN, 1, 1, 1 },

  { 26, "IMU/Acc_z", 0, EXT_IN, 1, 1, 1 },

  { 27, "IMU/Gyro_x", 1, EXT_IN, 1, 1, 1 },

  { 28, "IMU/Gyro_y", 1, EXT_IN, 1, 1, 1 },

  { 29, "IMU/Gyro_z", 1, EXT_IN, 1, 1, 1 },

  { 1, "alpha_VSP2", 0, EXT_OUT, 1, 1, 1 },

  { 2, "omega_VSP1", 0, EXT_OUT, 1, 1, 1 },

  { 3, "omega_VSP2", 0, EXT_OUT, 1, 1, 1 },

  { 4, "alpha_VSP1", 0, EXT_OUT, 1, 1, 1 },

  { 5, "u_BT", 0, EXT_OUT, 1, 1, 1 },

  { 6, "u_VSP1", 0, EXT_OUT, 1, 1, 1 },

  { 7, "u_VSP2", 0, EXT_OUT, 1, 1, 1 },

  { 8, "x_est", 0, EXT_OUT, 1, 1, 1 },

  { 9, "y_est", 0, EXT_OUT, 1, 1, 1 },

  { 10, "Observer output /eta_hat output/x_hat", 0, EXT_OUT, 1, 1, 1 },

  { 11, "Observer output /eta_hat output/y_hat", 0, EXT_OUT, 1, 1, 1 },

  { 12, "Observer output /eta_hat output/psi_hat", 0, EXT_OUT, 1, 1, 1 },

  { 13, "Observer output /nu_hat output/u_hat", 0, EXT_OUT, 1, 1, 1 },

  { 14, "Observer output /nu_hat output/v_hat", 0, EXT_OUT, 1, 1, 1 },

  { 15, "Observer output /nu_hat output/r_hat", 0, EXT_OUT, 1, 1, 1 },

  { 16, "Observer output /nu_dot_hat output/u_dot_hat", 0, EXT_OUT, 1, 1, 1 },

  { 17, "Observer output /nu_dot_hat output/v_dot_hat", 0, EXT_OUT, 1, 1, 1 },

  { 18, "Observer output /nu_dot_hat output/r_dot_hat", 0, EXT_OUT, 1, 1, 1 },

  { 19, "Observer output /b_hat output/b_x_hat", 0, EXT_OUT, 1, 1, 1 },

  { 20, "Observer output /b_hat output/b_y_hat", 0, EXT_OUT, 1, 1, 1 },

  { 21, "Observer output /b_hat output/b_psi_hat", 0, EXT_OUT, 1, 1, 1 },

  { 22, "z_est", 0, EXT_OUT, 1, 1, 1 },

  { 23, "Control output/tau_N", 0, EXT_OUT, 1, 1, 1 },

  { 24, "Control output/tau_X", 0, EXT_OUT, 1, 1, 1 },

  { 25, "Control output/tau_Y", 0, EXT_OUT, 1, 1, 1 },

  { 26, "Control output/psi_tilde", 0, EXT_OUT, 1, 1, 1 },

  { 27, "Control output/x_tilde", 0, EXT_OUT, 1, 1, 1 },

  { 28, "Control output/y_tidle", 0, EXT_OUT, 1, 1, 1 },

  { 29, "Control output/r_tilde", 0, EXT_OUT, 1, 1, 1 },

  { 30, "Control output/u_tilde", 0, EXT_OUT, 1, 1, 1 },

  { 31, "Control output/v_tilde", 0, EXT_OUT, 1, 1, 1 },

  { 32, "Guidance output/x_d", 0, EXT_OUT, 1, 1, 1 },

  { 33, "Guidance output/y_d", 0, EXT_OUT, 1, 1, 1 },

  { 34, "Guidance output/psi_d", 0, EXT_OUT, 1, 1, 1 },

  { 35, "Guidance output/r_d", 0, EXT_OUT, 1, 1, 1 },

  { 36, "Guidance output/u_d", 0, EXT_OUT, 1, 1, 1 },

  { 37, "Guidance output/v_d", 0, EXT_OUT, 1, 1, 1 },

  { -1, "", 0, 0, 0, 0, 0 }
};

/* This Task List is generated to allow access to the task specs without
 * initializing the model.
 * 0th entry is for scheduler (base rate)
 * rest for multirate model's tasks.
 */
NI_Task NI_TaskList[] DataSection(".NIVS.tasklist") =
{
  { 0, 0.01, 0 }
};

int32_t NI_NumTasks DataSection(".NIVS.numtasks") = 1;
static const char* NI_CompiledModelName DataSection(".NIVS.compiledmodelname") =
  "ctrl_DP";
static const char* NI_CompiledModelVersion = "1.53";
static const char* NI_CompiledModelDateTime = "Thu Jul 13 11:39:50 2017";
static const char* NI_builder DataSection(".NIVS.builder") =
  "NI Model Framework 2017.0.0.143 (2017) for Simulink Coder 8.11 (R2016b)";
static const char* NI_BuilderVersion DataSection(".NIVS.builderversion") =
  "2017.0.0.143";

/*========================================================================*
 * Function: NIRT_GetBuildInfo
 *
 * Abstract:
 *	Get the DLL versioning etc information.
 *
 * Output Parameters:
 *	detail	: String containing model build information.
 *	len		: the build info string length. If a value of "-1" is specified, the minimum buffer size of "detail" is returned as its value.
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_GetBuildInfo(char* detail, int32_t* len)
{
  int32_t msgLength = 0;
  char *msgBuffer = NULL;

  /* Message */
  const char msg[] =
    "%s\nModel Name: %s\nModel Version: %s\nVeriStand Model Framework Version: %s\nCompiled On: %s";

  /* There are no console properties to set for VxWorks, because the console is simply serial output data.
     Just do printf for VxWorks and ignore all console properties. */
#if ! defined (VXWORKS) && ! defined (kNIOSLinux)

  HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hStdout, FOREGROUND_INTENSITY | FOREGROUND_BLUE |
    FOREGROUND_GREEN | FOREGROUND_RED);

#endif

  /* Print to screen */
  printf("\n*******************************************************************************\n");
  msgLength = printf(msg, NI_builder, NI_CompiledModelName,
                     NI_CompiledModelVersion, NI_BuilderVersion,
                     NI_CompiledModelDateTime);
  printf("\n*******************************************************************************\n");

#if ! defined (VXWORKS) && ! defined (kNIOSLinux)

  SetConsoleTextAttribute(hStdout, FOREGROUND_BLUE | FOREGROUND_GREEN |
    FOREGROUND_RED);

#endif

  if (*len == -1) {
    /* Return the required minimum buffer size */
    *len = msgLength;
  } else {
    /* allocate the buffer */
    msgBuffer = (char*)calloc(msgLength + 1, sizeof(char));
    sprintf (msgBuffer, msg, NI_builder, NI_CompiledModelName,
             NI_CompiledModelVersion, NI_BuilderVersion,
             NI_CompiledModelDateTime);
    if (*len >= msgLength) {
      *len = msgLength + 1;
    }

    /* Copy into external buffer */
    strncpy(detail, msgBuffer, *len);

    /* Release memory */
    free(msgBuffer);
  }

  return NI_OK;
}

/*========================================================================*
 * Function: NIRT_GetSignalSpec
 *
 * Abstract:
 *	If index == -1, lookup parameter by the ID.
 *	If ID_len == 0 or if ID == null, return number of parameters in model.
 *	Otherwise, lookup parameter by index, and return the information.
 *
 * Input/Output Parameters:
 *	index		: index of the signal (in/out)
 *	ID			: ID of signal to be looked up (in), ID of signal at index (out)
 *	ID_len		: length of input ID(in), length of ID (out)
 *	bnlen		: length of buffer blkname (in), length of output blkname (out)
 *	snlen		: length of buffer signame (in), length of output signame (out)
 *
 * Output Parameters:
 *	blkname		: Name of the source block for the signal
 *	portnum		: port number of the block that is the source of the signal (0 indexed)
 *	signame		: Name of the signal
 *	datatype	: same as with parameters. Currently assuming all data to be double.
 *	dims		: The port's dimension of length 'numdims'.
 *	numdims		: the port's number of dimensions. If a value of "-1" is specified, the minimum buffer size of "dims" is returned as its value.
 *
 * Returns:
 *	NI_OK if no error(if sigidx == -1, number of signals)
 *========================================================================*/
DLL_EXPORT int32_t NIRT_GetSignalSpec(int32_t* sidx, char* ID, int32_t* ID_len,
  char* blkname, int32_t *bnlen,
  int32_t *portnum, char* signame, int32_t *snlen, int32_t *dattype, int32_t*
  dims, int32_t* numdim)
{
  int32_t sigidx = *sidx;
  int32_t i = 0;
  char *addr = NULL;
  char *IDblk = 0;
  int32_t IDport = 0;
  if (sigidx < 0) {
    /* check if ID has been specified. */
    if ((ID != NULL) && (ID_len != NULL) && (*ID_len > 0)) {
      /* parse ID into blkname and port */
      addr = strrchr(ID, ':');
      if (addr == NULL) {
        return NI_SigListSize;
      }

      /* Calculate the char offset into the string after the port */
      i = addr - ID;

      /* malformed ID */
      if (i<=0) {
        return NI_SigListSize;
      }

      IDblk = ID;
      IDport = atoi(ID+i+1);

      /* lookup the table for matching ID */
      for (i=0; i<NI_SigListSize; i++) {
        /* 11 to accomodate ':','/', port number and null character */
        char *tempID = (char *)calloc(strlen(NI_SigList[i].blockname)+strlen
          (NI_SigList[i].signalname) + 11, sizeof(char));
        if (strlen(NI_SigList[i].signalname)>0) {
          sprintf(tempID,"%s:%d%s%s",NI_SigList[i].blockname,NI_SigList[i].
                  portno+1,"/",NI_SigList[i].signalname);
        } else {
          sprintf(tempID,"%s:%d",NI_SigList[i].blockname,NI_SigList[i].portno+1);
        }

        if (!strcmp(IDblk,tempID) && IDport==(NI_SigList[i].portno+1)) {
          break;
        }

        free(tempID);
      }

      if (i < NI_SigListSize) {
        sigidx = *sidx = i;
      } else {
        return NI_SigListSize;
      }
    } else {
      // no index or ID specified.
      return NI_SigListSize;
    }
  }

  if (sigidx>=0 && sigidx<NI_SigListSize) {
    if (ID != NULL) {
      // no need for return string to be null terminated!
      /* 11 to accomodate ':','/', port number and null character */
      char *tempID = (char *)calloc(strlen(NI_SigList[sigidx].blockname)+strlen
        (NI_SigList[sigidx].signalname)+ 11, sizeof(char));
      if (strlen(NI_SigList[sigidx].signalname)>0) {
        sprintf(tempID,"%s:%d%s%s",NI_SigList[sigidx].blockname,
                NI_SigList[sigidx].portno+1,"/",NI_SigList[sigidx].signalname);
      } else {
        sprintf(tempID,"%s:%d",NI_SigList[sigidx].blockname,NI_SigList[sigidx].
                portno+1);
      }

      if ((int32_t)strlen(tempID)<*ID_len) {
        *ID_len = strlen(tempID);
      }

      strncpy(ID, tempID, *ID_len);
      free(tempID);
    }

    if (blkname != NULL) {
      // no need for return string to be null terminated!
      if ((int32_t)strlen(NI_SigList[sigidx].blockname)<*bnlen) {
        *bnlen = strlen(NI_SigList[sigidx].blockname);
      }

      strncpy(blkname, NI_SigList[sigidx].blockname, *bnlen);
    }

    if (signame != NULL) {
      // no need for return string to be null terminated!
      if ((int32_t)strlen(NI_SigList[sigidx].signalname)<*snlen) {
        *snlen = strlen(NI_SigList[sigidx].signalname);
      }

      strncpy(signame, NI_SigList[sigidx].signalname, *snlen);
    }

    if (portnum != NULL) {
      *portnum = NI_SigList[sigidx].portno;
    }

    if (dattype != NULL) {
      *dattype = NI_SigList[sigidx].datatype;
    }

    if (numdim != NULL) {
      if (*numdim == -1) {
        *numdim = NI_SigList[sigidx].numofdims;
      } else if (dims != NULL) {
        for (i=0;i < *numdim; i++) {
          dims[i] = NI_SigDimList[NI_SigList[sigidx].dimListOffset +i];
        }
      }
    }

    return NI_OK;
  }

  return NI_SigListSize;
}

/*========================================================================*
 * Function: NIRT_GetParameterIndices
 *
 * Abstract:
 *	Returns an array of indices to tunable parameters
 *
 * Output Parameters:
 *	indices	: buffer to store the parameter indices of length "len"
 *	len		: returns the number of indices. If a value of "-1" is specified, the minimum buffer size of "indices" is returned as its value.
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_GetParameterIndices(int32_t* indices, int32_t* len)
{
  int32_t i;
  if ((len == NULL) || (indices == NULL)) {
    return NI_ERROR;
  }

  if (*len == -1) {
    *len = NI_ParamListSize;
  } else {
    for (i=0; (i < NI_ParamListSize) && (i < *len); i++) {
      indices[i] = NI_ParamList[i].idx;
    }

    *len = i;
  }

  return NI_OK;
}

/*========================================================================*
 * Function: NIRT_GetParameterSpec
 *
 * Abstract:
 *	If index == -1, lookup parameter by the ID.
 *	If ID_len == 0 or if ID == null, return number of parameters in model.
 *	Otherwise, lookup parameter by index, and return the information.
 *
 * Input/Output Parameters:
 *	paramidx	: index of the parameter(in/out). If a value of "-1" is specified, the parameter's ID is used instead
 *	ID			: ID of parameter to be looked up (in), ID of parameter at index (out)
 *	ID_len		: length of input ID (in), length of ID (out)
 *	pnlen		: length of buffer paramname(in), length of the returned paramname (out)
 *	numdim		: length of buffer dimension(in), length of output dimension (out). If a value of "-1" is specified, the minimum buffer size of "dims" is returned as its value
 *
 * Output Parameters:
 *	paramname	: Name of the parameter
 *	datatype	: datatype of the parameter (currently assuming 0: double, .. )
 *	dims		: array of dimensions with length 'numdim'
 *
 * Returns:
 *	NI_OK if no error (if paramidx == -1, number of tunable parameters)
 *========================================================================*/
DLL_EXPORT int32_t NIRT_GetParameterSpec(int32_t* pidx, char* ID, int32_t*
  ID_len, char* paramname, int32_t *pnlen,
  int32_t *dattype, int32_t* dims, int32_t* numdim)
{
  int32_t i = 0;
  int32_t paramidx = *pidx;
  if (paramidx < 0) {
    // check if ID has been specified.
    if ((ID != NULL) && (ID_len != NULL) && (*ID_len > 0) ) {
      // lookup the table for matching ID
      for (i=0; i < NI_ParamListSize; i++) {
        if (strcmp(ID,NI_ParamList[i].paramname) == 0) {
          /* found matching string */
          break;
        }
      }

      if (i < NI_ParamListSize) {
        /* note the index into the rtParamAttribs */
        paramidx = *pidx = i;
      } else {
        return NI_ParamListSize;
      }
    } else {
      // no index or ID specified.
      return NI_ParamListSize;
    }
  }

  if ((paramidx >= 0) && (paramidx<NI_ParamListSize)) {
    if (ID != NULL) {
      if ((int32_t)strlen(NI_ParamList[paramidx].paramname) < *ID_len) {
        *ID_len = strlen(NI_ParamList[paramidx].paramname);
      }

      strncpy(ID, NI_ParamList[paramidx].paramname, *ID_len);
    }

    if (paramname != NULL) {
      /* no need for return string to be null terminated! */
      if ((int32_t)strlen(NI_ParamList[paramidx].paramname) < *pnlen) {
        *pnlen = strlen(NI_ParamList[paramidx].paramname);
      }

      strncpy(paramname, NI_ParamList[paramidx].paramname, *pnlen);
    }

    if (dattype != NULL) {
      *dattype = NI_ParamList[paramidx].datatype;
    }

    if (numdim != NULL) {
      if (*numdim == -1) {
        *numdim = NI_ParamList[paramidx].numofdims;
      } else if (dims != NULL) {
        for (i = 0; i < *numdim; i++) {
          dims[i] = NI_ParamDimList[NI_ParamList[paramidx].dimListOffset + i];
        }
      }
    }

    return NI_OK;
  }

  return NI_ParamListSize;
}

/*========================================================================*
 * Function: NIRT_GetExtIOSpec
 *
 * Abstract:
 *	Returns the model's inport or outport specification
 *
 * Input Parameters:
 *	index	: index of the task
 *
 * Output Parameters:
 *	idx		: idx of the IO.
 *	name	: Name of the IO block
 *	tid		: task id
 *	type	: EXT_IN or EXT_OUT
 *	dims	: The port's dimension of length 'numdims'.
 *	numdims : the port's number of dimensions. If a value of "-1" is specified, the minimum buffer size of "dims" is returned as its value.
 *
 * Returns
 *	NI_OK if no error. (if index == -1, return number of tasks in the model)
 *========================================================================*/
DLL_EXPORT int32_t NIRT_GetExtIOSpec(int32_t index, int32_t *idx, char* name,
  int32_t* tid, int32_t *type, int32_t *dims, int32_t* numdims)
{
  if (index == -1) {
    return NI_ExtListSize;
  }

  if (idx != NULL) {
    *idx = NI_ExtList[index].idx;
  }

  if (name != NULL) {
    int32_t sz = strlen(name);
    strncpy(name, NI_ExtList[index].name, sz-1);
    name[sz-1]= 0;
  }

  if (tid != NULL) {
    *tid = NI_ExtList[index].TID;
  }

  if (type != NULL) {
    *type = NI_ExtList[index].type;
  }

  if (numdims != NULL) {
    if (*numdims == -1) {
      *numdims = 2;
    } else if (numdims != NULL) {
      /* Return port dimensions */
      dims[0] = NI_ExtList[index].dimX;
      dims[1] = NI_ExtList[index].dimY;
    }
  }

  return NI_OK;
}

/*========================================================================*
 * Function: NI_ProbeOneSignal
 *
 * Abstract:
 *		Helper function to probe one signal. baseaddr must NOT be VIRTUAL_SIG
 *
 * Output Parameters
 *
 * Returns:
 *     Return value: Returns the last index value probed in a vector signal
 *========================================================================*/
static int32_t NI_ProbeOneSignal(int32_t idx, double *value, int32_t len,
  int32_t *count, int32_t vOffset, int32_t vLength)
{
  if (NI_SigList[idx].baseaddr == VIRTUAL_SIG) {
    SetSITErrorMessage("NI_ProbeOneSignal: Received request to probe a virtual signal, but was expecting a ground source. Ignoring virtual signal probe. Report this behavior to National Instruments.",
                       0);
    return 0;
  } else {
    char *ptr = (char*)((NI_SigList[idx].baseaddr == BLOCKIO_SIG) ? S->blockIO :
                        S->inputs) + (uintptr_t)NI_SigList[idx].addr;
    int32_t subindex = (vLength == -1) ? 0 : vOffset;
    int32_t sublength = (vLength == -1) ? NI_SigList[idx].width : (vLength +
      vOffset);
    while ((subindex < sublength) && (*count < len))
      value[(*count)++] = NIRT_GetValueByDataType(ptr, subindex++,
        NI_SigList[idx].datatype, NI_SigList[idx].IsComplex);
    return *count;
  }
}

/*========================================================================*
 * Function: NIRT_ProbeSignals
 *
 * Abstract:
 *	returns the latest signal values.
 *
 * Input Parameters:
 *	sigindices	: list of signal indices to be probed.
 *	numsigs		: length of sigindices array.
 *
 *		NOTE: (Implementation detail) the sigindices array that is passed in is delimited by a value of -1.
 *		Thus the # of valid indices in the sigindices table is min(numsigs, index of value -1) - 1.
 *		Reason for subtracting 1, the first index in the array is used for bookkeeping and should be copied
 *		into the 0th index in the signal values buffer.
 *		Also, the 1st index in the signal values buffer should contain the current timestamp. Hence valid
 *		signal data should be filled in starting from index 2. Any non-scalar signals should be added to the
 *		buffer in row-order.
 *
 * Input/Output Parameters
 *	num			: (in) length of sigvalues buffer (out) number of values returned in the buffer
 *
 * Output Parameters:
 *	value		: array of signal values
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_ProbeSignals(int32_t* sigindices, int32_t numsigs,
  double* value, int32_t* len)
{
  int32_t i = 0;
  int32_t idx = 0;
  int32_t count = 0;
  if (!SITexportglobals.inCriticalSection) {
    SetSITErrorMessage("SignalProbe should only be called between ScheduleTasks and PostOutputs",
                       1);
  }

  /* Get the index to the first signal */
  if ((*len > 1) && (numsigs > 0)) {
    value[count++] = sigindices[0];
    value[count++] = 0;
  }

  /* Get the second and other signals */
  for (i = 1; (i < numsigs) && (count < *len); i++) {
    idx = sigindices[i];
    if (idx < 0) {
      break;
    }

    if (idx < NI_SigListSize) {
      if (NI_SigList[idx].baseaddr == VIRTUAL_SIG) {
        int32_t vidx = NI_VirtualBlockSources[NI_SigList[idx].addr];
        NI_ProbeOneSignal(vidx, value, *len, &count, 0, -1);
      } else {
        NI_ProbeOneSignal(idx, value, *len, &count, 0, -1);
      }
    }
  }

  *len = count;
  return count;
}

int32_t NI_InitializeParamStruct()
{
  memcpy(&rtParameter[0], &ctrl_DP_P, sizeof(P_ctrl_DP_T));
  return NI_OK;
}

/*  After the model has initialized and updated the parameters in
   rtParameter[0] (aka ctrl_DP_P) we make a copy to rtParameter[1] so
   that it is double buffered. We also do a memcpy to each task's copy.
 */
int32_t NI_InitParamDoubleBuf()
{
  int32_t idx = 1;

#ifdef MULTITASKING

  for (; idx <= NUMST - TID01EQ; idx++)
#endif

    memcpy(&rtParameter[idx], &rtParameter[0], sizeof(P_ctrl_DP_T));
  return NI_OK;
}

static int32_t NI_SetParamTxStatus = NI_OK;

/*========================================================================*
 * Function: NIRT_SetParameter
 *
 * Abstract:
 *	Set parameter value. Called either in scheduler loop or a background loop.
 *
 * Input Parameters:
 *	index	: index of the parameter (as specified in Parameter Information)
 *	subindex: index in the flattened array, if parameter is n-D array
 *	val		: Value to set the parameter to
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_SetParameter(int32_t index, int32_t subindex, double
  value)
{
  char* ptr = NULL;

  /* Check bounds */
  if (index >= NI_ParamListSize) {
    SetSITErrorMessage("Parameter index is out of bounds.", 1);
    return NI_SetParamTxStatus= NI_ERROR;
  }

  /* Commit parameter values */
  if (index < 0) {
    if (ReadSideDirtyFlag == 1) {
      memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof
             (P_ctrl_DP_T));
      ReadSideDirtyFlag = 0;
      if (WriteSideDirtyFlag == 0) {
        /* No values to commit */
        return NI_OK;
      } else {
        SetSITErrorMessage("Parameters have been set inline and from the background loop at the same time. Parameters written from the background loop since the last commit have been lost.",
                           1);
        WriteSideDirtyFlag = 0;
        return NI_ERROR;
      }
    }

    /* If an error occurred and we have values to commit, then save to the write side and return error */
    if (NI_SetParamTxStatus == NI_ERROR) {
      // fail the transaction.
      // copy old list of parameters to the failed TX buffer
      if (WriteSideDirtyFlag == 1) {
        memcpy(&rtParameter[READSIDE], &rtParameter[1-READSIDE], sizeof
               (P_ctrl_DP_T));
      }

      // reset the status.
      NI_SetParamTxStatus = NI_OK;
      WriteSideDirtyFlag = 0;
      return NI_ERROR;
    }

    /* If we have values to commit, then save to the write-side */
    if (WriteSideDirtyFlag == 1) {
      S->defaultParam = (double *)&rtParameter[1-READSIDE];
      WaitForSingleObject(SITexportglobals.flipCriticalSection, INFINITE);
      READSIDE = 1 - READSIDE;
      SITexportglobals.copyTaskBitfield = 0xFFFFFFFF;
      ReleaseSemaphore(SITexportglobals.flipCriticalSection, 1, NULL);

      // Copy back the newly set parameters to the writeside.
      memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof
             (P_ctrl_DP_T));
      WriteSideDirtyFlag = 0;
    }

    return NI_OK;
  }

  // verify that subindex is within bounds.
  if (subindex >= NI_ParamList[index].width) {
    SetSITErrorMessage("Parameter subindex is out of bounds.",1);
    return NI_SetParamTxStatus = NI_ERROR;
  }

  if (ReadSideDirtyFlag == 1) {
    memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof(P_ctrl_DP_T));
    ReadSideDirtyFlag = 0;
  }

  /* Get the parameter's address into the Parameter struct
     casting to char to perform pointer arithmetic using the byte offset */
  ptr = (char *)(&rtParameter[1-READSIDE]) + NI_ParamList[index].addr;
  WriteSideDirtyFlag = 1;

  /* Convert the incoming double datatype to the parameter's internal datatype and update value */
  return NIRT_SetValueByDataType(ptr, subindex, value, NI_ParamList[index].
    datatype, NI_ParamList[index].IsComplex);
}

/*========================================================================*
 * Function: NIRT_SetVectorParameter
 *
 * Abstract:
 *	Sets the value to a parameter array.
 *
 * Input Parameters:
 *	index		: index of the parameter as returned by NIRT_GetParameterSpec()
 *	paramvalues	: array of values to set
 *	paramlength	: Length of parameter values.
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_SetVectorParameter( uint32_t index, const double
  * paramvalues, uint32_t paramlength)
{
  uint32_t i = 0;
  int32_t retval = NI_OK;
  char* ptr = NULL;

  /* verify that index is within bounds*/
  if (index >= (uint32_t)NI_ParamListSize) {
    SetSITErrorMessage("Parameter index is out of bounds.", 1);
    return NI_SetParamTxStatus = NI_ERROR;
  }

  // verify that subindex is within bounds.
  if (paramlength != (uint32_t)NI_ParamList[index].width) {
    SetSITErrorMessage("Parameter length is incorrect.", 1);
    return NI_SetParamTxStatus = NI_ERROR;
  }

  /* If we have pending modified parameters, then copy to write-side */
  if (ReadSideDirtyFlag == 1) {
    memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof(P_ctrl_DP_T));
    ReadSideDirtyFlag = 0;
  }

  /* Get the parameter's address into the Parameter struct
     casting to char to perform pointer arithmetic using the byte offset */
  ptr = (char*)(&rtParameter[1-READSIDE]) + NI_ParamList[index].addr;
  while (i < paramlength) {
    /* Convert the incoming double datatype to the parameter's internal datatype and update value */
    retval = retval & NIRT_SetValueByDataType(ptr, i, paramvalues[i],
      NI_ParamList[index].datatype, NI_ParamList[index].IsComplex);
    i++;
  }

  WriteSideDirtyFlag = 1;
  return retval;
}

/*========================================================================*
 * Function: NIRT_SetScalarParameterInline
 *
 * Abstract:
 *	Sets the value to a parameter immediately without the need of a commit request.
 *
 * Input Parameters:
 *	index		: index of the parameter as returned by NIRT_GetParameterSpec()
 *	subindex	: offset of the element within the parameter
 *	paramvalue	: Value to set the parameter to
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_SetScalarParameterInline( uint32_t index, uint32_t
  subindex, double paramvalue)
{
  char* ptr = NULL;
  if (index >= (uint32_t)NI_ParamListSize) {
    SetSITErrorMessage("Parameter index is out of bounds.", 1);
    return NI_SetParamTxStatus = NI_ERROR;
  }

  // verify that subindex is within bounds.
  if (subindex >= (uint32_t)NI_ParamList[index].width) {
    SetSITErrorMessage("Parameter subindex is out of bounds.", 1);
    return NI_SetParamTxStatus = NI_ERROR;
  }

  /* Get the parameter's address into the Parameter struct
     casting to char to perform pointer arithmetic using the byte offset */
  ptr = (char *)(&rtParameter[READSIDE]) + NI_ParamList[index].addr;
  ReadSideDirtyFlag = 1;

  /* Convert the incoming double datatype to the parameter's internal datatype and update value */
  return NIRT_SetValueByDataType(ptr, subindex, paramvalue, NI_ParamList[index].
    datatype, NI_ParamList[index].IsComplex);
}

/*========================================================================*
 * Function: NIRT_GetParameter
 *
 * Abstract:
 *	Get the current value of a parameter.
 *
 * Input Parameters:
 *	index	: index of the parameter
 *	subindex: element index into the flattened array if an array
 *
 * Output Parameters:
 *	val		: value of the parameter
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_GetParameter(int32_t index, int32_t subindex, double
  *value)
{
  char* ptr = NULL;

  /* Check index boundaries */
  if (index >= NI_ParamListSize || index < 0 || (subindex>=NI_ParamList[index].
       width)) {
    return NI_ERROR;
  }

  /* Get the parameter's address into the Parameter struct
     casting to char to perform pointer arithmetic using the byte offset */
  ptr = (char *)(&rtParameter[READSIDE]) + NI_ParamList[index].addr;

  /* Convert the parameter's internal datatype to double and return its value */
  *value = NIRT_GetValueByDataType(ptr, subindex, NI_ParamList[index].datatype,
    NI_ParamList[index].IsComplex);
  return NI_OK;
}

/*========================================================================*
 * Function: NIRT_GetVectorParameter
 *
 * Abstract:
 *	Get the current value of a vector parameter.
 *
 * Input Parameters:
 *	index: index of the parameter
 *	paramLength: length of the parameter
 *
 * Output Parameters:
 *	paramValues: an array of the parameter's value
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_GetVectorParameter(uint32_t index, double* paramvalues,
  uint32_t paramlength)
{
  char* ptr = NULL;
  uint32_t i = 0;
  if (index >= (uint32_t)NI_ParamListSize || index < 0 || (paramlength !=
       (uint32_t)NI_ParamList[index].width)) {
    return NI_ERROR;
  }

  /* Get the parameter's address into the Parameter struct
     casting to char to perform pointer arithmetic using the byte offset */
  ptr = (char *)(&rtParameter[READSIDE]) + NI_ParamList[index].addr;
  while (i<paramlength) {
    /* Convert the parameter's internal datatype to double and return its value */
    paramvalues[i] = NIRT_GetValueByDataType(ptr, i, NI_ParamList[index].
      datatype, NI_ParamList[index].IsComplex);
    i++;
  }

  return NI_OK;
}

/*========================================================================*
 * Function: NIRT_GetSimState
 *
 * Abstract:
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_GetSimState(int32_t* numContStates, char
  * contStatesNames, double* contStates, int32_t* numDiscStates, char
  * discStatesNames, double* discStates, int32_t* numClockTicks, char
  * clockTicksNames, int32_t* clockTicks)
{
  int32_t count = 0;
  int32_t idx = 0;
  if ((numContStates != NULL) && (numDiscStates != NULL) && (numClockTicks !=
       NULL)) {
    if (*numContStates < 0 || *numDiscStates < 0 || *numClockTicks < 0) {
      *numContStates = 21;
      *numDiscStates = 684;
      *numClockTicks = NUMST - TID01EQ;
      return NI_OK;
    }
  }

  if ((contStates != NULL) && (contStatesNames != NULL)) {
    idx = 0;
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_DP_X.Integrator1_CSTATE), 0,
      0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_DP_X.Integrator1_CSTATE), 1,
      0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_DP_X.Integrator1_CSTATE), 2,
      0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_DP_X.Integrator_CSTATE), 0,
      0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_DP_X.Integrator_CSTATE), 1,
      0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_DP_X.Integrator_CSTATE), 2,
      0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_DP_X.Integrator1_CSTATE_g),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE_g");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_DP_X.Integrator1_CSTATE_g),
      1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE_g");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_DP_X.Integrator1_CSTATE_g),
      2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE_g");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_DP_X.Integrator3_CSTATE), 0,
      0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator3_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_DP_X.Integrator3_CSTATE), 1,
      0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator3_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_DP_X.Integrator3_CSTATE), 2,
      0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator3_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_DP_X.Integrator_CSTATE_l),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_l");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_DP_X.Integrator_CSTATE_l),
      1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_l");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_DP_X.Integrator_CSTATE_l),
      2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_l");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_DP_X.Integrator2_CSTATE), 0,
      0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_DP_X.Integrator2_CSTATE), 1,
      0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_DP_X.Integrator2_CSTATE), 2,
      0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_DP_X.Integrator2_CSTATE_e),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE_e");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_DP_X.Integrator2_CSTATE_e),
      1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE_e");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_DP_X.Integrator2_CSTATE_e),
      2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE_e");
  }

  if ((discStates != NULL) && (discStatesNames != NULL)) {
    idx = 0;
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_p_x_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_p_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_p_y_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_p_y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_p_psi_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_p_psi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_i_psi_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_i_psi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_i_x_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_i_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_i_y_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_i_y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_d_psi_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_d_psi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_d_x_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_d_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_d_y_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_d_y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.x_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.y_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.psi_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.psi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.reset_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.reset_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.w_d_x_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.w_d_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.w_d_y_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.w_d_y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.w_d_psi_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.w_d_psi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.zeta_psi_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.zeta_psi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.zeta_x_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.zeta_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.zeta_y_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.zeta_y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.psi_ref_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.psi_ref_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.x_ref_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.x_ref_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.y_ref_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.y_ref_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.alpha_VSP2_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.alpha_VSP2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.z_m_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.z_m_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.omega_VSP1_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.omega_VSP1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.omega_VSP2_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.omega_VSP2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.alpha_VSP1_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.alpha_VSP1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.u_BT_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.u_BT_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.u_VSP1_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.u_VSP1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.u_VSP2_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.u_VSP2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.Acc_x_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.Acc_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.Acc_y_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.Acc_y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.Acc_z_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.Acc_z_DWORK1");
    for (count = 0; count < 81; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.Memory_PreviousInput,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.Memory_PreviousInput");
    }

    for (count = 0; count < 9; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_DP_DW.Memory1_PreviousInput, count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_DP_DW.Memory1_PreviousInput");
    }

    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.x_est_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.x_est_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.y_est_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.y_est_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.x_hat_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.x_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.y_hat_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.y_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.psi_hat_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.psi_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.u_hat_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.u_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.v_hat_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.v_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.r_hat_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.r_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.u_dot_hat_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.u_dot_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.v_dot_hat_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.v_dot_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.r_dot_hat_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.r_dot_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.b_x_hat_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.b_x_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.b_y_hat_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.b_y_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.b_psi_hat_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.b_psi_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.z_est_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.z_est_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.Gyro_x_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.Gyro_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.Gyro_y_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.Gyro_y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.Gyro_z_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.Gyro_z_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.tau_N_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.tau_N_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.tau_X_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.tau_X_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.tau_Y_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.tau_Y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.psi_tilde_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.psi_tilde_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.x_tilde_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.x_tilde_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.y_tidle_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.y_tidle_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.r_tilde_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.r_tilde_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.u_tilde_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.u_tilde_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.v_tilde_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.v_tilde_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.x_d_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.x_d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.y_d_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.y_d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.psi_d_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.psi_d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.r_d_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.r_d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.u_d_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.u_d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.v_d_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.v_d_DWORK1");
    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_p_x_DWORK2, count,
        21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_p_x_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_p_y_DWORK2, count,
        21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_p_y_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_p_psi_DWORK2,
        count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_p_psi_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_i_psi_DWORK2,
        count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_i_psi_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_i_x_DWORK2, count,
        21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_i_x_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_i_y_DWORK2, count,
        21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_i_y_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_d_psi_DWORK2,
        count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_d_psi_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_d_x_DWORK2, count,
        21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_d_x_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_d_y_DWORK2, count,
        21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_d_y_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.x_DWORK2, count, 21,
        0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.x_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.y_DWORK2, count, 21,
        0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.y_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.psi_DWORK2, count,
        21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.psi_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.reset_DWORK2, count,
        21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.reset_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.w_d_x_DWORK2, count,
        21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.w_d_x_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.w_d_y_DWORK2, count,
        21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.w_d_y_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.w_d_psi_DWORK2,
        count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.w_d_psi_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.zeta_psi_DWORK2,
        count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.zeta_psi_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.zeta_x_DWORK2, count,
        21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.zeta_x_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.zeta_y_DWORK2, count,
        21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.zeta_y_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.psi_ref_DWORK2,
        count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.psi_ref_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.x_ref_DWORK2, count,
        21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.x_ref_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.y_ref_DWORK2, count,
        21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.y_ref_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.alpha_VSP2_DWORK2,
        count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.alpha_VSP2_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.z_m_DWORK2, count,
        21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.z_m_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.omega_VSP1_DWORK2,
        count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.omega_VSP1_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.omega_VSP2_DWORK2,
        count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.omega_VSP2_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.alpha_VSP1_DWORK2,
        count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.alpha_VSP1_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.u_BT_DWORK2, count,
        21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.u_BT_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.u_VSP1_DWORK2, count,
        21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.u_VSP1_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.u_VSP2_DWORK2, count,
        21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.u_VSP2_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.Acc_x_DWORK2, count,
        21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.Acc_x_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.Acc_y_DWORK2, count,
        21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.Acc_y_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.Acc_z_DWORK2, count,
        21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.Acc_z_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.x_est_DWORK2, count,
        21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.x_est_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.y_est_DWORK2, count,
        21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.y_est_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.x_hat_DWORK2, count,
        21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.x_hat_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.y_hat_DWORK2, count,
        21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.y_hat_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.psi_hat_DWORK2,
        count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.psi_hat_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.u_hat_DWORK2, count,
        21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.u_hat_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.v_hat_DWORK2, count,
        21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.v_hat_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.r_hat_DWORK2, count,
        21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.r_hat_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.u_dot_hat_DWORK2,
        count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.u_dot_hat_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.v_dot_hat_DWORK2,
        count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.v_dot_hat_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.r_dot_hat_DWORK2,
        count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.r_dot_hat_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.b_x_hat_DWORK2,
        count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.b_x_hat_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.b_y_hat_DWORK2,
        count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.b_y_hat_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.b_psi_hat_DWORK2,
        count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.b_psi_hat_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.z_est_DWORK2, count,
        21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.z_est_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.Gyro_x_DWORK2, count,
        21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.Gyro_x_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.Gyro_y_DWORK2, count,
        21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.Gyro_y_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.Gyro_z_DWORK2, count,
        21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.Gyro_z_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.tau_N_DWORK2, count,
        21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.tau_N_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.tau_X_DWORK2, count,
        21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.tau_X_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.tau_Y_DWORK2, count,
        21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.tau_Y_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.psi_tilde_DWORK2,
        count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.psi_tilde_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.x_tilde_DWORK2,
        count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.x_tilde_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.y_tidle_DWORK2,
        count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.y_tidle_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.r_tilde_DWORK2,
        count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.r_tilde_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.u_tilde_DWORK2,
        count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.u_tilde_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.v_tilde_DWORK2,
        count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.v_tilde_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.x_d_DWORK2, count,
        21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.x_d_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.y_d_DWORK2, count,
        21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.y_d_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.psi_d_DWORK2, count,
        21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.psi_d_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.r_d_DWORK2, count,
        21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.r_d_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.u_d_DWORK2, count,
        21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.u_d_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.v_d_DWORK2, count,
        21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.v_d_DWORK2");
    }
  }

  if ((clockTicks != NULL) && (clockTicksNames != NULL)) {
    clockTicks[0] = S->Timing.clockTick0;
    strcpy(clockTicksNames, "clockTick0");
  }

  return NI_OK;
}

/*========================================================================*
 * Function: NIRT_SetSimState
 *
 * Abstract:
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_SetSimState(double* contStates, double* discStates,
  int32_t* clockTicks)
{
  int32_t count = 0;
  int32_t idx = 0;
  if (contStates != NULL) {
    idx = 0;
    NIRT_SetValueByDataType(&(ctrl_DP_X.Integrator1_CSTATE), 0, contStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_X.Integrator1_CSTATE), 1, contStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_X.Integrator1_CSTATE), 2, contStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_X.Integrator_CSTATE), 0, contStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_X.Integrator_CSTATE), 1, contStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_X.Integrator_CSTATE), 2, contStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_X.Integrator1_CSTATE_g), 0, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_X.Integrator1_CSTATE_g), 1, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_X.Integrator1_CSTATE_g), 2, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_X.Integrator3_CSTATE), 0, contStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_X.Integrator3_CSTATE), 1, contStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_X.Integrator3_CSTATE), 2, contStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_X.Integrator_CSTATE_l), 0, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_X.Integrator_CSTATE_l), 1, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_X.Integrator_CSTATE_l), 2, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_X.Integrator2_CSTATE), 0, contStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_X.Integrator2_CSTATE), 1, contStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_X.Integrator2_CSTATE), 2, contStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_X.Integrator2_CSTATE_e), 0, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_X.Integrator2_CSTATE_e), 1, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_X.Integrator2_CSTATE_e), 2, contStates[idx
      ++], 0, 0);
  }

  if (discStates != NULL) {
    idx = 0;
    NIRT_SetValueByDataType(&ctrl_DP_DW.K_p_x_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.K_p_y_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.K_p_psi_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.K_i_psi_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.K_i_x_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.K_i_y_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.K_d_psi_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.K_d_x_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.K_d_y_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.x_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.y_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.psi_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.reset_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.w_d_x_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.w_d_y_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.w_d_psi_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.zeta_psi_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.zeta_x_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.zeta_y_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.psi_ref_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.x_ref_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.y_ref_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.alpha_VSP2_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.z_m_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.omega_VSP1_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.omega_VSP2_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.alpha_VSP1_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.u_BT_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.u_VSP1_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.u_VSP2_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.Acc_x_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.Acc_y_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.Acc_z_DWORK1, 0, discStates[idx++], 0, 0);
    for (count = 0; count < 81; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.Memory_PreviousInput, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 9; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.Memory1_PreviousInput, count,
        discStates[idx++], 24, 0);
    }

    NIRT_SetValueByDataType(&ctrl_DP_DW.x_est_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.y_est_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.x_hat_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.y_hat_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.psi_hat_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.u_hat_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.v_hat_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.r_hat_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.u_dot_hat_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.v_dot_hat_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.r_dot_hat_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.b_x_hat_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.b_y_hat_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.b_psi_hat_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.z_est_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.Gyro_x_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.Gyro_y_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.Gyro_z_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.tau_N_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.tau_X_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.tau_Y_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.psi_tilde_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.x_tilde_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.y_tidle_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.r_tilde_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.u_tilde_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.v_tilde_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.x_d_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.y_d_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.psi_d_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.r_d_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.u_d_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.v_d_DWORK1, 0, discStates[idx++], 0, 0);
    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.K_p_x_DWORK2, count, discStates[idx++],
        21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.K_p_y_DWORK2, count, discStates[idx++],
        21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.K_p_psi_DWORK2, count, discStates[idx
        ++], 21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.K_i_psi_DWORK2, count, discStates[idx
        ++], 21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.K_i_x_DWORK2, count, discStates[idx++],
        21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.K_i_y_DWORK2, count, discStates[idx++],
        21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.K_d_psi_DWORK2, count, discStates[idx
        ++], 21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.K_d_x_DWORK2, count, discStates[idx++],
        21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.K_d_y_DWORK2, count, discStates[idx++],
        21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.x_DWORK2, count, discStates[idx++], 21,
        0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.y_DWORK2, count, discStates[idx++], 21,
        0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.psi_DWORK2, count, discStates[idx++],
        21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.reset_DWORK2, count, discStates[idx++],
        21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.w_d_x_DWORK2, count, discStates[idx++],
        21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.w_d_y_DWORK2, count, discStates[idx++],
        21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.w_d_psi_DWORK2, count, discStates[idx
        ++], 21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.zeta_psi_DWORK2, count, discStates[idx
        ++], 21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.zeta_x_DWORK2, count, discStates[idx++],
        21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.zeta_y_DWORK2, count, discStates[idx++],
        21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.psi_ref_DWORK2, count, discStates[idx
        ++], 21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.x_ref_DWORK2, count, discStates[idx++],
        21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.y_ref_DWORK2, count, discStates[idx++],
        21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.alpha_VSP2_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.z_m_DWORK2, count, discStates[idx++],
        21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.omega_VSP1_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.omega_VSP2_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.alpha_VSP1_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.u_BT_DWORK2, count, discStates[idx++],
        21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.u_VSP1_DWORK2, count, discStates[idx++],
        21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.u_VSP2_DWORK2, count, discStates[idx++],
        21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.Acc_x_DWORK2, count, discStates[idx++],
        21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.Acc_y_DWORK2, count, discStates[idx++],
        21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.Acc_z_DWORK2, count, discStates[idx++],
        21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.x_est_DWORK2, count, discStates[idx++],
        21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.y_est_DWORK2, count, discStates[idx++],
        21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.x_hat_DWORK2, count, discStates[idx++],
        21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.y_hat_DWORK2, count, discStates[idx++],
        21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.psi_hat_DWORK2, count, discStates[idx
        ++], 21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.u_hat_DWORK2, count, discStates[idx++],
        21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.v_hat_DWORK2, count, discStates[idx++],
        21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.r_hat_DWORK2, count, discStates[idx++],
        21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.u_dot_hat_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.v_dot_hat_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.r_dot_hat_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.b_x_hat_DWORK2, count, discStates[idx
        ++], 21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.b_y_hat_DWORK2, count, discStates[idx
        ++], 21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.b_psi_hat_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.z_est_DWORK2, count, discStates[idx++],
        21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.Gyro_x_DWORK2, count, discStates[idx++],
        21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.Gyro_y_DWORK2, count, discStates[idx++],
        21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.Gyro_z_DWORK2, count, discStates[idx++],
        21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.tau_N_DWORK2, count, discStates[idx++],
        21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.tau_X_DWORK2, count, discStates[idx++],
        21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.tau_Y_DWORK2, count, discStates[idx++],
        21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.psi_tilde_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.x_tilde_DWORK2, count, discStates[idx
        ++], 21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.y_tidle_DWORK2, count, discStates[idx
        ++], 21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.r_tilde_DWORK2, count, discStates[idx
        ++], 21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.u_tilde_DWORK2, count, discStates[idx
        ++], 21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.v_tilde_DWORK2, count, discStates[idx
        ++], 21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.x_d_DWORK2, count, discStates[idx++],
        21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.y_d_DWORK2, count, discStates[idx++],
        21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.psi_d_DWORK2, count, discStates[idx++],
        21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.r_d_DWORK2, count, discStates[idx++],
        21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.u_d_DWORK2, count, discStates[idx++],
        21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.v_d_DWORK2, count, discStates[idx++],
        21, 0);
    }
  }

  if (clockTicks != NULL) {
    S->Timing.clockTick0 = clockTicks[0];
    S->Timing.clockTick1 = clockTicks[0];
  }

  return NI_OK;
}

#endif                                 // of NI_ROOTMODEL_ctrl_DP
