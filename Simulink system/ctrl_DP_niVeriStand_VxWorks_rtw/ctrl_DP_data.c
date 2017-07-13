#include "ni_modelframework.h"
#if defined VXWORKS || defined kNIOSLinux
#define ctrl_DP_P                      ctrl_DP_P DataSection(".NIVS.defaultparams")
#endif

/*
 * ctrl_DP_data.c
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

/* Block parameters (auto storage) */
P_ctrl_DP_T ctrl_DP_P = {
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S25>/K_p_x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S25>/K_p_x'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S25>/K_p_x'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S25>/K_p_x'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S25>/K_p_x'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S25>/K_p_x'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S25>/K_p_y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S25>/K_p_y'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S25>/K_p_y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S25>/K_p_y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S25>/K_p_y'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S25>/K_p_y'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S25>/K_p_psi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S25>/K_p_psi'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S25>/K_p_psi'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S25>/K_p_psi'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S25>/K_p_psi'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S25>/K_p_psi'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S25>/K_i_psi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S25>/K_i_psi'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S25>/K_i_psi'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S25>/K_i_psi'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S25>/K_i_psi'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S25>/K_i_psi'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S25>/K_i_x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S25>/K_i_x'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S25>/K_i_x'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S25>/K_i_x'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S25>/K_i_x'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S25>/K_i_x'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S25>/K_i_y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S25>/K_i_y'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S25>/K_i_y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S25>/K_i_y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S25>/K_i_y'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S25>/K_i_y'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S25>/K_d_psi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S25>/K_d_psi'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S25>/K_d_psi'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S25>/K_d_psi'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S25>/K_d_psi'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S25>/K_d_psi'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S25>/K_d_x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S25>/K_d_x'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S25>/K_d_x'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S25>/K_d_x'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S25>/K_d_x'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S25>/K_d_x'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S25>/K_d_y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S25>/K_d_y'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<S25>/K_d_y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S25>/K_d_y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S25>/K_d_y'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S25>/K_d_y'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/x'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/x'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/x'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/x'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/x'
                                        */
  0.001,                               /* Expression: 1/1000
                                        * Referenced by: '<S10>/mm2m'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/y'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/y'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/y'
                                        */
  0.001,                               /* Expression: 1/1000
                                        * Referenced by: '<S10>/mm2m '
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/psi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/psi'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/psi'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/psi'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/psi'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/psi'
                                        */
  0.017453292519943295,                /* Expression: pi/180
                                        * Referenced by: '<S10>/Gain5'
                                        */
  1.0E+10,                             /* Expression: 1e10
                                        * Referenced by: '<S10>/Saturation'
                                        */
  -1.0E+10,                            /* Expression: -1e10
                                        * Referenced by: '<S10>/Saturation'
                                        */
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S10>/Gain6'
                                        */
  6.2831853071795862,                  /* Expression: 2*pi
                                        * Referenced by: '<S10>/Constant1'
                                        */
  1.0E+10,                             /* Expression: 1e10
                                        * Referenced by: '<S17>/Saturation'
                                        */
  -1.0E+10,                            /* Expression: -1e10
                                        * Referenced by: '<S17>/Saturation'
                                        */
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S17>/Gain'
                                        */
  6.2831853071795862,                  /* Expression: 2*pi
                                        * Referenced by: '<S17>/Constant'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/reset'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/reset'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/reset'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/reset'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/reset'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/reset'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S27>/Constant6'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S27>/Constant7'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S27>/Constant8'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S26>/w_d_x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S26>/w_d_x'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S26>/w_d_x'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S26>/w_d_x'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S26>/w_d_x'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S26>/w_d_x'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S26>/w_d_y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S26>/w_d_y'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S26>/w_d_y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S26>/w_d_y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S26>/w_d_y'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S26>/w_d_y'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S26>/w_d_psi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S26>/w_d_psi'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S26>/w_d_psi'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S26>/w_d_psi'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S26>/w_d_psi'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S26>/w_d_psi'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S26>/zeta_psi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S26>/zeta_psi'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S26>/zeta_psi'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S26>/zeta_psi'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S26>/zeta_psi'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S26>/zeta_psi'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S26>/zeta_x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S26>/zeta_x'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S26>/zeta_x'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S26>/zeta_x'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S26>/zeta_x'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S26>/zeta_x'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S26>/zeta_y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S26>/zeta_y'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S26>/zeta_y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S26>/zeta_y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S26>/zeta_y'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S26>/zeta_y'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/psi_ref'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/psi_ref'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/psi_ref'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/psi_ref'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/psi_ref'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/psi_ref'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/x_ref'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/x_ref'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/x_ref'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/x_ref'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/x_ref'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/x_ref'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/y_ref'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/y_ref'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/y_ref'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/y_ref'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/y_ref'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/y_ref'
                                        */
  1.0E+10,                             /* Expression: 1e10
                                        * Referenced by: '<S19>/Saturation'
                                        */
  -1.0E+10,                            /* Expression: -1e10
                                        * Referenced by: '<S19>/Saturation'
                                        */
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S19>/Gain'
                                        */
  6.2831853071795862,                  /* Expression: 2*pi
                                        * Referenced by: '<S19>/Constant'
                                        */
  1.0E+10,                             /* Expression: 1e10
                                        * Referenced by: '<S16>/Saturation'
                                        */
  -1.0E+10,                            /* Expression: -1e10
                                        * Referenced by: '<S16>/Saturation'
                                        */
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S16>/Gain'
                                        */
  6.2831853071795862,                  /* Expression: 2*pi
                                        * Referenced by: '<S16>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S13>/Integrator'
                                        */

  /*  Expression: [0 0 0]'
   * Referenced by: '<S8>/Integrator1'
   */
  { 0.0, 0.0, 0.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S18>/Integrator3'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Constant'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/alpha_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/alpha_VSP2'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/alpha_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/alpha_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/alpha_VSP2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/alpha_VSP2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/z_m'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/z_m'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/z_m'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/z_m'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/z_m'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/z_m'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/omega_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/omega_VSP1'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/omega_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/omega_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/omega_VSP1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/omega_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/omega_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/omega_VSP2'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/omega_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/omega_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/omega_VSP2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/omega_VSP2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/alpha_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/alpha_VSP1'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/alpha_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/alpha_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/alpha_VSP1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/alpha_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/u_BT'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/u_BT'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/u_BT'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/u_BT'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/u_BT'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/u_BT'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/u_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/u_VSP1'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/u_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/u_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/u_VSP1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/u_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/u_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/u_VSP2'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/u_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/u_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/u_VSP2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/u_VSP2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/Acc_x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/Acc_x'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S6>/Acc_x'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/Acc_x'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/Acc_x'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/Acc_x'
                                        */
  -9.81,                               /* Expression: -9.81
                                        * Referenced by: '<S6>/Gain'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/Acc_y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/Acc_y'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S6>/Acc_y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/Acc_y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/Acc_y'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/Acc_y'
                                        */
  -9.81,                               /* Expression: -9.81
                                        * Referenced by: '<S6>/Gain1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/Acc_z'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/Acc_z'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S6>/Acc_z'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/Acc_z'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/Acc_z'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/Acc_z'
                                        */
  -9.81,                               /* Expression: -9.81
                                        * Referenced by: '<S6>/Gain2'
                                        */

  /*  Expression: eye(9)
   * Referenced by: '<Root>/Memory'
   */
  { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0 },

  /*  Expression: zeros(9,1)
   * Referenced by: '<Root>/Memory1'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/x_est'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/x_est'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/x_est'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/x_est'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/x_est'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/x_est'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/y_est'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/y_est'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/y_est'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/y_est'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/y_est'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/y_est'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S44>/x_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S44>/x_hat'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S44>/x_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S44>/x_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S44>/x_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S44>/x_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S44>/y_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S44>/y_hat'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S44>/y_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S44>/y_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S44>/y_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S44>/y_hat'
                                        */
  1.0E+10,                             /* Expression: 1e10
                                        * Referenced by: '<S41>/Saturation'
                                        */
  -1.0E+10,                            /* Expression: -1e10
                                        * Referenced by: '<S41>/Saturation'
                                        */
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S41>/Gain'
                                        */
  6.2831853071795862,                  /* Expression: 2*pi
                                        * Referenced by: '<S41>/Constant'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S44>/psi_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S44>/psi_hat'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S44>/psi_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S44>/psi_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S44>/psi_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S44>/psi_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S46>/u_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S46>/u_hat'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S46>/u_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S46>/u_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S46>/u_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S46>/u_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S46>/v_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S46>/v_hat'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S46>/v_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S46>/v_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S46>/v_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S46>/v_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S46>/r_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S46>/r_hat'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S46>/r_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S46>/r_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S46>/r_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S46>/r_hat'
                                        */
  1.0E+10,                             /* Expression: 1e10
                                        * Referenced by: '<S42>/Saturation'
                                        */
  -1.0E+10,                            /* Expression: -1e10
                                        * Referenced by: '<S42>/Saturation'
                                        */
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S42>/Gain'
                                        */
  6.2831853071795862,                  /* Expression: 2*pi
                                        * Referenced by: '<S42>/Constant'
                                        */

  /*  Expression: [0 0 0]'
   * Referenced by: '<S8>/Integrator2'
   */
  { 0.0, 0.0, 0.0 },

  /*  Expression: M^-1
   * Referenced by: '<S8>/M^-1'
   */
  { 0.062073246430788334, 0.0, -0.0, 0.0, 0.041651810141086335,
    -0.0079851500148196766, -0.0, -0.0079851500148196766, 0.36384968931217082 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S45>/u_dot_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S45>/u_dot_hat'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S45>/u_dot_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S45>/u_dot_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S45>/u_dot_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S45>/u_dot_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S45>/v_dot_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S45>/v_dot_hat'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S45>/v_dot_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S45>/v_dot_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S45>/v_dot_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S45>/v_dot_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S45>/r_dot_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S45>/r_dot_hat'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S45>/r_dot_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S45>/r_dot_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S45>/r_dot_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S45>/r_dot_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S43>/b_x_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S43>/b_x_hat'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S43>/b_x_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S43>/b_x_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S43>/b_x_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S43>/b_x_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S43>/b_y_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S43>/b_y_hat'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S43>/b_y_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S43>/b_y_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S43>/b_y_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S43>/b_y_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S43>/b_psi_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S43>/b_psi_hat'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S43>/b_psi_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S43>/b_psi_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S43>/b_psi_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S43>/b_psi_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/z_est'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/z_est'
                                        */
  10.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/z_est'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/z_est'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/z_est'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/z_est'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S18>/Integrator2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/Gyro_x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/Gyro_x'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S6>/Gyro_x'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/Gyro_x'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/Gyro_x'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/Gyro_x'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/Gyro_y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/Gyro_y'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S6>/Gyro_y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/Gyro_y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/Gyro_y'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/Gyro_y'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/Gyro_z'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/Gyro_z'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S6>/Gyro_z'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/Gyro_z'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/Gyro_z'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/Gyro_z'
                                        */
  50.0,                                /* Expression: 50
                                        * Referenced by: '<S27>/Constant'
                                        */
  50.0,                                /* Expression: 50
                                        * Referenced by: '<S27>/Constant1'
                                        */
  50.0,                                /* Expression: 50
                                        * Referenced by: '<S27>/Constant2'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S27>/Constant3'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S27>/Constant4'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S27>/Constant5'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/tau_N'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/tau_N'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/tau_N'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/tau_N'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/tau_N'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/tau_N'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/tau_X'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/tau_X'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/tau_X'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/tau_X'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/tau_X'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/tau_X'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/tau_Y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/tau_Y'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/tau_Y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/tau_Y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/tau_Y'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/tau_Y'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/psi_tilde'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/psi_tilde'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/psi_tilde'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/psi_tilde'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/psi_tilde'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/psi_tilde'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/x_tilde'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/x_tilde'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/x_tilde'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/x_tilde'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/x_tilde'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/x_tilde'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/y_tidle'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/y_tidle'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/y_tidle'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/y_tidle'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/y_tidle'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/y_tidle'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/r_tilde'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/r_tilde'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/r_tilde'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/r_tilde'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/r_tilde'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/r_tilde'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/u_tilde'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/u_tilde'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/u_tilde'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/u_tilde'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/u_tilde'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/u_tilde'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/v_tilde'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/v_tilde'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/v_tilde'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/v_tilde'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/v_tilde'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/v_tilde'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/x_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/x_d'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/x_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/x_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/x_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/x_d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/y_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/y_d'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/y_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/y_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/y_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/y_d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/psi_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/psi_d'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/psi_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/psi_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/psi_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/psi_d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/r_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/r_d'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/r_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/r_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/r_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/r_d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/u_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/u_d'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/u_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/u_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/u_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/u_d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/v_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/v_d'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/v_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/v_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/v_d'
                                        */
  0.0                                  /* Expression: btype
                                        * Referenced by: '<S5>/v_d'
                                        */
};

/*========================================================================*
 * NI VeriStand Model Framework code generation
 *
 * Model : ctrl_DP
 * Model version : 1.53
 * VeriStand Model Framework version : 2017.0.0.143 (2017)
 * Source generated on : Thu Jul 13 11:39:50 2017
 *========================================================================*/
#if defined VXWORKS || defined kNIOSLinux

typedef struct {
  int32_t size;
  int32_t width;
  int32_t basetype;
} NI_ParamSizeWidth;

NI_ParamSizeWidth P_ctrl_DP_T_sizes[] DataSection(".NIVS.defaultparamsizes") = {
  { sizeof(P_ctrl_DP_T), 1 },

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

  { sizeof(real_T), 3, 0 },

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

  { sizeof(real_T), 81, 0 },

  { sizeof(real_T), 9, 0 },

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

  { sizeof(real_T), 3, 0 },

  { sizeof(real_T), 9, 0 },

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
};

#endif
