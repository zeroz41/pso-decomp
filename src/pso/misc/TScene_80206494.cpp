#include "types.h"
#include "pso/misc/TScene.h"
#include "pso/item/TItemDrop_800F93F0.h"
#include "pso/misc/TLobby_80131794.h"
#include "pso/misc/TLobby_80207644.h"
#include "pso/misc/TLobby_80207DA8.h"
#include "pso/misc/TScene_80206494.h"
#include "pso/unk/text_800F8A18.h"

#include "pso/misc/TOKeyMachine01.h"
#include "pso/misc/TQuestVmDownLoadServer.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/object/TObjButterflyLobby.h"
#include "pso/object/TObjMapCsn.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/map/CurrentArea.h"

struct RecoveredGlobal_8020650C___vt__6TScene { s32 value; u8 remaining[0x14]; };
typedef char RecoveredGlobal_8020650C___vt__6TScene_size[sizeof(RecoveredGlobal_8020650C___vt__6TScene) == 0x18 ? 1 : -1];

struct Ent_802066BC { char *name; s32 idx; };

struct Res_8020681C { s32 table; s32 index; s32 pad; };

struct Res_80207038 { s32 table; s32 index; s32 pad; };

extern "C" {
s32 get_player_name_copy_buffer();
s32 strncmp(s32, s32, s32);
s32 release_texture_list(u32);
extern s32 TScene__current_floor_name;
extern s32 *scene_collision_data;
extern void *TScene__data_805D5FCC;
extern u32 TScene__map_rel_load_buffer;
extern u32 TScene__collision_file_buffer;
extern u32 TScene__texture_animation_buffer;
extern u32 TScene__supplementary_rel_buffer;
extern u32 TScene__data_805D6020;
extern u32 TScene__material_info_buffer;
extern s32 lbl_805DC604;
s32 TScene__sub_80206410(void *);
s32 __ct__7TObjectFP7TObject(void *, void *);
extern s32 __vt__6TScene[];
extern s32 lbl_805D3618;
extern u32 TScene__texture_wave_resource;
extern u8 lbl_8044A948[];
extern Ent_802066BC scene_format_dispatch_tables[];
extern s32 TScene__data_805D5FE8;
extern s32 TScene__map_rel_load_size_limit;
void bind_gvm_texture_list(s32 *, u32);
extern s32 lbl_8044A97C[];
extern s32 lbl_8044A984[];
extern s32 current_floor_index;
extern s32 scene_resource_index;
extern s8 TScene__floor_scene_ready_flag;
extern s32 TScene__data_805D5FE0;
extern f32 TScene__visibility_radius_margin;
extern s32 TScene__map_section_render_callback;
extern s32 TScene__active_scene_callback;
extern s32 TScene__render_callback;
extern const f32 TScene__data_805DC5D8;
extern s32 lbl_805D5FF8;
extern s32 lbl_805D600C;
extern s32 lbl_805D6014;
extern s32 lbl_805D6018;
extern s32 TScene__loaded_floor_rel_file_index;
extern s32 floor_bin_file_size;
extern s32 scene_file_buffer_size;
s32 debug_print__6TLobbyFle(s32 *, ...);
s32 collect_collision_groups(u32, s32);
extern s32 lbl_8044A950[];
extern s32 lbl_8044A958[];
extern u8 lbl_8044A938[];
s32 read_disc_file(char *, u32);
extern const char lbl_8044A940[];
extern u8 lbl_8044A994[];
extern u8 lbl_8044A99C[];
extern u8 lbl_8044A9AC[];
struct Sp8Buf20_80206494 {
    s32 f0; s32 f4; s32 f8; s32 fc;
    s32 f10; s32 f14; s32 f18; s32 f1c;
};

s32 TScene__sub_80205AE8(s32 *);
s32 TScene__sub_80205FD4(void *);
void *__nw__7TObjectFUl(int);

}
TScene::~TScene() {
    TScene__sub_80205AE8((s32 *)this);
    TScene__sub_80205FD4(this);
    TScene__map_section_render_callback = 0;
    TScene__active_scene_callback = 0;
    TScene__render_callback = 0;
}


extern void *tl_02;

u8 *TScene__ct(TScene *scene, s32 arg1) {
    __ct__7TObjectFP7TObject((void *)scene, (void *)arg1);
    *(s32 **)((s8 *)scene + 0x18) = &(*(RecoveredGlobal_8020650C___vt__6TScene *)&__vt__6TScene).value;
    *(s32 *)((s8 *)scene + 0) = (s32) lbl_805D3618;
    scene->m_1c = 0;
    scene->m_30 = 0;
    scene->m_34 = 0;
    scene->m_38 = 0x32;
    scene->m_3c = 0;
    TScene__sub_80206410(scene);
    if ((get_current_area() == 1) && ((u32) TScene__texture_wave_resource != 0U) && ((void *) (*(u8 * *)&TScene__data_805D5FCC) != NULL) && ((u32) *(u32 *)((s8 *)(*(u8 * *)&TScene__data_805D5FCC) + 0x14) != 0U)) {
        TScene::create_texture_wave_tasks((s32)scene);
    }
    scene->init_material_nodes();
    return (u8 *)scene;
}

void TScene::create() {
    void *o;
    o = __nw__7TObjectFUl(0x40);
    if (o != NULL) {
        TScene__ct((TScene *)((u8 *)o), (s32)tl_02);
    }
}

void TScene__sub_802065E8(void) {  }
void TScene__sub_802065EC(void) {  }

extern s32 lbl_8044A98C[];

void TScene::load_floor_rel_file(s32 name) {
    u8 id[0x20];
    replace_file_extension__6TLobbyFPvPvPv((char *)((s32 *)id), (char *)name, (char *)((s32 *)lbl_8044A938));
    if (((TScene *)id)->update_lobby_scene() <= TScene__loaded_floor_rel_file_index) {
        if (TScene__supplementary_rel_buffer != 0U) {
            TScene__texture_wave_resource = (u32)load_relocatable_file((s32)((s32 *)id), TScene__supplementary_rel_buffer);
        } else {
            TScene__texture_wave_resource = 0;
        }
    }
}

void TScene::load_tam_file(s32 name) {
    u8 sp8[0x20];
    replace_file_extension__6TLobbyFPvPvPv((char *)((s32 *)sp8), (char *)name, (char *)((s32 *)((u8 *)&lbl_8044A940)));
    if (((TScene *)sp8)->update_lobby_scene() <= lbl_805D6018) {
        if (TScene__texture_animation_buffer != 0U) {
            read_disc_file((char *)sp8, TScene__texture_animation_buffer);
        } else {
            TScene__texture_animation_buffer = 0;
        }
    }
}

void load_scene_map_file(s32 arg0) {
    u8 id[0x20];
    Ent_802066BC *e;
    TScene__data_805D5FCC = NULL;
    TScene__data_805D5FE8 = -1;
    replace_file_extension__6TLobbyFPvPvPv((char *)((s32 *)id), (char *)arg0, (char *)((s32 *)lbl_8044A948));
    if (((TScene *)id)->update_lobby_scene() <= TScene__map_rel_load_size_limit && TScene__map_rel_load_buffer != 0) {
        TScene__data_805D5FCC = (void *)load_relocatable_file((s32)((s32 *)id), TScene__map_rel_load_buffer);
    }
    if (TScene__data_805D5FCC != NULL) {
        for (e = scene_format_dispatch_tables; e->name != NULL; e++) {
            if (strncmp((s32)TScene__data_805D5FCC, (s32)e->name, 4) == 0) {
                TScene__data_805D5FE8 = e->idx;
                break;
            }
        }
    }
}

void load_scene_collision_file(s32 name) {
    struct Sp8Buf20_80206494 sp8;
    replace_file_extension__6TLobbyFPvPvPv((char *)((s32 *)&sp8), (char *)name, (char *)lbl_8044A950);
    if (((TScene *)((char *)&sp8))->update_lobby_scene() <= lbl_805D6014) {
        if (TScene__collision_file_buffer != 0U) {
            scene_collision_data = (s32 *)load_relocatable_file((s32)((s32 *)&sp8), TScene__collision_file_buffer);
            if (scene_collision_data != NULL && TObjMapCsn::get_map_count() != 0U) {
                u32 csn = TObjMapCsn::get_map_count();
                collect_collision_groups(csn, *scene_collision_data);
                return;
            }
            debug_print__6TLobbyFle(lbl_8044A958);
            return;
        }
        scene_collision_data = NULL;
    }
}

void load_floor_scene(void) {
    Ent_802066BC *tbl;
    s32 ent;
    s32 found;
    Res_8020681C res;
    s32 path[11];
    if (TScene__data_805D5FCC != NULL && *(u32 *)((s8 *)TScene__data_805D5FCC + 0x14) != 0) {
        release_texture_list(*(u32 *)((s8 *)TScene__data_805D5FCC + 0x14));
        *(u32 *)((s8 *)TScene__data_805D5FCC + 0x14) = 0;
    }
    if (get_floor_map_selection(current_floor_index, (u8 *)&res) == 1) {
        tbl = (Ent_802066BC *)get_floor_scene_table(res.table);
        scene_resource_index = res.index;
        ent = tbl[res.index].idx;
    }
    copy_name((s32)((s32 *)TScene__current_floor_name));
    load_scene_map_file(ent);
    load_scene_collision_file(ent);
    if (TScene__data_805D5FCC != NULL && *(u32 *)((s8 *)TScene__data_805D5FCC + 0x14) != 0) {
        found = 0;
        if (TRaderMapCore::is_not_split_screen() == 1) {
            replace_file_extension__6TLobbyFPvPvPv((char *)path, (char *)tbl[scene_resource_index].name, (char *)lbl_8044A97C);
            found = ((TScene *)path)->update_lobby_scene();
        }
        if (found <= 0) {
            replace_file_extension__6TLobbyFPvPvPv((char *)path, (char *)tbl[scene_resource_index].name, (char *)lbl_8044A984);
        }
        bind_gvm_texture_list(path, *(u32 *)((s8 *)TScene__data_805D5FCC + 0x14));
    }
    TScene::load_floor_rel_file(ent);
    TScene::load_tam_file(ent);
    ((void (*)(s32))TScene__sub_802065EC)(ent);
    ((void (*)(s32))TScene__sub_802065E8)(ent);
    copy_name((s32)&lbl_805DC604);
    TScene__floor_scene_ready_flag = 1;
    TScene__data_805D5FE0 = 0;
    TScene__map_section_render_callback = 0;
    TScene__active_scene_callback = 0;
    TScene__render_callback = 0;
    TScene__visibility_radius_margin = TScene__data_805DC5D8;
}

#pragma push
#pragma fp_contract on

void TScene::free_scene_resources() {
    u32 temp_r3;
    temp_r3 = TScene__material_info_buffer;
    if (temp_r3 != 0U) {
        TAdSinglePlyChrSelectGC::safe_free(temp_r3);
        TScene__material_info_buffer = 0U;
    }
    temp_r3 = TScene__data_805D6020;
    if (temp_r3 != 0U) {
        TAdSinglePlyChrSelectGC::safe_free(temp_r3);
        TScene__data_805D6020 = 0U;
    }
    temp_r3 = TScene__texture_animation_buffer;
    if (temp_r3 != 0U) {
        TAdSinglePlyChrSelectGC::safe_free(temp_r3);
        TScene__texture_animation_buffer = 0U;
    }
    temp_r3 = TScene__supplementary_rel_buffer;
    if (temp_r3 != 0U) {
        TAdSinglePlyChrSelectGC::safe_free(temp_r3);
        TScene__supplementary_rel_buffer = 0U;
    }
    temp_r3 = (u32)TScene__data_805D5FCC;
    if (temp_r3 != 0U) {
        if ((temp_r3 = *(u32*)((u8*)TScene__data_805D5FCC + 0x14)) != 0U) {
            release_texture_list(temp_r3);
            *(u32 *)((s8 *)TScene__data_805D5FCC + 0x14) = 0U;
        }
    }
    temp_r3 = TScene__collision_file_buffer;
    if (temp_r3 != 0U) {
        TAdSinglePlyChrSelectGC::safe_free(temp_r3);
        TScene__collision_file_buffer = 0U;
    }
    TObjButterflyLobby::free_singleton_805D4E6C();
    temp_r3 = TScene__map_rel_load_buffer;
    if (temp_r3 != 0U) {
        TAdSinglePlyChrSelectGC::safe_free(temp_r3);
        TScene__map_rel_load_buffer = 0U;
    }
    (*(s32 *)&scene_collision_data) = 0;
    TScene__data_805D5FCC = NULL;
    if (strncmp(get_player_name_copy_buffer(), TScene__current_floor_name, 0x10) == 0) {
        copy_name((s32)&lbl_805DC604);
    }
}
#pragma pop

void TScene::load_file_to_buffer(s32 name) {
    s32 sp8[8];
    s32 temp_r31;
    u32 temp_r3;
    u32 temp_r3_2;

    TScene__material_info_buffer = 0U;
    scene_file_buffer_size = 0;
    replace_file_extension__6TLobbyFPvPvPv((char *)(sp8), (char *)(name), (char *)(lbl_8044A98C));
    temp_r31 = ((TScene *)sp8)->update_lobby_scene();
    if (get_current_area() == 0xF) {
        if ((temp_r31 > 0) && ((u32) temp_r31 <= 0x100U)) {
            temp_r3 = ((TQuestVmDownLoadServer *)0x100)->alloc();
            TScene__material_info_buffer = temp_r3;
            if (temp_r3 != 0U) {
                read_disc_file((char *)(sp8), temp_r3);
                scene_file_buffer_size = 0x100;
            }
        }
    } else if (temp_r31 > 0) {
        temp_r3_2 = ((TQuestVmDownLoadServer *)temp_r31)->alloc();
        TScene__material_info_buffer = temp_r3_2;
        if (temp_r3_2 != 0U) {
            read_disc_file((char *)(sp8), temp_r3_2);
            scene_file_buffer_size = temp_r31;
        }
    }
}

extern const char lbl_8044A9A4[];

void TScene::load_floor_bin_file(s32 name) {
    u8 sp8[0x20];
    s32 size;
    TScene__data_805D6020 = 0U;
    floor_bin_file_size = 0;
    if (TRaderMapCore::is_not_split_screen() == 1) {
        replace_file_extension__6TLobbyFPvPvPv((char *)((s32 *)sp8), (char *)name, (char *)((s32 *)lbl_8044A994));
    } else {
        replace_file_extension__6TLobbyFPvPvPv((char *)((s32 *)sp8), (char *)name, (char *)((s32 *)lbl_8044A99C));
    }
    size = ((TScene *)sp8)->update_lobby_scene();
    if (get_current_area() == 0xF) {
        if (size > 0 && (u32)size <= 0x100U) {
            TScene__data_805D6020 = ((TQuestVmDownLoadServer *)0x100)->alloc();
            if (TScene__data_805D6020 != 0U) {
                read_disc_file((char *)sp8, TScene__data_805D6020);
                floor_bin_file_size = 0x100;
            }
        }
    } else if (size > 0) {
        TScene__data_805D6020 = ((TQuestVmDownLoadServer *)size)->alloc();
        if (TScene__data_805D6020 != 0U) {
            read_disc_file((char *)sp8, TScene__data_805D6020);
            floor_bin_file_size = size;
        }
    }
}

void TScene::load_map_texture_archive(s32 name) {
    char sp8[0x20];
    s32 global_state;
    s32 var_r30;
    u32 temp_r3;
    u32 temp_r3_2;

    global_state = get_current_area();
    TScene__texture_animation_buffer = 0U;
    var_r30 = 0;
    lbl_805D6018 = 0;
    if (TRaderMapCore::is_not_split_screen() == 1) {
        replace_file_extension__6TLobbyFPvPvPv((char *)(sp8), (char *)(name), (char *)(lbl_8044A9A4));
        var_r30 = ((TScene *)sp8)->update_lobby_scene();
    }
    if (var_r30 <= 0) {
        replace_file_extension__6TLobbyFPvPvPv((char *)(sp8), (char *)(name), (char *)(lbl_8044A940));
        var_r30 = ((TScene *)sp8)->update_lobby_scene();
    }
    if (global_state == 0xF) {
        if ((var_r30 > 0) && ((u32) var_r30 <= 0x100U)) {
            temp_r3 = ((TQuestVmDownLoadServer *)0x100)->alloc();
            TScene__texture_animation_buffer = temp_r3;
            if (temp_r3 != 0U) {
                read_disc_file((char *)(sp8), temp_r3);
                lbl_805D6018 = 0x100;
            }
        }
    } else if (var_r30 > 0) {
        temp_r3_2 = ((TQuestVmDownLoadServer *)var_r30)->alloc();
        TScene__texture_animation_buffer = temp_r3_2;
        if (temp_r3_2 != 0U) {
            read_disc_file((char *)(sp8), temp_r3_2);
            lbl_805D6018 = var_r30;
        }
    }
}

void TScene::load_supplementary_t_rel(s32 name) {
    u8 id[0x20];
    s32 n;
    TScene__texture_wave_resource = 0;
    TScene__supplementary_rel_buffer = 0U;
    TScene__loaded_floor_rel_file_index = 0;
    replace_file_extension__6TLobbyFPvPvPv((char *)((s32 *)id), (char *)name, (char *)((s32 *)lbl_8044A938));
    n = ((TScene *)id)->update_lobby_scene();
    if (n > 0) {
        TScene__supplementary_rel_buffer = ((TQuestVmDownLoadServer *)n)->alloc();
        if (TScene__supplementary_rel_buffer != 0U) {
            TScene__texture_wave_resource = (u32)load_relocatable_file((s32)((s32 *)id), TScene__supplementary_rel_buffer);
            TScene__loaded_floor_rel_file_index = n;
        }
    }
}

void TScene::load_scene_rel_file(s32 arg0) {
    u8 id[0x28];
    s32 state;
    s32 size;
    state = get_current_area();
    TScene__data_805D5FCC = NULL;
    size = 0;
    TScene__map_rel_load_buffer = 0U;
    TScene__map_rel_load_size_limit = 0;
    TScene__data_805D5FE8 = -1;
    if (TRaderMapCore::is_not_split_screen() == 1) {
        replace_file_extension__6TLobbyFPvPvPv((char *)((s32 *)id), (char *)arg0, (char *)((s32 *)lbl_8044A9AC));
        size = ((TScene *)id)->update_lobby_scene();
    }
    if (size <= 0) {
        replace_file_extension__6TLobbyFPvPvPv((char *)((s32 *)id), (char *)arg0, (char *)((s32 *)lbl_8044A948));
        size = ((TScene *)id)->update_lobby_scene();
    }
    if (state == 0xF) {
        if (size > 0 && (u32)size <= 0x80000U) {
            TScene__map_rel_load_buffer = ((TQuestVmDownLoadServer *)0x80000)->alloc();
            if (TScene__map_rel_load_buffer != 0U) {
                TScene__data_805D5FCC = (void *)load_relocatable_file((s32)((s32 *)id), TScene__map_rel_load_buffer);
                TScene__map_rel_load_size_limit = 0x80000;
            }
        }
    } else if (size > 0) {
        TScene__map_rel_load_buffer = ((TQuestVmDownLoadServer *)size)->alloc();
        if (TScene__map_rel_load_buffer != 0U) {
            TScene__data_805D5FCC = (void *)load_relocatable_file((s32)((s32 *)id), TScene__map_rel_load_buffer);
            TScene__map_rel_load_size_limit = size;
        }
    }
    if (TScene__data_805D5FCC != NULL) {
        Ent_802066BC *e;
        for (e = scene_format_dispatch_tables; e->name != NULL; e++) {
            if (strncmp((s32)TScene__data_805D5FCC, (s32)e->name, 4) == 0) {
                TScene__data_805D5FE8 = e->idx;
                return;
            }
        }
    }
}

void TScene::load_scene_data(s32 name) {
    struct Sp8Buf20_80206494 sp8;
    s32 temp_r31;
    u32 temp_r3;
    u32 temp_r3_2;

    TObjButterflyLobby::alloc_scene_buffer();
    scene_collision_data = NULL;
    TScene__collision_file_buffer = 0U;
    lbl_805D6014 = 0;
    replace_file_extension__6TLobbyFPvPvPv((char *)((s32 *)((s32 *)&sp8)), (char *)(name), (char *)(lbl_8044A950));
    temp_r31 = ((TScene *)((s32 *)&sp8))->update_lobby_scene();
    if (get_current_area() == 0xF) {
        if ((temp_r31 > 0) && ((u32) temp_r31 <= 0x10000U)) {
            temp_r3 = ((TQuestVmDownLoadServer *)0x10000)->alloc();
            TScene__collision_file_buffer = temp_r3;
            if (temp_r3 != 0U) {
                scene_collision_data = (s32 *)load_relocatable_file((s32)((s32 *)&sp8), temp_r3);
                lbl_805D6014 = 0x10000;
            }
        }
    } else if (temp_r31 > 0) {
        temp_r3_2 = ((TQuestVmDownLoadServer *)temp_r31)->alloc();
        TScene__collision_file_buffer = temp_r3_2;
        if (temp_r3_2 != 0U) {
            scene_collision_data = (s32 *)load_relocatable_file((s32)((s32 *)&sp8), temp_r3_2);
            lbl_805D6014 = temp_r31;
        }
    }
    if (((s32 *) scene_collision_data != NULL) && (TObjMapCsn::get_map_count() != 0U)) {
        u32 temp_csn = TObjMapCsn::get_map_count();
        collect_collision_groups(temp_csn, *scene_collision_data);
        return;
    }
    debug_print__6TLobbyFle(lbl_8044A958);
}
void TScene::load_current_floor() {
    Ent_802066BC *tbl;
    s32 ent;
    s32 found;
    Res_80207038 res;
    s32 path[11];
    lbl_805D5FF8 = 0;
    TScene__map_rel_load_buffer = 0;
    TScene__collision_file_buffer = 0;
    TScene__supplementary_rel_buffer = 0;
    TScene__texture_animation_buffer = 0;
    TScene__data_805D6020 = 0;
    TScene__material_info_buffer = 0;
    lbl_805D600C = 0;
    TScene__map_rel_load_size_limit = 0;
    lbl_805D6014 = 0;
    TScene__loaded_floor_rel_file_index = 0;
    lbl_805D6018 = 0;
    floor_bin_file_size = 0;
    scene_file_buffer_size = 0;
    TScene__data_805D5FE8 = -1;
    if (get_floor_map_selection(current_floor_index, (u8 *)&res) == 1) {
        tbl = (Ent_802066BC *)get_floor_scene_table(res.table);
        scene_resource_index = res.index;
        ent = tbl[res.index].idx;
    }
    copy_name((s32)((s32 *)TScene__current_floor_name));
    TScene::load_scene_rel_file(ent);
    if (TScene__data_805D5FCC != NULL && *(u32 *)((s8 *)TScene__data_805D5FCC + 0x14) != 0) {
        found = 0;
        if (TRaderMapCore::is_not_split_screen() == 1) {
            replace_file_extension__6TLobbyFPvPvPv((char *)path, (char *)tbl[scene_resource_index].name, (char *)lbl_8044A97C);
            found = ((TScene *)path)->update_lobby_scene();
        }
        if (found <= 0) {
            replace_file_extension__6TLobbyFPvPvPv((char *)path, (char *)tbl[scene_resource_index].name, (char *)lbl_8044A984);
        }
        bind_gvm_texture_list(path, *(u32 *)((s8 *)TScene__data_805D5FCC + 0x14));
    }
    TScene::load_scene_data(ent);
    TScene::load_supplementary_t_rel(ent);
    TScene::load_map_texture_archive(ent);
    TScene::load_floor_bin_file(ent);
    TScene::load_file_to_buffer(ent);
    TScene__floor_scene_ready_flag = 1;
    TScene__data_805D5FE0 = 0;
    TScene__map_section_render_callback = 0;
    TScene__active_scene_callback = 0;
    TScene__render_callback = 0;
    TScene__visibility_radius_margin = TScene__data_805DC5D8;
}
