#ifndef PSO_UI_WINDOW_TWINDOWSUBSTATUSDISP_8026F6DC_H
#define PSO_UI_WINDOW_TWINDOWSUBSTATUSDISP_8026F6DC_H

#include "types.h"
#include "pso/system/NinjaTypes.h"

struct TWindowSimpleStatus;
struct WindowDrawContext;

// Points the lock-on child (array entry 1) at the window's player.
void update_lockon_window(TWindowSimpleStatus *window);
// Fans a ring arc from start_angle to end_angle around center in color.
void draw_photon_blast_fan(TWindowSimpleStatus *window, NJS_POINT2 *center, WindowDrawContext *ctx, u32 color, f32 depth_offset, s32 start_angle, s32 end_angle, f32 radius);
// Draws the photon blast charge ring at pos: one full ring in the colour of the
// current hundred and the next colour over the part already charged.
void draw_photon_blast_gauge_ring(TWindowSimpleStatus *window, WindowDrawContext *ctx, const NJS_POINT2 *pos, f32 charge, f32 radius);
void update_photon_blast_player_marker(saddr help, s32 client_id);
// Updates the photon blast marker (array entry 0) for the window's player; none in the lobby.
void update_status_help_item(TWindowSimpleStatus *window);

#endif
