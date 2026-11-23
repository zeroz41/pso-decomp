#include <string.h>
#include "pso/network/TGameProtocol.h"
#include "pso/render/GinjaMaterialState.h"
#include "pso/render/GvmTextureArchive.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/network/client_id.h"
#include "types.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/unk/TLobby_80131794.h"
#include "pso/unk/TLobby_801E43E4.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/system/byteswap.h"
#include "pso/system/TLanguage.h"
#include "pso/network/TProtocol.h"
#include "pso/system/TGStream.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/TTextureWave.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/render/GinjaTexture.h"
#include "pso/system/NinjaTypes.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/unk/TLobby_803DE778.h"

extern "C" {
s32 dispatch_6x_subcommand(void *);
s32 load_texture_list(s32 **);
s32 append_command_to_batch_buffer(void *, s32);
u8 *TQuestVmDownLoadServer__sub_8007EBDC(s32, s32);
s32 distort_texture_wave_image(void *);
}


void long_game_command_union::send_to_client(u32 client_id) {
    u32 size;

    size = ext_game_cmd.header.size;
    bswap_32(&size);
    if ((u32) local_client_id == client_id) {
        dispatching_own_subcommand = 1;
        dispatch_6x_subcommand(this);
        dispatching_own_subcommand = 0;
        return;
    }
    if (TLobby::protocol_instance != NULL) {
        TLobby::protocol_instance->send_pso_data_long2(client_id, game_cmd, size);
    }
}

void send_subcommand_to_leader(void *cmd) {
    s32 size;
    game_command *packet = (game_command *)cmd;

    size = packet->header.size * 4;
    if (get_main_phase() == 0xE) {
        dispatching_own_subcommand = 1;
        dispatch_6x_subcommand(packet);
        dispatching_own_subcommand = 0;
        return;
    }
    if (TLobby::protocol_instance != NULL) {
        TLobby::protocol_instance->send_pso_data2(designated_client_id, *packet, size);
    }
}

void game_command::send_to_client(u32 client_id) {
    s32 size;
    size = header.size * 4;
    if ((u32) local_client_id == client_id) {
        dispatching_own_subcommand = 1;
        dispatch_6x_subcommand(this);
        dispatching_own_subcommand = 0;
        return;
    }
    if (TLobby::protocol_instance != NULL) {
        TLobby::protocol_instance->send_pso_data2(client_id, *this, size);
    }
}

void game_command::send() {
    int size = header.size * 4;
    if (TLobby::protocol_instance != NULL) {
        TLobby::protocol_instance->send_pso_data(*this, size);
    }
}

void send_subcommand(void *cmd) {
    game_command *packet = (game_command *)cmd;
    s32 size = packet->header.size * 4;
    if (TLobby::protocol_instance != NULL) {
        TLobby::protocol_instance->send_pso_data(*packet, size);
    }
    dispatching_own_subcommand = 1;
    dispatch_6x_subcommand(packet);
    dispatching_own_subcommand = 0;
}

void TLobby::update_players() {
    TObject *packet;
    saddr cmd = (saddr)this;

    if ((s32) join_state_flag == 1) {
        send_subcommand((u8 *)cmd);
        return;
    }
    if (game_protocol_instance != NULL) {
        packet = game_protocol_instance->m_down;
        while (packet != NULL) {
            append_command_to_batch_buffer(packet, cmd);
            packet = packet->m_next;
        }
    }
    dispatching_own_subcommand = 1;
    dispatch_6x_subcommand((void *)cmd);
    dispatching_own_subcommand = 0;
}

void TLobby::bswap_switch_activate_token() { ((G_ClientIDHeader *)this)->bswap(); bswap_16((u16 *)((char*)this + 0x4)); bswap_16((u16 *)((char*)this + 0x6)); }

s32 TLobby::load_texture_pvm_file(const char *name, saddr arg1) {
    char path[0x40];
    uaddr buf;
    s32 allocated;
    s32 size;
    s32 ret;
    TLobby::pump_frames();
    strncpy(path, name, 0x40);
    if (((TLobby *)path)->compare_file_extension("gvm") != 0) {
        TLobby::change_file_extension(0, path, (char *)"gvm");
    }
    size = TGStream::get_resource_file_size((const char *)path);
    if (size <= 0) {
        TLobby::debug_print("psoLoadTexturePvmFile:%s file not found.", name);
        return -1;
    }
    allocated = 0;
    size = ((size + 0x7FF) / 2048) * 2048;
    if (size > 0x40000) {
        buf = (uaddr)TQuestVmDownLoadServer::alloc(size);
        if (buf == 0) {
            return -1;
        }
        allocated = 1;
    } else {
        buf = (saddr)TLobby::tmp_buf_use_req("LoadTexturePvm");
    }
    TGStream::load_sct_file((const char *)path, (u8 *)buf);
    ret = load_gvm_texture_archive((void *)buf, (NJS_TEXLIST *)arg1);
    if (allocated != 0) {
        TAdSinglePlyChrSelectGC::safe_free(buf);
    } else {
        TLobby::tmp_buf_release("LoadTexturePvm");
    }
    if (ret < 0) {
        TLobby::debug_print("psoLoadTexturePvmFile:%s load error.", name);
    }
    return ret;
}

s32 pso_load_texture(NJS_TEXLIST *texlist) {
    s32 r;
    s32 ret;
    TLobby::pump_frames();
    while (1) {
        r = load_texture_list((s32 **)texlist);
        if (r == 1) {
            ret = 1;
            break;
        }
        if (r == -1) {
            ret = -1;
            TLobby::debug_print("psoLoadTexture:%s load error.", **(s32 **)texlist);
            break;
        }
        TLobby::run_frame();
    }
    return ret;
}

void TObjPlayer::free_if_valid(saddr texlist) {
    if (texlist != 0) {
        release_texture_list((NJS_TEXLIST *)texlist);
        TAdSinglePlyChrSelectGC::safe_free(texlist);
    }
}

// A GVM texture archive's header ("GVMH").
struct GvmFileHeader {
    u8 magic[4];
    s32 size;
    u16 flags;
    u16 count;
};

saddr TLanguage__read_cursor;

u8 *load_gvm_texture_file(const char *name) {
    s32 count;
    s32 i;
    NJS_TEXLIST *res;
    NJS_TEXNAME *ent;
    char *str;
    uaddr buf;
    u32 big;
    s32 size;
    GvmFileHeader hdr;
    big = 0;
    TLobby::pump_frames();
    size = TGStream::get_resource_file_size(name);
    if (size <= 0) {
        TLobby::debug_print("LoadPvmFileTls:%s load error.", name);
        return NULL;
    }
    size = ((size + 0x7FF) / 2048) * 2048;
    if (size > 0x40000) {
        big = (uaddr)TQuestVmDownLoadServer::alloc(size);
        buf = big;
    } else {
        buf = (saddr)TLobby::tmp_buf_use_req("LoadPvmFileTls");
    }
    TGStream::load_sct_file(name, (u8 *)buf);
    count = TLanguage::read_file_header(buf, &hdr);
    if (count == 0) {
        if (big != 0) {
            TAdSinglePlyChrSelectGC::safe_free(big);
        } else {
            TLobby::tmp_buf_release("LoadPvmFileTls");
        }
        return NULL;
    }
    res = (NJS_TEXLIST *)TQuestVmDownLoadServer__sub_8007EBDC(1, count * 0x2C + 8);
    res->nbTexture = count;
    i = 0;
    res->textures = (NJS_TEXNAME *)(res + 1);
    ent = (NJS_TEXNAME *)(res + 1);
    str = (char *)(ent + count);
    for (; i < count; i++, ent++, str += 0x20) {
        ent->filename = str;
        TLanguage__read_cursor += 2;
        if (hdr.flags & 1) {
            TLanguage::read_into_buffer((saddr)str, 0x1C);
            str[0x1C] = 0;
        }
        if (hdr.flags & 2) {
            TLanguage__read_cursor += 2;
        }
        if (hdr.flags & 4) {
            TLanguage__read_cursor += 2;
        }
        if (hdr.flags & 8) {
            TLanguage__read_cursor += 4;
        }
    }
    load_gvm_texture_archive((void *)buf, res);
    if (big != 0) {
        TAdSinglePlyChrSelectGC::safe_free(big);
    } else {
        TLobby::tmp_buf_release("LoadPvmFileTls");
    }
    return (u8 *)res;
}

int TLanguage::read_file_header(int cursor, void *header) {
    GvmFileHeader *hdr = (GvmFileHeader *)header;
    TLanguage__read_cursor = cursor;
    TLanguage::read_into_buffer((saddr)hdr, 4);
    hdr->size = TLanguage::read_u32_le();
    hdr->flags = TLanguage::read_u16_le();
    hdr->count = TLanguage::read_u16_le();
    bswap_32((u32 *)&hdr->size);
    bswap_16(&hdr->flags);
    bswap_16(&hdr->count);
    return hdr->count;
}

void TLanguage::read_into_buffer(saddr arg0, s32 arg1) {
    move_data((void *)(arg0), (const void *)((const void *)TLanguage__read_cursor), (u32)arg1);
    TLanguage__read_cursor += arg1;
}

s32 TLanguage::read_u32_le() {
    s32 v = *(u8 *)TLanguage__read_cursor++;
    v |= *(u8 *)TLanguage__read_cursor++ << 8;
    v |= *(u8 *)TLanguage__read_cursor++ << 16;
    v |= *(u8 *)TLanguage__read_cursor++ << 24;
    return v;
}

s32 TLanguage::read_u16_le() {
    s32 lo = *(u8 *)TLanguage__read_cursor++;
    lo |= *(u8 *)TLanguage__read_cursor++ << 8;
    return lo;
}

void TTextureWave::update_texture_wave_image() {
    if ((is_split_screen() == 0) || (TCameraCtrl::get_camera_no() == 0)) {
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(m_3c));
        advance_wrapped_cursor();
        distort_texture_wave_image(this);
    }
}
