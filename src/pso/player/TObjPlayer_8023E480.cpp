#include "pso/render/GvmTextureArchive.h"
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
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/memory.h"

#pragma readonly_strings on

extern "C" {
char texture_prs_disc_filename_buffer[128];
char texture_prs_stream_filename_buffer[128];
saddr lbl_805D63C0;
s32 lbl_805D63C4;
extern char texture_prs_stream_filename_buffer[];
extern char texture_prs_disc_filename_buffer[];
extern saddr lbl_805D63C0;
extern s32 lbl_805D63C4;
int release_texture_list();
s32 load_texture_list();

}

s32 set_texlist(u32 texlist) {
    if (texlist == 0U) {
        return 0;
    }
    TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(texlist));
    return 1;
}


s32 load_streamed_prs_texture(saddr name, saddr texlist) {
    saddr h;
    saddr buf;
    sprintf(texture_prs_stream_filename_buffer, "%s.prs", name);
    h = (saddr)load_disc_file(texture_prs_stream_filename_buffer);
    if (h == 0) {
        TAdSinglePlyChrSelectGC::safe_free(h);
        return 0;
    }
    buf = (saddr)TQuestVmDownLoadServer::alloc(0x100000);
    prs_decompress_buffer(h, buf);
    load_gvm_texture_archive((void *)buf, (NJS_TEXLIST *)texlist);
    TAdSinglePlyChrSelectGC::safe_free(buf);
    TAdSinglePlyChrSelectGC::safe_free(h);
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
    u8 m_texture_list[8];
    NJS_TEXNAME *d;
    s32 i;
    s32 n;
    if (name == NULL || texlist == NULL) {
        return 0;
    }
    memset((void *)lbl_805D63C0, 0, 0x1800);
    TObjPlayer__sub_803DD5E8((NJS_TEXLIST *)m_texture_list, (NJS_TEXNAME *)lbl_805D63C0, lbl_805D63C4, 0x200);
    if (TLobby::load_texture_pvm_file(name, (saddr)m_texture_list) == -1) {
        return 0;
    }
    n = texlist->nbTexture;
    d = texlist->textures;
    for (i = 0; i < n; i++) {
        d[i].texture = ((NJS_TEXNAME *)lbl_805D63C0)[i].texture;
        d[i].attr = ((NJS_TEXNAME *)lbl_805D63C0)[i].attr;
    }
    return 1;
}

s32 free_texture_if_valid(u32 texlist) {
    if (texlist == 0U) {
        return 0;
    }
    release_texture_list();
    return 1;
}

s32 load_texture_if_valid(uaddr arg0) {
    if (arg0 == 0U) {
        return 0;
    }
    load_texture_list();
    return 1;
}

void init_buffers(void) {
    saddr p = (saddr)xmalloc(0x1800);
    lbl_805D63C0 = p;
    memset((void *)p, 0, 0x1800);
    lbl_805D63C4 = (saddr)xmalloc(0x3800);
}

