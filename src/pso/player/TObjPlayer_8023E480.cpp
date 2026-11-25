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
#include "pso/network/TLobby.h"
#include "pso/player/TObjPlayer.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/system/scene/TScene.h"
#include "pso/unk/text_803DD5E0.h"
#include "pso/system/memory.h"

#pragma readonly_strings on

char texture_prs_disc_filename_buffer[128];
char texture_prs_stream_filename_buffer[128];
// The texture entries and the 28-byte name slots bind_gvm_texture_list loads a PVM through (512 of each,
// allocated by init_buffers).
NJS_TEXNAME *temporary_texture_entries;
s32 temporary_texture_names;

s32 set_texlist(NJS_TEXLIST *texlist) {
    if (texlist == NULL) {
        return 0;
    }
    TObjFish::set_global_param(texlist);
    return 1;
}


s32 load_streamed_prs_texture(saddr name, saddr texlist) {
    void *h;
    void *buf;
    sprintf(texture_prs_stream_filename_buffer, "%s.prs", name);
    h = load_disc_file(texture_prs_stream_filename_buffer);
    if (h == NULL) {
        safe_free(h);
        return 0;
    }
    buf = TQuestVmDownLoadServer::alloc(0x100000);
    prs_decompress_buffer(h, buf);
    load_gvm_texture_archive(buf, (NJS_TEXLIST *)texlist);
    safe_free(buf);
    safe_free(h);
    return 1;
}

s32 load_disc_prs_texture(saddr name, saddr texlist) {
    AdxfHandle *file;
    s32 sectors;
    void *c;
    void *b;
    sprintf(texture_prs_disc_filename_buffer, "%s.prs", name);
    if (get_resource_file_size(texture_prs_disc_filename_buffer) != -1) {
        file = ADXF_Open(texture_prs_disc_filename_buffer, 0);
        sectors = ADXF_GetFsizeSct(file);
        ADXF_Close(file);
        b = xmalloc(sectors << 11);
        if (read_disc_file(texture_prs_disc_filename_buffer, b) != -1) {
            c = xmalloc(0x200000);
            prs_decompress_buffer(b, c);
            load_gvm_texture_archive(c, (NJS_TEXLIST *)texlist);
            xfree(c);
        }
        xfree(b);
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
    memset(temporary_texture_entries, 0, 0x1800);
    bind_texture_name_table(&temporary_texture_list, temporary_texture_entries, temporary_texture_names, 0x200);
    if (psoLoadTexturePvmFile(name, &temporary_texture_list) == -1) {
        return 0;
    }
    n = texlist->nbTexture;
    d = texlist->textures;
    for (i = 0; i < n; i++) {
        d[i].texture = temporary_texture_entries[i].texture;
        d[i].attr = temporary_texture_entries[i].attr;
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
    temporary_texture_entries = entries;
    memset(entries, 0, 0x1800);
    temporary_texture_names = (saddr)xmalloc(0x3800);
}

