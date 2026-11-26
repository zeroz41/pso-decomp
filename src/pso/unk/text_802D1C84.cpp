#include "types.h"
#include "pso/network/TLobby.h"
#include "pso/render/GinjaTexture.h"
#include "pso/render/GinjaTextureInput.h"
#include "pso/system/memory.h"
#include "pso/unk/text_802D1C84.h"

// Mericarol's 32x32 render target, registered as texture 0x18696.
void *mericarol_render_texture_buffer;
GinjaTextureInput mericarol_render_target;
NJS_TEXNAME mericarol_render_texture_name;
__declspec(section ".data") NJS_TEXLIST mericarol_render_texlist[1];

void release_mericarol_render_texture(void) {
    NJS_TEXLIST *texlist = mericarol_render_texlist;
    if (texlist != NULL) {
        release_texture_list(texlist);
    }
    if (mericarol_render_texture_buffer != NULL) {
        mem_free(mericarol_render_texture_buffer);
        mericarol_render_texture_buffer = NULL;
    }
}

void create_mericarol_render_texture(void) {
    mericarol_render_target.set_render_rect(mericarol_render_texture_buffer = mem_alloc(0x800), 0x902, 0x20, 0x20);
    set_texture_name(&mericarol_render_texture_name, &mericarol_render_target, 0x18696, 0x40800000);
    mericarol_render_texlist[0].textures = &mericarol_render_texture_name;
    mericarol_render_texlist[0].nbTexture = 1;
    psoLoadTexture(mericarol_render_texlist);
}
