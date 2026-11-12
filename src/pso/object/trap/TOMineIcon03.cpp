#include "types.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/trap/TOMineIcon03.h"
#include "pso/object/base/TObjChara.h"
#include "pso/object/trap/TOMine.h"
#include "pso/object/trap/TOMineTrap.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

s32 __dl__7TObjectFPv(void *);
void *__dt__6TOMineFv(void *arg0, s16 arg1);
void *__nw__7TObjectFUl(int);
s32 free_collision_body_parts(void *);

extern void *tl_05;

void *TOMineIcon03::create(void *arg0) {
    return new TOMineIcon03((TObject *)tl_05, arg0);
}

extern s32 __vt__12TOMineIcon03[];

void *__dt__12TOMineIcon03Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__12TOMineIcon03;
        ((TObjCollidable *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        __dt__6TOMineFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

}

extern "C" {
s32 TObjFish__sub_8001EDB0(void *, s32);
s32 get_bml_model(void *, s32);
void init_collision_body_parts(void *, void *, s32);
extern u8 mine_collision_body_parts[];
extern const char *TOMineIcon03__name;
extern s32 game_difficulty_selection;
extern void *lbl_805D5A50;
#pragma push
#pragma fp_contract on
TOMineIcon03::TOMineIcon03(TObject *parent, void *set_data) : TOMine(parent) {
    m_name = TOMineIcon03__name;
    apply_object_set_data(set_data);
    ((TObjPlayer *)this)->init_position_vectors();
    calc_attach_pos();
    model = (void *)get_bml_model(lbl_805D5A50, 6);
    texlist = TObjFish__sub_8001EDB0(lbl_805D5A50, 6);
    m_374 = get_bml_model(lbl_805D5A50, 2);
    m_378 = TObjFish__sub_8001EDB0(lbl_805D5A50, 2);
    mode = 0;
    if (set_params[0] < 0) {
        set_params[0] = 0;
    }
    if (set_params[1] < 6) {
        set_params[1] = 6;
    } else if (set_params[1] > 8) {
        set_params[1] = 8;
    }
    if (set_params[2] < 0) {
        set_params[2] = 0;
    }
    attack.power = (f32)set_params[0] * (2.0f * (f32)game_difficulty_selection + 1.0f);
    if (game_difficulty_selection == 3) {
        attack.power *= 2.0f;
    }
    attack.kind = set_params[1];
    pad_34C = 0.5f * scale.x + 30.0f;
    m_350 = 0.5f * scale.y + 60.0f;
    update_state();
    m_35c = 0xFFFF;
    actorFlags |= 0x60000000;
    init_collision_body_parts(this, mine_collision_body_parts, 1);
    refresh_collision_body_centers();
    register_object_by_id();
}
#pragma pop

}
