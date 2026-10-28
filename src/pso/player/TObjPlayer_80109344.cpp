#include "types.h"
#include "pso/player/TObjPlayer_80109344.h"
#include "pso/unk/text_80087278.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"

struct W_801093B4 { s32 a; s32 b; s32 c; };

union V_801093B4 { W_801093B4 w; struct { f32 x; f32 y; f32 z; } f; };

extern "C" {
extern const f32 lbl_805DAB38;
s32 __ct__14TItemEffHeavenFP7TObjectlsl(u32, s32, u32, u16, s32);
u32 __nw__7TObjectFUl(s32);

void TObjPlayer::spawn_heaven_effect(s32 arg0, u32 arg1, u16 arg2, s32 arg3) {
    u32 obj;
    if ((arg0 != 0) && ((u16) arg2 != 0xFFFF) && (arg1 != 0U) && ((obj = __nw__7TObjectFUl(0x4C)) != 0U)) {
        __ct__14TItemEffHeavenFP7TObjectlsl(obj, arg0, arg1, arg2, arg3);
    }
}

#pragma push
#pragma opt_propagation off
void TObjPlayer::spawn_hit_particle_trio() {
    W_801093B4 *arg0 = (W_801093B4 *)this;
    V_801093B4 v;
    s32 c;
    s32 b;
    s32 a;
    a = arg0->a;
    b = arg0->b;
    c = arg0->c;
    v.w.a = a;
    v.w.b = b;
    v.w.c = c;
    spawn_particle_effect(&v, 0x1D0);
    spawn_particle_effect(&v, 0x1D1);
    v.f.y = v.f.y - lbl_805DAB38;
    spawn_particle_effect(&v, 0x1D2);
}
#pragma pop

void TObjPlayer::forward_item_effect_callback(s32 arg0, s32 arg1) {
    ((TObjPlayer *)arg1)->spawn_hit_particle_trio();
}
void spawn_weapon_impact_effect(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    ((TObjPlayer *)arg3)->spawn_hit_particle_trio();
}


void invoke_menu_callback__10TObjPlayerFPv(void *arg0) {
    void *x;
    x = find_item_by_id((s32)(*(void **)((s8 *)arg0 + 0x34)));
    if (x != NULL) {
        ((TObjPlayer *)x)->call_callback_1ec((s32)((void *)((char *)arg0 + 28)), (s32)((void *)((char *)arg0 + 40)));
    }
    *(u32 *)((s8 *)arg0 + 0x38) = 1;
}

void TObjPlayer::invoke_menu_callback_if_set(u32 arg0) {
    if (arg0 != 0U) {
        ((s32 (*)())invoke_menu_callback__10TObjPlayerFPv)();
    }
}

}
