#include "pso/render/GinjaTextureInput.h"
#include "types.h"
#include "pso/system/memory.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/TTextureWave.h"

extern "C" {

s32 release_texture_list(s32);

void TTextureWave::advance_wrapped_cursor() {
    s32 temp_r0;
    s32 temp_r4;

    this->m_4c = (this->m_4c + 1);
    temp_r0 = this->m_4c;
    temp_r4 = this->m_4;
    if (temp_r0 >= temp_r4) {
        this->m_4c = (s32) (temp_r0 - temp_r4);
    }
}

TTextureWave::~TTextureWave() {
    release_texture_list(this->m_3c);
    safe_free(reinterpret_cast<void *>(this->m_44));
}

void TTextureWave::init_image_buffer(u8 *arg1, s32 arg2) {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r3;

    this->m_40 = arg1;
    this->m_48 = arg2;
    this->m_4 = (s32) *(u16 *)((s8 *)this->m_40 + 0x1C);
    this->m_0 = (s32) *(u16 *)((s8 *)this->m_40 + 0x1E);
    temp_r3 = this->m_40;
    this->m_8 = (s32) *(u16 *)((s8 *)temp_r3 + 8);
    this->m_8 = (s32) (this->m_8 | (*(u16 *)((s8 *)temp_r3 + 0xA) << 0x10));
    this->m_44 = (saddr)TQuestVmDownLoadServer::alloc((this->m_0 * (this->m_4 * 2)) + 0x20);
    *(void **)((s8 *)(*(void * *)&this->m_3c) + 0) = ((u8 *)&this->m_c);
    *(s32 *)((s8 *)(*(void * *)&this->m_3c) + 4) = 1;
    reinterpret_cast<GinjaTextureInput *>(arg0 + 0x18)->set_render_rect(reinterpret_cast<void *>(this->m_44 + 0x20), 5, (int) this->m_4, (int) this->m_0);
    set_texture_name(reinterpret_cast<NJS_TEXNAME *>(&this->m_c),
        reinterpret_cast<GinjaTextureInput *>(arg0 + 0x18), this->m_8, 0x40800000);
    pso_load_texture(*(NJS_TEXLIST **)&this->m_3c);
}

}

TTextureWave::TTextureWave(NJS_TEXLIST *texture_list) {
    m_4c = 0;
    m_40 = 0;
    m_44 = 0;
    m_48 = 0;
    m_0 = 0;
    m_4 = 0;
    m_3c = (saddr)texture_list;
}
