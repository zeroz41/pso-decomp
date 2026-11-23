#ifndef PSO_EFFECT_ITEM_TITEMEFFARMOR_H
#define PSO_EFFECT_ITEM_TITEMEFFARMOR_H

#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/system/NinjaTypes.h"

struct AnimationMotion;
struct NJS_TEXLIST;
struct NJS_OBJECT;
class TParticleCtrl;
struct TObjPlayer;

// The armour model TObjPlayer::spawn_appearance_effect plays around a player:
// it spins and rises over 29 frames while it fades out, with a particle
// emitter and a pulsing actor light on the player.
struct TItemEffArmor : public TObject {
    TItemEffArmor(TObjPlayer *owner, f32 scale, f32 rise);
    virtual ~TItemEffArmor();
    virtual void render();
    virtual void run_task();

    static const char *class_name;

    TParticleCtrl *particle;
    u8 pad_20[0x4];
    f32 frame;       // 0 to 29, the model's motion frame
    f32 scale;       // x and z scale of the model
    Vec position;    // the owner's position, raised by rise over the effect
    NJS_ARGB color;  // the model's material colour; alpha fades to 0
    u8 pad_48[0x10];
    f32 rise;
    f32 light_level;  // bounces between its start and 1 by light_step
    f32 light_intensity;
    f32 light_step;
    s32 angle_y;
    TObjPlayer *owner;
    NJS_OBJECT *model;
    AnimationMotion *motion;
    NJS_TEXLIST *texture_list;
};

LAYOUT_ASSERT(TItemEffArmor_size, sizeof(TItemEffArmor) == 0x7C);

// While a player wears the armour, every 120 frames: a particle effect on the
// player when its area allows items and a player of the other sex is near.
class TItemEffArmorPulse : public TObject {
public:
    TItemEffArmorPulse(TObject *parent, u16 client_id);
    virtual ~TItemEffArmorPulse();
    virtual void run_task();

    s32 timer;
    u16 client_id;  // the wearer (get_player_by_client_id)
    u8 pad_22[0x2];
};
LAYOUT_ASSERT(TItemEffArmorPulse_size, sizeof(TItemEffArmorPulse) == 0x24);

#endif
