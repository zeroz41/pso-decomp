#include "pso/system/memory.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/render/GinjaMaterialTextureSlot.h"
#include "pso/render/GinjaUvScroll.h"
#include "pso/map/TMapCsnCtrl.h"
#include "pso/system/ResourceFile.h"
#include "types.h"
#include "pso/map/FloorArea.h"
#include "pso/object/container/TContainerAncient01.h"
#include "pso/system/scene/TScene.h"
#include "pso/unk/TLobby_80207644.h"
#include "pso/render/reflection.h"
#include "pso/object/door/TObjDoorJung.h"
#include "pso/system/scene/TSceneMaterial.h"
#include "pso/system/task/TMainTask.h"
#include "pso/effect/TEffIndirectCtrl.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/drop/TItemDrop_800F93F0.h"
#include "pso/unk/TLobby_80131794.h"
#include "pso/unk/TLobby_80207DA8.h"
#include "pso/unk/text_800F8A18.h"
#include "pso/unk/text_803D853C.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/object/lobby/TObjButterflyLobby.h"
#include "pso/map/TObjMapCsn.h"
#include "pso/unk/TLobby.h"
#include "pso/system/task/TObject.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/system/vector.h"
#include "pso/render/NinjaUtil.h"
#include <string.h>
#include "pso/unk/text_803D96A8.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/effect/TEF_PvrWave.h"
#include "pso/player/PlayerSlots.h"

struct SurfaceAreaTable { s32 enabled[36]; };


extern SurfaceAreaTable player_auxiliary_surface_flag_table;

struct Tbl_8020335C { s32 v[8]; };


extern struct Tbl_8020335C group_selection_area_id_table;



extern "C" s32 is_item_area_enabled(s32 area);


extern s32 boss_area_id_table[];

extern s32 item_disabled_area_table[];




typedef void (*RecoveredCallback_2be3cacebb2e)(void);

struct SceneMaterialRoot;



struct W_802043CC { s32 a, b, c; };


struct Ent_802043CC { s32 id; s32 n; s32 start; };


struct Tbl_802043CC { u32 pad; s32 count; Ent_802043CC ents[1]; };
extern "C" {

SceneMaterialSection *find_scene_room_by_id(s32 id);

s32 TScene__sub_802040D4(TScene *scene, SceneMaterialNode *node, f32 depth, f32 near_depth);


f32 project_point_onto_line(void *, void *, void *);



SceneMaterialNode* resolve_indirect_node_record(void*,SceneMaterialStatic*);

SceneMaterialNode* resolve_indirect_object_record(void*,SceneMaterialAnimated*);


extern u8 identity_matrix[];



void rotate_matrix_y(s32, s32);

void rotate_vector_by_matrix(saddr, void *, Vec *);



extern s32 model_render_flags;

extern s32 saved_model_render_flags;



void post_translate_matrix(f32 *);

void rotate_matrix_by_node_angles(s32 *, s32);


void PPCSync();





struct Model_8020533C { u8 pad0[4]; TEffIndirect *tex; s32 sampler; u8 padC[2]; u8 scale; u8 effect_id; };

struct Lobby_8020533C { Vec v; SceneSectionAngles a; void *param; SceneMaterialNode *node; s16 scene; u8 id; };


void render_projected_shadow_receiver(void *, void *);


void release_indexed_entry__6TLobbyFl(Lobby_8020533C *);

void vec3_add_to(void *, void *);

void draw_ginja_object(void *);

void set_material_alpha_compare_reference(s32 reference);




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

LAYOUT_ASSERT(SceneDispatchPrefix_size, sizeof(SceneDispatchPrefix) == 0x78);


extern Vec lbl_8044A84C[];


struct Node_80205AEC { u32 flags; void *obj; u32 tex; u16 id; u8 b; u8 c; };

extern "C" {




extern u32 lbl_8044A800[];

extern u8 lbl_8044A80C[];

}




extern "C" {

saddr get_player_name_copy_buffer();


s32 release_texture_list(u32);

extern CsnGroup **scene_collision_data;





void bind_gvm_texture_list(s32 *, u32);





struct Sp8Buf20_80206494 {
    s32 f0; s32 f4; s32 f8; s32 fc;
    s32 f10; s32 f14; s32 f18; s32 f1c;
};

}


#pragma readonly_strings on

const char *current_floor_name = "SCENE";
s32 lbl_805D3614 = 10;
SceneNameIndex scene_format_dispatch_tables[] = {
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
const char *TScene::class_name = "TScene";
__declspec(section ".rodata") Vec lbl_8044A840[1] = {{0.0f, 0.0f, -1.0f}};
__declspec(section ".rodata") Vec lbl_8044A84C[1] = {{0.0f, 0.0f, -1.0f}};
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
SceneMaterialRoot *scene_material_root;
uaddr texture_wave_resource;
s8 floor_scene_ready_flag;
s32 current_lobby_id;
s32 lobby_online_ready_flag;
s32 reflection_pass_active;
f32 visibility_radius_margin;
s32 scene_format_index;
void (*map_section_render_callback)(Vec *, SceneSectionAngles *, u32);
void (*active_scene_callback)(s32);
RecoveredCallback_2be3cacebb2e render_callback;
s32 lbl_805D5FF8;
void *map_rel_load_buffer;
void *collision_file_buffer;
void *texture_animation_buffer;
void *supplementary_rel_buffer;
s32 lbl_805D600C;
s32 map_rel_load_size_limit;
s32 collision_file_size_limit;
s32 texture_animation_size_limit;
s32 loaded_floor_rel_file_index;
void *floor_bin_buffer;
s32 floor_bin_file_size;
void *material_info_buffer;
s32 scene_file_buffer_size;

extern "C" {
s32 load_texture_sequence_frame(void *task, SceneMaterialCycle *c);
}
void load_scene_map_file(saddr name);
void load_scene_collision_file(saddr name);
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

void TScene::set_instance(void (*callback)(void)) { render_callback = callback; }

void TScene::set_active_scene(void (*callback)(s32 flags)) { active_scene_callback = callback; }

void TScene::set_id(void (*callback)(Vec *pos, SceneSectionAngles *angles, u32 flags)) {
    map_section_render_callback = callback;
}

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
    if (get_floor_map_selection(floor, &selection) == 1) {
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

s32 find_section_at_position(Vec *pos) {
    SceneMaterialSection *r;
    s32 best = -1;
    s32 i;
    f32 bestd;
    if (scene_material_root == NULL) {
        return -1;
    }
    bestd = 1000000000.0f;
    r = scene_material_root->sections;
    for (i = 0; i < scene_material_root->count; i++, r++) {
        if (r->id >= 0) {
            f32 d = xyz_distance_squared(pos, (Vec *)r->position);
            if (!(d > r->radius * r->radius) && d < bestd) {
                bestd = d;
                best = r->id;
            }
        }
    }
    return best;
}

s32 TScene::find_player_section(u16 client_id) {
    TObjPlayer *player;

    player = get_player_by_client_id(client_id);
    if (player != NULL) {
        return find_section_at_position(&player->position);
    }
    return -1;
}

SceneMaterialSection *find_scene_room_by_id(s32 id) {
    s32 i;
    s16 count = scene_material_root->count;
    for (i = 0; i < count; i++) {
        if (scene_material_root->sections[i].id == id) {
            return &scene_material_root->sections[i];
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
    if (texture_animation_buffer == NULL || (*(SceneMaterialRoot * *)&scene_material_root) == NULL) {
        return;
    }
    room = (*(SceneMaterialRoot * *)&scene_material_root)->sections;
    for (section = 0; section < (*(SceneMaterialRoot * *)&scene_material_root)->count; section++, room++) {
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
    room = (*(SceneMaterialRoot * *)&scene_material_root)->sections;
    for (section = 0; section < (*(SceneMaterialRoot * *)&scene_material_root)->count; section++, room++) {
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
                    object->cycle->index++;
                    load_texture_sequence_frame(this, object->cycle);
                    set_ginja_model_texture_slot(node->model, object->cycle->texture);
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
                    anim->cycle->index++;
                    load_texture_sequence_frame(this, anim->cycle);
                    set_ginja_model_texture_slot(node->model, anim->cycle->texture);
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
    if (texture_animation_buffer == NULL || (*(SceneMaterialRoot * *)&scene_material_root) == NULL) {
        return;
    }
    room = (*(SceneMaterialRoot * *)&scene_material_root)->sections;
    for (section = 0; section < (*(SceneMaterialRoot * *)&scene_material_root)->count; section++, room++) {
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
    room = (*(SceneMaterialRoot * *)&scene_material_root)->sections;
    for (section = 0; section < (*(SceneMaterialRoot * *)&scene_material_root)->count; section++, room++) {
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
                    scroll_ginja_mesh_uvs(&node->model->model, (s32)uv->u, (s32)uv->v, uv->texture, 1);
                    uv->u -= (f32)(s32)uv->u;
                    uv->v -= (f32)(s32)uv->v;
                }
            }
            if (object->flags & 0x40) {
                object->cycle->timer--;
                if (object->cycle->timer < 0) {
                    object->cycle->index++;
                    load_texture_sequence_frame(this, object->cycle);
                    set_ginja_model_texture_slot(node->model, object->cycle->texture);
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
                    scroll_ginja_mesh_uvs(&node->model->model, (s32)uv->u, (s32)uv->v, uv->texture, 1);
                    uv->u -= (f32)(s32)uv->u;
                    uv->v -= (f32)(s32)uv->v;
                }
            }
            if (anim->flags & 0x40) {
                anim->cycle->timer--;
                if (anim->cycle->timer < 0) {
                    anim->cycle->index++;
                    load_texture_sequence_frame(this, anim->cycle);
                    set_ginja_model_texture_slot(node->model, anim->cycle->texture);
                }
            }
            anim->flags |= 0x20000;
        }
    }
    PPCSync();
}

#pragma defer_codegen on

void TScene::load_current_floor() {
    SceneNameIndex *tbl;
    s32 ent;
    s32 found;
    FloorMapSelection res;
    s32 path[11];
    lbl_805D5FF8 = 0;
    map_rel_load_buffer = NULL;
    collision_file_buffer = NULL;
    supplementary_rel_buffer = NULL;
    texture_animation_buffer = NULL;
    floor_bin_buffer = NULL;
    material_info_buffer = NULL;
    lbl_805D600C = 0;
    map_rel_load_size_limit = 0;
    collision_file_size_limit = 0;
    loaded_floor_rel_file_index = 0;
    texture_animation_size_limit = 0;
    floor_bin_file_size = 0;
    scene_file_buffer_size = 0;
    scene_format_index = -1;
    if (get_floor_map_selection(current_floor_index, &res) == 1) {
        tbl = (SceneNameIndex *)get_floor_scene_table(res.area);
        scene_resource_index = res.terrain;
        ent = tbl[res.terrain].idx;
    }
    copy_name((char *)current_floor_name);
    TScene::load_scene_rel_file(ent);
    if (scene_material_root != NULL && scene_material_root->texlist != 0) {
        found = 0;
        if (TRaderMapCore::is_not_split_screen() == 1) {
            TLobby::replace_file_extension((char *)path, (char *)tbl[scene_resource_index].name, (char *)"m.gvm");
            found = get_resource_file_size((const char *)path);
        }
        if (found <= 0) {
            TLobby::replace_file_extension((char *)path, (char *)tbl[scene_resource_index].name, (char *)".gvm");
        }
        bind_gvm_texture_list(path, scene_material_root->texlist);
    }
    TScene::load_scene_data(ent);
    TScene::load_supplementary_t_rel(ent);
    TScene::load_map_texture_archive(ent);
    TScene::load_floor_bin_file(ent);
    TScene::load_file_to_buffer(ent);
    floor_scene_ready_flag = 1;
    reflection_pass_active = 0;
    map_section_render_callback = 0;
    active_scene_callback = 0;
    render_callback = 0;
    visibility_radius_margin = 0.0f;
}

void TScene::load_scene_data(saddr name) {
    struct Sp8Buf20_80206494 filename;
    s32 size;
    void *lobby_buffer;
    void *buffer;

    TObjButterflyLobby::alloc_scene_buffer();
    scene_collision_data = NULL;
    collision_file_buffer = NULL;
    collision_file_size_limit = 0;
    TLobby::replace_file_extension((char *)((s32 *)((s32 *)&filename)), (char *)(name), (char *)("c.rel"));
    size = get_resource_file_size((const char *)&filename);
    if (get_current_floor_area() == AREA_LOBBY) {
        if ((size > 0) && ((u32) size <= 0x10000U)) {
            lobby_buffer = TQuestVmDownLoadServer::alloc(0x10000);
            collision_file_buffer = lobby_buffer;
            if (lobby_buffer != NULL) {
                scene_collision_data = (CsnGroup **)load_relocatable_file(reinterpret_cast<const char *>(&filename), lobby_buffer);
                collision_file_size_limit = 0x10000;
            }
        }
    } else if (size > 0) {
        buffer = TQuestVmDownLoadServer::alloc(size);
        collision_file_buffer = buffer;
        if (buffer != NULL) {
            scene_collision_data = (CsnGroup **)load_relocatable_file(reinterpret_cast<const char *>(&filename), buffer);
            collision_file_size_limit = size;
        }
    }
    if ((scene_collision_data != NULL) && (TObjMapCsn::get_collision_controller() != NULL)) {
        TMapCsnCtrl *csn = TObjMapCsn::get_collision_controller();
        collect_collision_groups(csn, *scene_collision_data);
        return;
    }
    TLobby::debug_print("TScene : CANNOT LOAD COLLISION DATA");
}

void TScene::load_scene_rel_file(saddr ent) {
    u8 id[0x28];
    s32 area;
    s32 size;
    area = get_current_floor_area();
    scene_material_root = NULL;
    size = 0;
    map_rel_load_buffer = NULL;
    map_rel_load_size_limit = 0;
    scene_format_index = -1;
    if (TRaderMapCore::is_not_split_screen() == 1) {
        TLobby::replace_file_extension((char *)((s32 *)id), (char *)ent, (char *)((s32 *)"nm.rel"));
        size = get_resource_file_size((const char *)id);
    }
    if (size <= 0) {
        TLobby::replace_file_extension((char *)((s32 *)id), (char *)ent, (char *)((s32 *)"n.rel"));
        size = get_resource_file_size((const char *)id);
    }
    if (area == AREA_LOBBY) {
        if (size > 0 && (u32)size <= 0x80000U) {
            map_rel_load_buffer = TQuestVmDownLoadServer::alloc(0x80000);
            if (map_rel_load_buffer != NULL) {
                scene_material_root = (SceneMaterialRoot *)load_relocatable_file(reinterpret_cast<const char *>(id), map_rel_load_buffer);
                map_rel_load_size_limit = 0x80000;
            }
        }
    } else if (size > 0) {
        map_rel_load_buffer = TQuestVmDownLoadServer::alloc(size);
        if (map_rel_load_buffer != NULL) {
            scene_material_root = (SceneMaterialRoot *)load_relocatable_file(reinterpret_cast<const char *>(id), map_rel_load_buffer);
            map_rel_load_size_limit = size;
        }
    }
    if (scene_material_root != NULL) {
        SceneNameIndex *e;
        for (e = scene_format_dispatch_tables; e->name != NULL; e++) {
            if (strncmp((const char *)scene_material_root, e->name, 4) == 0) {
                scene_format_index = e->idx;
                return;
            }
        }
    }
}

void TScene::load_supplementary_t_rel(saddr name) {
    u8 id[0x20];
    s32 n;
    texture_wave_resource = 0;
    supplementary_rel_buffer = NULL;
    loaded_floor_rel_file_index = 0;
    TLobby::replace_file_extension((char *)((s32 *)id), (char *)name, (char *)((s32 *)"t.rel"));
    n = get_resource_file_size((const char *)id);
    if (n > 0) {
        supplementary_rel_buffer = TQuestVmDownLoadServer::alloc(n);
        if (supplementary_rel_buffer != NULL) {
            texture_wave_resource = (u32)load_relocatable_file(reinterpret_cast<const char *>(id), supplementary_rel_buffer);
            loaded_floor_rel_file_index = n;
        }
    }
}

void TScene::load_map_texture_archive(saddr name) {
    char filename[0x20];
    s32 area;
    s32 size;
    void *lobby_buffer;
    void *buffer;

    area = get_current_floor_area();
    texture_animation_buffer = NULL;
    size = 0;
    texture_animation_size_limit = 0;
    if (TRaderMapCore::is_not_split_screen() == 1) {
        TLobby::replace_file_extension((char *)(filename), (char *)(name), (char *)("m.tam"));
        size = get_resource_file_size((const char *)filename);
    }
    if (size <= 0) {
        TLobby::replace_file_extension((char *)(filename), (char *)(name), (char *)(".tam"));
        size = get_resource_file_size((const char *)filename);
    }
    if (area == AREA_LOBBY) {
        if ((size > 0) && ((u32) size <= 0x100U)) {
            lobby_buffer = TQuestVmDownLoadServer::alloc(0x100);
            texture_animation_buffer = lobby_buffer;
            if (lobby_buffer != NULL) {
                read_disc_file((const char *)filename, lobby_buffer);
                texture_animation_size_limit = 0x100;
            }
        }
    } else if (size > 0) {
        buffer = TQuestVmDownLoadServer::alloc(size);
        texture_animation_buffer = buffer;
        if (buffer != NULL) {
            read_disc_file((const char *)filename, buffer);
            texture_animation_size_limit = size;
        }
    }
}

void TScene::load_floor_bin_file(saddr name) {
    u8 filename[0x20];
    s32 size;
    floor_bin_buffer = NULL;
    floor_bin_file_size = 0;
    if (TRaderMapCore::is_not_split_screen() == 1) {
        TLobby::replace_file_extension((char *)((s32 *)filename), (char *)name, (char *)((s32 *)"bm.bin"));
    } else {
        TLobby::replace_file_extension((char *)((s32 *)filename), (char *)name, (char *)((s32 *)"b.bin"));
    }
    size = get_resource_file_size((const char *)filename);
    if (get_current_floor_area() == AREA_LOBBY) {
        if (size > 0 && (u32)size <= 0x100U) {
            floor_bin_buffer = TQuestVmDownLoadServer::alloc(0x100);
            if (floor_bin_buffer != NULL) {
                read_disc_file((const char *)filename, floor_bin_buffer);
                floor_bin_file_size = 0x100;
            }
        }
    } else if (size > 0) {
        floor_bin_buffer = TQuestVmDownLoadServer::alloc(size);
        if (floor_bin_buffer != NULL) {
            read_disc_file((const char *)filename, floor_bin_buffer);
            floor_bin_file_size = size;
        }
    }
}

void TScene::load_file_to_buffer(saddr name) {
    s32 filename[8];
    s32 size;
    void *lobby_buffer;
    void *buffer;

    material_info_buffer = NULL;
    scene_file_buffer_size = 0;
    TLobby::replace_file_extension((char *)(filename), (char *)(name), (char *)("i.bin"));
    size = get_resource_file_size((const char *)filename);
    if (get_current_floor_area() == AREA_LOBBY) {
        if ((size > 0) && ((u32) size <= 0x100U)) {
            lobby_buffer = TQuestVmDownLoadServer::alloc(0x100);
            material_info_buffer = lobby_buffer;
            if (lobby_buffer != NULL) {
                read_disc_file((const char *)filename, lobby_buffer);
                scene_file_buffer_size = 0x100;
            }
        }
    } else if (size > 0) {
        buffer = TQuestVmDownLoadServer::alloc(size);
        material_info_buffer = buffer;
        if (buffer != NULL) {
            read_disc_file((const char *)filename, buffer);
            scene_file_buffer_size = size;
        }
    }
}

void TScene::free_scene_resources() {
    void *buffer;
    buffer = material_info_buffer;
    if (buffer != NULL) {
        safe_free(buffer);
        material_info_buffer = NULL;
    }
    buffer = floor_bin_buffer;
    if (buffer != NULL) {
        safe_free(buffer);
        floor_bin_buffer = NULL;
    }
    buffer = texture_animation_buffer;
    if (buffer != NULL) {
        safe_free(buffer);
        texture_animation_buffer = NULL;
    }
    buffer = supplementary_rel_buffer;
    if (buffer != NULL) {
        safe_free(buffer);
        supplementary_rel_buffer = NULL;
    }
    if (scene_material_root != NULL) {
        u32 texlist = scene_material_root->texlist;
        if (texlist != 0U) {
            release_texture_list(texlist);
            scene_material_root->texlist = 0U;
        }
    }
    buffer = collision_file_buffer;
    if (buffer != NULL) {
        safe_free(buffer);
        collision_file_buffer = NULL;
    }
    TObjButterflyLobby::free_singleton_805D4E6C();
    buffer = map_rel_load_buffer;
    if (buffer != NULL) {
        safe_free(buffer);
        map_rel_load_buffer = NULL;
    }
    scene_collision_data = NULL;
    scene_material_root = NULL;
    if (strncmp((const char *)get_player_name_copy_buffer(), current_floor_name, 0x10) == 0) {
        copy_name("..");
    }
}

void load_floor_scene(void) {
    SceneNameIndex *tbl;
    s32 ent;
    s32 found;
    FloorMapSelection res;
    s32 path[11];
    if (scene_material_root != NULL && scene_material_root->texlist != 0) {
        release_texture_list(scene_material_root->texlist);
        scene_material_root->texlist = 0;
    }
    if (get_floor_map_selection(current_floor_index, &res) == 1) {
        tbl = (SceneNameIndex *)get_floor_scene_table(res.area);
        scene_resource_index = res.terrain;
        ent = tbl[res.terrain].idx;
    }
    copy_name((char *)current_floor_name);
    load_scene_map_file(ent);
    load_scene_collision_file(ent);
    if (scene_material_root != NULL && scene_material_root->texlist != 0) {
        found = 0;
        if (TRaderMapCore::is_not_split_screen() == 1) {
            TLobby::replace_file_extension((char *)path, (char *)tbl[scene_resource_index].name, (char *)"m.gvm");
            found = get_resource_file_size((const char *)path);
        }
        if (found <= 0) {
            TLobby::replace_file_extension((char *)path, (char *)tbl[scene_resource_index].name, (char *)".gvm");
        }
        bind_gvm_texture_list(path, scene_material_root->texlist);
    }
    TScene::load_floor_rel_file(ent);
    TScene::load_tam_file(ent);
    TScene::empty_floor_loader_1(ent);
    TScene::empty_floor_loader_2(ent);
    copy_name("..");
    floor_scene_ready_flag = 1;
    reflection_pass_active = 0;
    map_section_render_callback = 0;
    active_scene_callback = 0;
    render_callback = 0;
    visibility_radius_margin = 0.0f;
}

void load_scene_collision_file(saddr name) {
    struct Sp8Buf20_80206494 filename;
    TLobby::replace_file_extension((char *)((s32 *)&filename), (char *)name, (char *)"c.rel");
    if (get_resource_file_size((const char *)&filename) <= collision_file_size_limit) {
        if (collision_file_buffer != NULL) {
            scene_collision_data = (CsnGroup **)load_relocatable_file(reinterpret_cast<const char *>(&filename), collision_file_buffer);
            if (scene_collision_data != NULL && TObjMapCsn::get_collision_controller() != NULL) {
                TMapCsnCtrl *csn = TObjMapCsn::get_collision_controller();
                collect_collision_groups(csn, *scene_collision_data);
                return;
            }
            TLobby::debug_print("TScene : CANNOT LOAD COLLISION DATA");
            return;
        }
        scene_collision_data = NULL;
    }
}

void load_scene_map_file(saddr name) {
    u8 id[0x20];
    SceneNameIndex *e;
    scene_material_root = NULL;
    scene_format_index = -1;
    TLobby::replace_file_extension((char *)((s32 *)id), (char *)name, (char *)((s32 *)"n.rel"));
    if (get_resource_file_size((const char *)id) <= map_rel_load_size_limit && map_rel_load_buffer != NULL) {
        scene_material_root = (SceneMaterialRoot *)load_relocatable_file(reinterpret_cast<const char *>(id), map_rel_load_buffer);
    }
    if (scene_material_root != NULL) {
        for (e = scene_format_dispatch_tables; e->name != NULL; e++) {
            if (strncmp((const char *)scene_material_root, e->name, 4) == 0) {
                scene_format_index = e->idx;
                break;
            }
        }
    }
}

void TScene::load_tam_file(saddr name) {
    u8 filename[0x20];
    TLobby::replace_file_extension((char *)((s32 *)filename), (char *)name, (char *)((s32 *)".tam"));
    if (get_resource_file_size((const char *)filename) <= texture_animation_size_limit) {
        if (texture_animation_buffer != NULL) {
            read_disc_file((const char *)filename, texture_animation_buffer);
        } else {
            texture_animation_buffer = NULL;
        }
    }
}

void TScene::load_floor_rel_file(saddr name) {
    u8 id[0x20];
    TLobby::replace_file_extension((char *)((s32 *)id), (char *)name, (char *)((s32 *)"t.rel"));
    if (get_resource_file_size((const char *)id) <= loaded_floor_rel_file_index) {
        if (supplementary_rel_buffer != NULL) {
            texture_wave_resource = (u32)load_relocatable_file(reinterpret_cast<const char *>(id), supplementary_rel_buffer);
        } else {
            texture_wave_resource = 0;
        }
    }
}

void TScene::empty_floor_loader_1(saddr) {}

void TScene::empty_floor_loader_2(saddr) {}

void TScene::create() {
    new TScene(tl_02);
}

TScene::TScene(TObject *parent) : TObject(parent) {
    m_name = class_name;
    visible_section_count = 0;
    pad_30 = 0;
    pad_34 = 0;
    pad_38 = 0x32;
    pad_3C = 0;
    initialize_materials();
    if ((get_current_floor_area() == AREA_FOREST1) && ((u32) texture_wave_resource != 0U) && (scene_material_root != NULL) && (scene_material_root->texlist != 0)) {
        TScene::create_texture_wave_tasks(this);
    }
    init_material_nodes();
}

TScene::~TScene() {
    release_material_nodes();
    cleanup_materials();
    map_section_render_callback = 0;
    active_scene_callback = 0;
    render_callback = 0;
}

void TScene::initialize_materials() {
    typedef void (TScene::*MaterialInitializer)();
    static MaterialInitializer fns[2] = {
        &TScene::initialize_fmt1_materials,
        &TScene::initialize_fmt2_materials,
    };
    (this->*fns[scene_format_index])();
}

void TScene::initialize_fmt1_materials() {
    SceneMaterialSection *room;
    s32 section;
    SceneMaterialStatic *object;
    s32 i;
    SceneMaterialAnimated *anim;
    s32 j;
    if (!texture_animation_buffer || !scene_material_root) return;
    room = scene_material_root->sections;
    for (section = 0; section < scene_material_root->count; section++, room++) {
        object = room->objects;
        for (i = 0; i < room->count; i++, object++) {
            if ((object->flags & 0x20) && !find_uv_animation((TextureUvAnimation *)object->uv)) object->flags &= ~0x20;
            if ((object->flags & 0x40) && !load_texture_sequence_frame(this, object->cycle)) object->flags &= ~0x40;
        }
        anim = room->animated;
        for (j = 0; j < room->animatedCount; j++, anim++) {
            if ((anim->flags & 0x20) && !find_uv_animation((TextureUvAnimation *)anim->uv)) anim->flags &= ~0x20;
            if ((anim->flags & 0x40) && !load_texture_sequence_frame(this, anim->cycle)) anim->flags &= ~0x40;
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
    if (!texture_animation_buffer || !scene_material_root) return;
    room = scene_material_root->sections;
    for (section = 0; section < scene_material_root->count; section++, room++) {
        object = room->objects;
        for (i = 0; i < room->count; i++, object++) {
            if (object->flags & 0x20) {
                SceneMaterialUv *uv = object->uv;
                if (uv->buffer) continue;
                TextureUvAnimation def;
                def.id = uv->id;
                if (find_uv_animation(&def) == 1) {
                    uv->id = def.id; uv->texture = def.texture;
                    uv->u = def.u; uv->v = def.v; uv->du = def.du; uv->dv = def.dv;
                    SceneMaterialNode *node = resolve_indirect_node_record(task, object);
                    void *buffer = ::operator new(20);
                    if (buffer) buffer = ((TScene *)buffer)->init_buffers((saddr)node, uv->texture);
                    uv->buffer = buffer;
                } else {
                    object->flags &= ~0x20;
                }
            }
            if ((object->flags & 0x40) && !load_texture_sequence_frame(task, object->cycle)) object->flags &= ~0x40;
        }
        anim = room->animated;
        for (j = 0; j < room->animatedCount; j++, anim++) {
            if (anim->flags & 0x20) {
                SceneMaterialUv *uv2 = anim->uv;
                if (uv2->buffer) continue;
                TextureUvAnimation def2;
                def2.id = uv2->id;
                if (find_uv_animation(&def2) == 1) {
                    uv2->id = def2.id; uv2->texture = def2.texture;
                    uv2->u = def2.u; uv2->v = def2.v; uv2->du = def2.du; uv2->dv = def2.dv;
                    SceneMaterialNode *node2 = resolve_indirect_object_record(task, anim);
                    void *buffer2 = ::operator new(20);
                    if (buffer2) buffer2 = ((TScene *)buffer2)->init_buffers((saddr)node2, uv2->texture);
                    uv2->buffer = buffer2;
                } else {
                    anim->flags &= ~0x20;
                }
            }
            if ((anim->flags & 0x40) && !load_texture_sequence_frame(task, anim->cycle)) anim->flags &= ~0x40;
        }
    }
}

void TScene::cleanup_materials() {
    typedef void (TScene::*MaterialCleanup)();
    static MaterialCleanup fns[2] = {
        &TScene::cleanup_fmt1_materials,
        &TScene::cleanup_fmt2_materials,
    };
    (this->*fns[scene_format_index])();
}


void TScene::cleanup_fmt1_materials() {  }

void TScene::cleanup_fmt2_materials() {
    s32 i;
    s32 j;
    SceneMaterialUv *uv;
    s32 k;
    SceneMaterialUv *uv2;
    if (scene_material_root != NULL) {
        for (i = 0; i < scene_material_root->count; i++) {
            SceneMaterialSection *sections = scene_material_root->sections;
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


void TextureUvAnimation::copy_from(TextureUvAnimation *src) {
    id = src->id;
    texture = src->texture;
    u = src->u;
    v = src->v;
    du = src->du;
    dv = src->dv;
}

s32 TScene::find_uv_animation(TextureUvAnimation *uv) {
    s16 *p;
    s16 n = 0;
    TextureUvAnimation *rec = NULL;
    p = static_cast<s16 *>(texture_animation_buffer);
    while (p[0] != -1) {
        if (p[0] & 1) {
            n = p[2];
            rec = (TextureUvAnimation *)(p + 4);
            break;
        }
        if (p[0] & 2) {
            p += p[1] / 2 + 2;
        } else {
            return 0;
        }
    }
    while (n > 0) {
        if (rec->id == uv->id) {
            uv->copy_from(rec);
            return 1;
        }
        rec++;
        n--;
    }
    return 0;
}

s32 load_texture_sequence_frame(void *task, SceneMaterialCycle *c) {
    s16 *p = static_cast<s16 *>(texture_animation_buffer);
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

void TScene::create_texture_wave_tasks(TObject *parent) {
    TextureWaveEntry *e = *(TextureWaveEntry **)texture_wave_resource;
    do {
        new TEF_PvrWave(parent, e->image, e->size, e->texture_index);
        e++;
    } while (e->texture_index >= 0);
}

void TScene::init_material_nodes() {
    SceneMaterialSection *sec;
    s32 i;
    SceneMaterialStatic *st;
    s32 j;
    Node_80205AEC *node;
    SceneMaterialInfo *info;
    SceneMaterialAnimated *an;
    s32 j2;
    Node_80205AEC *node2;
    SceneMaterialInfo *info2;
    if (scene_material_root != NULL) {
        for (i = 0, sec = scene_material_root->sections; i < scene_material_root->count; i++, sec++) {
            for (j = 0, st = sec->objects; j < sec->count; j++, st++) {
                if (st->flags & 0x200) {
                    node = (Node_80205AEC *)st->node;
                    if (node->obj == NULL) {
                        info = find_material_entry_by_id(node->id);
                        if (info != NULL) {
                            node->obj = new TEffIndirect(info->effect_id, this);
                            node->tex = lbl_8044A800[info->texture_index];
                            node->b = lbl_8044A80C[info->pad_03];
                            node->c = info->effect_id;
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
                        info2 = find_material_entry_by_id(node2->id);
                        if (info2 != NULL) {
                            node2->obj = new TEffIndirect(info2->effect_id, this);
                            node2->tex = lbl_8044A800[info2->texture_index];
                            node2->b = lbl_8044A80C[info2->pad_03];
                            node2->c = info2->effect_id;
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


void TScene::release_material_nodes() {}

SceneMaterialInfo *TScene::find_material_entry_by_id(u16 id) {
    SceneMaterialInfoFile *t = static_cast<SceneMaterialInfoFile *>(material_info_buffer);
    if (t != 0) {
        SceneMaterialInfo *p = t->entries;
        s32 i;
        for (i = 0; i < t->count; i++, p++) {
            if (p->id == id) return p;
        }
    }
    return 0;
}


void TScene::run_task() { set_field4(); advance_scene_object_animations(); dispatch_material_animation(); }

void TScene::set_field4() {
    if ((void *) scene_material_root != NULL) {
        scene_material_root->flags = 0x8F;
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

    if (floor_scene_ready_flag != 0 && scene_material_root != NULL) {
        if (TMainTask::get_render_pass() == 0) {
            for (i = 0; i < scene_material_root->count; i++) {
                scene_material_root->sections[i].flags &= ~0x10000;
            }
            (this->*tbl[get_cull_mode()])();
        }
        render_map_sections();
        set_material_alpha_compare_reference(0xBF);
    }
}
#pragma pop

extern "C" {

s32 TScene::get_cull_mode() {
    if (floor_bin_buffer != NULL) {
        return 2;
    }
    if (reflection_pass_active == 1) {
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
    if (scene_material_root != NULL) {
        TObjPlayer::draw_if_all_ready();
        if (render_callback != NULL) {
            render_callback();
        }
        if (scene_material_root->texlist != 0) {
            TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(scene_material_root->texlist));
        }
        sec = scene_material_root->sections;
        prepare_ginja_model();
        saved_model_render_flags = model_render_flags;
        for (i = 0; i < scene_material_root->count; i++, sec++) {
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
void TScene::render_static_map_section(SceneMaterialSection *scene_material_section, s32 flagged_only) {
    SceneMaterialStatic *e;
    s32 i;
    SceneMaterialNode *node;
    TEffIndirect *tex;

    for (i = 0, e = scene_material_section->objects; i < scene_material_section->count; i++, e++) {
        if (flagged_only != 0 && !(e->flags & 0x10000)) {
            continue;
        }
        if (e->node == NULL) {
            continue;
        }
        if (reflection_pass_active == 1 && !(e->flags & 0x100)) {
            continue;
        }
        if (reflection_pass_active == 0 && (e->flags & 0x100)) {
            continue;
        }
        if (e->flags & 1) {
            TParticleCtrl::begin_effect_render();
        }
        if (e->flags & 2) {
            model_render_flags |= 1;
        }
        if (e->flags & 0x10) {
            SceneMaterialNode *sh = resolve_indirect_node_record(this, e);
            if (sh != NULL) {
                Vec v;
                SceneSectionAngles a;
                v.x = sh->position[0];
                v.y = sh->position[1];
                v.z = sh->position[2];
                vec3_add_to(&v, scene_material_section->position);
                a.x = sh->angles[0] + scene_material_section->angles[0];
                a.y = sh->angles[1] + scene_material_section->angles[1];
                a.z = sh->angles[2] + scene_material_section->angles[2];
                render_projected_shadow_receiver(&v, &a);
            }
        }
        node = resolve_indirect_node_record(this, e);
        if (map_section_render_callback != NULL) {
            Vec v;
            SceneSectionAngles a;
            v.x = node->position[0];
            v.y = node->position[1];
            v.z = node->position[2];
            vec3_add_to(&v, scene_material_section->position);
            a.x = node->angles[0] + scene_material_section->angles[0];
            a.y = node->angles[1] + scene_material_section->angles[1];
            a.z = node->angles[2] + scene_material_section->angles[2];
            map_section_render_callback(&v, &a, e->flags);
        }
        if (e->flags & 0x200) {
            if (e->flags & 0x80) {
                Model_8020533C *m = (Model_8020533C *)e->node;
                if (m != NULL) {
                    play_reflection_particles(m->effect_id);
                } else {
                    play_reflection_particles(-1);
                }
                TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>((void *)scene_material_root->texlist));
                set_material_alpha_compare_reference(scene_material_root->flags);
                draw_ginja_object(node);
                reset_reflection_tev_stages();
            } else if (e->flags & 0x400) {
                Model_8020533C *m = (Model_8020533C *)e->node;
                if (m != NULL && TMainTask::get_render_pass() == 1) {
                    Lobby_8020533C l;
                    l.v.x = node->position[0];
                    l.v.y = node->position[1];
                    l.v.z = node->position[2];
                    vec3_add_to(&l.v, scene_material_section->position);
                    l.a.x = node->angles[0] + scene_material_section->angles[0];
                    l.a.y = node->angles[1] + scene_material_section->angles[1];
                    l.a.z = node->angles[2] + scene_material_section->angles[2];
                    l.param = (void *)scene_material_root->texlist;
                    l.node = node;
                    l.scene = scene_material_root->flags;
                    l.id = m->effect_id;
                    release_indexed_entry__6TLobbyFl(&l);
                }
            } else {
                Model_8020533C *m = (Model_8020533C *)e->node;
                if (m != NULL) {
                    if (m->tex != NULL) {
                        enable_indirect_tev(tex = m->tex, m->sampler, m->scale, 0);
                        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>((void *)scene_material_root->texlist));
                        set_material_alpha_compare_reference(scene_material_root->flags);
                        draw_ginja_object(node);
                        disable_indirect_tev(tex, 0);
                    }
                }
            }
        } else {
            set_material_alpha_compare_reference(scene_material_root->flags);
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
        if (active_scene_callback != NULL) {
            active_scene_callback(e->flags);
        }
    }
}
void draw_ginja_model_with_motion(void *, void *, f32);
void TScene::render_animated_map_section(SceneMaterialSection *scene_material_section, s32 flagged_only) {
  TEffIndirect *texture;
  SceneMaterialAnimated *e;
  s32 i;
  SceneMaterialNode *node;
  for (i = 0, e = scene_material_section->animated; i < scene_material_section->animatedCount; i++, e++)
  {
    if ((flagged_only != 0) && (!(e->flags & 0x10000)))
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
    if ((reflection_pass_active == 1) && (!(e->flags & 0x100)))
    {
      continue;
    }
    if ((reflection_pass_active == 0) && (e->flags & 0x100))
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
    node = resolve_indirect_object_record(this, e);
    if (e->flags & 0x10)
    {
      Vec v;
      SceneSectionAngles a;
      v.x = node->position[0];
      v.y = node->position[1];
      v.z = node->position[2];
      vec3_add_to(&v, scene_material_section->position);
      a.x = node->angles[0] + scene_material_section->angles[0];
      a.y = node->angles[1] + scene_material_section->angles[1];
      a.z = node->angles[2] + scene_material_section->angles[2];
      render_projected_shadow_receiver(&v, &a);
    }
    if (map_section_render_callback != 0)
    {
      Vec v;
      SceneSectionAngles a;
      v.x = node->position[0];
      v.y = node->position[1];
      v.z = node->position[2];
      vec3_add_to(&v, scene_material_section->position);
      a.x = node->angles[0] + scene_material_section->angles[0];
      a.y = node->angles[1] + scene_material_section->angles[1];
      a.z = node->angles[2] + scene_material_section->angles[2];
      map_section_render_callback(&v, &a, e->flags);
    }
    if (e->flags & 0x200)
    {
      Model_8020533C *m = (Model_8020533C *) e->node;
      if (m != 0)
      {

        TEffIndirect *tex = m->tex;
        if (tex != 0)
        {
          enable_indirect_tev(texture = tex, m->sampler, m->scale, 0);
          TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(scene_material_root->texlist));
          set_material_alpha_compare_reference(scene_material_root->flags);
          draw_ginja_model_with_motion(node, e->motion, e->frame);
          disable_indirect_tev(texture, 0);
        }

      }
    }
    else
      if (TRaderMapCore::is_not_split_screen() == 1)
    {
      set_material_alpha_compare_reference(scene_material_root->flags);
      draw_ginja_object(node);
    }
    else
    {
      set_material_alpha_compare_reference(scene_material_root->flags);
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
    if (active_scene_callback != 0)
    {
      active_scene_callback(e->flags);
    }
  }

}
}

void TScene::sub_80204D7C() {
    Vec dir;
    Vec d;
    Vec up = lbl_8044A840[0];
    Vec p;
    f32 far2;
    SceneMaterialSection *sec;
    s32 i;

    if (scene_material_root == NULL) {
        return;
    }
    visible_section_count = 0;
    far2 = scene_material_root->radius * scene_material_root->radius;
    push_matrix_from(identity_matrix);
    rotate_matrix_y(0, camera_ctrl_instance->yaw);
    rotate_vector_by_matrix(0, &up, &dir);
    normalize_vector(&dir);
    pop_matrices(1);

    sec = scene_material_root->sections;
    for (i = 0; i < scene_material_root->count; i++) {
        if (sec->flags & 0x80000) {
            update_room_object_visibility(sec);
            sec++;
        } else {
            f32 dist;
            f32 dot;
            p.x = sec->position[0];
            p.y = 0.0f;
            p.z = sec->position[2];
            d.x = p.x - camera_ctrl_instance->pos.x;
            d.y = 0.0f;
            d.z = p.z - camera_ctrl_instance->pos.z;
            dist = d.x * d.x + d.y * d.y + d.z * d.z;
            if (dist < sec->radius * sec->radius) {
                sec->flags |= 0x10000;
                sec++;
                visible_section_count++;
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
                    rotate_matrix_y(0, camera_ctrl_instance->fov);
                    rotate_vector_by_matrix(0, &dir, &up);
                    normalize_vector(&up);
                    pop_matrices(1);
                    if (is_within_view_edge(&p, &d, &up, sec->radius) != 0) {
                        sec->flags |= 0x10000;
                        sec++;
                        visible_section_count++;
                    } else {
                        push_matrix_from(identity_matrix);
                        rotate_matrix_y(0, -camera_ctrl_instance->fov);
                        rotate_vector_by_matrix(0, &dir, &up);
                        normalize_vector(&up);
                        pop_matrices(1);
                        if (is_within_view_edge(&p, &d, &up, sec->radius) != 0) {
                            sec->flags |= 0x10000;
                            sec++;
                            visible_section_count++;
                        } else {
                            goto clear;
                        }
                    }
                } else {
                    sec->flags |= 0x10000;
                    sec++;
                    visible_section_count++;
                }
            }
        }
        continue;
    clear:
        sec->flags &= ~0x10000;
        sec++;
    }
}


s32 TScene::check_object_in_view_cone(SceneMaterialSection *section, Vec *pos, Vec *dir, s32 angle) {
    Vec c;
    Vec a;
    Vec b;
    f32 r2;
    f32 g2;
    f32 k;
    f32 z;
    f32 x;
    f32 dist2;
    f32 d;
    k = 0.0f;
    x = section->position[0];
    a.x = x;
    a.y = k;
    z = section->position[2];
    a.z = z;
    b.x = x - pos->x;
    b.y = k;
    b.z = z - pos->z;
    dist2 = b.x * b.x + b.y * b.y + b.z * b.z;
    r2 = section->radius * section->radius;
    g2 = scene_material_root->radius * scene_material_root->radius;
    if (dist2 < r2) {
        section->flags |= 0x10000;
        return 1;
    }
    if (dist2 > g2) {
        section->flags &= ~0x10000;
        return 0;
    }
    normalize_vector(&b);
    d = vec3_dot(dir, &b);
    if (d < 0.0f) {
        section->flags &= ~0x10000;
        return 0;
    }
    if (d >= 0.0f && d < 0.5f) {
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, angle);
        rotate_vector_by_matrix(0, dir, &c);
        normalize_vector(&c);
        pop_matrix();
        if (is_within_view_edge(&a, &b, &c, section->radius) != 0) {
            section->flags |= 0x10000;
            return 1;
        }
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, -angle);
        rotate_vector_by_matrix(0, dir, &c);
        normalize_vector(&c);
        pop_matrix();
        if (is_within_view_edge(&a, &b, &c, section->radius) != 0) {
            section->flags |= 0x10000;
            return 1;
        }
    } else {
        section->flags |= 0x10000;
        return 1;
    }
    section->flags &= ~0x10000;
    return 0;
}

void TScene::cull_sections() {
    static f32 s_near = 520.0f;
    static f32 s_far = 800.0f;
    static f32 s_pad = 80.0f;
    Vec dir;
    Vec d;
    Vec up = lbl_8044A84C[0];
    Vec p;
    Vec v;
    s32 i;
    SceneMaterialSection *sec;

    if (scene_material_root == NULL) {
        return;
    }
    if (is_split_screen() != 0) {
        s_near = 480.0f;
        s_far = 500.0f;
    } else {
        s_near = 600.0f;
        s_far = scene_material_root->radius;
    }
    visible_section_count = 0;
    push_matrix_from(identity_matrix);
    rotate_matrix_y(0, camera_ctrl_instance->yaw);
    rotate_vector_by_matrix(0, &up, &dir);
    normalize_vector(&dir);
    pop_matrix();

    sec = scene_material_root->sections;
    for (i = 0; i < scene_material_root->count; i++) {
        if (sec->flags & 0x80000) {
            update_room_object_visibility(sec);
            sec++;
        } else {
            f32 dist;
            f32 dot;
            p.x = sec->position[0];
            p.y = 0.0f;
            p.z = sec->position[2];
            d.x = p.x - camera_ctrl_instance->pos.x;
            d.y = 0.0f;
            d.z = p.z - camera_ctrl_instance->pos.z;
            dist = d.x * d.x + d.y * d.y + d.z * d.z;
            if (dist < sec->radius * sec->radius) {
                sec->flags |= 0x10000;
                sec++;
                visible_section_count++;
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
                    rotate_matrix_y(0, camera_ctrl_instance->fov);
                    rotate_vector_by_matrix(0, &dir, &up);
                    normalize_vector(&up);
                    pop_matrices(1);
                    if (is_within_view_edge(&p, &d, &up, sec->radius) != 0) {
                        sec->flags |= 0x10000;
                        sec++;
                        visible_section_count++;
                    } else {
                        push_matrix_from(identity_matrix);
                        rotate_matrix_y(0, -camera_ctrl_instance->fov);
                        rotate_vector_by_matrix(0, &dir, &up);
                        normalize_vector(&up);
                        pop_matrices(1);
                        if (is_within_view_edge(&p, &d, &up, sec->radius) != 0) {
                            sec->flags |= 0x10000;
                            sec++;
                            visible_section_count++;
                        } else {
                            goto clear;
                        }
                    }
                } else {
                    sec->flags |= 0x10000;
                    sec++;
                    visible_section_count++;
                }
            }
        }
        continue;
    clear:
        sec->flags &= ~0x10000;
        sec++;
    }

    sec = scene_material_root->sections;
    for (i = 0; i < scene_material_root->count; i++, sec++) {
        if (sec->flags & 0x100000) {
            SceneMaterialStatic *st = sec->objects;
            s32 j;
            for (j = 0; j < sec->count; j++, st++) {
                SceneMaterialNode *n = resolve_indirect_node_record(this, st);
                v.x = n->model->center[0] + (sec->position[0] + n->position[0]);
                v.y = n->model->center[1] + (sec->position[1] + n->position[1]);
                v.z = n->model->center[2] + (sec->position[2] + n->position[2]);
                if (is_in_view_depth(&v, s_near + s_pad, 100.0f) != 0) {
                    st->flags |= 0x10000;
                } else {
                    st->flags &= ~0x10000;
                }
            }
            {
                SceneMaterialAnimated *an = sec->animated;
                for (j = 0; j < sec->animatedCount; j++, an++) {
                    SceneMaterialNode *n = resolve_indirect_object_record(this, an);
                    v.x = sec->position[0] + n->position[0];
                    v.y = sec->position[1] + n->position[1];
                    v.z = sec->position[2] + n->position[2];
                    if (is_in_view_depth(&v, s_near + s_pad, 100.0f) != 0) {
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
    Vec dir;
    Vec fwd;
    Vec out;
    Tbl_802043CC *tbl;
    s32 j;
    Ent_802043CC *e;
    s16 *ids;
    SceneMaterialSection *room;
    s32 sec;
    s32 i;
    f32 d;
    sec = find_section_at_position(&camera_ctrl_instance->pos);
    if (sec < 0) {
        sub_80204D7C();
        return;
    }
    tbl = static_cast<Tbl_802043CC *>(floor_bin_buffer);
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
            d = xz_distance_squared((const Vec *)room->position, &camera_ctrl_instance->pos);
            if (d < room->radius * room->radius) {
                room->flags |= 0x10000;
            } else {
                VecCopy((Vec *)(&dir), (const Vec *)room->position);
                subtract_vector(&dir, &camera_ctrl_instance->pos);
                normalize_vector((Vec *)(&dir));
                fwd.x = 0.0f;
                fwd.y = 0.0f;
                fwd.z = -1.0f;
                push_matrix_from(identity_matrix);
                rotate_matrix_y(0, camera_ctrl_instance->yaw);
                rotate_vector_by_matrix(0, &fwd, (Vec *)(&out));
                pop_matrix();
                normalize_vector((Vec *)(&out));
                if (vec3_dot(&dir, &out) < 0.0f) {
                    room->flags &= ~0x10000;
                } else if (d < (*(SceneMaterialRoot * *)&scene_material_root)->radius * (*(SceneMaterialRoot * *)&scene_material_root)->radius) {
                    room->flags |= 0x10000;
                } else {
                    room->flags &= ~0x10000;
                }
            }
        }
    }
    {
        W_802043CC w = lbl_8044A858[0];
        Vec out2;
        SceneMaterialSection *s;
        s32 k;
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, camera_ctrl_instance->yaw);
        rotate_vector_by_matrix(0, &w, (Vec *)(&out2));
        normalize_vector((Vec *)(&out2));
        pop_matrix();
        s = (*(SceneMaterialRoot * *)&scene_material_root)->sections;
        for (k = 0; k < (*(SceneMaterialRoot * *)&scene_material_root)->count; k++, s++) {
            if (s->flags & 0x80000) {
                update_room_object_visibility(s);
            } else if (s->id < 0) {
                check_object_in_view_cone(s, &camera_ctrl_instance->pos, &out2, camera_ctrl_instance->fov);
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
    Vec v = camera_ctrl_instance->pos;
    i = 0;
    off = 0;
    r = scene_material_root->radius + visibility_radius_margin;
    r2 = r * r;
    for (; i < scene_material_root->count; i++, off += sizeof(SceneMaterialSection)) {
        SceneMaterialSection *rec = (SceneMaterialSection *)((u8 *)scene_material_root->sections + off);
        if (xz_distance_squared(&v, (const Vec *)rec->position) < r2) {
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
            if (TScene__sub_802040D4(this, resolve_indirect_node_record(this, object), 10000.0f, 100.0f) != 0) {
                object->flags |= 0x10000;
            } else {
                object->flags &= ~0x10000;
            }
        }
    }
    for (anim = room->animated, i = 0; i < room->animatedCount; i++, anim++) {
        if (anim->node != NULL) {
            if (TScene__sub_802040D4(this, resolve_indirect_object_record(this, anim), 10000.0f, 100.0f) != 0) {
                anim->flags |= 0x10000;
            } else {
                anim->flags &= ~0x10000;
            }
        }
    }
}
BOOL TScene::is_in_view_depth(Vec *pos, f32 depth, f32) {
    Vec view;
    matrix_mult_vec(NULL, pos, &view);
    if (view.z > 0.0f) {
        return FALSE;
    }
    if (view.z < -depth) {
        return FALSE;
    }
    return TRUE;
}
extern "C" {
s32 TScene__sub_802040D4(TScene *scene, SceneMaterialNode *node, f32 f0, f32 f1) {
    if (node->model != NULL && camera_ctrl_instance != NULL) {
        Vec *pos = (Vec *)node->position;
        if (xz_distance_squared(&camera_ctrl_instance->pos, pos) < node->model->radius * node->model->radius) {
            return 1;
        }
        return scene->is_in_view_depth(pos, f0, f1);
    }
    return 0;
}
}

s32 TScene::is_within_view_edge(Vec *pos, Vec *dir, Vec *edge, f32 radius) {
    struct { Vec origin, direction; } line;
    Vec closest;
    if (vec3_dot(dir, edge) < 0.0f) {
        return 0;
    }
    line.origin.x = camera_ctrl_instance->pos.x;
    line.origin.y = 0.0f;
    line.origin.z = camera_ctrl_instance->pos.z;
    line.direction.x = edge->x;
    line.direction.y = edge->y;
    line.direction.z = edge->z;
    return project_point_onto_line(pos, &line, &closest) <= radius;
}
void TScene::advance_scene_object_animations() {
    SceneMaterialSection *g;
    s32 i;
    SceneMaterialAnimated *a;
    s32 j;
    if (scene_material_root == NULL) {
        return;
    }
    g = scene_material_root->sections;
    for (i = 0; i < scene_material_root->count; i++, g++) {
        a = g->animated;
        for (j = 0; j < g->animatedCount; j++, a++) {
            a->flags &= ~0x40000;
        }
    }
    g = scene_material_root->sections;
    for (i = 0; i < scene_material_root->count; i++, g++) {
        a = g->animated;
        for (j = 0; j < g->animatedCount; j++, a++) {
            if (!(a->flags & 0x40000)) {
                a->frame += a->speed;
                if (a->motion != NULL && a->frame > (a->motion->nbFrame - 1)) {
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
    (this->*fns[scene_format_index])();
}

#pragma defer_codegen off
