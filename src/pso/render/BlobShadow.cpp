#include "pso/system/memory.h"
#include <stddef.h>
#include "types.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/render/BlobShadow.h"
#include "pso/player/TObjPlayer_800F0810.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/render/render_util.h"
#include "pso/player/TObjPlayer.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/render/GinjaTexture.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/unk/TLobby_801E2F94.h"

#pragma readonly_strings on

NJS_TEXANIM blob_shadow_rect_desc = {5, 5, 0, 0, 5, 5, 253, 253, 0, 0};
NJS_TEXLIST *blob_shadow_texture_list;

void draw_blob_shadow(s32 forceDraw) {
    NJS_SPRITE sprite;
    if (forceDraw != 0 || is_split_screen__10TObjPlayerFv() != 0) {
        sprite.p.x = -4.9910388f;
        sprite.p.y = 0.0f;
        sprite.p.z = 0.0f;
        sprite.sx = 1.0f;
        sprite.sy = 1.0f;
        sprite.ang = 0;
        sprite.tlist = blob_shadow_texture_list;
        sprite.tanim = &blob_shadow_rect_desc;
        set_depth_buffer_settings_1();
        set_color_blending_mode(0, 8);
        set_color_blending_mode(1, 6);
        TParticleCtrl::begin_effect_render();
        draw_shadow_quad(&sprite, 0, 0x20);
        sprite.p.x = 0.0f;
        sprite.p.y = 0.0f;
        draw_shadow_quad(&sprite, 0, 0x24);
        sprite.p.x = -4.9910388f;
        sprite.p.y = -4.9910388f;
        draw_shadow_quad(&sprite, 0, 0x28);
        sprite.p.x = 0.0f;
        sprite.p.y = -4.9910388f;
        draw_shadow_quad(&sprite, 0, 0x2C);
        TParticleCtrl::end_effect_render();
        restore_saved_depth_alpha_state();
    }
}

void release_blob_shadow_texture(void) {
    if (blob_shadow_texture_list != NULL) {
        release_texture_list(blob_shadow_texture_list);
        safe_free(blob_shadow_texture_list);
        blob_shadow_texture_list = NULL;
    }
}

void load_ha_u032_kage(void) { blob_shadow_texture_list = load_gvm_texture_file("ha_u032_kage.gvm"); }
