/*
* Copyright(c) 2020 Intel Corporation
*
* This source code is subject to the terms of the BSD 2 Clause License and
* the Alliance for Open Media Patent License 1.0. If the BSD 2 Clause License
* was not distributed with this source code in the LICENSE file, you can
* obtain it at https://www.aomedia.org/license/software-license. If the Alliance for Open
* Media Patent License 1.0 was not distributed with this source code in the
* PATENTS file, you can obtain it at https://www.aomedia.org/license/patent-license.
*/


/*
* This file contains only debug macros that are used during the development
* and are supposed to be cleaned up every tag cycle
* all macros must have the following format:
* - adding a new feature should be prefixed by FTR_
* - tuning a feature should be prefixed by TUNE_
* - enabling a feature should be prefixed by EN_
* - disabling a feature should be prefixed by DIS_
* - bug fixes should be prefixed by FIX_
* - code refactors should be prefixed by RFCTR_
* - code cleanups should be prefixed by CLN_
* - all macros must have a coherent comment explaining what the MACRO is doing
* - #if 0 / #if 1 are not to be used
*/


#ifndef EbDebugMacros_h
#define EbDebugMacros_h

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

// undefining this macro would allow the AVX512 optimization to be enabled by default
#ifndef NON_AVX512_SUPPORT
#define NON_AVX512_SUPPORT
#endif
#define FTR_VBR_MT              1
#if FTR_VBR_MT
#define FTR_VBR_MT_ST1          1 // Storing/Restoring the stat ptrs in PCS
#define FTR_VBR_MT_ST2          1 // Storing/Restoring gf_group in PCS
#define FTR_VBR_MT_ST3          1 // Storing/Restoring rate_control in PCS
#define FTR_VBR_MT_ST4          1 // Replacing gf_interval calculation
#define FTR_VBR_MT_ST5          1 // Restore values from PCS to RC, fix kf_group_bit
#define FTR_VBR_MT_ST6          1 // Move kf_group_bit and kf_group_error_left to rate_control_param_ptr
#define FTR_VBR_MT_REMOVE_DEC_ORDER 0 // Remove the decode order constraint
#define FTR_VBR_MT_LOG          1
#endif
//FOR DEBUGGING - Do not remove
#define NO_ENCDEC               0 // bypass encDec to test cmpliance of MD. complained achieved when skip_flag is OFF. Port sample code from VCI-SW_AV1_Candidate1 branch
#define DEBUG_TPL               0 // Prints to debug TPL
#define DETAILED_FRAME_OUTPUT   0 // Prints detailed frame output from the library for debugging
#define TUNE_CHROMA_SSIM        0 // Allows for Chroma and SSIM BDR-based Tuning
#ifdef __cplusplus
}
#endif // __cplusplus

#endif // EbDebugMacros_h
