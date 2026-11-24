/* Ginja's system layer: the video mode, the external frame buffers, GX's setup and the frame flip. */
#define PSO_SDK_COMPACT_MATH
#include "types.h"
#include "pso/render/gjSystem.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/render/GinjaMaterialState.h"
#include "pso/render/GinjaTexture.h"
#include "pso/render/RenderSbssGlobals.h"
#include "pso/render/model_render_state.h"
#include "pso/math/AngleLookup.h"
#include <math.h>
#include <dolphin/os.h>
#include <dolphin/os/OSCache.h>
#include <dolphin/vi.h>
#include <dolphin/gx.h>

u8 video_black_pending = 1;

GXTlutRegion gx_tlut_region_table[0x50];

void *video_initial_display_framebuffer;
void *video_initial_draw_framebuffer;
void *video_current_framebuffer;
GXRenderModeObj *active_gx_render_mode;
s32 video_present_interval_retraces;
u32 last_present_retrace_count;
void *gx_fifo_buffer;
s32 gx_fifo_buffer_size;
GXFifoObj *gx_active_fifo;
GXFifoObj *gx_default_fifo;
FrameUpdateCallback frame_update_callback;

void init_video_and_gx(VideoSystemConfig *config) {
    set_present_interval(config->render_mode, config->present_interval);
    init_locked_cache_heap(config);
    VIConfigure(active_gx_render_mode);
    init_gx_display();
    show_first_framebuffer();
}

void begin_gx_frame(void) {
    GXRenderModeObj *rmode = active_gx_render_mode;
    if (rmode->field_rendering) {
        GXSetViewportJitter(0.0f, 0.0f, rmode->fbWidth, rmode->efbHeight, 0.0f, 1.0f, VIGetNextField());
    } else {
        GXSetViewport(0.0f, 0.0f, rmode->fbWidth, rmode->efbHeight, 0.0f, 1.0f);
    }
    GXInvalidateVtxCache();
    GXInvalidateTexAll();
}

void copy_efb_to_framebuffer(void) {
    GXSetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
    GXSetColorUpdate(GX_TRUE);
    GXCopyDisp(video_current_framebuffer, GX_TRUE);
    GXDrawDone();
}

void present_frame(void) {
    present_frame_and_wait_vsync();
}

void present_frame_and_wait_vsync(void) {
    s32 level;
    VISetNextFrameBuffer(video_current_framebuffer);
    if (video_black_pending != 0) {
        VISetBlack(FALSE);
        video_black_pending = 0;
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
    video_current_framebuffer = (video_current_framebuffer == video_initial_display_framebuffer)
                                    ? video_initial_draw_framebuffer
                                    : video_initial_display_framebuffer;
}

void run_frame_update_callback(void) {
    if (frame_update_callback != NULL) {
        frame_update_callback();
    }
}

void init_locked_cache_heap(VideoSystemConfig *config) {
    void *draw_framebuffer;
    u8 *heap;

    LCEnable();
    video_initial_display_framebuffer = config->display_framebuffer;
    draw_framebuffer = config->draw_framebuffer;
    video_initial_draw_framebuffer = draw_framebuffer;
    video_current_framebuffer = draw_framebuffer;
    gx_fifo_buffer = config->fifo_buffer;
    gx_fifo_buffer_size = config->fifo_size;
    heap = config->heap;
    locked_cache_heap_handle = OSCreateHeap(heap, heap + config->heap_size);
    display_heap_size = config->heap_size;
}

void set_present_interval(GXRenderModeObj *render_mode, s32 interval) {
    if (render_mode != NULL) {
        active_gx_render_mode = render_mode;
    } else {
        get_render_mode_for_tv_format(active_gx_render_mode, &tv_render_mode_obj);
        active_gx_render_mode = &tv_render_mode_obj;
        interval = 1;
    }
    video_present_interval_retraces = interval;
    last_present_retrace_count = VIGetRetraceCount();
}

void init_gx_display(void) {
    s32 i;
    s32 n;
    u32 addr;

    gx_default_fifo = gx_active_fifo = GXInit(gx_fifo_buffer, gx_fifo_buffer_size);
    GXSetViewport(0.0f, 0.0f, active_gx_render_mode->fbWidth, active_gx_render_mode->efbHeight, 0.0f, 1.0f);
    GXSetScissor(0, 0, active_gx_render_mode->fbWidth, active_gx_render_mode->efbHeight);
    GXSetDispCopySrc(0, 0, active_gx_render_mode->fbWidth, active_gx_render_mode->efbHeight);
    GXSetDispCopyDst(active_gx_render_mode->fbWidth, active_gx_render_mode->xfbHeight);
    GXSetDispCopyYScale(GXGetYScaleFactor(active_gx_render_mode->efbHeight, active_gx_render_mode->xfbHeight));
    GXSetCopyFilter(active_gx_render_mode->aa, active_gx_render_mode->sample_pattern, GX_TRUE,
                    active_gx_render_mode->vfilter);
    if (active_gx_render_mode->aa) {
        GXSetPixelFmt(GX_PF_RGB565_Z16, GX_ZC_LINEAR);
    } else {
        GXSetPixelFmt(GX_PF_RGB8_Z24, GX_ZC_LINEAR);
    }
    addr = 0xC0000;
    n = 0;
    for (i = 0; i < 0x40; i++, n++) {
        GXInitTlutRegion(&gx_tlut_region_table[n], addr, GX_TLUT_16);
        addr += 0x200;
    }
    for (i = 0; i < 0x10; i++, n++) {
        GXInitTlutRegion(&gx_tlut_region_table[n], addr, GX_TLUT_256);
        addr += 0x2000;
    }
    GXSetTlutRegionCallback(get_tlut_region);
    GXCopyDisp(video_current_framebuffer, GX_TRUE);
}

void show_first_framebuffer(void) {
    VISetNextFrameBuffer(video_initial_display_framebuffer);
    video_current_framebuffer = video_initial_draw_framebuffer;
    VIFlush();
    VIWaitForRetrace();
    // Non-interlaced modes wait one more retrace.
    if (active_gx_render_mode->viTVmode & 1u) {
        VIWaitForRetrace();
    }
}

void reset_projection_state(void) {
    init_projection_state();
}

void init_projection_state(void) {
    s32 i;
    ScreenProjection *c = &screen_projection;

    c->width = 1.0f;
    c->height = 1.0f;
    c->aspect = 1.0f;
    c->distance = 500.0f;
    c->scale_x = c->width * c->distance;
    c->scale_y = -c->scale_x;
    c->inv_scale_x = 1.0f / c->scale_x;
    c->inv_scale_y = 1.0f / c->scale_y;
    camera_clip_parameters[0] = 60000.0f;
    camera_clip_parameters[1] = 1.0f;
    model_render_flags = 0;
    motion_node_draw_callback = NULL;
    lbl_805D777C = 1.52590219e-05f;
    init_sin_cos_table();
    for (i = 0; i < 6; i++) {
        init_render_context(&render_contexts[i]);
    }
    select_render_context(0);
}

#pragma push
#pragma scheduling off
#pragma peephole off
GXTlutRegion *get_tlut_region(u32 index) {
    return &gx_tlut_region_table[index];
}
#pragma pop

s32 calc_framebuffer_size_bytes(GXRenderModeObj *render_mode) {
    GXRenderModeObj tv_mode;
    if (render_mode == NULL) {
        get_render_mode_for_tv_format(render_mode, &tv_mode);
        render_mode = &tv_mode;
    }
    return VIPadFrameBufferWidth(render_mode->fbWidth) * render_mode->xfbHeight * VI_DISPLAY_PIX_SZ;
}

void set_frame_update_callback(FrameUpdateCallback callback) {
    frame_update_callback = callback;
}

void get_render_mode_for_tv_format(GXRenderModeObj *render_mode, GXRenderModeObj *out) {
    switch (VIGetTvFormat()) {
    case VI_NTSC:
        render_mode = &GXNtsc480IntDf;
        break;
    case VI_PAL:
        render_mode = &GXPal528IntDf;
        break;
    case VI_MPAL:
        render_mode = &GXMpal480IntDf;
        break;
    default:
        OSPanic("gjSystem.c", 832, "invalid TV format\n");
        break;
    }
    GXAdjustForOverscan(render_mode, out, 0, 0);
}

#pragma push
#pragma optimize_for_size on
#pragma use_lmw_stmw off
void init_sin_cos_table(void) {
    s32 j;
    SinCosPair *p;
    s32 i;
    SinCosPair *table;
    f32 angle;
    table = (SinCosPair *)OSGetArenaLo();
    OSSetArenaLo(table + 0x10000);
    sin_cos_table = table;
    p = table;
    for (i = 0, j = 0; i < 0x10000; j += 2, i++) {
        angle = (3.14159203f * (f32)j) / 65536.0f;
        p->sin = sin(angle);
        p->cos = cos(angle);
        p++;
    }
}
#pragma pop

u32 lbl_8058D520[2];
ScreenProjection screen_projection;
f32 camera_clip_parameters[10];
NJS_ARGB model_material_color;
Mtx34 identity_matrix;
GinjaTextureError texture_error;
GinjaSceneState render_contexts[6] ATTRIBUTE_ALIGN(8);
GXRenderModeObj tv_render_mode_obj;
