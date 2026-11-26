#include "pso/render/psoLoadTexture.h"
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

    this->phase = (this->phase + 1);
    cursor = this->phase;
    width = this->width;
    if (cursor >= width) {
        this->phase = (s32) (cursor - width);
    }
}

TTextureWave::~TTextureWave() {
    release_texture_list(reinterpret_cast<NJS_TEXLIST *>(this->texture_list));
    safe_free(reinterpret_cast<void *>(this->output));
}

void TTextureWave::init_image_buffer(u8 *image, s32 displacement) {
    u8 *base = (u8 *)this;
    u8 *header;

    this->image_data = image;
    this->displacement = displacement;
    this->width = (s32) *(u16 *)((s8 *)this->image_data + 0x1C);
    this->height = (s32) *(u16 *)((s8 *)this->image_data + 0x1E);
    header = this->image_data;
    this->texture_id = (s32) *(u16 *)((s8 *)header + 8);
    this->texture_id = (s32) (this->texture_id | (*(u16 *)((s8 *)header + 0xA) << 0x10));
    this->output = (saddr)TQuestVmDownLoadServer::alloc((this->height * (this->width * 2)) + 0x20);
    *(void **)((s8 *)(*(void * *)&this->texture_list) + 0) = ((u8 *)&this->records);
    *(s32 *)((s8 *)(*(void * *)&this->texture_list) + 4) = 1;
    reinterpret_cast<GinjaTextureInput *>(base + 0x18)->set_render_rect(reinterpret_cast<void *>(this->output + 0x20), 5, (int) this->width, (int) this->height);
    set_texture_name(reinterpret_cast<NJS_TEXNAME *>(&this->records),
        reinterpret_cast<GinjaTextureInput *>(base + 0x18), this->texture_id, 0x40800000);
    psoLoadTexture(*(NJS_TEXLIST **)&this->texture_list);
}


TTextureWave::TTextureWave(NJS_TEXLIST *list) {
    phase = 0;
    image_data = 0;
    output = 0;
    displacement = 0;
    height = 0;
    width = 0;
    texture_list = (saddr)list;
}
