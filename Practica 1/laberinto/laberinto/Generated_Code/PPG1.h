/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : PPG1.h
**     Project     : laberinto
**     Processor   : MKE06Z128VLK4
**     Component   : PPG
**     Version     : Component 02.195, Driver 01.00, CPU db: 3.00.000
**     Repository  : Kinetis
**     Compiler    : GNU C Compiler
**     Date/Time   : 2021-06-07, 15:09, # CodeGen: 11
**     Abstract    :
**         This component "PPG" implements a programmable
**         pulse generator that generates signal with variable
**         duty and variable cycle (period).
**     Settings    :
**          Component name                                 : PPG1
**          Compare - period                               : FTM2_MOD
**          Compare - duty                                 : FTM2_C0V
**          Output pin                                     : PTH0/KBI1_P24/FTM2_CH0
**          Counter                                        : FTM2_CNT
**          Interrupt service/event                        : Disabled
**          Period                                         : 500 Hz
**          Starting pulse width                           : 1 ms
**          Initial polarity                               : low
**          Same period in modes                           : no
**          Component uses entire timer                    : no
**          Initialization                                 : 
**            Enabled in init. code                        : yes
**            Events enabled in init.                      : yes
**          CPU clock/speed selection                      : 
**            High speed mode                              : This component enabled
**            Low speed mode                               : This component disabled
**            Slow speed mode                              : This component disabled
**          Referenced components                          : 
**            PPG_LDD                                      : PPG_LDD
**     Contents    :
**         Enable        - byte PPG1_Enable(void);
**         Disable       - byte PPG1_Disable(void);
**         SetPeriodUS   - byte PPG1_SetPeriodUS(word Time);
**         SetPeriodMS   - byte PPG1_SetPeriodMS(word Time);
**         SetPeriodSec  - byte PPG1_SetPeriodSec(word Time);
**         SetPeriodReal - byte PPG1_SetPeriodReal(float Time);
**         SetFreqHz     - byte PPG1_SetFreqHz(word Freq);
**         SetFreqkHz    - byte PPG1_SetFreqkHz(word Freq);
**         SetFreqMHz    - byte PPG1_SetFreqMHz(word Freq);
**         SetRatio16    - byte PPG1_SetRatio16(word Ratio);
**         SetDutyUS     - byte PPG1_SetDutyUS(word Time);
**         SetDutyMS     - byte PPG1_SetDutyMS(word Time);
**         ClrValue      - byte PPG1_ClrValue(void);
**
**     Copyright : 1997 - 2015 Freescale Semiconductor, Inc. 
**     All Rights Reserved.
**     
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**     
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**     
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**     
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**     
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**     
**     http: www.freescale.com
**     mail: support@freescale.com
** ###################################################################*/
/*!
** @file PPG1.h
** @version 01.00
** @brief
**         This component "PPG" implements a programmable
**         pulse generator that generates signal with variable
**         duty and variable cycle (period).
*/         
/*!
**  @addtogroup PPG1_module PPG1 module documentation
**  @{
*/         

#ifndef __PPG1_H
#define __PPG1_H

/* MODULE PPG1. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */
#include "PpgLdd1.h"

#include "Cpu.h"


#define PPG1_PERIOD_VALUE  PpgLdd1_PERIOD_TICKS /* Initial period value in ticks of the timer. It is available only if the bean is enabled in high speed mode. */
#define PPG1_PERIOD_VALUE_HIGH PpgLdd1_PERIOD_TICKS_0 /* Period value in ticks of the timer in high speed mode. It is available only if the bean is enabled in high speed mode. */
#ifdef PpgLdd1_SPUS_MIN
#define PPG1_SPUS_MIN      PpgLdd1_SPUS_MIN /* Lower bound of interval for parameter of method SetPeriodUS */
#endif
#ifdef PpgLdd1_SPUS_MAX
#define PPG1_SPUS_MAX      PpgLdd1_SPUS_MAX /* Upper bound of interval for parameter of method SetPeriodUS */
#endif
#ifdef PpgLdd1_SPMS_MIN
#define PPG1_SPMS_MIN      PpgLdd1_SPMS_MIN /* Lower bound of interval for parameter of method SetPeriodMS. */
#endif
#ifdef PpgLdd1_SPMS_MAX
#define PPG1_SPMS_MAX      PpgLdd1_SPMS_MAX /* Upper bound of interval for parameter of method SetPeriodMS. */
#endif
#ifdef PpgLdd1_SPSEC_MIN
#define PPG1_SPSEC_MIN     PpgLdd1_SPSEC_MIN /* Lower bound of interval for parameter of method SetPeriodSec. */
#endif
#ifdef PpgLdd1_SPSEC_MAX
#define PPG1_SPSEC_MAX     PpgLdd1_SPSEC_MAX /* Upper bound of interval for parameter of method SetPeriodSec. */
#endif
#ifdef PpgLdd1_SPREAL_MIN
#define PPG1_SPREAL_MIN    PpgLdd1_SPREAL_MIN /* Lower bound of interval for parameter of method SetPeriodReal. */
#endif
#ifdef PpgLdd1_SPREAL_MAX
#define PPG1_SPREAL_MAX    PpgLdd1_SPREAL_MAX /* Upper bound of interval for parameter of method SetPeriodReal. */
#endif
#ifdef PpgLdd1_SFREQ_HZ_MIN
#define PPG1_SFREQ_HZ_MIN  PpgLdd1_SFREQ_HZ_MIN /* Lower bound of interval for parameter of method SetFreqHz. */
#endif
#ifdef PpgLdd1_SFREQ_HZ_MAX
#define PPG1_SFREQ_HZ_MAX  PpgLdd1_SFREQ_HZ_MAX /* Upper bound of interval for parameter of method SetFreqHz. */
#endif
#ifdef PpgLdd1_SFREQ_KHZ_MIN
#define PPG1_SFREQ_KHZ_MIN PpgLdd1_SFREQ_KHZ_MIN /* Lower bound of interval for parameter of method SetFreqkHz. */
#endif
#ifdef PpgLdd1_SFREQ_KHZ_MAX
#define PPG1_SFREQ_KHZ_MAX PpgLdd1_SFREQ_KHZ_MAX /* Upper bound of interval for parameter of method SetFreqkHz. */
#endif
#ifdef PpgLdd1_SFREQ_MHZ_MIN
#define PPG1_SFREQ_MHZ_MIN PpgLdd1_SFREQ_MHZ_MIN /* Lower bound of interval for parameter of method SetFreqMHz. */
#endif
#ifdef PpgLdd1_SFREQ_MHZ_MAX
#define PPG1_SFREQ_MHZ_MAX PpgLdd1_SFREQ_MHZ_MAX /* Upper bound of interval for parameter of method SetFreqMHz. */
#endif



/*
** ===================================================================
**     Method      :  PPG1_Enable (component PPG)
**     Description :
**         This method enables the component - it starts the signal
**         generation. Events may be generated (<DisableEvent>
**         /<EnableEvent>).
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/
#define PPG1_Enable() (PpgLdd1_Enable(PpgLdd1_DeviceData))

/*
** ===================================================================
**     Method      :  PPG1_Disable (component PPG)
**     Description :
**         This method disables the component - it stops the signal
**         generation and events calling. When the timer is disabled,
**         it is possible to call <ClrValue> and <SetValue> methods.
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/
#define PPG1_Disable() (PpgLdd1_Disable(PpgLdd1_DeviceData))

/*
** ===================================================================
**     Method      :  PPG1_SetPeriodUS (component PPG)
**     Description :
**         This method sets the new period of the output signal. The
**         period is expressed in microseconds as a 16-bit unsigned integer
**         number.
**         This method is only available when the runtime setting type
**         'from interval' is selected in the Timing dialog box of
**         the Runtime setting area.
**     Parameters  :
**         NAME       - DESCRIPTION
**         Time       - Period to set [in microseconds]
**                      (992 to 65535 microseconds)
**     Returns     :
**         ---        - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_MATH - Overflow during evaluation
**                           ERR_RANGE - Parameter out of range
** ===================================================================
*/
byte PPG1_SetPeriodUS(word Time);

/*
** ===================================================================
**     Method      :  PPG1_SetPeriodMS (component PPG)
**     Description :
**         This method sets the new period of the output signal. The
**         period is expressed in milliseconds as a 16-bit unsigned integer
**         number.
**         This method is only available when the runtime setting type
**         'from interval' is selected in the Timing dialog box of
**         the Runtime setting area.
**     Parameters  :
**         NAME       - DESCRIPTION
**         Time       - Period to set [in milliseconds]
**                      (1 to 1000 milliseconds)
**     Returns     :
**         ---        - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_MATH - Overflow during evaluation
**                           ERR_RANGE - Parameter out of range
** ===================================================================
*/
byte PPG1_SetPeriodMS(word Time);

/*
** ===================================================================
**     Method      :  PPG1_SetPeriodSec (component PPG)
**     Description :
**         This method sets the new period of the output signal. The
**         period is expressed in seconds as a 16-bit unsigned integer
**         number.
**         This method is only available when the runtime setting type
**         'from interval' is selected in the Timing dialog box of
**         the Runtime setting area.
**     Parameters  :
**         NAME       - DESCRIPTION
**         Time       - Period to set [in seconds]
**                      (1 to 1 seconds)
**     Returns     :
**         ---        - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_MATH - Overflow during evaluation
**                           ERR_RANGE - Parameter out of range
** ===================================================================
*/
byte PPG1_SetPeriodSec(word Time);

/*
** ===================================================================
**     Method      :  PPG1_SetPeriodReal (component PPG)
**     Description :
**         This method sets the new period of the output signal. The
**         period is expressed in seconds as a real number.
**         This method is only available when the runtime setting type
**         'from interval' is selected in the Timing dialog box of
**         the Runtime setting area.
**     Parameters  :
**         NAME       - DESCRIPTION
**         Time       - Period to set [in seconds]
**                      (0.000992 to 1.0 seconds)
**     Returns     :
**         ---        - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_MATH - Overflow during evaluation
**                           ERR_RANGE - Parameter out of range
** ===================================================================
*/
byte PPG1_SetPeriodReal(TPE_Float Time);

/*
** ===================================================================
**     Method      :  PPG1_SetFreqHz (component PPG)
**     Description :
**         This method sets the new frequency of the output signal. The
**         frequency is expressed in Hz as a 16-bit unsigned integer
**         number.
**         This method is only available when the runtime setting type
**         'from interval' is selected in the Timing dialog box of
**         the Runtime setting area.
**     Parameters  :
**         NAME       - DESCRIPTION
**         Freq       - Frequency to set [in Hz]
**                      (1 to 1008 Hz)
**     Returns     :
**         ---        - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_MATH - Overflow during evaluation
**                           ERR_RANGE - Parameter out of range
** ===================================================================
*/
byte PPG1_SetFreqHz(word Freq);

/*
** ===================================================================
**     Method      :  PPG1_SetFreqkHz (component PPG)
**     Description :
**         This method sets the new frequency of the output signal. The
**         frequency is expressed in kHz as a 16-bit unsigned integer
**         number.
**         This method is only available when the runtime setting type
**         'from interval' is selected in the Timing dialog box of
**         the Runtime setting area.
**     Parameters  :
**         NAME       - DESCRIPTION
**         Freq       - Frequency to set [in kHz]
**                      (1 to 1 kHz)
**     Returns     :
**         ---        - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_MATH - Overflow during evaluation
**                           ERR_RANGE - Parameter out of range
** ===================================================================
*/
byte PPG1_SetFreqkHz(word Freq);

/*
** ===================================================================
**     Method      :  PPG1_SetFreqMHz (component PPG)
**     Description :
**         This method sets the new frequency of the output signal. The
**         frequency is expressed in MHz as a 16-bit unsigned integer
**         number.
**         This method is only available when the runtime setting type
**         'from interval' is selected in the Timing dialog box of
**         the Runtime setting area.
**     Parameters  :
**         NAME       - DESCRIPTION
**         Freq       - Frequency to set [in MHz]
**         Note: The interval is too narrow. The method will return
**               just the error code.
**     Returns     :
**         ---        - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_MATH - Overflow during evaluation
**                           ERR_RANGE - Parameter out of range
** ===================================================================
*/
byte PPG1_SetFreqMHz(word Freq);

/*
** ===================================================================
**     Method      :  PPG1_SetRatio16 (component PPG)
**     Description :
**         This method sets a new duty-cycle ratio. Ratio is expressed
**         as a 16-bit unsigned integer number. Value 0 - 65535 value
**         is proportional to ratio 0 - 100%. 
**         Note: Calculated duty depends on the timer possibilities and
**         on the selected period.
**         The method is available only if method <SetPeriodMode> is
**         not selected.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Ratio           - Ratio to set. 0 - 65535 value is
**                           proportional to ratio 0 - 100%
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/
#define PPG1_SetRatio16(Ratio) (PpgLdd1_SetRatio16(PpgLdd1_DeviceData, Ratio))

/*
** ===================================================================
**     Method      :  PPG1_SetDutyUS (component PPG)
**     Description :
**         This method sets the new duty value of the output signal. The
**         duty is expressed in microseconds as a 16-bit unsigned integer
**         number.
**     Parameters  :
**         NAME       - DESCRIPTION
**         Time       - Duty to set [in microseconds]
**                      (0 to 992 us, resp. to 1000000 us
**                      in high speed mode)
**     Returns     :
**         ---        - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_MATH - Overflow during evaluation
**                           ERR_RANGE - Parameter out of range
** ===================================================================
*/
byte PPG1_SetDutyUS(word Time);

/*
** ===================================================================
**     Method      :  PPG1_SetDutyMS (component PPG)
**     Description :
**         This method sets the new duty value of the output signal. The
**         duty is expressed in milliseconds as a 16-bit unsigned integer
**         number.
**     Parameters  :
**         NAME       - DESCRIPTION
**         Time       - Duty to set [in milliseconds]
**                      (0 to 1 ms, resp. to 1000 ms
**                      in high speed mode)
**     Returns     :
**         ---        - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_MATH - Overflow during evaluation
**                           ERR_RANGE - Parameter out of range
** ===================================================================
*/
byte PPG1_SetDutyMS(word Time);

/*
** ===================================================================
**     Method      :  PPG1_ClrValue (component PPG)
**     Description :
**         This method clears (sets to "0" = "Low") timer flip-flop
**         output signal level. It allows to the user to directly set
**         the output pin value (=flip-flop state), and can set the
**         signal polarity. This method only works when the timer is
**         disabled (Disable) otherwise it returns the error code.
**         <ClrValue> and <SetValue> methods are used for setting the
**         initial state.
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_ENABLED - Component is enabled.
**                           Component must be disabled (see "Disable
**                           method")
** ===================================================================
*/
#define PPG1_ClrValue() (PpgLdd1_ClearValue(PpgLdd1_DeviceData))

/* END PPG1. */

#endif 
/* ifndef __PPG1_H */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/