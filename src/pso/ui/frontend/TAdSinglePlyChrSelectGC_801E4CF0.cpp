#include "pso/render/GinjaTextureInput.h"
#include "types.h"
#include "pso/system/memory.h"
#include "pso/network/TLobby.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/TTextureWave.h"
#include "pso/render/GinjaTexture.h"



void TTextureWave::advance_wrapped_cursor() {
    s32 cursor;
    s32 width;

    this->m_4c = (this->m_4c + 1);
    cursor = this->m_4c;
    width = this->m_4;
    if (cursor >= width) {
        this->m_4c = (s32) (cursor - width);
    }
}

TTextureWave::~TTextureWave() {
    release_texture_list(reinterpret_cast<NJS_TEXLIST *>(this->m_3c));
    safe_free(reinterpret_cast<void *>(this->m_44));
}

void TTextureWave::init_image_buffer(u8 *image, s32 size) {
    u8 *base = (u8 *)this;
    u8 *header;

    this->m_40 = image;
    this->m_48 = size;
    this->m_4 = (s32) *(u16 *)((s8 *)this->m_40 + 0x1C);
    this->m_0 = (s32) *(u16 *)((s8 *)this->m_40 + 0x1E);
    header = this->m_40;
    this->m_8 = (s32) *(u16 *)((s8 *)header + 8);
    this->m_8 = (s32) (this->m_8 | (*(u16 *)((s8 *)header + 0xA) << 0x10));
    this->m_44 = (saddr)TQuestVmDownLoadServer::alloc((this->m_0 * (this->m_4 * 2)) + 0x20);
    *(void **)((s8 *)(*(void * *)&this->m_3c) + 0) = ((u8 *)&this->m_c);
    *(s32 *)((s8 *)(*(void * *)&this->m_3c) + 4) = 1;
    reinterpret_cast<GinjaTextureInput *>(base + 0x18)->set_render_rect(reinterpret_cast<void *>(this->m_44 + 0x20), 5, (int) this->m_4, (int) this->m_0);
    set_texture_name(reinterpret_cast<NJS_TEXNAME *>(&this->m_c),
        reinterpret_cast<GinjaTextureInput *>(base + 0x18), this->m_8, 0x40800000);
    psoLoadTexture(*(NJS_TEXLIST **)&this->m_3c);
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
