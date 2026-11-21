#include "types.h"
#include "pso/unk/text_803DCDB0.h"
#include "pso/unk/text_803DCDFC.h"

extern void *active_gx_render_mode;
extern "C" {
void VIConfigure(void *);
}
void init_video_and_gx(void *arg0) {
    set_present_interval((s32 *)(*(void **)((s8 *)arg0 + 0x0)), (saddr)(*(void **)((s8 *)arg0 + 0x4)));
    init_locked_cache_heap((u8 *)arg0);
    VIConfigure(active_gx_render_mode);
    init_gx_display();
    fn_803DD294();
}
