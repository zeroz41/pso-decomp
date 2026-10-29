#include "types.h"
#include "pso/enemy/TObjEneRe7Berura_803E4CE0.h"
#include "pso/player/TObjPlayer.h"
#include "pso/enemy/TObjEneRe7Berura.h"
#include "pso/misc/TLobby_801E2F94.h"

extern "C" {


extern s32 process_callback_list__10TObjPlayerFl[];
extern s32 player_node_matrix_cursor;
extern s32 player_node_matrix_count;
extern s32 node_matrix_array_base;
extern s32 player_apply_callback_fn;

void TObjPlayer::apply_with_callback(s32 arg1, f32 farg0) {
    (*(s32 *)&this->m_20) = arg1;
    *(f32 *)&this->texlist = farg0;
    player_node_matrix_cursor = 0;
    player_node_matrix_count = *(s32 *)&this->set_index;
    node_matrix_array_base = *(s32 *)&this->room;
    player_apply_callback_fn = *(s32 *)&this->position.x;
    set_chunk_model_node_callback((s32)process_callback_list__10TObjPlayerFl);
    draw_motion(*(NJS_OBJECT **)((s8 *)this + 0x1C), (NJS_MOTION *)arg1, farg0);
    set_chunk_model_node_callback((s32)NULL);
}

}
