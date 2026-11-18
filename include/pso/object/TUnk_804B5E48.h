#ifndef PSO_OBJECT_TUNK_804B5E48_H
#define PSO_OBJECT_TUNK_804B5E48_H
#include "types.h"
#include "pso/object/base/TObjMotion.h"

// Common base of the seasonal city decorations (EasterEgg, ValentineHeart,
// XmasTree, 21_21, SonicAdv2); its vtable follows theirs in CitySeason's .data.
class TUnk_804B5E48 : public TObjCollidable {
public:
    TUnk_804B5E48(TObject *parent, void *set_data, s32 kind, f32 radius);
    virtual ~TUnk_804B5E48();
    void *get_anim_frame();
    s32 advance_anim_time(s32, f32);
    // Index into city_season_easter_egg_model_table: each derived constructor
    // passes its own constant, get_anim_frame reads the entry (name inferred).
    s32 model_index;
    f32 m_b0;
};

#endif
