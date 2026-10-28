#include "types.h"
#include "pso/enemy/TObjEneRecon_8029E89C.h"
#include "pso/unk/text_8029E7BC.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/memory.h"
#include "pso/misc/TSceneSora.h"
#include "pso/enemy/TObjEneRecon.h"
#include "pso/misc/TOKeyMachine01.h"

struct Vec_8029EA4C { f32 x, y, z; };

#include <stddef.h>
struct Stack_8029E960 {
    f32 sp8;
    f32 spC;
    f32 sp10;
    f32 sp14;
    f32 sp18;
    f32 sp1C;
};

extern "C" {
s32 GXSetScissor(s32, s32, s32, s32);
void project_world_to_screen(s32, void *, void *);
extern u16 scene_sora_reflect_active;
extern const f32 lbl_805DDD8C;
extern const f32 lbl_805DDD94;
s32 reflect_matrix_in_plane(s32, s32 *);
s32 push_matrix();
extern const f32 lbl_805DDD90;
void *get_player_by_client_id(s32 i);
s32 reset_ind_tev_stages__13TParticleCtrlFPv();

s32 TObjEneRecon::render_player_marker(u16 arg0, s32 arg1) {
    s32 sp8[8];
    s32 var_r3;
    u32 player;

    if (TOKeyMachine01::is_state_active() == 0) {
        return 0;
    }
    if ((u16) scene_sora_reflect_active == 0) {
        return 1;
    }
    player = (u32)get_player_by_client_id(arg0);
    if (player == 0U) {
        return 0;
    }
    if (fn_8029E7BC(player + 0x2FC, (u8 *)sp8) == 0) {
        return 0;
    }
    if (arg1 != 0) {
        var_r3 = TObjEneRecon__sub_8029EA4C(sp8, 1);
    } else {
        var_r3 = 1;
    }
    if (var_r3 != 0) {
        push_matrix();
        reflect_matrix_in_plane(0, sp8);
    }
    return var_r3;
}

s32 TObjEneRecon::push_reflect_matrix() {
    typedef char sp8_offset[(offsetof(Stack_8029E960, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_8029E960, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_8029E960, sp10) == 0x8) ? 1 : -1];
    typedef char sp14_offset[(offsetof(Stack_8029E960, sp14) == 0xC) ? 1 : -1];
    typedef char sp18_offset[(offsetof(Stack_8029E960, sp18) == 0x10) ? 1 : -1];
    typedef char sp1C_offset[(offsetof(Stack_8029E960, sp1C) == 0x14) ? 1 : -1];
    Stack_8029E960 stack;
    s32 temp_r3;
    if ((u16) scene_sora_reflect_active == 0) {
        return 1;
    }
    if (this == NULL) {
        return 0;
    }
    stack.sp8 = *(f32 *)&this->m_name;
    stack.spC = *(f32 *)&this->m_flags;
    stack.sp10 = *(f32 *)&this->m_prev;
    stack.sp14 = lbl_805DDD8C;
    stack.sp18 = lbl_805DDD90;
    stack.sp1C = stack.sp14;
    temp_r3 = TObjEneRecon__sub_8029EA4C(this, 1);
    if (temp_r3 != 0) {
        push_matrix();
        reflect_matrix_in_plane(0, (s32 *)&stack.sp8);
    }
    return temp_r3;
}
}

void restore_render_scissor(s32 arg0) {
    if ((u16) scene_sora_reflect_active != 0) {
        pop_matrix();
        if (arg0 != 0) {
            GXSetScissor(0, 0, 0x280, 0x1E0);
        }
    }
}

extern u32 scene_sora_instance;
extern "C" {

s32 TObjEneRecon__sub_8029EA4C(void *arg0, s32 _w1) {
    Vec_8029EA4C v;
    if (scene_sora_reflect_active == 0) {
        return 1;
    }
    restore_render_scissor(1);
    project_world_to_screen(0, arg0, &v);
    if (v.y >= lbl_805DDD8C && v.y <= lbl_805DDD94) {
        GXSetScissor(0, (s32)((u32)v.y), 0x280, (s32)((u32)(lbl_805DDD94 - v.y)));
        return 1;
    }
    return 0;
}

void TObjEneRecon::update_particle_if_active() {
    if (((u32) scene_sora_instance != 0U) && (((TSceneSora *)scene_sora_instance)->get_state() != 0U)) {
        reset_ind_tev_stages__13TParticleCtrlFPv();
    }
}

s32 play_particle__13TParticleCtrlFls(u32, s32, s32);

void TObjEneRecon::notify_scene(s32 arg0) {
    u32 temp_r31;
    if ((u32) scene_sora_instance != 0U) {
        temp_r31 = ((TSceneSora *)scene_sora_instance)->get_state();
        if (temp_r31 != 0U) {
            play_particle__13TParticleCtrlFls(temp_r31, 0, arg0);
        }
    }
}
}

#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

extern "C" {

s32 init_render_target__10TObjPlayerFv();

extern u32 scene_sora_recon_object;

void TObjEneRecon::destroy_instance() {
    scene_sora_instance = 0;
    if (TOKeyMachine01::is_state_active() != 0) {
        if ((u32) scene_sora_recon_object != 0U) {
            ((TObjPlayer *)scene_sora_recon_object)->reset_lobby_subobject();
        }
        if ((u32) scene_sora_recon_object != 0U) {
            ::operator delete((void *)scene_sora_recon_object);
            scene_sora_recon_object = 0U;
        }
    }
}

extern s32 lbl_805D65F0;

void TObjEneRecon::alloc_if_valid_state() {
    u32 temp_r3;

    if (TOKeyMachine01::is_state_active() != 0) {
        scene_sora_instance = 0;
        temp_r3 = (int)::operator new(0x28);
        scene_sora_recon_object = temp_r3;
        if (temp_r3 != 0U) {
            init_render_target__10TObjPlayerFv();
            lbl_805D65F0 = scene_sora_recon_object + 0x1C;
        }
    }
}

}
