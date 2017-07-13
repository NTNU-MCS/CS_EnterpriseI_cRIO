#include "ni_modelframework.h"
#if defined VXWORKS || defined kNIOSLinux
#define u2pwm_P                        u2pwm_P DataSection(".NIVS.defaultparams")
#endif

/*
 * u2pwm_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "u2pwm".
 *
 * Model version              : 1.51
 * Simulink Coder version : 8.11 (R2016b) 25-Aug-2016
 * C source code generated on : Thu Jul 13 11:58:15 2017
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "u2pwm.h"
#include "u2pwm_private.h"

/* Block parameters (auto storage) */
P_u2pwm_T u2pwm_P = {
  0.34999999999999964,                 /* Variable: BT_u2pwm_gain
                                        * Referenced by: '<S13>/VPS_Speed_Gain1'
                                        */
  7.5,                                 /* Variable: BT_zero_pwm
                                        * Referenced by: '<S16>/Constant'
                                        */
  7.3,                                 /* Variable: BT_zero_pwm_neg
                                        * Referenced by: '<S15>/Constant'
                                        */
  7.8,                                 /* Variable: BT_zero_pwm_pos
                                        * Referenced by: '<S14>/Constant'
                                        */
  1.8900000000000001,                  /* Variable: VSP_u2pwm_gain
                                        * Referenced by:
                                        *   '<S10>/VPS_Speed_Gain'
                                        *   '<S10>/VPS_Speed_Gain2'
                                        */
  5.01,                                /* Variable: VSP_zero_pwm
                                        * Referenced by: '<S10>/VPS_Power_Offset'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/Triangle'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/Triangle'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/Triangle'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/Triangle'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/Triangle'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/Triangle'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/Circle'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/Circle'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/Circle'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/Circle'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/Circle'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/Circle'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/Cross'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/Cross'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/Cross'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/Cross'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/Cross'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/Cross'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/Square'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/Square'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/Square'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/Square'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/Square'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/Square'
                                        */
  4.0,                                 /* Expression: 4
                                        * Referenced by: '<S2>/Memory'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/u_BT'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/u_BT'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/u_BT'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/u_BT'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/u_BT'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/u_BT'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/u_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/u_VSP2'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/u_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/u_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/u_VSP2'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/u_VSP2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/omega_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/omega_VSP1'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/omega_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/omega_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/omega_VSP1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/omega_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/omega_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/omega_VSP2'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/omega_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/omega_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/omega_VSP2'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/omega_VSP2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/u_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/u_VSP1'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/u_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/u_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/u_VSP1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/u_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/alpha_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/alpha_VSP1'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/alpha_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/alpha_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/alpha_VSP1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/alpha_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/alpha_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/alpha_VSP2'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/alpha_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/alpha_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/alpha_VSP2'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/alpha_VSP2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/u_BT'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/u_BT'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/u_BT'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/u_BT'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/u_BT'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/u_BT'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/u_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/u_VSP2'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/u_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/u_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/u_VSP2'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/u_VSP2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/omega_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/omega_VSP1'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/omega_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/omega_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/omega_VSP1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/omega_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/omega_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/omega_VSP2'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/omega_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/omega_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/omega_VSP2'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/omega_VSP2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/u_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/u_VSP1'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/u_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/u_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/u_VSP1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/u_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/alpha_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/alpha_VSP1'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/alpha_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/alpha_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/alpha_VSP1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/alpha_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/alpha_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/alpha_VSP2'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/alpha_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/alpha_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/alpha_VSP2'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/alpha_VSP2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Constant1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Constant2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Constant3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Constant4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Constant5'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Constant6'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/u_BT'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/u_BT'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S6>/u_BT'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/u_BT'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/u_BT'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/u_BT'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/u_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/u_VSP2'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S6>/u_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/u_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/u_VSP2'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/u_VSP2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/omega_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/omega_VSP1'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S6>/omega_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/omega_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/omega_VSP1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/omega_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/omega_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/omega_VSP2'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S6>/omega_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/omega_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/omega_VSP2'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/omega_VSP2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/u_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/u_VSP1'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S6>/u_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/u_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/u_VSP1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/u_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/alpha_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/alpha_VSP1'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S6>/alpha_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/alpha_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/alpha_VSP1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/alpha_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/alpha_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/alpha_VSP2'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S6>/alpha_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/alpha_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/alpha_VSP2'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/alpha_VSP2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/control input u exceeds bounds'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/control input u exceeds bounds'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/control input u exceeds bounds'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/control input u exceeds bounds'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/control input u exceeds bounds'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/control input u exceeds bounds'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/ctrl_custom'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/ctrl_custom'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/ctrl_custom'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/ctrl_custom'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/ctrl_custom'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/ctrl_custom'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/ctrl_DP'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/ctrl_DP'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/ctrl_DP'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/ctrl_DP'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/ctrl_DP'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/ctrl_DP'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/STOP'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/STOP'
                                        */
  10.0,                                /* Expression: portnum
                                        * Referenced by: '<S8>/STOP'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/STOP'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/STOP'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/STOP'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/ctrl_sixaxis2thruster'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/ctrl_sixaxis2thruster'
                                        */
  11.0,                                /* Expression: portnum
                                        * Referenced by: '<S8>/ctrl_sixaxis2thruster'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/ctrl_sixaxis2thruster'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/ctrl_sixaxis2thruster'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/ctrl_sixaxis2thruster'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/Integrator6'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/Integrator5'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/Integrator4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/Integrator3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/Integrator2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/Integrator1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/Integrator'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/enable_mech_el'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/enable_mech_el'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/enable_mech_el'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/enable_mech_el'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/enable_mech_el'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/enable_mech_el'
                                        */
  0.4,                                 /* Expression: 0.4
                                        * Referenced by: '<S10>/Saturation8'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/Saturation8'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/pwm_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/pwm_VSP1'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/pwm_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/pwm_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/pwm_VSP1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/pwm_VSP1'
                                        */
  0.4,                                 /* Expression: 0.4
                                        * Referenced by: '<S10>/Saturation9'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/Saturation9'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/pwm_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/pwm_VSP2'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/pwm_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/pwm_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/pwm_VSP2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/pwm_VSP2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S13>/Integrator'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/pwm_BT'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/pwm_BT'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/pwm_BT'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/pwm_BT'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/pwm_BT'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/pwm_BT'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S10>/Saturation10'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/Saturation10'
                                        */
  0.95,                                /* Expression: .95
                                        * Referenced by: '<S10>/Gain5'
                                        */
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S10>/Saturation1'
                                        */
  -3.1415926535897931,                 /* Expression: -pi
                                        * Referenced by: '<S10>/Saturation1'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S10>/Gain3'
                                        */

  /*  Expression: servo_mapping(:,:,4)
   * Referenced by: '<S10>/2-D Lookup Table3'
   */
  { 5.8, 6.0050252531694168, 6.5, 6.2878679656440362, 6.2, 5.5363961030678928,
    5.5686143571373723, 6.0635891039679564, 5.8514570696119916,
    5.9656854249492381, 4.9, 4.93221825406948, 5.01, 5.2857716446627538, 5.4,
    4.4757359312880718, 4.5079541853575513, 4.1544007947642774,
    4.6493755415948606, 4.7636038969321071, 4.3, 4.1535533905932738, 3.8,
    4.294974746830583, 4.5 },

  /*  Expression: [-1,-0.7071067811865476,0,0.7071067811865476,1]
   * Referenced by: '<S10>/2-D Lookup Table3'
   */
  { -1.0, -0.70710678118654757, 0.0, 0.70710678118654757, 1.0 },

  /*  Expression: [-1,-0.7071067811865476,0,0.7071067811865476,1]
   * Referenced by: '<S10>/2-D Lookup Table3'
   */
  { -1.0, -0.70710678118654757, 0.0, 0.70710678118654757, 1.0 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/pwm_servo4'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/pwm_servo4'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/pwm_servo4'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/pwm_servo4'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/pwm_servo4'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/pwm_servo4'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S10>/Gain2'
                                        */

  /*  Expression: servo_mapping(:,:,3)
   * Referenced by: '<S10>/2-D Lookup Table2'
   */
  { 5.5, 5.2363961030678929, 4.6, 4.1757359312880711, 4.0, 5.646446609406726,
    5.2920458146424485, 4.6556497115745561, 4.2313856428626275, 4.0, 6.0,
    5.6455992052357225, 4.79, 4.2313856428626275, 4.0, 5.9292893218813454,
    5.5748885271170678, 4.9384924240491745, 4.4435176772185914,
    4.2121320343559638, 5.9, 5.6363961030678933, 5.0, 4.5050252531694168, 4.3 },

  /*  Expression: [-1,-0.7071067811865476,0,0.7071067811865476,1]
   * Referenced by: '<S10>/2-D Lookup Table2'
   */
  { -1.0, -0.70710678118654757, 0.0, 0.70710678118654757, 1.0 },

  /*  Expression: [-1,-0.7071067811865476,0,0.7071067811865476,1]
   * Referenced by: '<S10>/2-D Lookup Table2'
   */
  { -1.0, -0.70710678118654757, 0.0, 0.70710678118654757, 1.0 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/pwm_servo3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/pwm_servo3'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/pwm_servo3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/pwm_servo3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/pwm_servo3'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/pwm_servo3'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S10>/Saturation11'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/Saturation11'
                                        */
  0.95,                                /* Expression: .95
                                        * Referenced by: '<S10>/Gain4'
                                        */
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S10>/Saturation'
                                        */
  -3.1415926535897931,                 /* Expression: -pi
                                        * Referenced by: '<S10>/Saturation'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S10>/Gain'
                                        */

  /*  Expression: servo_mapping(:,:,1)
   * Referenced by: '<S10>/2-D Lookup Table'
   */
  { 5.9, 5.6949747468305834, 5.2, 5.412132034355964, 5.5, 6.1636038969321074,
    6.102096320981282, 5.6071215741506988, 5.8192536085066635,
    5.7636038969321071, 6.8, 6.7384924240491753, 6.59, 6.4556497115745559, 6.4,
    7.3656854249492376, 7.304177848998413, 7.4455992052357223, 7.304177848998413,
    7.2485281374238566, 7.6, 7.6585786437626906, 7.8, 7.6585786437626906, 7.6 },

  /*  Expression: [-1,-0.7071067811865476,0,0.7071067811865476,1]
   * Referenced by: '<S10>/2-D Lookup Table'
   */
  { -1.0, -0.70710678118654757, 0.0, 0.70710678118654757, 1.0 },

  /*  Expression: [-1,-0.7071067811865476,0,0.7071067811865476,1]
   * Referenced by: '<S10>/2-D Lookup Table'
   */
  { -1.0, -0.70710678118654757, 0.0, 0.70710678118654757, 1.0 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/pwm_servo1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/pwm_servo1'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/pwm_servo1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/pwm_servo1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/pwm_servo1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/pwm_servo1'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S10>/Gain1'
                                        */

  /*  Expression: servo_mapping(:,:,2)
   * Referenced by: '<S10>/2-D Lookup Table1'
   */
  { 6.8, 6.5363961030678928, 5.9, 5.4757359312880718, 5.3, 6.9171572875253808,
    6.6213351365237942, 5.9849390334559018, 5.5606749647439724,
    5.2414213562373089, 7.2, 6.9041778489984136, 6.19, 5.4192536085066632, 5.1,
    7.1292893218813447, 6.8334671708797581, 6.4092031021678295,
    5.7728069990999371, 5.4535533905932736, 7.1, 6.9242640687119286, 6.5,
    5.8636038969321067, 5.6 },

  /*  Expression: [-1,-0.7071067811865476,0,0.7071067811865476,1]
   * Referenced by: '<S10>/2-D Lookup Table1'
   */
  { -1.0, -0.70710678118654757, 0.0, 0.70710678118654757, 1.0 },

  /*  Expression: [-1,-0.7071067811865476,0,0.7071067811865476,1]
   * Referenced by: '<S10>/2-D Lookup Table1'
   */
  { -1.0, -0.70710678118654757, 0.0, 0.70710678118654757, 1.0 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/pwm_servo2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/pwm_servo2'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/pwm_servo2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/pwm_servo2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/pwm_servo2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/pwm_servo2'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S10>/Saturation7'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S10>/Saturation7'
                                        */
  3.0,                                 /* Expression: 3
                                        * Referenced by: '<S13>/Gain6'
                                        */

  /*  Computed Parameter: uDLookupTable3_maxIndex
   * Referenced by: '<S10>/2-D Lookup Table3'
   */
  { 4U, 4U },

  /*  Computed Parameter: uDLookupTable2_maxIndex
   * Referenced by: '<S10>/2-D Lookup Table2'
   */
  { 4U, 4U },

  /*  Computed Parameter: uDLookupTable_maxIndex
   * Referenced by: '<S10>/2-D Lookup Table'
   */
  { 4U, 4U },

  /*  Computed Parameter: uDLookupTable1_maxIndex
   * Referenced by: '<S10>/2-D Lookup Table1'
   */
  { 4U, 4U }
};

/*========================================================================*
 * NI VeriStand Model Framework code generation
 *
 * Model : u2pwm
 * Model version : 1.51
 * VeriStand Model Framework version : 2017.0.0.143 (2017)
 * Source generated on : Thu Jul 13 11:58:15 2017
 *========================================================================*/
#if defined VXWORKS || defined kNIOSLinux

typedef struct {
  int32_t size;
  int32_t width;
  int32_t basetype;
} NI_ParamSizeWidth;

NI_ParamSizeWidth P_u2pwm_T_sizes[] DataSection(".NIVS.defaultparamsizes") = {
  { sizeof(P_u2pwm_T), 1 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 25, 0 },

  { sizeof(real_T), 5, 0 },

  { sizeof(real_T), 5, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 25, 0 },

  { sizeof(real_T), 5, 0 },

  { sizeof(real_T), 5, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 25, 0 },

  { sizeof(real_T), 5, 0 },

  { sizeof(real_T), 5, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 25, 0 },

  { sizeof(real_T), 5, 0 },

  { sizeof(real_T), 5, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(uint32_T), 2, 7 },

  { sizeof(uint32_T), 2, 7 },

  { sizeof(uint32_T), 2, 7 },

  { sizeof(uint32_T), 2, 7 },
};

#endif
