#include "pso/system/BmlResource.h"
#include "pso/system/NinjaTypes.h"
#include "types.h"
#include "pso/render/StripBufferPair.h"
#include "pso/object/city/CitySeasonResources.h"
#include "pso/network/TLobby.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/ui/keyboard/SystemBootInit.h"

int city_season_flags[6];
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
// Each season's model resource and its first texture list, indexed like city_season_resource_descriptors.
BmlResource *city_season_resources[6];
NJS_TEXLIST *city_season_texlists[6];
s32 city_season_index;
StripBufferPair *city_season_strips;
BmlResource *city_season_board_resource;
NJS_OBJECT *city_season_board_model;
NJS_OBJECT *city_season_board_pillar_model;
NJS_TEXLIST *city_season_board_texlist;
StripBufferPair *city_season_board_strips;

NJS_TEXLIST *get_city_season_texlist(s32 season) { return city_season_texlists[season]; }

BmlResource *get_city_season_resource(s32 season) { return city_season_resources[season]; }

s32 is_city_season_active() {
    return city_season_index != -1;
}

s32 is_city_season_enabled(s32 season) { return city_season_flags[season]; }

void enable_city_season_for_event_theme() {
    s32 i;
    clear_city_season_flags();
    for (i = 0; i < 6; i++) {
        if (TLobby::event_theme_id == lobby_event_theme_id_table[i]) {
            city_season_flags[i] = 1;
            return;
        }
    }
}

void disable_city_seasons() { clear_city_season_flags(); }

void clear_city_season_flags() {
    s32 i;
    for (i = 0; i < 6; i++) {
        city_season_flags[i] = 0;
    }
}

void free_city_season_resources() {
    s32 i;
    if (city_season_board_strips != NULL) {
        delete city_season_board_strips;
        city_season_board_strips = NULL;
    }
    if (city_season_board_resource != NULL) {
        delete city_season_board_resource;
        city_season_board_resource = NULL;
    }
    city_season_board_texlist = NULL;
    city_season_board_model = NULL;
    city_season_board_pillar_model = NULL;
    if (city_season_strips != NULL) {
        delete city_season_strips;
        city_season_strips = NULL;
    }
    for (i = 5; i >= 0; i--) {
        if (city_season_resources[i] != NULL) {
            delete city_season_resources[i];
        }
        city_season_resources[i] = NULL;
        city_season_texlists[i] = NULL;
    }
}

void load_city_season_resources() {
    s32 i;
    BmlResource *resource;
    BmlResource *board;
    NJS_OBJECT *object;

    clear_city_season_flags();
    if (get_main_phase() == 0xf) {
        enable_city_season_for_event_theme();
    } else {
        disable_city_seasons();
    }
    city_season_index = -1;
    for (i = 0; i < 6; i++) {
        if (is_city_season_enabled(i)) {
            city_season_index = i;
            break;
        }
    }
    if (city_season_index != -1) {
        for (s32 j = 0; j < 6; j++) {
            city_season_resources[j] = NULL;
            city_season_texlists[j] = NULL;
        }
        resource = new BmlResource(1, city_season_resource_descriptors[city_season_index], 0, 0, NULL);
        city_season_resources[city_season_index] = resource;
        for (i = 0; i < resource->model_count; i++) {
            if (resource->models[i].texlist != NULL) {
                city_season_texlists[city_season_index] = resource->models[i].texlist;
                break;
            }
        }
        if (city_season_index == 0) {
            object = resource->models[1].model;
            city_season_strips = new StripBufferPair(object, 3);
            ((NJS_CNK_MODEL *)object->child->model)->polygon_list[6] &= ~0x1000;
        } else if (city_season_index == 4) {
            object = resource->models[1].model;
            city_season_strips = new StripBufferPair(object, 0);
            ((NJS_CNK_MODEL *)object->child->model)->polygon_list[6] &= ~0x1000;
        } else {
            city_season_strips = NULL;
        }
    }

    if (city_season_index == 2) {
        board = new BmlResource(1, &bm_obj_city_board_xmas_resource_descriptor, 0, 0, NULL);
        city_season_board_model = board->models[0].model;
        city_season_board_pillar_model = board->models[1].model;
    } else if (city_season_index == 4) {
        board = new BmlResource(1, &bm_obj_city_board_2001_resource_descriptor, 0, 0, NULL);
        city_season_board_model = board->models[0].model;
        city_season_board_pillar_model = board->models[1].model;
    } else {
        board = new BmlResource(1, &bm_obj_city_board_normal_resource_descriptor, 0, 0, NULL);
        city_season_board_model = board->models[0].model;
        city_season_board_pillar_model = board->models[1].model;
    }

    city_season_board_strips = new StripBufferPair(city_season_board_model, 2);
    ((NJS_CNK_MODEL *)city_season_board_model->model)->polygon_list[6] &= ~0x2000;
    city_season_board_resource = board;
    for (i = 0; i < board->model_count; i++) {
        if (board->models[i].texlist != NULL) {
            city_season_board_texlist = board->models[i].texlist;
            break;
        }
    }
}
