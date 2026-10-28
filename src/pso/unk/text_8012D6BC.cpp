#include "types.h"
#include "pso/item/TItem.h"
#include "pso/misc/TTecSlicer.h"
#include "pso/item/TUnk_804A5A28.h"
#include "pso/TItemAttacker.h"
#include "pso/player/TObjPlayer.h"

struct RecoveredGlobal_8012D6BC_lbl_804A05A8 {
    s32 value;
    u8 remaining[0x1C];
};

extern "C" {
u8 * TItemTimerEvent__ct(void *, s16, s32);
extern RecoveredGlobal_8012D6BC_lbl_804A05A8 lbl_804A05A8;
u8 *slow_curse_timer_ct(u8 *arg0, s16 arg1, s32 arg2, f32 farg0);
struct Owner_8012D708 { u8 pad[0x60]; s32 f60; };
struct Self_8012D708 { u8 pad0[0x24]; s32 f24; u8 pad28[0xF0 - 0x28]; Owner_8012D708 *owner; u8 padF4[0x188 - 0xF4]; s32 f188; };
struct Vec_8012D708 { f32 x, y, z; };
struct Tec_8012D708 {
    s16 id;
    u8 pad2[2];
    s32 f4;
    s32 f8;
    s32 fC;
    s16 f10;
    s16 f12;
    f32 f14;
    f32 f18;
    f32 f1C;
    f32 f20;
    f32 f24;
    s32 f28;
    u8 pad2C[4];
    Vec_8012D708 pos;
    Vec_8012D708 dir;
};

s16 get_entity_id(void *);
f32 query_extended_state__10TObjPlayerFv(void *);
struct SlicerState_801295FC;
void init_slicer_launch_state(void *arg0);
s16 get_validated_attack_stage(u8 *arg0);
s16 TObjPlayer__sub_801D2F4C(s16 *arg0);
}
void enlarge_flight_cutter_slicer(void *arg0);
extern const f32 lbl_805DAF28;
extern const f32 lbl_805DAF2C;
extern const f32 lbl_805DAF30;
typedef char RecoveredGlobal_8012D6BC_lbl_804A05A8_size[sizeof(RecoveredGlobal_8012D6BC_lbl_804A05A8) == 0x20 ? 1 : -1];

u8 *slow_curse_timer_ct(u8 *arg0, s16 arg1, s32 arg2, f32 farg0) {
    TItemTimerEvent__ct(arg0, arg1, arg2);
    *(s32 **)((s8 *)arg0 + 0x18) = &lbl_804A05A8.value;
    *(f32 *)((s8 *)arg0 + 0x2C) = farg0;
    return arg0;
}

void TUnk_804A5A28::emit_marker_effects() {
    Tec_8012D708 tec;

    init_slicer_launch_state((SlicerState_801295FC *)&tec);
    tec.id = get_entity_id(((Self_8012D708 *)this)->owner);
    tec.fC = ((TItem *)this)->get_item_id();
    tec.f4 = ((Self_8012D708 *)this)->f24;
    tec.f8 = ((Self_8012D708 *)this)->f188;
    tec.f10 = TObjPlayer__sub_801D2F4C((s16 *)((u8 *)((Self_8012D708 *)this)->owner + 0x7CC));
    tec.f12 = get_validated_attack_stage((u8 *)((Self_8012D708 *)this)->owner + 0x7CC);
    tec.f14 = query_extended_state__10TObjPlayerFv(((Self_8012D708 *)this)->owner);
    tec.f18 = lbl_805DAF28;
    tec.f1C = lbl_805DAF2C;
    tec.f20 = lbl_805DAF28;
    tec.f24 = lbl_805DAF30;
    tec.f28 = ((Self_8012D708 *)this)->owner->f60;
    ((TObjPlayer *)this)->draw_icon(3, (s32)&tec.pos);
    ((TObjPlayer *)this)->draw_icon(2, (s32)&tec.dir);
    TItemAttacker::spawn_item_timer((s32)(TTecSlicer::create((u16*)&tec)), (s32)enlarge_flight_cutter_slicer, 3);
}
