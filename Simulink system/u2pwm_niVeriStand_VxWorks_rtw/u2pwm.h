/*
 * u2pwm.h
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

#ifndef RTW_HEADER_u2pwm_h_
#define RTW_HEADER_u2pwm_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef u2pwm_COMMON_INCLUDES_
# define u2pwm_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_logging.h"
#endif                                 /* u2pwm_COMMON_INCLUDES_ */

#include "u2pwm_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->blkStateChange = (val))
#endif

#ifndef rtmGetBlockIO
# define rtmGetBlockIO(rtm)            ((rtm)->blockIO)
#endif

#ifndef rtmSetBlockIO
# define rtmSetBlockIO(rtm, val)       ((rtm)->blockIO = (val))
#endif

#ifndef rtmGetChecksums
# define rtmGetChecksums(rtm)          ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
# define rtmSetChecksums(rtm, val)     ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
# define rtmGetConstBlockIO(rtm)       ((rtm)->constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
# define rtmSetConstBlockIO(rtm, val)  ((rtm)->constBlockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->contStates = (val))
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        ()
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)   ()
#endif

#ifndef rtmGetDefaultParam
# define rtmGetDefaultParam(rtm)       ((rtm)->defaultParam)
#endif

#ifndef rtmSetDefaultParam
# define rtmSetDefaultParam(rtm, val)  ((rtm)->defaultParam = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
# define rtmGetDirectFeedThrough(rtm)  ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
# define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
# define rtmGetErrorStatusFlag(rtm)    ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
# define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
# define rtmSetFinalTime(rtm, val)     ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
# define rtmGetFirstInitCondFlag(rtm)  ()
#endif

#ifndef rtmSetFirstInitCondFlag
# define rtmSetFirstInitCondFlag(rtm, val) ()
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->intgData = (val))
#endif

#ifndef rtmGetMdlRefGlobalTID
# define rtmGetMdlRefGlobalTID(rtm)    ()
#endif

#ifndef rtmSetMdlRefGlobalTID
# define rtmSetMdlRefGlobalTID(rtm, val) ()
#endif

#ifndef rtmGetMdlRefTriggerTID
# define rtmGetMdlRefTriggerTID(rtm)   ()
#endif

#ifndef rtmSetMdlRefTriggerTID
# define rtmSetMdlRefTriggerTID(rtm, val) ()
#endif

#ifndef rtmGetModelMappingInfo
# define rtmGetModelMappingInfo(rtm)   ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
# define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
# define rtmGetModelName(rtm)          ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
# define rtmSetModelName(rtm, val)     ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
# define rtmGetNonInlinedSFcns(rtm)    ()
#endif

#ifndef rtmSetNonInlinedSFcns
# define rtmSetNonInlinedSFcns(rtm, val) ()
#endif

#ifndef rtmGetNumBlockIO
# define rtmGetNumBlockIO(rtm)         ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
# define rtmSetNumBlockIO(rtm, val)    ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
# define rtmGetNumBlockParams(rtm)     ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
# define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
# define rtmGetNumBlocks(rtm)          ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
# define rtmSetNumBlocks(rtm, val)     ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
# define rtmGetNumContStates(rtm)      ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
# define rtmSetNumContStates(rtm, val) ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
# define rtmGetNumDWork(rtm)           ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
# define rtmSetNumDWork(rtm, val)      ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
# define rtmGetNumInputPorts(rtm)      ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
# define rtmSetNumInputPorts(rtm, val) ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
# define rtmGetNumNonSampledZCs(rtm)   ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
# define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
# define rtmGetNumOutputPorts(rtm)     ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
# define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumPeriodicContStates
# define rtmGetNumPeriodicContStates(rtm) ((rtm)->Sizes.numPeriodicContStates)
#endif

#ifndef rtmSetNumPeriodicContStates
# define rtmSetNumPeriodicContStates(rtm, val) ((rtm)->Sizes.numPeriodicContStates = (val))
#endif

#ifndef rtmGetNumSFcnParams
# define rtmGetNumSFcnParams(rtm)      ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
# define rtmSetNumSFcnParams(rtm, val) ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
# define rtmGetNumSFunctions(rtm)      ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
# define rtmSetNumSFunctions(rtm, val) ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
# define rtmGetNumSampleTimes(rtm)     ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
# define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
# define rtmGetNumU(rtm)               ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
# define rtmSetNumU(rtm, val)          ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
# define rtmGetNumY(rtm)               ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
# define rtmSetNumY(rtm, val)          ((rtm)->Sizes.numY = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->odeY = (val))
#endif

#ifndef rtmGetOffsetTimeArray
# define rtmGetOffsetTimeArray(rtm)    ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
# define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
# define rtmGetOffsetTimePtr(rtm)      ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
# define rtmSetOffsetTimePtr(rtm, val) ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
# define rtmGetOptions(rtm)            ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
# define rtmSetOptions(rtm, val)       ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
# define rtmGetParamIsMalloced(rtm)    ()
#endif

#ifndef rtmSetParamIsMalloced
# define rtmSetParamIsMalloced(rtm, val) ()
#endif

#ifndef rtmGetPath
# define rtmGetPath(rtm)               ((rtm)->path)
#endif

#ifndef rtmSetPath
# define rtmSetPath(rtm, val)          ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
# define rtmGetPerTaskSampleHits(rtm)  ()
#endif

#ifndef rtmSetPerTaskSampleHits
# define rtmSetPerTaskSampleHits(rtm, val) ()
#endif

#ifndef rtmGetPerTaskSampleHitsArray
# define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
# define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
# define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
# define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetPrevZCSigState
# define rtmGetPrevZCSigState(rtm)     ((rtm)->prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
# define rtmSetPrevZCSigState(rtm, val) ((rtm)->prevZCSigState = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
# define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
# define rtmGetRTWGeneratedSFcn(rtm)   ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
# define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmSetRTWLogInfo
# define rtmSetRTWLogInfo(rtm, val)    ((rtm)->rtwLogInfo = (val))
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
# define rtmGetRTWRTModelMethodsInfo(rtm) ()
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
# define rtmSetRTWRTModelMethodsInfo(rtm, val) ()
#endif

#ifndef rtmGetRTWSfcnInfo
# define rtmGetRTWSfcnInfo(rtm)        ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
# define rtmSetRTWSfcnInfo(rtm, val)   ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
# define rtmGetRTWSolverInfo(rtm)      ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
# define rtmSetRTWSolverInfo(rtm, val) ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
# define rtmGetRTWSolverInfoPtr(rtm)   ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
# define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
# define rtmGetReservedForXPC(rtm)     ((rtm)->SpecialInfo.xpcData)
#endif

#ifndef rtmSetReservedForXPC
# define rtmSetReservedForXPC(rtm, val) ((rtm)->SpecialInfo.xpcData = (val))
#endif

#ifndef rtmGetRootDWork
# define rtmGetRootDWork(rtm)          ((rtm)->dwork)
#endif

#ifndef rtmSetRootDWork
# define rtmSetRootDWork(rtm, val)     ((rtm)->dwork = (val))
#endif

#ifndef rtmGetSFunctions
# define rtmGetSFunctions(rtm)         ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
# define rtmSetSFunctions(rtm, val)    ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
# define rtmGetSampleHitArray(rtm)     ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
# define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
# define rtmGetSampleHitPtr(rtm)       ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
# define rtmSetSampleHitPtr(rtm, val)  ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
# define rtmGetSampleTimeArray(rtm)    ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
# define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
# define rtmGetSampleTimePtr(rtm)      ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
# define rtmSetSampleTimePtr(rtm, val) ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
# define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
# define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
# define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
# define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSelf
# define rtmGetSelf(rtm)               ()
#endif

#ifndef rtmSetSelf
# define rtmSetSelf(rtm, val)          ()
#endif

#ifndef rtmGetSimMode
# define rtmGetSimMode(rtm)            ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
# define rtmSetSimMode(rtm, val)       ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
# define rtmGetSimTimeStep(rtm)        ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
# define rtmSetSimTimeStep(rtm, val)   ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStartTime
# define rtmGetStartTime(rtm)          ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
# define rtmSetStartTime(rtm, val)     ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
# define rtmSetStepSize(rtm, val)      ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
# define rtmGetStopRequestedFlag(rtm)  ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
# define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetTaskCounters
# define rtmGetTaskCounters(rtm)       ()
#endif

#ifndef rtmSetTaskCounters
# define rtmSetTaskCounters(rtm, val)  ()
#endif

#ifndef rtmGetTaskTimeArray
# define rtmGetTaskTimeArray(rtm)      ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
# define rtmSetTaskTimeArray(rtm, val) ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
# define rtmGetTimePtr(rtm)            ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
# define rtmSetTimePtr(rtm, val)       ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
# define rtmGetTimingData(rtm)         ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
# define rtmSetTimingData(rtm, val)    ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
# define rtmGetU(rtm)                  ((rtm)->inputs)
#endif

#ifndef rtmSetU
# define rtmSetU(rtm, val)             ((rtm)->inputs = (val))
#endif

#ifndef rtmGetVarNextHitTimesListPtr
# define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
# define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
# define rtmGetY(rtm)                  ((rtm)->outputs)
#endif

#ifndef rtmSetY
# define rtmSetY(rtm, val)             ((rtm)->outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
# define rtmGetZCSignalValues(rtm)     ((rtm)->zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
# define rtmSetZCSignalValues(rtm, val) ((rtm)->zcSignalValues = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
# define rtmGet_TimeOfLastOutput(rtm)  ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
# define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->derivs = (val))
#endif

#ifndef rtmGetChecksumVal
# define rtmGetChecksumVal(rtm, idx)   ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
# define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
# define rtmGetDWork(rtm, idx)         ((rtm)->dwork[idx])
#endif

#ifndef rtmSetDWork
# define rtmSetDWork(rtm, idx, val)    ((rtm)->dwork[idx] = (val))
#endif

#ifndef rtmGetOffsetTime
# define rtmGetOffsetTime(rtm, idx)    ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
# define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
# define rtmGetSFunction(rtm, idx)     ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
# define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
# define rtmGetSampleTime(rtm, idx)    ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
# define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
# define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
# define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTimeList
# define rtmGetVarNextHitTimeList(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTimeList
# define rtmSetVarNextHitTimeList(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmIsContinuousTask
# define rtmIsContinuousTask(rtm, tid) ((tid) == 0)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmIsSampleHit
# define rtmIsSampleHit(rtm, sti, tid) ((rtmIsMajorTimeStep((rtm)) && (rtm)->Timing.sampleHits[(rtm)->Timing.sampleTimeTaskIDPtr[sti]]))
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

#ifndef rtmSetT
# define rtmSetT(rtm, val)                                       /* Do Nothing */
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
# define rtmGetTStart(rtm)             ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
# define rtmSetTStart(rtm, val)        ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetTaskTime
# define rtmGetTaskTime(rtm, sti)      (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmSetTaskTime
# define rtmSetTaskTime(rtm, sti, val) (rtmGetTPtr((rtm))[sti] = (val))
#endif

#ifndef rtmGetTimeOfLastOutput
# define rtmGetTimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)

/* Definition for use in the target main file */
#define u2pwm_rtModel                  RT_MODEL_u2pwm_T

/* Block signals (auto storage) */
typedef struct {
  real_T Triangle;                     /* '<S2>/Triangle' */
  real_T Circle;                       /* '<S2>/Circle' */
  real_T Cross;                        /* '<S2>/Cross' */
  real_T Square;                       /* '<S2>/Square' */
  real_T Memory;                       /* '<S2>/Memory' */
  real_T u_BT;                         /* '<S5>/u_BT' */
  real_T u_VSP2;                       /* '<S5>/u_VSP2' */
  real_T omega_VSP1;                   /* '<S5>/omega_VSP1' */
  real_T omega_VSP2;                   /* '<S5>/omega_VSP2' */
  real_T u_VSP1;                       /* '<S5>/u_VSP1' */
  real_T alpha_VSP1;                   /* '<S5>/alpha_VSP1' */
  real_T alpha_VSP2;                   /* '<S5>/alpha_VSP2' */
  real_T u_BT_i;                       /* '<S4>/u_BT' */
  real_T u_VSP2_c;                     /* '<S4>/u_VSP2' */
  real_T omega_VSP1_o;                 /* '<S4>/omega_VSP1' */
  real_T omega_VSP2_i;                 /* '<S4>/omega_VSP2' */
  real_T u_VSP1_i;                     /* '<S4>/u_VSP1' */
  real_T alpha_VSP1_b;                 /* '<S4>/alpha_VSP1' */
  real_T alpha_VSP2_j;                 /* '<S4>/alpha_VSP2' */
  real_T u_BT_m;                       /* '<S6>/u_BT' */
  real_T u_VSP2_e;                     /* '<S6>/u_VSP2' */
  real_T omega_VSP1_k;                 /* '<S6>/omega_VSP1' */
  real_T omega_VSP2_m;                 /* '<S6>/omega_VSP2' */
  real_T u_VSP1_c;                     /* '<S6>/u_VSP1' */
  real_T alpha_VSP1_k;                 /* '<S6>/alpha_VSP1' */
  real_T alpha_VSP2_h;                 /* '<S6>/alpha_VSP2' */
  real_T enable_mech_el;               /* '<Root>/enable_mech_el' */
  real_T Sum1;                         /* '<S10>/Sum1' */
  real_T Sum;                          /* '<S10>/Sum' */
  real_T Merge;                        /* '<S13>/Merge' */
  real_T Sum2;                         /* '<S13>/Sum2' */
  real_T uDLookupTable3;               /* '<S10>/2-D Lookup Table3' */
  real_T uDLookupTable2;               /* '<S10>/2-D Lookup Table2' */
  real_T uDLookupTable;                /* '<S10>/2-D Lookup Table' */
  real_T uDLookupTable1;               /* '<S10>/2-D Lookup Table1' */
  real_T Sum_k;                        /* '<S7>/Sum' */
  real_T Sum1_k;                       /* '<S7>/Sum1' */
  real_T Sum2_e;                       /* '<S7>/Sum2' */
  real_T Sum3;                         /* '<S7>/Sum3' */
  real_T Sum4;                         /* '<S7>/Sum4' */
  real_T Sum5;                         /* '<S7>/Sum5' */
  real_T Sum6;                         /* '<S7>/Sum6' */
  real_T Gain6;                        /* '<S13>/Gain6' */
  real_T switch_signal;                /* '<S2>/Switch_function' */
  boolean_T ctrl_custom;               /* '<S8>/C' */
  boolean_T ctrl_DP;                   /* '<S8>/C' */
  boolean_T STOP;                      /* '<S8>/C' */
  boolean_T ctrl_sixaxis2thruster;     /* '<S8>/C' */
  boolean_T fault;                     /* '<Root>/control limit checking' */
} B_u2pwm_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T Triangle_DWORK1;              /* '<S2>/Triangle' */
  real_T Circle_DWORK1;                /* '<S2>/Circle' */
  real_T Cross_DWORK1;                 /* '<S2>/Cross' */
  real_T Square_DWORK1;                /* '<S2>/Square' */
  real_T Memory_PreviousInput;         /* '<S2>/Memory' */
  real_T u_BT_DWORK1;                  /* '<S5>/u_BT' */
  real_T u_VSP2_DWORK1;                /* '<S5>/u_VSP2' */
  real_T omega_VSP1_DWORK1;            /* '<S5>/omega_VSP1' */
  real_T omega_VSP2_DWORK1;            /* '<S5>/omega_VSP2' */
  real_T u_VSP1_DWORK1;                /* '<S5>/u_VSP1' */
  real_T alpha_VSP1_DWORK1;            /* '<S5>/alpha_VSP1' */
  real_T alpha_VSP2_DWORK1;            /* '<S5>/alpha_VSP2' */
  real_T u_BT_DWORK1_o;                /* '<S4>/u_BT' */
  real_T u_VSP2_DWORK1_g;              /* '<S4>/u_VSP2' */
  real_T omega_VSP1_DWORK1_j;          /* '<S4>/omega_VSP1' */
  real_T omega_VSP2_DWORK1_l;          /* '<S4>/omega_VSP2' */
  real_T u_VSP1_DWORK1_e;              /* '<S4>/u_VSP1' */
  real_T alpha_VSP1_DWORK1_n;          /* '<S4>/alpha_VSP1' */
  real_T alpha_VSP2_DWORK1_l;          /* '<S4>/alpha_VSP2' */
  real_T u_BT_DWORK1_p;                /* '<S6>/u_BT' */
  real_T u_VSP2_DWORK1_f;              /* '<S6>/u_VSP2' */
  real_T omega_VSP1_DWORK1_c;          /* '<S6>/omega_VSP1' */
  real_T omega_VSP2_DWORK1_c;          /* '<S6>/omega_VSP2' */
  real_T u_VSP1_DWORK1_i;              /* '<S6>/u_VSP1' */
  real_T alpha_VSP1_DWORK1_j;          /* '<S6>/alpha_VSP1' */
  real_T alpha_VSP2_DWORK1_e;          /* '<S6>/alpha_VSP2' */
  real_T controlinputuexceedsbounds_DWOR;/* '<Root>/control input u exceeds bounds' */
  real_T ctrl_custom_DWORK1;           /* '<S8>/ctrl_custom' */
  real_T ctrl_DP_DWORK1;               /* '<S8>/ctrl_DP' */
  real_T STOP_DWORK1;                  /* '<S8>/STOP' */
  real_T ctrl_sixaxis2thruster_DWORK1; /* '<S8>/ctrl_sixaxis2thruster' */
  real_T enable_mech_el_DWORK1;        /* '<Root>/enable_mech_el' */
  real_T pwm_VSP1_DWORK1;              /* '<S9>/pwm_VSP1' */
  real_T pwm_VSP2_DWORK1;              /* '<S9>/pwm_VSP2' */
  real_T pwm_BT_DWORK1;                /* '<S9>/pwm_BT' */
  real_T pwm_servo4_DWORK1;            /* '<S9>/pwm_servo4' */
  real_T pwm_servo3_DWORK1;            /* '<S9>/pwm_servo3' */
  real_T pwm_servo1_DWORK1;            /* '<S9>/pwm_servo1' */
  real_T pwm_servo2_DWORK1;            /* '<S9>/pwm_servo2' */
  int8_T If_ActiveSubsystem;           /* '<S13>/If' */
  uint8_T Triangle_DWORK2[6];          /* '<S2>/Triangle' */
  uint8_T Circle_DWORK2[6];            /* '<S2>/Circle' */
  uint8_T Cross_DWORK2[6];             /* '<S2>/Cross' */
  uint8_T Square_DWORK2[6];            /* '<S2>/Square' */
  uint8_T u_BT_DWORK2[6];              /* '<S5>/u_BT' */
  uint8_T u_VSP2_DWORK2[6];            /* '<S5>/u_VSP2' */
  uint8_T omega_VSP1_DWORK2[6];        /* '<S5>/omega_VSP1' */
  uint8_T omega_VSP2_DWORK2[6];        /* '<S5>/omega_VSP2' */
  uint8_T u_VSP1_DWORK2[6];            /* '<S5>/u_VSP1' */
  uint8_T alpha_VSP1_DWORK2[6];        /* '<S5>/alpha_VSP1' */
  uint8_T alpha_VSP2_DWORK2[6];        /* '<S5>/alpha_VSP2' */
  uint8_T u_BT_DWORK2_i[6];            /* '<S4>/u_BT' */
  uint8_T u_VSP2_DWORK2_n[6];          /* '<S4>/u_VSP2' */
  uint8_T omega_VSP1_DWORK2_a[6];      /* '<S4>/omega_VSP1' */
  uint8_T omega_VSP2_DWORK2_i[6];      /* '<S4>/omega_VSP2' */
  uint8_T u_VSP1_DWORK2_h[6];          /* '<S4>/u_VSP1' */
  uint8_T alpha_VSP1_DWORK2_b[6];      /* '<S4>/alpha_VSP1' */
  uint8_T alpha_VSP2_DWORK2_a[6];      /* '<S4>/alpha_VSP2' */
  uint8_T u_BT_DWORK2_o[6];            /* '<S6>/u_BT' */
  uint8_T u_VSP2_DWORK2_i[6];          /* '<S6>/u_VSP2' */
  uint8_T omega_VSP1_DWORK2_e[6];      /* '<S6>/omega_VSP1' */
  uint8_T omega_VSP2_DWORK2_b[6];      /* '<S6>/omega_VSP2' */
  uint8_T u_VSP1_DWORK2_a[6];          /* '<S6>/u_VSP1' */
  uint8_T alpha_VSP1_DWORK2_d[6];      /* '<S6>/alpha_VSP1' */
  uint8_T alpha_VSP2_DWORK2_o[6];      /* '<S6>/alpha_VSP2' */
  uint8_T controlinputuexceedsbounds_DW_p[6];/* '<Root>/control input u exceeds bounds' */
  uint8_T ctrl_custom_DWORK2[6];       /* '<S8>/ctrl_custom' */
  uint8_T ctrl_DP_DWORK2[6];           /* '<S8>/ctrl_DP' */
  uint8_T STOP_DWORK2[6];              /* '<S8>/STOP' */
  uint8_T ctrl_sixaxis2thruster_DWORK2[6];/* '<S8>/ctrl_sixaxis2thruster' */
  uint8_T enable_mech_el_DWORK2[6];    /* '<Root>/enable_mech_el' */
  uint8_T pwm_VSP1_DWORK2[6];          /* '<S9>/pwm_VSP1' */
  uint8_T pwm_VSP2_DWORK2[6];          /* '<S9>/pwm_VSP2' */
  uint8_T pwm_BT_DWORK2[6];            /* '<S9>/pwm_BT' */
  uint8_T pwm_servo4_DWORK2[6];        /* '<S9>/pwm_servo4' */
  uint8_T pwm_servo3_DWORK2[6];        /* '<S9>/pwm_servo3' */
  uint8_T pwm_servo1_DWORK2[6];        /* '<S9>/pwm_servo1' */
  uint8_T pwm_servo2_DWORK2[6];        /* '<S9>/pwm_servo2' */
} DW_u2pwm_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T Integrator6_CSTATE;           /* '<S7>/Integrator6' */
  real_T Integrator5_CSTATE;           /* '<S7>/Integrator5' */
  real_T Integrator4_CSTATE;           /* '<S7>/Integrator4' */
  real_T Integrator3_CSTATE;           /* '<S7>/Integrator3' */
  real_T Integrator2_CSTATE;           /* '<S7>/Integrator2' */
  real_T Integrator1_CSTATE;           /* '<S7>/Integrator1' */
  real_T Integrator_CSTATE;            /* '<S7>/Integrator' */
  real_T Integrator_CSTATE_h;          /* '<S13>/Integrator' */
} X_u2pwm_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T Integrator6_CSTATE;           /* '<S7>/Integrator6' */
  real_T Integrator5_CSTATE;           /* '<S7>/Integrator5' */
  real_T Integrator4_CSTATE;           /* '<S7>/Integrator4' */
  real_T Integrator3_CSTATE;           /* '<S7>/Integrator3' */
  real_T Integrator2_CSTATE;           /* '<S7>/Integrator2' */
  real_T Integrator1_CSTATE;           /* '<S7>/Integrator1' */
  real_T Integrator_CSTATE;            /* '<S7>/Integrator' */
  real_T Integrator_CSTATE_h;          /* '<S13>/Integrator' */
} XDot_u2pwm_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator6_CSTATE;        /* '<S7>/Integrator6' */
  boolean_T Integrator5_CSTATE;        /* '<S7>/Integrator5' */
  boolean_T Integrator4_CSTATE;        /* '<S7>/Integrator4' */
  boolean_T Integrator3_CSTATE;        /* '<S7>/Integrator3' */
  boolean_T Integrator2_CSTATE;        /* '<S7>/Integrator2' */
  boolean_T Integrator1_CSTATE;        /* '<S7>/Integrator1' */
  boolean_T Integrator_CSTATE;         /* '<S7>/Integrator' */
  boolean_T Integrator_CSTATE_h;       /* '<S13>/Integrator' */
} XDis_u2pwm_T;

#ifndef ODE4_INTG
#define ODE4_INTG

/* ODE4 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[4];                        /* derivatives */
} ODE4_IntgData;

#endif

/* Backward compatible GRT Identifiers */
#define rtB                            u2pwm_B
#define BlockIO                        B_u2pwm_T
#define rtX                            u2pwm_X
#define ContinuousStates               X_u2pwm_T
#define rtXdot                         u2pwm_XDot
#define StateDerivatives               XDot_u2pwm_T
#define tXdis                          u2pwm_XDis
#define StateDisabled                  XDis_u2pwm_T
#define rtP                            u2pwm_P
#define Parameters                     P_u2pwm_T
#define rtDWork                        u2pwm_DW
#define D_Work                         DW_u2pwm_T

/* Parameters (auto storage) */
struct P_u2pwm_T_ {
  real_T BT_u2pwm_gain;                /* Variable: BT_u2pwm_gain
                                        * Referenced by: '<S13>/VPS_Speed_Gain1'
                                        */
  real_T BT_zero_pwm;                  /* Variable: BT_zero_pwm
                                        * Referenced by: '<S16>/Constant'
                                        */
  real_T BT_zero_pwm_neg;              /* Variable: BT_zero_pwm_neg
                                        * Referenced by: '<S15>/Constant'
                                        */
  real_T BT_zero_pwm_pos;              /* Variable: BT_zero_pwm_pos
                                        * Referenced by: '<S14>/Constant'
                                        */
  real_T VSP_u2pwm_gain;               /* Variable: VSP_u2pwm_gain
                                        * Referenced by:
                                        *   '<S10>/VPS_Speed_Gain'
                                        *   '<S10>/VPS_Speed_Gain2'
                                        */
  real_T VSP_zero_pwm;                 /* Variable: VSP_zero_pwm
                                        * Referenced by: '<S10>/VPS_Power_Offset'
                                        */
  real_T Triangle_P1;                  /* Expression: width
                                        * Referenced by: '<S2>/Triangle'
                                        */
  real_T Triangle_P2;                  /* Expression: dtype
                                        * Referenced by: '<S2>/Triangle'
                                        */
  real_T Triangle_P3;                  /* Expression: portnum
                                        * Referenced by: '<S2>/Triangle'
                                        */
  real_T Triangle_P4;                  /* Expression: stime
                                        * Referenced by: '<S2>/Triangle'
                                        */
  real_T Triangle_P5;                  /* Expression: stype
                                        * Referenced by: '<S2>/Triangle'
                                        */
  real_T Triangle_P6;                  /* Expression: btype
                                        * Referenced by: '<S2>/Triangle'
                                        */
  real_T Circle_P1;                    /* Expression: width
                                        * Referenced by: '<S2>/Circle'
                                        */
  real_T Circle_P2;                    /* Expression: dtype
                                        * Referenced by: '<S2>/Circle'
                                        */
  real_T Circle_P3;                    /* Expression: portnum
                                        * Referenced by: '<S2>/Circle'
                                        */
  real_T Circle_P4;                    /* Expression: stime
                                        * Referenced by: '<S2>/Circle'
                                        */
  real_T Circle_P5;                    /* Expression: stype
                                        * Referenced by: '<S2>/Circle'
                                        */
  real_T Circle_P6;                    /* Expression: btype
                                        * Referenced by: '<S2>/Circle'
                                        */
  real_T Cross_P1;                     /* Expression: width
                                        * Referenced by: '<S2>/Cross'
                                        */
  real_T Cross_P2;                     /* Expression: dtype
                                        * Referenced by: '<S2>/Cross'
                                        */
  real_T Cross_P3;                     /* Expression: portnum
                                        * Referenced by: '<S2>/Cross'
                                        */
  real_T Cross_P4;                     /* Expression: stime
                                        * Referenced by: '<S2>/Cross'
                                        */
  real_T Cross_P5;                     /* Expression: stype
                                        * Referenced by: '<S2>/Cross'
                                        */
  real_T Cross_P6;                     /* Expression: btype
                                        * Referenced by: '<S2>/Cross'
                                        */
  real_T Square_P1;                    /* Expression: width
                                        * Referenced by: '<S2>/Square'
                                        */
  real_T Square_P2;                    /* Expression: dtype
                                        * Referenced by: '<S2>/Square'
                                        */
  real_T Square_P3;                    /* Expression: portnum
                                        * Referenced by: '<S2>/Square'
                                        */
  real_T Square_P4;                    /* Expression: stime
                                        * Referenced by: '<S2>/Square'
                                        */
  real_T Square_P5;                    /* Expression: stype
                                        * Referenced by: '<S2>/Square'
                                        */
  real_T Square_P6;                    /* Expression: btype
                                        * Referenced by: '<S2>/Square'
                                        */
  real_T Memory_X0;                    /* Expression: 4
                                        * Referenced by: '<S2>/Memory'
                                        */
  real_T u_BT_P1;                      /* Expression: width
                                        * Referenced by: '<S5>/u_BT'
                                        */
  real_T u_BT_P2;                      /* Expression: dtype
                                        * Referenced by: '<S5>/u_BT'
                                        */
  real_T u_BT_P3;                      /* Expression: portnum
                                        * Referenced by: '<S5>/u_BT'
                                        */
  real_T u_BT_P4;                      /* Expression: stime
                                        * Referenced by: '<S5>/u_BT'
                                        */
  real_T u_BT_P5;                      /* Expression: stype
                                        * Referenced by: '<S5>/u_BT'
                                        */
  real_T u_BT_P6;                      /* Expression: btype
                                        * Referenced by: '<S5>/u_BT'
                                        */
  real_T u_VSP2_P1;                    /* Expression: width
                                        * Referenced by: '<S5>/u_VSP2'
                                        */
  real_T u_VSP2_P2;                    /* Expression: dtype
                                        * Referenced by: '<S5>/u_VSP2'
                                        */
  real_T u_VSP2_P3;                    /* Expression: portnum
                                        * Referenced by: '<S5>/u_VSP2'
                                        */
  real_T u_VSP2_P4;                    /* Expression: stime
                                        * Referenced by: '<S5>/u_VSP2'
                                        */
  real_T u_VSP2_P5;                    /* Expression: stype
                                        * Referenced by: '<S5>/u_VSP2'
                                        */
  real_T u_VSP2_P6;                    /* Expression: btype
                                        * Referenced by: '<S5>/u_VSP2'
                                        */
  real_T omega_VSP1_P1;                /* Expression: width
                                        * Referenced by: '<S5>/omega_VSP1'
                                        */
  real_T omega_VSP1_P2;                /* Expression: dtype
                                        * Referenced by: '<S5>/omega_VSP1'
                                        */
  real_T omega_VSP1_P3;                /* Expression: portnum
                                        * Referenced by: '<S5>/omega_VSP1'
                                        */
  real_T omega_VSP1_P4;                /* Expression: stime
                                        * Referenced by: '<S5>/omega_VSP1'
                                        */
  real_T omega_VSP1_P5;                /* Expression: stype
                                        * Referenced by: '<S5>/omega_VSP1'
                                        */
  real_T omega_VSP1_P6;                /* Expression: btype
                                        * Referenced by: '<S5>/omega_VSP1'
                                        */
  real_T omega_VSP2_P1;                /* Expression: width
                                        * Referenced by: '<S5>/omega_VSP2'
                                        */
  real_T omega_VSP2_P2;                /* Expression: dtype
                                        * Referenced by: '<S5>/omega_VSP2'
                                        */
  real_T omega_VSP2_P3;                /* Expression: portnum
                                        * Referenced by: '<S5>/omega_VSP2'
                                        */
  real_T omega_VSP2_P4;                /* Expression: stime
                                        * Referenced by: '<S5>/omega_VSP2'
                                        */
  real_T omega_VSP2_P5;                /* Expression: stype
                                        * Referenced by: '<S5>/omega_VSP2'
                                        */
  real_T omega_VSP2_P6;                /* Expression: btype
                                        * Referenced by: '<S5>/omega_VSP2'
                                        */
  real_T u_VSP1_P1;                    /* Expression: width
                                        * Referenced by: '<S5>/u_VSP1'
                                        */
  real_T u_VSP1_P2;                    /* Expression: dtype
                                        * Referenced by: '<S5>/u_VSP1'
                                        */
  real_T u_VSP1_P3;                    /* Expression: portnum
                                        * Referenced by: '<S5>/u_VSP1'
                                        */
  real_T u_VSP1_P4;                    /* Expression: stime
                                        * Referenced by: '<S5>/u_VSP1'
                                        */
  real_T u_VSP1_P5;                    /* Expression: stype
                                        * Referenced by: '<S5>/u_VSP1'
                                        */
  real_T u_VSP1_P6;                    /* Expression: btype
                                        * Referenced by: '<S5>/u_VSP1'
                                        */
  real_T alpha_VSP1_P1;                /* Expression: width
                                        * Referenced by: '<S5>/alpha_VSP1'
                                        */
  real_T alpha_VSP1_P2;                /* Expression: dtype
                                        * Referenced by: '<S5>/alpha_VSP1'
                                        */
  real_T alpha_VSP1_P3;                /* Expression: portnum
                                        * Referenced by: '<S5>/alpha_VSP1'
                                        */
  real_T alpha_VSP1_P4;                /* Expression: stime
                                        * Referenced by: '<S5>/alpha_VSP1'
                                        */
  real_T alpha_VSP1_P5;                /* Expression: stype
                                        * Referenced by: '<S5>/alpha_VSP1'
                                        */
  real_T alpha_VSP1_P6;                /* Expression: btype
                                        * Referenced by: '<S5>/alpha_VSP1'
                                        */
  real_T alpha_VSP2_P1;                /* Expression: width
                                        * Referenced by: '<S5>/alpha_VSP2'
                                        */
  real_T alpha_VSP2_P2;                /* Expression: dtype
                                        * Referenced by: '<S5>/alpha_VSP2'
                                        */
  real_T alpha_VSP2_P3;                /* Expression: portnum
                                        * Referenced by: '<S5>/alpha_VSP2'
                                        */
  real_T alpha_VSP2_P4;                /* Expression: stime
                                        * Referenced by: '<S5>/alpha_VSP2'
                                        */
  real_T alpha_VSP2_P5;                /* Expression: stype
                                        * Referenced by: '<S5>/alpha_VSP2'
                                        */
  real_T alpha_VSP2_P6;                /* Expression: btype
                                        * Referenced by: '<S5>/alpha_VSP2'
                                        */
  real_T u_BT_P1_g;                    /* Expression: width
                                        * Referenced by: '<S4>/u_BT'
                                        */
  real_T u_BT_P2_n;                    /* Expression: dtype
                                        * Referenced by: '<S4>/u_BT'
                                        */
  real_T u_BT_P3_e;                    /* Expression: portnum
                                        * Referenced by: '<S4>/u_BT'
                                        */
  real_T u_BT_P4_m;                    /* Expression: stime
                                        * Referenced by: '<S4>/u_BT'
                                        */
  real_T u_BT_P5_b;                    /* Expression: stype
                                        * Referenced by: '<S4>/u_BT'
                                        */
  real_T u_BT_P6_k;                    /* Expression: btype
                                        * Referenced by: '<S4>/u_BT'
                                        */
  real_T u_VSP2_P1_i;                  /* Expression: width
                                        * Referenced by: '<S4>/u_VSP2'
                                        */
  real_T u_VSP2_P2_e;                  /* Expression: dtype
                                        * Referenced by: '<S4>/u_VSP2'
                                        */
  real_T u_VSP2_P3_c;                  /* Expression: portnum
                                        * Referenced by: '<S4>/u_VSP2'
                                        */
  real_T u_VSP2_P4_o;                  /* Expression: stime
                                        * Referenced by: '<S4>/u_VSP2'
                                        */
  real_T u_VSP2_P5_a;                  /* Expression: stype
                                        * Referenced by: '<S4>/u_VSP2'
                                        */
  real_T u_VSP2_P6_o;                  /* Expression: btype
                                        * Referenced by: '<S4>/u_VSP2'
                                        */
  real_T omega_VSP1_P1_c;              /* Expression: width
                                        * Referenced by: '<S4>/omega_VSP1'
                                        */
  real_T omega_VSP1_P2_k;              /* Expression: dtype
                                        * Referenced by: '<S4>/omega_VSP1'
                                        */
  real_T omega_VSP1_P3_d;              /* Expression: portnum
                                        * Referenced by: '<S4>/omega_VSP1'
                                        */
  real_T omega_VSP1_P4_e;              /* Expression: stime
                                        * Referenced by: '<S4>/omega_VSP1'
                                        */
  real_T omega_VSP1_P5_e;              /* Expression: stype
                                        * Referenced by: '<S4>/omega_VSP1'
                                        */
  real_T omega_VSP1_P6_d;              /* Expression: btype
                                        * Referenced by: '<S4>/omega_VSP1'
                                        */
  real_T omega_VSP2_P1_d;              /* Expression: width
                                        * Referenced by: '<S4>/omega_VSP2'
                                        */
  real_T omega_VSP2_P2_g;              /* Expression: dtype
                                        * Referenced by: '<S4>/omega_VSP2'
                                        */
  real_T omega_VSP2_P3_m;              /* Expression: portnum
                                        * Referenced by: '<S4>/omega_VSP2'
                                        */
  real_T omega_VSP2_P4_f;              /* Expression: stime
                                        * Referenced by: '<S4>/omega_VSP2'
                                        */
  real_T omega_VSP2_P5_e;              /* Expression: stype
                                        * Referenced by: '<S4>/omega_VSP2'
                                        */
  real_T omega_VSP2_P6_l;              /* Expression: btype
                                        * Referenced by: '<S4>/omega_VSP2'
                                        */
  real_T u_VSP1_P1_o;                  /* Expression: width
                                        * Referenced by: '<S4>/u_VSP1'
                                        */
  real_T u_VSP1_P2_h;                  /* Expression: dtype
                                        * Referenced by: '<S4>/u_VSP1'
                                        */
  real_T u_VSP1_P3_l;                  /* Expression: portnum
                                        * Referenced by: '<S4>/u_VSP1'
                                        */
  real_T u_VSP1_P4_k;                  /* Expression: stime
                                        * Referenced by: '<S4>/u_VSP1'
                                        */
  real_T u_VSP1_P5_a;                  /* Expression: stype
                                        * Referenced by: '<S4>/u_VSP1'
                                        */
  real_T u_VSP1_P6_c;                  /* Expression: btype
                                        * Referenced by: '<S4>/u_VSP1'
                                        */
  real_T alpha_VSP1_P1_o;              /* Expression: width
                                        * Referenced by: '<S4>/alpha_VSP1'
                                        */
  real_T alpha_VSP1_P2_j;              /* Expression: dtype
                                        * Referenced by: '<S4>/alpha_VSP1'
                                        */
  real_T alpha_VSP1_P3_m;              /* Expression: portnum
                                        * Referenced by: '<S4>/alpha_VSP1'
                                        */
  real_T alpha_VSP1_P4_i;              /* Expression: stime
                                        * Referenced by: '<S4>/alpha_VSP1'
                                        */
  real_T alpha_VSP1_P5_o;              /* Expression: stype
                                        * Referenced by: '<S4>/alpha_VSP1'
                                        */
  real_T alpha_VSP1_P6_a;              /* Expression: btype
                                        * Referenced by: '<S4>/alpha_VSP1'
                                        */
  real_T alpha_VSP2_P1_h;              /* Expression: width
                                        * Referenced by: '<S4>/alpha_VSP2'
                                        */
  real_T alpha_VSP2_P2_l;              /* Expression: dtype
                                        * Referenced by: '<S4>/alpha_VSP2'
                                        */
  real_T alpha_VSP2_P3_p;              /* Expression: portnum
                                        * Referenced by: '<S4>/alpha_VSP2'
                                        */
  real_T alpha_VSP2_P4_k;              /* Expression: stime
                                        * Referenced by: '<S4>/alpha_VSP2'
                                        */
  real_T alpha_VSP2_P5_l;              /* Expression: stype
                                        * Referenced by: '<S4>/alpha_VSP2'
                                        */
  real_T alpha_VSP2_P6_o;              /* Expression: btype
                                        * Referenced by: '<S4>/alpha_VSP2'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S1>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S1>/Constant2'
                                        */
  real_T Constant3_Value;              /* Expression: 0
                                        * Referenced by: '<S1>/Constant3'
                                        */
  real_T Constant4_Value;              /* Expression: 0
                                        * Referenced by: '<S1>/Constant4'
                                        */
  real_T Constant5_Value;              /* Expression: 0
                                        * Referenced by: '<S1>/Constant5'
                                        */
  real_T Constant6_Value;              /* Expression: 0
                                        * Referenced by: '<S1>/Constant6'
                                        */
  real_T u_BT_P1_m;                    /* Expression: width
                                        * Referenced by: '<S6>/u_BT'
                                        */
  real_T u_BT_P2_j;                    /* Expression: dtype
                                        * Referenced by: '<S6>/u_BT'
                                        */
  real_T u_BT_P3_l;                    /* Expression: portnum
                                        * Referenced by: '<S6>/u_BT'
                                        */
  real_T u_BT_P4_l;                    /* Expression: stime
                                        * Referenced by: '<S6>/u_BT'
                                        */
  real_T u_BT_P5_k;                    /* Expression: stype
                                        * Referenced by: '<S6>/u_BT'
                                        */
  real_T u_BT_P6_c;                    /* Expression: btype
                                        * Referenced by: '<S6>/u_BT'
                                        */
  real_T u_VSP2_P1_l;                  /* Expression: width
                                        * Referenced by: '<S6>/u_VSP2'
                                        */
  real_T u_VSP2_P2_l;                  /* Expression: dtype
                                        * Referenced by: '<S6>/u_VSP2'
                                        */
  real_T u_VSP2_P3_d;                  /* Expression: portnum
                                        * Referenced by: '<S6>/u_VSP2'
                                        */
  real_T u_VSP2_P4_l;                  /* Expression: stime
                                        * Referenced by: '<S6>/u_VSP2'
                                        */
  real_T u_VSP2_P5_j;                  /* Expression: stype
                                        * Referenced by: '<S6>/u_VSP2'
                                        */
  real_T u_VSP2_P6_k;                  /* Expression: btype
                                        * Referenced by: '<S6>/u_VSP2'
                                        */
  real_T omega_VSP1_P1_a;              /* Expression: width
                                        * Referenced by: '<S6>/omega_VSP1'
                                        */
  real_T omega_VSP1_P2_a;              /* Expression: dtype
                                        * Referenced by: '<S6>/omega_VSP1'
                                        */
  real_T omega_VSP1_P3_i;              /* Expression: portnum
                                        * Referenced by: '<S6>/omega_VSP1'
                                        */
  real_T omega_VSP1_P4_o;              /* Expression: stime
                                        * Referenced by: '<S6>/omega_VSP1'
                                        */
  real_T omega_VSP1_P5_j;              /* Expression: stype
                                        * Referenced by: '<S6>/omega_VSP1'
                                        */
  real_T omega_VSP1_P6_a;              /* Expression: btype
                                        * Referenced by: '<S6>/omega_VSP1'
                                        */
  real_T omega_VSP2_P1_j;              /* Expression: width
                                        * Referenced by: '<S6>/omega_VSP2'
                                        */
  real_T omega_VSP2_P2_i;              /* Expression: dtype
                                        * Referenced by: '<S6>/omega_VSP2'
                                        */
  real_T omega_VSP2_P3_p;              /* Expression: portnum
                                        * Referenced by: '<S6>/omega_VSP2'
                                        */
  real_T omega_VSP2_P4_fp;             /* Expression: stime
                                        * Referenced by: '<S6>/omega_VSP2'
                                        */
  real_T omega_VSP2_P5_p;              /* Expression: stype
                                        * Referenced by: '<S6>/omega_VSP2'
                                        */
  real_T omega_VSP2_P6_c;              /* Expression: btype
                                        * Referenced by: '<S6>/omega_VSP2'
                                        */
  real_T u_VSP1_P1_f;                  /* Expression: width
                                        * Referenced by: '<S6>/u_VSP1'
                                        */
  real_T u_VSP1_P2_b;                  /* Expression: dtype
                                        * Referenced by: '<S6>/u_VSP1'
                                        */
  real_T u_VSP1_P3_g;                  /* Expression: portnum
                                        * Referenced by: '<S6>/u_VSP1'
                                        */
  real_T u_VSP1_P4_o;                  /* Expression: stime
                                        * Referenced by: '<S6>/u_VSP1'
                                        */
  real_T u_VSP1_P5_e;                  /* Expression: stype
                                        * Referenced by: '<S6>/u_VSP1'
                                        */
  real_T u_VSP1_P6_n;                  /* Expression: btype
                                        * Referenced by: '<S6>/u_VSP1'
                                        */
  real_T alpha_VSP1_P1_k;              /* Expression: width
                                        * Referenced by: '<S6>/alpha_VSP1'
                                        */
  real_T alpha_VSP1_P2_f;              /* Expression: dtype
                                        * Referenced by: '<S6>/alpha_VSP1'
                                        */
  real_T alpha_VSP1_P3_i;              /* Expression: portnum
                                        * Referenced by: '<S6>/alpha_VSP1'
                                        */
  real_T alpha_VSP1_P4_b;              /* Expression: stime
                                        * Referenced by: '<S6>/alpha_VSP1'
                                        */
  real_T alpha_VSP1_P5_p;              /* Expression: stype
                                        * Referenced by: '<S6>/alpha_VSP1'
                                        */
  real_T alpha_VSP1_P6_c;              /* Expression: btype
                                        * Referenced by: '<S6>/alpha_VSP1'
                                        */
  real_T alpha_VSP2_P1_o;              /* Expression: width
                                        * Referenced by: '<S6>/alpha_VSP2'
                                        */
  real_T alpha_VSP2_P2_j;              /* Expression: dtype
                                        * Referenced by: '<S6>/alpha_VSP2'
                                        */
  real_T alpha_VSP2_P3_j;              /* Expression: portnum
                                        * Referenced by: '<S6>/alpha_VSP2'
                                        */
  real_T alpha_VSP2_P4_c;              /* Expression: stime
                                        * Referenced by: '<S6>/alpha_VSP2'
                                        */
  real_T alpha_VSP2_P5_j;              /* Expression: stype
                                        * Referenced by: '<S6>/alpha_VSP2'
                                        */
  real_T alpha_VSP2_P6_p;              /* Expression: btype
                                        * Referenced by: '<S6>/alpha_VSP2'
                                        */
  real_T controlinputuexceedsbounds_P1;/* Expression: width
                                        * Referenced by: '<Root>/control input u exceeds bounds'
                                        */
  real_T controlinputuexceedsbounds_P2;/* Expression: dtype
                                        * Referenced by: '<Root>/control input u exceeds bounds'
                                        */
  real_T controlinputuexceedsbounds_P3;/* Expression: portnum
                                        * Referenced by: '<Root>/control input u exceeds bounds'
                                        */
  real_T controlinputuexceedsbounds_P4;/* Expression: stime
                                        * Referenced by: '<Root>/control input u exceeds bounds'
                                        */
  real_T controlinputuexceedsbounds_P5;/* Expression: stype
                                        * Referenced by: '<Root>/control input u exceeds bounds'
                                        */
  real_T controlinputuexceedsbounds_P6;/* Expression: btype
                                        * Referenced by: '<Root>/control input u exceeds bounds'
                                        */
  real_T ctrl_custom_P1;               /* Expression: width
                                        * Referenced by: '<S8>/ctrl_custom'
                                        */
  real_T ctrl_custom_P2;               /* Expression: dtype
                                        * Referenced by: '<S8>/ctrl_custom'
                                        */
  real_T ctrl_custom_P3;               /* Expression: portnum
                                        * Referenced by: '<S8>/ctrl_custom'
                                        */
  real_T ctrl_custom_P4;               /* Expression: stime
                                        * Referenced by: '<S8>/ctrl_custom'
                                        */
  real_T ctrl_custom_P5;               /* Expression: stype
                                        * Referenced by: '<S8>/ctrl_custom'
                                        */
  real_T ctrl_custom_P6;               /* Expression: btype
                                        * Referenced by: '<S8>/ctrl_custom'
                                        */
  real_T ctrl_DP_P1;                   /* Expression: width
                                        * Referenced by: '<S8>/ctrl_DP'
                                        */
  real_T ctrl_DP_P2;                   /* Expression: dtype
                                        * Referenced by: '<S8>/ctrl_DP'
                                        */
  real_T ctrl_DP_P3;                   /* Expression: portnum
                                        * Referenced by: '<S8>/ctrl_DP'
                                        */
  real_T ctrl_DP_P4;                   /* Expression: stime
                                        * Referenced by: '<S8>/ctrl_DP'
                                        */
  real_T ctrl_DP_P5;                   /* Expression: stype
                                        * Referenced by: '<S8>/ctrl_DP'
                                        */
  real_T ctrl_DP_P6;                   /* Expression: btype
                                        * Referenced by: '<S8>/ctrl_DP'
                                        */
  real_T STOP_P1;                      /* Expression: width
                                        * Referenced by: '<S8>/STOP'
                                        */
  real_T STOP_P2;                      /* Expression: dtype
                                        * Referenced by: '<S8>/STOP'
                                        */
  real_T STOP_P3;                      /* Expression: portnum
                                        * Referenced by: '<S8>/STOP'
                                        */
  real_T STOP_P4;                      /* Expression: stime
                                        * Referenced by: '<S8>/STOP'
                                        */
  real_T STOP_P5;                      /* Expression: stype
                                        * Referenced by: '<S8>/STOP'
                                        */
  real_T STOP_P6;                      /* Expression: btype
                                        * Referenced by: '<S8>/STOP'
                                        */
  real_T ctrl_sixaxis2thruster_P1;     /* Expression: width
                                        * Referenced by: '<S8>/ctrl_sixaxis2thruster'
                                        */
  real_T ctrl_sixaxis2thruster_P2;     /* Expression: dtype
                                        * Referenced by: '<S8>/ctrl_sixaxis2thruster'
                                        */
  real_T ctrl_sixaxis2thruster_P3;     /* Expression: portnum
                                        * Referenced by: '<S8>/ctrl_sixaxis2thruster'
                                        */
  real_T ctrl_sixaxis2thruster_P4;     /* Expression: stime
                                        * Referenced by: '<S8>/ctrl_sixaxis2thruster'
                                        */
  real_T ctrl_sixaxis2thruster_P5;     /* Expression: stype
                                        * Referenced by: '<S8>/ctrl_sixaxis2thruster'
                                        */
  real_T ctrl_sixaxis2thruster_P6;     /* Expression: btype
                                        * Referenced by: '<S8>/ctrl_sixaxis2thruster'
                                        */
  real_T Integrator6_IC;               /* Expression: 0
                                        * Referenced by: '<S7>/Integrator6'
                                        */
  real_T Integrator5_IC;               /* Expression: 0
                                        * Referenced by: '<S7>/Integrator5'
                                        */
  real_T Integrator4_IC;               /* Expression: 0
                                        * Referenced by: '<S7>/Integrator4'
                                        */
  real_T Integrator3_IC;               /* Expression: 0
                                        * Referenced by: '<S7>/Integrator3'
                                        */
  real_T Integrator2_IC;               /* Expression: 0
                                        * Referenced by: '<S7>/Integrator2'
                                        */
  real_T Integrator1_IC;               /* Expression: 0
                                        * Referenced by: '<S7>/Integrator1'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S7>/Integrator'
                                        */
  real_T enable_mech_el_P1;            /* Expression: width
                                        * Referenced by: '<Root>/enable_mech_el'
                                        */
  real_T enable_mech_el_P2;            /* Expression: dtype
                                        * Referenced by: '<Root>/enable_mech_el'
                                        */
  real_T enable_mech_el_P3;            /* Expression: portnum
                                        * Referenced by: '<Root>/enable_mech_el'
                                        */
  real_T enable_mech_el_P4;            /* Expression: stime
                                        * Referenced by: '<Root>/enable_mech_el'
                                        */
  real_T enable_mech_el_P5;            /* Expression: stype
                                        * Referenced by: '<Root>/enable_mech_el'
                                        */
  real_T enable_mech_el_P6;            /* Expression: btype
                                        * Referenced by: '<Root>/enable_mech_el'
                                        */
  real_T Saturation8_UpperSat;         /* Expression: 0.4
                                        * Referenced by: '<S10>/Saturation8'
                                        */
  real_T Saturation8_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S10>/Saturation8'
                                        */
  real_T pwm_VSP1_P1;                  /* Expression: width
                                        * Referenced by: '<S9>/pwm_VSP1'
                                        */
  real_T pwm_VSP1_P2;                  /* Expression: dtype
                                        * Referenced by: '<S9>/pwm_VSP1'
                                        */
  real_T pwm_VSP1_P3;                  /* Expression: portnum
                                        * Referenced by: '<S9>/pwm_VSP1'
                                        */
  real_T pwm_VSP1_P4;                  /* Expression: stime
                                        * Referenced by: '<S9>/pwm_VSP1'
                                        */
  real_T pwm_VSP1_P5;                  /* Expression: stype
                                        * Referenced by: '<S9>/pwm_VSP1'
                                        */
  real_T pwm_VSP1_P6;                  /* Expression: btype
                                        * Referenced by: '<S9>/pwm_VSP1'
                                        */
  real_T Saturation9_UpperSat;         /* Expression: 0.4
                                        * Referenced by: '<S10>/Saturation9'
                                        */
  real_T Saturation9_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S10>/Saturation9'
                                        */
  real_T pwm_VSP2_P1;                  /* Expression: width
                                        * Referenced by: '<S9>/pwm_VSP2'
                                        */
  real_T pwm_VSP2_P2;                  /* Expression: dtype
                                        * Referenced by: '<S9>/pwm_VSP2'
                                        */
  real_T pwm_VSP2_P3;                  /* Expression: portnum
                                        * Referenced by: '<S9>/pwm_VSP2'
                                        */
  real_T pwm_VSP2_P4;                  /* Expression: stime
                                        * Referenced by: '<S9>/pwm_VSP2'
                                        */
  real_T pwm_VSP2_P5;                  /* Expression: stype
                                        * Referenced by: '<S9>/pwm_VSP2'
                                        */
  real_T pwm_VSP2_P6;                  /* Expression: btype
                                        * Referenced by: '<S9>/pwm_VSP2'
                                        */
  real_T Integrator_IC_i;              /* Expression: 0
                                        * Referenced by: '<S13>/Integrator'
                                        */
  real_T pwm_BT_P1;                    /* Expression: width
                                        * Referenced by: '<S9>/pwm_BT'
                                        */
  real_T pwm_BT_P2;                    /* Expression: dtype
                                        * Referenced by: '<S9>/pwm_BT'
                                        */
  real_T pwm_BT_P3;                    /* Expression: portnum
                                        * Referenced by: '<S9>/pwm_BT'
                                        */
  real_T pwm_BT_P4;                    /* Expression: stime
                                        * Referenced by: '<S9>/pwm_BT'
                                        */
  real_T pwm_BT_P5;                    /* Expression: stype
                                        * Referenced by: '<S9>/pwm_BT'
                                        */
  real_T pwm_BT_P6;                    /* Expression: btype
                                        * Referenced by: '<S9>/pwm_BT'
                                        */
  real_T Saturation10_UpperSat;        /* Expression: 1
                                        * Referenced by: '<S10>/Saturation10'
                                        */
  real_T Saturation10_LowerSat;        /* Expression: 0
                                        * Referenced by: '<S10>/Saturation10'
                                        */
  real_T Gain5_Gain;                   /* Expression: .95
                                        * Referenced by: '<S10>/Gain5'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: pi
                                        * Referenced by: '<S10>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -pi
                                        * Referenced by: '<S10>/Saturation1'
                                        */
  real_T Gain3_Gain;                   /* Expression: -1
                                        * Referenced by: '<S10>/Gain3'
                                        */
  real_T uDLookupTable3_tableData[25]; /* Expression: servo_mapping(:,:,4)
                                        * Referenced by: '<S10>/2-D Lookup Table3'
                                        */
  real_T uDLookupTable3_bp01Data[5];   /* Expression: [-1,-0.7071067811865476,0,0.7071067811865476,1]
                                        * Referenced by: '<S10>/2-D Lookup Table3'
                                        */
  real_T uDLookupTable3_bp02Data[5];   /* Expression: [-1,-0.7071067811865476,0,0.7071067811865476,1]
                                        * Referenced by: '<S10>/2-D Lookup Table3'
                                        */
  real_T pwm_servo4_P1;                /* Expression: width
                                        * Referenced by: '<S9>/pwm_servo4'
                                        */
  real_T pwm_servo4_P2;                /* Expression: dtype
                                        * Referenced by: '<S9>/pwm_servo4'
                                        */
  real_T pwm_servo4_P3;                /* Expression: portnum
                                        * Referenced by: '<S9>/pwm_servo4'
                                        */
  real_T pwm_servo4_P4;                /* Expression: stime
                                        * Referenced by: '<S9>/pwm_servo4'
                                        */
  real_T pwm_servo4_P5;                /* Expression: stype
                                        * Referenced by: '<S9>/pwm_servo4'
                                        */
  real_T pwm_servo4_P6;                /* Expression: btype
                                        * Referenced by: '<S9>/pwm_servo4'
                                        */
  real_T Gain2_Gain;                   /* Expression: -1
                                        * Referenced by: '<S10>/Gain2'
                                        */
  real_T uDLookupTable2_tableData[25]; /* Expression: servo_mapping(:,:,3)
                                        * Referenced by: '<S10>/2-D Lookup Table2'
                                        */
  real_T uDLookupTable2_bp01Data[5];   /* Expression: [-1,-0.7071067811865476,0,0.7071067811865476,1]
                                        * Referenced by: '<S10>/2-D Lookup Table2'
                                        */
  real_T uDLookupTable2_bp02Data[5];   /* Expression: [-1,-0.7071067811865476,0,0.7071067811865476,1]
                                        * Referenced by: '<S10>/2-D Lookup Table2'
                                        */
  real_T pwm_servo3_P1;                /* Expression: width
                                        * Referenced by: '<S9>/pwm_servo3'
                                        */
  real_T pwm_servo3_P2;                /* Expression: dtype
                                        * Referenced by: '<S9>/pwm_servo3'
                                        */
  real_T pwm_servo3_P3;                /* Expression: portnum
                                        * Referenced by: '<S9>/pwm_servo3'
                                        */
  real_T pwm_servo3_P4;                /* Expression: stime
                                        * Referenced by: '<S9>/pwm_servo3'
                                        */
  real_T pwm_servo3_P5;                /* Expression: stype
                                        * Referenced by: '<S9>/pwm_servo3'
                                        */
  real_T pwm_servo3_P6;                /* Expression: btype
                                        * Referenced by: '<S9>/pwm_servo3'
                                        */
  real_T Saturation11_UpperSat;        /* Expression: 1
                                        * Referenced by: '<S10>/Saturation11'
                                        */
  real_T Saturation11_LowerSat;        /* Expression: 0
                                        * Referenced by: '<S10>/Saturation11'
                                        */
  real_T Gain4_Gain;                   /* Expression: .95
                                        * Referenced by: '<S10>/Gain4'
                                        */
  real_T Saturation_UpperSat;          /* Expression: pi
                                        * Referenced by: '<S10>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -pi
                                        * Referenced by: '<S10>/Saturation'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S10>/Gain'
                                        */
  real_T uDLookupTable_tableData[25];  /* Expression: servo_mapping(:,:,1)
                                        * Referenced by: '<S10>/2-D Lookup Table'
                                        */
  real_T uDLookupTable_bp01Data[5];    /* Expression: [-1,-0.7071067811865476,0,0.7071067811865476,1]
                                        * Referenced by: '<S10>/2-D Lookup Table'
                                        */
  real_T uDLookupTable_bp02Data[5];    /* Expression: [-1,-0.7071067811865476,0,0.7071067811865476,1]
                                        * Referenced by: '<S10>/2-D Lookup Table'
                                        */
  real_T pwm_servo1_P1;                /* Expression: width
                                        * Referenced by: '<S9>/pwm_servo1'
                                        */
  real_T pwm_servo1_P2;                /* Expression: dtype
                                        * Referenced by: '<S9>/pwm_servo1'
                                        */
  real_T pwm_servo1_P3;                /* Expression: portnum
                                        * Referenced by: '<S9>/pwm_servo1'
                                        */
  real_T pwm_servo1_P4;                /* Expression: stime
                                        * Referenced by: '<S9>/pwm_servo1'
                                        */
  real_T pwm_servo1_P5;                /* Expression: stype
                                        * Referenced by: '<S9>/pwm_servo1'
                                        */
  real_T pwm_servo1_P6;                /* Expression: btype
                                        * Referenced by: '<S9>/pwm_servo1'
                                        */
  real_T Gain1_Gain;                   /* Expression: -1
                                        * Referenced by: '<S10>/Gain1'
                                        */
  real_T uDLookupTable1_tableData[25]; /* Expression: servo_mapping(:,:,2)
                                        * Referenced by: '<S10>/2-D Lookup Table1'
                                        */
  real_T uDLookupTable1_bp01Data[5];   /* Expression: [-1,-0.7071067811865476,0,0.7071067811865476,1]
                                        * Referenced by: '<S10>/2-D Lookup Table1'
                                        */
  real_T uDLookupTable1_bp02Data[5];   /* Expression: [-1,-0.7071067811865476,0,0.7071067811865476,1]
                                        * Referenced by: '<S10>/2-D Lookup Table1'
                                        */
  real_T pwm_servo2_P1;                /* Expression: width
                                        * Referenced by: '<S9>/pwm_servo2'
                                        */
  real_T pwm_servo2_P2;                /* Expression: dtype
                                        * Referenced by: '<S9>/pwm_servo2'
                                        */
  real_T pwm_servo2_P3;                /* Expression: portnum
                                        * Referenced by: '<S9>/pwm_servo2'
                                        */
  real_T pwm_servo2_P4;                /* Expression: stime
                                        * Referenced by: '<S9>/pwm_servo2'
                                        */
  real_T pwm_servo2_P5;                /* Expression: stype
                                        * Referenced by: '<S9>/pwm_servo2'
                                        */
  real_T pwm_servo2_P6;                /* Expression: btype
                                        * Referenced by: '<S9>/pwm_servo2'
                                        */
  real_T Saturation7_UpperSat;         /* Expression: 1
                                        * Referenced by: '<S10>/Saturation7'
                                        */
  real_T Saturation7_LowerSat;         /* Expression: -1
                                        * Referenced by: '<S10>/Saturation7'
                                        */
  real_T Gain6_Gain;                   /* Expression: 3
                                        * Referenced by: '<S13>/Gain6'
                                        */
  uint32_T uDLookupTable3_maxIndex[2]; /* Computed Parameter: uDLookupTable3_maxIndex
                                        * Referenced by: '<S10>/2-D Lookup Table3'
                                        */
  uint32_T uDLookupTable2_maxIndex[2]; /* Computed Parameter: uDLookupTable2_maxIndex
                                        * Referenced by: '<S10>/2-D Lookup Table2'
                                        */
  uint32_T uDLookupTable_maxIndex[2];  /* Computed Parameter: uDLookupTable_maxIndex
                                        * Referenced by: '<S10>/2-D Lookup Table'
                                        */
  uint32_T uDLookupTable1_maxIndex[2]; /* Computed Parameter: uDLookupTable1_maxIndex
                                        * Referenced by: '<S10>/2-D Lookup Table1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_u2pwm_T {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWLogInfo *rtwLogInfo;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;
  void *blockIO;
  const void *constBlockIO;
  void *defaultParam;
  ZCSigState *prevZCSigState;
  real_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  void *zcSignalValues;
  void *inputs;
  void *outputs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T blkStateChange;
  real_T odeY[8];
  real_T odeF[4][8];
  ODE4_IntgData intgData;
  void *dwork;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
    void *xpcData;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T stepSize1;
    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    void *timingData;
    real_T *varNextHitTimesList;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[2];
    time_T offsetTimesArray[2];
    int_T sampleTimeTaskIDArray[2];
    int_T sampleHitArray[2];
    int_T perTaskSampleHitsArray[4];
    time_T tArray[2];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_u2pwm_T u2pwm_P;

/* Block signals (auto storage) */
extern B_u2pwm_T u2pwm_B;

/* Continuous states (auto storage) */
extern X_u2pwm_T u2pwm_X;

/* Block states (auto storage) */
extern DW_u2pwm_T u2pwm_DW;

/* Model entry point functions */
extern void u2pwm_initialize(void);
extern void u2pwm_output(void);
extern void u2pwm_update(void);
extern void u2pwm_terminate(void);

/*====================*
 * External functions *
 *====================*/
extern u2pwm_rtModel *u2pwm(void);
extern void MdlInitializeSizes(void);
extern void MdlInitializeSampleTimes(void);
extern void MdlInitialize(void);
extern void MdlStart(void);
extern void MdlOutputs(int_T tid);
extern void MdlUpdate(int_T tid);
extern void MdlTerminate(void);

/* Real-time Model object */
extern RT_MODEL_u2pwm_T *const u2pwm_M;

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
 * '<Root>' : 'u2pwm'
 * '<S1>'   : 'u2pwm/STOP'
 * '<S2>'   : 'u2pwm/Switch_subsystem'
 * '<S3>'   : 'u2pwm/control limit checking'
 * '<S4>'   : 'u2pwm/ctrl_DP'
 * '<S5>'   : 'u2pwm/ctrl_custom'
 * '<S6>'   : 'u2pwm/ctrl_sixaxis2thruster'
 * '<S7>'   : 'u2pwm/emulate mechanical and electrical system'
 * '<S8>'   : 'u2pwm/indicator'
 * '<S9>'   : 'u2pwm/pwm'
 * '<S10>'  : 'u2pwm/u2pwm'
 * '<S11>'  : 'u2pwm/Switch_subsystem/Switch_function'
 * '<S12>'  : 'u2pwm/indicator/C'
 * '<S13>'  : 'u2pwm/u2pwm/BT_system'
 * '<S14>'  : 'u2pwm/u2pwm/BT_system/If Action Subsystem'
 * '<S15>'  : 'u2pwm/u2pwm/BT_system/If Action Subsystem1'
 * '<S16>'  : 'u2pwm/u2pwm/BT_system/If Action Subsystem2'
 */
#endif                                 /* RTW_HEADER_u2pwm_h_ */

/*========================================================================*
 * NI VeriStand Model Framework code generation
 *
 * Model : u2pwm
 * Model version : 1.51
 * VeriStand Model Framework version : 2017.0.0.143 (2017)
 * Source generated on : Thu Jul 13 11:58:15 2017
 *========================================================================*/
#if !defined(NI_HEADER_u2pwm_h_)
#define NI_HEADER_u2pwm_h_
#ifdef NI_ROOTMODEL_u2pwm

/* main model definitions enabled by makefile */
#include "ni_pglobals.h"
#ifndef NI_VERISTAND_MODELDATAFILE
#ifdef NI_VERISTAND_MAINMODELFILE

/* u2pwm.c definitions */
int READSIDE = 0;
int tid = 0;

#ifdef MULTITASKING

/* multi-rate model */
P_u2pwm_T rtParameter[NUMST+!TID01EQ];
P_u2pwm_T *param_lookup[NUMST][2] = {
  { &rtParameter[0], &rtParameter[1] },

  { &rtParameter[0], &rtParameter[1] },
};

#else

/* single-rate model */
P_u2pwm_T rtParameter[2];

#endif

#else

extern int READSIDE;

#ifdef MULTITASKING

/* multi-rate model */
extern int tid;
extern P_u2pwm_T* param_lookup[NUMST][2];

#else

/* single-rate model */
extern P_u2pwm_T rtParameter[];

#endif
#endif

/* Declare parameter macros */
#define _NI_DEFINE_PARAMS_DBL_BUFFER_
#include "ni_pglobals.h"
#endif
#endif
#endif                                 /* NI_HEADER_u2pwm_h_ */
