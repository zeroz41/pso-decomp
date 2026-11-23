#include "pso/system/BmlResource.h"
#include "types.h"
#include "pso/render/StripBufferPair.h"
#include "pso/unk/text_80184C2C.h"
#include "pso/unk/TLobby.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"

int lbl_8050DC20[6];
const s32 lobby_event_theme_id_table[6] = {4, 3, 1, 5, 2, 6};

static __declspec(section ".rodata") const char ds_obj_21_nj[] ATTRIBUTE_ALIGN(4) = "ds_obj_21.nj";
static __declspec(section ".rodata") const char ds_obj_21_dai_1_nj[] ATTRIBUTE_ALIGN(4) = "ds_obj_21_dai_1.nj";
static __declspec(section ".rodata") const char ds_obj_21_njm[] ATTRIBUTE_ALIGN(4) = "ds_obj_21.njm";
static __declspec(section ".rodata") const char bm_obj_city_21_bml[] ATTRIBUTE_ALIGN(4) = "bm_obj_city_21.bml";
static __declspec(section ".rodata") const char fs_obj_daiue_nj[] ATTRIBUTE_ALIGN(4) = "fs_obj_daiue.nj";
static __declspec(section ".rodata") const char fs_obj_egg_nj[] ATTRIBUTE_ALIGN(4) = "fs_obj_egg.nj";
static __declspec(section ".rodata") const char bm_obj_city_easter_bml[] ATTRIBUTE_ALIGN(4) = "bm_obj_city_easter.bml";
static __declspec(section ".rodata") const char fd_obj_n_pump_obj6_nj[] ATTRIBUTE_ALIGN(4) = "fd_obj_n_pump_obj6.nj";
static __declspec(section ".rodata") const char bm_obj_city_pump_bml[] ATTRIBUTE_ALIGN(4) = "bm_obj_city_pump.bml";
static __declspec(section ".rodata") const char re_b_eggman_body_nj[] ATTRIBUTE_ALIGN(4) = "re_b_eggman_body.nj";
static __declspec(section ".rodata") const char re_b_knuckles_body_nj[] ATTRIBUTE_ALIGN(4) = "re_b_knuckles_body.nj";
static __declspec(section ".rodata") const char re_b_sonic_body_nj[] ATTRIBUTE_ALIGN(4) = "re_b_sonic_body.nj";
static __declspec(section ".rodata") const char re_b_tails_body_nj[] ATTRIBUTE_ALIGN(4) = "re_b_tails_body.nj";
static __declspec(section ".rodata") const char wait_eggman_body_njm[] ATTRIBUTE_ALIGN(4) = "wait_eggman_body.njm";
static __declspec(section ".rodata") const char wait_knuckles_body_njm[] ATTRIBUTE_ALIGN(4) = "wait_knuckles_body.njm";
static __declspec(section ".rodata") const char wait_sonic_body_njm[] ATTRIBUTE_ALIGN(4) = "wait_sonic_body.njm";
static __declspec(section ".rodata") const char wait_tails_body_njm[] ATTRIBUTE_ALIGN(4) = "wait_tails_body.njm";
static __declspec(section ".rodata") const char bm_obj_city_sonic_bml[] ATTRIBUTE_ALIGN(4) = "bm_obj_city_sonic.bml";
static __declspec(section ".rodata") const char de_obj_heartstar_01_1_nj[] ATTRIBUTE_ALIGN(4) = "de_obj_heartstar_01_1.nj";
static __declspec(section ".rodata") const char de_obj_heartstar_02_1_nj[] ATTRIBUTE_ALIGN(4) = "de_obj_heartstar_02_1.nj";
static __declspec(section ".rodata") const char ds_obj_heart_dai_1_nj[] ATTRIBUTE_ALIGN(4) = "ds_obj_heart_dai_1.nj";
static __declspec(section ".rodata") const char de_obj_heartstar_01_1_njm[] ATTRIBUTE_ALIGN(4) = "de_obj_heartstar_01_1.njm";
static __declspec(section ".rodata") const char de_obj_heartstar_02_1_njm[] ATTRIBUTE_ALIGN(4) = "de_obj_heartstar_02_1.njm";
static __declspec(section ".rodata") const char ds_obj_heart_dai_1_njm[] ATTRIBUTE_ALIGN(4) = "ds_obj_heart_dai_1.njm";
static __declspec(section ".rodata") const char bm_obj_city_valen_bml[] ATTRIBUTE_ALIGN(4) = "bm_obj_city_valen.bml";
static __declspec(section ".rodata") const char de_obj_o_aircar01_xmas_nj[] ATTRIBUTE_ALIGN(4) = "de_obj_o_aircar01_xmas.nj";
static __declspec(section ".rodata") const char de_obj_o_aircar02_xmas_nj[] ATTRIBUTE_ALIGN(4) = "de_obj_o_aircar02_xmas.nj";
static __declspec(section ".rodata") const char de_obj_o_aircar03_xmas_nj[] ATTRIBUTE_ALIGN(4) = "de_obj_o_aircar03_xmas.nj";
static __declspec(section ".rodata") const char de_obj_o_aircar04_xmas_nj[] ATTRIBUTE_ALIGN(4) = "de_obj_o_aircar04_xmas.nj";
static __declspec(section ".rodata") const char de_obj_o_aircar05_xmas_nj[] ATTRIBUTE_ALIGN(4) = "de_obj_o_aircar05_xmas.nj";
static __declspec(section ".rodata") const char fd_obj_n_leas_bmerge1_nj[] ATTRIBUTE_ALIGN(4) = "fd_obj_n_leas_bmerge1.nj";
static __declspec(section ".rodata") const char fd_obj_n_tree_cyl199_nj[] ATTRIBUTE_ALIGN(4) = "fd_obj_n_tree_cyl199.nj";
static __declspec(section ".rodata") const char fd_obj_n_tree_cyl200_nj[] ATTRIBUTE_ALIGN(4) = "fd_obj_n_tree_cyl200.nj";
static __declspec(section ".rodata") const char fd_obj_n_tree_cyl201_nj[] ATTRIBUTE_ALIGN(4) = "fd_obj_n_tree_cyl201.nj";
static __declspec(section ".rodata") const char fd_obj_n_tree_obj2_nj[] ATTRIBUTE_ALIGN(4) = "fd_obj_n_tree_obj2.nj";
static __declspec(section ".rodata") const char fd_obj_n_tree_cyl199_njm[] ATTRIBUTE_ALIGN(4) = "fd_obj_n_tree_cyl199.njm";
static __declspec(section ".rodata") const char fd_obj_n_tree_cyl200_njm[] ATTRIBUTE_ALIGN(4) = "fd_obj_n_tree_cyl200.njm";
static __declspec(section ".rodata") const char bm_obj_city_xmas_bml[] ATTRIBUTE_ALIGN(4) = "bm_obj_city_xmas.bml";
static __declspec(section ".rodata") const char fd_obj_n_keijiban_board_n_nj[] ATTRIBUTE_ALIGN(4) = "fd_obj_n_keijiban_board_n.nj";
static __declspec(section ".rodata") const char fd_obj_n_keijiban_hasira_n_nj[] ATTRIBUTE_ALIGN(4) = "fd_obj_n_keijiban_hasira_n.nj";
static __declspec(section ".rodata") const char bm_obj_city_board_normal_bml[] ATTRIBUTE_ALIGN(4) = "bm_obj_city_board_normal.bml";
static __declspec(section ".rodata") const char fd_obj_n_keijiban_board_x_nj[] ATTRIBUTE_ALIGN(4) = "fd_obj_n_keijiban_board_x.nj";
static __declspec(section ".rodata") const char fd_obj_n_keijiban_hasira_x_nj[] ATTRIBUTE_ALIGN(4) = "fd_obj_n_keijiban_hasira_x.nj";
static __declspec(section ".rodata") const char bm_obj_city_board_xmas_bml[] ATTRIBUTE_ALIGN(4) = "bm_obj_city_board_xmas.bml";
static __declspec(section ".rodata") const char fd_obj_n_keijiban_board_y_nj[] ATTRIBUTE_ALIGN(4) = "fd_obj_n_keijiban_board_y.nj";
static __declspec(section ".rodata") const char fd_obj_n_keijiban_hasira_y_nj[] ATTRIBUTE_ALIGN(4) = "fd_obj_n_keijiban_hasira_y.nj";

static __declspec(section ".rodata") const char bm_obj_city_board_2001_bml[0x20] ATTRIBUTE_ALIGN(4) =
    "bm_obj_city_board_2001.bml";

const char *bm_obj_city_21_model_names[3] = {ds_obj_21_nj, ds_obj_21_dai_1_nj, NULL};
const char *bm_obj_city_21_motion_names[2] = {ds_obj_21_njm, NULL};
BmlResourceDescriptor bm_obj_city_21_resource_descriptor = {
    bm_obj_city_21_bml, bm_obj_city_21_model_names, bm_obj_city_21_motion_names, 2, 1,
};

const char *bm_obj_city_easter_model_names[3] = {fs_obj_daiue_nj, fs_obj_egg_nj, NULL};
const char *bm_obj_city_easter_motion_names[1] = {NULL};
BmlResourceDescriptor bm_obj_city_easter_resource_descriptor = {
    bm_obj_city_easter_bml, bm_obj_city_easter_model_names, bm_obj_city_easter_motion_names, 2, 0,
};

const char *bm_obj_city_pump_model_names[2] = {fd_obj_n_pump_obj6_nj, NULL};
const char *bm_obj_city_pump_motion_names[1] = {NULL};
BmlResourceDescriptor bm_obj_city_pump_resource_descriptor = {
    bm_obj_city_pump_bml, bm_obj_city_pump_model_names, bm_obj_city_pump_motion_names, 1, 0,
};

const char *bm_obj_city_sonic_model_names[5] = {
    re_b_eggman_body_nj, re_b_knuckles_body_nj, re_b_sonic_body_nj, re_b_tails_body_nj, NULL,
};
const char *bm_obj_city_sonic_motion_names[5] = {
    wait_eggman_body_njm, wait_knuckles_body_njm, wait_sonic_body_njm, wait_tails_body_njm, NULL,
};
BmlResourceDescriptor bm_obj_city_sonic_resource_descriptor = {
    bm_obj_city_sonic_bml, bm_obj_city_sonic_model_names, bm_obj_city_sonic_motion_names, 4, 4,
};

const char *bm_obj_city_valen_model_names[4] = {
    de_obj_heartstar_01_1_nj, de_obj_heartstar_02_1_nj, ds_obj_heart_dai_1_nj, NULL,
};
const char *bm_obj_city_valen_motion_names[4] = {
    de_obj_heartstar_01_1_njm, de_obj_heartstar_02_1_njm, ds_obj_heart_dai_1_njm, NULL,
};
BmlResourceDescriptor bm_obj_city_valen_resource_descriptor = {
    bm_obj_city_valen_bml, bm_obj_city_valen_model_names, bm_obj_city_valen_motion_names, 3, 3,
};

const char *bm_obj_city_xmas_model_names[11] = {
    de_obj_o_aircar01_xmas_nj, de_obj_o_aircar02_xmas_nj, de_obj_o_aircar03_xmas_nj,
    de_obj_o_aircar04_xmas_nj, de_obj_o_aircar05_xmas_nj, fd_obj_n_leas_bmerge1_nj,
    fd_obj_n_tree_cyl199_nj,   fd_obj_n_tree_cyl200_nj,   fd_obj_n_tree_cyl201_nj,
    fd_obj_n_tree_obj2_nj,     NULL,
};
const char *bm_obj_city_xmas_motion_names[3] = {fd_obj_n_tree_cyl199_njm, fd_obj_n_tree_cyl200_njm, NULL};
BmlResourceDescriptor bm_obj_city_xmas_resource_descriptor = {
    bm_obj_city_xmas_bml, bm_obj_city_xmas_model_names, bm_obj_city_xmas_motion_names, 10, 2,
};

const char *bm_obj_city_board_normal_model_names[3] = {fd_obj_n_keijiban_board_n_nj, fd_obj_n_keijiban_hasira_n_nj, NULL};
const char *bm_obj_city_board_normal_motion_names[1] = {NULL};
BmlResourceDescriptor bm_obj_city_board_normal_resource_descriptor = {
    bm_obj_city_board_normal_bml, bm_obj_city_board_normal_model_names, bm_obj_city_board_normal_motion_names, 2, 0,
};

const char *bm_obj_city_board_xmas_model_names[3] = {fd_obj_n_keijiban_board_x_nj, fd_obj_n_keijiban_hasira_x_nj, NULL};
const char *bm_obj_city_board_xmas_motion_names[1] = {NULL};
BmlResourceDescriptor bm_obj_city_board_xmas_resource_descriptor = {
    bm_obj_city_board_xmas_bml, bm_obj_city_board_xmas_model_names, bm_obj_city_board_xmas_motion_names, 2, 0,
};

const char *bm_obj_city_board_2001_model_names[3] = {fd_obj_n_keijiban_board_y_nj, fd_obj_n_keijiban_hasira_y_nj, NULL};
const char *bm_obj_city_board_2001_motion_names[1] = {NULL};
BmlResourceDescriptor bm_obj_city_board_2001_resource_descriptor = {
    bm_obj_city_board_2001_bml, bm_obj_city_board_2001_model_names, bm_obj_city_board_2001_motion_names, 2, 0,
};

// inferred: indexed by the active season slot (lobby_event_theme_id_table order)
BmlResourceDescriptor *city_season_resource_descriptors[6] = {
    &bm_obj_city_easter_resource_descriptor, &bm_obj_city_valen_resource_descriptor,
    &bm_obj_city_xmas_resource_descriptor,   &bm_obj_city_pump_resource_descriptor,
    &bm_obj_city_21_resource_descriptor,     &bm_obj_city_sonic_resource_descriptor,
};

BmlResource *city_season_easter_egg_model_table[6];
NJS_TEXLIST *city_season_xmas_model_table[6];
s32 lbl_805D5B30;
StripBufferPair *lbl_805D5B34;
BmlResource *lbl_805D5B38;
saddr lbl_805D5B3C;
saddr lbl_805D5B40;
NJS_TEXLIST *lbl_805D5B44;
StripBufferPair *lbl_805D5B48;

NJS_TEXLIST *TLobby__sub_80184C2C(int a0) {  return city_season_xmas_model_table[a0]; }

BmlResource *get_season_model_resource(int a0) {  return city_season_easter_egg_model_table[a0]; }

s32 TLobby__sub_80184C54(void) {
    return lbl_805D5B30 != -1;
}

int TLobby__sub_80184C6C(int a0) {  return lbl_8050DC20[a0]; }

void TLobby__sub_80184C80(void *p) {
    s32 i;
    TLobby::clear_global_array(p);
    for (i = 0; i < 6; i++) {
        if (TLobby::event_theme_id == lobby_event_theme_id_table[i]) {
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
        delete lbl_805D5B48;
        lbl_805D5B48 = NULL;
    }
    if (lbl_805D5B38 != NULL) {
        delete (BmlResource *)lbl_805D5B38;
        lbl_805D5B38 = NULL;
    }
    lbl_805D5B44 = NULL;
    lbl_805D5B3C = 0;
    lbl_805D5B40 = 0;
    if (lbl_805D5B34 != NULL) {
        delete lbl_805D5B34;
        lbl_805D5B34 = NULL;
    }
    for (i = 5; i >= 0; i--) {
        if (city_season_easter_egg_model_table[i] != NULL) {
            delete (BmlResource *)city_season_easter_egg_model_table[i];
        }
        city_season_easter_egg_model_table[i] = NULL;
        city_season_xmas_model_table[i] = NULL;
    }
}

extern "C" void clear_global_array__6TLobbyFPv();

extern "C" void TLobby__sub_80184DF4(void) {
    s32 i;
    s32 count;
    u8 *board;
    u8 *tmp;
    u8 *base;
    u8 *ent;
    saddr ph;
    s32 slot_offset;
    void *p;

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
                city_season_easter_egg_model_table[j] = NULL;
                city_season_xmas_model_table[j] = NULL;
            }
        }
        tmp = (u8 *)new BmlResource(1, (BmlResourceDescriptor *)city_season_resource_descriptors[lbl_805D5B30], 0, 0, NULL);
        slot_offset = lbl_805D5B30 * sizeof(city_season_easter_egg_model_table[0]);
        *(BmlResource **)((u8 *)&city_season_easter_egg_model_table + slot_offset) = (BmlResource *)tmp;
        for (i = 0; i < *(s32 *)(tmp + 0x434); i++) {
            if ((*(u32 (**)[4])(tmp + 0x42c))[i][3] != 0) {
                *(NJS_TEXLIST **)((u8 *)&city_season_xmas_model_table + slot_offset) = ((BmlResource *)tmp)->models[i].texlist;
                break;
            }
        }
        if (lbl_805D5B30 == 0) {
            base = *(u8 **)(tmp + 0x42c);
            ent = *(u8 **)(base + 0x18);
            lbl_805D5B34 = new StripBufferPair((NJS_OBJECT *)ent, 3);
            base = *(u8 **)(*(u8 **)(ent + 0x2c) + 4);
            base = *(u8 **)(base + 4);
            *(s16 *)(base + 0xc) &= ~0x1000;
        } else if (lbl_805D5B30 == 4) {
            base = *(u8 **)(tmp + 0x42c);
            ent = *(u8 **)(base + 0x18);
            lbl_805D5B34 = new StripBufferPair((NJS_OBJECT *)ent, 0);
            base = *(u8 **)(*(u8 **)(ent + 0x2c) + 4);
            base = *(u8 **)(base + 4);
            *(s16 *)(base + 0xc) &= ~0x1000;
        } else {
            lbl_805D5B34 = NULL;
        }
    }

    if (lbl_805D5B30 == 2) {
        u8 *r = (u8 *)new BmlResource(1, &bm_obj_city_board_xmas_resource_descriptor, 0, 0, NULL);
        board = r;
        lbl_805D5B3C = *(s32 *)(*(u8 **)(r + 0x42c) + 8);
        lbl_805D5B40 = *(s32 *)(*(u8 **)(r + 0x42c) + 0x18);
    } else if (lbl_805D5B30 == 4) {
        u8 *r = (u8 *)new BmlResource(1, &bm_obj_city_board_2001_resource_descriptor, 0, 0, NULL);
        board = r;
        lbl_805D5B3C = *(s32 *)(*(u8 **)(r + 0x42c) + 8);
        lbl_805D5B40 = *(s32 *)(*(u8 **)(r + 0x42c) + 0x18);
    } else {
        u8 *r = (u8 *)new BmlResource(1, &bm_obj_city_board_normal_resource_descriptor, 0, 0, NULL);
        board = r;
        lbl_805D5B3C = *(s32 *)(*(u8 **)(r + 0x42c) + 8);
        lbl_805D5B40 = *(s32 *)(*(u8 **)(r + 0x42c) + 0x18);
    }

    lbl_805D5B48 = new StripBufferPair((NJS_OBJECT *)lbl_805D5B3C, 2);
    base = (u8 *)lbl_805D5B3C;
    base = *(u8 **)(base + 4);
    base = *(u8 **)(base + 4);
    *(s16 *)(base + 0xc) &= ~0x2000;
    lbl_805D5B38 = (BmlResource *)board;
    for (i = 0; i < *(s32 *)(board + 0x434); i++) {
        if ((*(u32 (**)[4])(board + 0x42c))[i][3] != 0) {
            lbl_805D5B44 = ((BmlResource *)board)->models[i].texlist;
            break;
        }
    }
}
