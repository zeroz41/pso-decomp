#include "types.h"
#include "pso/misc/TScene_800838C4.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/TObjBoss5FloorStone.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TScene.h"
#include "pso/object/TObjFish.h"

extern "C" {
s32 rotate_matrix_by_node_angles(void *, int);
int push_matrix(void);
s32 scale_current_matrix(void *);
s32 post_translate_matrix(void *);
int draw_if_all_ready__10TObjPlayerFv(void*);

void TObjPlayer::draw_shadowed_node_tree() {
    u8 *arg0 = (u8 *)this;
    if (arg0 != NULL) {
        push_matrix();
        post_translate_matrix((u8 *)&this->m_prev);
        rotate_matrix_by_node_angles((u8 *)&this->m_down, 1);
        scale_current_matrix((u8 *)&this->m_20);
        if (!(*(s32 *)((s8 *)arg0 + 0) & 8) && ((u32) *(u32 *)((s8 *)arg0 + 4) != 0U)) {
            render_projected_shadow_receiver((u8 *)(arg0 + 8), (s32)(arg0 + 0x14));
            ::draw_ginja_model((*(u32 *)((s8 *)arg0 + 4)));
            TScene::apply_single_screen_state();
        }
        (*(TObjPlayer **)&this->set_index)->draw_shadowed_node_tree();
        pop_matrix();
        ((TObjPlayer *)(this->actorFlags))->draw_shadowed_node_tree();
    }
}

void TObjBoss5FloorStone::render_impl(void* a1) { draw_if_all_ready__10TObjPlayerFv(this); TObjFish::set_global_param((s32)this); push_matrix(); ((TObjPlayer *)a1)->draw_shadowed_node_tree(); pop_matrix(); }

}
