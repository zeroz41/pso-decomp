#ifndef PSO_UNK_TUNK_804E4B24_H
#define PSO_UNK_TUNK_804E4B24_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include <dolphin/mtx/GeoTypes.h>

class TObjBoss7Tunnel;

class TUnk_804E4B24 : public TObject {
public:
    TUnk_804E4B24(TObject *parent, s32 kind, Vec *pos, f32 half_length);
    virtual ~TUnk_804E4B24();
    void update_collision();
    virtual void run_task();
    s32 is_in_camera_range();
    // TObjBoss7Tunnel::render draws each segment in three passes: model_indices[0] on draw list 1,
    // model_indices[1] (and [2] for a four-model segment) on draw list 2, then the last one as an effect.
    // Draw lists 1 and 2 are the ones TMainTask::render_task_layer_02 draws in its first and second
    // pass; reading them as the opaque and translucent lists is inferred.
    void draw_opaque_model();
    void draw_translucent_models();
    void draw_tunnel_segment();
    // A tunnel segment; TObjBoss7Tunnel::spawn builds it under the controller's segment list.
    Vec position;      // x follows the controller's segment_x, z scrolls by its scroll_speed
    s32 rotation_x;    // rotate_matrix_yxz angles, zeroed by the constructor
    s32 rotation_y;
    s32 rotation_z;
    TObjBoss7Tunnel *controller; // the segment list's m_up: the TObjBoss7Tunnel that spawned it
    s32 model_count;   // boss2_tunnel_effect_name_table[kind].count
    const s32 *model_indices; // boss2_tunnel_effect_name_table[kind].indices (bml object indices)
    s32 kind;          // spawn's table index (0..4)
    f32 half_length;   // the controller's half_length; destroyed once z <= -half_length
    Mtx34 matrix;      // update_collision: identity, translate(position), rotate(rotation)
};
LAYOUT_ASSERT(TUnk_804E4B24_size, sizeof(TUnk_804E4B24) == 0x78);

#endif
