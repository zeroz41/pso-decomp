#include "types.h"
#include "pso/render/GinjaMaterialState.h"
#include "pso/render/GinjaTextureHeader.h"
#include "pso/render/RenderSbssGlobals.h"
#include "pso/system/TLanguage.h"

void set_texture_palette_bank(GinjaTextureState *texture, s32 bank) {
    texture->tlut_name = bank;
}

// Callers outside render reach this as a TLanguage member (font and HUD palettes).
#pragma push
#pragma scheduling off
#pragma peephole off
void TLanguage::set_entry_index(s32 index, s32 bank) {
    set_texture_palette_bank(current_render_context->textures->textures[index].texture, bank);
}
#pragma pop
