#include "pso/effect/particle/ParticleFactory.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/object/switch/TOSwitchAttack_801778A4.h"
#include "types.h"
#include "pso/object/switch/TOSwitchAttack.h"

#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/unk/TLobby.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/object/switch/TSwitch.h"

struct Atk_801778A8 {
    s32 a;
    f32 v;
};

struct Rec_801778A8 { u8 pad[0x1C]; Vec pos; u8 pad28[4]; };

struct Mylla_801778A8 { u8 pad[0xA4]; Rec_801778A8 *recs; s32 count; };

struct VBase_801778A8 { char pad[0x18]; };

struct VObj_801778A8 : VBase_801778A8 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20();
    virtual void m21(void *, Atk_801778A8, s32, s32, s32);
};

struct Sw_801778A8 {
    u8 pad0[0x14];
    u32 f14;
    u8 pad18[0x38 - 0x18];
    Vec pos;
    u8 pad44[0x90 - 0x44];
    f32 scale;
    f32 f94;
    f32 f98;
    s32 f9C;
    u16 fA0;
    u16 fA2;
    u16 fA4;
    u8 fA6;
    u8 fA7;
    s32 fA8;
};

extern "C" {
extern const char *TOSwitchAttack__name;
f32 horizontal_distance_squared(void *, void *);

void TOSwitchAttack::render() {  }


#pragma push
#pragma opt_lifetimes off
void TOSwitchAttack::run_task() {
    Sw_801778A8 *o = (Sw_801778A8 *)this;
    u8 busy;
    s32 ok;
    u8 r;
    Mylla_801778A8 *q;
    s32 n;
    s32 i;
    VObj_801778A8 *p;
    s32 end;
    Rec_801778A8 *rec;
    if (o->fA8 > 0) {
        o->fA8--;
    }
    busy = 0;
    if (o->fA4 == 0 && o->f9C == 1) {
        busy = 1;
    }
    if (busy) {
        return;
    }
    ok = 1;
    if (o->fA2 <= 0x100 && is_current_floor_switch_set(o->fA2) == 1) {
        ok = 0;
        o->fA6 = 0;
    }
    if (ok != 1) {
        return;
    }
    if (o->fA0 > 0x100) {
        return;
    }
    r = is_current_floor_switch_set(o->fA0);
    if (r == 1 && o->fA6 == 0) {
        n = TLobby::get_game_mode();
        for (i = 0; i != n; i++) {
            p = (VObj_801778A8 *)resolve_hittable_target(i, 0);
            if (p != NULL) {
                if (((TObjPlayer *)p)->get_floor() == get_current_floor() &&
                    horizontal_distance_squared((u8 *)p + 0x38, &o->pos) < o->f94) {
                    Atk_801778A8 b;
                    b.a = 0;
                    b.v = o->f98;
                    p->m21(o, b, 0, -1, -1);
                }
            }
        }
        end = n + TObjEneDD::get_enemy_count();
        for (i = n; i != end; i++) {
            q = (Mylla_801778A8 *)find_entity_by_id(i);
            if (q != NULL) {
                s32 k;
                rec = q->recs;
                for (k = 0; k != q->count; k++, rec++) {
                    if (horizontal_distance_squared(&rec->pos, &o->pos) < o->f94) {
                        VObj_801778A8 *p2 = (VObj_801778A8 *)resolve_hittable_target(i, k);
                        if (p2 != NULL) {
                            Atk_801778A8 b;
                            b.a = 0;
                            b.v = o->f98;
                            p2->m21(o, b, 0, -1, -1);
                        }
                    }
                }
            }
        }
        switch (o->fA7) {
        case 0:
            spawn_particle_effect_with_flags(&o->pos, 0x45, 0x40);
            spawn_particle_effect_with_flags(&o->pos, 0x189, 0x40);
            TCameraCtrl::set_shake_preset(2);
            play_sound_effect(0x4001C112, &o->pos, 0, 0);
            break;
        case 1:
            TCameraCtrl::set_shake_preset(2);
            break;
        case 2:
            if (o->fA8 == 0) {
                Vec v = o->pos;
                v.y += 10.0f;
                spawn_particle_effect_with_flags(&v, 0x1A6, 0x40);
                spawn_particle_effect_with_flags(&v, 0x1A7, 0x40);
                o->fA8 = 0x3C;
            }
            break;
        case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10:
        case 11: case 12: case 13: case 14: case 15: case 16: case 17:
        case 18: case 19: case 20:
            if (o->f14 == 0) {
                TOSwitchAttack::create_sub((saddr)o, o->fA2, o->fA0, o->fA7 - 3, o->scale);
            }
            break;
        }
        o->f9C = 1;
    }
    o->fA6 = r;
}
#pragma pop

void *TOSwitchAttack::create(void *set_data) {
    return new TOSwitchAttack(tl_05, set_data);
}

void TOSwitchAttack__sub_80177C20(void) {  }
void TOSwitchAttack__sub_80177C24(void) {  }

}
TOSwitchAttack::~TOSwitchAttack() {

}

TOSwitchAttack::TOSwitchAttack(TObject *parent, void *set_data) : TObjBase(parent) {
    m_name = TOSwitchAttack__name;
    apply_object_set_data(set_data);
    init_params();
    m_a6 = 0;
    m_a8 = 0;
}
