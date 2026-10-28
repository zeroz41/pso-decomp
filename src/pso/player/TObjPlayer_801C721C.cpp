#include "types.h"
#include "pso/misc/TLobby_801E43E4.h"
#include "pso/player/TObjPlayer_801C721C.h"
#include "pso/system/byteswap.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

int TFontSmallLobby__sub_801C01BC(void*);
int TFontSmallLobby__sub_801C0228(void*);

void TObjPlayer::set_flag_2000000_alt() { set_state_flags((u32)((void*)2097152)); }
void TObjPlayer::check_flag_04000000() { check_flag((s32)((void*)4194304)); }
void TObjPlayer::set_flag_0x8000() { sub_8011E204((s32)((void*)32768)); }
void TObjPlayer::check_flag_0x8000() { check_flag((s32)((void*)32768)); }
void*TObjPlayer::restore_shrunken_font() { TFontSmallLobby__sub_801C0228(this); return this; }
void TObjPlayer::init_6x88_packet() { *(u8*)((char*)this + 0x0) = 136; *(u8*)((char*)this + 0x1) = 1; }
void TObjPlayer::send_font_update_60() { TFontSmallLobby__sub_801C01BC(this); send_subcommand((u8 *)this); }

void TObjPlayer::bswap_shrink() { read_be16_field2(); bswap_32((u32 *)((char*)this + 0x4)); }

void *TObjPlayer__sub_801C7360(void *arg0, void *arg1) {
    TFontSmallLobby__sub_801C0228(arg0);
    *(f32 *)((s8 *)arg0 + 0x4) = *(f32 *)((s8 *)arg1 + 0x4);
    return arg0;
}

    extern const float lbl_805DC320;
void TObjPlayer::init_shrink_effect() { *(float*)((char*)this + 0x4) = lbl_805DC320; *(unsigned char*)((char*)this + 0x0) = 135; *(unsigned char*)((char*)this + 0x1) = 2; }

void TObjPlayer::update_and_send_60() { bswap_shrink(); send_subcommand((u8 *)this); }

u16 TObjPlayer::interpolate_angle(void *arg0, u16 arg1, u16 arg2, s32 *arg3) {
    s16 temp_r0;
    s32 var_r3;

    temp_r0 = (s16) ((u16) arg2 - arg1);
    if ((temp_r0 > -0x3000) && (temp_r0 < 0x3000)) {
        var_r3 = (temp_r0 >> 4) - (temp_r0 >> 5);
    } else {
        var_r3 = temp_r0 >> 4;
    }
    *arg3 = var_r3;
    return (u16) (arg1 + var_r3);
}

}
