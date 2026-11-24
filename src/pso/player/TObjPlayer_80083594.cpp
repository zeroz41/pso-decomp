#include "pso/ui/window/TWindowCtrlMain_8024674C.h"
#include "pso/unk/text_803DD5E0.h"
#include "pso/render/GinjaRenderTarget.h"
#include "pso/render/GinjaTextureInput.h"
#pragma defer_codegen on

#pragma readonly_strings on

#include "types.h"
#include "pso/math/InverseTrig.h"
#include "pso/system/vector.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"

struct GXColor_80083B8C { u8 r, g, b, a; };

extern "C" {
void GXPixModeSync(void);
void GXSetTexCopySrc(u16, u16, u16, u16);
void GXSetTexCopyDst(u16, u16, s32, u8);
void GXSetCopyClear(GXColor_80083B8C, u32);
void GXCopyTex(void *, u8);
void GXSetViewport(f32, f32, f32, f32, f32, f32);
void GXSetScissor(u32, u32, u32, u32);
void clear_camera_capture_flags_bit2(void);
void set_camera_capture_flags_bit2(void);
}

#include "pso/effect/TEffect.h"
#include "pso/render/render_util.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include <stddef.h>
#include "pso/player/TObjPlayer.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/system/ControllerInput.h"

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

static NJS_TEXNAME effect_textures[54] = {
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

NJS_TEXLIST shared_effect_texture_list = {effect_textures, 54};

/* inferred: one-entry list init_capture_texture fills with a 640x480 render texture
   that capture_viewport_texture and copy_screen_to_texture copy the framebuffer into */
NJS_TEXNAME shared_capture_texture_entry = {NULL, 0, NULL};
NJS_TEXLIST shared_capture_texture_list = {&shared_capture_texture_entry, 1};

/* inferred: one-entry list TObjPlayer__sub_80083F38 fills with a 256x256 render texture
   that end_shadow_map_pass copies the shadow pass into and draw_if_all_ready binds */
NJS_TEXNAME shadow_map_texture_entry = {NULL, 0, NULL};
NJS_TEXLIST shadow_map_texture_list = {&shadow_map_texture_entry, 1};
Vec shadow_light_position = {0.0f, 0.0f, 0.0f};

extern "C" {
}

#include "pso/system/task/TMainTask.h"
#include "pso/camera/TLiveCameraView.h"
#include <stddef.h>
#include "pso/camera/TCameraCtrl.h"
#include "pso/unk/text_803DD5E0.h"
#include "pso/camera/CameraViewParams.h"
#include "pso/camera/CameraHelpers.h"
#include "pso/render/GinjaView.h"

extern "C" {
s32 GXSetZMode(int, int, int);
}
extern GinjaRenderTarget *camera_render_target_singleton;
void load_list_texture(s32 idx, s32 wrapS, s32 wrapT, s32 map);

#include "pso/player/TObjPlayer_80083B38.h"
#include "pso/player/TObjPlayer_800847A8.h"
#include "pso/system/memory.h"
#include "pso/player/TCameraCapturePass.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/map/FloorArea.h"
#include "pso/unk/TLobby.h"
#include "pso/player/TObjPlayer_80083594.h"
#include "pso/unk/text_803D96A8.h"
#include <stddef.h>
#include "pso/object/trap/TOTrapAncient02.h"
#include "pso/system/scene/TScene_800838C4.h"
#include "pso/system/scene/TScene.h"
#include "pso/system/main_loop.h"
#include "pso/render/RenderSbssGlobals.h"
#include "pso/player/PlayerSlots.h"

extern "C" {
u8 camera_capture_overlay_alpha = 143;
extern s32 model_render_flags;
}

void set_ginja_post_texgen_count(s32 x);
void set_ginja_post_tev_stage_count(s32 x);

extern "C" {
void translate_current_matrix_ps(f32, f32, f32);
void rotate_current_matrix_x_ps(s32);
void push_identity_matrix_ps();
}

struct Stack_800836E8 {
    f32 sp8;
    f32 spC;
    GC_Mtx sp10;
};

extern "C" {
s32 rotate_matrix_y(int, void *);
s32 GXSetTevOp(s32, s32);
s32 GXSetTevOrder(s32, s32, s32, s32);
}

void calc_projection_screen_offset(f32 *x, f32 *arg1);
f32 calc_camera_fov_degrees(void);
void load_current_pos_matrix(s32 arg0);
void load_current_tex_matrix(s32 i);

struct Stack_80083914 {
    f32 sp8;
    u8 pad_C[0x4];
    GC_Mtx sp10;
};

extern "C" {
// The game passes 8 floats; the SDK's C_MTXLightFrustum takes 9, so transT is whatever f9 holds.
s32 C_MTXLightFrustum(void *, f32, f32, f32, f32, f32, f32, f32, f32);
f32 rotate_matrix_by_node_angles(void *, int);
f32 sin_table_lookup(int);
f32 cos_table_lookup(int);
}

int lbl_805D4EE0;
unsigned char camera_capture_flags;
GinjaRenderTarget *camera_render_target_singleton;

extern "C" {
void reset_and_release_capture_texture(void);
void reset_and_init_capture_texture(void);
void clear_camera_flag(void);
void set_camera_capture_flags_bit0(void);
void **release_texture_list();
void **TObjPlayer__sub_80083F04(void);
s32 is_in_shadow_range(u8 *arg0, f32 farg0);
saddr get_capture_texture_pixels(void);
void TObjPlayer__sub_80083F38(void);
void **release_shared_capture_texture(void);
u8 get_display_copy_filter();
s32 GXSetCopyFilter(int, void *, int, void *);
s32 GXSetProjection(void *, int);
f32 vec_squared_length(void *);
void GXTexCoord2f32_80083594(f32 farg0, f32 farg1);
void GXColor1u32_80083594(s32 arg0);
void GXPosition3f32_80083594(f32 farg0, f32 farg1, f32 farg2);
s32 GXSetVtxDesc(s32, s32);
s32 GXClearVtxDesc();
s32 GXSetVtxAttrFmt(s32, s32, s32, s32, s32);
s32 GXSetNumTexGens(s32);
s32 GXBegin(s32, s32, s32);
s32 GXSetNumChans(s32);
}

void disable_camera_capture_overlay(void);
void init_capture_texture(s32 wide);
void set_light_ambient_color(f32 r, f32 g, f32 b);
void submit_light0(s32 arg0, s32 arg1);
void load_gx_light_slot(s32 arg0);
extern u8 *active_gx_render_mode;
void capture_viewport_texture(void);
void setup_blended_textured_draw(void);

extern "C" {
s32 GXSetTexCoordGen2(s32 a0 = 0, s32 a1 = 0, s32 a2 = 0, s32 a3 = 0, s32 a4 = 0, s32 a5 = 0);

int TObjPlayer::is_inactive() { return this->model_load_flags == 0; }

void GXPosition3f32_80083594(f32 farg0, f32 farg1, f32 farg2) {
    *(f32 *)0xCC008000 = farg0;
    *(f32 *)0xCC008000 = farg1;
    *(f32 *)0xCC008000 = farg2;
}

void GXColor1u32_80083594(s32 arg0) {
    *(s32 *)0xCC008000 = arg0;
}

void GXTexCoord2f32_80083594(f32 farg0, f32 farg1) {
    *(f32 *)0xCC008000 = farg0;
    *(f32 *)0xCC008000 = farg1;
}

f32 TObjPlayer::get_end_text_value(f32 x) {
    return atan(x);
}

void TObjPlayer::end_screen_quad() {  }

void TObjPlayer::set_tex_coord_gen(s32 dst, s32 func, s32 src, s32 mtx) {
    GXSetTexCoordGen2(dst, func, src, mtx, 0, 0x7D);
}

unsigned char get_camera_capture_flags(void) {  return camera_capture_flags; }

s32 test_camera_capture_flags_bits01(void) {
    if ((camera_capture_flags & 2) && (camera_capture_flags & 1)) {
        return 1;
    }
    return 0;
}
}

void disable_camera_capture_overlay(void) {
  int temp = (*(u8 *)&camera_capture_flags);
  (*(u8 *)&camera_capture_flags) = temp & (~2);
  camera_capture_overlay_alpha = 0x8F;
}

void set_camera_capture_flags_bit0(void) { (*(u8 *)&camera_capture_flags) = ((*(u8 *)&camera_capture_flags) | 0x1); }

s32 TObjPlayer::get_camera_flag() {
    return ((u8) (*(u8 *)&camera_capture_flags) >> 4U) & 1;
}

void clear_camera_flag(void) { (*(u8 *)&camera_capture_flags) = ((*(u8 *)&camera_capture_flags) & 0xffffffef); }

void set_camera_capture_flags_bit2(void) { (*(u8 *)&camera_capture_flags) = ((*(u8 *)&camera_capture_flags) | 0x4); }

void clear_camera_capture_flags_bit2(void) { (*(u8 *)&camera_capture_flags) = ((*(u8 *)&camera_capture_flags) & 0xfffffffb); }

void init_capture_texture(s32 wide) {
    GinjaTextureInput r;
    s32 mode;
    u16 w;
    u16 h;
    if (wide != 0) {
        mode = 6;
        w = 640;
        h = 480;
    } else {
        mode = 4;
        w = 640;
        h = 480;
    }
    r.set_render_rect(NULL, mode, w, h);
    set_texture_name(shared_capture_texture_list.textures, &r, 0x2EE0, 0x08800000);
    load_texture_list(&shared_capture_texture_list);
}

void **release_shared_capture_texture(void) {
    void **var_r3;
    var_r3 = (void **)&shared_capture_texture_list;
    if (shared_capture_texture_list.textures->texture != NULL) {
        var_r3 = release_texture_list();
    }
    return var_r3;
}

void TObjPlayer::reset_movie_state() { camera_capture_flags = 0; init_capture_texture((saddr)(1)); }

void reset_and_init_capture_texture(void) { camera_capture_flags = 0; init_capture_texture((saddr)(0)); }

void reset_and_release_capture_texture(void) { camera_capture_flags = 0; release_shared_capture_texture(); }

saddr get_capture_texture_pixels(void) {
    return (saddr)shared_capture_texture_list.textures->texture->surface->header.pixels;
}

void capture_viewport_texture(void) {
    if (!(camera_capture_flags & 4)) {
        GXColor_80083B8C c = {0, 0, 0, 0};
        GXSetCopyClear(c, 0xFFFFFF);
        GXSetTexCopySrc(0, 0, 0x280, 0x1E0);
        GXSetTexCopyDst(0x280, 0x1E0, 4, 0);
        if (camera_capture_flags & 8) {
            GXCopyTex(shared_capture_texture_list.textures->texture->surface->header.pixels, 1);
        } else {
            GXCopyTex(shared_capture_texture_list.textures->texture->surface->header.pixels, 0);
        }
        GXPixModeSync();
    }
}

void TObjPlayer::load_capture_texture() {
    TObjFish::set_global_param(&shared_capture_texture_list);
    load_list_texture(0, 0, 0, 0);
}

void TObjPlayer::draw_textured_screen_quad(u32 arg0, f32 *arg1, f32 *size, s32 arg3) {
    u32 temp_r31;
    void *temp_r4;
    void *temp_r4_2;
    f32 z;
    TObjFish::set_global_param(&shared_capture_texture_list);
    if (arg3 != 0) {
        temp_r4 = shared_capture_texture_list.textures->texture->surface;
        *(s32 *)((s8 *)temp_r4 + 0x10) = 0x100;
        *(s32 *)((s8 *)temp_r4 + 0x14) = 0xC0;
    }
    load_list_texture(0, 0, 0, 0);
    set_default_alpha_blend();
    TObjPlayer::load_screen_space_matrix();
    setup_blended_textured_draw();
    GXSetNumTexGens(1);
    GXSetNumChans(1);
    TObjPlayer::set_tex_coord_gen(0, 1, 4, 0x3C);
    GXSetTevOp(0, 1);
    GXSetTevOrder(0, 0, 0, 4);
    GXClearVtxDesc();
    GXSetVtxDesc(9, 1);
    GXSetVtxDesc(0xB, 1);
    GXSetVtxDesc(0xD, 1);
    GXSetVtxAttrFmt(4, 9, 1, 4, 0);
    GXSetVtxAttrFmt(4, 0xB, 1, 5, 0);
    GXSetVtxAttrFmt(4, 0xD, 1, 4, 0);
    GXBegin(0x80, 4, 4);
    z = -1.0f;
    GXPosition3f32_80083594(arg1[0] * z, arg1[1] * z, z);
    temp_r31 = (arg0 << 8) | (arg0 >> 24);
    GXColor1u32_80083594(temp_r31);
    GXTexCoord2f32_80083594(0.0f, 0.0f);
    GXPosition3f32_80083594(z * (arg1[0] + size[0]), arg1[1] * z, z);
    GXColor1u32_80083594(temp_r31);
    GXTexCoord2f32_80083594(1.0f, 0.0f);
    GXPosition3f32_80083594(z * (arg1[0] + size[0]), z * (arg1[1] + size[1]), z);
    GXColor1u32_80083594(temp_r31);
    GXTexCoord2f32_80083594(1.0f, 1.0f);
    GXPosition3f32_80083594(arg1[0] * z, z * (arg1[1] + size[1]), z);
    GXColor1u32_80083594(temp_r31);
    GXTexCoord2f32_80083594(0.0f, 1.0f);
    end_screen_quad();
    set_default_alpha_blend();
    if (arg3 != 0) {
        temp_r4_2 = shared_capture_texture_list.textures->texture->surface;
        *(s32 *)((s8 *)temp_r4_2 + 0x10) = 0x280;
        *(s32 *)((s8 *)temp_r4_2 + 0x14) = 0x1E0;
    }
}

void TObjPlayer::draw_screen_quad(u32 arg0, s32 arg1, f32 farg0) {
    f32 temp_f31;
    f32 temp_f30;
    f32 temp_f30_2;
    f32 s0;
    f32 s1;
    f32 z;
    u32 temp_r31;
    void *temp_r4;
    void *temp_r4_2;
    TObjFish::set_global_param(&shared_capture_texture_list);
    if (arg1 != 0) {
        temp_r4 = shared_capture_texture_list.textures->texture->surface;
        *(s32 *)((s8 *)temp_r4 + 0x10) = 0x100;
        *(s32 *)((s8 *)temp_r4 + 0x14) = 0xC0;
    }
    load_list_texture(0, 0, 0, 0);
    set_default_alpha_blend();
    TObjPlayer::load_screen_space_matrix();
    setup_blended_textured_draw();
    GXSetNumTexGens(1);
    GXSetNumChans(1);
    TObjPlayer::set_tex_coord_gen(0, 1, 4, 0x3C);
    GXSetTevOp(0, 1);
    GXSetTevOrder(0, 0, 0, 4);
    GXClearVtxDesc();
    GXSetVtxDesc(9, 1);
    GXSetVtxDesc(0xB, 1);
    GXSetVtxDesc(0xD, 1);
    GXSetVtxAttrFmt(4, 9, 1, 4, 0);
    GXSetVtxAttrFmt(4, 0xB, 1, 5, 0);
    GXSetVtxAttrFmt(4, 0xD, 1, 4, 0);
    GXBegin(0x80, 4, 4);
    z = -2.0f;
    temp_f31 = -farg0 * z;
    GXPosition3f32_80083594(temp_f31, temp_f31, z);
    temp_r31 = (arg0 << 8) | (arg0 >> 24);
    GXColor1u32_80083594(temp_r31);
    GXTexCoord2f32_80083594(0.0f, 0.0f);
    s0 = 640.0f + farg0;
    temp_f30 = s0 * z;
    GXPosition3f32_80083594(temp_f30, temp_f31, z);
    GXColor1u32_80083594(temp_r31);
    GXTexCoord2f32_80083594(1.0f, 0.0f);
    s1 = 480.0f + farg0;
    temp_f30_2 = s1 * z;
    GXPosition3f32_80083594(temp_f30, temp_f30_2, z);
    GXColor1u32_80083594(temp_r31);
    GXTexCoord2f32_80083594(1.0f, 1.0f);
    GXPosition3f32_80083594(temp_f31, temp_f30_2, z);
    GXColor1u32_80083594(temp_r31);
    GXTexCoord2f32_80083594(0.0f, 1.0f);
    end_screen_quad();
    set_default_alpha_blend();
    if (arg1 != 0) {
        temp_r4_2 = shared_capture_texture_list.textures->texture->surface;
        *(s32 *)((s8 *)temp_r4_2 + 0x10) = 0x280;
        *(s32 *)((s8 *)temp_r4_2 + 0x14) = 0x1E0;
    }
}

s32 TObjPlayer::check_all_players_ready() {
    s32 flag;
    s32 counter;
    void *p;
    flag = 1;
    if (((s32)is_shadow_pass_requested()) == 0) {
        return 0;
    }
    if (get_main_phase() == 0xF) {
        counter = 0;
        do {
            TObjPlayer *player = get_player_by_client_id(counter);
            if ((player != NULL) && (player->is_inactive() == 0)) {
                flag = 0;
            }
            counter += 1;
        } while (counter < 4);
    }
    return flag;
}

void TObjPlayer::clear_shadow_pass_request() { lbl_805D4EE0 = 0; }

void TObjPlayer::request_shadow_pass() { lbl_805D4EE0 = 1; }

int TObjPlayer::is_shadow_pass_requested() {  return lbl_805D4EE0; }

void TObjPlayer__sub_80083F38(void) {
    GinjaTextureInput r;
    r.set_render_rect(NULL, 2, 0x100, 0x100);
    set_texture_name(shadow_map_texture_list.textures, &r, 0x2EE1, 0x08800000);
    load_texture_list(&shadow_map_texture_list);
    lbl_805D4EE0 = 0;
}

void **TObjPlayer__sub_80083F04(void) {
    void **var_r3;
    var_r3 = (void **)&shadow_map_texture_list;
    if (shadow_map_texture_list.textures->texture != NULL) {
        var_r3 = release_texture_list();
    }
    return var_r3;
}

#pragma push
#pragma fp_contract on
void begin_shadow_map_pass(void) {
    Mtx44 proj;
    Vec d;
    f32 t;
    f32 r;
    if (is_split_screen() != 0) {
        return;
    }
    TObjPlayer::request_shadow_pass();
    if (TObjPlayer::check_all_players_ready() == 0) {
        return;
    }
    TCameraCtrl::restore_full_screen_view();
    if (camera_ctrl_instance == 0) {
        return;
    }
    d.x = camera_ctrl_instance->tgt.x - camera_ctrl_instance->pos.x;
    d.y = camera_ctrl_instance->tgt.y - camera_ctrl_instance->pos.y;
    d.z = camera_ctrl_instance->tgt.z - camera_ctrl_instance->pos.z;
    if (0.0f != vec_squared_length(&d)) {
        normalize_vector(&d);
        shadow_light_position.x = camera_ctrl_instance->pos.x + 0.4f * (256.0f * d.x);
        shadow_light_position.y = camera_ctrl_instance->pos.y;
        shadow_light_position.z = camera_ctrl_instance->pos.z + 0.4f * (256.0f * d.z);
    } else {
        shadow_light_position.x = 0.0f;
        shadow_light_position.y = 0.0f;
        shadow_light_position.z = 0.0f;
    }
    push_matrix();
    GXSetViewport(0.0f, 0.0f, 256.0f, 256.0f, 0.0f, 1.0f);
    GXSetScissor(1, 1, 0xFE, 0xFE);
    t = 2.1f;
    r = -2.1f;
    C_MTXFrustum(proj, t, -t, r, -r, 500.0f, 20000.0f);
    GXSetProjection(proj, 0);
    set_light_ambient_color(1.0f, 1.0f, 1.0f);
    submit_light0(0, 0);
    load_gx_light_slot(0);
    push_identity_matrix_ps();
    translate_current_matrix_ps(0.0f, 0.0f, -15000.0f);
    rotate_current_matrix_x_ps(0x3800);
    translate_current_matrix_ps(-shadow_light_position.x, -shadow_light_position.y, -shadow_light_position.z);
    set_ginja_draw_flags(2);
}

s32 is_in_shadow_range(u8 *radius, f32 farg0) {
    if ((camera_ctrl_instance != NULL) && (((farg0 * farg0) + horizontal_distance_squared((const Vec *)radius, &shadow_light_position)) <= 8537.761f)) {
        return 1;
    }
    return 0;
}

void end_shadow_map_pass() {
    u8 *temp_r31;
    if ((is_split_screen() == 0) && (TObjPlayer::check_all_players_ready() != 0) && (camera_ctrl_instance != NULL)) {
        pop_matrix();
        pop_matrix();
        GXColor_80083B8C c = {0, 0, 0, 0};
        GXSetCopyFilter((int) (0U), NULL, (int) (0U), NULL);
        set_cull_none();
        GXSetCopyClear(c, 0xFFFFFF);
        GXSetTexCopySrc(0, 0, 0x100, 0x100);
        GXSetTexCopyDst(0x100, 0x100, 2, 0);
        GXCopyTex(shadow_map_texture_list.textures->texture->surface->header.pixels, 1);
        GXPixModeSync();
        temp_r31 = active_gx_render_mode;
        GXSetCopyFilter((int) (*(u8 *)((s8 *)temp_r31 + 0x19)), temp_r31 + 0x1A, (int) (get_display_copy_filter()), temp_r31 + 0x32);
        GXSetViewport(0.0f, 0.0f, 640.0f, 480.0f, 0.0f, 1.0f);
        GXSetScissor(0, 0, 0x280, 0x1E0);
        GXSetProjection(scene_projection_state.matrix, 0);
        set_light_ambient_color(0.3f, 0.3f, 0.3f);
        submit_light0(0, 1);
        load_gx_light_slot(0);
        set_ginja_draw_flags(0);
        TCameraCtrl::restore_saved_view();
    }
}

#pragma pop
void TObjPlayer::draw_if_all_ready() {
    if ((is_split_screen() == 0) && (TObjPlayer::check_all_players_ready() != 0)) {
        TObjFish::set_global_param(&shadow_map_texture_list);
        load_list_texture(0, 0, 0, 1);
    }
}

f32 calc_camera_fov_degrees(void) {
    f32 temp_f2;
    f32 temp_f31;
    f32 var_f1;
    s32 temp_r31;
    var_f1 = 11832.0f;
    if (camera_ctrl_instance != NULL) {
        temp_f2 = (f32)camera_ctrl_instance->fov;
        temp_f2 *= 0.85f;
        temp_r31 = (s32) (temp_f2 / 2.0f);
        temp_f31 = cos_table_lookup(temp_r31);
        var_f1 = (f32) ((s32) (10430.38043493439 * TObjPlayer::get_end_text_value((f32) ((sin_table_lookup(temp_r31) / temp_f31) / 1.1333334f))) * 2);
    }
    return var_f1;
}

#pragma push
#pragma opt_common_subs off


void render_projected_shadow_receiver(u8 *arg0, saddr ang) {
    LAYOUT_ASSERT(sp8_offset, offsetof(Stack_80083914, sp8) == 0x0);
    LAYOUT_ASSERT(sp10_offset, offsetof(Stack_80083914, sp10) == 0x8);
    Stack_80083914 stack;
    f32 t;
    f32 r;
    if ((is_split_screen() == 0) && (TObjPlayer::check_all_players_ready() != 0)) {
        push_identity_matrix_ps();
        translate_current_matrix_ps(0.0f, 0.0f, -15000.0f);
        rotate_current_matrix_x_ps(0x3800);
        translate_current_matrix_ps(-shadow_light_position.x, -shadow_light_position.y, -shadow_light_position.z);
        translate_current_matrix_ps(*(f32 *)((s8 *)arg0 + 0), *(f32 *)((s8 *)arg0 + 4), *(f32 *)((s8 *)arg0 + 8));
        rotate_matrix_by_node_angles((void *)ang, 1);
        stack.sp8 = 0.5f;
        t = 2.1f;
        r = -2.1f;
        C_MTXLightFrustum(stack.sp10, -t, t, r, -r, 500.0f, 0.5f, 0.5f, 0.5f);
        PSMTXConcat(stack.sp10, *current_matrix, *current_matrix);
        load_current_tex_matrix(0);
        pop_matrix();
        load_current_pos_matrix(0);
        GXSetTevOrder(1, 1, 1, 4);
        GXSetTevOp(1, 1);
        TObjPlayer::set_tex_coord_gen(1, 0, 0, 0x1E);
        model_render_flags |= 0x80000;
        set_ginja_post_tev_stage_count(((int) (1U)));
        set_ginja_post_texgen_count(((int) (1U)));
    }
}
#pragma pop
void TScene::apply_single_screen_state() {
    if ((is_split_screen() == 0) && (TObjPlayer::check_all_players_ready() != 0)) {
        model_render_flags &= 0xFFF7FFFF;
        set_ginja_post_tev_stage_count(0);
        set_ginja_post_texgen_count(0);
    }
}

void load_projection_tex_matrix(saddr rotation_y) {
    GC_Mtx mtx;
    f32 spC;
    f32 sp8;
    f32 fovY;
    if (is_split_screen() == 0) {
        calc_projection_screen_offset(&spC, &sp8);
        push_matrix();
        rotate_matrix_y(0, (void *)rotation_y);
        fovY = (f32) (0.0054931640625 * calc_camera_fov_degrees());
        if (TCameraCtrl::is_view_offset() != 0) {
            C_MTXLightPerspective(mtx, fovY, 1.1333334f, 0.5f, -0.5f, (f32) (0.5f - spC), (f32) (0.5f - sp8));
        } else {
            C_MTXLightPerspective(mtx, fovY, 1.1333334f, 0.5f, -0.5f, 0.5f, 0.5f);
        }
        PSMTXConcat(mtx, *current_matrix, *current_matrix);
        load_current_tex_matrix(0);
        pop_matrix();
        load_current_pos_matrix(0);
    }
}

void load_projected_texture_matrix(f32 aspect) {
    LAYOUT_ASSERT(sp8_offset, offsetof(Stack_800836E8, sp8) == 0x0);
    LAYOUT_ASSERT(spC_offset, offsetof(Stack_800836E8, spC) == 0x4);
    LAYOUT_ASSERT(sp10_offset, offsetof(Stack_800836E8, sp10) == 0x8);
    Stack_800836E8 stack;
    f32 fovY;
    if (is_split_screen() == 0) {
        calc_projection_screen_offset(&stack.spC, &stack.sp8);
        push_matrix();
        fovY = (f32) (0.0054931640625 * calc_camera_fov_degrees());
        if (TCameraCtrl::is_view_offset() != 0) {
            C_MTXLightPerspective(stack.sp10, fovY, aspect, 0.5f, -0.5f, (f32) (0.5f - stack.spC), (f32) (0.5f - stack.sp8));
        } else {
            C_MTXLightPerspective(stack.sp10, fovY, aspect, 0.5f, -0.5f, 0.5f, 0.5f);
        }
        PSMTXConcat(stack.sp10, *current_matrix, *current_matrix);
        load_current_tex_matrix(0);
        pop_matrix();
        load_current_pos_matrix(0);
    }
}

void setup_particle_tev(s32 arg0) {
    if (is_split_screen() == 0) {
        GXSetTevOrder(1, 1, 1, 4);
        if (arg0 != 0) {
            GXSetTevOp(1, 0);
        } else {
            GXSetTevOp(1, 1);
        }
        TObjPlayer::set_tex_coord_gen(1, 0, 0, 0x1E);
        TObjFish::set_global_param(&shared_capture_texture_list);
        load_list_texture(0, 0, 0, 1);
        model_render_flags |= 0x80000;
        set_ginja_post_tev_stage_count(1);
        set_ginja_post_texgen_count(1);
    }
}

void TObjPlayer::setup_tev_stage() {
    if (is_split_screen() == 0) {
        GXSetTevOrder(1, 1, 1, 4);
        GXSetTevOp(1, 2);
        TObjPlayer::set_tex_coord_gen(1, 0, 0, 0x1E);
        TObjFish::set_global_param(&shared_capture_texture_list);
        load_list_texture(0, 0, 0, 1);
        model_render_flags |= 0x80000;
        set_ginja_post_tev_stage_count(1);
        set_ginja_post_texgen_count(1);
    }
}

void reset_particle_tev() {
    if (is_split_screen() == 0) {
        set_ginja_post_tev_stage_count(0);
        set_ginja_post_texgen_count(0);
        model_render_flags &= 0xFFF7FFFF;
    }
}


TCameraCapturePass::TCameraCapturePass(TObject *parent, s32 flags) : TObject(parent) {
    this->flags = flags;
}

TCameraCapturePass::~TCameraCapturePass() {
}

void TCameraCapturePass::run_task() {  }

void TCameraCapturePass::render_shadows() { if (TObjPlayer::get_camera_flag() != 0) { set_tev_swap_mode((u8)(0)); } }

void TCameraCapturePass::render() {
    if (!(get_camera_capture_flags() & 4)) {
        if (flags & 1) {
            if (test_camera_capture_flags_bits01() == 1) {
                TCameraCtrl::restore_full_screen_view();
                TParticleCtrl::begin_effect_render();
                TObjPlayer::draw_screen_quad(camera_capture_overlay_alpha << 0x18, 0, 0.0f);
                TParticleCtrl::end_effect_render();
                TCameraCtrl::restore_saved_view();
                disable_camera_capture_overlay();
            }
        } else {
            set_camera_capture_flags_bit0();
            capture_viewport_texture();
        }
        if (TObjPlayer::get_camera_flag() != 0) {
            clear_camera_flag();
            init_tev_swap();
        }
    }
}

void TObjPlayer::init_render_target_singleton() {
    GinjaRenderTarget *target;
    camera_render_target_singleton = NULL;
    if (get_current_floor_area() == AREA_GOL_DRAGON) {
        target = static_cast<GinjaRenderTarget *>(::operator new(sizeof(GinjaRenderTarget)));
        camera_render_target_singleton = target;
        if (target != NULL) {
            target->init_render_target();
        }
    }
}

void TObjPlayer::free_singleton() {
    if (camera_render_target_singleton != NULL) {
        camera_render_target_singleton->release_texture();
    }
    if (camera_render_target_singleton != NULL) {
        ::operator delete(camera_render_target_singleton);
        camera_render_target_singleton = NULL;
    }
}

TLiveCameraView::TLiveCameraView(TObject *parent, s32 id, const Vec *eye, const Vec *target, f32 value)
    : TObject(parent) {
    pad_38 = value;
    VecCopy(&this->eye, eye);
    VecCopy(&this->target, target);
    flags = 0;
}

TLiveCameraView::~TLiveCameraView() {}

#pragma push
#pragma opt_common_subs off
void TLiveCameraView::render_shadows() {
    if (is_split_screen() == 0) {
        TCameraCtrl::restore_full_screen_view();
        GXSetViewport(0.0f, 0.0f, 640.0f, 480.0f, 0.0f, 1.0f);
        GXSetScissor(0, 0, 0x280, 0x1E0);
        Vec up = {0.0f, 1.0f, 0.0f};
        set_perspective_projection_from_fov((camera_ctrl_instance->fov), 1.1333334f, 1.0f, 21000.0f);
        set_camera_look_at(&eye, &target, &up);
        if (camera_ctrl_instance != NULL) {
            Vec dir;
            s32 pitch;
            s32 yaw;
            dir.x = target.x - eye.x;
            dir.y = target.y - eye.y;
            dir.z = target.z - eye.z;
            direction_to_pitch_yaw(&dir, &pitch, &yaw);
            TCameraCtrl::calc_axes_from_angles((saddr)camera_ctrl_instance, pitch, yaw);
        }
        set_camera_capture_flags_bit2();
        main_task.render_scene_passes();
        clear_camera_capture_flags_bit2();
        if (camera_render_target_singleton != NULL) {
            GXColor_80083B8C c = {0, 0, 0, 0};
            GXSetCopyClear(c, 0xFFFFFF);
            GXSetZMode((int) (1U), 7, 1);
            GXSetTexCopySrc((int) (0U), 0, (int) (0x280U), (int) (0x1E0U));
            GXSetTexCopyDst(0x280, 0x1E0, 4, 0);
            GXCopyTex(camera_render_target_singleton->texture_list.textures->texture->surface->header.pixels, 1);
            GXPixModeSync();
        }
        GXSetViewport(0.0f, 0.0f, 640.0f, 480.0f, 0.0f, 1.0f);
        GXSetScissor(0, 0, 0x280, 0x1E0);
        TCameraCtrl::restore_saved_view();
        camera_ctrl_instance->calc_rotated_axes();
        camera_ctrl_instance->setup_default_view(0);
    }
}

#pragma pop
void TLiveCameraView::run_task() {}

void TLiveCameraView::render() {}

void TLiveCameraView::bind_texture() {
    if ((is_split_screen() == 0) && (camera_render_target_singleton != NULL)) {
        TObjFish::set_global_param(&camera_render_target_singleton->texture_list);
        load_list_texture(0, 0, 0, 0);
    }
}

void TLiveCameraView::set_view(const Vec *eye, const Vec *target) {
    VecCopy(&this->eye, eye);
    VecCopy(&this->target, target);
}

void calc_projection_screen_offset(f32 *x, f32 *arg1) {
    f32 dx = TCameraCtrl::view_params.screen.projection.center_x;
    f32 y = TCameraCtrl::view_params.screen.projection.center_y;
    f32 dy;
    dx -= 320.0f;
    dy = y - 240.0f;
    *x = (-0.12f * dx) / 80.0f;
    *arg1 = (0.235f * dy) / -112.0f;
}

void TObjPlayer::copy_screen_to_texture(s32 mode, void *src) {
    NJS_POINT2 a;
    NJS_POINT2 b;
    NJS_POINT2 v;
    void *cam;
    GXColor_80083B8C c = {0, 0, 0, 0};
    GXSetCopyClear(c, 0xFFFFFF);
    switch (mode) {
    case 0:
        if (src != NULL) {
            copy_vec2((&v), src);
            v.x -= 128.0f;
            v.y -= 96.0f;
        } else {
            v.x = 192.0f;
            v.y = 144.0f;
        }
        GXSetTexCopySrc(v.x, v.y, 0x100, 0xC0);
        GXSetTexCopyDst(0x100, 0xC0, 4, 0);
        GXCopyTex(shared_capture_texture_list.textures->texture->surface->header.pixels, 1);
        GXPixModeSync();
        cam = &controller_physical_port_bank.controllers[3];
        a.x = 192.0f;
        a.y = 144.0f;
        b.x = 256.0f;
        b.y = 192.0f;
        if (test_previous_buttons_packed(cam, 0x100) != 0) {
            set_tev_swap_mode(0);
        }
        TObjPlayer::draw_textured_screen_quad((u32)(-1), (f32 *)&a, (f32 *)&b, 1);
        if (test_previous_buttons_packed(cam, 0x100) != 0) {
            init_tev_swap();
        }
        draw_capture_caption_bar();
        GXSetTexCopySrc(0xC0, 0x90, 0x100, 0xC0);
        GXSetTexCopyDst(0x100, 0xC0, 4, 0);
        GXCopyTex(shared_capture_texture_list.textures->texture->surface->header.pixels, 1);
        GXPixModeSync();
        break;
    case 1:
        GXColor_80083B8C c = {0, 0, 0, 0};
        GXSetCopyClear(c, 0xFFFFFF);
        GXSetTexCopySrc(0, 0, 0x280, 0x1E0);
        GXSetTexCopyDst(0x280, 0x1E0, 4, 0);
        GXCopyTex(shared_capture_texture_list.textures->texture->surface->header.pixels, 1);
        GXPixModeSync();
        cam = &controller_physical_port_bank.controllers[3];
        a.x = 192.0f;
        a.y = 144.0f;
        b.x = 256.0f;
        b.y = 192.0f;
        if (test_previous_buttons_packed(cam, 0x100) != 0) {
            set_tev_swap_mode(0);
        }
        TObjPlayer::draw_textured_screen_quad((u32)(-1), (f32 *)&a, (f32 *)&b, 0);
        if (test_previous_buttons_packed(cam, 0x100) != 0) {
            init_tev_swap();
        }
        draw_capture_caption_bar();
        GXSetTexCopySrc(0xC0, 0x90, 0x100, 0xC0);
        GXSetTexCopyDst(0x100, 0xC0, 4, 0);
        GXCopyTex(shared_capture_texture_list.textures->texture->surface->header.pixels, 1);
        GXPixModeSync();
        break;
    }
}

void TLiveCameraView::enable() { flags &= ~4; }

void TLiveCameraView::disable() { flags |= 4; }

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
void TObjPlayer::draw_capture_caption_bar() {
    LAYOUT_ASSERT(sp8_offset, offsetof(Stack_80082C30, sp8) == 0x0);
    LAYOUT_ASSERT(spC_offset, offsetof(Stack_80082C30, spC) == 0x4);
    LAYOUT_ASSERT(sp10_offset, offsetof(Stack_80082C30, sp10) == 0x8);
    LAYOUT_ASSERT(sp14_offset, offsetof(Stack_80082C30, sp14) == 0xC);
    LAYOUT_ASSERT(sp18_offset, offsetof(Stack_80082C30, sp18) == 0x10);
    LAYOUT_ASSERT(sp1C_offset, offsetof(Stack_80082C30, sp1C) == 0x14);
    LAYOUT_ASSERT(sp20_offset, offsetof(Stack_80082C30, sp20) == 0x18);
    LAYOUT_ASSERT(sp24_offset, offsetof(Stack_80082C30, sp24) == 0x1C);
    Stack_80082C30 stack;
    f32 y;
    f32 x;
    TObjFish::set_global_param(hud_texlist);
    set_draw_texture_and_color(0, -1);
    begin_screen_draw(1);
    x = 192.0f;
    y = 315.0f;
    stack.sp8 = x;
    stack.spC = y;
    stack.sp10 = x + 256.0f;
    stack.sp14 = y + 19.0f;
    stack.sp18 = 0.0f;
    stack.sp1C = 0.9254902f;
    stack.sp20 = 1.0f;
    stack.sp24 = 1.0f;
    draw_textured_quad_at_depth((&stack.sp8), 0.5f);
    TWindowSubStatusDisp::get_player();
}

#pragma pop
