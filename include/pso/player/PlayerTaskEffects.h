#ifndef PSO_PLAYER_PLAYERTASKEFFECTS_H
#define PSO_PLAYER_PLAYERTASKEFFECTS_H

#include "types.h"
#include <dolphin/mtx/GeoTypes.h>

// Where a player appears on the next floor when an override is set (12 slots,
// one per client id).
struct ArrivalOverride {
    s32 active;
    s32 heading;
    Vec pos;

    Vec *get_pos();
    s32 get_heading();
    void set_active(s32 v);
    s32 get_active();
};

// Clears an override: inactive, heading 0, at the origin.
void init_arrival_override(ArrivalOverride *entry);

extern ArrivalOverride player_arrival_overrides[12];

// Overrides where player `slot` appears on the next floor: at `pos`, facing `heading`.
void set_arrival_override_pos(u16 slot, s32 heading, const Vec *pos);

// Overrides where player `slot` appears on the next floor: at (x, y, z),
// facing `heading`.
void set_arrival_override_coords(u16 slot, s32 heading, f32 x, f32 y, f32 z);

struct TObjPlayer;

// Puts `pos` over `player`'s head, 1.2 body proportions above its feet: where the
// lobby marker is drawn.
void calc_marker_position(Vec *pos, TObjPlayer *player);

#endif
