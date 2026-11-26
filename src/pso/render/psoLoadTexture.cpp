#include "pso/system/memory.h"
#include <string.h>
#include "pso/network/TGameProtocol.h"
#include "pso/render/GinjaMaterialState.h"
#include "pso/render/GvmTextureArchive.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/network/client_id.h"
#include "types.h"
#include "pso/ui/keyboard/SystemBootInit.h"
#include "pso/render/psoLoadTexture.h"
#include "pso/system/byteswap.h"
#include "pso/system/TLanguage.h"
#include "pso/network/TProtocol.h"
#include "pso/system/TGStream.h"
#include "pso/network/TLobby.h"
#include "pso/unk/TTextureWave.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/render/GinjaTexture.h"
#include "pso/system/NinjaTypes.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/unk/text_803DA798.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/unk/TLobby_803DE778.h"
#include "pso/unk/text_803DD5E0.h"
#include "pso/quest/TQuestListVM_8007EAF8.h"
#include "pso/system/BmlResource.h"
#include "pso/render/render_util.h"
#include "pso/render/GinjaDrawUtil.h"
#include "pso/render/nuReLoadTexture.h"
#include "pso/system/AsyncFileRead.h"
#include "pso/ui/window/TWindowKeyBoardHard_801A529C.h"
#include "pso/network/TPacket.h"


s32 psoLoadTexturePvmFile(const char *name, NJS_TEXLIST *texlist) {
    char path[0x40];
    u8 *buf;
    s32 allocated;
    s32 size;
    s32 ret;
    pump_frames();
    strncpy(path, name, 0x40);
    if (((TLobby *)path)->compare_file_extension("gvm") != 0) {
        TLobby::change_file_extension(0, path, (char *)"gvm");
    }
    size = TGStream::get_resource_file_size(path);
    if (size <= 0) {
        TLobby::debug_print("psoLoadTexturePvmFile:%s file not found.", name);
        return -1;
    }
    allocated = 0;
    size = ((size + 0x7FF) / 2048) * 2048;
    if (size > 0x40000) {
        buf = static_cast<u8 *>(TQuestVmDownLoadServer::alloc(size));
        if (buf == 0) {
            return -1;
        }
        allocated = 1;
    } else {
        buf = (u8 *)tmp_buf_use_req("LoadTexturePvm");
    }
    TGStream::gsSctLoadFile(path, buf);
    ret = load_gvm_texture_archive(buf, texlist);
    if (allocated != 0) {
        safe_free(buf);
    } else {
        tmp_buf_release("LoadTexturePvm");
    }
    if (ret < 0) {
        TLobby::debug_print("psoLoadTexturePvmFile:%s load error.", name);
    }
    return ret;
}

s32 psoLoadTexture(NJS_TEXLIST *texlist) {
    s32 r;
    s32 ret;
    pump_frames();
    while (1) {
        r = load_texture_list(texlist);
        if (r == 1) {
            ret = 1;
            break;
        }
        if (r == -1) {
            ret = -1;
            TLobby::debug_print("psoLoadTexture:%s load error.", texlist->textures->filename);
            break;
        }
        TLobby::run_frame();
    }
    return ret;
}

void TObjPlayer::free_if_valid(saddr texlist) {
    if (texlist != 0) {
        release_texture_list((NJS_TEXLIST *)texlist);
        safe_free(reinterpret_cast<void *>(texlist));
    }
}

// A GVM texture archive's header ("GVMH").

u8 *language_read_cursor;

NJS_TEXLIST *LoadPvmFileTls(const char *name) {
    s32 count;
    s32 i;
    NJS_TEXLIST *res;
    NJS_TEXNAME *ent;
    char *str;
    u8 *buf;
    u8 *big;
    s32 size;
    GvmFileHeader hdr;
    big = NULL;
    pump_frames();
    size = TGStream::get_resource_file_size(name);
    if (size <= 0) {
        TLobby::debug_print("LoadPvmFileTls:%s load error.", name);
        return NULL;
    }
    size = ((size + 0x7FF) / 2048) * 2048;
    if (size > 0x40000) {
        big = static_cast<u8 *>(TQuestVmDownLoadServer::alloc(size));
        buf = big;
    } else {
        buf = tmp_buf_use_req("LoadPvmFileTls");
    }
    TGStream::gsSctLoadFile(name, buf);
    count = TLanguage::read_file_header(buf, &hdr);
    if (count == 0) {
        if (big != NULL) {
            safe_free(big);
        } else {
            tmp_buf_release("LoadPvmFileTls");
        }
        return NULL;
    }
    res = (NJS_TEXLIST *)alloc_zeroed_array(1, count * 0x2C + 8);
    res->nbTexture = count;
    i = 0;
    res->textures = (NJS_TEXNAME *)(res + 1);
    ent = (NJS_TEXNAME *)(res + 1);
    str = (char *)(ent + count);
    for (; i < count; i++, ent++, str += 0x20) {
        ent->filename = str;
        language_read_cursor += 2;
        if (hdr.flags & 1) {
            TLanguage::read_into_buffer(str, 0x1C);
            str[0x1C] = 0;
        }
        if (hdr.flags & 2) {
            language_read_cursor += 2;
        }
        if (hdr.flags & 4) {
            language_read_cursor += 2;
        }
        if (hdr.flags & 8) {
            language_read_cursor += 4;
        }
    }
    load_gvm_texture_archive(buf, res);
    if (big != NULL) {
        safe_free(big);
    } else {
        tmp_buf_release("LoadPvmFileTls");
    }
    return res;
}

int TLanguage::read_file_header(u8 *cursor, GvmFileHeader *hdr) {
    language_read_cursor = cursor;
    TLanguage::read_into_buffer(hdr, 4);
    hdr->size = TLanguage::read_u32_le();
    hdr->flags = TLanguage::read_u16_le();
    hdr->count = TLanguage::read_u16_le();
    bswap_32(&hdr->size);
    bswap_16(&hdr->flags);
    bswap_16(&hdr->count);
    return hdr->count;
}

void TLanguage::read_into_buffer(void *destination, s32 length) {
    move_data(destination, language_read_cursor, length);
    language_read_cursor += length;
}

s32 TLanguage::read_u32_le() {
    s32 v = *language_read_cursor++;
    v |= *language_read_cursor++ << 8;
    v |= *language_read_cursor++ << 16;
    v |= *language_read_cursor++ << 24;
    return v;
}

s32 TLanguage::read_u16_le() {
    s32 lo = *language_read_cursor++;
    lo |= *language_read_cursor++ << 8;
    return lo;
}

void TTextureWave::update_texture_wave_image() {
    if ((is_split_screen() == 0) || (TCameraCtrl::get_camera_no() == 0)) {
        set_texture_list(reinterpret_cast<NJS_TEXLIST *>(texture_list));
        advance_wrapped_cursor();
        distort_image();
    }
}

void TTextureWave::distort_image() {
    s32 y;
    u8 *dx;
    u8 *dy;
    u16 *image;
    u16 *out;
    s32 x;
    y = 0;
    out = reinterpret_cast<GvrTexture *>(output)->texels;
    dx = reinterpret_cast<u8 *>(displacement);
    image = reinterpret_cast<GvrTexture *>(image_data)->texels;
    dy = dx + height * width;
    for (; y < height; y++) {
        for (x = 0; x < width; x++) {
            s32 at = phase + x;
            u16 sx;
            u16 sy;
            u16 color;
            u8 ox;
            s32 idx;
            u8 oy;
            if (at >= width) {
                at -= width;
            }
            idx = at + y * width;
            ox = dx[idx];
            oy = dy[idx];
            sx = ox + x;
            if (sx >= width) {
                sx -= width;
            }
            sy = oy + y;
            if (sy >= height) {
                sy -= height;
            }
            color = image[sx + sy * width] | 0x8000;
            out[calc_gx_tile_index(x, y, width)] = color;
        }
    }
    reload_texture_num(0, output + 0x20, NJD_TEXATTR_TYPE_MEMORY, 0);
}
