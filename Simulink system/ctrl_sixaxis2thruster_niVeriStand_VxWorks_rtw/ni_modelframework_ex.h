/*========================================================================*
 * NI VeriStand Model Framework
 *
 * Model Framework utility functions.
 *========================================================================*/

#ifndef NI_MODELFRAMEWORK_EX_H
#define NI_MODELFRAMEWORK_EX_H
#include "ni_modelframework.h"

// for virtual signals, addr is offset into virtualmap array that contains indices in NI_Signal
// array corresponding to the non-virtual signals that compose the virtual signal.
// currently unused
#define VIRTUAL_SIG                    2
#define BLOCKIO_SIG                    0
#define EXTIO_SIG                      1
#define EXT_IN                         0
#define EXT_OUT                        1

typedef struct {
  HANDLE flipCriticalSection;
  uint_T copyTaskBitfield;

  // inCriticalSection keeps track of how many entries the TCL has into the critical section
  // presumably, it should only have <= 1, and if it ever goes above that, we will error out.
  // the critical section is acquired BEFORE the call to MdlOutputs, inCriticalSection is incremented AFTER.
  // the critical section is released AFTER the call to MdlUpdate, inCriticalSection is decremented BEFORE.
  // this allows us to use the flag to know when it is valid to probe.
  uint_T inCriticalSection;
} _SITexportglobals;

#if defined(__cplusplus)

extern "C" {

#endif

  /* Implemented by ni_modelframework.c */
  void SetSITErrorMessage(const char *ErrMsg, int32_t Error);

#if defined (VXWORKS) || defined (kNIOSLinux)
#define CRITICAL_SECTION               HANDLE

  void InitializeCriticalSection(CRITICAL_SECTION *CriticalSection);
  HANDLE CreateSemaphore(void* lpSemaphoreAttributes, int lInitialCount, int
    lMaximumCount, char* lpName);
  void EnterCriticalSection(CRITICAL_SECTION *CriticalSection);
  void WaitForSingleObject(HANDLE hHandle, int dwMilliseconds);
  void LeaveCriticalSection(CRITICAL_SECTION *CriticalSection);
  void ReleaseSemaphore(HANDLE hSemaphore, int lReleaseCount, void
                        * lpPreviousCount);
  void DeleteCriticalSection(CRITICAL_SECTION *CriticalSection);
  void CloseHandle(HANDLE hObject);

#endif

#if defined(__cplusplus)

}
#endif
#endif
