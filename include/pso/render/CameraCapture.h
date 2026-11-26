#ifndef PSO_RENDER_CAMERACAPTURE_H
#define PSO_RENDER_CAMERACAPTURE_H

#include "types.h"
#include "pso/render/GinjaMaterialState.h"
#include "pso/render/GinjaRenderTarget.h"

struct Vec;

// The screen capture texture, the shadow-map pass and the projected-texture stages.

enum CameraCaptureFlag {
    CAPTURE_VIEWPORT_CAPTURED = 0x01,   // the capture pass copied the frame into the capture texture
    CAPTURE_OVERLAY_REQUESTED = 0x02,   // draw the capture over the screen (TBoss5GryphonDemo)
    CAPTURE_LIVE_VIEW_RENDERING = 0x04, // a TLiveCameraView is rendering the scene; capture is skipped
    CAPTURE_CLEAR_ON_COPY = 0x08,       // the viewport copy clears the frame buffer
    CAPTURE_SCREEN_BW = 0x10,           // quest opcode set_screen_bw: grey TEV swap for the next frame
};

// Alpha of the capture overlay and the CameraCaptureFlag bits.
extern u8 camera_capture_overlay_alpha;
extern u8 camera_capture_flags;

// The 640x480 capture texture and the 256x256 shadow map.
extern NJS_TEXLIST shared_capture_texture_list;
extern NJS_TEXLIST shadow_map_texture_list;

// The Gol Dragon floor's live-camera render target: a 640x480 texture TLiveCameraView
// renders into.
extern GinjaRenderTarget *camera_render_target_singleton;

u8 get_camera_capture_flags();
s32 is_capture_overlay_ready();
void disable_camera_capture_overlay();
void set_viewport_captured();
s32 is_screen_bw_requested();
void clear_screen_bw_request();
void begin_live_view_render();
void end_live_view_render();

void init_capture_texture(s32 wide);
void release_capture_texture();
void reset_movie_state();
void reset_and_init_capture_texture();
void reset_and_release_capture_texture();
u32 *get_capture_texture_pixels();
void capture_viewport_texture();
void copy_screen_to_texture(s32 mode, NJS_POINT2 *center);
void draw_textured_screen_quad(u32 argb, f32 *pos, f32 *size, s32 cropped);
void draw_screen_quad(u32 argb, s32 cropped, f32 border);

void init_camera_render_target();
void free_camera_render_target();

void init_shadow_map_texture();
void release_shadow_map_texture();
s32 is_shadow_pass_active();
void begin_shadow_map_pass();
void end_shadow_map_pass();
void bind_shadow_map_texture();
s32 is_in_shadow_range(const Vec *pos, f32 radius);
void render_projected_shadow_receiver(const f32 *pos, const s32 *ang);

// The camera's vertical field of view as a 0x10000-per-turn angle.
f32 calc_camera_vertical_fov();
void calc_projection_screen_offset(f32 *x, f32 *y);
void load_projection_tex_matrix(s32 rotation_y);
void load_projected_texture_matrix(f32 aspect);
void setup_particle_tev(s32 modulate);
void setup_capture_blend_tev();
void reset_particle_tev();

#endif
