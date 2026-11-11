#include "types.h"
#include "pso/unk/TLobby.h"
#include "pso/item/TUnk_804CC048.h"
#include "pso/map/FloorArea.h"
#include "pso/unk/TLobby_80207644.h"
#include "pso/unk/TLobby_8023F734.h"

struct RecoveredGlobal_80227AA8_lbl_80514F64 {
    s32 value;
    u8 remaining[0xC38];
};

extern "C" {
void get_menu_field_280__6TLobbyFv(void);
void fn_8023F660(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);

    extern int music_stream_base_gain;
int get_music_base_gain(void) {  return music_stream_base_gain; }
typedef char RecoveredGlobal_80227AA8_lbl_80514F64_size[sizeof(RecoveredGlobal_80227AA8_lbl_80514F64) == 0xC3C ? 1 : -1];
void TLobby__sub_80227AA8(s32 arg0) {
    fn_8023F660((&(*(RecoveredGlobal_80227AA8_lbl_80514F64 *)&sound_control_state).value), (arg0), (((s32 (*)())get_menu_field_280__6TLobbyFv)() + 0x55), 0x40, 0x40, 0);
}

}


struct RecoveredGlobal_8000F764_TKeyBoardControl__data_80506270 {
    s32 value;
    u8 remaining[0xAC];
};

struct RecoveredGlobal_8000F7FC_lbl_80515F48 {
    s32 value;
    u8 remaining[0x24];
};

struct RecoveredGlobal_8000F9E4_lbl_804FE120 {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_8000F90C_lbl_804FE120 {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_8000F9CC_lbl_804FE120 {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_8000F8FC_lbl_804FE120 {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_8000F8EC_lbl_804FE120 {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_8000F91C_lbl_804FE120 {
    s32 value;
    u8 remaining[0x14];
};

#include <stddef.h>
#include "pso/system/scene/TScene.h"
struct RecoveredGlobal_80069094_camera_controller_registry { s32 value; u8 remaining[0x64]; };

struct RecoveredGlobal_80069024_TCameraCtrl__data_804FF634 {
    s32 value;
    u8 remaining[0x44];
};

struct RecoveredGlobal_80069024_lbl_804FF67C {
    s32 value;
    u8 remaining[0x44];
};

struct RecoveredGlobal_800695E8_TCameraCtrl__data_804FF628 {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_800691C8_TCameraCtrl__data_804FF6D0 {
    s32 value;
    u8 remaining[0x2C];
};

struct RecoveredGlobal_800691C8_TCameraCtrl__data_804FF700 {
    s32 value;
    u8 remaining[0xBC];
};

struct RecoveredGlobal_800691C8_main_task {
    s32 value;
    u8 remaining[0x30];
};

struct RecoveredGlobal_800687E4_TCameraCtrl__data_804FF6C4 {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_80069148_TCameraCtrl__data_804FF6D0 {
    s32 value;
    u8 remaining[0x2C];
};

struct RecoveredGlobal_80069148_TCameraCtrl__data_804FF700 {
    s32 value;
    u8 remaining[0xBC];
};

struct RecoveredGlobal_80069C94_camera_controller_registry {
    s32 value;
    u8 remaining[0x64];
};

struct RecoveredGlobal_80069C94_TCameraCtrl__data_804FF628 {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_80069D04_camera_controller_registry {
    s32 value;
    u8 remaining[0x64];
};

struct RecoveredGlobal_80069D04_TCameraCtrl__data_804FF628 {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_800687C8_TCameraCtrl__data_804FF6C4 {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_80069304_TCameraCtrl__data_804FF628 {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_8006961C_TCameraCtrl__data_804FF628 {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_8006961C_TCameraCtrl__data_804FF634 {
    s32 value;
    u8 remaining[0x44];
};

struct RecoveredGlobal_8006961C_lbl_8058CA60 {
    s32 value;
    u8 remaining[0x54];
};

struct RecoveredGlobal_80069258_TCameraCtrl__data_804FF6D0 {
    s32 value;
    u8 remaining[0x2C];
};

struct RecoveredGlobal_80069258_TCameraCtrl__data_804FF700 {
    s32 value;
    u8 remaining[0xBC];
};

struct RecoveredGlobal_80069258_main_task {
    s32 value;
    u8 remaining[0x30];
};

struct RecoveredGlobal_80069A6C_camera_controller_registry {
    s32 value;
    u8 remaining[0x64];
};

struct RecoveredGlobal_80069A6C_TCameraCtrl__data_804FF628 {
    u8 value;
    u8 remaining[0xB];
};

extern "C" {
void apply_clamped_field_27c__6TLobbyFv(f32 value);
void is_sound_enabled(void);
s32 is_special_sound_id(u32 x);
s32 normalize_sound_request(u32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
s32 play_packed_sound_once(u32 arg0, s32 arg1, s32 arg2, s32 arg3);
void TLobby__sub_80227AF8(s32 arg0, s32 arg1);
void release_sound_with_fade(s32 slot);
void TLobby__sub_80227D38(void);
void handle_6xB2_play_sound_from_player(void *arg0);
s32 play_sound_effect(s32, s32, s32, s32);
u16 TCameraCtrl__sub_8006A5DC();
void *get_player_by_client_id(s32 i);
s32 bswap_6xB2_play_sound();
s32 on_set_mode__6TLobbyFv(s32);

void TLobby__sub_80227AF8(s32 arg0, s32 arg1) { TLobby__sub_8023F754(arg0, arg1); }

extern s32 local_client_id;

typedef char RecoveredGlobal_8000F764_TKeyBoardControl__data_80506270_size[sizeof(RecoveredGlobal_8000F764_TKeyBoardControl__data_80506270) == 0xB0 ? 1 : -1];
typedef char RecoveredGlobal_8000F7FC_lbl_80515F48_size[sizeof(RecoveredGlobal_8000F7FC_lbl_80515F48) == 0x28 ? 1 : -1];

s32 is_special_sound_id(u32 x) {
    s32 lo = x & 0xffff;
    s32 hi = x >> 16;
    if (hi == 2 && (lo == 0x27 || lo == 0x2f)) {
        return 1;
    }
    return 0;
}

void apply_clamped_field_27c__6TLobbyFv(f32 value) {
    set_clamped_field27c__6TLobbyFPvf(&sound_control_state, value);
}
typedef char RecoveredGlobal_8000F90C_lbl_804FE120_size[sizeof(RecoveredGlobal_8000F90C_lbl_804FE120) == 0x18 ? 1 : -1];
typedef char RecoveredGlobal_8000F8FC_lbl_804FE120_size[sizeof(RecoveredGlobal_8000F8FC_lbl_804FE120) == 0x18 ? 1 : -1];
typedef char RecoveredGlobal_8000F8EC_lbl_804FE120_size[sizeof(RecoveredGlobal_8000F8EC_lbl_804FE120) == 0x18 ? 1 : -1];
typedef char RecoveredGlobal_8000F91C_lbl_804FE120_size[sizeof(RecoveredGlobal_8000F91C_lbl_804FE120) == 0x18 ? 1 : -1];
typedef char RecoveredGlobal_8000F9E4_lbl_804FE120_size[sizeof(RecoveredGlobal_8000F9E4_lbl_804FE120) == 0x18 ? 1 : -1];
typedef char RecoveredGlobal_8000F9CC_lbl_804FE120_size[sizeof(RecoveredGlobal_8000F9CC_lbl_804FE120) == 0x18 ? 1 : -1];

void handle_6xB2_play_sound_from_player(void *arg0) {
    s32 player;

    bswap_6xB2_play_sound();
    if ((s8) *(u8 *)((s8 *)arg0 + 4) == get_current_floor_area()) {
        if (*(s16 *)((s8 *)arg0 + 6) == 0xFFFF) {
            play_sound_effect(*(s32 *)((s8 *)arg0 + 8), 0, 0, 0);
            return;
        }
        player = (s32)get_player_by_client_id(local_client_id);
        if (player != 0) {
            play_sound_effect(*(s32 *)((s8 *)arg0 + 8), player + 0x38, 0, 0);
        }
    }
}

s32 TLobby::is_camera_state_active() {
    if ((TCameraCtrl__sub_8006A5DC() == 5) || (TCameraCtrl__sub_8006A5DC() == 9)) {
        return 1;
    }
    return 0;
}

void TLobby::set_mode(s32 arg0) {
    switch (arg0) {
    case 0:
        on_set_mode__6TLobbyFv(1);
        break;
    case 1:
        on_set_mode__6TLobbyFv(0);
        break;
    case 2:
        on_set_mode__6TLobbyFv(0);
        break;
    }
    set_mode__6TLobbyFPvi((s32 *)&sound_control_state, arg0);
}

void get_menu_field_280__6TLobbyFv(void) {
    get_field_0x280__6TLobbyFPv((s32 *)(&(*(RecoveredGlobal_8000F7FC_lbl_80515F48 *)&sound_control_state).value));
}

typedef char RecoveredGlobal_80069094_camera_controller_registry_size[sizeof(RecoveredGlobal_80069094_camera_controller_registry) == 0x68 ? 1 : -1];
typedef char RecoveredGlobal_800687E4_TCameraCtrl__data_804FF6C4_size[sizeof(RecoveredGlobal_800687E4_TCameraCtrl__data_804FF6C4) == 0xC ? 1 : -1];
typedef char RecoveredGlobal_800687C8_TCameraCtrl__data_804FF6C4_size[sizeof(RecoveredGlobal_800687C8_TCameraCtrl__data_804FF6C4) == 0xC ? 1 : -1];
void TLobby::set_menu_index_main(u8 *arg0) {
    set_menu_index__6TLobbyFPvi((&(*(RecoveredGlobal_800687E4_TCameraCtrl__data_804FF6C4 *)&sound_control_state).value), (s32)arg0);
}
typedef char RecoveredGlobal_80069024_TCameraCtrl__data_804FF634_size[sizeof(RecoveredGlobal_80069024_TCameraCtrl__data_804FF634) == 0x48 ? 1 : -1];
typedef char RecoveredGlobal_80069024_lbl_804FF67C_size[sizeof(RecoveredGlobal_80069024_lbl_804FF67C) == 0x48 ? 1 : -1];
typedef char RecoveredGlobal_800691C8_TCameraCtrl__data_804FF6D0_size[sizeof(RecoveredGlobal_800691C8_TCameraCtrl__data_804FF6D0) == 0x30 ? 1 : -1];
typedef char RecoveredGlobal_800691C8_TCameraCtrl__data_804FF700_size[sizeof(RecoveredGlobal_800691C8_TCameraCtrl__data_804FF700) == 0xC0 ? 1 : -1];
typedef char RecoveredGlobal_800691C8_main_task_size[sizeof(RecoveredGlobal_800691C8_main_task) == 0x34 ? 1 : -1];
typedef char RecoveredGlobal_80069148_TCameraCtrl__data_804FF6D0_size[sizeof(RecoveredGlobal_80069148_TCameraCtrl__data_804FF6D0) == 0x30 ? 1 : -1];
typedef char RecoveredGlobal_80069148_TCameraCtrl__data_804FF700_size[sizeof(RecoveredGlobal_80069148_TCameraCtrl__data_804FF700) == 0xC0 ? 1 : -1];
typedef char RecoveredGlobal_80069258_TCameraCtrl__data_804FF6D0_size[sizeof(RecoveredGlobal_80069258_TCameraCtrl__data_804FF6D0) == 0x30 ? 1 : -1];
typedef char RecoveredGlobal_80069258_TCameraCtrl__data_804FF700_size[sizeof(RecoveredGlobal_80069258_TCameraCtrl__data_804FF700) == 0xC0 ? 1 : -1];
typedef char RecoveredGlobal_80069258_main_task_size[sizeof(RecoveredGlobal_80069258_main_task) == 0x34 ? 1 : -1];
typedef char RecoveredGlobal_800695E8_TCameraCtrl__data_804FF628_size[sizeof(RecoveredGlobal_800695E8_TCameraCtrl__data_804FF628) == 0xC ? 1 : -1];
typedef char RecoveredGlobal_80069304_TCameraCtrl__data_804FF628_size[sizeof(RecoveredGlobal_80069304_TCameraCtrl__data_804FF628) == 0xC ? 1 : -1];
typedef char RecoveredGlobal_8006961C_TCameraCtrl__data_804FF628_size[sizeof(RecoveredGlobal_8006961C_TCameraCtrl__data_804FF628) == 0xC ? 1 : -1];
typedef char RecoveredGlobal_8006961C_TCameraCtrl__data_804FF634_size[sizeof(RecoveredGlobal_8006961C_TCameraCtrl__data_804FF634) == 0x48 ? 1 : -1];
typedef char RecoveredGlobal_8006961C_lbl_8058CA60_size[sizeof(RecoveredGlobal_8006961C_lbl_8058CA60) == 0x58 ? 1 : -1];
typedef char RecoveredGlobal_80069A6C_camera_controller_registry_size[sizeof(RecoveredGlobal_80069A6C_camera_controller_registry) == 0x68 ? 1 : -1];
typedef char RecoveredGlobal_80069A6C_TCameraCtrl__data_804FF628_size[sizeof(RecoveredGlobal_80069A6C_TCameraCtrl__data_804FF628) == 0xC ? 1 : -1];
typedef char RecoveredGlobal_80069C94_camera_controller_registry_size[sizeof(RecoveredGlobal_80069C94_camera_controller_registry) == 0x68 ? 1 : -1];
typedef char RecoveredGlobal_80069C94_TCameraCtrl__data_804FF628_size[sizeof(RecoveredGlobal_80069C94_TCameraCtrl__data_804FF628) == 0xC ? 1 : -1];
typedef char RecoveredGlobal_80069D04_camera_controller_registry_size[sizeof(RecoveredGlobal_80069D04_camera_controller_registry) == 0x68 ? 1 : -1];
typedef char RecoveredGlobal_80069D04_TCameraCtrl__data_804FF628_size[sizeof(RecoveredGlobal_80069D04_TCameraCtrl__data_804FF628) == 0xC ? 1 : -1];

void release_sound_with_fade(s32 slot) { fade_out_sound_slot(slot, 64); }
void TLobby__sub_80227D38(void) { fade_voice_channels__6TLobbyFi(0); }

s32 normalize_sound_request(u32 arg0, s32 actor, s32 position, s32 arg3, s32 arg4) {
    s32 r;
    s32 m;
    s32 flags;
    s32 v;
    s32 h;
    flags = 0;
    if (position == 0) {
        flags |= 0xE;
    }
    if (arg4 & 1) {
        flags |= 0xC;
    }
    if (arg4 & 2) {
        v = -(s32)((arg0 >> 8U) & 0x7F);
        if (arg3 >= 0) {
            arg3 = 0;
        }
        v += arg3;
    } else {
        v = -(s32)((arg0 >> 8U) & 0x7F);
    }
    if (v < -0x7F) {
        r = -0x7F;
    } else {
        r = v < 0 ? v : 0;
    }
    if (!((arg0 >> 0xFU) & 1)) {
        flags |= 8;
    }
    if (!(arg0 & 0x40000000)) {
        flags |= 0x10;
    }
    m = arg0 & 0xBFFF00FF;
    if (((s32 (*)(void))is_sound_enabled)() == 1) {
        h = alloc_looping_sound_slot(m, actor, (const void *)position, r, flags);
        if (is_special_sound_id(m) != 0) {
            set_sound_slot_special_scale(h, 1.0f);
        }
        return h;
    }
    return -1;
}

s32 play_packed_sound_once(u32 arg0, s32 position, s32 arg2, s32 arg3) {
    s32 r;
    s32 m;
    s32 flags;
    s32 v;
    s32 h;
    flags = 0;
    if (position == 0) {
        flags |= 0xE;
    }
    if (arg3 & 1) {
        flags |= 0xC;
    }
    if (arg3 & 2) {
        v = -(s32)((arg0 >> 8U) & 0x7F);
        if (arg2 >= 0) {
            arg2 = 0;
        }
        v += arg2;
    } else {
        v = -(s32)((arg0 >> 8U) & 0x7F);
    }
    if (v < -0x7F) {
        r = -0x7F;
    } else {
        r = v < 0 ? v : 0;
    }
    if (!((arg0 >> 0xFU) & 1)) {
        flags |= 8;
    }
    if (!(arg0 & 0x40000000)) {
        flags |= 0x10;
    }
    m = arg0 & 0xBFFF00FF;
    if (((s32 (*)(void))is_sound_enabled)() == 1) {
        h = alloc_one_shot_sound_slot(m, (const void *)position, r, flags);
        if (is_special_sound_id(m) != 0) {
            set_sound_slot_special_scale(h, 1.0f);
        }
        return h;
    }
    return -1;
}

void is_sound_enabled(void) {
    is_ready__6TLobbyFPv(&sound_control_state);
}

}


struct RecoveredGlobal_8022804C_lbl_80514F64 {
    s32 value;
    u8 remaining[0xC38];
};

struct RecoveredGlobal_80228074_lbl_80514F64 {
    s32 value;
    u8 remaining[0xC38];
};

struct RecoveredGlobal_8022809C_lbl_80514F64 {
    s32 value;
    u8 remaining[0xC38];
};

struct RecoveredGlobal_802280C4_lbl_80514F64 {
    s32 value;
    u8 remaining[0xC38];
};

extern "C" {
s32 update_sound_frame(void *);
int render_tick__Fv(void);
s32 init_sound_aux_effects(void *);
void TLobby__sub_803382E4(void);
s32 TLobby__sub_803CB81C();
s32 TLobby__sub_80226B64(int);
extern const s32 floor_sound_bank_table[36] = {
    1, 2, 2, 4, 4, 4, 6, 6, 8, 8, 8, 3,
    5, 7, 9, -1, 10, 11, 1, 14, 14, 15, 15, 12,
    12, 12, 12, 12, 16, 16, 13, 17, 18, 21, 19, 20,
};
extern const f32 floor_sound_bank_volume_table[36] = {
    0.0f, 0.0f, 0.0f, 0.5f, 0.4f, 0.3f, 0.2f, 0.2f, 0.35f, 0.35f, 0.35f, 0.1f,
    0.4f, 0.0f, 0.2f, 0.0f, 0.05f, 0.0f, 0.0f, 0.0f, 0.0f, 0.05f, 0.05f, 0.1f,
    0.1f, 0.1f, 0.1f, 0.1f, 0.5f, 0.5f, 0.1f, 0.5f, 0.0f, 0.1f, 0.1f, 0.2f,
};

void TLobby::refresh_render_state() { pop_sound_groups__6TLobbyFPvi((void *)&sound_control_state, (s32)((void*)0)); ((int (*)(float))apply_clamped_field_27c__6TLobbyFv)(0.0f); render_tick__Fv(); }

void load_floor_sound_bank(s32 arg0) {
    s32 temp_r0;
    s32 temp_r31;

    if (arg0 >= 0) {
        temp_r0 = arg0 * 4;
        temp_r31 = *(s32 *)((s8 *)((u8 *)floor_sound_bank_table + temp_r0) + 0);
        if (temp_r31 >= 0) {
            if (arg0 < 0x24) {
                ((s32 (*)(void *, f32))apply_clamped_field_27c__6TLobbyFv)((void *)floor_sound_bank_volume_table, (f32) (*(f32 *)((s8 *)((u8 *)floor_sound_bank_volume_table + temp_r0) + 0)));
            }
            validate_and_set_selection__6TLobbyFPvi((void *)&sound_control_state, (int)temp_r31);
            do {
                TLobby::run_disk_error_check();
                TLobby__sub_803CB81C();
                TLobby::run_frame();
            } while (((s32 (*)(void *))is_ready__6TLobbyFPv)((void *)&sound_control_state) == 0);
            TLobby__sub_80226B64(0);
        }
    }
}

typedef char RecoveredGlobal_8022804C_lbl_80514F64_size[sizeof(RecoveredGlobal_8022804C_lbl_80514F64) == 0xC3C ? 1 : -1];
void TLobby__sub_8022804C(void) {
    TLobby__sub_802401C8(&sound_control_state);
}

typedef char RecoveredGlobal_80228074_lbl_80514F64_size[sizeof(RecoveredGlobal_80228074_lbl_80514F64) == 0xC3C ? 1 : -1];
void update_global_sound_frame(void) {
    update_sound_frame((void *) (&(*(RecoveredGlobal_80228074_lbl_80514F64 *)&sound_control_state).value));
}

typedef char RecoveredGlobal_8022809C_lbl_80514F64_size[sizeof(RecoveredGlobal_8022809C_lbl_80514F64) == 0xC3C ? 1 : -1];
void TLobby__sub_8022809C(void) {
    reset_sound_state__6TLobbyFPv((u8 *)(&(*(RecoveredGlobal_8022809C_lbl_80514F64 *)&sound_control_state).value));
}

typedef char RecoveredGlobal_802280C4_lbl_80514F64_size[sizeof(RecoveredGlobal_802280C4_lbl_80514F64) == 0xC3C ? 1 : -1];
void TLobby::wait_for_sound_init() {
    init_sound_aux_effects((void *) (&(*(RecoveredGlobal_802280C4_lbl_80514F64 *)&sound_control_state).value));
    validate_and_set_selection__6TLobbyFPvi((void *) (&(*(RecoveredGlobal_802280C4_lbl_80514F64 *)&sound_control_state).value), 0);
    do {
        TLobby__sub_803382E4();
        TLobby::run_disk_error_check();
        TLobby__sub_803CB81C();
        render_tick__Fv();
    } while (((s32 (*)())is_sound_enabled)() == 0);
}
}

SoundControlState sound_control_state;
