#include "types.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/misc/TScene.h"
#include "pso/object/TObjFish.h"
#include "pso/map/CurrentArea.h"

struct Ent_801FB798 { s32 a; char *name; };

extern u32 TRaderMapCore__data_805D5F4C;
extern "C" {
s32 get_current_floor();
s32 save_floor_discovery__13TRaderMapCoreFiPv(int, int);
s32 release_texture_list(int);
extern u8 *TRaderMapCore__floor_map_resource;
extern s32 TRaderMapCore__render_mode;
void copy_name(s32 arg0);
}
s32 create_named_object(s32 arg0);
extern "C" {
s32 replace_file_extension__6TLobbyFPvPvPv(char *arg0, char *arg1, char *arg2);
void init_radar_floor_flags(s32, u8 *);
s32 get_floor_scene_table(s32 arg0);
void bind_gvm_texture_list(char *, u8 *);
extern const char lbl_8044A7B0[];
extern s32 lbl_805D49B4;
extern s32 TRaderMapCore__data_805D5F30;
extern s8 lbl_805D5F34;
extern s32 lbl_805D5F38;
extern const char lbl_805DC5AC[2];
extern const char lbl_805DC5B0[3];
s32 TRaderMapCore__ct(void *, s32);
u32 __nw__7TObjectFUl(s32);

extern s32 tl_radermap;
extern s32 tl_clipout;

void TRaderMapCore::create() {
    void *obj;
    if ((TRaderMapCore::is_not_split_screen() != 1) || (TLobby::is_ready() != 1)) {
        if (TRaderMapCore::is_not_split_screen() == 1) {
            if ((obj = (void *) __nw__7TObjectFUl(0x1A4)) != 0) {
                TRaderMapCore__ct(obj, tl_clipout);
            }
        } else if ((obj = (void *) __nw__7TObjectFUl(0x1A4)) != 0) {
            TRaderMapCore__ct(obj, tl_radermap);
        }
    }
}

void TRaderMapCore::unload_floor_map() {
    u32 temp_r3;
    u8 *temp_r31;
    temp_r31 = (u8 *)TRaderMapCore__floor_map_resource;
    if (temp_r31 != NULL) {
        save_floor_discovery__13TRaderMapCoreFiPv((int) (get_current_floor()), (int)temp_r31);
    }
    TRaderMapCore::free_statics();
    if ((void *) TRaderMapCore__floor_map_resource != NULL) {
        temp_r3 = *(u32 *)((s8 *)TRaderMapCore__floor_map_resource + 4);
        if (temp_r3 != 0U) {
            release_texture_list((int)temp_r3);
        }
    }
    if ((void *) TRaderMapCore__floor_map_resource != NULL) {
        TLobby::free_nodes_with_id((int)TRaderMapCore__floor_map_resource);
        TRaderMapCore__floor_map_resource = NULL;
    }
    TRaderMapCore__render_mode = 0;
}

void TRaderMapCore::load_map_resources() {
    char buf[32];
    Ent_801FB798 *e;
    s32 status;
    s32 state;
    state = get_current_area();
    status = TScene::get_status();
    e = (Ent_801FB798 *)get_floor_scene_table(state);
    replace_file_extension__6TLobbyFPvPvPv((char *)buf, (char *)e[status].name, (char *)lbl_8044A7B0);
    TRaderMapCore__floor_map_resource = (u8 *)create_named_object((s32)buf);
    if (TRaderMapCore__floor_map_resource != NULL && *(u32 *)(TRaderMapCore__floor_map_resource + 4) != 0) {
        replace_file_extension__6TLobbyFPvPvPv((char *)buf, (char *)e[status].name, (char *)lbl_805DC5AC);
        bind_gvm_texture_list(buf, *(u8 **)(TRaderMapCore__floor_map_resource + 4));
    }
    copy_name((s32)lbl_805DC5B0);
    lbl_805D49B4 = 0;
    TRaderMapCore::load_frame_texture();
    e = (Ent_801FB798 *)TRaderMapCore__floor_map_resource;
    if (e != NULL) {
        init_radar_floor_flags(get_current_floor(), (u8 *)e);
    }
    TRaderMapCore__data_805D5F30 = 0;
    lbl_805D5F34 = 0;
    lbl_805D5F38 = 0;
    TRaderMapCore__render_mode = 1;
}

s32 TRaderMapCore::apply_compass_param() {
    if ((u32) TRaderMapCore__data_805D5F4C != 0U) {
        TObjFish::set_global_param((s32) TRaderMapCore__data_805D5F4C);
        return 1;
    }
    return -1;
}
}
