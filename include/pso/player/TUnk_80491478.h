#ifndef PSO_PLAYER_TUNK_80491478_H
#define PSO_PLAYER_TUNK_80491478_H
#include "types.h"
#include "pso/object/base/TObjMotion.h"

class TObjEneDubchik;

// One of the parts a TObjEneDubchik falls apart into (TObjEneDubchik::update_fall_apart news one per part).
class TUnk_80491478 : public TObjCollidable {
public:
    TUnk_80491478(s32 index, TObjEneDubchik *parent, NJS_TEXLIST *texlist, Vec *offset);
    virtual ~TUnk_80491478();
    virtual void run_task();
    virtual void render();
    // TObjEneDubchik::update_fall_apart calls these on its parts.
    void cancel_action();
    s32 get_action_priority();  // 1 once it has settled (state 3)
    s16 part_index;  // the ctor's index: picks the model node and the part's direction
    s16 m_ae;
    u8 unk_B0[0x4];
    f32 m_b4;
    u8 unk_B8[0x8];
    s32 rot_y;  // render's rotate_matrix_y angle (inferred)
    u8 unk_C4[0x4];
    s32 m_c8;
    Vec *target;  // &parent->part_offsets[part_index]; run_task homes on it (inferred)
    TObject *m_d0;
    s16 parent_id;  // get_entity_id(parent)
    u8 unk_D6[0x2];
    NJS_TEXLIST *m_d8;
    Vec origin;  // the offset it starts from; run_task stops sliding range away from it (inferred)
    f32 m_e8;
    f32 range;   // 30, or the distance to the csnLookAt hit less 5 (at least 10) (inferred)
    Vec pos;     // where it is drawn (render's post_translate_matrix)
};
typedef char TUnk_80491478_size[sizeof(TUnk_80491478) == 0xFC ? 1 : -1];

#endif
