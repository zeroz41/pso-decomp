#include "types.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/system/vector.h"
#include "pso/TParticleCtrl.h"
#include "pso/player/TObjPlayer.h"

struct VBase_18_1a504b { char pad[0x18]; };

struct VObj_18_1a504b : VBase_18_1a504b {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5(u32);
};

struct List_802370D8 { u32 items[32]; s32 count; };

struct Obj_802370D8 : VObj_18_1a504b {
    void *source;
};

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct Vec_80236EE8 { f32 x, y, z; };

struct Arr_80236EE8 { u32 w[3]; };

struct Tec_80236EE8 {
    u8 pad0[0x8A];
    s16 type;
    u8 pad8C[0xA4 - 0x8C];
    s16 level;
    u8 padA6[2];
    u16 slot;
    u8 padAA[2];
    s32 active;
};

extern "C" {
u16 get_entity_id(u32);
List_802370D8 *find_support_technique_contact_for_target__10TObjPlayerFl(void *, u32);
List_802370D8 *gather_contacts_for_self__10TObjPlayerFl(void *, u32);
void deliver_technique_to_party_targets(Obj_802370D8 *arg0);
void *spawn_particle_effect(void *pos, s32 id);
void *get_player_by_client_id(s32 i);
u32 classify_distance_band__8TTecCtrlFlll(s16, s16, u16);
extern s32 support_tec_range_effect_id_table[];
extern Arr_80236EE8 lbl_8044D908;
void spawn_support_tec_range_effect(Tec_80236EE8 *self);

void spawn_support_tec_range_effect(Tec_80236EE8 *self) {
    s32 kind;
    Vec_80236EE8 pos;
    s32 i;
    u32 band;
    u8 *pl;
    s32 j;
    s32 k;
    if (self->active == 0) {
        return;
    }
    if (self->slot >= 4) {
        return;
    }
    pl = (u8 *)get_player_by_client_id(self->slot);
    if (pl == NULL) {
        return;
    }
    {
        VecCopy((Vec *)&pos, (const Vec *)(pl + 0x38));
        switch (self->type) {
        case 8:
            break;
        case 6:
            kind = 0xF;
            break;
        case 7:
            kind = 0x10;
            break;
        case 9:
            kind = 0xD;
            break;
        case 10:
            kind = 0xA;
            break;
        }
        band = classify_distance_band__8TTecCtrlFlll(kind, self->level, self->slot);
        {
            Arr_80236EE8 fx = lbl_8044D908;
            fx.w[0] = (u32)spawn_particle_effect(&pos, support_tec_range_effect_id_table[band]);
            if (band == 3) {
                fx.w[1] = (u32)spawn_particle_effect(&pos, 0x1F2);
                fx.w[2] = (u32)spawn_particle_effect(&pos, 0x19D);
            }
            switch ((s16)kind) {
            case 14:
                break;
            case 16:
                for (i = 0; i < 3; i++) {
                    if (fx.w[i] != 0) {
                        ((TParticleCtrl *)(fx.w[i]))->set_tint_color(0xFF4DFF99);
                    }
                }
                break;
            case 13:
                for (j = 0; j < 3; j++) {
                    if (fx.w[j] != 0) {
                        ((TParticleCtrl *)(fx.w[j]))->set_tint_color(-0x6667);
                    }
                }
                break;
            case 10:
                for (k = 0; k < 3; k++) {
                    if (fx.w[k] != 0) {
                        ((TParticleCtrl *)(fx.w[k]))->set_tint_color(0xFF337FFF);
                    }
                }
                break;
            }
        }
    }
}

void deliver_technique_to_party_targets(Obj_802370D8 *arg0) {
    List_802370D8 *list;
    s32 i;
    if (*(u32 *)((s8 *)arg0 + 0xDC) == 0) {
        queue_destruction__7TObjectFv(arg0);
        return;
    }
    if (get_entity_id(*(u32 *)((s8 *)arg0 + 0x1C)) < 4) {
        list = gather_contacts_for_self__10TObjPlayerFl(arg0, *(u32 *)((s8 *)arg0 + 0x1C));
    } else {
        list = find_support_technique_contact_for_target__10TObjPlayerFl(arg0, *(u32 *)((s8 *)arg0 + 0x1C));
    }
    for (i = 0; i < list->count; i++) {
        if (TObjPlayer::is_valid_and_active(list->items[i]) != 0) {
            arg0->m5(list->items[i]);
        }
    }
}

}
