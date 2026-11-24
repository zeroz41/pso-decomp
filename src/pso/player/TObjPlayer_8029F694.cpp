#include "pso/render/GinjaRenderTarget.h"
#include "pso/render/GinjaTexture.h"
#include "pso/render/GinjaTextureInput.h"
#include "pso/unk/text_803DD5E0.h"

void GinjaRenderTarget::release_texture() {
    load_result = 0;
    release_texture_list(&texture_list);
}

void GinjaRenderTarget::init_render_target() {
    GinjaTextureInput input;
    texture_list.textures = &texture_entry;
    texture_list.nbTexture = 1;
    input.set_render_rect(NULL, 4, 0x280, 0x1E0);
    set_texture_name(texture_list.textures, &input, 0x901, 0x08800000);
    load_result = load_texture_list(&texture_list);
}
