#include "pso/render/GinjaTextureInput.h"
#include "types.h"
#include "pso/system/memory.h"
#include "pso/network/TLobby.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/TTextureWave.h"
#include "pso/render/GinjaTexture.h"
#include "pso/render/psoLoadTexture.h"


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
    release_texture_list(this->texture_list);
    safe_free(this->output);
}

void TTextureWave::init_image_buffer(u8 *image, s32 displacement) {
    GvrTexture *header;

    this->image_data = (GvrTexture *)image;
    this->displacement = displacement;
    this->width = (s32)this->image_data->width;
    this->height = (s32)this->image_data->height;
    header = this->image_data;
    this->texture_id = (s32)header->global_index[0];
    this->texture_id = (s32)(this->texture_id | (header->global_index[1] << 0x10));
    this->output = (GvrTexture *)alloc((this->height * (this->width * 2)) + 0x20);
    this->texture_list->textures = &this->texture_name;
    this->texture_list->nbTexture = 1;
    this->texture_input.set_render_rect(this->output->texels, 5, (int)this->width, (int)this->height);
    set_texture_name(&this->texture_name, &this->texture_input, this->texture_id, 0x40800000);
    psoLoadTexture(this->texture_list);
}


TTextureWave::TTextureWave(NJS_TEXLIST *list) {
    phase = 0;
    image_data = 0;
    output = 0;
    displacement = 0;
    height = 0;
    width = 0;
    texture_list = list;
}
