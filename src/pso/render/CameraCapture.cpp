#include "pso/render/GinjaTextureInput.h"
#pragma defer_codegen on

#pragma readonly_strings on

#include "types.h"
#include "pso/render/gjSystem.h"
#include "pso/math/InverseTrig.h"
#include <dolphin/mtx.h>
#include <dolphin/gx/GXFrameBuffer.h>
#include <dolphin/gx/GXManage.h>
#include <dolphin/gx/GXTransform.h>
#include <dolphin/gx/GXCull.h>
#include <dolphin/gx/GXPixel.h>
#include <dolphin/gx/GXTev.h>
#include <dolphin/gx/GXGeometry.h>
#include <dolphin/gx/GXLighting.h>
#include "pso/system/vector.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/ui/keyboard/SystemBootInit.h"
#include "pso/render/CameraCapture.h"
#include "pso/render/ScreenPrimitiveDraw.h"
#include "pso/effect/TEffect.h"
#include "pso/render/render_util.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include <stddef.h>
#include "pso/player/TObjPlayer.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/render/TextureState.h"
#include "pso/system/ControllerInput.h"
#include "pso/effect/sprite/TQuadSprite.h"

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

NJS_TEXNAME shared_capture_texture_entry = {NULL, 0, NULL};
NJS_TEXLIST shared_capture_texture_list = {&shared_capture_texture_entry, 1};

NJS_TEXNAME shadow_map_texture_entry = {NULL, 0, NULL};
NJS_TEXLIST shadow_map_texture_list = {&shadow_map_texture_entry, 1};
// Where the shadow-map pass looks from: 102.4 units ahead of the camera, at its height.
Vec shadow_light_position = {0.0f, 0.0f, 0.0f};


#include "pso/system/task/TMainTask.h"
#include "pso/camera/TLiveCameraView.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/render/TextureLoad.h"
#include "pso/camera/CameraViewParams.h"
#include "pso/camera/CameraHelpers.h"
#include "pso/render/GinjaView.h"
#include "pso/render/GinjaTexture.h"
#include "pso/system/memory.h"
#include "pso/player/TCameraCapturePass.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/map/FloorArea.h"
#include "pso/network/TLobby.h"
#include "pso/system/MatrixStack.h"
#include "pso/object/trap/TOTrapAncient02.h"
#include "pso/system/scene/TScene.h"
#include "pso/system/main_loop.h"
#include "pso/render/RenderSbssGlobals.h"
#include "pso/render/model_render_state.h"
#include "pso/player/PlayerSlots.h"
#include "pso/render/GinjaDrawUtil.h"
#include "pso/render/SceneFog.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/render/gjLight.h"
#include "pso/boss/derolle/DisplayCopyFilter.h"
#include "pso/math/AngleLookup.h"
#include "pso/math/MatrixVector.h"
#include "pso/system/MatrixStack.h"
#include "pso/math/MatrixReflect.h"
#include "pso/ui/window/TWindowBase.h"

u8 camera_capture_overlay_alpha = 143;

int shadow_pass_requested;
u8 camera_capture_flags;
GinjaRenderTarget *camera_render_target_singleton;

int TObjPlayer::is_inactive() { return this->model_load_flags == 0; }

// The SDK's GXPosition3f32, GXColor1u32 and GXTexCoord2f32 out of line: each
// writes its vertex attribute straight into the GX write-gather FIFO.
static void write_position(f32 x, f32 y, f32 z) {
    *(volatile f32 *)0xCC008000 = x;
    *(volatile f32 *)0xCC008000 = y;
    *(volatile f32 *)0xCC008000 = z;
}

static void write_color(s32 color) {
    *(volatile s32 *)0xCC008000 = color;
}

static void write_tex_coord(f32 s, f32 t) {
    *(volatile f32 *)0xCC008000 = s;
    *(volatile f32 *)0xCC008000 = t;
}

f32 atan_float(f32 x) {
    return atan(x);
}

void TObjPlayer::end_screen_quad() {}

// The SDK's GXSetTexCoordGen out of line: no normalisation, identity post-transform.
static void set_tex_coord_gen(GXTexCoordID dst, GXTexGenType func, GXTexGenSrc src, u32 mtx) {
    GXSetTexCoordGen2(dst, func, src, mtx, GX_FALSE, GX_PTIDENTITY);
}

u8 get_camera_capture_flags() { return camera_capture_flags; }

s32 is_capture_overlay_ready() {
    if ((camera_capture_flags & CAPTURE_OVERLAY_REQUESTED) && (camera_capture_flags & CAPTURE_VIEWPORT_CAPTURED)) {
        return 1;
    }
    return 0;
}

void disable_camera_capture_overlay() {
    camera_capture_flags &= ~CAPTURE_OVERLAY_REQUESTED;
    camera_capture_overlay_alpha = 0x8F;
}

void set_viewport_captured() { camera_capture_flags |= CAPTURE_VIEWPORT_CAPTURED; }

s32 is_screen_bw_requested() { return (camera_capture_flags >> 4) & 1; }

void clear_screen_bw_request() { camera_capture_flags &= ~CAPTURE_SCREEN_BW; }

void begin_live_view_render() { camera_capture_flags |= CAPTURE_LIVE_VIEW_RENDERING; }

void end_live_view_render() { camera_capture_flags &= ~CAPTURE_LIVE_VIEW_RENDERING; }

void init_capture_texture(s32 wide) {
    GinjaTextureInput input;
    s32 format;
    u16 width;
    u16 height;
    if (wide != 0) {
        format = GX_TF_RGBA8;
        width = 640;
        height = 480;
    } else {
        format = GX_TF_RGB565;
        width = 640;
        height = 480;
    }
    input.set_render_rect(NULL, format, width, height);
    set_texture_name(shared_capture_texture_list.textures, &input, 0x2EE0, 0x08800000);
    load_texture_list(&shared_capture_texture_list);
}

void release_capture_texture() {
    if (shared_capture_texture_list.textures->texture != NULL) {
        release_texture_list(&shared_capture_texture_list);
    }
}

void reset_movie_state() {
    camera_capture_flags = 0;
    init_capture_texture(1);
}

void reset_and_init_capture_texture() {
    camera_capture_flags = 0;
    init_capture_texture(0);
}

void reset_and_release_capture_texture() {
    camera_capture_flags = 0;
    release_capture_texture();
}

u32 *get_capture_texture_pixels() {
    return shared_capture_texture_list.textures->texture->surface->header.pixels;
}

void capture_viewport_texture() {
    if (!(camera_capture_flags & CAPTURE_LIVE_VIEW_RENDERING)) {
        GXColor clear = {0, 0, 0, 0};
        GXSetCopyClear(clear, 0xFFFFFF);
        GXSetTexCopySrc(0, 0, 640, 480);
        GXSetTexCopyDst(640, 480, GX_TF_RGB565, GX_FALSE);
        if (camera_capture_flags & CAPTURE_CLEAR_ON_COPY) {
            GXCopyTex(shared_capture_texture_list.textures->texture->surface->header.pixels, GX_TRUE);
        } else {
            GXCopyTex(shared_capture_texture_list.textures->texture->surface->header.pixels, GX_FALSE);
        }
        GXPixModeSync();
    }
}

void TObjPlayer::load_capture_texture() {
    set_texture_list(&shared_capture_texture_list);
    load_list_texture(0, 0, 0, 0);
}

void draw_textured_screen_quad(u32 argb, f32 *pos, f32 *size, s32 cropped) {
    u32 rgba;
    GinjaSurfaceState *surface;
    f32 z;
    set_texture_list(&shared_capture_texture_list);
    if (cropped != 0) {
        surface = shared_capture_texture_list.textures->texture->surface;
        surface->header.width = 256;
        surface->header.height = 192;
    }
    load_list_texture(0, 0, 0, 0);
    set_default_alpha_blend();
    load_screen_space_matrix();
    setup_blended_textured_draw();
    GXSetNumTexGens(1);
    GXSetNumChans(1);
    set_tex_coord_gen(GX_TEXCOORD0, GX_TG_MTX2x4, GX_TG_TEX0, GX_IDENTITY);
    GXSetTevOp(GX_TEVSTAGE0, GX_DECAL);
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
    GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
    GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
    GXSetVtxAttrFmt(GX_VTXFMT4, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT4, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);
    GXSetVtxAttrFmt(GX_VTXFMT4, GX_VA_TEX0, GX_TEX_ST, GX_F32, 0);
    GXBegin(GX_QUADS, GX_VTXFMT4, 4);
    z = -1.0f;
    write_position(pos[0] * z, pos[1] * z, z);
    rgba = (argb << 8) | (argb >> 24);
    write_color(rgba);
    write_tex_coord(0.0f, 0.0f);
    write_position(z * (pos[0] + size[0]), pos[1] * z, z);
    write_color(rgba);
    write_tex_coord(1.0f, 0.0f);
    write_position(z * (pos[0] + size[0]), z * (pos[1] + size[1]), z);
    write_color(rgba);
    write_tex_coord(1.0f, 1.0f);
    write_position(pos[0] * z, z * (pos[1] + size[1]), z);
    write_color(rgba);
    write_tex_coord(0.0f, 1.0f);
    TObjPlayer::end_screen_quad();
    set_default_alpha_blend();
    if (cropped != 0) {
        surface = shared_capture_texture_list.textures->texture->surface;
        surface->header.width = 640;
        surface->header.height = 480;
    }
}

void draw_screen_quad(u32 argb, s32 cropped, f32 border) {
    f32 top_left;
    f32 right;
    f32 bottom;
    f32 z;
    u32 rgba;
    GinjaSurfaceState *surface;
    set_texture_list(&shared_capture_texture_list);
    if (cropped != 0) {
        surface = shared_capture_texture_list.textures->texture->surface;
        surface->header.width = 256;
        surface->header.height = 192;
    }
    load_list_texture(0, 0, 0, 0);
    set_default_alpha_blend();
    load_screen_space_matrix();
    setup_blended_textured_draw();
    GXSetNumTexGens(1);
    GXSetNumChans(1);
    set_tex_coord_gen(GX_TEXCOORD0, GX_TG_MTX2x4, GX_TG_TEX0, GX_IDENTITY);
    GXSetTevOp(GX_TEVSTAGE0, GX_DECAL);
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
    GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
    GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
    GXSetVtxAttrFmt(GX_VTXFMT4, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT4, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);
    GXSetVtxAttrFmt(GX_VTXFMT4, GX_VA_TEX0, GX_TEX_ST, GX_F32, 0);
    GXBegin(GX_QUADS, GX_VTXFMT4, 4);
    z = -2.0f;
    top_left = -border * z;
    write_position(top_left, top_left, z);
    rgba = (argb << 8) | (argb >> 24);
    write_color(rgba);
    write_tex_coord(0.0f, 0.0f);
    right = (640.0f + border) * z;
    write_position(right, top_left, z);
    write_color(rgba);
    write_tex_coord(1.0f, 0.0f);
    bottom = (480.0f + border) * z;
    write_position(right, bottom, z);
    write_color(rgba);
    write_tex_coord(1.0f, 1.0f);
    write_position(top_left, bottom, z);
    write_color(rgba);
    write_tex_coord(0.0f, 1.0f);
    TObjPlayer::end_screen_quad();
    set_default_alpha_blend();
    if (cropped != 0) {
        surface = shared_capture_texture_list.textures->texture->surface;
        surface->header.width = 640;
        surface->header.height = 480;
    }
}

s32 is_shadow_pass_active() {
    s32 active;
    s32 client_id;
    active = 1;
    if (TObjPlayer::is_shadow_pass_requested() == 0) {
        return 0;
    }
    if (get_main_phase() == 0xF) {
        client_id = 0;
        do {
            TObjPlayer *player = get_player_by_client_id(client_id);
            if ((player != NULL) && (player->is_inactive() == 0)) {
                active = 0;
            }
            client_id += 1;
        } while (client_id < 4);
    }
    return active;
}

void TObjPlayer::clear_shadow_pass_request() { shadow_pass_requested = 0; }

void TObjPlayer::request_shadow_pass() { shadow_pass_requested = 1; }

int TObjPlayer::is_shadow_pass_requested() { return shadow_pass_requested; }

void init_shadow_map_texture() {
    GinjaTextureInput input;
    input.set_render_rect(NULL, GX_TF_IA4, 256, 256);
    set_texture_name(shadow_map_texture_list.textures, &input, 0x2EE1, 0x08800000);
    load_texture_list(&shadow_map_texture_list);
    shadow_pass_requested = 0;
}

void release_shadow_map_texture() {
    if (shadow_map_texture_list.textures->texture != NULL) {
        release_texture_list(&shadow_map_texture_list);
    }
}

#pragma push
#pragma fp_contract on
void begin_shadow_map_pass() {
    Mtx44 proj;
    Vec dir;
    f32 top;
    f32 left;
    if (is_split_screen() != 0) {
        return;
    }
    TObjPlayer::request_shadow_pass();
    if (is_shadow_pass_active() == 0) {
        return;
    }
    TCameraCtrl::restore_full_screen_view();
    if (camera_ctrl_instance == 0) {
        return;
    }
    dir.x = camera_ctrl_instance->tgt.x - camera_ctrl_instance->pos.x;
    dir.y = camera_ctrl_instance->tgt.y - camera_ctrl_instance->pos.y;
    dir.z = camera_ctrl_instance->tgt.z - camera_ctrl_instance->pos.z;
    if (0.0f != vec_squared_length(&dir)) {
        normalize_vector(&dir);
        shadow_light_position.x = camera_ctrl_instance->pos.x + 0.4f * (256.0f * dir.x);
        shadow_light_position.y = camera_ctrl_instance->pos.y;
        shadow_light_position.z = camera_ctrl_instance->pos.z + 0.4f * (256.0f * dir.z);
    } else {
        shadow_light_position.x = 0.0f;
        shadow_light_position.y = 0.0f;
        shadow_light_position.z = 0.0f;
    }
    push_matrix();
    GXSetViewport(0.0f, 0.0f, 256.0f, 256.0f, 0.0f, 1.0f);
    GXSetScissor(1, 1, 254, 254);
    top = 2.1f;
    left = -2.1f;
    C_MTXFrustum(proj, top, -top, left, -left, 500.0f, 20000.0f);
    GXSetProjection(proj, GX_PERSPECTIVE);
    set_light_ambient_color(1.0f, 1.0f, 1.0f);
    submit_light0(0, 0);
    load_gx_light_slot(0);
    push_identity_matrix_ps();
    translate_current_matrix_ps(0.0f, 0.0f, -15000.0f);
    rotate_current_matrix_x_ps(0x3800);
    translate_current_matrix_ps(-shadow_light_position.x, -shadow_light_position.y, -shadow_light_position.z);
    set_ginja_draw_flags(2);
}

s32 is_in_shadow_range(const Vec *pos, f32 radius) {
    if ((camera_ctrl_instance != NULL) && (((radius * radius) + horizontal_distance_squared(pos, &shadow_light_position)) <= 8537.761f)) {
        return 1;
    }
    return 0;
}

void end_shadow_map_pass() {
    GXRenderModeObj *mode;
    if ((is_split_screen() == 0) && (is_shadow_pass_active() != 0) && (camera_ctrl_instance != NULL)) {
        pop_matrix();
        pop_matrix();
        GXColor clear = {0, 0, 0, 0};
        GXSetCopyFilter(GX_FALSE, NULL, GX_FALSE, NULL);
        set_cull_none();
        GXSetCopyClear(clear, 0xFFFFFF);
        GXSetTexCopySrc(0, 0, 256, 256);
        GXSetTexCopyDst(256, 256, GX_TF_IA4, GX_FALSE);
        GXCopyTex(shadow_map_texture_list.textures->texture->surface->header.pixels, GX_TRUE);
        GXPixModeSync();
        mode = active_gx_render_mode;
        GXSetCopyFilter(mode->aa, mode->sample_pattern, get_display_copy_filter(), mode->vfilter);
        GXSetViewport(0.0f, 0.0f, 640.0f, 480.0f, 0.0f, 1.0f);
        GXSetScissor(0, 0, 640, 480);
        GXSetProjection(scene_projection_state.matrix, GX_PERSPECTIVE);
        set_light_ambient_color(0.3f, 0.3f, 0.3f);
        submit_light0(0, 1);
        load_gx_light_slot(0);
        set_ginja_draw_flags(0);
        TCameraCtrl::restore_saved_view();
    }
}

#pragma pop
void bind_shadow_map_texture() {
    if ((is_split_screen() == 0) && (is_shadow_pass_active() != 0)) {
        set_texture_list(&shadow_map_texture_list);
        load_list_texture(0, 0, 0, 1);
    }
}

f32 calc_camera_vertical_fov() {
    f32 fov;
    f32 cos_half;
    f32 vertical;
    s32 half;
    vertical = 11832.0f;
    if (camera_ctrl_instance != NULL) {
        fov = (f32)camera_ctrl_instance->fov;
        fov *= 0.85f;
        half = (s32)(fov / 2.0f);
        cos_half = cos_table_lookup(half);
        vertical = (f32)((s32)(10430.38043493439 * atan_float((sin_table_lookup(half) / cos_half) / 1.1333334f)) * 2);
    }
    return vertical;
}

#pragma push
#pragma opt_common_subs off


void render_projected_shadow_receiver(const f32 *pos, const s32 *ang) {
    GC_Mtx mtx;
    f32 top;
    f32 left;
    if ((is_split_screen() == 0) && (is_shadow_pass_active() != 0)) {
        push_identity_matrix_ps();
        translate_current_matrix_ps(0.0f, 0.0f, -15000.0f);
        rotate_current_matrix_x_ps(0x3800);
        translate_current_matrix_ps(-shadow_light_position.x, -shadow_light_position.y, -shadow_light_position.z);
        translate_current_matrix_ps(pos[0], pos[1], pos[2]);
        rotate_matrix_by_node_angles(ang, 1);
        top = 2.1f;
        left = -2.1f;
        C_MTXLightFrustum(mtx, -top, top, left, -left, 500.0f, 0.5f, 0.5f, 0.5f, 0.5f);
        PSMTXConcat(mtx, *current_matrix, *current_matrix);
        load_current_tex_matrix(0);
        pop_matrix();
        load_current_pos_matrix(0);
        GXSetTevOrder(GX_TEVSTAGE1, GX_TEXCOORD1, GX_TEXMAP1, GX_COLOR0A0);
        GXSetTevOp(GX_TEVSTAGE1, GX_DECAL);
        set_tex_coord_gen(GX_TEXCOORD1, GX_TG_MTX3x4, GX_TG_POS, GX_TEXMTX0);
        model_render_flags |= 0x80000;
        set_ginja_post_tev_stage_count(1);
        set_ginja_post_texgen_count(1);
    }
}
#pragma pop
void TScene::apply_single_screen_state() {
    if ((is_split_screen() == 0) && (is_shadow_pass_active() != 0)) {
        model_render_flags &= ~0x80000;
        set_ginja_post_tev_stage_count(0);
        set_ginja_post_texgen_count(0);
    }
}

void load_projection_tex_matrix(s32 rotation_y) {
    GC_Mtx mtx;
    f32 offset_x;
    f32 offset_y;
    f32 fov_y;
    if (is_split_screen() == 0) {
        calc_projection_screen_offset(&offset_x, &offset_y);
        push_matrix();
        rotate_matrix_y(NULL, rotation_y);
        fov_y = (f32)(0.0054931640625 * calc_camera_vertical_fov());
        if (TCameraCtrl::is_view_offset() != 0) {
            C_MTXLightPerspective(mtx, fov_y, 1.1333334f, 0.5f, -0.5f, (f32)(0.5f - offset_x), (f32)(0.5f - offset_y));
        } else {
            C_MTXLightPerspective(mtx, fov_y, 1.1333334f, 0.5f, -0.5f, 0.5f, 0.5f);
        }
        PSMTXConcat(mtx, *current_matrix, *current_matrix);
        load_current_tex_matrix(0);
        pop_matrix();
        load_current_pos_matrix(0);
    }
}

void load_projected_texture_matrix(f32 aspect) {
    GC_Mtx mtx;
    f32 offset_x;
    f32 offset_y;
    f32 fov_y;
    if (is_split_screen() == 0) {
        calc_projection_screen_offset(&offset_x, &offset_y);
        push_matrix();
        fov_y = (f32)(0.0054931640625 * calc_camera_vertical_fov());
        if (TCameraCtrl::is_view_offset() != 0) {
            C_MTXLightPerspective(mtx, fov_y, aspect, 0.5f, -0.5f, (f32)(0.5f - offset_x), (f32)(0.5f - offset_y));
        } else {
            C_MTXLightPerspective(mtx, fov_y, aspect, 0.5f, -0.5f, 0.5f, 0.5f);
        }
        PSMTXConcat(mtx, *current_matrix, *current_matrix);
        load_current_tex_matrix(0);
        pop_matrix();
        load_current_pos_matrix(0);
    }
}

void setup_particle_tev(s32 modulate) {
    if (is_split_screen() == 0) {
        GXSetTevOrder(GX_TEVSTAGE1, GX_TEXCOORD1, GX_TEXMAP1, GX_COLOR0A0);
        if (modulate != 0) {
            GXSetTevOp(GX_TEVSTAGE1, GX_MODULATE);
        } else {
            GXSetTevOp(GX_TEVSTAGE1, GX_DECAL);
        }
        set_tex_coord_gen(GX_TEXCOORD1, GX_TG_MTX3x4, GX_TG_POS, GX_TEXMTX0);
        set_texture_list(&shared_capture_texture_list);
        load_list_texture(0, 0, 0, 1);
        model_render_flags |= 0x80000;
        set_ginja_post_tev_stage_count(1);
        set_ginja_post_texgen_count(1);
    }
}

void setup_capture_blend_tev() {
    if (is_split_screen() == 0) {
        GXSetTevOrder(GX_TEVSTAGE1, GX_TEXCOORD1, GX_TEXMAP1, GX_COLOR0A0);
        GXSetTevOp(GX_TEVSTAGE1, GX_BLEND);
        set_tex_coord_gen(GX_TEXCOORD1, GX_TG_MTX3x4, GX_TG_POS, GX_TEXMTX0);
        set_texture_list(&shared_capture_texture_list);
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
        model_render_flags &= ~0x80000;
    }
}


TCameraCapturePass::TCameraCapturePass(TObject *parent, s32 flags) : TObject(parent) {
    this->flags = flags;
}

TCameraCapturePass::~TCameraCapturePass() {
}

void TCameraCapturePass::run_task() {}

void TCameraCapturePass::render_shadows() {
    if (is_screen_bw_requested() != 0) {
        set_tev_swap_mode(0);
    }
}

void TCameraCapturePass::render() {
    if (!(get_camera_capture_flags() & CAPTURE_LIVE_VIEW_RENDERING)) {
        if (flags & 1) {
            if (is_capture_overlay_ready() == 1) {
                TCameraCtrl::restore_full_screen_view();
                TParticleCtrl::begin_effect_render();
                draw_screen_quad(camera_capture_overlay_alpha << 24, 0, 0.0f);
                TParticleCtrl::end_effect_render();
                TCameraCtrl::restore_saved_view();
                disable_camera_capture_overlay();
            }
        } else {
            set_viewport_captured();
            capture_viewport_texture();
        }
        if (is_screen_bw_requested() != 0) {
            clear_screen_bw_request();
            init_tev_swap();
        }
    }
}

void init_camera_render_target() {
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

void free_camera_render_target() {
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
        GXSetScissor(0, 0, 640, 480);
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
        begin_live_view_render();
        main_task.render_scene_passes();
        end_live_view_render();
        if (camera_render_target_singleton != NULL) {
            GXColor clear = {0, 0, 0, 0};
            GXSetCopyClear(clear, 0xFFFFFF);
            GXSetZMode(GX_TRUE, GX_ALWAYS, GX_TRUE);
            GXSetTexCopySrc(0, 0, 640, 480);
            GXSetTexCopyDst(640, 480, GX_TF_RGB565, GX_FALSE);
            GXCopyTex(camera_render_target_singleton->texture_list.textures->texture->surface->header.pixels, GX_TRUE);
            GXPixModeSync();
        }
        GXSetViewport(0.0f, 0.0f, 640.0f, 480.0f, 0.0f, 1.0f);
        GXSetScissor(0, 0, 640, 480);
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
        set_texture_list(&camera_render_target_singleton->texture_list);
        load_list_texture(0, 0, 0, 0);
    }
}

void TLiveCameraView::set_view(const Vec *eye, const Vec *target) {
    VecCopy(&this->eye, eye);
    VecCopy(&this->target, target);
}

void calc_projection_screen_offset(f32 *x, f32 *y) {
    f32 dx = TCameraCtrl::view_params.screen.projection.center_x;
    f32 center_y = TCameraCtrl::view_params.screen.projection.center_y;
    f32 dy;
    dx -= 320.0f;
    dy = center_y - 240.0f;
    *x = (-0.12f * dx) / 80.0f;
    *y = (0.235f * dy) / -112.0f;
}

void copy_screen_to_texture(s32 mode, NJS_POINT2 *center) {
    f32 pos[2];
    f32 size[2];
    NJS_POINT2 corner;
    ControllerInputContext *pad;
    GXColor clear = {0, 0, 0, 0};
    GXSetCopyClear(clear, 0xFFFFFF);
    switch (mode) {
    case 0:
        if (center != NULL) {
            copy_vec2(&corner, center);
            corner.x -= 128.0f;
            corner.y -= 96.0f;
        } else {
            corner.x = 192.0f;
            corner.y = 144.0f;
        }
        GXSetTexCopySrc(corner.x, corner.y, 256, 192);
        GXSetTexCopyDst(256, 192, GX_TF_RGB565, GX_FALSE);
        GXCopyTex(shared_capture_texture_list.textures->texture->surface->header.pixels, GX_TRUE);
        GXPixModeSync();
        pad = &controller_physical_port_bank.controllers[3];
        pos[0] = 192.0f;
        pos[1] = 144.0f;
        size[0] = 256.0f;
        size[1] = 192.0f;
        if (test_previous_buttons_packed(pad, 0x100) != 0) {
            set_tev_swap_mode(0);
        }
        draw_textured_screen_quad(0xFFFFFFFF, pos, size, 1);
        if (test_previous_buttons_packed(pad, 0x100) != 0) {
            init_tev_swap();
        }
        TObjPlayer::draw_capture_caption_bar();
        GXSetTexCopySrc(192, 144, 256, 192);
        GXSetTexCopyDst(256, 192, GX_TF_RGB565, GX_FALSE);
        GXCopyTex(shared_capture_texture_list.textures->texture->surface->header.pixels, GX_TRUE);
        GXPixModeSync();
        break;
    case 1:
        GXColor full_clear = {0, 0, 0, 0};
        GXSetCopyClear(full_clear, 0xFFFFFF);
        GXSetTexCopySrc(0, 0, 640, 480);
        GXSetTexCopyDst(640, 480, GX_TF_RGB565, GX_FALSE);
        GXCopyTex(shared_capture_texture_list.textures->texture->surface->header.pixels, GX_TRUE);
        GXPixModeSync();
        pad = &controller_physical_port_bank.controllers[3];
        pos[0] = 192.0f;
        pos[1] = 144.0f;
        size[0] = 256.0f;
        size[1] = 192.0f;
        if (test_previous_buttons_packed(pad, 0x100) != 0) {
            set_tev_swap_mode(0);
        }
        draw_textured_screen_quad(0xFFFFFFFF, pos, size, 0);
        if (test_previous_buttons_packed(pad, 0x100) != 0) {
            init_tev_swap();
        }
        TObjPlayer::draw_capture_caption_bar();
        GXSetTexCopySrc(192, 144, 256, 192);
        GXSetTexCopyDst(256, 192, GX_TF_RGB565, GX_FALSE);
        GXCopyTex(shared_capture_texture_list.textures->texture->surface->header.pixels, GX_TRUE);
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
    QuadSpriteRect rect;
    f32 y;
    f32 x;
    set_texture_list(hud_texlist);
    set_draw_texture_and_color(0, -1);
    begin_screen_draw(1);
    x = 192.0f;
    y = 315.0f;
    rect.x0 = x;
    rect.y0 = y;
    rect.x1 = x + 256.0f;
    rect.y1 = y + 19.0f;
    rect.u0 = 0.0f;
    rect.v0 = 0.9254902f;
    rect.u1 = 1.0f;
    rect.v1 = 1.0f;
    draw_textured_quad_at_depth(&rect.x0, 0.5f);
    end_screen_draw();
}

#pragma pop
