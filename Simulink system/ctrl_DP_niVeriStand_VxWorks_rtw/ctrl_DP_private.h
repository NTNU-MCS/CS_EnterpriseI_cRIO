/*
 * ctrl_DP_private.h
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

#ifndef RTW_HEADER_ctrl_DP_private_h_
#define RTW_HEADER_ctrl_DP_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "ctrl_DP.h"

extern real_T rt_roundd_snf(real_T u);
extern real_T rt_remd_snf(real_T u0, real_T u1);
extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern void ctrl_DP_MATLABFunction(real_T rtu_K_p1, real_T rtu_K_p1_e, real_T
  rtu_K_p1_f, B_MATLABFunction_ctrl_DP_T *localB);
extern void ctrl_DP_MATLABFunction1(real_T rtu_K_i1, real_T rtu_K_i1_m, real_T
  rtu_K_i1_n, B_MATLABFunction1_ctrl_DP_T *localB);
extern void ctrl_DP_MATLABFunction2(real_T rtu_K_d1, real_T rtu_K_d1_p, real_T
  rtu_K_d1_i, B_MATLABFunction2_ctrl_DP_T *localB);

/* private model entry point functions */
extern void ctrl_DP_derivatives(void);

#endif                                 /* RTW_HEADER_ctrl_DP_private_h_ */
