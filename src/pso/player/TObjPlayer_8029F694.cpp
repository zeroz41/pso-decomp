#include "types.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

s32 release_texture_list(void *);
s32 set_texture_name(s32, s32 *, s32, s32);
s32 load_texture_list(void *);

void TObjPlayer::reset_lobby_subobject() {
    this->texture_id = 0;
    release_texture_list((u8 *)&this->entity_id);
}

void TObjPlayer::init_render_target() {
    u8 *arg0 = (u8 *)this;
    s32 sp8[12];

    *(s32 *)((s8 *)arg0 + 0x1C) = (s32)(arg0 + 0x10);
    (*(s32 *)&this->m_20) = 1;
    ((TObjPlayer *)sp8)->set_render_rect(0, 4, 0x280, 0x1E0);
    set_texture_name(*(s32 *)((s8 *)arg0 + 0x1C), sp8, 0x901, 0x08800000);
    *(s32 *)&this->texture_id = load_texture_list((u8 *)&this->entity_id);
}

}
