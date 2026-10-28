#include "types.h"
#include "pso/system/vector.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/TObjGrassWeb.h"
#include "pso/TObject.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/object/TObjMotion.h"
#include "pso/map/CurrentArea.h"

typedef struct Web_800BC798 {
    u8 pad0[0x38];
    u8 pos[0x84 - 0x38];
    s32 timer;
    u8 pad88[0x90 - 0x88];
    s32 state;
} Web_800BC798;

extern "C" {
s16 get_entity_id(u32);
int queue_destruction__7TObjectFv(void*);
s32 __ct__13TUnk_804B9870FP7TObject();
extern s32 __vt__12TObjGrassWeb[];
extern s32 lbl_805D2A3C;
u8 *TObjGrassWeb__ct(u8 *arg0, s32 arg1, u32 arg2);
s32 play_persistent_sound(s32 id, s32 a1, u32 src, s32 a3, s32 flags);
extern s32 enable_v2_features;
void TObjGrassWeb__sub_800BC798(Web_800BC798 *o);
void *__dt__12TObjGrassWebFv(void *arg0, s16 arg1);
s32 is_locally_controlled__10TObjPlayerFPv();
void *get_player_by_client_id(s32 i);
void __dl__7TObjectFPv(void *);
s32 obj_testFlags30__13TUnk_804AF8A0FUl(s32, s32);

int TObjGrassWeb::queue_destruction() { return queue_destruction__7TObjectFv(this); }

void TObjGrassWeb__sub_800BC798(Web_800BC798 *o) {
    switch (get_current_area()) {
    case 3:
    case 4:
    case 5:
        play_persistent_sound(0x4003A809, (s32)o, (u32)o->pos, 0, 0);
        break;
    case 16:
    case 17:
        if (enable_v2_features == 1) {
            play_persistent_sound(0x3051E, (s32)o, (u32)o->pos, 0, 0);
        }
        break;
    case 18:
        break;
    case 19:
    case 20:
        play_persistent_sound(0x3A81D, (s32)o, (u32)o->pos, 0, 0);
        break;
    }
    if (o->timer-- < 0) {
        o->state = 2;
    }
}

void TObjGrassWeb::apply_to_player() {
    s32 temp_r3;

    this->m_90 = 1;
    temp_r3 = (s32)get_player_by_client_id(this->m_a4);
    if ((temp_r3 != 0) && (is_locally_controlled__10TObjPlayerFPv() != 0) && (((TObject *)temp_r3)->all_parents_unqueued_for_destruction() != 0) && (obj_testFlags30__13TUnk_804AF8A0FUl(temp_r3, 0x800) == 0)) {
        TObjPlayer::play_effect(temp_r3, this->set_params[0], 1);
    }
}

void TObjGrassWeb::run_task() {
    u8 *arg0 = (u8 *)this;
    switch (this->m_90) {
    case 0:
        apply_to_player();
        return;
    case 1:
        TObjGrassWeb__sub_800BC798((Web_800BC798 *)(arg0));
        return;
    default:
        queue_destruction();
        return;
    }
}

void TObjGrassWeb::render() {  }

void *__dt__12TObjGrassWebFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__12TObjGrassWeb;
        __dt__13TUnk_804B9870Fv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
#pragma push
#pragma fp_contract on
u8 *TObjGrassWeb__ct(u8 *grass_web, s32 arg1, u32 arg2) {
    __ct__13TUnk_804B9870FP7TObject();
    *(s32 **)((s8 *)grass_web + 0x18) = __vt__12TObjGrassWeb;
    if (arg2 != 0U) {
        *(s32 *)((s8 *)grass_web + 0) = (s32) lbl_805D2A3C;
        VecCopy((Vec *)(grass_web + 0x38), (const Vec *)(arg2 + 0x38));
        ((TObjGrassWeb *)grass_web)->m_90 = 0;
        ((TObjGrassWeb *)grass_web)->m_a4 = get_entity_id(arg2);
        ((TObjGrassWeb *)grass_web)->set_params[0] = 0xB4;
    } else {
        queue_destruction__7TObjectFv(grass_web);
    }
    return grass_web;
}
#pragma pop

}
