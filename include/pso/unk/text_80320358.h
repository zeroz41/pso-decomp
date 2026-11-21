#ifndef PSO_UNK_TEXT_80320358_H
#define PSO_UNK_TEXT_80320358_H

#include "types.h"
#include "pso/system/RelModuleBuffer.h"

struct MwsfdPly;
struct MwsfdCrePrm;
struct MovieFrameRate;
struct MovieFramePlanes;

// movie.rel install table: its prolog stores one CRI Sofdec MWSFD/GC function per hook, in this order.
// Names follow each target body's own CRI error string; lbl_ entries have no name evidence yet.
extern void (*mwPlyInitSfdFx_hook)(MovieFrameRate *);
extern s32 (*mwPlyFinishSfdFx_hook)();
extern s32 (*mwPlyCalcWorkCprmSfd_hook)(MwsfdCrePrm *);
extern MwsfdPly *(*mwPlyCreateSofdec_hook)(MwsfdCrePrm *);
extern s32 (*mwPlyGetCurFrm_hook)(void **, u32 *);
extern s32 (*mwPlyRelCurFrm_hook)(void **);
extern void (*lbl_805D6B40)();
extern void (*mwPlySetAudioCh_hook)();
extern void (*mwPlySetAudioSw_hook)();
extern void (*mwPlyIsNextFrmReady_hook)();
extern void (*mwPlyGetSyncMode_hook)();
extern void (*mwPlyGetFrmSync_hook)();
extern void (*mwPlyIsPause_hook)();
extern void (*mwPlyGetPlyInf_hook)();
extern void (*mwPlyGetNumDropFrm_hook)();
extern void (*mwPlyGetNumSkipDec_hook)();
extern void (*mwPlyGetNumSkipDisp_hook)();
extern void (*mwPlyGetNumSkipEmptyB_hook)();
extern void (*mwPlyGetNumTotalDec_hook)();
extern void (*mwPlyGetNumDecPool_hook)();
extern void (*lbl_805D6B78)();
extern void (*mwPlySetSyncMode_hook)();
extern void (*mwPlySetFrmSync_hook)();
extern void (*mwPlySetBpicSkip_hook)();
extern void (*mwPlySetEmptyBpicSkip_hook)();
extern void (*mwPlySetLimitTime_hook)();
extern void (*mwPlyStartFnameLp_hook)();
extern void (*mwPlyReleaseLp_hook)();
extern void (*mwPlyStartAfsLp_hook)();
extern void (*mwPlyEntryFname_hook)(MwsfdPly *, const char *);
extern void (*mwPlyStartSeamless_hook)(MwsfdPly *);
extern void (*mwPlyReleaseSeamless_hook)(MwsfdPly *);
extern void (*mwPlyEntryAfs_hook)();
extern void (*mwPlyGetNumSlFiles_hook)();
extern void (*mwPlyGetSlFname_hook)();
extern void (*mwPlyStartAfs_hook)();
extern s32 (*mwPlyFxCnvFrmARGB8888_hook)(s32, s32, s32);
extern void (*mwPlyFxCnvFrmYUV422_hook)();
extern void (*mwPlyFxCnvFrmY84C44_hook)();
extern s32 (*mwPlyFxSetOutBufSize_hook)(s32, s32, s32);
extern void (*mwPlyFxGetOutBufSize_hook)();
extern void (*mwPlyFxSetCompoMode_hook)();
extern void (*mwPlyFxGetCompoMode_hook)();
extern void (*lbl_805D6BD4)();
extern void (*lbl_805D6BD8)();
extern void (*mwPlyFxCnvFrmZ16_hook)();
extern void (*mwPlyFxCnvFrmZ32_hook)();
extern void (*mwPlyFxSetZclip_hook)();
extern void (*mwPlyFxGetZclip_hook)();
extern void (*lbl_805D6BEC)();
extern void (*mwPlyCnvFrm_hook)();
extern void (*lbl_805D6BF4)(u32, s32, s32, MovieFramePlanes *);
extern void (*lbl_805D6BF8)();
extern void (*lbl_805D6BFC)();
extern void (*mwPlyGetAdxtHn_hook)();
extern void (*mwPlyGetInputSj_hook)();
extern void (*mwPlyGetSfdHn_hook)();

#endif
