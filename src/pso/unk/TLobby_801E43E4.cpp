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
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/render/GinjaTexture.h"
#include "pso/system/NinjaTypes.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/object/ambient/TObjFish.h"

extern "C" {
s32 TProtocol__send_60(int, int, int);
s32 dispatch_6x_subcommand(void *);
extern u32 TLobby__protocol_instance;
char *strncpy(char *, const char *, u32);
s32 load_gvm_texture_archive(u32, void *);
s32 load_texture_list(s32 **);
s32 append_command_to_batch_buffer(void *, s32);
u8 *TQuestVmDownLoadServer__sub_8007EBDC(s32, s32);
s32 distort_texture_wave_image(void *);
s32 is_split_screen();
s32 send_pso_data_long2__9TProtocolFcR17long_game_commandUl(void *, u32, void *, s32);
}

extern s32 TLobby__designated_client_id;
extern s32 TLobby__join_state_flag;
extern void *game_protocol_instance;

void TLobby::send_command(u32 arg1) {
    s32 sp8;

    sp8 = *(s32 *)&this->m_flags;
    bswap_32((u32 *)&sp8);
    if ((u32) local_client_id == arg1) {
        dispatching_own_subcommand = 1;
        dispatch_6x_subcommand(this);
        dispatching_own_subcommand = 0;
        return;
    }
    if ((u32) TLobby__protocol_instance != 0U) {
        send_pso_data_long2__9TProtocolFcR17long_game_commandUl((void *)TLobby__protocol_instance, arg1, this, sp8);
    }
}

void send_subcommand_to_leader(void *cmd) {
    void *src = cmd;
    s32 len;

    len = *(u8 *)((s8 *)src + 1) * 4;
    if (get_main_phase() == 0xE) {
        dispatching_own_subcommand = 1;
        dispatch_6x_subcommand(src);
        dispatching_own_subcommand = 0;
        return;
    }
    if ((u32) TLobby__protocol_instance != 0U) {
        ((TProtocol *)TLobby__protocol_instance)->send_subcommand_to_client((s32)TLobby__designated_client_id, (s8 *)src, (s32)len);
    }
}

void TLobby::send_subcommand_to_client(u32 arg1) {
    s32 size;
    size = *(u8 *)((s8 *)this + 1) * 4;
    if ((u32) local_client_id == arg1) {
        dispatching_own_subcommand = 1;
        dispatch_6x_subcommand(this);
        dispatching_own_subcommand = 0;
        return;
    }
    if ((u32) TLobby__protocol_instance != 0U) {
        ((TProtocol *)TLobby__protocol_instance)->send_subcommand_to_client((s32)arg1, (s8 *)this, (s32)size);
    }
}

void TLobby::send_60_sized() {
    int size = ((u8 *)this)[1] * 4;
    if (TLobby__protocol_instance != 0) {
        TProtocol__send_60(TLobby__protocol_instance, (int)this, size);
    }
}

void send_subcommand(void *cmd) {
    u8 *arg0 = (u8 *)cmd;
    s32 len;
    u8 *var_r31;
    u8 *var_r3;
    u8 *src;
    var_r31 = arg0;
    src = (u8 *)((*(u8 * *)&TLobby__protocol_instance));
    len = *(u8 *)((s8 *)arg0 + 1) * 4;
    if (src != NULL) {
        var_r3 = src;
        src = var_r31;
        TProtocol__send_60((int)var_r3, (int)src, (int)len);
    }
    var_r3 = var_r31;
    dispatching_own_subcommand = 1;
    dispatch_6x_subcommand(var_r3);
    dispatching_own_subcommand = 0;
}

void TLobby::update_players() {
    void *var_r31;
    s32 arg0 = (s32)this;

    if ((s32) TLobby__join_state_flag == 1) {
        send_subcommand((u8 *)arg0);
        return;
    }
    if ((void *) game_protocol_instance != NULL) {
        var_r31 = *(void **)((s8 *)game_protocol_instance + 0x14);
        while (var_r31 != NULL) {
            append_command_to_batch_buffer(var_r31, arg0);
            var_r31 = *(void **)((s8 *)var_r31 + 0xC);
        }
    }
    dispatching_own_subcommand = 1;
    dispatch_6x_subcommand((void *)arg0);
    dispatching_own_subcommand = 0;
}

void TLobby::bswap_switch_activate_token() { ((G_ClientIDHeader *)this)->bswap(); bswap_16((u16 *)((char*)this + 0x4)); bswap_16((u16 *)((char*)this + 0x6)); }

s32 TLobby::load_texture_pvm_file(const char *name, s32 arg1) {
    char path[0x40];
    u32 buf;
    s32 allocated;
    s32 size;
    s32 ret;
    TLobby::pump_frames();
    strncpy(path, name, 0x40);
    if (((TLobby *)path)->compare_file_extension("gvm") != 0) {
        change_file_extension__6TLobbyFPvPvPv(0, path, "gvm");
    }
    size = ((TLobby *)path)->get_resource_file_size();
    if (size <= 0) {
        TLobby::debug_print("psoLoadTexturePvmFile:%s file not found.", name);
        return -1;
    }
    allocated = 0;
    size = ((size + 0x7FF) / 2048) * 2048;
    if (size > 0x40000) {
        buf = (u32)TQuestVmDownLoadServer::alloc(size);
        if (buf == 0) {
            return -1;
        }
        allocated = 1;
    } else {
        buf = TLobby::tmp_buf_use_req("LoadTexturePvm");
    }
    TGStream::load_sct_file((s32)path, buf);
    ret = load_gvm_texture_archive(buf, (void *)arg1);
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

s32 TLobby::pso_load_texture() {
    s32 r;
    s32 ret;
    TLobby::pump_frames();
    while (1) {
        r = load_texture_list(((s32 **)this));
        if (r == 1) {
            ret = 1;
            break;
        }
        if (r == -1) {
            ret = -1;
            TLobby::debug_print("psoLoadTexture:%s load error.", **((s32 **)this));
            break;
        }
        TLobby::run_frame();
    }
    return ret;
}

void TObjPlayer::free_if_valid(s32 texlist) {
    if (texlist != 0) {
        release_texture_list((GinjaTextureList *)texlist);
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

s32 TLanguage__read_cursor;

struct Base_801E4B68_801E4874 { char pad[0x50]; };
struct VObj_801E4B68_801E4874 : Base_801E4B68_801E4874 {
    virtual void m0();
};

u8 *load_gvm_texture_file(s32 arg0) {
    s32 count;
    s32 i;
    NJS_TEXLIST *res;
    NJS_TEXNAME *ent;
    u8 *str;
    u32 buf;
    u32 big;
    s32 size;
    GvmFileHeader hdr;
    big = 0;
    TLobby::pump_frames();
    size = ((TLobby *)arg0)->get_resource_file_size();
    if (size <= 0) {
        TLobby::debug_print("LoadPvmFileTls:%s load error.", arg0);
        return NULL;
    }
    size = ((size + 0x7FF) / 2048) * 2048;
    if (size > 0x40000) {
        big = (u32)TQuestVmDownLoadServer::alloc(size);
        buf = big;
    } else {
        buf = TLobby::tmp_buf_use_req("LoadPvmFileTls");
    }
    TGStream::load_sct_file(arg0, buf);
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
    str = (u8 *)(ent + count);
    for (; i < count; i++, ent++, str += 0x20) {
        ent->filename = str;
        TLanguage__read_cursor += 2;
        if (hdr.flags & 1) {
            TLanguage::read_into_buffer((s32)str, 0x1C);
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
    load_gvm_texture_archive(buf, res);
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
    TLanguage::read_into_buffer((s32)hdr, 4);
    hdr->size = TLanguage::read_u32_le();
    hdr->flags = TLanguage::read_u16_le();
    hdr->count = TLanguage::read_u16_le();
    bswap_32((u32 *)&hdr->size);
    bswap_16(&hdr->flags);
    bswap_16(&hdr->count);
    return hdr->count;
}

void TLanguage::read_into_buffer(s32 arg0, s32 arg1) {
    ((TLobby *)arg0)->move_data((const void *)TLanguage__read_cursor, (u32)arg1);
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

void update_texture_wave_image(void *wave) {
    if ((is_split_screen() == 0) || (TCameraCtrl::get_camera_no() == 0)) {
        TObjFish::set_global_param(*(s32 *)((s8 *)wave + 0x3C));
        ((VObj_801E4B68_801E4874 *)wave)->m0();
        distort_texture_wave_image(wave);
    }
}
