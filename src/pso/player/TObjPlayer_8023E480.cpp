#include "pso/render/GvmTextureArchive.h"
#include "pso/render/GinjaTexture.h"
#include "pso/system/Adxf.h"
#include "pso/system/ResourceFile.h"
#include "types.h"
#include <string.h>
#include <stdio.h>
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/unk/text_800F7DAC.h"
#include "pso/unk/TLobby.h"
#include "pso/player/TObjPlayer.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/system/scene/TScene.h"
#include "pso/unk/text_803DD5E0.h"
#include "pso/system/memory.h"

#pragma readonly_strings on

extern "C" {
char texture_prs_disc_filename_buffer[128];
char texture_prs_stream_filename_buffer[128];
NJS_TEXNAME *lbl_805D63C0;
s32 lbl_805D63C4;

}

s32 set_texlist(NJS_TEXLIST *texlist) {
    if (texlist == NULL) {
        return 0;
    }
    TObjFish::set_global_param(texlist);
    return 1;
}


s32 load_streamed_prs_texture(saddr name, saddr texlist) {
    saddr h;
    saddr buf;
    sprintf(texture_prs_stream_filename_buffer, "%s.prs", name);
    h = (saddr)load_disc_file(texture_prs_stream_filename_buffer);
    if (h == 0) {
        safe_free(reinterpret_cast<void *>(h));
        return 0;
    }
    buf = (saddr)TQuestVmDownLoadServer::alloc(0x100000);
    prs_decompress_buffer(h, buf);
    load_gvm_texture_archive((void *)buf, (NJS_TEXLIST *)texlist);
    safe_free(reinterpret_cast<void *>(buf));
    safe_free(reinterpret_cast<void *>(h));
    return 1;
}

s32 load_disc_prs_texture(saddr name, saddr texlist) {
    AdxfHandle *file;
    saddr b;
    saddr c;
    sprintf(texture_prs_disc_filename_buffer, "%s.prs", name);
    if (get_resource_file_size(texture_prs_disc_filename_buffer) != -1) {
        file = ADXF_Open(texture_prs_disc_filename_buffer, 0);
        b = ADXF_GetFsizeSct(file);
        ADXF_Close(file);
        b = (saddr)xmalloc((s32)(b << 11));
        if (read_disc_file(texture_prs_disc_filename_buffer, (void *)b) != -1) {
            c = (saddr)xmalloc(0x200000);
            prs_decompress_buffer(b, c);
            load_gvm_texture_archive((void *)c, (NJS_TEXLIST *)texlist);
            xfree((void *)c);
        }
        xfree((void *)b);
        return 1;
    }
    return 0;
}

s32 bind_gvm_texture_list(const char *name, NJS_TEXLIST *texlist) {
    NJS_TEXLIST temporary_texture_list;
    NJS_TEXNAME *d;
    s32 i;
    s32 n;
    if (name == NULL || texlist == NULL) {
        return 0;
    }
    memset(lbl_805D63C0, 0, 0x1800);
    TObjPlayer__sub_803DD5E8(&temporary_texture_list, lbl_805D63C0, lbl_805D63C4, 0x200);
    if (TLobby::load_texture_pvm_file(name, &temporary_texture_list) == -1) {
        return 0;
    }
    n = texlist->nbTexture;
    d = texlist->textures;
    for (i = 0; i < n; i++) {
        d[i].texture = lbl_805D63C0[i].texture;
        d[i].attr = lbl_805D63C0[i].attr;
    }
    return 1;
}

s32 free_texture_if_valid(NJS_TEXLIST *texlist) {
    if (texlist == NULL) {
        return 0;
    }
    release_texture_list(texlist);
    return 1;
}

s32 load_texture_if_valid(NJS_TEXLIST *texlist) {
    if (texlist == NULL) {
        return 0;
    }
    load_texture_list(texlist);
    return 1;
}

void init_buffers(void) {
    NJS_TEXNAME *entries = static_cast<NJS_TEXNAME *>(xmalloc(0x1800));
    lbl_805D63C0 = entries;
    memset(entries, 0, 0x1800);
    lbl_805D63C4 = (saddr)xmalloc(0x3800);
}

