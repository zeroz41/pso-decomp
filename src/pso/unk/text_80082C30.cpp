#pragma readonly_strings on
#include "pso/effect/TEffect.h"
#include "pso/render/render_util.h"
#include "pso/misc/TWindowSubStatusDisp_803DEE6C.h"

#include "types.h"

#include <stddef.h>
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/misc/TWindowSubSymbolChatPartsSet.h"
#include "pso/object/TObjFish.h"
struct Stack_80082C30 {
    f32 sp8;
    f32 spC;
    f32 sp10;
    f32 sp14;
    f32 sp18;
    f32 sp1C;
    f32 sp20;
    f32 sp24;
};

struct Color_80082CDC { u8 r, g, b, a; };

struct V2_80082CDC { f32 x, y; };

struct C_80082CDC { u8 pad[0x20]; void *tex; };

struct B_80082CDC { u8 pad[0xC]; C_80082CDC *c; };

struct A_80082CDC { u8 pad[0x8]; B_80082CDC *b; };

static GinjaTextureEntry effect_textures[54] = {
    {"f008_white_npr01", 0, NULL},
    {"f032_awa_apn01", 0, NULL},
    {"f032_chun_npn01", 0, NULL},
    {"f032_flash_apr01", 0, NULL},
    {"f032_fog_npn01", 0, NULL},
    {"f032_gunbullet_apr01", 0, NULL},
    {"f032_kisekigreen_apn01", 0, NULL},
    {"f032_kisekired_apn01", 0, NULL},
    {"f032_kisekiviolet_apn01", 0, NULL},
    {"f032_lens01_apn01", 0, NULL},
    {"f032_lens02_apn01", 0, NULL},
    {"f032_lens03_apn01", 0, NULL},
    {"f032_lens04_apn01", 0, NULL},
    {"f032_lens05_apn01", 0, NULL},
    {"f032_lens06_apn01", 0, NULL},
    {"f032_lens07_apn01", 0, NULL},
    {"f032_mshield01_apn01", 0, NULL},
    {"f032_mshield02_apn01", 0, NULL},
    {"f032_netload_apr01", 0, NULL},
    {"f032_redgray_apn01", 0, NULL},
    {"f032_senkou_apr01", 0, NULL},
    {"f032_sennkou_apr01", 0, NULL},
    {"f032_shield01_apn01", 0, NULL},
    {"f032_slow_apn01", 0, NULL},
    {"f032_tama_apn01", 0, NULL},
    {"f064_hane_apr01", 0, NULL},
    {"f064_hitfirec_apr01", 0, NULL},
    {"f064_hitfirered_apr01", 0, NULL},
    {"f064_hitmark_apr01", 0, NULL},
    {"f064_hitmarkblue_apr01", 0, NULL},
    {"f064_impacte_apn01", 0, NULL},
    {"f064_lens01resize_apn01", 0, NULL},
    {"f064_megido_apr01", 0, NULL},
    {"f064_monshou_apr01", 0, NULL},
    {"f064_questloadapn16", 0, NULL},
    {"f064_senblue_apn01", 0, NULL},
    {"f064_shield02_apn01", 0, NULL},
    {"f064_shield03_apn01", 0, NULL},
    {"f064_shield04_apn01", 0, NULL},
    {"f064_shield05_apn01", 0, NULL},
    {"f128_bakuhatu_apn16", 0, NULL},
    {"f128_blackfog_nln16", 0, NULL},
    {"f128_feio_aln16", 0, NULL},
    {"f128_fog_aln16", 0, NULL},
    {"f128_granz_aln16", 0, NULL},
    {"f128_hibana_aln16", 0, NULL},
    {"f128_houden_apr16", 0, NULL},
    {"f128_lightning_alr16", 0, NULL},
    {"f128_smoke_apn16", 0, NULL},
    {"f128_worm_alr16", 0, NULL},
    {"f256_zonde_alr16", 0, NULL},
    {"k016_happa_npr01", 0, NULL},
    {"t032_heart_apn01", 0, NULL},
    {"u064_glasshahen_npr01", 0, NULL},
};

GinjaTextureList shared_effect_texture_list = {effect_textures, 54};

extern "C" {
extern s32 lbl_805D63F0;
extern const f32 lbl_805D93C0;
extern const f32 lbl_805D93C4;
extern const f32 lbl_805D93C8;
extern const f32 lbl_805D93CC;
extern const f32 lbl_805D93D0;
extern const f32 lbl_805D93D4;
extern const f32 lbl_805D93D8;
extern const f32 lbl_805D93DC;
void TObjPlayer__sub_80082C30(void);
s32 is_on_current_screen__11TCameraCtrlFv(void *, s32);
void GXPixModeSync(void);
void GXSetTexCopySrc(u16, u16, u16, u16);
void GXSetTexCopyDst(u16, u16, s32, u8);
void GXSetCopyClear(Color_80082CDC, u32);
void GXCopyTex(void *, u8);
extern A_80082CDC *shared_capture_texture_list[];
extern u8 controller_physical_port_bank[];
extern const f32 lbl_805D93E0;
extern const f32 lbl_805D93E4;
extern const f32 lbl_805D93E8;
extern Color_80082CDC lbl_805E1214;
extern Color_80082CDC lbl_805E1218;
}

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
void TObjPlayer__sub_80082C30(void) {
    typedef char sp8_offset[(offsetof(Stack_80082C30, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_80082C30, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_80082C30, sp10) == 0x8) ? 1 : -1];
    typedef char sp14_offset[(offsetof(Stack_80082C30, sp14) == 0xC) ? 1 : -1];
    typedef char sp18_offset[(offsetof(Stack_80082C30, sp18) == 0x10) ? 1 : -1];
    typedef char sp1C_offset[(offsetof(Stack_80082C30, sp1C) == 0x14) ? 1 : -1];
    typedef char sp20_offset[(offsetof(Stack_80082C30, sp20) == 0x18) ? 1 : -1];
    typedef char sp24_offset[(offsetof(Stack_80082C30, sp24) == 0x1C) ? 1 : -1];
    Stack_80082C30 stack;
    TObjFish::set_global_param(lbl_805D63F0);
    set_draw_texture_and_color(0, -1);
    begin_screen_draw(1);
    stack.sp8 = lbl_805D93C0;
    stack.spC = lbl_805D93C4;
    stack.sp10 = lbl_805D93C8 + lbl_805D93C0;
    stack.sp14 = lbl_805D93CC + lbl_805D93C4;
    stack.sp18 = lbl_805D93D0;
    stack.sp1C = lbl_805D93D4;
    stack.sp20 = lbl_805D93D8;
    stack.sp24 = lbl_805D93D8;
    draw_textured_quad_at_depth((&stack.sp8), lbl_805D93DC);
    TWindowSubStatusDisp::get_player();
}
#pragma pop

extern "C" void TObjPlayer__sub_80082CBC(void* effect) {
    *(reinterpret_cast<u8*>(effect) + 0x1C) |= 0x4;
}

extern "C" void TObjPlayer__sub_80082CCC(void* effect) {
    *(reinterpret_cast<u8*>(effect) + 0x1C) &= ~0x4;
}
void TObjPlayer::copy_screen_to_texture(s32 mode, void *src) {
    V2_80082CDC a;
    V2_80082CDC b;
    V2_80082CDC v;
    void *cam;
    GXSetCopyClear(lbl_805E1214, 0xFFFFFF);
    switch (mode) {
    case 0:
        if (src != NULL) {
            ((TWindowSubSymbolChatPartsSet *)(&v))->copy_vec2(src);
            v.x -= lbl_805D93E0;
            v.y -= lbl_805D93E4;
        } else {
            v.x = lbl_805D93C0;
            v.y = lbl_805D93E8;
        }
        GXSetTexCopySrc(v.x, v.y, 0x100, 0xC0);
        GXSetTexCopyDst(0x100, 0xC0, 4, 0);
        GXCopyTex(shared_capture_texture_list[0]->b->c->tex, 1);
        GXPixModeSync();
        cam = controller_physical_port_bank + 0x110;
        a.x = lbl_805D93C0;
        a.y = lbl_805D93E8;
        b.x = lbl_805D93C8;
        b.y = lbl_805D93C0;
        if (is_on_current_screen__11TCameraCtrlFv(cam, 0x100) != 0) {
            set_tev_swap_mode(0);
        }
        TObjPlayer::draw_textured_screen_quad((u32)(-1), (f32 *)&a, (f32 *)&b, 1);
        if (is_on_current_screen__11TCameraCtrlFv(cam, 0x100) != 0) {
            init_tev_swap();
        }
        TObjPlayer__sub_80082C30();
        GXSetTexCopySrc(0xC0, 0x90, 0x100, 0xC0);
        GXSetTexCopyDst(0x100, 0xC0, 4, 0);
        GXCopyTex(shared_capture_texture_list[0]->b->c->tex, 1);
        GXPixModeSync();
        break;
    case 1:
        GXSetCopyClear(lbl_805E1218, 0xFFFFFF);
        GXSetTexCopySrc(0, 0, 0x280, 0x1E0);
        GXSetTexCopyDst(0x280, 0x1E0, 4, 0);
        GXCopyTex(shared_capture_texture_list[0]->b->c->tex, 1);
        GXPixModeSync();
        cam = controller_physical_port_bank + 0x110;
        a.x = lbl_805D93C0;
        a.y = lbl_805D93E8;
        b.x = lbl_805D93C8;
        b.y = lbl_805D93C0;
        if (is_on_current_screen__11TCameraCtrlFv(cam, 0x100) != 0) {
            set_tev_swap_mode(0);
        }
        TObjPlayer::draw_textured_screen_quad((u32)(-1), (f32 *)&a, (f32 *)&b, 0);
        if (is_on_current_screen__11TCameraCtrlFv(cam, 0x100) != 0) {
            init_tev_swap();
        }
        TObjPlayer__sub_80082C30();
        GXSetTexCopySrc(0xC0, 0x90, 0x100, 0xC0);
        GXSetTexCopyDst(0x100, 0xC0, 4, 0);
        GXCopyTex(shared_capture_texture_list[0]->b->c->tex, 1);
        GXPixModeSync();
        break;
    }
}
