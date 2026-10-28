#include "pso/system/NinjaTypes.h"
#include "types.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/system/vector.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TUnk_804F0A00.h"
#include "pso/player/TUnk_804F0AF8.h"
#include "pso/player/TUnk_804F0908.h"
#include "pso/player/TUnk_804F0810.h"

struct Base_8034EFDC { char pad[0x18]; };
struct VObj_8034EFDC : Base_8034EFDC {
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
    virtual void m33();
    virtual void m34();
    virtual void m35();
    virtual void m36();
    virtual void m37();
    virtual void m38();
    virtual void m39();
    virtual void m40();
    virtual void m41();
    virtual void m42();
    virtual void m43();
    virtual void m44();
    virtual void m45();
    virtual void m46();
    virtual void m47();
    virtual void m48();
    virtual void m49();
    virtual void m50();
    virtual void m51();
    virtual void m52();
    virtual void m53();
    virtual void m54();
    virtual void m55();
    virtual void m56();
    virtual void m57();
    virtual void m58();
    virtual void m59();
    virtual void m60();
    virtual void m61();
    virtual void m62();
    virtual void m63(s32, void *);
};

struct RecoveredGlobal_8034F754_lbl_804F0A00 {
    s32 value;
    u8 remaining[0xF4];
};

struct O_8034F590 { u8 pad[0x40]; u32 flags; u8 pad2[0x70 - 0x44]; void *f70; void *f74; };

struct Elem_80125628 { u8 pad[0x1c]; u8 f1c[0x2c - 0x1c]; };

struct Obj_80125628 { u8 pad[0xa4]; Elem_80125628 *elems; };

struct Ctx_80125628 { Obj_80125628 *obj; s32 idx; };

struct P_8034F020 { u8 pad0[0x1F8]; s32 f1F8; };

typedef struct SlicerLaunchData_8012D9C8 {
    u16 player; u16 pad;
    void *textures; void *model; u32 weapon;
    s16 kind, stage; f32 multiplier; f32 color[4];
    s32 facing, spin; f32 first[3], second[3];
} SlicerLaunchData_8012D9C8;

struct Elem_8034F204 { u8 x[0x2C]; };

struct Tbl_8034F204 { u8 pad[0x1C]; Elem_8034F204 arr[1]; };

struct Info_8034F4FC {
    u8 pad0[0x10];
    s32 f10;
    u8 pad14[0x80 - 0x14];
};

extern "C" {
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
u8 *TObjPlayer__sub_8034F1AC(u8 *arg0);
void TItemWeapon__ct(void *, void *);
void set_status_flags__10TObjPlayerFUl(void *, int);
}
extern s32 lbl_804F0A00[];
u8 *construct_gi_gue_bazooka(u8 *arg0, u8 *arg1, s32 _w2);
extern "C" {
void init_fire_explosion_config__10TObjPlayerFPvPv(void *a, O_8034F590 *o);
s32 rotate_matrix_z(s32, s32);
void init_slicer_launch_state(void *arg0);
u16 obj_getField1c(void *);
s16 TObjPlayer__sub_801D2F4C(s16 *arg0);
s16 get_validated_attack_stage(u8 *arg0);
f32 query_extended_state__10TObjPlayerFv(void *);
void get_weapon_color__11TItemWeaponFPv(f32 *, void *);
u8 *create__10TTecSlicerFPUs(SlicerLaunchData_8012D9C8 *);
extern const f32 lbl_805DFDF8;
void launch_rappys_fan_slicer__10TObjPlayerFPv(u8 *weapon);
s32 spawn_particle_effect(void *, s32);
void *find_entity_by_id(s32);
s32 construct_explosion_collider__13TUnk_804A2548Fv(void *, s32, void *);
void *__nw__7TObjectFUl(u32);
s32 create_fire_explosion_effect(void *, void *, s32, s32, f32);
void *TObjPlayer__sub_802E449C(void *a0);
extern s32 tl_particle;
extern const f32 lbl_805DFE00;
void *__dt__13TUnk_804F0810Fv(void *arg0, s16 arg1);
void *__dt__13TUnk_804F0908Fv(void *arg0, s16 arg1);
void *__dt__13TUnk_804F0A00Fv(void *arg0, s16 arg1);
void *__dt__13TUnk_804F0AF8Fv(void *arg0, s16 arg1);
s32 rotate_matrix_x(s32, s32);
int update_trail_slot__11TItemWeaponFPvi(void*, void*);
void draw_weapon_at_joint(s32 arg0, s8 arg1);
void *__dt__11TItemWeaponFv(void *arg0, s16 arg1);

void TUnk_804F0810::emit_marker_effects() {
    u8 sp8[0x18];
    struct VObj_8034EFDC *o = (struct VObj_8034EFDC *)this->player;
    o->m63(0x30, sp8);
    spawn_particle_effect(sp8, 0x1D0);
}

void TObjPlayer::rotate_by_player_list() {
    switch (TObjPlayer::get_player_list()) {
    case 1:
        ((s32)rotate_matrix_z(0, (s32)(((P_8034F020 *)this)->f1F8)));
        break;
    }
}

void TUnk_804F0810::reserved_53() { draw_weapon_at_joint((s32)this, (s8)((void*)49)); update_trail_slot__11TItemWeaponFPvi(this, (void*)0); update_trail_slot__11TItemWeaponFPvi(this, (void*)1); }
void TUnk_804F0810::update_idle() { TObjPlayer::add_angle_clamped((s32 *)((char*)this + 0x1f8), (s32)((void*)(1820)), (s32)((void*)(13653))); }
void TUnk_804F0810::update_attack() { TObjPlayer::add_angle_clamped((s32 *)((char*)this + 0x1f8), (s32)((void*)(-4551)), (s32)((void*)(0))); }

extern s32 lbl_804F0810[];

void *__dt__13TUnk_804F0810Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804F0810;
        __dt__11TItemWeaponFv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}

void *TUnk_804F0810::enter_timed_state(s32 _w1, void *_w2) {
    TItemWeapon__ct((void *)this, (void *)_w1);
    *(s32 **)((s8 *)this + 0x18) = lbl_804F0810;
    set_status_flags__10TObjPlayerFUl(this, 1);
    *(u32 *)&this->unk_1F8 = 13653;
    return this;
}

extern s32 lbl_804F0908[];

u8 *TObjPlayer__sub_8034F1AC(u8 *arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x1FC));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(((u8 *)((TUnk_804F0810 *)temp_r3)->enter_timed_state(tl_05, arg0)));
        }
        return var_r0;
    }
    return NULL;
}
void TObjPlayer::spawn_particle_at_entity_slot(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 *temp_r5;
    void *entity;
    entity = find_entity_by_id(arg2);
    if (entity != NULL) {
        temp_r5 = *(u8 **)((s8 *)entity + 0xA4);
        if ((temp_r5 != NULL) && (arg3 < (s32) *(s32 *)((s8 *)entity + 0xA8))) {
            spawn_particle_effect(&((Tbl_8034F204 *)temp_r5)->arr[arg3], 0x1BF);
        }
    }
}

void launch_rappys_fan_slicer__10TObjPlayerFPv(u8 *weapon) {
    f32 tmp[4];
    SlicerLaunchData_8012D9C8 launch;
    u8 *t;
    init_slicer_launch_state(&launch);
    launch.player = obj_getField1c(*(u8 * *)&((TUnk_804F0908 *)weapon)->player);
    launch.weapon = ((TItem *)weapon)->get_item_id();
    launch.textures = *(void **)((s8 *)weapon + 0x24);
    launch.model = *(void **)((s8 *)weapon + 0x188);
    launch.kind = TObjPlayer__sub_801D2F4C((s16 *)(*(u8 * *)&((TUnk_804F0908 *)weapon)->player + 0x7CC));
    launch.stage = get_validated_attack_stage(*(u8 * *)&((TUnk_804F0908 *)weapon)->player + 0x7CC);
    launch.multiplier = query_extended_state__10TObjPlayerFv(*(u8 * *)&((TUnk_804F0908 *)weapon)->player);
    get_weapon_color__11TItemWeaponFPv(tmp, weapon);
    copy_argb((NJS_ARGB *)launch.color, (NJS_ARGB *)tmp);
    launch.facing = *(s32 *)((s8 *)(*(u8 * *)&((TUnk_804F0908 *)weapon)->player) + 0x60);
    launch.spin = 0;
    ((TObjPlayer *)weapon)->draw_icon(3, (s32)launch.first);
    ((TObjPlayer *)weapon)->draw_icon(2, (s32)launch.second);
    t = create__10TTecSlicerFPUs(&launch);
    if (t != NULL) {
        *(s32 *)((s8 *)t + 0x5C) += 0x4000;
        *(f32 *)((s8 *)t + 0x68) = lbl_805DFDF8;
        *(f32 *)((s8 *)t + 0x6C) = lbl_805DFDF8;
        *(f32 *)((s8 *)t + 0x70) = lbl_805DFDF8;
        *(s32 *)((s8 *)t + 0x13C) = 0;
    }
}

void *__dt__13TUnk_804F0908Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804F0908;
        __dt__11TItemWeaponFv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}

void *TUnk_804F0908::construct_rappys_fan(s32 _w1, void *_w2) {
    TItemWeapon__ct((void *)this, (void *)_w1);
    *(s32 **)((s8 *)this + 0x18) = lbl_804F0908;
    *(s32 **)((s8 *)this + 0x1F4) = ((s32 *)TObjPlayer::spawn_particle_at_entity_slot);
    set_status_flags__10TObjPlayerFUl(this, 2);
    return this;
}

u8 *TObjPlayer::create_rappys_fan() {
    u8 *temp_r3;
    u8 *var_r0;
    if (this != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x1F8));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(((u8 *)((TUnk_804F0908 *)temp_r3)->construct_rappys_fan(tl_05, this)));
        }
        return var_r0;
    }
    return NULL;
}

void TObjPlayer::spawn_fire_explosion_for_item(s32 arg0, s32 arg1) {
    u32 temp_r3 = (u32)find_item_by_id(arg0);
    if (temp_r3 != 0U) {
        TObjPlayer::spawn_fire_explosion(temp_r3, arg1);
    }
}

void TObjPlayer::spawn_fire_explosion_at_item(s32 arg0, s32 arg1) {
    Ctx_80125628 *ctx = (Ctx_80125628 *)arg1;
    u32 p = (u32)find_item_by_id(arg0);
    if (p != 0U) {
        TObjPlayer::spawn_fire_explosion(p, (s32)((s32)ctx->obj->elems[ctx->idx].f1c));
    }
}

s32 TObjPlayer::spawn_fire_explosion(u32 a0, s32 a1) {
    Info_8034F4FC info;
    void *o;
    TObjPlayer__sub_802E449C(&info);
    ((TObjPlayer *)a0)->fill_status_info(&info);
    VecCopy((Vec *)&info, (const Vec *)a1);
    info.f10 = 0xA;
    o = __nw__7TObjectFUl(0xC8);
    if (o != NULL) {
        construct_explosion_collider__13TUnk_804A2548Fv(o, tl_05, &info);
    }
    o = __nw__7TObjectFUl(0x64);
    if (o != NULL) {
        ((s32 (*)(f32, void *, void *, s32, s32))create_fire_explosion_effect)(lbl_805DFE00, o, &info, 0, tl_particle);
    }
}

void init_fire_explosion_config__10TObjPlayerFPvPv(void *a, O_8034F590 *o) {
    o->f74 = (void *)TObjPlayer::spawn_fire_explosion_at_item;
    o->f70 = (void *)TObjPlayer::spawn_fire_explosion_for_item;
    o->flags |= 0x80;
}

void TObjPlayer::pose_gi_gue_bazooka_nodes() {
    s32 player_list;

    player_list = TObjPlayer::get_player_list();
    switch (player_list) {
    case 2:
        rotate_matrix_x(0, *(s32 *)&this->unk_1F8);
        return;
    case 3:
        rotate_matrix_x(0, this->m_1fc);
        return;
    case 5:
        rotate_matrix_z(0, *(s32 *)&this->unk_200);
        return;
    case 4:
        rotate_matrix_z(0, -*(s32 *)&this->unk_200);
        return;
    }
}

void TUnk_804F0A00::update_idle() { TObjPlayer::add_angle_clamped((s32 *)((char*)this + 0x1f8), (s32)((void*)((void*)1820)), (s32)((void*)((void*)7281))); TObjPlayer::add_angle_clamped((s32 *)((char*)this + 0x1fc), (s32)((void*)((void*)-1820)), (s32)((void*)((void*)-5461))); TObjPlayer::add_angle_clamped((s32 *)((char*)this + 0x200), (s32)((void*)((void*)1820)), (s32)((void*)((void*)9102))); }

void TUnk_804F0A00::update_attack() { TObjPlayer::add_angle_clamped((s32 *)((char*)this + 0x1f8), (s32)((void*)((void*)-3640)), (s32)((void*)((void*)0))); TObjPlayer::add_angle_clamped((s32 *)((char*)this + 0x1fc), (s32)((void*)((void*)2730)), (s32)((void*)((void*)0))); TObjPlayer::add_angle_clamped((s32 *)((char*)this + 0x200), (s32)((void*)((void*)-1820)), (s32)((void*)((void*)0))); }

void *__dt__13TUnk_804F0A00Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804F0A00;
        __dt__11TItemWeaponFv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}
}

typedef char RecoveredGlobal_8034F754_lbl_804F0A00_size[sizeof(RecoveredGlobal_8034F754_lbl_804F0A00) == 0xF8 ? 1 : -1];
u8 *construct_gi_gue_bazooka(u8 *arg0, u8 *arg1, s32 _w2) {
    TItemWeapon__ct(arg0, arg1);
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_8034F754_lbl_804F0A00 *)&lbl_804F0A00).value;
    set_status_flags__10TObjPlayerFUl(arg0, 0x8000);
    *(s32 *)((s8 *)arg0 + 0x1F8) = -0x1C71;
    ((TUnk_804F0A00 *)arg0)->m_1fc = -0x1555;
    *(s32 *)((s8 *)arg0 + 0x200) = 0x238E;
    return arg0;
}

u8 *TObjPlayer::create_gi_gue_bazooka(s32 arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != 0) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x204));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(construct_gi_gue_bazooka((u8 *)temp_r3, (u8 *)tl_05, (s32)arg0));
        }
        return var_r0;
    }
    return NULL;
}

void TObjPlayer::dispatch_by_state() {
    s32 player_list;

    player_list = TObjPlayer::get_player_list();
    switch (player_list) {
    case 2:
        rotate_matrix_z(0, *(s32 *)&this->unk_1F8);
        return;
    case 8:
        rotate_matrix_z(0, this->m_1fc);
        return;
    }
}

void TUnk_804F0AF8::reserved_53() { draw_weapon_at_joint((s32)this, (s8)((void*)49)); update_trail_slot__11TItemWeaponFPvi(this, (void*)0); update_trail_slot__11TItemWeaponFPvi(this, (void*)1); }

void TUnk_804F0AF8::update_idle() { TObjPlayer::add_angle_clamped((s32 *)((char*)this + 0x1f8), (s32)((void*)((void*)-8192)), (s32)((void*)((void*)-30947))); TObjPlayer::add_angle_clamped((s32 *)((char*)this + 0x1fc), (s32)((void*)((void*)-1820)), (s32)((void*)((void*)-7281))); }

void TUnk_804F0AF8::update_attack() { TObjPlayer::add_angle_clamped((s32 *)((char*)this + 0x1f8), (s32)((void*)((void*)16384)), (s32)((void*)((void*)0))); TObjPlayer::add_angle_clamped((s32 *)((char*)this + 0x1fc), (s32)((void*)((void*)3640)), (s32)((void*)((void*)0))); }

extern s32 lbl_804F0AF8[];

void *__dt__13TUnk_804F0AF8Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804F0AF8;
        __dt__11TItemWeaponFv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}
