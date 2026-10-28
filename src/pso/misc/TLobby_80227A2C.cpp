#include "types.h"
#include "pso/misc/TLobby.h"
#include "pso/item/TUnk_804CC048.h"
#include "pso/map/FloorArea.h"
#include "pso/misc/TLobby_80207644.h"

struct RecoveredGlobal_80227AA8_lbl_80514F64 {
    s32 value;
    u8 remaining[0xC38];
};

extern "C" {
void get_menu_field_280__6TLobbyFv(void);
void fn_8023F660(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern unsigned char sound_control_state[];
void TLobby__sub_80227AA8(s32 arg0);
int free__6TLobbyFPv(void* p);
int TLobby__sub_80227A4C(void* p);
void TLobby__sub_80227A6C(void);
int TLobby__sub_80227A70(void* p);
void TLobby__sub_80227A90(void);
void TLobby__sub_80227A94(void);
int get_music_base_gain(void);
void TLobby__sub_8022804C(void);
int xfree__FPv(void*);
int xmalloc__FUl(void*);

int free__6TLobbyFPv(void* p) { return xfree__FPv(p); }
int TLobby__sub_80227A4C(void* p) { return xmalloc__FUl(p); }
void TLobby__sub_80227A6C(void) {  }
int TLobby__sub_80227A70(void* p) { return ((int (*)(void*))TLobby__sub_8022804C)(p); }
void TLobby__sub_80227A90(void) {  }

    extern int lbl_805D3710;
    extern int lbl_805D6314;
void TLobby__sub_80227A94(void) { lbl_805D6314 = lbl_805D3710; }

    extern int music_stream_base_gain;
int get_music_base_gain(void) {  return music_stream_base_gain; }
typedef char RecoveredGlobal_80227AA8_lbl_80514F64_size[sizeof(RecoveredGlobal_80227AA8_lbl_80514F64) == 0xC3C ? 1 : -1];
void TLobby__sub_80227AA8(s32 arg0) {
    fn_8023F660((&(*(RecoveredGlobal_80227AA8_lbl_80514F64 *)sound_control_state).value), (arg0), (((s32 (*)())get_menu_field_280__6TLobbyFv)() + 0x55), 0x40, 0x40, 0);
}

}

__declspec(section ".ctors") static void *const __sinit_TLobby_80227A2C_80227A2C_cpp_ref = (void *)TLobby__sub_80227A94;

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
#include "pso/misc/TScene.h"
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
s32 set_clamped_field27c__6TLobbyFPvf(s32 *);
void apply_clamped_field_27c__6TLobbyFv(void);
s32 get_field_0x280__6TLobbyFPv(void *p);
void set_menu_index__6TLobbyFPvi(void *p, s32 v);
s32 is_ready__6TLobbyFPv(s32 *);
void is_sound_enabled(void);
s32 is_special_sound_id(u32 x);
void set_sound_slot_special_scale(s32 slot, f32 scale);
s32 alloc_looping_sound_slot(u32 id, s32 actor, const void *position, s32 base, s32 flags);
extern const f32 lbl_805DC768;
s32 normalize_sound_request(u32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
s32 alloc_one_shot_sound_slot(u32 id, const void *position, s32 base, s32 flags);
s32 play_packed_sound_once(u32 arg0, s32 arg1, s32 arg2, s32 arg3);
int TLobby__sub_80227AF8(void* p);
int release_sound_with_fade(void* p);
int TLobby__sub_80227D38(void);
void handle_6xB2_play_sound_from_player(void *arg0);
s32 play_sound_effect(s32, s32, s32, s32);
u16 TCameraCtrl__sub_8006A5DC();
int TLobby__sub_8023F754(void*);
int fade_out_sound_slot(void*, int);
int fade_voice_channels__6TLobbyFi(void*);
void *get_player_by_client_id(s32 i);
s32 bswap_6xB2_play_sound();
s32 on_set_mode__6TLobbyFv(s32);
void set_mode__6TLobbyFPvi(void *arg0, s32 arg1);

int TLobby__sub_80227AF8(void* p) { return TLobby__sub_8023F754(p); }

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

void apply_clamped_field_27c__6TLobbyFv(void) {
    set_clamped_field27c__6TLobbyFPvf((s32 *)(&(*(RecoveredGlobal_8000F7FC_lbl_80515F48 *)&sound_control_state).value));
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
    set_mode__6TLobbyFPvi((s32 *)sound_control_state, arg0);
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

int release_sound_with_fade(void* p) { return fade_out_sound_slot(p, 64); }
int TLobby__sub_80227D38(void) { return fade_voice_channels__6TLobbyFi((void*)(0)); }

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
            set_sound_slot_special_scale(h, lbl_805DC768);
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
            set_sound_slot_special_scale(h, lbl_805DC768);
        }
        return h;
    }
    return -1;
}

void is_sound_enabled(void) {
    is_ready__6TLobbyFPv((s32 *)(&(*(RecoveredGlobal_8000F7FC_lbl_80515F48 *)&sound_control_state).value));
}

}

struct RecoveredGlobal_80228634_lbl_804CBE98 {
    s32 value;
    u8 remaining[0x1AC];
};

struct RecoveredGlobal_80228754_lbl_804CBE98 {
    s32 value;
    u8 remaining[0x1AC];
};

struct RecoveredGlobal_802286C4_lbl_804CBE98 {
    s32 value;
    u8 remaining[0x1AC];
};

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

struct RecoveredGlobal_802287F0_lbl_80515BA0 {
    s32 value;
    u8 remaining[0x24];
};

struct O_80228A74 { u8 pad[0x1c]; char names[1][0x20]; };

struct P_80228A74 { u8 pad[0x109c]; s32 count; };

struct L_8022884C { u8 pad[0x109c]; s32 count; s32 hi; s32 lo; };

extern "C" {
s32 select_area_entrance(void *arg0);
s32 lookup_scene_object__6TLobbyFPv(s32, void *);
extern RecoveredGlobal_80228634_lbl_804CBE98 area_initializer_dispatch_table;
void run_area_scene_cleanup(u8 *arg0);
void promote_area_floor(u8 *arg0);
void load_area_scene_and_init(u8 *arg0);
s32 TLobby__sub_802401C8(void *);
s32 update_sound_frame(void *);
void update_global_sound_frame(void);
s32 reset_sound_state__6TLobbyFPv(u8 *arg0);
void TLobby__sub_8022809C(void);
int render_tick__Fv(void);
s32 init_sound_aux_effects(void *);
s32 validate_and_set_selection__6TLobbyFPvi(void *, int);
void TLobby__sub_803382E4(void);
s32 TLobby__sub_803CB81C();
extern RecoveredGlobal_802287F0_lbl_80515BA0 lbl_80515BA0;
void *reset_sound_owner_state(void *self);
void *TLobby__sub_80240808(void *arg0, s16 arg1);
void *__register_global_object(void *obj, void *dtor, void *entry);
extern char lbl_80514F58[];
void TLobby__sub_80228118(void);
char *strcpy(char *dst, const char *src);
void clear_work_buffer(u8 *arg0);
extern char lbl_805DC788[4];
u32 strlen(const char *s);
s32 debug_printf_at(u32, void *, ...);
s32 TLobby__sub_80226B64(int);
extern s32 floor_sound_bank_table[];
extern s32 floor_sound_bank_volume_table[];
void load_floor_sound_bank(s32 arg0);
s32 get_floor_map_terrain(s32);
s32 pop_sound_groups__6TLobbyFPvi(void *p, s32 arg1);
void __ct__7TObjectFP7TObject(void *);
void memset(void *, int, int);

    extern float lbl_805DC76C;
void TLobby::refresh_render_state() { pop_sound_groups__6TLobbyFPvi((void *)sound_control_state, (s32)((void*)0)); ((int (*)(float))apply_clamped_field_27c__6TLobbyFv)(lbl_805DC76C); render_tick__Fv(); }

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
            validate_and_set_selection__6TLobbyFPvi((void *)sound_control_state, (int)temp_r31);
            do {
                TLobby::run_disk_error_check();
                TLobby__sub_803CB81C();
                TLobby::run_frame();
            } while (((s32 (*)(void *))is_ready__6TLobbyFPv)((void *)sound_control_state) == 0);
            TLobby__sub_80226B64(0);
        }
    }
}

typedef char RecoveredGlobal_8022804C_lbl_80514F64_size[sizeof(RecoveredGlobal_8022804C_lbl_80514F64) == 0xC3C ? 1 : -1];
void TLobby__sub_8022804C(void) {
    s32 *var_r3;
    var_r3 = (s32 *)(&(*(RecoveredGlobal_8022804C_lbl_80514F64 *)&sound_control_state).value);
    var_r3 = (s32 *)(&(*(RecoveredGlobal_8022804C_lbl_80514F64 *)&sound_control_state).value);
    TLobby__sub_802401C8((void *) (&(*(RecoveredGlobal_8022804C_lbl_80514F64 *)&sound_control_state).value));
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

void TLobby__sub_80228118(void) {
    __register_global_object(reset_sound_owner_state(((char *)&sound_control_state)), (void *)TLobby__sub_80240808, lbl_80514F58);
}

void TLobby::clear_ready_flag_unless_locked() {
    if (get_current_floor_area() != AREA_LOBBY) {
        *(s32 *)((s8 *)this + 0x20) = (s32) (*(s32 *)((s8 *)this + 0x20) & 0xFFFFFFFE);
    }
}

void TLobby::set_area(s32 arg1) {
    *(s32 *)&this->m_next = arg1;
    *(s32 *)((s8 *)this + 0x18) = get_floor_map_terrain(*(s32 *)&this->m_next);
}

#pragma push
#pragma fp_contract on
s32 select_area_entrance(void *arg0) {
    s32 temp_r0;
    s32 temp_r3;
    if ((s32) *(s32 *)((s8 *)arg0 + 0) > 0x11) {
        return 4;
    }
    if (*(s32 *)((s8 *)arg0 + 0x20) & 1) {
        return 2;
    }
    if ((TLobby::get_instance() == 0) && (get_floor_area(*(s32 *)((s8 *)arg0 + 0)) == 0xD)) {
        switch (get_floor_area(*(s32 *)((s8 *)arg0 + 4))) {
        case 8:
        case 9:
        case 10:
            return 1;
        default:
            return 0;
        }
    }
    temp_r0 = *(s32 *)((s8 *)arg0 + 4) - *(s32 *)((s8 *)arg0 + 0);
    if (temp_r0 >= 0) {
        return 1;
    }
    return (temp_r0 < 0) ? 0 : 4;
}
#pragma pop

typedef char RecoveredGlobal_80228634_lbl_804CBE98_size[sizeof(RecoveredGlobal_80228634_lbl_804CBE98) == 0x1B0 ? 1 : -1];
void run_area_scene_cleanup(u8 *arg0) {
    s32 sp8;
    s32 (*var_r12)(s32);
    s32 *var_r4;
    s32 var_r3;
    u8 *var_r31;
    var_r4 = &sp8;
    var_r31 = arg0;
    var_r3 = *(s32 *)((s8 *)arg0 + 4);
    if (lookup_scene_object__6TLobbyFPv(var_r3, var_r4) != 0) {
        var_r3 = (s32) &area_initializer_dispatch_table.value;
        var_r3 = (s32) &area_initializer_dispatch_table.value;
        var_r3 += sp8 * 0xC;
        var_r12 = *(s32 (**)(s32))((s8 *)var_r3 + 8);
        var_r12(var_r3);
    } else {
        var_r3 = (s32) &area_initializer_dispatch_table.value;
        var_r3 = (s32) &area_initializer_dispatch_table.value;
        var_r3 += *(s32 *)((s8 *)var_r31 + 4) * 0xC;
        var_r12 = *(s32 (**)(s32))((s8 *)var_r3 + 8);
        var_r12(var_r3);
    }
    *(s32 *)((s8 *)var_r31 + 4) = 0;
    *(s32 *)((s8 *)var_r31 + 8) = 0;
    *(s32 *)((s8 *)var_r31 + 0xC) = 0;
}

typedef char RecoveredGlobal_80228754_lbl_804CBE98_size[sizeof(RecoveredGlobal_80228754_lbl_804CBE98) == 0x1B0 ? 1 : -1];

typedef char RecoveredGlobal_802286C4_lbl_804CBE98_size[sizeof(RecoveredGlobal_802286C4_lbl_804CBE98) == 0x1B0 ? 1 : -1];
void load_area_scene_and_init(u8 *arg0) {
    s32 sp8;
    s32 (*var_r12)(s32);
    s32 *var_r4;
    s32 var_r3;
    u8 *var_r31;
    var_r31 = arg0;
    var_r3 = *(s32 *)((s8 *)arg0 + 4);
    set_current_floor_area((var_r3));
    var_r3 = *(s32 *)((s8 *)var_r31 + 0x10);
    TScene::set_scene(var_r3);
    var_r3 = *(s32 *)((s8 *)var_r31 + 4);
    var_r4 = &sp8;
    if (lookup_scene_object__6TLobbyFPv(var_r3, var_r4) != 0) {
        var_r3 = (s32) &(*(RecoveredGlobal_802286C4_lbl_804CBE98 *)&area_initializer_dispatch_table).value;
        var_r3 = (s32) &(*(RecoveredGlobal_802286C4_lbl_804CBE98 *)&area_initializer_dispatch_table).value;
        var_r3 += sp8 * 0xC;
        var_r12 = *(s32 (**)(s32))((s8 *)var_r3 + 4);
        var_r12(var_r3);
        return;
    }
    var_r3 = (s32) &(*(RecoveredGlobal_802286C4_lbl_804CBE98 *)&area_initializer_dispatch_table).value;
    var_r3 = (s32) &(*(RecoveredGlobal_802286C4_lbl_804CBE98 *)&area_initializer_dispatch_table).value;
    var_r3 += *(s32 *)((s8 *)var_r31 + 4) * 0xC;
    var_r12 = *(s32 (**)(s32))((s8 *)var_r3 + 4);
    var_r12(var_r3);
}

void promote_area_floor(u8 *arg0) {
    s32 sp8;
    s32 (*var_r12)(s32);
    s32 *var_r4;
    s32 var_r3;
    u8 *var_r31;
    var_r4 = &sp8;
    var_r31 = arg0;
    var_r3 = *(s32 *)((s8 *)arg0 + 4);
    if (lookup_scene_object__6TLobbyFPv(var_r3, var_r4) != 0) {
        var_r3 = (s32) &(*(RecoveredGlobal_80228754_lbl_804CBE98 *)&area_initializer_dispatch_table).value;
        var_r3 = (s32) &(*(RecoveredGlobal_80228754_lbl_804CBE98 *)&area_initializer_dispatch_table).value;
        var_r3 += sp8 * 0xC;
        var_r12 = *(s32 (**)(s32))((s8 *)var_r3 + 8);
        var_r12(var_r3);
    } else {
        var_r3 = (s32) &(*(RecoveredGlobal_80228754_lbl_804CBE98 *)&area_initializer_dispatch_table).value;
        var_r3 = (s32) &(*(RecoveredGlobal_80228754_lbl_804CBE98 *)&area_initializer_dispatch_table).value;
        var_r3 += *(s32 *)((s8 *)var_r31 + 4) * 0xC;
        var_r12 = *(s32 (**)(s32))((s8 *)var_r3 + 8);
        var_r12(var_r3);
    }
    *(s32 *)((s8 *)var_r31 + 0) = (s32) *(s32 *)((s8 *)var_r31 + 4);
    *(s32 *)((s8 *)var_r31 + 4) = (s32) *(s32 *)((s8 *)var_r31 + 0xC);
    *(s32 *)((s8 *)var_r31 + 0x10) = (s32) *(s32 *)((s8 *)var_r31 + 0x18);
    TLobby::reset_story_select_state();
}

typedef char RecoveredGlobal_802287F0_lbl_80515BA0_size[sizeof(RecoveredGlobal_802287F0_lbl_80515BA0) == 0x28 ? 1 : -1];
s32 TLobby::init_range_zero_global() { return ((TLobby *)((s32) &lbl_80515BA0.value))->init_range_zero(); }

s32 TLobby::init_range_zero() {
    init_range(0);
    return (s32)this;
}

struct O_80228A74;

#pragma push
#pragma opt_propagation off
void TUnk_804CC048::render() {
    L_8022884C *self = (L_8022884C *)this;
    s32 off;
    s32 i;
    s32 t;
    i = 0;
    off = 0;
    while (i < self->count) {
        t = off + 0x1c;
        debug_printf_at((self->hi << 16) | (self->lo + i), (u8 *)self + t);
        i++;
        off += 0x20;
    }
}
#pragma pop

void TLobby::tokenize_args(char *s) {
    char *start;
    s32 quoted;
    clear_work_buffer((u8 *)this);
    start = s;
    quoted = 0;
    for (;;) {
        switch (*s) {
        case 0:
            this->add_token(start);
            return;
        case '"':
            if (quoted) {
                quoted = 0;
                *s = 0;
                s++;
            } else {
                s++;
                quoted = 1;
                start = s;
            }
            break;
        case '\t':
        case '\n':
            if (quoted) {
                s++;
            } else {
                *s = 0;
                s++;
                this->add_token(start);
                start = s;
            }
            break;
        default:
            s++;
            break;
        }
    }
}

void TLobby::parse_csv_line(char *s) {
    char *start;
    s32 quoted;
    clear_work_buffer((u8 *)this);
    start = s;
    quoted = 0;
    for (;;) {
        switch (*s) {
        case 0:
            this->add_token(start);
            return;
        case '"':
            if (quoted) {
                quoted = 0;
                *s = 0;
                s++;
            } else {
                s++;
                quoted = 1;
                start = s;
            }
            break;
        case '\t':
        case '\n':
        case ',':
            if (quoted) {
                s++;
            } else {
                *s = 0;
                s++;
                this->add_token(start);
                start = s;
            }
            break;
        default:
            s++;
            break;
        }
    }
}

void TLobby::add_token(const char *src) {
    O_80228A74 *self = (O_80228A74 *)this;
    strcpy(self->names[((P_80228A74 *)self)->count++], src);
}

void clear_work_buffer(u8 *arg0) {
    memset(arg0 + 0x1C, 0, 0x1000);
    *(s32 *)((s8 *)arg0 + 0x109C) = 0;
}

extern s32 lbl_804CC048[];

void *TUnk_804CC048::construct(void *arg1, void *arg2, void *arg3) {
    __ct__7TObjectFP7TObject(this);
    *(s32 **)((s8 *)this + 0x18) = lbl_804CC048;
    *(void **)((s8 *)this + 0x10A0) = arg2;
    this->m_10a4 = arg3;
    memset((void *)((void *)((char *)this + 28)), 0, 4096);
    this->m_109c = 0;
    return this;
}
void TLobby::trim_whitespace() {
    char *s = (char *)this;
    s32 len = strlen(s);
    s32 i;
    for (i = 0; i <= len && ((u8 *)s)[i] <= ' '; i++) {
    }
    if (i > len) {
        strcpy(s, lbl_805DC788);
    } else {
        for (; ((u8 *)s)[len] <= ' '; len--) {
            s[len] = 0;
        }
        strcpy(s, s + i);
    }
}

}
