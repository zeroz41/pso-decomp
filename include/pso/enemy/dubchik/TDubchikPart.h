#ifndef PSO_ENEMY_DUBCHIK_TDUBCHIKPART_H
#define PSO_ENEMY_DUBCHIK_TDUBCHIKPART_H
#include "types.h"
#include "pso/object/base/TObjMotion.h"

class TObjEneDubchik;
class TeneFakeTecThunderEff;

// One of the parts a TObjEneDubchik falls apart into (TObjEneDubchik::update_fall_apart news one per part).
class TDubchikPart : public TObjCollidable {
public:
    TDubchikPart(s32 index, TObjEneDubchik *parent, NJS_TEXLIST *texlist, Vec *offset);
    virtual ~TDubchikPart();
    virtual void run_task();
    virtual void render();
    // TObjEneDubchik::update_fall_apart calls these on its parts.
    void cancel_action();
    s32 get_action_priority();  // 1 once it has settled (state 3)
    s16 part_index;  // the ctor's index: picks the model node and the part's direction
    s16 state;  // 0 sliding apart, 1 falling, 2 homing on target (cancel_action), 3 settled
    Vec velocity;  // the push it falls apart with; y is its fall speed (gravity 0.109 a frame)
    u8 pad_BC[0x4];
    s32 rot_y;  // render's rotate_matrix_y angle (inferred)
    u8 pad_C4[0x4];
    NJS_OBJECT *part_model;
    Vec *target;  // &parent->part_offsets[part_index]; run_task homes on it (inferred)
    TeneFakeTecThunderEff *thunder_effect;  // the ctor's 0x348-byte TeneFakeTecThunderEff (inferred name)
    s16 parent_id;  // get_entity_id(parent)
    u8 pad_D6[0x2];
    NJS_TEXLIST *part_texlist;
    Vec origin;  // the offset it starts from; run_task stops sliding range away from it (inferred)
    f32 floor_y;  // the ground under it; run_task lands it there
    f32 range;   // 30, or the distance to the csnLookAt hit less 5 (at least 10) (inferred)
    Vec pos;     // where it is drawn (render's post_translate_matrix)
};
LAYOUT_ASSERT(TDubchikPart_size, sizeof(TDubchikPart) == 0xFC);

#endif
