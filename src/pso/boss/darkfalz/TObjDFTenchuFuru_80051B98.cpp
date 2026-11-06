#include "types.h"
#include "pso/math/MatrixVector.h"
#include "pso/player/TObjPlayer_80052374.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/boss/darkfalz/TObjDFJisin.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/boss/darkfalz/TObjDFTenchuFuru.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/charcreate/TCharaMaking.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/system/MatrixStack.h"
#include "pso/player/TObjPlayer_801AF2F0.h"

extern "C" {
s32 TCharaMaking__draw_colored_hair(int, void *, int, f32);
extern s32 df_captured_matrix_pair[];
extern const f32 lbl_805D8A30;
extern const f32 lbl_805D8A34;

    extern int TObjDFTenchuFuru__matrix_node_index;
void TObjDFTenchuFuru::draw_node_tree() { TObjDFTenchuFuru__matrix_node_index = 0; push_matrix(); set_matrix_identity((u8 *)((void*)0)); transform_node_tree(); pop_matrix(); }
void TObjPlayer::draw_player_model_by_client(u16 arg0, s32 arg1, f32 farg0, f32 farg1) {
    u8 *p;
    u32 a;
    u32 b;
    u8 *c;
    u32 d;
    u8 *e;
    s32 f;
    u8 *g;
    if (lbl_805D8A30 == farg1) {
        return;
    }
    if (arg0 == 0xFFFF) {
        return;
    }
    p = (u8 *)get_player_by_client_id(arg0);
    if (p == NULL || *(s32 *)((s8 *)p + 0xCFC) != 0) {
        return;
    }
    c = p + 0xA1C;
    a = *(u32 *)((s8 *)p + 0x8B0);
    e = p + 0xB88;
    b = *(u32 *)((s8 *)p + 0x8AC);
    d = *(u32 *)((s8 *)p + 0x8B4);
    g = p + 0xCF4;
    f = *(s32 *)((s8 *)p + 0x34);
    if (farg1 < lbl_805D8A34) {
        TObjPlayer__sub_80052390(farg1);
    }
    TObjFish::set_global_param((s32)g);
    TObjDFTenchuFuru::register_callback();
    draw_model_motion((void *)f, (void *)arg1, farg0);
    TObjDFTenchuFuru__sub_80051A7C();
    if (d != 0) {
        push_matrix_from((u8 *)df_captured_matrix_pair + 0x30);
        TObjFish::set_global_param((s32)e);
        draw_chunk_object((void *)d);
        pop_matrix();
    }
    if (a != 0) {
        TCharaMaking::enable_making();
        push_matrix_from(df_captured_matrix_pair);
        TObjFish::set_global_param((s32)c);
        draw_chunk_object((void *)a);
        pop_matrix();
        TCharaMaking::clear_flag_bit0();
    }
    if (farg1 < lbl_805D8A34) {
        TObjPlayer::sync_player_globals();
    }
    if (b != 0) {
        TCharaMaking::enable_making();
        push_matrix_from(df_captured_matrix_pair);
        TObjFish::set_global_param((s32)c);
        TCharaMaking__draw_colored_hair(b, p + 0x85C, 0, farg1);
        pop_matrix();
        TCharaMaking::clear_flag_bit0();
    }
}

}
