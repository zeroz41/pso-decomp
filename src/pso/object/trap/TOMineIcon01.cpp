#include "types.h"
#include "pso/unk/text_80087278.h"
#include "pso/object/base/TObjChara.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/trap/TOMine.h"
#include "pso/object/trap/TOMineIcon02.h"
#include "pso/object/trap/TOMineIcon01.h"
#include "pso/object/trap/TOMineTrap.h"
#include "pso/player/TObjPlayer.h"


extern "C" {
s32 TObjFish__sub_8001EDB0(void *, s32);
s32 get_bml_model(void *, s32);
void init_collision_body_parts(void *, void *, s32);
extern u8 mine_collision_body_parts[];
extern s32 __vt__12TOMineIcon01[];
extern const char *TOMineIcon01__name;
extern s32 game_difficulty_selection;
extern void *lbl_805D5A50;
s32 free_collision_body_parts(void *);
s32 __dl__7TObjectFPv(void *);
void *__dt__6TOMineFv(void *arg0, s16 arg1);
void *__nw__7TObjectFUl(int);

extern void *tl_05;

void TOMineIcon01::vfunc_84() {  }

void *TOMineIcon01::create() {
    return new TOMineIcon01((TObject *)tl_05, this);
}

void *__dt__12TOMineIcon01Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__12TOMineIcon01;
        ((TObjCollidable *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        __dt__6TOMineFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

#pragma push
#pragma fp_contract on
TOMineIcon01::TOMineIcon01(TObject *parent, void *set_data) : TOMine(parent) {
    m_name = TOMineIcon01__name;
    apply_object_set_data(set_data);
    ((TObjPlayer *)this)->init_position_vectors();
    calc_attach_pos();
    model = (void *)get_bml_model(lbl_805D5A50, 4);
    texlist = TObjFish__sub_8001EDB0(lbl_805D5A50, 4);
    m_374 = get_bml_model(lbl_805D5A50, 1);
    m_378 = TObjFish__sub_8001EDB0(lbl_805D5A50, 1);
    mode = 0;
    if (set_params[0] < 0) {
        set_params[0] = 0;
    }
    if (set_params[1] < 0) {
        set_params[1] = 0;
    } else if (set_params[1] > 5) {
        set_params[1] = 5;
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

void TOMineIcon02::vfunc_84() {  }

void TOMineIcon02::vfunc_82() {
    s32 arg0 = (s32)this;
    spawn_particle_effect((void *)(arg0 + 0x2FC), 0x8E);
    spawn_particle_effect((void *)(arg0 + 0x2FC), 0x8E);
}

}
