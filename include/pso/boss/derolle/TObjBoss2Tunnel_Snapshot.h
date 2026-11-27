#ifndef PSO_BOSS_DEROLLE_TOBJBOSS2TUNNEL_SNAPSHOT_H
#define PSO_BOSS_DEROLLE_TOBJBOSS2TUNNEL_SNAPSHOT_H

#include "types.h"

// pos is the top-left corner (x, y); NULL draws at 192, 144.
void draw_screen_snapshot(f32 *pos);
s32 save_screen_snapshot(void);

// Takes a snapshot of the screen inside the C stick frame and saves it to the memory card.
s32 take_snapshot(void);
// Moves the capture frame with the C stick and keeps it on screen.
void move_snapshot_frame(void);
void draw_snapshot_capture_overlay(void);
void load_data_buffers(void);
s32 memcard_check_snapshot(s32 for_save, s32 *error);

struct Vec;
struct NJS_CAMERA;
struct CameraMatrix;

// True when b lies clockwise of a in the XZ plane (a.z * b.x - a.x * b.z < 0).
s32 is_vec_xz_cross_negative(const Vec *a, const Vec *b);
void rotate_vec_xz(const Vec *in, Vec *out, s32 angle);
void rotate_xz_pair_by_angle(f32 *x, f32 *z, s32 angle);

// Carries in through the current matrix and then TCameraCtrl's view matrix into out.
// camera is not read.
void transform_vec_by_camera(NJS_CAMERA *camera, const Vec *in, Vec *out);
// Stores the inverse of the current matrix in view. camera is not read.
void store_inverse_current_matrix(NJS_CAMERA *camera, CameraMatrix *view);

#endif
