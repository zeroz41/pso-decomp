#include "types.h"
#include "pso/player/TObjPlayer_80052374.h"
#include "pso/boss/darkfalz/TObjDFTenchuFuru_80051D5C.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/ui/charcreate/CharacterAppearance.h"
#include "pso/player/TObjPlayer.h"
#include "pso/boss/darkfalz/TObjDFTenchuFuru.h"
#include "pso/ui/charcreate/TCharaMaking.h"
#include "pso/object/ambient/TObjFish.h"

extern "C" {

void *get_player_by_client_id(s32 i);
s32 push_matrix();
s32 post_translate_matrix(s32 *);
}
extern s32 lbl_804FF228[];
extern s32 lbl_804FF234[];
extern const f32 lbl_805D8A30;
extern const f32 lbl_805D8A34;

void boss6type2_draw_models(s32 arg0, s32 arg1, s32 arg2, u32 arg3, u32 arg4, u32 arg5, u32 arg6, s32 appearance, f32 alpha) {
    if (lbl_805D8A30 != alpha) {
        ((TObjDFTenchuFuru *)arg3)->draw_node_tree();
        if (alpha < lbl_805D8A34) {
            TObjPlayer__sub_80052390(alpha);
        }
        TObjFish::set_global_param(arg0);
        draw_chunk_object((void *)arg3);
        if (arg6 != 0U) {
            push_matrix();
            post_translate_matrix(lbl_804FF234);
            TObjFish::set_global_param(arg2);
            draw_chunk_object((void *)arg6);
            pop_matrix();
        }
        if (arg4 != 0U) {
            TCharaMaking::enable_making();
            push_matrix();
            post_translate_matrix(lbl_804FF228);
            TObjFish::set_global_param(arg1);
            draw_chunk_object((void *)arg4);
            pop_matrix();
            TCharaMaking::clear_flag_bit0();
        }
        if (alpha < lbl_805D8A34) {
            TObjPlayer::sync_player_globals();
        }
        if (arg5 != 0U) {
            TCharaMaking::enable_making();
            push_matrix();
            post_translate_matrix(lbl_804FF228);
            TObjFish::set_global_param(arg1);
            TCharaMaking__draw_colored_hair(alpha, (s32)arg5, (CharacterAppearanceFields *)appearance, 0);
            pop_matrix();
            TCharaMaking::clear_flag_bit0();
        }
    }
}

void TObjPlayer::draw_player_model_by_id(s32 arg0, f32 alpha) {
    u8 *p;
    u32 m8b0;
    u32 m8ac;
    s32 a1c;
    u32 m8b4;
    s32 b88;
    u32 m34;
    s32 cf4;

    if (lbl_805D8A30 == alpha) {
        return;
    }
    if ((u16)arg0 == 0xFFFF) {
        return;
    }
    p = (u8 *)get_player_by_client_id((u16)arg0);
    if (p == NULL || *(s32 *)((s8 *)p + 0xCFC) != 0) {
        return;
    }
    m34 = *(u32 *)((s8 *)p + 0x34);
    a1c = (s32)(p + 0xA1C);
    m8b0 = *(u32 *)((s8 *)p + 0x8B0);
    b88 = (s32)(p + 0xB88);
    m8ac = *(u32 *)((s8 *)p + 0x8AC);
    m8b4 = *(u32 *)((s8 *)p + 0x8B4);
    cf4 = (s32)(p + 0xCF4);
    ((TObjDFTenchuFuru *)m34)->draw_node_tree();
    if (alpha < lbl_805D8A34) {
        TObjPlayer__sub_80052390(alpha);
    }
    TObjFish::set_global_param(cf4);
    draw_chunk_object((void *)m34);
    if (m8b4 != 0U) {
        push_matrix();
        post_translate_matrix(lbl_804FF234);
        TObjFish::set_global_param(b88);
        draw_chunk_object((void *)m8b4);
        pop_matrix();
    }
    if (m8b0 != 0U) {
        TCharaMaking::enable_making();
        push_matrix();
        post_translate_matrix(lbl_804FF228);
        TObjFish::set_global_param(a1c);
        draw_chunk_object((void *)m8b0);
        pop_matrix();
        TCharaMaking::clear_flag_bit0();
    }
    if (alpha < lbl_805D8A34) {
        TObjPlayer::sync_player_globals();
    }
    if (m8ac != 0U) {
        TCharaMaking::enable_making();
        push_matrix();
        post_translate_matrix(lbl_804FF228);
        TObjFish::set_global_param(a1c);
        TCharaMaking__draw_colored_hair(alpha, (s32)m8ac, (CharacterAppearanceFields *)(p + 0x85C), 0);
        pop_matrix();
        TCharaMaking::clear_flag_bit0();
    }
}
