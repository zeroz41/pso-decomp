#include "types.h"
#include "pso/misc/TLanguage_801E4874.h"
#include "pso/system/byteswap.h"
#include "pso/misc/TLanguage.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TGStream.h"
#include "pso/misc/TLobby.h"
#include "pso/object/TObjFish.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct Hdr_801E4874 {
    u8 magic[4];
    s32 size;
    u16 flags;
    u16 count;
};

struct Ent_801E4874 {
    u8 *name;
    u8 pad[8];
};

extern s32 TLanguage__read_cursor;
extern "C" {
u8 *TQuestVmDownLoadServer__sub_8007EBDC(s32, s32);
u32 alloc__22TQuestVmDownLoadServerFv();
void debug_print__6TLobbyFle(void *, ...);
void load_gvm_texture_archive(u32, u8 *);
extern u8 texture_file_load_error_format[];
extern u8 lbl_8044983C[];
struct Base_801E4B68_801E4874 { char pad[0x50]; };
struct VObj_801E4B68_801E4874 : Base_801E4B68_801E4874 {
    virtual void m0();
};

s32 distort_texture_wave_image(void *);
s32 is_split_screen();

u8 *load_gvm_texture_file(s32 arg0) {
    s32 count;
    s32 i;
    u8 *res;
    Ent_801E4874 *ent;
    u8 *str;
    u32 buf;
    u32 big;
    s32 size;
    Hdr_801E4874 hdr;
    big = 0;
    TLobby::pump_frames();
    size = ((TLobby *)arg0)->get_resource_file_size();
    if (size <= 0) {
        debug_print__6TLobbyFle(texture_file_load_error_format, arg0);
        return NULL;
    }
    if (((size + 0x7FF) / 2048) * 2048 > 0x40000) {
        big = alloc__22TQuestVmDownLoadServerFv();
        buf = big;
    } else {
        buf = TLobby::tmp_buf_use_req((const char *)lbl_8044983C);
    }
    TGStream::load_sct_file(arg0, buf);
    count = ((s32 (*)(s32, u8 *))read_file_header__9TLanguageFiPv)(buf, (u8 *)&hdr);
    if (count == 0) {
        if (big != 0) {
            TAdSinglePlyChrSelectGC::safe_free(big);
        } else {
            TLobby::tmp_buf_release((const char *)lbl_8044983C);
        }
        return NULL;
    }
    res = TQuestVmDownLoadServer__sub_8007EBDC(1, count * 0x2C + 8);
    *(s32 *)(res + 4) = count;
    i = 0;
    *(Ent_801E4874 **)res = (Ent_801E4874 *)(res + 8);
    ent = (Ent_801E4874 *)(res + 8);
    str = (u8 *)(ent + count);
    for (; i < count; i++, ent++, str += 0x20) {
        ent->name = str;
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
        TLobby::tmp_buf_release((const char *)lbl_8044983C);
    }
    return res;
}

u16 read_file_header__9TLanguageFiPv(s32 arg0, u8 *arg1) {
    TLanguage__read_cursor = arg0;
    TLanguage::read_into_buffer((s32)arg1, 4);
    *(s32 *)((s8 *)arg1 + 4) = TLanguage::read_u32_le();
    *(u16 *)((s8 *)arg1 + 8) = TLanguage::read_u16_le();
    *(u16 *)((s8 *)arg1 + 0xA) = TLanguage::read_u16_le();
    bswap_32((u32 *)(arg1 + 4));
    bswap_16((u16 *)(arg1 + 8));
    bswap_16((u16 *)(arg1 + 0xA));
    return *(u16 *)((s8 *)arg1 + 0xA);
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
}

void update_texture_wave_image(void *wave) {
    if ((is_split_screen() == 0) || (TCameraCtrl::get_camera_no() == 0)) {
        TObjFish::set_global_param(*(s32 *)((s8 *)wave + 0x3C));
        ((VObj_801E4B68_801E4874 *)wave)->m0();
        distort_texture_wave_image(wave);
    }
}
