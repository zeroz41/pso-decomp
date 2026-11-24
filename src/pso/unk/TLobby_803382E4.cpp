#include "pso/system/memory.h"
#include "pso/ui/window/TWindowCtrlMain_8024674C.h"
#include "pso/render/GinjaTexture.h"
#include "pso/ui/UISprite.h"
#include "pso/render/GvmTextureArchive.h"
#include "pso/render/GinjaMaterialState.h"
#include "pso/system/ResourceFile.h"
#include "types.h"
#include "pso/unk/TLobby_803382E4.h"
#include "pso/unk/text_800F7DAC.h"
#include "pso/render/render_util.h"
#include "pso/unk/text_803DA798.h"
#include "pso/unk/text_803E2D70.h"

#include "pso/unk/TLobby.h"
#include "pso/system/NinjaTypes.h"
#include "pso/ui/frontend/TAdPlayerLoadGC.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/render/GinjaView.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/math/AngleLookup.h"
#include "pso/system/TLanguage_801E4874.h"


// These records are consecutive in the overlay data, beginning at lbl_804EF1B8.
struct LobbyOverlayVertices {
    NJS_TEXNAME texture_names[3];
    NJS_TEXLIST texture_list;
    ProjectedVertex title[4];
    ProjectedStripVertex info_icon[4];
    ProjectedStripVertex hud_icon[4];
};

extern "C" {
s32 lobby_request_flags;
int info_icon_texture;
s32 lobby_pulse_color_phase;
u32 __cvt_fp2unsigned(f32);

NJS_TEXNAME lbl_804EF1B8[3] = {
    { "f256_nowloading", 0, 0 },
    { "f256_nowloading_b", 0, 0 },
    { "f064_mahourot", 0, 0 },
};
__declspec(section ".data") NJS_TEXLIST lbl_804EF1DC = {lbl_804EF1B8, 3};
ProjectedVertex title_pulse_color_table[4] = {
    { 528.0f, 289.0f, 0.5f, 0xB4000000 },
    { 592.0f, 289.0f, 0.5f, 0xB4000000 },
    { 528.0f, 353.0f, 0.5f, 0xB4000000 },
    { 592.0f, 353.0f, 0.5f, 0xB4000000 },
};
ProjectedStripVertex lobby_pulse_color_table[8] = {
    { 528.0f, 289.0f, 0.5f, 0.0f, 0.0f, 0xFFFFFFFF },
    { 592.0f, 289.0f, 0.5f, 1.0f, 0.0f, 0xFFFFFFFF },
    { 528.0f, 353.0f, 0.5f, 0.0f, 1.0f, 0xFFFFFFFF },
    { 592.0f, 353.0f, 0.5f, 1.0f, 1.0f, 0xFFFFFFFF },
    { 496.0f, 355.0f, 0.5f, 0.390625f, 0.0f, 0xFFFFFFFF },
    { 624.0f, 355.0f, 0.5f, 0.890625f, 0.0f, 0xFFFFFFFF },
    { 496.0f, 411.0f, 0.5f, 0.390625f, 0.21875f, 0xFFFFFFFF },
    { 624.0f, 411.0f, 0.5f, 0.890625f, 0.21875f, 0xFFFFFFFF },
};
ProjectedStripVertex lbl_804EF2E4[4] = {
    { 368.0f, 352.0f, 0.5f, 0.0f, 0.0f, 0xFFFFFFFF },
    { 368.0f, 480.0f, 0.5f, 0.0f, 1.0f, 0xFFFFFFFF },
    { 497.0f, 352.0f, 0.5f, 1.0f, 0.0f, 0xFFFFFFFF },
    { 497.0f, 480.0f, 0.5f, 1.0f, 1.0f, 0xFFFFFFFF },
};
ProjectedStripVertex lbl_804EF344[4] = {
    { 496.0f, 352.0f, 0.5f, 0.0f, 0.0f, 0xFFFFFFFF },
    { 496.0f, 480.0f, 0.5f, 0.0f, 1.0f, 0xFFFFFFFF },
    { 624.0f, 352.0f, 0.5f, 1.0f, 0.0f, 0xFFFFFFFF },
    { 624.0f, 480.0f, 0.5f, 1.0f, 1.0f, 0xFFFFFFFF },
};
NJS_TEXANIM lbl_804EF3A4[3] = {
    { 64, 64, 32, 32, 0, 0, 256, 256, 2, 0 },
    { 64, 64, 32, 32, 0, 0, 256, 256, 2, 0 },
    { 64, 64, 32, 32, 0, 0, 256, 256, 2, 0 },
};
NJS_SPRITE lbl_804EF3E0 = {
    { 496.0f, 416.0f, 0.0f }, 1.0f, 1.0f, 0, &lbl_804EF1DC, lbl_804EF3A4,
};

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma fp_contract on
void TLobby__sub_803382E4(void) {
    f32 alpha;

    if (lobby_request_flags & 2) {
        lbl_804EF3E0.ang += 0x16C;
        alpha = 0.5f + (1.0f + cos_table_lookup(lbl_804EF3E0.ang)) / 4.0f;
        set_perspective_projection_from_fov(0x3555, 1.1333334f, 1.0f, 21000.0f);
        set_depth_buffer_settings_2();
        TParticleCtrl::begin_effect_render();
        TCameraCtrl::restore_full_screen_view();
        set_default_alpha_blend();
        TObjFish::set_global_param(&lbl_804EF1DC);
        set_texture_num(0);
        TLobby__sub_803E2EE4(0);
        draw_projected_textured_strip(lbl_804EF2E4, 4);
        TLobby::reset_player_state();
        set_texture_num(1);
        TLobby__sub_803E2EE4(0);
        draw_projected_textured_strip(lbl_804EF344, 4);
        TLobby::reset_player_state();
        set_additive_blend();
        draw_compass_sprite(&lbl_804EF3E0, 2, (__cvt_fp2unsigned(255.0f * alpha) << 24) | 0xFFFFFF, 0x21, 0.5f);
        set_default_alpha_blend();
        TCameraCtrl::restore_saved_view();
        TParticleCtrl::end_effect_render();
        restore_saved_depth_alpha_state();
    }
}
}
#pragma pop

void TLobby::handle_flag2_request() {
    if (lobby_request_flags & 2) {
        release_texture_list(&lbl_804EF1DC);
        lobby_request_flags &= 0xFFFFFFFD;
    }
}

void TLobby::load_now_loading_texture() {
    void *archive;
    void *packed;
    if (!(lobby_request_flags & 2)) {
        archive = TQuestVmDownLoadServer::alloc(0x11000);
        packed = TQuestVmDownLoadServer::alloc(0x2000);
        read_disc_file_sectors("NowLoading.prs", packed);
        prs_decompress_buffer(reinterpret_cast<saddr>(packed), reinterpret_cast<saddr>(archive));
        load_gvm_texture_archive(archive, &lbl_804EF1DC);
        safe_free(packed);
        safe_free(archive);
        lobby_request_flags |= 2;
    }
}

void render_info_icon_overlay(void) {
    s32 instance;
    instance = TAdPlayerLoadGC::get_instance();
    switch (instance) {
    case 5:
    case 6:
    case 11:
    case 12:
    case 15:
    case 19:
        TLobby::update_pulse_colors(0);
        TLobby__sub_80338534();
        return;
    case 18:
        TLobby::update_pulse_colors(1);
        TLobby__sub_80338534();
    default:
        return;
    }
}

#pragma push
#pragma opt_propagation off

void TLobby__sub_80338534(void) {
    LobbyOverlayVertices *overlay = reinterpret_cast<LobbyOverlayVertices *>(lbl_804EF1B8);
    TCameraCtrl::restore_full_screen_view();
    set_default_alpha_blend();
    TParticleCtrl::begin_effect_render();
    TObjBoss2Tunnel::setup_projected_color_draw(1);
    TObjBoss2Tunnel::draw_projected_quads(overlay->title, 4);
    TObjBoss2Tunnel::reset_player_state();
    if ((u32)info_icon_texture != 0) {
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(info_icon_texture));
        if (lobby_request_flags & 4) {
            set_texture_num(1);
        } else {
            set_texture_num(0);
        }
        set_additive_blend();
        TLobby__sub_803E2EE4(1);
        draw_projected_textured_strip(overlay->info_icon, 4);
        TLobby::reset_player_state();
        set_default_alpha_blend();
        TObjFish::set_global_param(hud_texlist);
        set_texture_num(5);
        TLobby__sub_803E2EE4(1);
        draw_projected_textured_strip(overlay->hud_icon, 4);
        TLobby::reset_player_state();
    }
    set_default_alpha_blend();
    TCameraCtrl::restore_saved_view();
    TParticleCtrl::end_effect_render();
}
#pragma pop

#pragma push
#pragma fp_contract on
void TLobby::update_pulse_colors(s32 arg0) {
    f32 t;
    u32 c0;
    u32 c1;
    s32 i;
    ProjectedVertex *b;
    ProjectedStripVertex *a;
    t = 0.5f + (1.0f + cos_table_lookup(lobby_pulse_color_phase)) / 4.0f;
    lobby_pulse_color_phase += 0xCCC;
    c0 = ((u32)(255.0f * t) << 24) | 0xFFFFFF;
    c1 = (u32)(178.0f * t) << 24;
    a = lobby_pulse_color_table;
    b = title_pulse_color_table;
    for (i = 0; i < 4; i++) {
        a->color = c0;
        a++;
        b->color = c1;
        b++;
    }
    switch (arg0) {
    case 0:
        lobby_request_flags &= ~4;
        break;
    case 1:
        lobby_request_flags |= 4;
        break;
    }
}
#pragma pop

void TWindowSubStatusDisp__sub_803386F0(void) { TObjPlayer::free_if_valid(info_icon_texture); }

void load_info_icon(void) { info_icon_texture = (saddr)load_gvm_texture_file("InfoIcon.gvm"); }
