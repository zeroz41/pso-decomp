#ifndef PSO_RENDER_GJSYSTEM_H
#define PSO_RENDER_GJSYSTEM_H

#include "types.h"
#include <dolphin/mtx/GeoTypes.h>

// The SDK headers clash with the game's C library headers, so the GX types are
// named by their struct tags here.
struct _GXRenderModeObj;
struct _GXTlutRegion;

#ifdef __cplusplus
extern "C" {
#endif

// What init_video_and_gx sets the video system up from: the render mode (NULL: the console's TV format), the
// retraces per frame, the two external frame buffers, the GX command FIFO and the heap texture pixels are allocated from.
typedef struct VideoSystemConfig {
    struct _GXRenderModeObj *render_mode;
    s32 present_interval;
    u8 *display_framebuffer;
    u8 *draw_framebuffer;
    u8 *fifo_buffer;
    u32 fifo_size;
    u8 *heap;
    u32 heap_size;
} VideoSystemConfig;

// The screen the view projects onto: per-axis scale (distance times the
// screen size, y flipped), the centre and the reciprocals of the scales.
typedef struct ScreenProjection {
    f32 scale_x;
    f32 scale_y;
    f32 center_x;
    f32 center_y;
    f32 inv_scale_x;
    f32 inv_scale_y;
    f32 distance;
    f32 width;
    f32 height;
    f32 aspect;  // height / width
} ScreenProjection;

typedef void (*FrameUpdateCallback)(void);

void init_video_and_gx(VideoSystemConfig *config);
// Sets the viewport for the render mode (jittered by field when field rendering) and drops GX's vertex and texture caches.
void begin_gx_frame(void);
// Copies the embedded frame buffer to the current external frame buffer and waits for GX to finish.
void copy_efb_to_framebuffer(void);
void present_frame(void);
// Shows the current frame buffer at the next retrace, holding the frame to the present interval, runs the frame
// update callback and swaps the draw and display buffers.
void present_frame_and_wait_vsync(void);
void run_frame_update_callback(void);
void init_locked_cache_heap(VideoSystemConfig *config);
// Takes the render mode (NULL: the one for the console's TV format, one retrace per frame) and the retraces per frame.
void set_present_interval(struct _GXRenderModeObj *render_mode, s32 interval);
void init_gx_display(void);
// Shows the display buffer and makes the draw buffer current.
void show_first_framebuffer(void);
void reset_projection_state(void);
// Fills the screen projection defaults, the sin/cos table and the render contexts.
void init_projection_state(void);
struct _GXTlutRegion *get_tlut_region(u32 index);
// Bytes of one 16-bit external frame buffer for the render mode (NULL: the console's TV format).
s32 calc_framebuffer_size_bytes(struct _GXRenderModeObj *render_mode);
void set_frame_update_callback(FrameUpdateCallback callback);
// Copies the render mode of the console's TV format, adjusted for overscan, into out.
void get_render_mode_for_tv_format(struct _GXRenderModeObj *render_mode, struct _GXRenderModeObj *out);
void init_sin_cos_table(void);

extern struct _GXRenderModeObj *active_gx_render_mode;
// The render mode for the console's TV format, used when no render mode is given.
extern struct _GXRenderModeObj tv_render_mode_obj;
extern void *video_current_framebuffer;
extern void *video_initial_draw_framebuffer;
extern void *video_initial_display_framebuffer;
extern FrameUpdateCallback frame_update_callback;
extern ScreenProjection screen_projection;
// [0] far and [1] near clip distance, [2..5] the screen bounds of [6..9]
// relative to the screen centre.
extern f32 camera_clip_parameters[10];
// The identity matrix push_matrix_from starts a fresh stack entry from.
extern Mtx34 identity_matrix;

#ifdef __cplusplus
}
#endif

#endif
