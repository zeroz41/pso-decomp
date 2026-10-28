#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/enemy/TObjEneRe7Berura.h"

extern "C" {

s32 render_model_tree__12TBoss8DragonFPv(s32, s32, f32);

extern s32 process_callback_list__10TObjPlayerFl[];
extern s32 player_node_matrix_cursor;
extern s32 player_node_matrix_count;
extern s32 node_matrix_array_base;
extern s32 player_apply_callback_fn;

void TObjPlayer::apply_with_callback(s32 arg1, f32 farg0) {
    (*(s32 *)&this->m_20) = arg1;
    *(f32 *)&this->texture_id = farg0;
    player_node_matrix_cursor = 0;
    player_node_matrix_count = *(s32 *)&this->set_index;
    node_matrix_array_base = *(s32 *)&this->room;
    player_apply_callback_fn = *(s32 *)&this->position[0];
    TObjEneRe7Berura::set_global_state((s32)process_callback_list__10TObjPlayerFl);
    render_model_tree__12TBoss8DragonFPv(*(s32 *)((s8 *)this + 0x1C), arg1, farg0);
    TObjEneRe7Berura::set_global_state((s32)NULL);
}

}
