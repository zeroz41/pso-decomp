#include "pso/system/ResourceFile.h"
#include "types.h"
#include "pso/boss/olgaflow/TBoss6Zanzo.h"
#include "pso/unk/text_80320358.h"
#include "pso/system/memory.h"
#include "pso/system/scene/TScene.h"

// movie.rel hooks (see text_80320358.h). Only movie.rel reads most of them, so the DOL link must keep them.
#pragma push
#pragma force_active on
void (*mwPlyInitSfdFx_hook)(MovieFrameRate *);
s32 (*mwPlyFinishSfdFx_hook)();
s32 (*mwPlyCalcWorkCprmSfd_hook)(MwsfdCrePrm *);
MwsfdPly *(*mwPlyCreateSofdec_hook)(MwsfdCrePrm *);
s32 (*mwPlyGetCurFrm_hook)(void **, u32 *);
s32 (*mwPlyRelCurFrm_hook)(void **);
void (*lbl_805D6B40)();  // calls the VIWaitForRetrace wrapper 0x803CBE00, no arguments
void (*mwPlySetAudioCh_hook)();
void (*mwPlySetAudioSw_hook)();
void (*mwPlyIsNextFrmReady_hook)();
void (*mwPlyGetSyncMode_hook)();
void (*mwPlyGetFrmSync_hook)();
void (*mwPlyIsPause_hook)();
void (*mwPlyGetPlyInf_hook)();
void (*mwPlyGetNumDropFrm_hook)();
void (*mwPlyGetNumSkipDec_hook)();
void (*mwPlyGetNumSkipDisp_hook)();
void (*mwPlyGetNumSkipEmptyB_hook)();
void (*mwPlyGetNumTotalDec_hook)();
void (*mwPlyGetNumDecPool_hook)();
void (*lbl_805D6B78)();  // returns a Bool from field +0x28 of a module-global work struct
void (*mwPlySetSyncMode_hook)();
void (*mwPlySetFrmSync_hook)();
void (*mwPlySetBpicSkip_hook)();
void (*mwPlySetEmptyBpicSkip_hook)();
void (*mwPlySetLimitTime_hook)();
void (*mwPlyStartFnameLp_hook)();
void (*mwPlyReleaseLp_hook)();
void (*mwPlyStartAfsLp_hook)();
void (*mwPlyEntryFname_hook)(MwsfdPly *, const char *);
void (*mwPlyStartSeamless_hook)(MwsfdPly *);
void (*mwPlyReleaseSeamless_hook)(MwsfdPly *);
void (*mwPlyEntryAfs_hook)();
void (*mwPlyGetNumSlFiles_hook)();
void (*mwPlyGetSlFname_hook)();
void (*mwPlyStartAfs_hook)();
s32 (*mwPlyFxCnvFrmARGB8888_hook)(s32, s32, s32);
void (*mwPlyFxCnvFrmYUV422_hook)();
void (*mwPlyFxCnvFrmY84C44_hook)();
s32 (*mwPlyFxSetOutBufSize_hook)(s32, s32, s32);
void (*mwPlyFxGetOutBufSize_hook)();
void (*mwPlyFxSetCompoMode_hook)();
void (*mwPlyFxGetCompoMode_hook)();
void (*lbl_805D6BD4)();  // sets two ints and a switch on an SFX sub-handle (pair of lbl_805D6BD8)
void (*lbl_805D6BD8)();  // reads back the two ints and switch that lbl_805D6BD4 sets
void (*mwPlyFxCnvFrmZ16_hook)();
void (*mwPlyFxCnvFrmZ32_hook)();
void (*mwPlyFxSetZclip_hook)();
void (*mwPlyFxGetZclip_hook)();
void (*lbl_805D6BEC)();  // forwards its arguments to a leaf routine (rel s1+0x38F48)
void (*mwPlyCnvFrm_hook)();
void (*lbl_805D6BF4)(u32, s32, s32, MovieFramePlanes *);  // fills a frame plane/size record from a frame
void (*lbl_805D6BF8)();  // frame plane helper, then the leaf converter at rel s1+0x3899C
void (*lbl_805D6BFC)();  // frame plane helper, then the leaf converter at rel s1+0x38708
void (*mwPlyGetAdxtHn_hook)();
void (*mwPlyGetInputSj_hook)();
void (*mwPlyGetSfdHn_hook)();
#pragma pop

struct S_80320358 {
    void *a;
    void *b;
};

extern "C" {
s32 OSLink(void *, void *);
void OSUnlink(void *);
S_80320358 *fn_80320358(S_80320358 *arg0, s16 arg1);

S_80320358 *fn_80320358(S_80320358 *arg0, s16 arg1) {
    u8 *t;
    if (arg0 != NULL) {
        t = (u8 *)fn_803204B0(arg0);
        if (t != NULL) {
            (*(void (**)(void))(t + 0x38))();
        }
        if (arg0->b != NULL) {
            OSUnlink(arg0->b);
            xfree(arg0->b);
            arg0->b = NULL;
        }
        if (arg0->a != NULL) {
            xfree(arg0->a);
            arg0->a = NULL;
        }
        if (arg1 > 0) {
            ::operator delete(arg0);
        }
    }
    return arg0;
}

#pragma push
#pragma fp_contract on
u8 *load_rel_module(u8 *arg0, s32 arg1) {
    u8 *temp_r3;
    s32 size;
    u32 size2;
    *(void **)((s8 *)arg0 + 0) = NULL;
    *(void **)((s8 *)arg0 + 4) = NULL;
    size = get_resource_file_size((const char *)arg1);
    if (size > 0) {
        *(void **)((s8 *)arg0 + 4) = xmalloc(size);
        if ((void *) *(void **)((s8 *)arg0 + 4) == NULL) {
            return arg0;
        }
        read_disc_file((const char *)arg1, *(void **)((s8 *)arg0 + 4));
        size2 = *(u32 *)((s8 *)(*(void **)((s8 *)arg0 + 4)) + 0x20);
        if (size2 != 0U) {
            *(void **)((s8 *)arg0 + 0) = xmalloc(size2);
            if ((void *) *(void **)((s8 *)arg0 + 0) == NULL) {
                return arg0;
            }
        }
        OSLink((void *) (*(void **)((s8 *)arg0 + 4)), (void *) (*(void **)((s8 *)arg0 + 0)));
        temp_r3 = (u8 *)fn_803204B0(arg0);
        if (temp_r3 != NULL) {
            (*(s32 (**)())((s8 *)temp_r3 + 0x34))();
        }
        goto block_8;
    }
block_8:
    return arg0;
}
#pragma pop

}
