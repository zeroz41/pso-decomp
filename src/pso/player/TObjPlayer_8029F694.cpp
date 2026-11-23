#include "pso/render/GinjaTextureInput.h"
#include "types.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

s32 release_texture_list(void *);
s32 load_texture_list(void *);

void TObjPlayer::reset_lobby_subobject() {
    this->texlist = 0;
    release_texture_list((u8 *)&this->entity_id);
}

void TObjPlayer::init_render_target() {
    u8 *arg0 = (u8 *)this;
    s32 input[12];

    *(s32 *)((s8 *)arg0 + 0x1C) = (saddr)(arg0 + 0x10);
    (this->m_20) = 1;
    reinterpret_cast<GinjaTextureInput *>(input)->set_render_rect(NULL, 4, 0x280, 0x1E0);
    set_texture_name(*reinterpret_cast<GinjaTextureEntry **>(arg0 + 0x1C),
        reinterpret_cast<GinjaTextureInput *>(input), 0x901, 0x08800000);
    this->texlist = load_texture_list((u8 *)&this->entity_id);
}

}
