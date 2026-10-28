#include "types.h"
#include "pso/enemy/TObjEneDelDepthBomb.h"
#include "pso/enemy/TObjEneDelDepth_80315AD8.h"
#include "pso/enemy/TObjEneDelDepth.h"
#include "pso/misc/TLobby.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct Info_80315B10 { s32 a, b, c, d; };
struct Rec_80315B10 { u8 pad0[8]; s32 f8; s32 fC; u8 pad10[8]; s32 f18; s32 f1C; };
struct Obj_80315B10 { u8 pad0[0x42C]; Rec_80315B10 *rec; s32 f430; };
struct Sub_80315B10 { u8 pad0[0xC]; f32 fC; };

extern "C" {
s32 is_split_screen(void);
s32 dispatch_shared_handler_a__6TLobbyFl(s32);
Obj_80315B10 *load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern Info_80315B10 deldepth_anim_binding;
extern Info_80315B10 deldepth_anim_binding_b;
extern s32 TObjEneDelDepth__tune_params;
extern const f32 TObjEneDelDepth__data_805DF258;
void TLobby__sub_8001FE7C(void*, int);
s32 TObjControl__ct(s32, s32);
s32 __nw__7TObjectFUl(s32);

extern "C" void TObjEneDelDepth__sub_80313740();
extern "C" void update_bomb_drop__15TObjEneDelDepthFv();
extern "C" void TObjEneDelDepth__sub_803141A8();
extern "C" void update_movement__15TObjEneDelDepthFv();
extern "C" void update_scale_pulse__15TObjEneDelDepthFv();
extern "C" void init_draw_mode_and_motion__15TObjEneDelDepthFv();
extern "C" void init_draw_params__15TObjEneDelDepthFv();
extern "C" void enter_appear_state__15TObjEneDelDepthFv();
extern "C" void enter_state8__15TObjEneDelDepthFv();
extern "C" void init_depth__15TObjEneDelDepthFv();
extern "C" void init_draw_state__15TObjEneDelDepthFv();
extern "C" void init_move__15TObjEneDelDepthFv();
extern "C" void init_params__15TObjEneDelDepthFv();
extern "C" void init_state__15TObjEneDelDepthFv();
extern "C" u8 lbl_80475BD8[];
extern "C" u8 lbl_80475BE8[];
extern "C" u8 lbl_80475BF8[];
extern "C" u8 lbl_80475C08[];
extern "C" u8 lbl_80475C20[];
extern "C" u8 lbl_80475C38[];
extern "C" u8 lbl_80475C50[];
extern "C" u8 lbl_80475C64[];
extern "C" u8 lbl_80475C78[];
extern "C" u8 lbl_80475C90[];
extern "C" u8 lbl_80475CA8[];
extern "C" u8 lbl_80475CC0[];
extern "C" u8 lbl_80475CD8[];
extern "C" u8 lbl_80475CF0[];
extern "C" u8 lbl_80475D04[];
extern "C" u8 lbl_80475D18[];
extern "C" u8 lbl_80475D30[];
extern "C" u8 lbl_80475D40[];
extern "C" void setup_depth_draw__15TObjEneDelDepthFv();
extern "C" void start_attack_motion__15TObjEneDelDepthFv();
extern "C" void try_enter_appear__15TObjEneDelDepthFv();
extern "C" void try_relocate_on_timer__15TObjEneDelDepthFv();
extern "C" void update_ai_state__15TObjEneDelDepthFv();
extern "C" void update_attack_cast__15TObjEneDelDepthFv();
extern "C" void update_state__15TObjEneDelDepthFv();
extern "C" void update_state_flag__15TObjEneDelDepthFv();
extern void *lbl_804E80C0[4];
extern void *TObjEneDelDepth_motion_file_list[13];
extern void *lbl_804E8114[4];
extern void *TObjEneDelDepth_motion_names[13];
void *lbl_804E80C0[4] = {
    (void *)&lbl_80475BD8, (void *)&lbl_80475BE8, (void *)&lbl_80475BF8, (void *)0x0,
};
void *TObjEneDelDepth_motion_file_list[13] = {
    (void *)&lbl_80475C08, (void *)&lbl_80475C20, (void *)&lbl_80475C38, (void *)&lbl_80475C50,
    (void *)&lbl_80475C64, (void *)&lbl_80475C78, (void *)&lbl_80475C90, (void *)&lbl_80475CA8,
    (void *)&lbl_80475CC0, (void *)&lbl_80475CD8, (void *)&lbl_80475CF0, (void *)&lbl_80475D04,
    (void *)0x0,
};
void *lbl_804E8104[4] = {
    (void *)&lbl_80475D18, (void *)&lbl_804E80C0, (void *)&TObjEneDelDepth_motion_file_list, (void *)0x3000c,
};
void *lbl_804E8114[4] = {
    (void *)&lbl_80475D30, (void *)&lbl_80475BE8, (void *)&lbl_80475BF8, (void *)0x0,
};
void *TObjEneDelDepth_motion_names[13] = {
    (void *)&lbl_80475C08, (void *)&lbl_80475C20, (void *)&lbl_80475C38, (void *)&lbl_80475C50,
    (void *)&lbl_80475C64, (void *)&lbl_80475C78, (void *)&lbl_80475C90, (void *)&lbl_80475CA8,
    (void *)&lbl_80475CC0, (void *)&lbl_80475CD8, (void *)&lbl_80475CF0, (void *)&lbl_80475D04,
    (void *)0x0,
};
void *lbl_804E8158[4] = {
    (void *)&lbl_80475D40, (void *)&lbl_804E8114, (void *)&TObjEneDelDepth_motion_names, (void *)0x3000c,
};
void *TObjEneDelDepth_collision_body_parts[11] = {
    (void *)0x0, (void *)0x41700000, (void *)0x0, (void *)0x41200000,
    (void *)0x0, (void *)0x0, (void *)0x8003, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
void *lbl_804E8194[24] = {
    (void *)0x10000, (void *)0xb, (void *)0x3f000000, (void *)0x0,
    (void *)0x20000, (void *)0x5, (void *)0x3f4ccccd, (void *)0x0,
    (void *)0x30000, (void *)0x6, (void *)0x3f4ccccd, (void *)0x0,
    (void *)0x30000, (void *)0xb, (void *)0x3f000000, (void *)0x0,
    (void *)0x30000, (void *)0x9, (void *)0x3f4ccccd, (void *)0x0,
    (void *)0x30000, (void *)0xa, (void *)0x3f333333, (void *)0x0,
};
void *lbl_804E81F4[94] = {
    (void *)0x10000, (void *)0xb, (void *)0x3f000000, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)&init_params__15TObjEneDelDepthFv, (void *)0x0,
    (void *)0xffffffff, (void *)&try_relocate_on_timer__15TObjEneDelDepthFv, (void *)0x0, (void *)0xffffffff,
    (void *)&init_draw_params__15TObjEneDelDepthFv, (void *)0x0, (void *)0xffffffff, (void *)&TObjEneDelDepth__sub_80314EC4,
    (void *)0x0, (void *)0xffffffff, (void *)&init_draw_mode_and_motion__15TObjEneDelDepthFv, (void *)0x0,
    (void *)0xffffffff, (void *)&update_scale_pulse__15TObjEneDelDepthFv, (void *)0x0, (void *)0xffffffff,
    (void *)&start_move_toward_player__15TObjEneDelDepthFv, (void *)0x0, (void *)0xffffffff, (void *)&update_movement__15TObjEneDelDepthFv,
    (void *)0x0, (void *)0xffffffff, (void *)&enter_state8__15TObjEneDelDepthFv, (void *)0x0,
    (void *)0xffffffff, (void *)&update_state__15TObjEneDelDepthFv, (void *)0x0, (void *)0xffffffff,
    (void *)&enter_appear_state__15TObjEneDelDepthFv, (void *)0x0, (void *)0xffffffff, (void *)&try_enter_appear__15TObjEneDelDepthFv,
    (void *)0x0, (void *)0xffffffff, (void *)&TObjEneDelDepth__sub_80314500, (void *)0x0,
    (void *)0xffffffff, (void *)&TObjEneDelDepth__sub_803142DC, (void *)0x0, (void *)0xffffffff,
    (void *)&init_depth__15TObjEneDelDepthFv, (void *)0x0, (void *)0xffffffff, (void *)&TObjEneDelDepth__sub_803141A8,
    (void *)0x0, (void *)0xffffffff, (void *)&setup_depth_draw__15TObjEneDelDepthFv, (void *)0x0,
    (void *)0xffffffff, (void *)&move_toward_target__15TObjEneDelDepthFv, (void *)0x0, (void *)0xffffffff,
    (void *)&TObjEneDelDepth__sub_80313DE4, (void *)0x0, (void *)0xffffffff, (void *)&update_attack_cast__15TObjEneDelDepthFv,
    (void *)0x0, (void *)0xffffffff, (void *)&init_draw_state__15TObjEneDelDepthFv, (void *)0x0,
    (void *)0xffffffff, (void *)&update_bomb_drop__15TObjEneDelDepthFv, (void *)0x0, (void *)0xffffffff,
    (void *)&init_state__15TObjEneDelDepthFv, (void *)0x0, (void *)0xffffffff, (void *)&update_state_flag__15TObjEneDelDepthFv,
    (void *)0x0, (void *)0xffffffff, (void *)&start_attack_motion__15TObjEneDelDepthFv, (void *)0x0,
    (void *)0xffffffff, (void *)&update_ai_state__15TObjEneDelDepthFv, (void *)0x0, (void *)0xffffffff,
    (void *)&init_move__15TObjEneDelDepthFv, (void *)0x0, (void *)0xffffffff, (void *)&TObjEneDelDepth__sub_80313954,
    (void *)0x0, (void *)0xffffffff, (void *)&TObjEneDelDepth__sub_803138F8, (void *)0x0,
    (void *)0xffffffff, (void *)&TObjEneDelDepth__sub_80313740,
};
void *lbl_804E836C[90] = {
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0,
};

void TObjEneDelDepth::free_shared_data() {
    extern u32 TObjEneDelDepth__shared_resource;
    if ((u32) TObjEneDelDepth__shared_resource != 0U) {
        TLobby__sub_8001FE7C((void*)TObjEneDelDepth__shared_resource, 1);
        TObjEneDelDepth__shared_resource = 0U;
    }
}

void TObjEneDelDepth::load_assets() {
    extern Obj_80315B10 *TObjEneDelDepth__shared_resource;
    Sub_80315B10 *g;

    if (is_split_screen() != 0) {
        Obj_80315B10 *p = (Obj_80315B10 *)::operator new(0x440);
        if (p != NULL) {
            p = load_resource_from_descriptor(p, 1, lbl_804E8158, 0, 0, 0);
        }
        TObjEneDelDepth__shared_resource = p;
    } else {
        Obj_80315B10 *p = (Obj_80315B10 *)::operator new(0x440);
        if (p != NULL) {
            p = load_resource_from_descriptor(p, 1, lbl_804E8104, 0, 0, 0);
        }
        TObjEneDelDepth__shared_resource = p;
    }
    g = (Sub_80315B10 *)TObjEneDelDepth_collision_body_parts;
    {
        Info_80315B10 info = deldepth_anim_binding;
        info.a = TObjEneDelDepth__shared_resource->f430;
        TLobby::spawn_npc_enemy((s16)0x47, TObjEneDelDepth__shared_resource->rec->f8, TObjEneDelDepth__shared_resource->rec->fC, (s32)&info, g->fC, (f32)TObjEneDelDepth__data_805DF258);
    }
    {
        Info_80315B10 info = deldepth_anim_binding_b;
        info.a = TObjEneDelDepth__shared_resource->f430;
        TLobby::spawn_npc_enemy((s16)0x48, TObjEneDelDepth__shared_resource->rec->f18, TObjEneDelDepth__shared_resource->rec->f1C, (s32)&info, g->fC, (f32)TObjEneDelDepth__data_805DF258);
    }
    TObjEneDelDepth__tune_params = dispatch_shared_handler_a__6TLobbyFl(0x30);
}

extern s32 tl_04;

s32 TObjEneDelDepth__create(s32 arg0) {
    s32 ene_del_depth;
    s32 var_r4;

    ene_del_depth = __nw__7TObjectFUl(0x434);
    if (ene_del_depth != 0) {
        var_r4 = __nw__7TObjectFUl(0x20);
        if (var_r4 != 0) {
            var_r4 = TObjControl__ct(var_r4, tl_04);
        }
        ene_del_depth = (s32)TObjEneDelDepth__ct((u8 *)ene_del_depth, var_r4, arg0);
    }
    return ene_del_depth;
}

}
