#include "types.h"
#include "pso/object/TObjMotion.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/object/TObjHashiVersus2.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

extern char lbl_80445974[];
extern char lbl_80445988[];
extern const char *fe_obj321_hashi_model_names[2];
extern BmlResourceDescriptor TObjHashiVersus2__resource_descriptor;
extern const char *fe_obj321_hashi_motion_names[1];

struct RecoveredGlobal_80191340_lbl_804B7C90 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_80191340_lbl_804B7C90_size[sizeof(RecoveredGlobal_80191340_lbl_804B7C90) == 0x10 ? 1 : -1];

struct RecoveredGlobal_801913F8_lbl_804B7D24 { s32 value; u8 remaining[0x54]; };
typedef char RecoveredGlobal_801913F8_lbl_804B7D24_size[sizeof(RecoveredGlobal_801913F8_lbl_804B7D24) == 0x58 ? 1 : -1];

struct RecoveredGlobal_801913F8___vt__16TObjHashiVersus2 { s32 value; u8 remaining[0x34]; };
typedef char RecoveredGlobal_801913F8___vt__16TObjHashiVersus2_size[sizeof(RecoveredGlobal_801913F8___vt__16TObjHashiVersus2) == 0x38 ? 1 : -1];

extern "C" {
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern u32 TObjHashiVersus2__resource_bundle;
s32 TObjFish__sub_8001EDB0(void *, s32);
s32 get_bml_model(void *, s32);
u32 init_collision_body_parts(void *, s32, s32);
u8 * TObjHashiBase__ct(void *, s32);
u8 is_current_floor_switch_set(int);
extern RecoveredGlobal_801913F8_lbl_804B7D24 TObjHashiVersus2__collision_body_parts;
extern s32 __vt__16TObjHashiVersus2[];
extern s32 lbl_805D3380;
extern const f32 lbl_805DBE20;
u8 *TObjHashiVersus2__ct(u8 *arg0, s32 arg1, s32 _w2);
void *TObjHashiVersus2__create(void *arg0);
void *__dt__16TObjHashiVersus2Fv(void *arg0, s16 arg1);
void TLobby__sub_8001FE7C(void*, int);
s32 free_collision_body_parts(void *);
s32 __dl__7TObjectFPv(void *);
void *__dt__13TObjHashiBaseFv(void *arg0, s16 arg1);
void *__nw__7TObjectFUl(int);

extern void *tl_05;

void *TObjHashiVersus2__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xD4);
    if (o != NULL) {
        o = TObjHashiVersus2__ct((u8 *)o, (s32)tl_05, (s32)arg0);
    }
    return o;
}

void TObjHashiVersus2::free_static_data() {
    if ((u32) TObjHashiVersus2__resource_bundle != 0U) {
        TLobby__sub_8001FE7C((void*)TObjHashiVersus2__resource_bundle, 1);
        TObjHashiVersus2__resource_bundle = 0U;
    }
}

void TObjHashiVersus2::load_shared_resource() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 1, &TObjHashiVersus2__resource_descriptor, 0, 0, 0));
    }
    (*(s32 *)&TObjHashiVersus2__resource_bundle) = var_r0;
}

void *__dt__16TObjHashiVersus2Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__16TObjHashiVersus2;
        ((TUnk_804AF8A0 *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        __dt__13TObjHashiBaseFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
u8 *TObjHashiVersus2__ct(u8 *player, s32 arg1, s32 _w2) {
    TObjHashiBase__ct(player, arg1);
    *(s32 **)((s8 *)player + 0x18) = &(*(RecoveredGlobal_801913F8___vt__16TObjHashiVersus2 *)&__vt__16TObjHashiVersus2).value;
    *(s32 *)((s8 *)player + 0) = (s32) lbl_805D3380;
    if (is_current_floor_switch_set((int) ((u16) *(s32 *)((s8 *)player + 0xC8))) == 0) {
        *(f32 *)((s8 *)player + 0x3C) = (f32) (*(f32 *)((s8 *)player + 0x3C) - *(f32 *)((s8 *)player + 0x68));
    }
    *(f32 *)((s8 *)player + 0xD0) = (f32) *(f32 *)((s8 *)player + 0x6C);
    *(f32 *)((s8 *)player + 0xC4) = (f32) lbl_805DBE20;
    *(s32 *)((s8 *)player + 0x34) = get_bml_model((*(u8 * *)&TObjHashiVersus2__resource_bundle), 0);
    *(s32 *)((s8 *)player + 0x24) = TObjFish__sub_8001EDB0((*(u8 * *)&TObjHashiVersus2__resource_bundle), 0);
    init_collision_body_parts(player, (s32) &TObjHashiVersus2__collision_body_parts.value, 2);
    *(s32 *)((s8 *)player + 0x30) = (s32) (*(s32 *)((s8 *)player + 0x30) | 0x40000000);
    ((TObjPlayer *)player)->register_object_by_id();
    return player;
}

__declspec(section ".data") const char *fe_obj321_hashi_model_names[2] = { lbl_80445974, NULL };
BmlResourceDescriptor TObjHashiVersus2__resource_descriptor = { lbl_80445988, fe_obj321_hashi_model_names, fe_obj321_hashi_motion_names, 1, 0 };
__declspec(section ".sdata") const char *fe_obj321_hashi_motion_names[1] = { NULL };
}
