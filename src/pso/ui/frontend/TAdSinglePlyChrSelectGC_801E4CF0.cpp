#include "types.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801E4CF0.h"
#include "pso/system/memory.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/text_801E4E4C.h"
#include "pso/unk/TUnk_804C57E0.h"

extern "C" {

s32 release_texture_list(s32);
s32 set_texture_name(void *, void *, int, int);

void TUnk_804C57E0::advance_wrapped_cursor() {
    s32 temp_r0;
    s32 temp_r4;

    this->m_4c = (this->m_4c + 1);
    temp_r0 = this->m_4c;
    temp_r4 = this->m_4;
    if (temp_r0 >= temp_r4) {
        this->m_4c = (s32) (temp_r0 - temp_r4);
    }
}

extern s32 __vt__13TUnk_804C57E0[];

TUnk_804C57E0::~TUnk_804C57E0() {
    release_texture_list(this->m_3c);
    TAdSinglePlyChrSelectGC::safe_free(this->m_44);
}

void TUnk_804C57E0::init_image_buffer(u8 *arg1, s32 arg2) {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r3;

    this->m_40 = arg1;
    this->m_48 = arg2;
    this->m_4 = (s32) *(u16 *)((s8 *)this->m_40 + 0x1C);
    this->m_0 = (s32) *(u16 *)((s8 *)this->m_40 + 0x1E);
    temp_r3 = this->m_40;
    this->m_8 = (s32) *(u16 *)((s8 *)temp_r3 + 8);
    this->m_8 = (s32) (this->m_8 | (*(u16 *)((s8 *)temp_r3 + 0xA) << 0x10));
    this->m_44 = (s32)TQuestVmDownLoadServer::alloc((this->m_0 * (this->m_4 * 2)) + 0x20);
    *(void **)((s8 *)(*(void * *)&this->m_3c) + 0) = ((u8 *)&this->m_c);
    *(s32 *)((s8 *)(*(void * *)&this->m_3c) + 4) = 1;
    ((TObjPlayer *)(arg0 + 0x18))->set_render_rect(this->m_44 + 0x20, 5, (int) this->m_4, (int) this->m_0);
    set_texture_name((u8 *)&this->m_c, arg0 + 0x18, (int) this->m_8, 0x40800000);
    ((TLobby *)(*(void * *)&this->m_3c))->pso_load_texture();
}

}

void construct_texture_wave(u8 *arg0, s32 arg1) {
    *(s32 **)((s8 *)arg0 + 0x50) = __vt__13TUnk_804C57E0;
    *(s32 *)((s8 *)arg0 + 0x4C) = 0;
    *(s32 *)((s8 *)arg0 + 0x40) = 0;
    *(s32 *)((s8 *)arg0 + 0x44) = 0;
    *(s32 *)((s8 *)arg0 + 0x48) = 0;
    *(s32 *)((s8 *)arg0 + 0) = 0;
    *(s32 *)((s8 *)arg0 + 4) = 0;
    *(s32 *)((s8 *)arg0 + 0x3C) = arg1;
}
