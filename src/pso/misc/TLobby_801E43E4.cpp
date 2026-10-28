#include "pso/protocol/protocol_types.h"
#include "pso/network/client_id.h"
#include "types.h"
#include "pso/misc/TKeyBoardControl_8000F764.h"
#include "pso/misc/TLobby_80131794.h"
#include "pso/misc/TLobby_801E43E4.h"
#include "pso/system/byteswap.h"
#include "pso/TProtocol.h"
#include "pso/misc/TGStream.h"
#include "pso/misc/TLobby.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

extern "C" {
s32 TProtocol__send_60(int, int, int);
s32 dispatch_6x_subcommand(void *);
extern u32 TLobby__protocol_instance;
void *tmp_buf_use_req__6TLobbyFPCc(char *);
void *alloc__22TQuestVmDownLoadServerFv(void);
void debug_print__6TLobbyFle(const char *, ...);
char *strncpy(char *, const char *, u32);
s32 load_gvm_texture_archive(void *, s32);
extern char texture_pvm_not_found_format[];
extern char lbl_804497C4[];
extern char texture_pvm_load_error_format[];
extern char lbl_805DC448[4];
s32 load_texture_list(s32 **);
extern char pso_texture_load_error_format[];
s32 append_command_to_batch_buffer(void *, s32);
s32 send_pso_data_long2__9TProtocolFcR17long_game_commandUl(void*, u32, void *, s32);

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
        send_pso_data_long2__9TProtocolFcR17long_game_commandUl((void*)TLobby__protocol_instance, arg1, this, sp8);
    }
}

extern s32 TLobby__designated_client_id;

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
extern "C" {

extern s32 TLobby__join_state_flag;
extern void *game_protocol_instance;

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
extern "C" {

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
    void *buf;
    s32 allocated;
    s32 size;
    s32 ret;
    TLobby::pump_frames();
    strncpy(path, name, 0x40);
    if (((TLobby *)path)->compare_file_extension(lbl_805DC448) != 0) {
        change_file_extension__6TLobbyFPvPvPv(0, path, lbl_805DC448);
    }
    size = ((TLobby *)path)->get_resource_file_size();
    if (size <= 0) {
        debug_print__6TLobbyFle(texture_pvm_not_found_format, name);
        return -1;
    }
    allocated = 0;
    if (((size + 0x7FF) / 2048) * 2048 > 0x40000) {
        buf = alloc__22TQuestVmDownLoadServerFv();
        if (buf == NULL) {
            return -1;
        }
        allocated = 1;
    } else {
        buf = tmp_buf_use_req__6TLobbyFPCc(lbl_804497C4);
    }
    TGStream::load_sct_file((s32)path, (s32)buf);
    ret = load_gvm_texture_archive(buf, arg1);
    if (allocated != 0) {
        TAdSinglePlyChrSelectGC::safe_free((u32)buf);
    } else {
        ((TLobby *)lbl_804497C4)->tmp_buf_release();
    }
    if (ret < 0) {
        debug_print__6TLobbyFle(texture_pvm_load_error_format, name);
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
            debug_print__6TLobbyFle(pso_texture_load_error_format, **((s32 **)this));
            break;
        }
        TLobby::run_frame();
    }
    return ret;
}

}
