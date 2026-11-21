#include "pso/system/RelModuleBuffer.h"
#include <dolphin/os/OSLink.h>
#include "pso/system/ResourceFile.h"
#include "types.h"
#include "pso/unk/text_80320358.h"
#include "pso/system/memory.h"

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

extern "C" {
RelModuleBuffer *destroy_rel_module(RelModuleBuffer *module, s16 should_delete) {
    if (module != NULL) {
        OSModuleHeader *image = get_rel_module_image(module);
        if (image != NULL) {
            ((void (*)())image->epilog)();
        }
        if (module->image != NULL) {
            OSUnlink(&module->image->info);
            xfree(module->image);
            module->image = NULL;
        }
        if (module->bss != NULL) {
            xfree(module->bss);
            module->bss = NULL;
        }
        if (should_delete > 0) {
            ::operator delete(module);
        }
    }
    return module;
}

#pragma push
#pragma fp_contract on
RelModuleBuffer *load_rel_module(RelModuleBuffer *module, const char *filename) {
    module->bss = NULL;
    module->image = NULL;
    s32 size = get_resource_file_size(filename);
    if (size > 0) {
        module->image = (OSModuleHeader *)xmalloc(size);
        if (module->image == NULL) {
            return module;
        }
        read_disc_file(filename, module->image);
        u32 bss_size = module->image->bssSize;
        if (bss_size != 0) {
            module->bss = xmalloc(bss_size);
            if (module->bss == NULL) {
                return module;
            }
        }
        OSLink(&module->image->info, module->bss);
        OSModuleHeader *image = get_rel_module_image(module);
        if (image != NULL) {
            ((void (*)())image->prolog)();
        }
    }
    return module;
}
#pragma pop

OSModuleHeader *get_rel_module_image(RelModuleBuffer *module) {
    return module->image;
}
}
