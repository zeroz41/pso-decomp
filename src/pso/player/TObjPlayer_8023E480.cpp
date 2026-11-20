#include "pso/system/ResourceFile.h"
#include "types.h"
#include <string.h>
#include <stdio.h>
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
s32 lbl_805D63C0;
s32 lbl_805D63C4;
void load_gvm_texture_archive(s32, s32);
extern char texture_prs_stream_filename_buffer[];
s32 adxf_get_fsize_sct();
s32 adxf_open__6TLobbyFUii(void *, s32);
s32 xmalloc__FUl(s32);
void xfree__FPv(s32);
extern char texture_prs_disc_filename_buffer[];
void TObjPlayer__sub_803DD5E8(void *, s32, s32, s32);
extern s32 lbl_805D63C0;
extern s32 lbl_805D63C4;
int release_texture_list();
s32 load_texture_list();
int set_global_param__8TObjFishFl();

}

s32 set_texlist(u32 texlist) {
    if (texlist == 0U) {
        return 0;
    }
    set_global_param__8TObjFishFl();
    return 1;
}


s32 load_streamed_prs_texture(s32 arg0, s32 arg1) {
    s32 h;
    s32 buf;
    sprintf(texture_prs_stream_filename_buffer, "%s.prs", arg0);
    h = (s32)load_disc_file(texture_prs_stream_filename_buffer);
    if (h == 0) {
        TAdSinglePlyChrSelectGC::safe_free(h);
        return 0;
    }
    buf = (s32)TQuestVmDownLoadServer::alloc(0x100000);
    prs_decompress_buffer(h, buf);
    load_gvm_texture_archive(buf, arg1);
    TAdSinglePlyChrSelectGC::safe_free(buf);
    TAdSinglePlyChrSelectGC::safe_free(h);
    return 1;
}

s32 load_disc_prs_texture(s32 arg0, s32 arg1) {
    saddr a;
    s32 b;
    s32 c;
    sprintf(texture_prs_disc_filename_buffer, "%s.prs", arg0);
    if (get_resource_file_size(texture_prs_disc_filename_buffer) != -1) {
        a = adxf_open__6TLobbyFUii(texture_prs_disc_filename_buffer, 0);
        b = adxf_get_fsize_sct();
        ((TLobby *)a)->close_adxf_handle();
        b = (s32)xmalloc((s32)(b << 11));
        if (read_disc_file(texture_prs_disc_filename_buffer, (void *)b) != -1) {
            c = (s32)xmalloc(0x200000);
            prs_decompress_buffer(b, c);
            load_gvm_texture_archive(c, arg1);
            xfree((void *)c);
        }
        xfree((void *)b);
        return 1;
    }
    return 0;
}

s32 bind_gvm_texture_list(const char *name, GinjaTextureList *texlist) {
    u8 m_texture_list[8];
    GinjaTextureEntry *d;
    s32 i;
    s32 n;
    if (name == NULL || texlist == NULL) {
        return 0;
    }
    memset((void *)lbl_805D63C0, 0, 0x1800);
    TObjPlayer__sub_803DD5E8(m_texture_list, lbl_805D63C0, lbl_805D63C4, 0x200);
    if (TLobby::load_texture_pvm_file(name, (s32)m_texture_list) == -1) {
        return 0;
    }
    n = texlist->count;
    d = texlist->entries;
    for (i = 0; i < n; i++) {
        d[i].texture = ((GinjaTextureEntry *)lbl_805D63C0)[i].texture;
        d[i].value04 = ((GinjaTextureEntry *)lbl_805D63C0)[i].value04;
    }
    return 1;
}

s32 free_texture_if_valid(u32 arg0) {
    if (arg0 == 0U) {
        return 0;
    }
    release_texture_list();
    return 1;
}

s32 load_texture_if_valid(u32 arg0) {
    if (arg0 == 0U) {
        return 0;
    }
    load_texture_list();
    return 1;
}

void init_buffers(void) {
    s32 p = (s32)xmalloc(0x1800);
    lbl_805D63C0 = p;
    memset((void *)p, 0, 0x1800);
    lbl_805D63C4 = (s32)xmalloc(0x3800);
}

