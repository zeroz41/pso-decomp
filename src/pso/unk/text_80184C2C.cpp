#include "types.h"
#include "pso/unk/text_800F5BC0.h"
#include "pso/unk/text_80184C2C.h"
#include "pso/unk/TLobby.h"
#include "pso/system/BmlResourceDescriptor.h"

int lbl_8050DC20[6];
const s32 lobby_event_theme_id_table[6] = {4, 3, 1, 5, 2, 6};

const char *bm_obj_city_21_model_names[3] = {"ds_obj_21.nj", "ds_obj_21_dai_1.nj", NULL};
const char *bm_obj_city_21_motion_names[2] = {"ds_obj_21.njm", NULL};
BmlResourceDescriptor bm_obj_city_21_resource_descriptor = {
    "bm_obj_city_21.bml", bm_obj_city_21_model_names, bm_obj_city_21_motion_names, 2, 1,
};

const char *bm_obj_city_easter_model_names[3] = {"fs_obj_daiue.nj", "fs_obj_egg.nj", NULL};
const char *bm_obj_city_easter_motion_names[1] = {NULL};
BmlResourceDescriptor bm_obj_city_easter_resource_descriptor = {
    "bm_obj_city_easter.bml", bm_obj_city_easter_model_names, bm_obj_city_easter_motion_names, 2, 0,
};

const char *bm_obj_city_pump_model_names[2] = {"fd_obj_n_pump_obj6.nj", NULL};
const char *bm_obj_city_pump_motion_names[1] = {NULL};
BmlResourceDescriptor bm_obj_city_pump_resource_descriptor = {
    "bm_obj_city_pump.bml", bm_obj_city_pump_model_names, bm_obj_city_pump_motion_names, 1, 0,
};

const char *bm_obj_city_sonic_model_names[5] = {
    "re_b_eggman_body.nj", "re_b_knuckles_body.nj", "re_b_sonic_body.nj", "re_b_tails_body.nj", NULL,
};
const char *bm_obj_city_sonic_motion_names[5] = {
    "wait_eggman_body.njm", "wait_knuckles_body.njm", "wait_sonic_body.njm", "wait_tails_body.njm", NULL,
};
BmlResourceDescriptor bm_obj_city_sonic_resource_descriptor = {
    "bm_obj_city_sonic.bml", bm_obj_city_sonic_model_names, bm_obj_city_sonic_motion_names, 4, 4,
};

const char *bm_obj_city_valen_model_names[4] = {
    "de_obj_heartstar_01_1.nj", "de_obj_heartstar_02_1.nj", "ds_obj_heart_dai_1.nj", NULL,
};
const char *bm_obj_city_valen_motion_names[4] = {
    "de_obj_heartstar_01_1.njm", "de_obj_heartstar_02_1.njm", "ds_obj_heart_dai_1.njm", NULL,
};
BmlResourceDescriptor bm_obj_city_valen_resource_descriptor = {
    "bm_obj_city_valen.bml", bm_obj_city_valen_model_names, bm_obj_city_valen_motion_names, 3, 3,
};

const char *bm_obj_city_xmas_model_names[11] = {
    "de_obj_o_aircar01_xmas.nj", "de_obj_o_aircar02_xmas.nj", "de_obj_o_aircar03_xmas.nj",
    "de_obj_o_aircar04_xmas.nj", "de_obj_o_aircar05_xmas.nj", "fd_obj_n_leas_bmerge1.nj",
    "fd_obj_n_tree_cyl199.nj",   "fd_obj_n_tree_cyl200.nj",   "fd_obj_n_tree_cyl201.nj",
    "fd_obj_n_tree_obj2.nj",     NULL,
};
const char *bm_obj_city_xmas_motion_names[3] = {"fd_obj_n_tree_cyl199.njm", "fd_obj_n_tree_cyl200.njm", NULL};
BmlResourceDescriptor bm_obj_city_xmas_resource_descriptor = {
    "bm_obj_city_xmas.bml", bm_obj_city_xmas_model_names, bm_obj_city_xmas_motion_names, 10, 2,
};

const char *bm_obj_city_board_normal_model_names[3] = {"fd_obj_n_keijiban_board_n.nj", "fd_obj_n_keijiban_hasira_n.nj", NULL};
const char *bm_obj_city_board_normal_motion_names[1] = {NULL};
BmlResourceDescriptor bm_obj_city_board_normal_resource_descriptor = {
    "bm_obj_city_board_normal.bml", bm_obj_city_board_normal_model_names, bm_obj_city_board_normal_motion_names, 2, 0,
};

const char *bm_obj_city_board_xmas_model_names[3] = {"fd_obj_n_keijiban_board_x.nj", "fd_obj_n_keijiban_hasira_x.nj", NULL};
const char *bm_obj_city_board_xmas_motion_names[1] = {NULL};
BmlResourceDescriptor bm_obj_city_board_xmas_resource_descriptor = {
    "bm_obj_city_board_xmas.bml", bm_obj_city_board_xmas_model_names, bm_obj_city_board_xmas_motion_names, 2, 0,
};

const char *bm_obj_city_board_2001_model_names[3] = {"fd_obj_n_keijiban_board_y.nj", "fd_obj_n_keijiban_hasira_y.nj", NULL};
const char *bm_obj_city_board_2001_motion_names[1] = {NULL};
BmlResourceDescriptor bm_obj_city_board_2001_resource_descriptor = {
    "bm_obj_city_board_2001.bml", bm_obj_city_board_2001_model_names, bm_obj_city_board_2001_motion_names, 2, 0,
};

// inferred: indexed by the active season slot (lobby_event_theme_id_table order)
BmlResourceDescriptor *city_season_resource_descriptors[6] = {
    &bm_obj_city_easter_resource_descriptor, &bm_obj_city_valen_resource_descriptor,
    &bm_obj_city_xmas_resource_descriptor,   &bm_obj_city_pump_resource_descriptor,
    &bm_obj_city_21_resource_descriptor,     &bm_obj_city_sonic_resource_descriptor,
};
extern s32 TLobby__event_theme_id;
extern "C" {
void free_bin_model_request(void *, s32);
int city_season_easter_egg_model_table[6];
int city_season_xmas_model_table[6];
s32 lbl_805D5B30;
void *lbl_805D5B34;
void *lbl_805D5B38;
s32 lbl_805D5B3C;
s32 lbl_805D5B40;
s32 lbl_805D5B44;
void *lbl_805D5B48;

int TLobby__sub_80184C2C(int a0) {  return city_season_xmas_model_table[a0]; }
}

int get_season_model_resource(int a0) {  return city_season_easter_egg_model_table[a0]; }

u8 TLobby__sub_80184C54(void) {
    return (u8) (lbl_805D5B30 != -1);
}

int TLobby__sub_80184C6C(int a0) {  return lbl_8050DC20[a0]; }

void TLobby__sub_80184C80(void *p) {
    s32 i;
    TLobby::clear_global_array(p);
    for (i = 0; i < 6; i++) {
        if (TLobby__event_theme_id == lobby_event_theme_id_table[i]) {
            lbl_8050DC20[i] = 1;
            return;
        }
    }
}

void TLobby__sub_80184CE0(void* p) { TLobby::clear_global_array(p); }
void TLobby::clear_global_array(void* _w0) {
    s32 i;
    for (i = 0; i < 6; i++) {
        ((s32 *)&lbl_8050DC20)[i] = 0;
    }
}

void TLobby::free_buffers() {
    s32 i;
    if (lbl_805D5B48 != NULL) {
        destroy_buffer_pair(lbl_805D5B48, 1);
        lbl_805D5B48 = NULL;
    }
    if (lbl_805D5B38 != NULL) {
        free_bin_model_request(lbl_805D5B38, 1);
        lbl_805D5B38 = NULL;
    }
    lbl_805D5B44 = 0;
    lbl_805D5B3C = 0;
    lbl_805D5B40 = 0;
    if (lbl_805D5B34 != NULL) {
        destroy_buffer_pair(lbl_805D5B34, 1);
        lbl_805D5B34 = NULL;
    }
    for (i = 5; i >= 0; i--) {
        if ((u32)city_season_easter_egg_model_table[i] != 0) {
            free_bin_model_request((void *)city_season_easter_egg_model_table[i], 1);
        }
        city_season_easter_egg_model_table[i] = 0;
        city_season_xmas_model_table[i] = 0;
    }
}

extern "C" s32 get_main_phase(void);
extern "C" void *load_resource_from_descriptor(void *, s32, BmlResourceDescriptor *, s32, s32, s32);
extern "C" void clear_global_array__6TLobbyFPv();

extern "C" void TLobby__sub_80184DF4(void) {
    s32 i;
    s32 count;
    u8 *board;
    u8 *tmp;
    u8 *base;
    u8 *ent;
    s32 ph;
    void *p;
    s32 off;

    clear_global_array__6TLobbyFPv();
    ph = get_main_phase();
    if (ph == 0xf) {
        TLobby__sub_80184C80((void *)ph);
    } else {
        TLobby__sub_80184CE0((void *)ph);
    }
    lbl_805D5B30 = -1;
    for (i = 0; i < 6; i++) {
        if (TLobby__sub_80184C6C(i)) {
            lbl_805D5B30 = i;
            break;
        }
    }
    if (lbl_805D5B30 != -1) {
        {
            s32 j;
            for (j = 0; j < 6; j++) {
                city_season_easter_egg_model_table[j] = 0;
                city_season_xmas_model_table[j] = 0;
            }
        }
        tmp = (u8 *)::operator new(0x440);
        if (tmp != NULL) {
            tmp = (u8 *)load_resource_from_descriptor(tmp, 1, city_season_resource_descriptors[lbl_805D5B30], 0, 0, 0);
        }
        off = lbl_805D5B30 * 4;
        *(s32 *)((u8 *)city_season_easter_egg_model_table + off) = (int)tmp;
        for (i = 0; i < *(s32 *)(tmp + 0x434); i++) {
            if ((*(u32 (**)[4])(tmp + 0x42c))[i][3] != 0) {
                *(s32 *)((u8 *)city_season_xmas_model_table + off) = (*(u32 (**)[4])(tmp + 0x42c))[i][3];
                break;
            }
        }
        if (lbl_805D5B30 == 0) {
            base = *(u8 **)(tmp + 0x42c);
            ent = *(u8 **)(base + 0x18);
            tmp = (u8 *)::operator new(0x14);
            if (tmp != NULL) tmp = (u8 *)((TLobby *)tmp)->alloc_tables((s32)ent, 3);
            lbl_805D5B34 = tmp;
            base = *(u8 **)(*(u8 **)(ent + 0x2c) + 4);
            base = *(u8 **)(base + 4);
            *(s16 *)(base + 0xc) &= ~0x1000;
        } else if (lbl_805D5B30 == 4) {
            base = *(u8 **)(tmp + 0x42c);
            ent = *(u8 **)(base + 0x18);
            tmp = (u8 *)::operator new(0x14);
            if (tmp != NULL) tmp = (u8 *)((TLobby *)tmp)->alloc_tables((s32)ent, 0);
            lbl_805D5B34 = tmp;
            base = *(u8 **)(*(u8 **)(ent + 0x2c) + 4);
            base = *(u8 **)(base + 4);
            *(s16 *)(base + 0xc) &= ~0x1000;
        } else {
            lbl_805D5B34 = NULL;
        }
    }

    if (lbl_805D5B30 == 2) {
        u8 *r = (u8 *)::operator new(0x440);
        if (r != NULL) {
            r = (u8 *)load_resource_from_descriptor(r, 1, &bm_obj_city_board_xmas_resource_descriptor, 0, 0, 0);
        }
        board = r;
        lbl_805D5B3C = *(s32 *)(*(u8 **)(r + 0x42c) + 8);
        lbl_805D5B40 = *(s32 *)(*(u8 **)(r + 0x42c) + 0x18);
    } else if (lbl_805D5B30 == 4) {
        u8 *r = (u8 *)::operator new(0x440);
        if (r != NULL) {
            r = (u8 *)load_resource_from_descriptor(r, 1, &bm_obj_city_board_2001_resource_descriptor, 0, 0, 0);
        }
        board = r;
        lbl_805D5B3C = *(s32 *)(*(u8 **)(r + 0x42c) + 8);
        lbl_805D5B40 = *(s32 *)(*(u8 **)(r + 0x42c) + 0x18);
    } else {
        u8 *r = (u8 *)::operator new(0x440);
        if (r != NULL) {
            r = (u8 *)load_resource_from_descriptor(r, 1, &bm_obj_city_board_normal_resource_descriptor, 0, 0, 0);
        }
        board = r;
        lbl_805D5B3C = *(s32 *)(*(u8 **)(r + 0x42c) + 8);
        lbl_805D5B40 = *(s32 *)(*(u8 **)(r + 0x42c) + 0x18);
    }

    tmp = (u8 *)::operator new(0x14);
    if (tmp != NULL) tmp = (u8 *)((TLobby *)tmp)->alloc_tables((s32)(void *)lbl_805D5B3C, 2);
    lbl_805D5B48 = tmp;
    base = (u8 *)lbl_805D5B3C;
    base = *(u8 **)(base + 4);
    base = *(u8 **)(base + 4);
    *(s16 *)(base + 0xc) &= ~0x2000;
    lbl_805D5B38 = board;
    for (i = 0; i < *(s32 *)(board + 0x434); i++) {
        if ((*(u32 (**)[4])(board + 0x42c))[i][3] != 0) {
            lbl_805D5B44 = (*(u32 (**)[4])(board + 0x42c))[i][3];
            break;
        }
    }
}
