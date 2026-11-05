#include "types.h"
#include "pso/player/TObjPlayer_8012121C.h"
#include "pso/unk/text_80087278.h"
#include "pso/player/TUnk_804A3358.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/text_801277EC.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/item/TItemEquipVariant_80127844.h"
#include "pso/item/TItem.h"

struct VBase_18 { char pad[0x18]; };

struct VObj_18 : VBase_18 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual void m31();
    virtual void m32();
    virtual s32 m33();
};

struct Rec_80127694 {
    s32 kind;
    s16 uid;
    s16 sub;
    u8 rest[0x5C];
};

extern "C" {
s16 is_status_subsystem_ready__10TObjPlayerFv(void *);
void *get_captured_target_entry(void *, int);
void TUnk_804A3358::emit_marker_effects() {
    u8 pos[12];
    Rec_80127694 rec;
    void *st;
    get_joint_position(2, pos);
    spawn_particle_effect(pos, 0x1BE);
    get_joint_position(3, pos);
    spawn_particle_effect(pos, 0x1BE);
    get_joint_position(0, pos);
    if (is_status_subsystem_ready__10TObjPlayerFv(this->owner) == 2) {
        if (((VObj_18 *)((u8 *)this))->m33() == 1) {
            st = ((TObjPlayer *)(this->owner))->get_extended_state();
            if (get_captured_target_count((s32 *)st) != 0) {
                void *e = get_captured_target_entry(st, 0);
                ((TObjPlayer *)(&rec))->construct_target_cursor_records();
                rec.kind = 1;
                rec.uid = ((TObjPlayer *)e)->get_uid();
                rec.sub = get_captured_target_collider_index(e);
                TObjPlayer::create_tec_zonde(this->owner, (void *)pos, &rec, (void *)3);
            }
        }
    } else {
        ((TObjPlayer *)((u8 *)this))->update_active_game_effect();
    }
}

}

extern "C" {

void __ct__11TItemWeaponFP7TObjectPUc(void *);

extern s32 __vt__13TUnk_804A3358[];

void *TUnk_804A3358::init_variant_34() {
    __ct__11TItemWeaponFP7TObjectPUc(this);
    *(s32 **)((s8 *)this + 0x18) = __vt__13TUnk_804A3358;
    set_weapon_flags(34);
    return this;
}

}

extern "C" {
u8 * init_variant_34__13TUnk_804A3358Fv(void *, s32, void *);
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
u8 *TObjPlayer__sub_801277EC(u8 *arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x1F8));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(init_variant_34__13TUnk_804A3358Fv(temp_r3, tl_05, arg0));
        }
        return var_r0;
    }
    return NULL;
}

}

extern s32 __vt__13TUnk_804A3358[];

TUnk_804A3358::~TUnk_804A3358() {}
