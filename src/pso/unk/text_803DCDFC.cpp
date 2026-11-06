


typedef struct GXRenderModeObj_803DD430 { unsigned char data[0x3C]; } GXRenderModeObj_803DD430;
extern "C" void get_render_mode_for_tv_format(GXRenderModeObj_803DD430 *rmode, GXRenderModeObj_803DD430 *out);


#include "types.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/unk/text_803DCDFC.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/system/movie/TMovie.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/NinjaTypes.h"


struct RMode_803DCDFC {
    u32 viTVmode;
    u16 fbWidth;
    u16 efbHeight;
    u16 xfbHeight;
    u16 viXOrigin;
    u16 viYOrigin;
    u16 viWidth;
    u16 viHeight;
    u32 xFBmode;
    u8 field_rendering;
};
typedef void (*RecoveredCallback_2be3cacebb2e)(void);

struct RMode_803DD0D8 {
    u32 viTVmode;
    u16 fbWidth;
    u16 efbHeight;
    u16 xfbHeight;
    u8 pad0A[0x19 - 0xA];
    u8 aa;
    u8 sample_pattern[12][2];
    u8 vfilter[7];
};
struct Tlut_803DD0D8 { u32 w[4]; };

extern "C" {
u8 lbl_805D46C8 = 0x1;
Tlut_803DD0D8 gx_tlut_region_table[0x500 / sizeof(Tlut_803DD0D8)];
s32 tv_render_mode_obj[16];
}

extern "C" {

u32 VIGetNextField(void);
void GXInvalidateVtxCache(void);
void GXInvalidateTexAll(void);
void GXSetViewportJitter(f32, f32, f32, f32, f32, f32, u32);
void GXSetViewport(f32, f32, f32, f32, f32, f32);
void GXSetZMode(s32, s32, s32);
void GXSetColorUpdate(s32);
void GXCopyDisp(void *, s32);
void GXDrawDone(void);
s32 OSDisableInterrupts(void);
s32 OSRestoreInterrupts(s32);
void VIWaitForRetrace(void);
void VIFlush(void);
void VISetNextFrameBuffer(void *);
void VISetBlack(s32);
u32 VIGetRetraceCount(void);
s32 LCEnable();
s32 OSCreateHeap(int, int);
void *GXInit(s32, s32);
void GXInitTlutRegion(Tlut_803DD0D8 *, u32, u32);
void GXSetDispCopySrc(u16, u16, u16, u16);
void GXSetDispCopyDst(u16, u16);
f32 GXGetYScaleFactor(u16, u16);
u32 GXSetDispCopyYScale(f32);
void Dolphin_GXSetCopyFilter(u8, void *, int, void *);
void *GXSetTlutRegionCallback(void *);
void GXSetPixelFmt(int, int);
void GXSetScissor(u32, u32, u32, u32);
Tlut_803DD0D8 *fn_803DD3C8(s32);

extern s32 *active_gx_render_mode;
extern void *video_current_framebuffer;
extern void *video_initial_draw_framebuffer;
extern void *video_initial_display_framebuffer;
extern u8 lbl_805D46C8;
extern RecoveredCallback_2be3cacebb2e frame_update_callback;
extern u32 last_present_retrace_count;
extern s32 video_present_interval_retraces;
extern s32 gx_fifo_buffer_size;
extern s32 gx_fifo_buffer;
extern s32 display_heap_size;
extern s32 locked_cache_heap_handle;
extern s32 tv_render_mode_obj[];
extern Tlut_803DD0D8 gx_tlut_region_table[];
extern void *lbl_805D771C;
extern void *lbl_805D7720;


#define active_gx_render_mode ((RMode_803DCDFC *)active_gx_render_mode)
void func_803DCDFC__Fv(void) {
    RMode_803DCDFC *rmode = active_gx_render_mode;
    if (rmode->field_rendering) {
        GXSetViewportJitter(0.0f, 0.0f, rmode->fbWidth, rmode->efbHeight, 0.0f, 1.0f, VIGetNextField());
    } else {
        GXSetViewport(0.0f, 0.0f, rmode->fbWidth, rmode->efbHeight, 0.0f, 1.0f);
    }
    GXInvalidateVtxCache();
    GXInvalidateTexAll();
}
#undef active_gx_render_mode


void fn_803DCEC8(void) {
    GXSetZMode(1, 3, 1);
    GXSetColorUpdate(1);
    GXCopyDisp(video_current_framebuffer, 1);
    GXDrawDone();
}


void fn_803DCF0C(void) {
    present_frame_and_wait_vsync();
}
}


void present_frame_and_wait_vsync(void) {
    s32 level;
    VISetNextFrameBuffer(video_current_framebuffer);
    if (lbl_805D46C8 != 0) {
        VISetBlack(0);
        lbl_805D46C8 = 0;
    }
    level = OSDisableInterrupts();
    while (VIGetRetraceCount() < last_present_retrace_count + video_present_interval_retraces - 1) {
        VIWaitForRetrace();
    }
    OSRestoreInterrupts(level);
    VIFlush();
    VIWaitForRetrace();
    last_present_retrace_count = VIGetRetraceCount();
    if (frame_update_callback != NULL) {
        frame_update_callback();
    }
    video_current_framebuffer = (video_current_framebuffer == video_initial_display_framebuffer) ? video_initial_draw_framebuffer : video_initial_display_framebuffer;
}


#define frame_update_callback (*(s32 (**)())&frame_update_callback)

void TMovie::run_callback() {
    if (((s32 (*)()) frame_update_callback) != NULL) {
        frame_update_callback();
    }
}

void init_locked_cache_heap(u8 *arg0) {
    s32 temp_r0;
    s32 start;

    LCEnable();
    (*(s32 *)&video_initial_display_framebuffer) = *(s32 *)((s8 *)arg0 + 8);
    temp_r0 = *(s32 *)((s8 *)arg0 + 0xC);
    (*(s32 *)&video_initial_draw_framebuffer) = temp_r0;
    (*(s32 *)&video_current_framebuffer) = temp_r0;
    gx_fifo_buffer = *(s32 *)((s8 *)arg0 + 0x10);
    gx_fifo_buffer_size = *(s32 *)((s8 *)arg0 + 0x14);
    start = *(s32 *)((s8 *)arg0 + 0x18);
    locked_cache_heap_handle = OSCreateHeap(start, (int) (start + *(s32 *)((s8 *)arg0 + 0x1C)));
    display_heap_size = *(s32 *)((s8 *)arg0 + 0x1C);
}


void set_present_interval(s32 *arg0, s32 arg1) {
    s32 var_r4;
    var_r4 = arg1;
    if (arg0 != NULL) {
        (*(s32 * *)&active_gx_render_mode) = arg0;
    } else {
        get_render_mode_for_tv_format((GXRenderModeObj_803DD430 *) ((*(s32 * *)&active_gx_render_mode)), (GXRenderModeObj_803DD430 *) (tv_render_mode_obj));
        (*(s32 * *)&active_gx_render_mode) = tv_render_mode_obj;
        var_r4 = 1;
    }
    video_present_interval_retraces = var_r4;
    (*(s32 *)&last_present_retrace_count) = VIGetRetraceCount();
}

#define rmode ((RMode_803DD0D8 *)active_gx_render_mode)
void init_gx_display(void) {
    s32 i;
    s32 n;
    u32 addr;

    lbl_805D771C = lbl_805D7720 = GXInit(gx_fifo_buffer, gx_fifo_buffer_size);
    GXSetViewport(0.0f, 0.0f, rmode->fbWidth, rmode->efbHeight, 0.0f, 1.0f);
    GXSetScissor(0, 0, rmode->fbWidth, rmode->efbHeight);
    GXSetDispCopySrc(0, 0, rmode->fbWidth, rmode->efbHeight);
    GXSetDispCopyDst(rmode->fbWidth, rmode->xfbHeight);
    GXSetDispCopyYScale(GXGetYScaleFactor(rmode->efbHeight, rmode->xfbHeight));
    Dolphin_GXSetCopyFilter(rmode->aa, rmode->sample_pattern, 1, rmode->vfilter);
    if (rmode->aa) {
        GXSetPixelFmt(2, 0);
    } else {
        GXSetPixelFmt(0, 0);
    }
    addr = 0xC0000;
    n = 0;
    for (i = 0; i < 0x40; i++, n++) {
        GXInitTlutRegion(&gx_tlut_region_table[n], addr, 1);
        addr += 0x200;
    }
    for (i = 0; i < 0x10; i++, n++) {
        GXInitTlutRegion(&gx_tlut_region_table[n], addr, 0x10);
        addr += 0x2000;
    }
    GXSetTlutRegionCallback((void *)fn_803DD3C8);
    GXCopyDisp((void *)(*(s32 *)&video_current_framebuffer), 1);
}
#undef rmode
extern "C" {

void fn_803DD294(void) {
    VISetNextFrameBuffer((void *) ((*(s32 *)&video_initial_display_framebuffer)));
    (*(s32 *)&video_current_framebuffer) = (*(s32 *)&video_initial_draw_framebuffer);
    VIFlush();
    VIWaitForRetrace();
    if ((u32) (*active_gx_render_mode & 1) != 0) {
        VIWaitForRetrace();
    }
}
#undef frame_update_callback


typedef struct { u8 pad[0x28]; } Elem_803DD300;

typedef struct {
    f32 a;
    f32 b;
    f32 pad8[2];
    f32 e;
    f32 f;
    f32 g;
    f32 h;
    f32 i;
    f32 j;
} Cam_803DD300;

typedef struct {
    f32 a;
    f32 b;
} Pair_803DD300;

void init_render_context(Elem_803DD300 *);
extern Elem_803DD300 render_contexts[6];
extern f32 camera_clip_parameters[];
extern Cam_803DD300 lbl_8058D4F8;
extern s32 motion_node_draw_callback;
extern f32 lbl_805D777C;
extern s32 model_render_flags;


void TKeyBoardControl::update_camera() {
    TCameraCtrl::init_projection_state();
}


s32 TCameraCtrl::init_projection_state() {
    s32 i;
    Cam_803DD300 *c = &lbl_8058D4F8;

    c->h = 1.0f;
    c->i = 1.0f;
    c->j = 1.0f;
    c->g = 500.0f;
    c->a = c->h * c->g;
    c->b = -c->a;
    c->e = 1.0f / c->a;
    c->f = 1.0f / c->b;
    camera_clip_parameters[0] = 60000.0f;
    camera_clip_parameters[1] = 1.0f;
    model_render_flags = 0;
    motion_node_draw_callback = 0;
    lbl_805D777C = 1.52590219e-05f;
    init_sin_cos_table();
    for (i = 0; i < 6; i++) {
        init_render_context(&render_contexts[i]);
    }
    select_render_context(0);
}
}


typedef Tlut_803DD0D8 E_803DD3C8;


struct Fmt_803DD3DC { u8 pad0[4]; u16 w; u16 pad6; u16 h; u8 rest[0x3A]; };

extern "C" {
E_803DD3C8 *fn_803DD3C8(s32 i);
s32 fn_803DD3DC(Fmt_803DD3DC *arg0);
#pragma push
#pragma scheduling off
#pragma peephole off
E_803DD3C8 *fn_803DD3C8(s32 i) {
    return &gx_tlut_region_table[i];
}
#pragma pop

s32 fn_803DD3DC(Fmt_803DD3DC *rmode) {
    Fmt_803DD3DC sp8;
    if (rmode == 0) {
        get_render_mode_for_tv_format((GXRenderModeObj_803DD430 *)rmode, (GXRenderModeObj_803DD430 *)&sp8);
        rmode = &sp8;
    }
    return (u16)((rmode->w + 15) & ~15) * rmode->h * 2;
}


void TKeyBoardControl::set_key_state(s32 arg0) {
    *(s32 *)&frame_update_callback = arg0;
}

}


struct SinCos_803DD4EC { f32 c; f32 s; };

extern "C" {
s32 VIGetTvFormat(void);
void OSPanic(const char *file, int line, const char *msg, ...);
void GXAdjustForOverscan(GXRenderModeObj_803DD430 *rmin, GXRenderModeObj_803DD430 *rmout, u16 hor, u16 ver);
extern GXRenderModeObj_803DD430 GXNtsc480IntDf;
extern GXRenderModeObj_803DD430 GXMpal480IntDf;
extern GXRenderModeObj_803DD430 GXPal528IntDf;
void *OSGetArenaLo(void);
void OSSetArenaLo(void *);
f64 cos(f64);
f64 sin(f64);
extern SinCos_803DD4EC *sin_cos_table;
void get_render_mode_for_tv_format(GXRenderModeObj_803DD430 *rmode, GXRenderModeObj_803DD430 *out) {
    switch (VIGetTvFormat()) {
    case 0:
        rmode = &GXNtsc480IntDf;
        break;
    case 1:
        rmode = &GXPal528IntDf;
        break;
    case 2:
        rmode = &GXMpal480IntDf;
        break;
    default:
        OSPanic("gjSystem.c", 0x340, "invalid TV format\x0A");
        break;
    }
    GXAdjustForOverscan(rmode, out, 0, 0);
}
}
#pragma push
#pragma optimize_for_size on
#pragma use_lmw_stmw off
void init_sin_cos_table(void) {
    s32 j;
    SinCos_803DD4EC *p;
    s32 i;
    SinCos_803DD4EC *base;
    f32 a;
    base = (SinCos_803DD4EC *) OSGetArenaLo();
    OSSetArenaLo((u8 *) base + 0x80000);
    sin_cos_table = base;
    p = base;
    for (i = 0, j = 0; i < 0x10000; j += 2, i++) {
        a = (3.14159203f * (f32) j) / 65536.0f;
        p->c = sin(a);
        p->s = cos(a);
        p++;
    }
}
#pragma pop

extern "C" {
Elem_803DD300 render_contexts[6];
s32 lbl_8058D470[8];
Mtx34 identity_matrix;
NJS_ARGB model_material_color;
f32 camera_clip_parameters[10];
Cam_803DD300 lbl_8058D4F8;
}
