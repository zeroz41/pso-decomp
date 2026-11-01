#include "types.h"
#include "pso/unk/text_8007C0CC.h"
#include "pso/unk/text_800F7DAC.h"
#include "pso/misc/TLobby_8007C550.h"
#include "pso/misc/TLobby_800F9690.h"
#include "pso/object/TObjFish_8001ED90.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TGStream.h"
#include "pso/misc/TQuestVmDownLoadServer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

extern "C" {
s32 alloc_named_object(s32, s32, s32, s32);
int sprintf(char *, const char *, ...);
extern char lbl_8043D9FC[];
extern char lbl_8043DA04[];
s32 subtractive_rng_seed(s32 *, s32);

struct Sp8_800f9690 { s8 data[240]; };
u32 TLobby::write_packet_header(s32 arg1, s32 arg2, u32 arg3) {
    struct Sp8_800f9690 sp8;
    u32 v0 = (u32)*(s32 *)&this->m_name;
    s32 v4 = *(s32 *)&this->m_flags;

    if (v0 > arg3) {
        return 0U;
    }
    __ct__14SubtractiveRngFv((s32 *)&sp8);
    subtractive_rng_seed((s32 *)&sp8, v4);
    subtractive_rng_xor_buffer((s32 *)&sp8, (u32 *)&this->m_prev, arg1 - 8);
    prs_decompress_buffer((s32)&this->m_prev, arg2);
    return v0;
}

struct Sp8_800f970c { s8 data[240]; };
s32 TLobby::alloc_download_quest(s32 arg1, s32 *arg2) {
    struct Sp8_800f970c sp8;
    s32 v0 = *(s32 *)&this->m_name;
    s32 v4 = *(s32 *)&this->m_flags;
    s32 ret;

    ret = ((TQuestVmDownLoadServer *)v0)->alloc();
    if (ret == 0) {
        return 0;
    }
    __ct__14SubtractiveRngFv((s32 *)&sp8);
    subtractive_rng_seed((s32 *)&sp8, v4);
    subtractive_rng_xor_buffer((s32 *)&sp8, (u32 *)&this->m_prev, arg1 - 8);
    prs_decompress_buffer((s32)&this->m_prev, ret);
    if (arg2 != NULL) {
        *arg2 = v0;
    }
    return ret;
}
u8 *set_stream_and_load_file__6TLobbyFi(s32);
s32 update_lobby_scene__6TSceneFv();
s32 read_disc_file(s32, s32);
s32 destroy_gstream(s32 *, s32);
s32 open__8TGStreamFPvPvi(s32 *, s32, s32);
extern s32 lbl_80499A40[];

struct Stream_800F979C { u8 data[0x2c]; };
struct Sel_800F979C { u8 data[240]; };

s32 load_encrypted_text_archive(char *name, s32 *arg1) {
    s32 size;
    s32 h;
    u8 *buf;
    s32 ret;
    s32 sp8;
    Stream_800F979C st;
    Sel_800F979C sel;

    size = update_lobby_scene__6TSceneFv();
    if (size <= 0) {
        return 0;
    }
    if ((size <= 0x40000) && (TLobby::tmp_buf_is_free() != 0)) {
        buf = (u8 *)TLobby::tmp_buf_use_req((const char *)lbl_80499A40);
        read_disc_file((s32)name, (s32)buf);
        ret = ((TLobby *)buf)->alloc_download_quest(size, &sp8);
        TLobby::tmp_buf_release((const char *)lbl_80499A40);
    } else {
        open__8TGStreamFPvPvi((s32 *)&st, (s32)name, 1);
        buf = (u8 *)((TQuestVmDownLoadServer *)0x800)->alloc();
        ((TGStream *)((s32 *)&st))->read_sectors_sync(1, (s32)buf);
        sp8 = *(s32 *)((s8 *)buf + 0);
        h = *(s32 *)((s8 *)buf + 4);
        TAdSinglePlyChrSelectGC::safe_free((u32)buf);
        ret = ((TQuestVmDownLoadServer *)sp8)->alloc();
        buf = set_stream_and_load_file__6TLobbyFi((s32)name);
        __ct__14SubtractiveRngFv((s32 *)&sel);
        subtractive_rng_seed((s32 *)&sel, h);
        subtractive_rng_xor_buffer((s32 *)&sel, (u32 *)(buf + 8), size - 8);
        prs_decompress_buffer((s32)(buf + 8), ret);
        TAdSinglePlyChrSelectGC::safe_free((u32)buf);
        destroy_gstream((s32 *)&st, -1);
    }
    if (arg1 != NULL) {
        *arg1 = sp8;
    }
    return ret;
}

s32 load_text_resource_pair(s32 arg0) {
    s32 sp8;
    char buf[0x40];
    s32 a;
    s32 b;
    s32 r;
    sprintf(buf, lbl_8043D9FC, arg0);
    a = load_encrypted_text_archive(buf, &sp8);
    sprintf(buf, lbl_8043DA04, arg0);
    b = load_encrypted_text_archive(buf, &sp8);
    r = alloc_named_object(arg0, a, sp8, b);
    TAdSinglePlyChrSelectGC::safe_free((u32)((void *)b));
    return r;
}

}
