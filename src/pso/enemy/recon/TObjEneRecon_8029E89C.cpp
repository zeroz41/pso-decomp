#include "pso/render/reflection.h"
#include "types.h"
#include "pso/enemy/recon/TObjEneRecon_8029E89C.h"
#include "pso/unk/text_8029E7BC.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/memory.h"
#include "pso/system/scene/TSceneSora.h"
#include "pso/enemy/recon/TObjEneRecon.h"
#include "pso/object/key/TOKeyMachine01.h"
#include "pso/map/FloorArea.h"
#include "pso/player/TObjPlayer_801AF2F0.h"

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
s32 reset_ind_tev_stages__13TParticleCtrlFPv();

s32 TObjEneRecon::render_player_marker(u16 arg0, s32 arg1) {
    s32 sp8[8];
    s32 var_r3;
    u32 player;

    if (is_central_control_area() == 0) {
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

}

s32 push_reflection_matrix(Vec *point) {
    Vec plane[2];
    s32 visible;
    if (scene_sora_reflect_active == 0) {
        return 1;
    }
    if (point == NULL) {
        return 0;
    }
    plane[0].x = point->x;
    plane[0].y = point->y;
    plane[0].z = point->z;
    plane[1].x = lbl_805DDD8C;
    plane[1].y = lbl_805DDD90;
    plane[1].z = plane[1].x;
    visible = TObjEneRecon__sub_8029EA4C((void *)point, 1);
    if (visible != 0) {
        push_matrix();
        reflect_matrix_in_plane(0, (s32 *)plane);
    }
    return visible;

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
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

extern "C" {

s32 init_render_target__10TObjPlayerFv();

extern u32 scene_sora_recon_object;

void TObjEneRecon::destroy_instance() {
    scene_sora_instance = 0;
    if (is_central_control_area() != 0) {
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

    if (is_central_control_area() != 0) {
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
