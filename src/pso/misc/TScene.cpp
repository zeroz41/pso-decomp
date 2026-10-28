#include "types.h"
#include "pso/map/FloorArea.h"
#include "pso/misc/TContainerAncient01.h"
#include "pso/misc/TScene.h"
#include "pso/misc/TLobby_80207644.h"
#include "pso/enemy/TObjEneRecon.h"
#include "pso/object/TObjDoorJung.h"
#include "pso/misc/TSceneMaterial.h"
#include "pso/TMainTask.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/text_802A8210.h"
#include "pso/item/TItemDrop_800F93F0.h"
#include "pso/misc/TLobby_80131794.h"
#include "pso/misc/TLobby_80207DA8.h"
#include "pso/unk/text_800F8A18.h"
#include "pso/misc/TQuestVmDownLoadServer.h"
#include "pso/object/TObjButterflyLobby.h"
#include "pso/object/TObjMapCsn.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct SurfaceAreaTable { s32 enabled[36]; };


extern SurfaceAreaTable player_auxiliary_surface_flag_table;

struct Tbl_8020335C { s32 v[8]; };


extern struct Tbl_8020335C group_selection_area_id_table;



struct FloorMapSelection {
    s32 area;
    u8 rest[0x8];
};


extern "C" s32 is_item_area_enabled(s32 area);


extern s32 boss_area_id_table[];

extern s32 item_disabled_area_table[];

struct Rec_80203510 { s32 id; f32 pos[3]; u8 pad[0xC]; f32 radius; u8 pad2[0x14]; };


struct Root_80203510 { u8 pad[8]; s16 count; u8 pad2[6]; Rec_80203510 *recs; };


struct Root_80204024 { u8 pad[0x178]; f32 x; f32 y; f32 z; };


struct Vec_80204024 { f32 x, y, z; };


struct Inner_802040D4 { u8 pad[0x20]; f32 radius; };


struct Obj_802040D4 { u8 pad[4]; Inner_802040D4 *inner; u8 pos[1]; };


struct Rec_8020430C { u8 pad0[4]; f32 pos[3]; u8 pad1[0x20]; u32 flags; };


struct Root_8020430C { u8 pad[8]; s16 count; u8 pad2[2]; f32 radius; Rec_8020430C *recs; };


struct W_8020430C { s32 a, b, c; };


struct Cam_8020430C { u8 pad[0x178]; W_8020430C pos; };


struct Obj_802040D4;


struct Obj_80204B78 { u8 pad0[4]; f32 x; f32 y; f32 z; u8 pad10[0xC]; f32 radius; u8 pad20[0x10]; u32 flags; };


typedef void (*RecoveredCallback_2be3cacebb2e)(void);

struct SceneMaterialRoot;

struct Motion_80203F0C { u8 pad[4]; u32 frames; };


struct Anim_80203F0C {
    u8 pad0[4];
    Motion_80203F0C *motion;
    u8 pad8[4];
    f32 frame;
    f32 speed;
    u8 pad14[8];
    u32 flags;
};


struct Group_80203F0C {
    u8 pad0[0x24];
    Anim_80203F0C *anims;
    u8 pad28[4];
    s32 count;
    u8 pad30[4];
};


struct Root_80203F0C { u8 pad[8]; s16 count; u8 pad2[6]; Group_80203F0C *groups; };


struct Vec_802043CC { f32 x, y, z; };


struct W_802043CC { s32 a, b, c; };


struct Cam_802043CC { u8 pad[0x178]; Vec_802043CC pos; u8 pad2[0x10]; s32 angY; u8 pad3[4]; s32 f19C; };


struct Ent_802043CC { s32 id; s32 n; s32 start; };


struct Tbl_802043CC { u32 pad; s32 count; Ent_802043CC ents[1]; };
extern "C" {

SceneMaterialSection *find_scene_room_by_id(s32 id);

void matrix_mult_vec(int, void *, void *);


bool is_in_view_depth__6TSceneFf(f32 farg0);

f32 xyz_distance_squared(u8 *arg0, u8 *arg1);


f32 vec3_dot(void *, void *);

f32 project_point_onto_line(void *, void *, void *);

extern Root_80204024 *camera_ctrl_instance;

s32 TScene__sub_80204024(f32 thr, s32 unused, void *a, void *b, Vec_80204024 *c);

f32 xz_distance_squared(void *, void *);

s32 TScene__sub_802040D4(void *arg0, Obj_802040D4 *o, f32 f0, f32 f1);


SceneMaterialNode* resolve_indirect_node_record(void*,SceneMaterialStatic*);

SceneMaterialNode* resolve_indirect_object_record(void*,SceneMaterialAnimated*);




extern u8 identity_matrix[];

void normalize_vector(Vec_80204024 *);

void push_matrix_from(void *);

void rotate_matrix_y(s32, s32);

void rotate_vector_by_matrix(s32, void *, Vec_80204024 *);

void pop_matrix(void);

s32 check_object_in_view_cone__6TSceneFiPvPvPvi(s32 arg0, Obj_80204B78 *obj, Vec_80204024 *pos, void *arg3, s32 arg4);

extern s32 model_render_flags;

extern s32 saved_model_render_flags;

void prepare_ginja_model(void);

void push_matrix(void);

void post_translate_matrix(f32 *);

void rotate_matrix_by_node_angles(s32 *, s32);



f32 fabs_float(f32);

void PPCSync();



void scroll_ginja_mesh_uvs(void *, s32, s32, u16, s32);


struct Vec_8020533C { f32 x, y, z; };

struct Ang_8020533C { s32 x, y, z; };

struct Node_8020533C { u8 pad0[8]; Vec_8020533C pos; Ang_8020533C ang; };

struct Model_8020533C { u8 pad0[4]; void *tex; s32 f8; u8 padC[2]; u8 fE; u8 fF; };

struct Lobby_8020533C { Vec_8020533C v; Ang_8020533C a; void *param; Node_8020533C *node; s16 scene; u8 id; };


void render_projected_shadow_receiver(void *, void *);

void draw_field_1c__6TSceneFlll(void *, s32, s32, s32);

void release_indexed_entry__6TLobbyFl(Lobby_8020533C *);

void vec3_add_to(void *, void *);

void draw_ginja_object(void *);

void set_material_alpha_compare_reference(s32 reference);


void VecCopy__FP3VecPC3Vec(void *, void *);


void subtract_vector(void *, void *);
}


void end_ginja_model_draw(void);

extern W_802043CC lbl_8044A858[];



struct SceneFormatEntry {
    const char *name;
    s32 format;
};

struct SceneMemberPointerBits {
    s32 thisAdjustment;
    s32 virtualOffset;
    void (*function)();
};

struct SceneDispatchPrefix {
    SceneFormatEntry formats[3];
    SceneMemberPointerBits initializeTemplate[2];
    SceneMemberPointerBits initializeStorage[2];
    SceneMemberPointerBits cleanupTemplate[2];
    SceneMemberPointerBits cleanupStorage[2];
};

typedef char SceneDispatchPrefix_size[sizeof(SceneDispatchPrefix) == 0x78 ? 1 : -1];

struct Task_80204688;
extern "C" {

extern const char lbl_8044A7F0[];

extern const char lbl_8044A7F8[];

void initialize_fmt1_materials__6TSceneFv(void *);

void initialize_fmt2_materials__6TSceneFv();

void TScene__sub_80205FD0(void);

void TScene__sub_80205ECC(void);

s32 TScene__sub_80205874(void*);

void *get_player_by_client_id(s32 i);
}

struct Cam_80204688 { u8 pad[0x178]; f32 x; f32 y; f32 z; u8 pad184[0x194 - 0x184]; s32 a194; u8 pad198[4]; s32 a19C; };

struct Task_80204688 { u8 pad[0x1C]; s32 count; };

struct Model_80204688 { u8 pad[0x14]; f32 x, y, z; };

struct Node_80204688 { u32 flags; Model_80204688 *model; f32 x, y, z; };
extern "C" {







extern Vec_80204024 lbl_8044A84C[];

void pop_matrices(s32);

s32 is_split_screen(void);
#define CAM ((Cam_80204688 *)camera_ctrl_instance)
#define TEST ((s32 (*)(f32, void *, void *, void *, Vec_80204024 *))TScene__sub_80204024)
#define VIS ((s32 (*)(void *, void *, f32, f32))is_in_view_depth__6TSceneFf)
}

struct Ent_80205AA8 { u16 id; u8 pad[6]; };


struct Tbl_80205AA8 { s32 x; s32 count; Ent_80205AA8 e[1]; };
extern "C" {

Ent_80205AA8 *find_material_entry_by_id__6TSceneFPvUs(void *self, u16 id);

}

struct Cyc_80205D24 { u16 id; u16 reserved; s16 texture; s16 index; s32 timer; };


struct Uv_80205DE4 { u16 id; };

struct Node_80205AEC { u32 flags; void *obj; u32 tex; u16 id; u8 b; u8 c; };


struct Info_80205AEC { u8 a0; u8 a1; u8 tex; u8 b; u8 c; };


struct Def_80206058 { u16 id, texture; f32 u, v, du, dv; };
extern "C" {

u8 *construct_pvr_wave__6TSceneFPvPvPvii(void *, s32, s32, s32, s32);

u8 *__nw__7TObjectFUl(s32);

s32 find_uv_animation__6TSceneFPvPv(void *task, Uv_80205DE4 *uv);

extern u32 lbl_8044A800[];

extern u8 lbl_8044A80C[];

}

struct RecoveredGlobal_8020650C___vt__6TScene { s32 value; u8 remaining[0x14]; };

typedef char RecoveredGlobal_8020650C___vt__6TScene_size[sizeof(RecoveredGlobal_8020650C___vt__6TScene) == 0x18 ? 1 : -1];


struct Ent_802066BC { char *name; s32 idx; };


struct Res_8020681C { s32 table; s32 index; s32 pad; };


struct Res_80207038 { s32 table; s32 index; s32 pad; };
extern "C" {

s32 get_player_name_copy_buffer();

s32 strncmp(s32, s32, s32);

s32 release_texture_list(u32);

extern s32 *scene_collision_data;



s32 __ct__7TObjectFP7TObject(void *, void *);

extern s32 __vt__6TScene[];



void bind_gvm_texture_list(s32 *, u32);



s32 debug_print__6TLobbyFle(s32 *, ...);

s32 collect_collision_groups(u32, s32);




s32 read_disc_file(char *, u32);





struct Sp8Buf20_80206494 {
    s32 f0; s32 f4; s32 f8; s32 fc;
    s32 f10; s32 f14; s32 f18; s32 f1c;
};


void TScene__sub_80205AE8(s32 *);

}





#pragma readonly_strings on

const char *TScene__current_floor_name = "SCENE";
s32 lbl_805D3614 = 10;
Ent_802066BC scene_format_dispatch_tables[] = {
    {"fmt1", 0},
    {"fmt2", 1},
    {NULL, -1},
};
__declspec(section ".rodata") u32 lbl_8044A800[3] = {0, 1, 2};
__declspec(section ".rodata") u8 lbl_8044A80C[8] = {0, 1, 2, 3, 4, 0, 0, 0};
__declspec(section ".rodata") s32 boss_area_id_table[] = {
    AREA_DRAGON, AREA_DE_ROL_LE, AREA_VOL_OPT, AREA_DARK_FALZ,
    AREA_GAL_GRYPHON, AREA_OLGA_FLOW, AREA_BARBA_RAY, AREA_GOL_DRAGON, -1,
};
const char *TScene__class_name = "TScene";
__declspec(section ".rodata") Vec_80204024 lbl_8044A840[1] = {{0.0f, 0.0f, -1.0f}};
__declspec(section ".rodata") Vec_80204024 lbl_8044A84C[1] = {{0.0f, 0.0f, -1.0f}};
__declspec(section ".rodata") W_802043CC lbl_8044A858[1] = {{0, 0, (s32)0xBF800000}};
__declspec(section ".rodata") s32 item_disabled_area_table[] = {AREA_PIONEER2_EP1, AREA_LOBBY, AREA_PIONEER2_EP2, -1};
__declspec(section ".rodata") Tbl_8020335C group_selection_area_id_table = {{
    AREA_CENTRAL_CONTROL_AREA, AREA_JUNGLE_NORTH, AREA_JUNGLE_EAST, AREA_MOUNTAIN,
    AREA_SEASIDE, AREA_SEASIDE_NIGHT, AREA_TOWER, -1,
}};
__declspec(section ".rodata") SurfaceAreaTable player_auxiliary_surface_flag_table = {{
    0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 0,
    1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
}};

s32 current_floor_index;
floor_area current_floor_area_type;
s32 scene_resource_index;
SceneMaterialRoot *TScene__data_805D5FCC;
u32 TScene__texture_wave_resource;
s8 TScene__floor_scene_ready_flag;
s32 current_lobby_id;
s32 lobby_online_ready_flag;
s32 TScene__data_805D5FE0;
f32 TScene__visibility_radius_margin;
s32 TScene__data_805D5FE8;
void (*TScene__map_section_render_callback)(Vec_8020533C *, Ang_8020533C *, u32);
void (*TScene__active_scene_callback)(u32);
RecoveredCallback_2be3cacebb2e TScene__render_callback;
s32 lbl_805D5FF8;
u32 TScene__map_rel_load_buffer;
u32 TScene__collision_file_buffer;
u32 TScene__texture_animation_buffer;
u32 TScene__supplementary_rel_buffer;
s32 lbl_805D600C;
s32 TScene__map_rel_load_size_limit;
s32 lbl_805D6014;
s32 lbl_805D6018;
s32 TScene__loaded_floor_rel_file_index;
u32 TScene__data_805D6020;
s32 floor_bin_file_size;
u32 TScene__material_info_buffer;
s32 scene_file_buffer_size;

extern "C" {
u8 *TScene__ct(TScene *scene, s32 arg1);
void TScene__sub_802065E8(void);
void TScene__sub_802065EC(void);
s32 load_texture_sequence_frame(void *task, Cyc_80205D24 *c);
}
void load_scene_map_file(s32 arg0);
void load_scene_collision_file(s32 name);
void load_floor_scene(void);

s32 player_auxiliary_surfaces_enabled() {
    SurfaceAreaTable table = player_auxiliary_surface_flag_table;
    return table.enabled[get_current_floor_area()];
}

SceneMaterialNode *resolve_indirect_object_record(void *, SceneMaterialAnimated *record) {
    if (record->flags & 0x200) {
        return *(SceneMaterialNode **)record->node;
    }
    return record->node;
}

SceneMaterialNode *resolve_indirect_node_record(void *, SceneMaterialStatic *record) {
    if (record->flags & 0x200) {
        return *(SceneMaterialNode **)record->node;
    }
    return record->node;
}

void TScene::set_instance(int a0) { TScene__render_callback = (RecoveredCallback_2be3cacebb2e)a0; }

void TScene::set_active_scene(int a0) { TScene__active_scene_callback = (void (*)(u32))a0; }

void TScene::set_id(int a0) { TScene__map_section_render_callback = (void (*)(Vec_8020533C *, Ang_8020533C *, u32))a0; }

s32 TContainerAncient01::is_global_state_in_table() {
    struct Tbl_8020335C t = group_selection_area_id_table;
    s32 area = get_current_floor_area();
    s32 i;
    for (i = 0; t.v[i] != -1;) {
        if (area == t.v[i++]) {
            return 1;
        }
    }
    return 0;
}

s32 is_warp_excluded_area(s32 area) {
    s32 i = 0;
    while (boss_area_id_table[i] != -1) {
        if (area == boss_area_id_table[i++]) return 1;
    }
    return 0;
}

s32 is_boss_area() {
    s32 area = get_current_floor_area();
    s32 i = 0;
    while (boss_area_id_table[i] != -1) {
        if (area == boss_area_id_table[i++]) return 1;
    }
    return 0;
}

void set_current_floor_area(s32 floor) {
    FloorMapSelection selection;
    current_floor_index = floor;
    if (get_floor_map_selection(floor, (u8 *)&selection.area) == 1) {
        current_floor_area_type = (floor_area)selection.area;
    }
}

floor_area get_current_floor_area() {
    return current_floor_area_type;
}

s32 is_item_area_enabled(s32 area) {
    s32 i = 0;
    while (item_disabled_area_table[i] != -1) {
        if (area == item_disabled_area_table[i++]) return 0;
    }
    return 1;
}

s32 is_current_area_item_enabled() {
    return is_item_area_enabled(get_current_floor_area());
}

s32 TScene::find_section_at_position() {
    Rec_80203510 *r;
    s32 best = -1;
    s32 i;
    f32 bestd;
    if ((*(Root_80203510 * *)&TScene__data_805D5FCC) == NULL) {
        return -1;
    }
    bestd = 1000000000.0f;
    r = (*(Root_80203510 * *)&TScene__data_805D5FCC)->recs;
    for (i = 0; i < (*(Root_80203510 * *)&TScene__data_805D5FCC)->count; i++, r++) {
        if (r->id >= 0) {
            f32 d = xyz_distance_squared((u8 *)this, (u8 *)r->pos);
            if (!(d > r->radius * r->radius) && d < bestd) {
                bestd = d;
                best = r->id;
            }
        }
    }
    return best;
}

s32 TScene::get_player_ctrl_field(u16 arg0) {
    u32 player;

    player = (u32)get_player_by_client_id((arg0));
    if (player != 0U) {
        return ((TScene *)(player + 0x38))->find_section_at_position();
    }
    return -1;
}

SceneMaterialSection *find_scene_room_by_id(s32 id) {
    s32 i;
    s16 count = TScene__data_805D5FCC->count;
    for (i = 0; i < count; i++) {
        if (TScene__data_805D5FCC->sections[i].id == id) {
            return &TScene__data_805D5FCC->sections[i];
        }
    }
    return NULL;
}

void TScene::tick_material_fmt2() {
    SceneMaterialSection *room;
    s32 section;
    SceneMaterialStatic *object;
    s32 i;
    SceneMaterialAnimated *anim;
    SceneMaterialNode *node;
    SceneMaterialUv *uv;
    if ((*(void * *)&TScene__texture_animation_buffer) == NULL || (*(SceneMaterialRoot * *)&TScene__data_805D5FCC) == NULL) {
        return;
    }
    room = (*(SceneMaterialRoot * *)&TScene__data_805D5FCC)->sections;
    for (section = 0; section < (*(SceneMaterialRoot * *)&TScene__data_805D5FCC)->count; section++, room++) {
        SceneMaterialStatic *o2;
        s32 k;
        o2 = room->objects;
        for (k = 0; k < room->count; k++, o2++) {
            o2->flags &= ~0x20000;
        }
        {
            SceneMaterialAnimated *a2;
            s32 k2;
            a2 = room->animated;
            for (k2 = 0; k2 < room->animatedCount; k2++, a2++) {
                a2->flags &= ~0x20000;
            }
        }
    }
    room = (*(SceneMaterialRoot * *)&TScene__data_805D5FCC)->sections;
    for (section = 0; section < (*(SceneMaterialRoot * *)&TScene__data_805D5FCC)->count; section++, room++) {
        object = room->objects;
        for (i = 0; i < room->count; i++, object++) {
            if (object->flags & 0x20000) {
                continue;
            }
            if (object->flags & 0x04000000) {
                continue;
            }
            node = ((SceneMaterialNode *)resolve_indirect_node_record(this, (SceneMaterialStatic*)(object)));
            if (object->flags & 0x20) {
                uv = object->uv;
                uv->u += uv->du;
                uv->v += uv->dv;
                if (fabs_float(uv->u) >= 1.0f || fabs_float(uv->v) >= 1.0f) {
                    if (uv->buffer != NULL) {
                        ((TScene *)(uv->buffer))->offset_position((s32)((s32)uv->u), (s32)((s32)uv->v));
                    }
                    uv->u -= (f32)(s32)uv->u;
                    uv->v -= (f32)(s32)uv->v;
                }
            }
            if (object->flags & 0x40) {
                object->cycle->timer--;
                if (object->cycle->timer < 0) {
                    (*(s16 *)&object->cycle->index)++;
                    load_texture_sequence_frame(this, (Cyc_80205D24 *)(object->cycle));
                    ((TObjDoorJung *)(node->model))->free_children((void *)object->cycle->texture);
                    if (object->flags & 0x20) {
                        object->uv->texture = object->cycle->texture;
                    }
                }
            }
            object->flags |= 0x20000;
        }
        anim = room->animated;
        for (i = 0; i < room->animatedCount; i++, anim++) {
            if (anim->flags & 0x20000) {
                continue;
            }
            if (anim->flags & 0x04000000) {
                continue;
            }
            node = ((SceneMaterialNode *)resolve_indirect_object_record(this, (SceneMaterialAnimated*)(anim)));
            if (anim->flags & 0x20) {
                uv = anim->uv;
                uv->u += uv->du;
                uv->v += uv->dv;
                if (uv->u >= 1.0f || uv->v >= 1.0f) {
                    if (uv->buffer != NULL) {
                        ((TScene *)(uv->buffer))->offset_position((s32)((s32)uv->u), (s32)((s32)uv->v));
                    }
                    uv->u -= (f32)(s32)uv->u;
                    uv->v -= (f32)(s32)uv->v;
                }
            }
            if (anim->flags & 0x40) {
                anim->cycle->timer--;
                if (anim->cycle->timer < 0) {
                    (*(s16 *)&anim->cycle->index)++;
                    load_texture_sequence_frame(this, (Cyc_80205D24 *)(anim->cycle));
                    ((TObjDoorJung *)(node->model))->free_children((void *)anim->cycle->texture);
                }
            }
            anim->flags |= 0x20000;
        }
    }
    PPCSync();
}

void TScene::tick_material_fmt1() {
    SceneMaterialSection *room;
    s32 section;
    SceneMaterialStatic *object;
    s32 i;
    SceneMaterialAnimated *anim;
    SceneMaterialNode *node;
    SceneMaterialUv *uv;
    if ((*(void * *)&TScene__texture_animation_buffer) == NULL || (*(SceneMaterialRoot * *)&TScene__data_805D5FCC) == NULL) {
        return;
    }
    room = (*(SceneMaterialRoot * *)&TScene__data_805D5FCC)->sections;
    for (section = 0; section < (*(SceneMaterialRoot * *)&TScene__data_805D5FCC)->count; section++, room++) {
        SceneMaterialStatic *o2;
        s32 k;
        o2 = room->objects;
        for (k = 0; k < room->count; k++, o2++) {
            o2->flags &= ~0x20000;
        }
        {
            SceneMaterialAnimated *a2;
            s32 k2;
            a2 = room->animated;
            for (k2 = 0; k2 < room->animatedCount; k2++, a2++) {
                a2->flags &= ~0x20000;
            }
        }
    }
    room = (*(SceneMaterialRoot * *)&TScene__data_805D5FCC)->sections;
    for (section = 0; section < (*(SceneMaterialRoot * *)&TScene__data_805D5FCC)->count; section++, room++) {
        object = room->objects;
        for (i = 0; i < room->count; i++, object++) {
            if (object->flags & 0x20000) {
                continue;
            }
            if (object->flags & 0x04000000) {
                continue;
            }
            node = ((SceneMaterialNode *)resolve_indirect_node_record(this, (SceneMaterialStatic*)(object)));
            if (object->flags & 0x20) {
                uv = object->uv;
                uv->u += uv->du;
                uv->v += uv->dv;
                if (fabs_float(uv->u) >= 1.0f || fabs_float(uv->v) >= 1.0f) {
                    scroll_ginja_mesh_uvs(node->model, (s32)uv->u, (s32)uv->v, uv->texture, 1);
                    uv->u -= (f32)(s32)uv->u;
                    uv->v -= (f32)(s32)uv->v;
                }
            }
            if (object->flags & 0x40) {
                object->cycle->timer--;
                if (object->cycle->timer < 0) {
                    (*(s16 *)&object->cycle->index)++;
                    load_texture_sequence_frame(this, (Cyc_80205D24 *)(object->cycle));
                    ((TObjDoorJung *)(node->model))->free_children((void *)object->cycle->texture);
                    if (object->flags & 0x20) {
                        object->uv->texture = object->cycle->texture;
                    }
                }
            }
            object->flags |= 0x20000;
        }
        anim = room->animated;
        for (i = 0; i < room->animatedCount; i++, anim++) {
            if (anim->flags & 0x20000) {
                continue;
            }
            if (anim->flags & 0x04000000) {
                continue;
            }
            node = ((SceneMaterialNode *)resolve_indirect_object_record(this, (SceneMaterialAnimated*)(anim)));
            if (anim->flags & 0x20) {
                uv = anim->uv;
                uv->u += uv->du;
                uv->v += uv->dv;
                if (uv->u >= 1.0f || uv->v >= 1.0f) {
                    scroll_ginja_mesh_uvs(node->model, (s32)uv->u, (s32)uv->v, uv->texture, 1);
                    uv->u -= (f32)(s32)uv->u;
                    uv->v -= (f32)(s32)uv->v;
                }
            }
            if (anim->flags & 0x40) {
                anim->cycle->timer--;
                if (anim->cycle->timer < 0) {
                    (*(s16 *)&anim->cycle->index)++;
                    load_texture_sequence_frame(this, (Cyc_80205D24 *)(anim->cycle));
                    ((TObjDoorJung *)(node->model))->free_children((void *)anim->cycle->texture);
                }
            }
            anim->flags |= 0x20000;
        }
    }
    PPCSync();
}

#pragma defer_codegen on

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
            replace_file_extension__6TLobbyFPvPvPv((char *)path, (char *)tbl[scene_resource_index].name, (char *)"m.gvm");
            found = ((TScene *)path)->update_lobby_scene();
        }
        if (found <= 0) {
            replace_file_extension__6TLobbyFPvPvPv((char *)path, (char *)tbl[scene_resource_index].name, (char *)".gvm");
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
    TScene__visibility_radius_margin = 0.0f;
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
    replace_file_extension__6TLobbyFPvPvPv((char *)((s32 *)((s32 *)&sp8)), (char *)(name), (char *)("c.rel"));
    temp_r31 = ((TScene *)((s32 *)&sp8))->update_lobby_scene();
    if (get_current_floor_area() == AREA_LOBBY) {
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
    debug_print__6TLobbyFle((s32 *)"TScene : CANNOT LOAD COLLISION DATA");
}

void TScene::load_scene_rel_file(s32 arg0) {
    u8 id[0x28];
    s32 area;
    s32 size;
    area = get_current_floor_area();
    TScene__data_805D5FCC = NULL;
    size = 0;
    TScene__map_rel_load_buffer = 0U;
    TScene__map_rel_load_size_limit = 0;
    TScene__data_805D5FE8 = -1;
    if (TRaderMapCore::is_not_split_screen() == 1) {
        replace_file_extension__6TLobbyFPvPvPv((char *)((s32 *)id), (char *)arg0, (char *)((s32 *)"nm.rel"));
        size = ((TScene *)id)->update_lobby_scene();
    }
    if (size <= 0) {
        replace_file_extension__6TLobbyFPvPvPv((char *)((s32 *)id), (char *)arg0, (char *)((s32 *)"n.rel"));
        size = ((TScene *)id)->update_lobby_scene();
    }
    if (area == AREA_LOBBY) {
        if (size > 0 && (u32)size <= 0x80000U) {
            TScene__map_rel_load_buffer = ((TQuestVmDownLoadServer *)0x80000)->alloc();
            if (TScene__map_rel_load_buffer != 0U) {
                TScene__data_805D5FCC = (SceneMaterialRoot *)load_relocatable_file((s32)((s32 *)id), TScene__map_rel_load_buffer);
                TScene__map_rel_load_size_limit = 0x80000;
            }
        }
    } else if (size > 0) {
        TScene__map_rel_load_buffer = ((TQuestVmDownLoadServer *)size)->alloc();
        if (TScene__map_rel_load_buffer != 0U) {
            TScene__data_805D5FCC = (SceneMaterialRoot *)load_relocatable_file((s32)((s32 *)id), TScene__map_rel_load_buffer);
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

void TScene::load_supplementary_t_rel(s32 name) {
    u8 id[0x20];
    s32 n;
    TScene__texture_wave_resource = 0;
    TScene__supplementary_rel_buffer = 0U;
    TScene__loaded_floor_rel_file_index = 0;
    replace_file_extension__6TLobbyFPvPvPv((char *)((s32 *)id), (char *)name, (char *)((s32 *)"t.rel"));
    n = ((TScene *)id)->update_lobby_scene();
    if (n > 0) {
        TScene__supplementary_rel_buffer = ((TQuestVmDownLoadServer *)n)->alloc();
        if (TScene__supplementary_rel_buffer != 0U) {
            TScene__texture_wave_resource = (u32)load_relocatable_file((s32)((s32 *)id), TScene__supplementary_rel_buffer);
            TScene__loaded_floor_rel_file_index = n;
        }
    }
}

void TScene::load_map_texture_archive(s32 name) {
    char sp8[0x20];
    s32 area;
    s32 var_r30;
    u32 temp_r3;
    u32 temp_r3_2;

    area = get_current_floor_area();
    TScene__texture_animation_buffer = 0U;
    var_r30 = 0;
    lbl_805D6018 = 0;
    if (TRaderMapCore::is_not_split_screen() == 1) {
        replace_file_extension__6TLobbyFPvPvPv((char *)(sp8), (char *)(name), (char *)("m.tam"));
        var_r30 = ((TScene *)sp8)->update_lobby_scene();
    }
    if (var_r30 <= 0) {
        replace_file_extension__6TLobbyFPvPvPv((char *)(sp8), (char *)(name), (char *)(".tam"));
        var_r30 = ((TScene *)sp8)->update_lobby_scene();
    }
    if (area == AREA_LOBBY) {
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

void TScene::load_floor_bin_file(s32 name) {
    u8 sp8[0x20];
    s32 size;
    TScene__data_805D6020 = 0U;
    floor_bin_file_size = 0;
    if (TRaderMapCore::is_not_split_screen() == 1) {
        replace_file_extension__6TLobbyFPvPvPv((char *)((s32 *)sp8), (char *)name, (char *)((s32 *)"bm.bin"));
    } else {
        replace_file_extension__6TLobbyFPvPvPv((char *)((s32 *)sp8), (char *)name, (char *)((s32 *)"b.bin"));
    }
    size = ((TScene *)sp8)->update_lobby_scene();
    if (get_current_floor_area() == AREA_LOBBY) {
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

void TScene::load_file_to_buffer(s32 name) {
    s32 sp8[8];
    s32 temp_r31;
    u32 temp_r3;
    u32 temp_r3_2;

    TScene__material_info_buffer = 0U;
    scene_file_buffer_size = 0;
    replace_file_extension__6TLobbyFPvPvPv((char *)(sp8), (char *)(name), (char *)("i.bin"));
    temp_r31 = ((TScene *)sp8)->update_lobby_scene();
    if (get_current_floor_area() == AREA_LOBBY) {
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
    if (strncmp(get_player_name_copy_buffer(), (s32)TScene__current_floor_name, 0x10) == 0) {
        copy_name((s32)"..");
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
            replace_file_extension__6TLobbyFPvPvPv((char *)path, (char *)tbl[scene_resource_index].name, (char *)"m.gvm");
            found = ((TScene *)path)->update_lobby_scene();
        }
        if (found <= 0) {
            replace_file_extension__6TLobbyFPvPvPv((char *)path, (char *)tbl[scene_resource_index].name, (char *)".gvm");
        }
        bind_gvm_texture_list(path, *(u32 *)((s8 *)TScene__data_805D5FCC + 0x14));
    }
    TScene::load_floor_rel_file(ent);
    TScene::load_tam_file(ent);
    ((void (*)(s32))TScene__sub_802065EC)(ent);
    ((void (*)(s32))TScene__sub_802065E8)(ent);
    copy_name((s32)"..");
    TScene__floor_scene_ready_flag = 1;
    TScene__data_805D5FE0 = 0;
    TScene__map_section_render_callback = 0;
    TScene__active_scene_callback = 0;
    TScene__render_callback = 0;
    TScene__visibility_radius_margin = 0.0f;
}

void load_scene_collision_file(s32 name) {
    struct Sp8Buf20_80206494 sp8;
    replace_file_extension__6TLobbyFPvPvPv((char *)((s32 *)&sp8), (char *)name, (char *)"c.rel");
    if (((TScene *)((char *)&sp8))->update_lobby_scene() <= lbl_805D6014) {
        if (TScene__collision_file_buffer != 0U) {
            scene_collision_data = (s32 *)load_relocatable_file((s32)((s32 *)&sp8), TScene__collision_file_buffer);
            if (scene_collision_data != NULL && TObjMapCsn::get_map_count() != 0U) {
                u32 csn = TObjMapCsn::get_map_count();
                collect_collision_groups(csn, *scene_collision_data);
                return;
            }
            debug_print__6TLobbyFle((s32 *)"TScene : CANNOT LOAD COLLISION DATA");
            return;
        }
        scene_collision_data = NULL;
    }
}

void load_scene_map_file(s32 arg0) {
    u8 id[0x20];
    Ent_802066BC *e;
    TScene__data_805D5FCC = NULL;
    TScene__data_805D5FE8 = -1;
    replace_file_extension__6TLobbyFPvPvPv((char *)((s32 *)id), (char *)arg0, (char *)((s32 *)"n.rel"));
    if (((TScene *)id)->update_lobby_scene() <= TScene__map_rel_load_size_limit && TScene__map_rel_load_buffer != 0) {
        TScene__data_805D5FCC = (SceneMaterialRoot *)load_relocatable_file((s32)((s32 *)id), TScene__map_rel_load_buffer);
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

void TScene::load_tam_file(s32 name) {
    u8 sp8[0x20];
    replace_file_extension__6TLobbyFPvPvPv((char *)((s32 *)sp8), (char *)name, (char *)((s32 *)".tam"));
    if (((TScene *)sp8)->update_lobby_scene() <= lbl_805D6018) {
        if (TScene__texture_animation_buffer != 0U) {
            read_disc_file((char *)sp8, TScene__texture_animation_buffer);
        } else {
            TScene__texture_animation_buffer = 0;
        }
    }
}

void TScene::load_floor_rel_file(s32 name) {
    u8 id[0x20];
    replace_file_extension__6TLobbyFPvPvPv((char *)((s32 *)id), (char *)name, (char *)((s32 *)"t.rel"));
    if (((TScene *)id)->update_lobby_scene() <= TScene__loaded_floor_rel_file_index) {
        if (TScene__supplementary_rel_buffer != 0U) {
            TScene__texture_wave_resource = (u32)load_relocatable_file((s32)((s32 *)id), TScene__supplementary_rel_buffer);
        } else {
            TScene__texture_wave_resource = 0;
        }
    }
}

void TScene__sub_802065EC(void) {  }

void TScene__sub_802065E8(void) {  }

void TScene::create() {
    void *o;
    o = __nw__7TObjectFUl(0x40);
    if (o != NULL) {
        TScene__ct((TScene *)((u8 *)o), (s32)tl_02);
    }
}

u8 *TScene__ct(TScene *scene, s32 arg1) {
    __ct__7TObjectFP7TObject((void *)scene, (void *)arg1);
    *(s32 **)((s8 *)scene + 0x18) = &(*(RecoveredGlobal_8020650C___vt__6TScene *)&__vt__6TScene).value;
    *(s32 *)((s8 *)scene + 0) = (s32)TScene__class_name;
    scene->m_1c = 0;
    scene->m_30 = 0;
    scene->m_34 = 0;
    scene->m_38 = 0x32;
    scene->m_3c = 0;
    scene->initialize_materials();
    if ((get_current_floor_area() == AREA_FOREST1) && ((u32) TScene__texture_wave_resource != 0U) && ((void *) (*(u8 * *)&TScene__data_805D5FCC) != NULL) && ((u32) *(u32 *)((s8 *)(*(u8 * *)&TScene__data_805D5FCC) + 0x14) != 0U)) {
        TScene::create_texture_wave_tasks((s32)scene);
    }
    scene->init_material_nodes();
    return (u8 *)scene;
}

TScene::~TScene() {
    TScene__sub_80205AE8((s32 *)this);
    cleanup_materials();
    TScene__map_section_render_callback = 0;
    TScene__active_scene_callback = 0;
    TScene__render_callback = 0;
}

void TScene::initialize_materials() {
    typedef void (TScene::*MaterialInitializer)();
    static MaterialInitializer fns[2] = {
        &TScene::initialize_fmt1_materials,
        &TScene::initialize_fmt2_materials,
    };
    (this->*fns[TScene__data_805D5FE8])();
}

void TScene::initialize_fmt1_materials() {
    SceneMaterialSection *room;
    s32 section;
    SceneMaterialStatic *object;
    s32 i;
    SceneMaterialAnimated *anim;
    s32 j;
    if (!TScene__texture_animation_buffer || !TScene__data_805D5FCC) return;
    room = TScene__data_805D5FCC->sections;
    for (section = 0; section < TScene__data_805D5FCC->count; section++, room++) {
        object = room->objects;
        for (i = 0; i < room->count; i++, object++) {
            if ((object->flags & 0x20) && !find_uv_animation__6TSceneFPvPv(this, (Uv_80205DE4 *)object->uv)) object->flags &= ~0x20;
            if ((object->flags & 0x40) && !load_texture_sequence_frame(this, (Cyc_80205D24 *)object->cycle)) object->flags &= ~0x40;
        }
        anim = room->animated;
        for (j = 0; j < room->animatedCount; j++, anim++) {
            if ((anim->flags & 0x20) && !find_uv_animation__6TSceneFPvPv(this, (Uv_80205DE4 *)anim->uv)) anim->flags &= ~0x20;
            if ((anim->flags & 0x40) && !load_texture_sequence_frame(this, (Cyc_80205D24 *)anim->cycle)) anim->flags &= ~0x40;
        }
    }
}

void TScene::initialize_fmt2_materials() {
    SceneMaterialSection *room;
    s32 section;
    SceneMaterialStatic *object;
    s32 i;
    void *task = this;
    SceneMaterialAnimated *anim;
    s32 j;
    if (!TScene__texture_animation_buffer || !TScene__data_805D5FCC) return;
    room = TScene__data_805D5FCC->sections;
    for (section = 0; section < TScene__data_805D5FCC->count; section++, room++) {
        object = room->objects;
        for (i = 0; i < room->count; i++, object++) {
            if (object->flags & 0x20) {
                SceneMaterialUv *uv = object->uv;
                if (uv->buffer) continue;
                Def_80206058 def;
                def.id = uv->id;
                if (find_uv_animation__6TSceneFPvPv(task, (Uv_80205DE4 *)&def) == 1) {
                    uv->id = def.id; uv->texture = def.texture;
                    uv->u = def.u; uv->v = def.v; uv->du = def.du; uv->dv = def.dv;
                    SceneMaterialNode *node = resolve_indirect_node_record(task, object);
                    void *buffer = ::operator new(20);
                    if (buffer) buffer = ((TScene *)buffer)->init_buffers((s32)node, uv->texture);
                    uv->buffer = buffer;
                } else {
                    object->flags &= ~0x20;
                }
            }
            if ((object->flags & 0x40) && !load_texture_sequence_frame(task, (Cyc_80205D24 *)object->cycle)) object->flags &= ~0x40;
        }
        anim = room->animated;
        for (j = 0; j < room->animatedCount; j++, anim++) {
            if (anim->flags & 0x20) {
                SceneMaterialUv *uv2 = anim->uv;
                if (uv2->buffer) continue;
                Def_80206058 def2;
                def2.id = uv2->id;
                if (find_uv_animation__6TSceneFPvPv(task, (Uv_80205DE4 *)&def2) == 1) {
                    uv2->id = def2.id; uv2->texture = def2.texture;
                    uv2->u = def2.u; uv2->v = def2.v; uv2->du = def2.du; uv2->dv = def2.dv;
                    SceneMaterialNode *node2 = resolve_indirect_object_record(task, anim);
                    void *buffer2 = ::operator new(20);
                    if (buffer2) buffer2 = ((TScene *)buffer2)->init_buffers((s32)node2, uv2->texture);
                    uv2->buffer = buffer2;
                } else {
                    anim->flags &= ~0x20;
                }
            }
            if ((anim->flags & 0x40) && !load_texture_sequence_frame(task, (Cyc_80205D24 *)anim->cycle)) anim->flags &= ~0x40;
        }
    }
}

void TScene::cleanup_materials() {
    typedef void (TScene::*MaterialCleanup)();
    static MaterialCleanup fns[2] = {
        &TScene::cleanup_fmt1_materials,
        &TScene::cleanup_fmt2_materials,
    };
    (this->*fns[TScene__data_805D5FE8])();
}

extern "C" {
void TScene::cleanup_fmt1_materials() {  }
}

void TScene::cleanup_fmt2_materials() {
    s32 i;
    s32 j;
    SceneMaterialUv *uv;
    s32 k;
    SceneMaterialUv *uv2;
    if (TScene__data_805D5FCC != NULL) {
        for (i = 0; i < TScene__data_805D5FCC->count; i++) {
            SceneMaterialSection *sections = TScene__data_805D5FCC->sections;
            for (j = 0; j < sections[i].count; j++) {
                if (sections[i].objects[j].flags & 0x20) {
                    uv = sections[i].objects[j].uv;
                    if (uv->buffer != NULL) {
                        ((TScene *)uv->buffer)->destroy_buffers(1);
                        uv->buffer = NULL;
                    }
                }
            }
            for (k = 0; k < sections[i].animatedCount; k++) {
                if (sections[i].animated[k].flags & 0x20) {
                    uv2 = sections[i].animated[k].uv;
                    if (uv2->buffer != NULL) {
                        ((TScene *)uv2->buffer)->destroy_buffers(1);
                        uv2->buffer = NULL;
                    }
                }
            }
        }
    }
}

extern "C" {
void TScene::copy_header_and_vec(void* q) { *(u16 *)&this->m_name = *(u16*)((char*)q + 0x0); *(u16*)((char*)this + 0x2) = *(u16*)((char*)q + 0x2); *(f32 *)&this->m_flags = *(f32*)((char*)q + 0x4); *(f32 *)&this->m_prev = *(f32*)((char*)q + 0x8); *(f32 *)&this->m_next = *(f32*)((char*)q + 0xc); *(f32 *)&this->m_up = *(f32*)((char*)q + 0x10); }
}

s32 find_uv_animation__6TSceneFPvPv(void *task, Uv_80205DE4 *uv) {
    s16 *p;
    s16 n = 0;
    u16 *rec = NULL;
    p = (*(s16 * *)&TScene__texture_animation_buffer);
    while (p[0] != -1) {
        if (p[0] & 1) {
            n = p[2];
            rec = (u16 *)(p + 4);
            break;
        }
        if (p[0] & 2) {
            p += p[1] / 2 + 2;
        } else {
            return 0;
        }
    }
    while (n > 0) {
        if (rec[0] == uv->id) {
            ((TScene *)uv)->copy_header_and_vec(rec);
            return 1;
        }
        rec = (u16 *)((u8 *)rec + 0x14);
        n--;
    }
    return 0;
}

s32 load_texture_sequence_frame(void *task, Cyc_80205D24 *c) {
    s16 *p = (*(s16 * *)&TScene__texture_animation_buffer);
    while (p[0] != -1) {
        if (p[0] & 1) {
            p += p[1] / 2 + 2;
            continue;
        }
        if (p[0] & 2) {
            if (c->id == p[2]) {
                if (c->index >= p[3]) {
                    c->index = 0;
                }
                p += c->index * 2 + 4;
                c->texture = p[0];
                c->timer = p[1];
                return 1;
            }
            p += p[1] / 2 + 2;
            continue;
        }
        return 0;
    }
    return 0;
}

void TScene::create_texture_wave_tasks(s32 arg0) {
  s8 *new_var;
  s16 temp_r0;
  u8 *temp_r3;
  u8 *var_r31;
  var_r31 = (u8 *) (*(void **)TScene__texture_wave_resource);
  do
  {
    new_var = (s8 *) var_r31;
    temp_r3 = (u8 *) __nw__7TObjectFUl(0x38);
    if (temp_r3 != 0)
    {
      construct_pvr_wave__6TSceneFPvPvPvii(temp_r3, arg0, *((s32 *) (((s8 *) var_r31) + 4)), *((s32 *) (((s8 *) var_r31) + 8)), (s32) (*((s16 *) (((s8 *) var_r31) + 0))));
    }
    temp_r0 = *((s16 *)(new_var + 0xC));
    var_r31 += 0xC;
  }
  while (temp_r0 >= 0);
}

void TScene::init_material_nodes() {
    SceneMaterialSection *sec;
    s32 i;
    SceneMaterialStatic *st;
    s32 j;
    Node_80205AEC *node;
    Info_80205AEC *info;
    void *o;
    SceneMaterialAnimated *an;
    s32 j2;
    Node_80205AEC *node2;
    Info_80205AEC *info2;
    void *o2;
    if (TScene__data_805D5FCC != NULL) {
        for (i = 0, sec = TScene__data_805D5FCC->sections; i < TScene__data_805D5FCC->count; i++, sec++) {
            for (j = 0, st = sec->objects; j < sec->count; j++, st++) {
                if (st->flags & 0x200) {
                    node = (Node_80205AEC *)st->node;
                    if (node->obj == NULL) {
                        info = (Info_80205AEC *)find_material_entry_by_id__6TSceneFPvUs(this, node->id);
                        if (info != NULL) {
                            o = __nw__7TObjectFUl(0x20);
                            if (o != NULL) {
                                o = fn_802A8210((u8 *)o, info->c, (u8 *)this);
                            }
                            node->obj = o;
                            node->tex = lbl_8044A800[info->tex];
                            node->b = lbl_8044A80C[info->b];
                            node->c = info->c;
                        } else {
                            node->obj = 0;
                            node->tex = 0;
                            node->b = 0;
                            node->c = 0;
                        }
                    }
                }
            }
            for (j2 = 0, an = sec->animated; j2 < sec->animatedCount; j2++, an++) {
                if (an->flags & 0x200) {
                    node2 = (Node_80205AEC *)an->node;
                    if (node2->obj == NULL) {
                        info2 = (Info_80205AEC *)find_material_entry_by_id__6TSceneFPvUs(this, node2->id);
                        if (info2 != NULL) {
                            o2 = __nw__7TObjectFUl(0x20);
                            if (o2 != NULL) {
                                o2 = fn_802A8210((u8 *)o2, info2->c, (u8 *)this);
                            }
                            node2->obj = o2;
                            node2->tex = lbl_8044A800[info2->tex];
                            node2->b = lbl_8044A80C[info2->b];
                            node2->c = info2->c;
                        } else {
                            node2->obj = 0;
                            node2->tex = 0;
                            node2->b = 0;
                            node2->c = 0;
                        }
                    }
                }
            }
        }
    }
}

extern "C" {
void TScene__sub_80205AE8(s32 *) {  }
}

Ent_80205AA8 *find_material_entry_by_id__6TSceneFPvUs(void *self, u16 id) {
    Tbl_80205AA8 *t = (Tbl_80205AA8 *)TScene__material_info_buffer;
    if (t != 0) {
        Ent_80205AA8 *p = t->e;
        s32 i;
        for (i = 0; i < t->count; i++, p++) {
            if (p->id == id) return p;
        }
    }
    return 0;
}

extern "C" {
void TScene::run_task() { set_field4(); advance_scene_object_animations(); dispatch_material_animation(); }
}

void TScene::set_field4() {
    if ((void *) TScene__data_805D5FCC != NULL) {
        *(s32 *)((s8 *)TScene__data_805D5FCC + 4) = 0x8F;
    }
}

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TScene::render() {
    static void (TScene::*tbl[4])() = {
        &TScene::sub_80204D7C, &TScene::cull_sections, &TScene::update_room_visibility_from_camera, &TScene::update_records_in_range,
    };
    s32 i;

    if (TScene__floor_scene_ready_flag != 0 && TScene__data_805D5FCC != NULL) {
        if (TMainTask::get_render_pass() == 0) {
            for (i = 0; i < TScene__data_805D5FCC->count; i++) {
                TScene__data_805D5FCC->sections[i].flags &= ~0x10000;
            }
            (this->*tbl[TScene__sub_80205874(this)])();
        }
        render_map_sections();
        set_material_alpha_compare_reference(0xBF);
    }
}
#pragma pop

extern "C" {
s32 get_main_phase(void);

s32 TScene__sub_80205874(void *) {
    if (TScene__data_805D6020 != 0) {
        return 2;
    }
    if (TScene__data_805D5FE0 == 1) {
        return 3;
    }
    s32 phase = get_main_phase();
    if (phase == 14) {
        if (is_split_screen() == 1 && get_current_floor_area() == AREA_FOREST1) {
            return 1;
        }
        return 0;
    } else if (phase == 15) {
        switch (get_current_floor_area()) {
        case AREA_FOREST1:
        case AREA_FOREST2:
            return 1;
        }
        return 0;
    }
    return 0;
}
void TScene::render_map_sections() {
    SceneMaterialSection *sec;
    s32 i;
    if (TScene__data_805D5FCC != NULL) {
        TObjPlayer::draw_if_all_ready();
        if (TScene__render_callback != NULL) {
            TScene__render_callback();
        }
        if (*(void **)((u8 *)TScene__data_805D5FCC + 0x14) != NULL) {
            TObjFish::set_global_param((s32)(*(void **)((u8 *)TScene__data_805D5FCC + 0x14)));
        }
        sec = TScene__data_805D5FCC->sections;
        prepare_ginja_model();
        saved_model_render_flags = model_render_flags;
        for (i = 0; i < TScene__data_805D5FCC->count; i++, sec++) {
            if (sec->flags & 0x10000) {
                if (sec->flags & 0x80000) {
                    push_matrix();
                    switch (get_current_floor_area()) {
                    case AREA_PIONEER2_EP1:
                    case AREA_LOBBY:
                    case AREA_PIONEER2_EP2:
                        render_static_map_section(sec, 0);
                        render_animated_map_section(sec, 0);
                        break;
                    default:
                        render_static_map_section(sec, 1);
                        render_animated_map_section(sec, 1);
                        break;
                    }
                    pop_matrix();
                } else if (sec->flags & 0x100000) {
                    push_matrix();
                    post_translate_matrix(sec->position);
                    rotate_matrix_by_node_angles(sec->angles, 1);
                    render_static_map_section(sec, 1);
                    render_animated_map_section(sec, 1);
                    pop_matrix();
                } else {
                    push_matrix();
                    post_translate_matrix(sec->position);
                    rotate_matrix_by_node_angles(sec->angles, 1);
                    render_static_map_section(sec, 0);
                    render_animated_map_section(sec, 0);
                    pop_matrix();
                }
            }
        }
        model_render_flags = saved_model_render_flags;
        end_ginja_model_draw();
    }
}
void TScene::render_static_map_section(SceneMaterialSection *scene_material_section, s32 arg2) {
    SceneMaterialStatic *e;
    s32 i;
    Node_8020533C *node;
    void *tex;

    for (i = 0, e = scene_material_section->objects; i < scene_material_section->count; i++, e++) {
        if (arg2 != 0 && !(e->flags & 0x10000)) {
            continue;
        }
        if (e->node == NULL) {
            continue;
        }
        if (TScene__data_805D5FE0 == 1 && !(e->flags & 0x100)) {
            continue;
        }
        if (TScene__data_805D5FE0 == 0 && (e->flags & 0x100)) {
            continue;
        }
        if (e->flags & 1) {
            TParticleCtrl::begin_effect_render();
        }
        if (e->flags & 2) {
            model_render_flags |= 1;
        }
        if (e->flags & 0x10) {
            Node_8020533C *sh = (Node_8020533C *)resolve_indirect_node_record(this, e);
            if (sh != NULL) {
                Vec_8020533C v;
                Ang_8020533C a;
                v.x = sh->pos.x;
                v.y = sh->pos.y;
                v.z = sh->pos.z;
                vec3_add_to(&v, scene_material_section->position);
                a.x = sh->ang.x + scene_material_section->angles[0];
                a.y = sh->ang.y + scene_material_section->angles[1];
                a.z = sh->ang.z + scene_material_section->angles[2];
                render_projected_shadow_receiver(&v, &a);
            }
        }
        node = (Node_8020533C *)resolve_indirect_node_record(this, e);
        if (TScene__map_section_render_callback != NULL) {
            Vec_8020533C v;
            Ang_8020533C a;
            v.x = node->pos.x;
            v.y = node->pos.y;
            v.z = node->pos.z;
            vec3_add_to(&v, scene_material_section->position);
            a.x = node->ang.x + scene_material_section->angles[0];
            a.y = node->ang.y + scene_material_section->angles[1];
            a.z = node->ang.z + scene_material_section->angles[2];
            TScene__map_section_render_callback(&v, &a, e->flags);
        }
        if (e->flags & 0x200) {
            if (e->flags & 0x80) {
                Model_8020533C *m = (Model_8020533C *)e->node;
                if (m != NULL) {
                    TObjEneRecon::notify_scene(m->fF);
                } else {
                    TObjEneRecon::notify_scene(-1);
                }
                TObjFish::set_global_param((s32)((void *)*(s32 *)((s8 *)TScene__data_805D5FCC + 0x14)));
                set_material_alpha_compare_reference(TScene__data_805D5FCC->flags);
                draw_ginja_object(node);
                TObjEneRecon::update_particle_if_active();
            } else if (e->flags & 0x400) {
                Model_8020533C *m = (Model_8020533C *)e->node;
                if (m != NULL && TMainTask::get_render_pass() == 1) {
                    Lobby_8020533C l;
                    l.v.x = node->pos.x;
                    l.v.y = node->pos.y;
                    l.v.z = node->pos.z;
                    vec3_add_to(&l.v, scene_material_section->position);
                    l.a.x = node->ang.x + scene_material_section->angles[0];
                    l.a.y = node->ang.y + scene_material_section->angles[1];
                    l.a.z = node->ang.z + scene_material_section->angles[2];
                    l.param = (void *)*(s32 *)((s8 *)TScene__data_805D5FCC + 0x14);
                    l.node = node;
                    l.scene = TScene__data_805D5FCC->flags;
                    l.id = m->fF;
                    release_indexed_entry__6TLobbyFl(&l);
                }
            } else {
                Model_8020533C *m = (Model_8020533C *)e->node;
                if (m != NULL) {
                    if (m->tex != NULL) {
                        draw_field_1c__6TSceneFlll(tex = m->tex, m->f8, m->fE, 0);
                        TObjFish::set_global_param((s32)((void *)*(s32 *)((s8 *)TScene__data_805D5FCC + 0x14)));
                        set_material_alpha_compare_reference(TScene__data_805D5FCC->flags);
                        draw_ginja_object(node);
                        TScene::set_indirect_tev((u32)tex, 0);
                    }
                }
            }
        } else {
            set_material_alpha_compare_reference(TScene__data_805D5FCC->flags);
            draw_ginja_object(node);
        }
        if (e->flags & 0x10) {
            TScene::apply_single_screen_state();
        }
        if (e->flags & 2) {
            model_render_flags &= ~1;
        }
        if (e->flags & 1) {
            TParticleCtrl::end_effect_render();
        }
        if (TScene__active_scene_callback != NULL) {
            TScene__active_scene_callback(e->flags);
        }
    }
}
void draw_ginja_model_with_motion(void *, void *, f32);
void TScene::render_animated_map_section(SceneMaterialSection *scene_material_section, s32 arg2) {
  void *texture;
  SceneMaterialAnimated *e;
  s32 i;
  Node_8020533C *node;
  for (i = 0, e = scene_material_section->animated; i < scene_material_section->animatedCount; i++, e++)
  {
    if ((arg2 != 0) && (!(e->flags & 0x10000)))
    {
      continue;
    }
    if (e->node == 0)
    {
      continue;
    }
    if (e->motion == 0)
    {
      continue;
    }
    if ((TScene__data_805D5FE0 == 1) && (!(e->flags & 0x100)))
    {
      continue;
    }
    if ((TScene__data_805D5FE0 == 0) && (e->flags & 0x100))
    {
      continue;
    }
    if (e->flags & 1)
    {
      TParticleCtrl::begin_effect_render();
    }
    if (e->flags & 2)
    {
      model_render_flags |= 1;
    }
    node = (Node_8020533C *) resolve_indirect_object_record(this, e);
    if (e->flags & 0x10)
    {
      Vec_8020533C v;
      Ang_8020533C a;
      v.x = node->pos.x;
      v.y = node->pos.y;
      v.z = node->pos.z;
      vec3_add_to(&v, scene_material_section->position);
      a.x = node->ang.x + scene_material_section->angles[0];
      a.y = node->ang.y + scene_material_section->angles[1];
      a.z = node->ang.z + scene_material_section->angles[2];
      render_projected_shadow_receiver(&v, &a);
    }
    if (TScene__map_section_render_callback != 0)
    {
      Vec_8020533C v;
      Ang_8020533C a;
      v.x = node->pos.x;
      v.y = node->pos.y;
      v.z = node->pos.z;
      vec3_add_to(&v, scene_material_section->position);
      a.x = node->ang.x + scene_material_section->angles[0];
      a.y = node->ang.y + scene_material_section->angles[1];
      a.z = node->ang.z + scene_material_section->angles[2];
      TScene__map_section_render_callback(&v, &a, e->flags);
    }
    if (e->flags & 0x200)
    {
      Model_8020533C *m = (Model_8020533C *) e->node;
      if (m != 0)
      {

        void *tex = m->tex;
        if (tex != 0)
        {
          draw_field_1c__6TSceneFlll(texture = tex, m->f8, m->fE, 0);
          TObjFish::set_global_param((s32)((void *) (*((s32 *) (((s8 *) TScene__data_805D5FCC) + 0x14)))));
          set_material_alpha_compare_reference(TScene__data_805D5FCC->flags);
          draw_ginja_model_with_motion(node, e->motion, e->frame);
          TScene::set_indirect_tev((u32) texture, 0);
        }

      }
    }
    else
      if (TRaderMapCore::is_not_split_screen() == 1)
    {
      set_material_alpha_compare_reference(TScene__data_805D5FCC->flags);
      draw_ginja_object(node);
    }
    else
    {
      set_material_alpha_compare_reference(TScene__data_805D5FCC->flags);
      draw_ginja_model_with_motion(node, e->motion, e->frame);
    }
    if (e->flags & 0x10)
    {
      TScene::apply_single_screen_state();
    }
    if (e->flags & 2)
    {
      model_render_flags &= ~1;
    }
    if (e->flags & 1)
    {
      TParticleCtrl::end_effect_render();
    }
    if (TScene__active_scene_callback != 0)
    {
      TScene__active_scene_callback(e->flags);
    }
  }

}
extern Vec_80204024 lbl_8044A840[];
}

void TScene::sub_80204D7C() {
    Vec_80204024 dir;
    Vec_80204024 d;
    Vec_80204024 up = lbl_8044A840[0];
    Vec_80204024 p;
    f32 far2;
    SceneMaterialSection *sec;
    s32 i;

    if (TScene__data_805D5FCC == NULL) {
        return;
    }
    m_1c = 0;
    far2 = TScene__data_805D5FCC->radius * TScene__data_805D5FCC->radius;
    push_matrix_from(identity_matrix);
    rotate_matrix_y(0, CAM->a194);
    rotate_vector_by_matrix(0, &up, &dir);
    normalize_vector(&dir);
    pop_matrices(1);

    sec = TScene__data_805D5FCC->sections;
    for (i = 0; i < TScene__data_805D5FCC->count; i++) {
        if (sec->flags & 0x80000) {
            update_room_object_visibility(sec);
            sec++;
        } else {
            f32 dist;
            f32 dot;
            p.x = sec->position[0];
            p.y = 0.0f;
            p.z = sec->position[2];
            d.x = p.x - CAM->x;
            d.y = 0.0f;
            d.z = p.z - CAM->z;
            dist = d.x * d.x + d.y * d.y + d.z * d.z;
            if (dist < sec->radius * sec->radius) {
                sec->flags |= 0x10000;
                sec++;
                m_1c++;
            } else if (dist > far2) {
                sec->flags &= ~0x10000;
                sec++;
            } else {
                normalize_vector(&d);
                dot = vec3_dot(&dir, &d);
                if (dot < 0.0f) {
                    sec->flags &= ~0x10000;
                    sec++;
                } else if (dot >= 0.0f && dot < 0.5f) {
                    push_matrix_from(identity_matrix);
                    rotate_matrix_y(0, CAM->a19C);
                    rotate_vector_by_matrix(0, &dir, &up);
                    normalize_vector(&up);
                    pop_matrices(1);
                    if (TEST(sec->radius, this, &p, &d, &up) != 0) {
                        sec->flags |= 0x10000;
                        sec++;
                        m_1c++;
                    } else {
                        push_matrix_from(identity_matrix);
                        rotate_matrix_y(0, -CAM->a19C);
                        rotate_vector_by_matrix(0, &dir, &up);
                        normalize_vector(&up);
                        pop_matrices(1);
                        if (TEST(sec->radius, this, &p, &d, &up) != 0) {
                            sec->flags |= 0x10000;
                            sec++;
                            m_1c++;
                        } else {
                            goto clear;
                        }
                    }
                } else {
                    sec->flags |= 0x10000;
                    sec++;
                    m_1c++;
                }
            }
        }
        continue;
    clear:
        sec->flags &= ~0x10000;
        sec++;
    }
}


s32 check_object_in_view_cone__6TSceneFiPvPvPvi(s32 unused, Obj_80204B78 *obj, Vec_80204024 *pos, void *arg3, s32 arg4) {
    Vec_80204024 c;
    Vec_80204024 a;
    Vec_80204024 b;
    f32 r2;
    f32 g2;
    f32 k;
    f32 z;
    f32 x;
    f32 dist2;
    f32 d;
    k = 0.0f;
    x = obj->x;
    a.x = x;
    a.y = k;
    z = obj->z;
    a.z = z;
    b.x = x - pos->x;
    b.y = k;
    b.z = z - pos->z;
    dist2 = b.x * b.x + b.y * b.y + b.z * b.z;
    r2 = obj->radius * obj->radius;
    g2 = TScene__data_805D5FCC->radius * TScene__data_805D5FCC->radius;
    if (dist2 < r2) {
        obj->flags |= 0x10000;
        return 1;
    }
    if (dist2 > g2) {
        obj->flags &= ~0x10000;
        return 0;
    }
    normalize_vector(&b);
    d = vec3_dot(arg3, &b);
    if (d < 0.0f) {
        obj->flags &= ~0x10000;
        return 0;
    }
    if (d >= 0.0f && d < 0.5f) {
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, arg4);
        rotate_vector_by_matrix(0, arg3, &c);
        normalize_vector(&c);
        pop_matrix();
        if (TScene__sub_80204024(obj->radius, unused, &a, &b, &c) != 0) {
            obj->flags |= 0x10000;
            return 1;
        }
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, -arg4);
        rotate_vector_by_matrix(0, arg3, &c);
        normalize_vector(&c);
        pop_matrix();
        if (TScene__sub_80204024(obj->radius, unused, &a, &b, &c) != 0) {
            obj->flags |= 0x10000;
            return 1;
        }
    } else {
        obj->flags |= 0x10000;
        return 1;
    }
    obj->flags &= ~0x10000;
    return 0;
}

void TScene::cull_sections() {
    Task_80204688 *task = (Task_80204688*)this;
    static f32 s_near = 520.0f;
    static f32 s_far = 800.0f;
    static f32 s_pad = 80.0f;
    Vec_80204024 dir;
    Vec_80204024 d;
    Vec_80204024 up = lbl_8044A84C[0];
    Vec_80204024 p;
    Vec_80204024 v;
    s32 i;
    SceneMaterialSection *sec;

    if (TScene__data_805D5FCC == NULL) {
        return;
    }
    if (is_split_screen() != 0) {
        s_near = 480.0f;
        s_far = 500.0f;
    } else {
        s_near = 600.0f;
        s_far = TScene__data_805D5FCC->radius;
    }
    task->count = 0;
    push_matrix_from(identity_matrix);
    rotate_matrix_y(0, CAM->a194);
    rotate_vector_by_matrix(0, &up, &dir);
    normalize_vector(&dir);
    pop_matrix();

    sec = TScene__data_805D5FCC->sections;
    for (i = 0; i < TScene__data_805D5FCC->count; i++) {
        if (sec->flags & 0x80000) {
            ((TScene *)task)->update_room_object_visibility(sec);
            sec++;
        } else {
            f32 dist;
            f32 dot;
            p.x = sec->position[0];
            p.y = 0.0f;
            p.z = sec->position[2];
            d.x = p.x - CAM->x;
            d.y = 0.0f;
            d.z = p.z - CAM->z;
            dist = d.x * d.x + d.y * d.y + d.z * d.z;
            if (dist < sec->radius * sec->radius) {
                sec->flags |= 0x10000;
                sec++;
                task->count++;
            } else if (dist > s_far * s_far) {
                sec->flags &= ~0x10000;
                sec++;
            } else {
                normalize_vector(&d);
                dot = vec3_dot(&dir, &d);
                if (dot < 0.0f) {
                    sec->flags &= ~0x10000;
                    sec++;
                } else if (dot >= 0.0f && dot < 0.5f) {
                    push_matrix_from(identity_matrix);
                    rotate_matrix_y(0, CAM->a19C);
                    rotate_vector_by_matrix(0, &dir, &up);
                    normalize_vector(&up);
                    pop_matrices(1);
                    if (TEST(sec->radius, task, &p, &d, &up) != 0) {
                        sec->flags |= 0x10000;
                        sec++;
                        task->count++;
                    } else {
                        push_matrix_from(identity_matrix);
                        rotate_matrix_y(0, -CAM->a19C);
                        rotate_vector_by_matrix(0, &dir, &up);
                        normalize_vector(&up);
                        pop_matrices(1);
                        if (TEST(sec->radius, task, &p, &d, &up) != 0) {
                            sec->flags |= 0x10000;
                            sec++;
                            task->count++;
                        } else {
                            goto clear;
                        }
                    }
                } else {
                    sec->flags |= 0x10000;
                    sec++;
                    task->count++;
                }
            }
        }
        continue;
    clear:
        sec->flags &= ~0x10000;
        sec++;
    }

    sec = TScene__data_805D5FCC->sections;
    for (i = 0; i < TScene__data_805D5FCC->count; i++, sec++) {
        if (sec->flags & 0x100000) {
            SceneMaterialStatic *st = sec->objects;
            s32 j;
            for (j = 0; j < sec->count; j++, st++) {
                Node_80204688 *n = (Node_80204688 *)resolve_indirect_node_record(task, st);
                v.x = n->model->x + (sec->position[0] + n->x);
                v.y = n->model->y + (sec->position[1] + n->y);
                v.z = n->model->z + (sec->position[2] + n->z);
                if (VIS(task, &v, s_near + s_pad, 100.0f) != 0) {
                    st->flags |= 0x10000;
                } else {
                    st->flags &= ~0x10000;
                }
            }
            {
                SceneMaterialAnimated *an = sec->animated;
                for (j = 0; j < sec->animatedCount; j++, an++) {
                    Node_80204688 *n = (Node_80204688 *)resolve_indirect_object_record(task, an);
                    v.x = sec->position[0] + n->x;
                    v.y = sec->position[1] + n->y;
                    v.z = sec->position[2] + n->z;
                    if (VIS(task, &v, s_near + s_pad, 100.0f) != 0) {
                        an->flags |= 0x10000;
                    } else {
                        an->flags &= ~0x10000;
                    }
                }
            }
        }
    }
}

#pragma push
#pragma opt_propagation off
#pragma opt_lifetimes off
void TScene::update_room_visibility_from_camera() {
    Vec_802043CC dir;
    Vec_802043CC fwd;
    Vec_802043CC out;
    Tbl_802043CC *tbl;
    s32 j;
    Ent_802043CC *e;
    s16 *ids;
    SceneMaterialSection *room;
    s32 sec;
    s32 i;
    f32 d;
    sec = ((TScene *)(&(*(Cam_802043CC * *)&camera_ctrl_instance)->pos))->find_section_at_position();
    if (sec < 0) {
        sub_80204D7C();
        return;
    }
    tbl = (Tbl_802043CC *)TScene__data_805D6020;
    for (i = 0, e = tbl->ents; i < tbl->count; e++, i++) {
        if (e->id == sec) {
            break;
        }
    }
    if (i >= tbl->count) {
        sub_80204D7C();
        return;
    }
    room = find_scene_room_by_id(sec);
    if (room != NULL) {
        room->flags |= 0x10000;
    }
    tbl = (Tbl_802043CC *)((u8 *)tbl + tbl->count * 0xC);
    ids = (s16 *)tbl->ents;
    for (j = 0; j < e->n; j++) {
        room = find_scene_room_by_id(ids[e->start + j]);
        if (room != NULL) {
            d = xz_distance_squared(room->position, &(*(Cam_802043CC * *)&camera_ctrl_instance)->pos);
            if (d < room->radius * room->radius) {
                room->flags |= 0x10000;
            } else {
                VecCopy__FP3VecPC3Vec(&dir, room->position);
                subtract_vector(&dir, &(*(Cam_802043CC * *)&camera_ctrl_instance)->pos);
                normalize_vector((Vec_80204024 *)(&dir));
                fwd.x = 0.0f;
                fwd.y = 0.0f;
                fwd.z = -1.0f;
                push_matrix_from(identity_matrix);
                rotate_matrix_y(0, (*(Cam_802043CC * *)&camera_ctrl_instance)->angY);
                rotate_vector_by_matrix(0, &fwd, (Vec_80204024 *)(&out));
                pop_matrix();
                normalize_vector((Vec_80204024 *)(&out));
                if (vec3_dot(&dir, &out) < 0.0f) {
                    room->flags &= ~0x10000;
                } else if (d < (*(SceneMaterialRoot * *)&TScene__data_805D5FCC)->radius * (*(SceneMaterialRoot * *)&TScene__data_805D5FCC)->radius) {
                    room->flags |= 0x10000;
                } else {
                    room->flags &= ~0x10000;
                }
            }
        }
    }
    {
        W_802043CC w = lbl_8044A858[0];
        Vec_802043CC out2;
        SceneMaterialSection *s;
        s32 k;
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, (*(Cam_802043CC * *)&camera_ctrl_instance)->angY);
        rotate_vector_by_matrix(0, &w, (Vec_80204024 *)(&out2));
        normalize_vector((Vec_80204024 *)(&out2));
        pop_matrix();
        s = (*(SceneMaterialRoot * *)&TScene__data_805D5FCC)->sections;
        for (k = 0; k < (*(SceneMaterialRoot * *)&TScene__data_805D5FCC)->count; k++, s++) {
            if (s->flags & 0x80000) {
                update_room_object_visibility(s);
            } else if (s->id < 0) {
                check_object_in_view_cone__6TSceneFiPvPvPvi((s32)this, (Obj_80204B78 *)(s), (Vec_80204024 *)(&(*(Cam_802043CC * *)&camera_ctrl_instance)->pos), &out2, (s32)((*(Cam_802043CC * *)&camera_ctrl_instance)->f19C));
            }
        }
    }
}
#pragma pop

void TScene::update_records_in_range() {
    f32 r;
    f32 r2;
    s32 off;
    s32 i;
    W_8020430C v = (*(Cam_8020430C * *)&camera_ctrl_instance)->pos;
    i = 0;
    off = 0;
    r = (*(Root_8020430C * *)&TScene__data_805D5FCC)->radius + TScene__visibility_radius_margin;
    r2 = r * r;
    for (; i < (*(Root_8020430C * *)&TScene__data_805D5FCC)->count; i++, off += 0x34) {
        Rec_8020430C *rec = (Rec_8020430C *)((u8 *)(*(Root_8020430C * *)&TScene__data_805D5FCC)->recs + off);
        if (xz_distance_squared(&v, rec->pos) < r2) {
            rec->flags |= 0x10000;
        } else {
            rec->flags &= ~0x10000;
        }
    }
}

void TScene::update_room_object_visibility(SceneMaterialSection *room) {
    SceneMaterialStatic *object;
    s32 i;
    SceneMaterialAnimated *anim;
    i = 0;
    room->flags |= 0x10000;
    for (object = room->objects; i < room->count; i++, object++) {
        if (object->node != NULL) {
            if (TScene__sub_802040D4(this, (Obj_802040D4 *)((SceneMaterialNode *)resolve_indirect_node_record(this, (SceneMaterialStatic*)(object))), 10000.0f, 100.0f) != 0) {
                object->flags |= 0x10000;
            } else {
                object->flags &= ~0x10000;
            }
        }
    }
    for (anim = room->animated, i = 0; i < room->animatedCount; i++, anim++) {
        if (anim->node != NULL) {
            if (TScene__sub_802040D4(this, (Obj_802040D4 *)((SceneMaterialNode *)resolve_indirect_object_record(this, (SceneMaterialAnimated*)(anim))), 10000.0f, 100.0f) != 0) {
                anim->flags |= 0x10000;
            } else {
                anim->flags &= ~0x10000;
            }
        }
    }
}
bool is_in_view_depth__6TSceneFf(f32 farg0) {
    f32 sp[6];
    void *unused;
    matrix_mult_vec(0, unused, &sp[0]);
    if (sp[2] > 0.0f) {
        return 0;
    }
    return (sp[2] < -farg0) == 0;
}
s32 TScene__sub_802040D4(void *arg0, Obj_802040D4 *o, f32 f0, f32 f1) {
    if (o->inner != NULL && (*(u8 * *)&camera_ctrl_instance) != NULL) {
        void *p = o->pos;
        if (xz_distance_squared((*(u8 * *)&camera_ctrl_instance) + 0x178, p) < o->inner->radius * o->inner->radius) {
            return 1;
        }
        return ((s32 (*)(void *, void *, f32, f32))is_in_view_depth__6TSceneFf)(arg0, p, f0, f1);
    }
    return 0;
}
s32 TScene__sub_80204024(f32 thr, s32 unused, void *a, void *b, Vec_80204024 *c) {
    struct { Vec_80204024 p, q; } s;
    Vec_80204024 o;
    if (vec3_dot(b, c) < 0.0f) {
        return 0;
    }
    s.p.x = camera_ctrl_instance->x;
    s.p.y = 0.0f;
    s.p.z = camera_ctrl_instance->z;
    s.q.x = c->x;
    s.q.y = c->y;
    s.q.z = c->z;
    return project_point_onto_line(a, &s, &o) <= thr;
}
void TScene::advance_scene_object_animations() {
    Group_80203F0C *g;
    s32 i;
    Anim_80203F0C *a;
    s32 j;
    if ((*(Root_80203F0C **)&TScene__data_805D5FCC) == NULL) {
        return;
    }
    g = (*(Root_80203F0C **)&TScene__data_805D5FCC)->groups;
    for (i = 0; i < (*(Root_80203F0C **)&TScene__data_805D5FCC)->count; i++, g++) {
        a = g->anims;
        for (j = 0; j < g->count; j++, a++) {
            a->flags &= ~0x40000;
        }
    }
    g = (*(Root_80203F0C **)&TScene__data_805D5FCC)->groups;
    for (i = 0; i < (*(Root_80203F0C **)&TScene__data_805D5FCC)->count; i++, g++) {
        a = g->anims;
        for (j = 0; j < g->count; j++, a++) {
            if (!(a->flags & 0x40000)) {
                a->frame += a->speed;
                if (a->motion != NULL && a->frame > (a->motion->frames - 1)) {
                    a->frame = 0.0f;
                }
                a->flags |= 0x40000;
            }
        }
    }
}

void TScene::dispatch_material_animation() {
    typedef void (TScene::*MaterialTicker)();
    static MaterialTicker fns[2] = {
        &TScene::tick_material_fmt1,
        &TScene::tick_material_fmt2,
    };
    (this->*fns[TScene__data_805D5FE8])();
}

#pragma defer_codegen off
