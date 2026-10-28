#include "types.h"
#include "pso/system/NinjaUtil.h"
#include "pso/object/TObjDoorJung.h"
#include "pso/misc/TUnk_804DDD28.h"
#include "pso/object/TObjSeabedSuisoBrakable.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/map/CurrentArea.h"

extern "C" {
u8 is_valid_player_motion_variant(u32 arg0);
u8 TLobby__sub_802A7278(u32 arg0);
int match_coordinate_pair(u8 *arg0, s32 arg1, s32 arg2);
void TLobby__sub_8001FE7C(void*, int);
s32 release_texture_list(void*);

struct Tbl_802A6F98 { s32 w[5]; };
struct Brk_802A6F98 { s32 a[5]; s32 b[3]; s32 *c[3]; };

void *get_bml_model(u32, int);
u32 load_resource_from_descriptor(void *, int, void *, int, int, int);
u8 *load_gvm_texture_file(s32 arg0);
extern Tbl_802A6F98 seabed_suiso_texture_name_table;
extern Tbl_802A6F98 lbl_80466C80;
extern s32 lbl_80466CE0[];
extern s32 lbl_80466CF8[];
extern s32 bm_obj_seabed_suiso_resource_descriptor[];
extern s32 bm_obj_seabed_suiso_2_resource_descriptor[];

int TObjSeabedSuisoBrakable__break_model_entries[5];
int TObjSeabedSuisoBrakable__model12_render_nodes[3];
int suiso_brakable_linked_switch_counts[4];

extern u32 TObjSeabedSuisoBrakable__resource_bundle;
extern u32 TObjSeabedSuisoBrakable__texture_gvm_handle;

void TObjSeabedSuisoBrakable::free_static_resources() {
    if ((u32) TObjSeabedSuisoBrakable__texture_gvm_handle != 0U) {
        release_texture_list((void*)TObjSeabedSuisoBrakable__texture_gvm_handle);
        TAdSinglePlyChrSelectGC::safe_free(TObjSeabedSuisoBrakable__texture_gvm_handle);
        TObjSeabedSuisoBrakable__texture_gvm_handle = 0U;
    }
    if ((u32) TObjSeabedSuisoBrakable__resource_bundle != 0U) {
        TLobby__sub_8001FE7C((void*)TObjSeabedSuisoBrakable__resource_bundle, 1);
        TObjSeabedSuisoBrakable__resource_bundle = 0U;
    }
}

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TObjSeabedSuisoBrakable::load_resources() {
    s32 i;
    void *p;
    void *item;
    s32 **ptrs;
    Tbl_802A6F98 t1;
    Tbl_802A6F98 t2;

    switch (get_current_area()) {
    case 0x1D:
        p = ::operator new(0x440);
        if (p != NULL) {
            p = (void *)load_resource_from_descriptor(p, 1, bm_obj_seabed_suiso_2_resource_descriptor, 0, 0, 0);
        }
        TObjSeabedSuisoBrakable__resource_bundle = (u32)p;
        if ((TObjSeabedSuisoBrakable__texture_gvm_handle = (u32)load_gvm_texture_file((s32)lbl_80466CE0)) != 0) {
            t1 = seabed_suiso_texture_name_table;
            for (i = 0; i < 5; i++) {
                TObjSeabedSuisoBrakable__break_model_entries[i] = ((TObjDoorJung *)TObjSeabedSuisoBrakable__texture_gvm_handle)->find_entry_by_name((const char *)(t1.w[i]));
            }
        }
        break;
    case 0x1C:
    default:
        p = ::operator new(0x440);
        if (p != NULL) {
            p = (void *)load_resource_from_descriptor(p, 1, bm_obj_seabed_suiso_resource_descriptor, 0, 0, 0);
        }
        TObjSeabedSuisoBrakable__resource_bundle = (u32)p;
        if ((TObjSeabedSuisoBrakable__texture_gvm_handle = (u32)load_gvm_texture_file((s32)lbl_80466CF8)) != 0) {
            t2 = lbl_80466C80;
            for (i = 0; i < 5; i++) {
                TObjSeabedSuisoBrakable__break_model_entries[i] = ((TObjDoorJung *)TObjSeabedSuisoBrakable__texture_gvm_handle)->find_entry_by_name((const char *)(t2.w[i]));
            }
        }
        break;
    }
    if ((item = get_bml_model(TObjSeabedSuisoBrakable__resource_bundle, 0xC)) != NULL) {
        TObjSeabedSuisoBrakable__model12_render_nodes[0] = (int)find_object_node((NJS_OBJECT *)item, 1);
        TObjSeabedSuisoBrakable__model12_render_nodes[1] = (int)find_object_node((NJS_OBJECT *)item, 2);
        TObjSeabedSuisoBrakable__model12_render_nodes[2] = (int)find_object_node((NJS_OBJECT *)item, 4);
    }
    if ((p = get_bml_model(TObjSeabedSuisoBrakable__resource_bundle, 0xD)) != NULL) {
        suiso_brakable_linked_switch_counts[0] = (int) find_object_node((NJS_OBJECT *)p, 1);
        suiso_brakable_linked_switch_counts[1] = (int) find_object_node((NJS_OBJECT *)p, 2);
        suiso_brakable_linked_switch_counts[2] = (int) find_object_node((NJS_OBJECT *)p, 3);
        ptrs = (s32 **)suiso_brakable_linked_switch_counts;
        for (i = 0; i < 3; i++) {
            if (ptrs[i] != NULL) {
                *ptrs[i] |= 0x100000;
            }
        }
    }
}
extern int fold_flush_802A6F98;
#pragma pop

    extern int TObjSeabedSuisoBrakable__break_model_entries[];
int TObjSeabedSuisoBrakable::get_break_data(int a0) {  return TObjSeabedSuisoBrakable__break_model_entries[a0]; }

    extern int TObjSeabedSuisoBrakable__model12_render_nodes[];
int TObjSeabedSuisoBrakable::get_table0_entry(int a0) {  return TObjSeabedSuisoBrakable__model12_render_nodes[a0]; }

    extern int suiso_brakable_linked_switch_counts[];
int TObjSeabedSuisoBrakable::get_table1_entry(int a0) {  return suiso_brakable_linked_switch_counts[a0]; }

void TObjSeabedSuisoBrakable::vfunc_19() {  }

int match_coordinate_pair(u8 *arg0, s32 arg1, s32 arg2) {
    u8 var_r6;
    var_r6 = 0;
    if ((arg1 == (s32) *(s32 *)((s8 *)arg0 + 0)) && (arg2 == (s32) *(s32 *)((s8 *)arg0 + 4))) {
        var_r6 = 1;
    }
    return var_r6;
}

u8 is_valid_player_motion_variant(u32 arg0) {
    return (u8) (arg0 < 0x13U);
}

u8 TLobby__sub_802A7278(u32 arg0) {
    return (u8) (arg0 < 6U);
}

}
