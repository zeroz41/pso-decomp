#include "types.h"
#include "pso/system/vector.h"
#include "pso/unk/TUnk_804CC888.h"
#include "pso/TParticleCtrl.h"
#include "pso/player/TObjPlayer.h"

struct Part_80232EC0 { s32 id; u32 flags; u8 pad8[4]; };

struct Profile_80232EC0 { Part_80232EC0 *parts; u32 count; };

struct Task_80232EC0 {
    u8 pad0[0x18];
    void **vt;
    u32 *emitters;
    s32 sound;
    s32 tier;
    s32 level;
    s16 x2c;
    u16 owner;
    u8 pos[0xC];
};

extern "C" {
u16 get_entity_id(void *);
void *spawn_continuous_particle_effect_with_flags(void *parent, s32 idx, s32 flags);
void *mem_alloc(u32 size);
s32 update_technique_slot__10TTecRaFoieFl(s32, s32, s32);
s32 play_sound_effect(s32, void *, s32, s32);
extern Profile_80232EC0 grants_effect_emitter_table[];
}
TUnk_804CC888::TUnk_804CC888(u8 *src, s32 level, TObject *parent) : TObject(parent) {
    u32 i;
    VecCopy((Vec *)(((Task_80232EC0 *)this)->pos), (const Vec *)(src + 0x38));
    ((Task_80232EC0 *)this)->x2c = 0;
    ((Task_80232EC0 *)this)->owner = get_entity_id(src);
    ((Task_80232EC0 *)this)->level = level;
    if (((Task_80232EC0 *)this)->level < 0) {
        ((Task_80232EC0 *)this)->level = 0;
    } else if (level >= 0x1E) {
        ((Task_80232EC0 *)this)->level = 0x1E;
    }
    ((Task_80232EC0 *)this)->tier = TObjPlayer::get_level_tier(((Task_80232EC0 *)this)->level);
    ((Task_80232EC0 *)this)->emitters = (u32 *)mem_alloc(grants_effect_emitter_table[((Task_80232EC0 *)this)->tier].count * 4);
    for (i = 0; i < grants_effect_emitter_table[((Task_80232EC0 *)this)->tier].count; i++) {
        ((Task_80232EC0 *)this)->emitters[i] = (u32)spawn_continuous_particle_effect_with_flags(((Task_80232EC0 *)this)->pos, grants_effect_emitter_table[((Task_80232EC0 *)this)->tier].parts[i].id, 0x10);
        if (((Task_80232EC0 *)this)->emitters[i] != 0) {
            ((TParticleCtrl *)(((Task_80232EC0 *)this)->emitters[i]))->set_owner_id(((Task_80232EC0 *)this)->owner);
        }
    }
    switch (((Task_80232EC0 *)this)->tier) {
    case 0:
        ((Task_80232EC0 *)this)->sound = play_sound_effect(0x4002A90C, ((Task_80232EC0 *)this)->pos, 0, 0);
        if (((Task_80232EC0 *)this)->sound >= 0) {
            update_technique_slot__10TTecRaFoieFl(((Task_80232EC0 *)this)->sound, 0x100, 0);
        }
        break;
    case 1:
        ((Task_80232EC0 *)this)->sound = play_sound_effect(0x4002A90C, ((Task_80232EC0 *)this)->pos, 0, 0);
        break;
    case 2:
    case 3:
        ((Task_80232EC0 *)this)->sound = play_sound_effect(0x4002A90C, ((Task_80232EC0 *)this)->pos, 0, 0);
        if (((Task_80232EC0 *)this)->sound >= 0) {
            update_technique_slot__10TTecRaFoieFl(((Task_80232EC0 *)this)->sound, -0x180, 0);
        }
        break;
    case 4:
        ((Task_80232EC0 *)this)->sound = play_sound_effect(0x4002A90C, ((Task_80232EC0 *)this)->pos, 0, 0);
        if (((Task_80232EC0 *)this)->sound >= 0) {
            update_technique_slot__10TTecRaFoieFl(((Task_80232EC0 *)this)->sound, -0x250, 0);
        }
        break;
    case 5:
        ((Task_80232EC0 *)this)->sound = play_sound_effect(0x4002A90C, ((Task_80232EC0 *)this)->pos, 0, 0);
        if (((Task_80232EC0 *)this)->sound >= 0) {
            update_technique_slot__10TTecRaFoieFl(((Task_80232EC0 *)this)->sound, -0x100, 0);
        }
        break;
    }
}
