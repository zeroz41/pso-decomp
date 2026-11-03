#ifndef PSO_UNK_TUNK_804E4B24_H
#define PSO_UNK_TUNK_804E4B24_H
#include "types.h"
#include "pso/TObject.h"
#include <dolphin/mtx/GeoTypes.h>

class TUnk_804E4B24 : public TObject {
public:
    virtual ~TUnk_804E4B24();
    void update_collision();
    virtual void run_task();
    // A tunnel segment; fn_802F1FB0 builds it under the controller's segment list.
    Vec position;      // x follows the controller's segment_x, z scrolls by its scroll_speed
    s32 rotation_x;    // rotate_matrix_yxz angles, zeroed by the constructor
    s32 rotation_y;
    s32 rotation_z;
    s32 controller;    // the segment list's m_up: the TUnk_804E4B3C that spawned it
    s32 model_count;   // boss2_tunnel_effect_name_table[kind].count
    s32 model_indices; // boss2_tunnel_effect_name_table[kind].indices (bml object indices)
    s32 kind;          // spawn's table index (0..4)
    f32 half_length;   // the controller's half_length; destroyed once z <= -half_length
    Mtx34 matrix;      // update_collision: identity, translate(position), rotate(rotation)
};
typedef char TUnk_804E4B24_size[sizeof(TUnk_804E4B24) == 0x78 ? 1 : -1];

#endif
