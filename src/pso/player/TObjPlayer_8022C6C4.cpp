#include "types.h"
#include "pso/TObject.h"
#include "pso/TTecCtrl.h"
#include "pso/object/TObjLight.h"
#include "pso/player/TObjPlayer_8022C6C4.h"
#include "pso/player/TObjPlayer.h"
#include "pso/map/FloorArea.h"
extern "C" void render__8TTecCtrlFv();
extern "C" void run_task__8TTecCtrlFv();

#include "pso/misc/TLockOnCursor.h"
#include "pso/misc/TTecAnti.h"
#include "pso/misc/TTecBarta.h"
#include "pso/misc/TTecFoie.h"
#include "pso/misc/TTecGiBarta.h"
#include "pso/misc/TTecGiFoie.h"
#include "pso/misc/TTecGiZonde.h"
#include "pso/misc/TTecGrants.h"
#include "pso/misc/TTecLuker.h"
#include "pso/misc/TTecMegid.h"
#include "pso/misc/TTecRaBarta.h"
#include "pso/misc/TTecRaFoie.h"
#include "pso/misc/TTecRaZonde.h"
#include "pso/misc/TTecReverser.h"
#include "pso/misc/TTecSifta.h"

typedef struct Owner_8022CDE8 {
    u8 pad0[0x424];
    u32 f424;
    u8 slots[0x10];
} Owner_8022CDE8;

typedef struct Cursor_8022CDE8 {
    u8 pad0[0x9C];
    u8 list[0x10];
} Cursor_8022CDE8;

struct Vec_8022D27C { f32 x, y, z; };

struct Target_8022D27C { u16 id; s16 part; };

struct Entry_8022D27C { u16 id; s16 part; f32 c; };

struct List_8022D27C { s32 count; Entry_8022D27C e[11]; };

struct Coll_8022D27C { u8 pad0[0x1C]; Vec_8022D27C pos; u8 pad28[0x2C - 0x28]; };

struct Ent_8022D27C { u8 pad0[0xA4]; Coll_8022D27C *colls; };

struct Player_8022D27C {
    u8 pad0[0x38];
    Vec_8022D27C pos;
    u8 pad44[0x60 - 0x44];
    s32 rotY;
    u8 pad64[0x428 - 0x64];
    u8 tech[1];
};

typedef struct Col_8022C738 { s32 w[4]; } Col_8022C738;

typedef struct Vec_8022C738 { f32 x, y, z; } Vec_8022C738;

typedef struct Params_8022C738 { u8 pad0[0x12]; s16 f12; u8 pad14[0x20 - 0x14]; s16 f20; } Params_8022C738;

typedef struct LightData_8022C738 { u8 pad0[0x1C]; f32 f1C; u8 pad20[4]; } LightData_8022C738;

extern "C" {
Cursor_8022CDE8 *find_by_pos__11TMainCursorFss(u32, int, s16);
void *TObjPlayer__sub_80116620(void *, int);
s32 get_obj_id__10TObjPlayerFv(void *);
void set_slot_type_state__10TObjPlayerFllss(void *, int, u16, s32);
void capture_technique_targets__10TObjPlayerFv(int kind, Owner_8022CDE8 *owner);
void VecCopy__FP3VecPC3Vec(void *, void *);
u16 get_entity_id(void *);
s32 is_split_screen();
Ent_8022D27C *find_entity_by_id(u16);
void get_hand_joint_position__10TObjPlayerFl(void *, void *);
Target_8022D27C *get_technique_data__10TObjPlayerFPv(void *);
u8 get_cast_technique_level(void *, int);
void create__10TTecDebandFllll(void *, void *, void *, int);
void create__9TTecRestaFPvPvPvPv(void *, void *, void *, int);
void matrix_mult_vec(int, void *, void *);
void rotate_matrix_y(int, int);
void push_matrix_from(void *);
void pop_matrices(int);
extern u8 identity_matrix[];
extern s32 local_client_id;
extern const f32 lbl_805DC7D8;
extern const f32 lbl_805DC7E4;
void launch_technique__10TObjPlayerFv(s32 tech, s32 unused, Player_8022D27C *pl);
s32 is_locally_controlled__10TObjPlayerFPv(void *);
void *__nw__7TObjectFUl(u32);
Params_8022C738 *get_technique_base_params(void);
void *construct_actor_light__9TObjLightFlllllfffl(void *, Col_8022C738 *, Vec_8022C738 *, s32, void *, s32, f32, f32, f32);
void *__ct__13TUnk_804CC794Fll(void *, void *, s32);
void *__ct__13TUnk_804CC948Fll(void *, void *, s32);
void *__ct__13TUnk_804CCD0CFll(void *, void *, s32);
void *construct_resta_charge_sound(void *, void *, s32);
void *__ct__13TUnk_804CCAC8Fll(void *, void *, s32);
void *__ct__13TUnk_804CC74CFll(void *, void *, s32);
extern Col_8022C738 technique_charge_light_color;
extern Vec_8022C738 lbl_8044CF8C;
extern Col_8022C738 technique_charge_light_params;
extern Vec_8022C738 lbl_8044CFA8;
extern Col_8022C738 lbl_8044CFB4;
extern Vec_8022C738 lbl_8044CFC4;
extern Col_8022C738 rabarta_charge_light_color;
extern Vec_8022C738 lbl_8044CFE0;
extern Col_8022C738 zonde_charge_light_color;
extern Vec_8022C738 lbl_8044CFFC;
extern Col_8022C738 resta_charge_light_color;
extern Vec_8022C738 lbl_8044D018;
extern Col_8022C738 ryuker_charge_light_color;
extern Vec_8022C738 lbl_8044D034;
extern Col_8022C738 shifta_charge_light_color;
extern Vec_8022C738 lbl_8044D050;
extern Col_8022C738 megid_charge_light_color;
extern Vec_8022C738 lbl_8044D06C;
extern LightData_8022C738 TObjLight__scene_light_state;
extern s32 tl_07;
extern const f32 lbl_805DC7DC;
extern const f32 lbl_805DC7E0;
extern "C" void __dt__8TTecCtrlFv();
extern "C" void render_shadows__7TObjectFv();
void *tech_high_level_linear_power_table[19] = {
    (void *)0xffab0041, (void *)0x1e002a, (void *)0x1720015, (void *)0xff83003f,
    (void *)0x28, (void *)0x1d6000f, (void *)0x50037, (void *)0xffe20026,
    (void *)0x2260009, (void *)0x578003c, (void *)0xa0001, (void *)0xa0001,
    (void *)0xa0001, (void *)0xa0001, (void *)0x0, (void *)0xffec000a,
    (void *)0x0, (void *)0x0, (void *)0x2a0002,
};
void *lbl_804CC55C[38] = {
    (void *)0x3f4ccccd, (void *)0x40400000, (void *)0x3f4ccccd, (void *)0x40000000,
    (void *)0x3f19999a, (void *)0x40000000, (void *)0x3f4ccccd, (void *)0x40400000,
    (void *)0x3f19999a, (void *)0x40000000, (void *)0x3ecccccd, (void *)0x40000000,
    (void *)0x3f000000, (void *)0x40800000, (void *)0x3ecccccd, (void *)0x40000000,
    (void *)0x3ecccccd, (void *)0x40000000, (void *)0x3dcccccd, (void *)0x40000000,
    (void *)0x3f800000, (void *)0x40a00000, (void *)0x3f800000, (void *)0x40a00000,
    (void *)0x3f800000, (void *)0x40a00000, (void *)0x3f800000, (void *)0x40a00000,
    (void *)0x3f800000, (void *)0x3f800000, (void *)0x3dcccccd, (void *)0x40a00000,
    (void *)0x3f800000, (void *)0x41200000, (void *)0x3f800000, (void *)0x41f00000,
    (void *)0x3e99999a, (void *)0x40a00000,
};
void *__vt__8TTecCtrl[6] = {
    (void *)0x0, (void *)0x0, (void *)&__dt__8TTecCtrlFv, (void *)&run_task__8TTecCtrlFv,
    (void *)&render__8TTecCtrlFv, (void *)&render_shadows__7TObjectFv,
};

s32 TObjPlayer::get_level_tier(s32 arg0) {

    switch (arg0 / 5) {
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
        return 2;
    case 3:
        return 3;
    case 4:
        return 4;
    case 5:
        return 5;
    default:
        return 0;
    }
}
}
#define ONE_SLOT()                                                                       \
    if (((TObjPlayer *)(TObjPlayer__sub_80116620(c->list, 0)))->get_type_id() != 0xFFFF) { \
        set_slot_type_state__10TObjPlayerFllss(slots, 0,                                                \
            ((TObjPlayer *)(TObjPlayer__sub_80116620(c->list, 0)))->get_type_id(),           \
            get_obj_id__10TObjPlayerFv(TObjPlayer__sub_80116620(c->list, 0)));           \
        ((TObjPlayer *)slots)->set_tech_level(1);                                      \
    }

#pragma push
#pragma opt_propagation off
#define CHARGE_LIGHT_8022C738(COL, VEC, INIT)                                                    \
    {                                                                                            \
        Col_8022C738 c = COL;                                                                    \
        Vec_8022C738 v = VEC;                                                                    \
        void *o = __nw__7TObjectFUl(100);                                                        \
        if (o != NULL) {                                                                         \
            ((void *(*)(f32, f32, f32, void *, Col_8022C738 *, Vec_8022C738 *, s32, void *, s32)) \
                 construct_actor_light__9TObjLightFlllllfffl)(lbl_805DC7DC, lbl_805DC7E0, TObjLight__scene_light_state.f1C, \
                                          o, &c, &v, base, owner, tl_07);                        \
        }                                                                                        \
        if (is_locally_controlled__10TObjPlayerFPv(owner) != 0) {                                \
            o = __nw__7TObjectFUl(0x34);                                                         \
            if (o != NULL) {                                                                     \
                INIT(o, owner, tl_07);                                                           \
            }                                                                                    \
        }                                                                                        \
    }
void create_technique_charge_light(u32 kind, void *owner) {
    Params_8022C738 *p = get_technique_base_params();
    s32 base = p->f12 + p->f20 + 50;
    switch (kind) {
    case 1:
        CHARGE_LIGHT_8022C738(technique_charge_light_color, lbl_8044CF8C, __ct__13TUnk_804CC794Fll)
        break;
    case 0:
    case 2:
        CHARGE_LIGHT_8022C738(technique_charge_light_params, lbl_8044CFA8, __ct__13TUnk_804CC794Fll)
        break;
    case 3:
    case 4:
        CHARGE_LIGHT_8022C738(lbl_8044CFB4, lbl_8044CFC4, __ct__13TUnk_804CC948Fll)
        break;
    case 5:
        CHARGE_LIGHT_8022C738(rabarta_charge_light_color, lbl_8044CFE0, __ct__13TUnk_804CC948Fll)
        break;
    case 6:
    case 7:
    case 8:
        CHARGE_LIGHT_8022C738(zonde_charge_light_color, lbl_8044CFFC, __ct__13TUnk_804CCD0CFll)
        break;
    case 9:
    case 15:
    case 16:
    case 17:
        CHARGE_LIGHT_8022C738(resta_charge_light_color, lbl_8044D018, construct_resta_charge_sound)
        break;
    case 10:
    case 11:
    case 12:
    case 14:
        CHARGE_LIGHT_8022C738(ryuker_charge_light_color, lbl_8044D034, __ct__13TUnk_804CCAC8Fll)
        break;
    case 13:
        CHARGE_LIGHT_8022C738(shifta_charge_light_color, lbl_8044D050, __ct__13TUnk_804CCAC8Fll)
        break;
    case 18:
        CHARGE_LIGHT_8022C738(megid_charge_light_color, lbl_8044D06C, __ct__13TUnk_804CC74CFll)
        break;
    }
}
#pragma pop

void capture_technique_targets__10TObjPlayerFv(int kind, Owner_8022CDE8 *owner) {
    Cursor_8022CDE8 *c;
    void *slots;
    if (owner == NULL) {
        return;
    }
    if (owner->f424 == 0) {
        return;
    }
    slots = owner->slots;
    if (slots == NULL) {
        return;
    }
    ((TObjPlayer *)(owner->slots))->reset_slots();
    c = find_by_pos__11TMainCursorFss(owner->f424, 3, kind);
    if (c == NULL) {
        return;
    }
    switch (kind) {
    case 0:
        ONE_SLOT();
        break;
    case 2:
        ONE_SLOT();
        break;
    case 3:
        ONE_SLOT();
        break;
    case 4:
        ONE_SLOT();
        break;
    case 6:
        ONE_SLOT();
        break;
    case 7: {
        int n = 0;
        int i;
        for (i = 0; i < ((TLockOnCursor *)(c->list))->get_target(); i++) {
            if (((TObjPlayer *)(TObjPlayer__sub_80116620(c->list, n)))->get_type_id() != 0xFFFF) {
                set_slot_type_state__10TObjPlayerFllss(slots, n,
                    ((TObjPlayer *)(TObjPlayer__sub_80116620(c->list, n)))->get_type_id(),
                    get_obj_id__10TObjPlayerFv(TObjPlayer__sub_80116620(c->list, n)));
                n++;
            }
        }
        ((TObjPlayer *)slots)->set_tech_level(n);
        break;
    }
    case 9:
        ONE_SLOT();
        break;
    case 10:
    case 11:
    case 12:
    case 13:
    case 15:
    case 16: {
        int i;
        int n = 0;
        for (i = 0; i < ((TLockOnCursor *)(c->list))->get_target(); i++) {
            set_slot_type_state__10TObjPlayerFllss(slots, n,
                ((TObjPlayer *)(TObjPlayer__sub_80116620(c->list, n)))->get_type_id(),
                get_obj_id__10TObjPlayerFv(TObjPlayer__sub_80116620(c->list, n)));
            n++;
        }
        ((TObjPlayer *)slots)->set_tech_level(n);
        break;
    }
    case 17:
        ONE_SLOT();
        break;
    case 18:
        ONE_SLOT();
        break;
    }
}
#define COLLECT_8022D27C()                                              \
    list.count = 0;                                                     \
    for (i = 0; i < n; i++) {                                           \
        if (targets == NULL || targets->id == 0xFFFF) {                 \
            break;                                                      \
        }                                                               \
        list.e[i].id = targets->id;                                     \
        list.e[i].part = targets->part;                                 \
        targets++;                                                      \
    }                                                                   \
    list.count = n;
#define AIM_8022D27C()                                                  \
    if (targets->id == 0xFFFF) {                                        \
        return;                                                         \
    }                                                                   \
    ent = find_entity_by_id(targets->id);                               \
    if (ent == NULL) {                                                  \
        return;                                                         \
    }                                                                   \
    if (ent->colls == NULL) {                                           \
        return;                                                         \
    }                                                                   \
    VecCopy__FP3VecPC3Vec(&aim, &ent->colls[targets->part].pos);
void launch_technique__10TObjPlayerFv(s32 tech, s32 unused, Player_8022D27C *pl) {
    Vec_8022D27C aim;
    Vec_8022D27C hand;
    Vec_8022D27C ofs;
    List_8022D27C list;
    void *td;
    s32 n;
    Target_8022D27C *targets;
    s32 i;
    Ent_8022D27C *ent;
    ((TObjPlayer *)(&list))->construct_target_cursor_records();
    ofs.x = lbl_805DC7D8;
    ofs.y = lbl_805DC7D8;
    ofs.z = lbl_805DC7E4;
    if (pl == NULL) {
        return;
    }
    if (get_current_floor_area() == AREA_PIONEER2_EP1 || get_current_floor_area() == AREA_PIONEER2_EP2 ||
        get_current_floor_area() == AREA_LOBBY) {
        switch (tech) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 18:
            return;
        }
    }
    td = pl->tech;
    targets = get_technique_data__10TObjPlayerFPv(td);
    if (targets == NULL) {
        return;
    }
    n = ((TObjPlayer *)td)->get_section_clamped();
    push_matrix_from(identity_matrix);
    rotate_matrix_y(0, pl->rotY);
    matrix_mult_vec(0, &ofs, &ofs);
    pop_matrices(1);
    ofs.x += pl->pos.x;
    ofs.y += pl->pos.y;
    ofs.z += pl->pos.z;
    get_hand_joint_position__10TObjPlayerFl(pl, &hand);
    switch (tech) {
    case 0:
        if (n != 0) {
            AIM_8022D27C()
            TTecFoie::create_ex((void *)pl, &hand, &aim, (void *)(get_cast_technique_level(td, 0)));
        } else {
            TTecFoie::create((void *)pl, &hand, (void *)pl->rotY, (void *)(get_cast_technique_level(td, 0)));
        }
        break;
    case 1:
        TTecGiFoie::create((void *)pl, &hand, (void *)(get_cast_technique_level(td, 1)));
        break;
    case 2:
        COLLECT_8022D27C()
        if (n == 0) {
            return;
        }
        ((TTecRaFoie *)pl)->create_ex(&hand, &list, (void *)(get_cast_technique_level(td, 2)));
        break;
    case 3:
        if (n != 0) {
            AIM_8022D27C()
            ((TTecBarta *)pl)->create(&pl->pos, &aim, (void *)(get_cast_technique_level(td, 3)));
        } else {
            ((TTecBarta *)pl)->create_ex(&pl->pos, (void *)pl->rotY, (void *)(get_cast_technique_level(td, 3)));
        }
        break;
    case 4:
        if (n != 0) {
            AIM_8022D27C()
            ((TTecGiBarta *)pl)->create(&hand, &aim, (void *)(get_cast_technique_level(td, 4)));
        } else {
            ((TTecGiBarta *)pl)->create_ex(&hand, (void *)pl->rotY, (void *)(get_cast_technique_level(td, 4)));
        }
        break;
    case 5:
        ((TTecRaBarta *)pl)->create(&hand, (void *)(get_cast_technique_level(td, 5)));
        break;
    case 6:
        COLLECT_8022D27C()
        if (n == 0) {
            return;
        }
        TObjPlayer::create_tec_zonde((void *)pl, &hand, &list, (void *)(get_cast_technique_level(td, 6)));
        break;
    case 7:
        COLLECT_8022D27C()
        if (n == 0) {
            return;
        }
        ((TTecGiZonde *)pl)->create(&hand, &list, (void *)(get_cast_technique_level(td, 7)));
        break;
    case 8:
        ((TTecRaZonde *)pl)->create(&hand, (void *)(get_cast_technique_level(td, 8)));
        break;
    case 9:
        COLLECT_8022D27C()
        if (n == 0) {
            return;
        }
        TTecGrants::create((void *)pl, &hand, &list, (void *)(get_cast_technique_level(td, 9)));
        break;
    case 10:
        COLLECT_8022D27C()
        create__10TTecDebandFllll(pl, &hand, &list, get_cast_technique_level(td, 10));
        break;
    case 11:
        COLLECT_8022D27C()
        TObjPlayer::create_tec_jelin((void *)pl, &hand, &list, (void *)(get_cast_technique_level(td, 11)));
        break;
    case 12:
        COLLECT_8022D27C()
        TObjPlayer::create_tec_zarua((void *)pl, &hand, &list, (void *)(get_cast_technique_level(td, 12)));
        break;
    case 13:
        COLLECT_8022D27C()
        ((TTecSifta *)pl)->create_instance(&hand, &list, (void *)(get_cast_technique_level(td, 13)));
        break;
    case 14:
        if (is_split_screen() != 0) {
            ((TTecLuker *)pl)->create(&hand, &ofs, 0);
        } else if (local_client_id == get_entity_id(pl)) {
            ((TTecLuker *)pl)->create(&hand, &ofs, 0);
        }
        break;
    case 15:
        COLLECT_8022D27C()
        create__9TTecRestaFPvPvPvPv(pl, &hand, &list, get_cast_technique_level(td, 15));
        break;
    case 16:
        COLLECT_8022D27C()
        TTecAnti::create((void *)pl, &hand, &list, (void *)(get_cast_technique_level(td, 16)));
        break;
    case 17:
        COLLECT_8022D27C()
        if (n == 0) {
            return;
        }
        TTecReverser::create((void *)pl, &hand, &list, (void *)(get_cast_technique_level(td, 17)));
        break;
    case 18:
        if (n != 0) {
            AIM_8022D27C()
            TTecMegid::create((s32)pl, (s32)&hand, (s32)&aim, (s32)(get_cast_technique_level(td, 18)));
        } else {
            TTecMegid::create_ex((s32)pl, (s32)&hand, pl->rotY, (s32)(get_cast_technique_level(td, 18)));
        }
        break;
    }
}
