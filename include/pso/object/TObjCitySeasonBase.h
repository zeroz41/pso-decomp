#ifndef PSO_OBJECT_TOBJCITYSEASONBASE_H
#define PSO_OBJECT_TOBJCITYSEASONBASE_H
#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct BmlResource;

// Common base of the seasonal city decorations (EasterEgg, ValentineHeart,
// XmasTree, 21_21, SonicAdv2); its vtable follows theirs in CitySeason's .data.
class TObjCitySeasonBase : public TObjCollidable {
public:
    TObjCitySeasonBase(TObject *parent, void *set_data, s32 kind, f32 radius);
    virtual ~TObjCitySeasonBase();
    // The decoration's model resource (city_season_resources[model_index]).
    BmlResource *get_anim_frame();
    s32 advance_anim_time(s32 motion, f32 step);
    // Index into city_season_easter_egg_model_table: each derived constructor
    // passes its own constant, get_anim_frame reads the entry (name inferred).
    s32 model_index;
    // advance_anim_time steps it and wraps it at the motion's last frame; the
    // renders draw the motion at it.
    f32 anim_time;
};

#endif
