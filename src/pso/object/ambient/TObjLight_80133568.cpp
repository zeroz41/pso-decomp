#include "pso/system/ResourceFile.h"
#include "pso/system/NinjaTypes.h"
#include "types.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/object/TUnk_804A6FC0.h"
#include "pso/object/TUnk_804A6FA8.h"
#include "pso/object/TUnk_804A6F90.h"
#include "pso/object/TUnk_804A6F78.h"
#include "pso/system/task/TMainTask.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/object/ambient/TObjLight_803DF220.h"
#include "pso/system/memory.h"
#include "pso/system/byteswap.h"
#include "pso/system/vector.h"
#include "pso/quest/TQuestThread.h"
#include "pso/map/FloorArea.h"

#include <stddef.h>
#include "pso/object/ambient/TObjLight.h"
#include "pso/object/ambient/PointLight.h"
#include "pso/unk/TLobby.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/system/scene/TScene.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/object/base/TObjBase.h"
#include "pso/math/MatrixVector.h"
#include "pso/unk/text_803DD5E0.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

extern "C" {
void GXInitLightDir(void *light, f32 nx, f32 ny, f32 nz);
void GXInitLightSpot(void *light, f32 cutoff, s32 spot_func);
void GXInitLightDistAttn(void *light, f32 ref_distance, f32 ref_brightness, s32 dist_func);
void __dt__7TObjectFv(void *, int);
}

// The GX light id of each point light slot.
int light_type_id_table[3] = { 2, 3, 4 };
TObjLightSceneLightState scene_light_state;
PointLight *light_slots[3];
ActorLight actor_light_table[32];
ActorLight light_table[8];
extern "C" {
__declspec(section ".data") u32 TObjLight__data_80506A5C;
}
const char light_entry_file_name[] = "lightentry.bin";
extern "C" {
TQuestThread *TLobby__sub_80134A20(void *p) { return TQuestThread::create_in_root((saddr)p); }

extern s32 lbl_804A7008[];

void *__dt__13TUnk_804A7008Fv(void *object, s16 arg1) {
    if (object != NULL) {
        *(s32 **)((s8 *)object + 0x18) = lbl_804A7008;
        __dt__7TObjectFv(object, 0);
        if (arg1 > 0) {
            TObject::operator delete(object);
        }
    }
    return object;
}
}

void LightEntry::bswap_data() {
    bswap_32((u32 *)&direction.x);
    bswap_32((u32 *)&direction.y);
    bswap_32((u32 *)&direction.z);
    bswap_32((u32 *)&view_direction.x);
    bswap_32((u32 *)&view_direction.y);
    bswap_32((u32 *)&view_direction.z);
    bswap_32((u32 *)&pad_18);
    bswap_32((u32 *)&intensity);
    bswap_32((u32 *)&ambient);
    bswap_32((u32 *)&color.a);
    bswap_32((u32 *)&color.r);
    bswap_32((u32 *)&color.g);
    bswap_32((u32 *)&color.b);
    bswap_32((u32 *)&ambient_color.a);
    bswap_32((u32 *)&ambient_color.r);
    bswap_32((u32 *)&ambient_color.g);
    bswap_32((u32 *)&ambient_color.b);
}

TUnk_804A6F90::~TUnk_804A6F90() {}

TUnk_804A6F78::~TUnk_804A6F78() {}

void TObjLight::init_light_tables() {
    s32 i;
    s32 j;
    for (i = 0; i < 32; i++) {
        actor_light_table[i].id = 0xFFFF;
        actor_light_table[i].direction.x = 0.0f;
        actor_light_table[i].direction.y = 0.0f;
        actor_light_table[i].direction.z = 0.0f;
        actor_light_table[i].color.a = 0.0f;
        actor_light_table[i].color.r = 0.0f;
        actor_light_table[i].color.g = 0.0f;
        actor_light_table[i].color.b = 0.0f;
        actor_light_table[i].ambient = 0.0f;
        actor_light_table[i].intensity = 0.0f;
        actor_light_table[i].flags = 0;
    }
    actor_light_count = 0;
    for (j = 0; j < 8; j++) {
        light_table[j].id = 0xFFFF;
        light_table[j].direction.x = 0.0f;
        light_table[j].direction.y = 0.0f;
        light_table[j].direction.z = 0.0f;
        light_table[j].color.a = 0.0f;
        light_table[j].color.r = 0.0f;
        light_table[j].color.g = 0.0f;
        light_table[j].color.b = 0.0f;
        light_table[j].ambient = 0.0f;
        light_table[j].intensity = 0.0f;
        light_table[j].flags = 0;
    }
    light_count = 0;
}

void register_actor_light(s32 id, TObjLight *light) {
    if (actor_light_count < 32) {
        actor_light_table[actor_light_count].id = id;
        VecCopy(&actor_light_table[actor_light_count].direction, &light->actor_direction);
        copy_argb(&actor_light_table[actor_light_count].color, &light->actor_color);
        actor_light_count += 1;
    }
}

void publish_light_direction_color(u32 id, void *dir, void *color) {
    s32 add;
    s32 i;
    ActorLight *e;
    add = 1;
    if (light_count < 8) {
        for (i = 0; i < 8; i++) {
            e = &light_table[i];
            if (id == e->id) {
                light_table[i].id = id;
                VecCopy(&e->direction, (const Vec *)dir);
                copy_argb(&e->color, (NJS_ARGB *)color);
                add = 0;
                light_table[i].flags |= 2;
                break;
            }
            if (e->id == 0xFFFF) {
                break;
            }
        }
        if (add) {
            light_table[light_count].id = id;
            VecCopy(&light_table[light_count].direction, (const Vec *)dir);
            copy_argb(&light_table[light_count].color, (NJS_ARGB *)color);
            light_table[light_count].flags |= 2;
            light_count++;
        }
    }
}

void publish_actor_light_scalars(u32 id, f32 intensity, f32 ambient) {
    s32 count = light_count;
    s32 add;
    s32 i;
    ActorLight *e;
    add = 1;
    if (count < 8) {
        for (i = 0; i < 8; i++) {
            if (id == light_table[i].id) {
                add = 0;
                light_table[i].id = id;
                light_table[i].intensity = intensity;
                light_table[i].ambient = ambient;
                light_table[i].flags |= 1;
                break;
            }
            if (light_table[i].id == 0xFFFF) {
                break;
            }
        }
        if (add != 0) {
            e = &light_table[count];
            e->id = id;
            e->intensity = intensity;
            e->ambient = ambient;
            e->flags |= 1;
            light_count++;
        }
    }
}

void TObjLight::find_light_params(f32 *dir, f32 *color, u32 id) {
    s32 i;
    for (i = 0; i < actor_light_count; i++) {
        ActorLight *e = &actor_light_table[i];
        if (id == e->id) {
            VecCopy((Vec *)dir, &e->direction);
            copy_argb((NJS_ARGB *)color, &e->color);
            return;
        }
    }
    copy_argb((NJS_ARGB *)color, &scene_light_state.color);
    VecCopy((Vec *)dir, &scene_light_state.view_direction);
}


void select_actor_lighting(TObjBase *obj) {
    s32 i;

    for (i = 0; i < light_count; i++) {
        if (light_table[i].id == obj->get_entity_id()) {
            if ((light_table[i].flags & 1) && (light_table[i].flags & 2)) {
                set_light_ambient_color(light_table[i].ambient, light_table[i].ambient, light_table[i].ambient);
                init_distant_light(0, light_table[i].direction.x, light_table[i].direction.y, light_table[i].direction.z);
                GXInitLightDir(gx_light_objects, light_table[i].direction.x, light_table[i].direction.y, light_table[i].direction.z);
                set_gx_light_color(0, light_table[i].color.r, light_table[i].color.g, light_table[i].color.b);
                load_gx_light_slot(0);
                return;
            }
            if (light_table[i].flags & 1) {
                set_light_ambient_color(scene_light_state.ambient, scene_light_state.ambient, scene_light_state.ambient);
                load_gx_light_slot(0);
                return;
            }
            if (get_current_floor_area() == AREA_LOBBY) {
                init_distant_light(0, light_table[i].direction.x, light_table[i].direction.y, light_table[i].direction.z);
                GXInitLightDir(gx_light_objects, light_table[i].direction.x, light_table[i].direction.y, light_table[i].direction.z);
                set_gx_light_color(0, light_table[i].color.r, light_table[i].color.g, light_table[i].color.b);
                load_gx_light_slot(0);
                return;
            }
            init_distant_light(0, light_table[i].direction.x, light_table[i].direction.y, light_table[i].direction.z);
            GXInitLightDir(gx_light_objects, light_table[i].direction.x, light_table[i].direction.y, light_table[i].direction.z);
            set_gx_light_color(0, light_table[i].color.r, light_table[i].color.g, light_table[i].color.b);
            return;
        }
    }
    for (i = 0; i < actor_light_count; i++) {
        if (actor_light_table[i].id == obj->get_entity_id()) {
            init_distant_light(0, actor_light_table[i].direction.x, actor_light_table[i].direction.y, actor_light_table[i].direction.z);
            GXInitLightDir(gx_light_objects, actor_light_table[i].direction.x, actor_light_table[i].direction.y, actor_light_table[i].direction.z);
            set_light_ambient_color(scene_light_state.ambient, scene_light_state.ambient, scene_light_state.ambient);
            set_gx_light_color(0, actor_light_table[i].color.r, actor_light_table[i].color.g, actor_light_table[i].color.b);
            load_gx_light_slot(0);
            return;
        }
    }
    set_light_ambient_color(scene_light_state.ambient, scene_light_state.ambient, scene_light_state.ambient);
    init_distant_light(0, scene_light_state.view_direction.x, scene_light_state.view_direction.y, scene_light_state.view_direction.z);
    GXInitLightDir(gx_light_objects, scene_light_state.view_direction.x, scene_light_state.view_direction.y, scene_light_state.view_direction.z);
    set_gx_light_color(0, scene_light_state.color.r, scene_light_state.color.g, scene_light_state.color.b);
    load_gx_light_slot(0);
}

void restore_scene_lighting(void) {
    if (get_current_floor_area() == AREA_LOBBY) {
        init_distant_light(0, scene_light_state.view_direction.x, scene_light_state.view_direction.y, scene_light_state.view_direction.z);
        GXInitLightDir(gx_light_objects, scene_light_state.view_direction.x, scene_light_state.view_direction.y, scene_light_state.view_direction.z);
        set_gx_light_color(0, scene_light_state.color.r, scene_light_state.color.g, scene_light_state.color.b);
        load_gx_light_slot(0);
    } else {
        init_distant_light(0, scene_light_state.view_direction.x, scene_light_state.view_direction.y, scene_light_state.view_direction.z);
        GXInitLightDir(gx_light_objects, scene_light_state.view_direction.x, scene_light_state.view_direction.y, scene_light_state.view_direction.z);
        set_gx_light_color(0, scene_light_state.color.r, scene_light_state.color.g, scene_light_state.color.b);
        load_gx_light_slot(0);
    }
    set_light_ambient_color(scene_light_state.ambient, scene_light_state.ambient, scene_light_state.ambient);
}

void set_light(const Vec *dir, const NJS_ARGB *color, f32 ambient) {
    init_distant_light(0, dir->x, dir->y, dir->z);
    GXInitLightDir(gx_light_objects, dir->x, dir->y, dir->z);
    set_gx_light_color(0, color->r, color->g, color->b);
    set_light_ambient_color(ambient, ambient, ambient);
    load_gx_light_slot(0);
}

void TObjLight::apply_distant_light() {
    set_light_ambient_color(scene_light_state.ambient, scene_light_state.ambient, scene_light_state.ambient);
    init_distant_light(0, scene_light_state.view_direction.x, scene_light_state.view_direction.y, scene_light_state.view_direction.z);
    GXInitLightDir(gx_light_objects, scene_light_state.view_direction.x, scene_light_state.view_direction.y, scene_light_state.view_direction.z);
    set_gx_light_color(0, scene_light_state.color.r, scene_light_state.color.g, scene_light_state.color.b);
    load_gx_light_slot(0);
}

TUnk_804A6FC0::TUnk_804A6FC0(TObject *parent) : TObject(parent) {}

TUnk_804A6FC0::~TUnk_804A6FC0() {}

void load_light_entry_file(void) {
    light_entry_data = NULL;
    light_entry_file_size = get_resource_file_size(light_entry_file_name);
    if (light_entry_file_size > 0) {
        light_entry_data = (LightEntry *)TQuestVmDownLoadServer::alloc(light_entry_file_size);
        if (light_entry_data) {
            read_disc_file(light_entry_file_name, light_entry_data);
        }
    }
}

void TObjLight::free_shared_data() {
    if (light_entry_data != NULL) {
        safe_free(light_entry_data);
        light_entry_data = NULL;
    }
}

void init_area_lights(void) {
    LightEntry entry;
    s32 area;
    if (light_entry_data != NULL) {
        area = get_current_floor_area();
        if (TLobby::is_online_ready() != 0) {
            area += 48.0f;
        }
        *(LightEntryBytes *)&entry = *(LightEntryBytes *)&light_entry_data[area];
        entry.bswap_data();
        init_map_lights(&entry);
        return;
    }
    init_map_lights(&default_scene_light_config);
}

TUnk_804A6FA8::TUnk_804A6FA8(TObject *parent) : TObject(parent) {}

TUnk_804A6FA8::~TUnk_804A6FA8() {}

void TUnk_804A6FA8::run_task() {
    s32 i;
    s32 j;
    for (i = 0; i < 32; i++) {
        actor_light_table[i].id = 0xFFFF;
        actor_light_table[i].direction.x = 0.0f;
        actor_light_table[i].direction.y = 0.0f;
        actor_light_table[i].direction.z = 0.0f;
        actor_light_table[i].color.a = 0.0f;
        actor_light_table[i].color.r = 0.0f;
        actor_light_table[i].color.g = 0.0f;
        actor_light_table[i].color.b = 0.0f;
        actor_light_table[i].ambient = 0.0f;
        actor_light_table[i].intensity = 0.0f;
        actor_light_table[i].flags = 0;
    }
    for (j = 0; j < 8; j++) {
        light_table[j].id = 0xFFFF;
        light_table[j].direction.x = 0.0f;
        light_table[j].direction.y = 0.0f;
        light_table[j].direction.z = 0.0f;
        light_table[j].color.a = 0.0f;
        light_table[j].color.r = 0.0f;
        light_table[j].color.g = 0.0f;
        light_table[j].color.b = 0.0f;
        light_table[j].ambient = 0.0f;
        light_table[j].intensity = 0.0f;
        light_table[j].flags = 0;
    }
    light_count = 0;
    actor_light_count = 0;
}

void init_map_lights(LightEntry *entry) {
    Vec direction;
    direction.x = entry->direction.x;
    direction.y = entry->direction.y;
    direction.z = entry->direction.z;
    if (0.0f != vector_length(&direction)) {
        normalize_vector(&direction);
    }
    scene_light_state.direction.x = direction.x;
    scene_light_state.direction.y = direction.y;
    scene_light_state.direction.z = direction.z;
    scene_light_state.pad_18 = entry->pad_18;
    scene_light_state.intensity = entry->intensity;
    scene_light_state.ambient = entry->ambient;
    scene_light_state.color.r = entry->color.r;
    scene_light_state.color.g = entry->color.g;
    scene_light_state.color.b = entry->color.b;
    scene_light_state.ambient_color.r = entry->ambient_color.r;
    scene_light_state.ambient_color.g = entry->ambient_color.g;
    scene_light_state.ambient_color.b = entry->ambient_color.b;
    TObjLight::init_light_tables();
    new TUnk_804A6F90(tl_02);
    new TUnk_804A6FA8(tl_02);
    new TUnk_804A6F78(tl_02);
}

void init_menu_scene_lights(LightEntry *entry, s32) {
    Vec direction;
    direction.x = entry->direction.x;
    direction.y = entry->direction.y;
    direction.z = entry->direction.z;
    if (0.0f != vector_length(&direction)) {
        normalize_vector(&direction);
    }
    scene_light_state.direction.x = direction.x;
    scene_light_state.direction.y = direction.y;
    scene_light_state.direction.z = direction.z;
    scene_light_state.pad_18 = entry->pad_18;
    scene_light_state.intensity = entry->intensity;
    scene_light_state.ambient = entry->ambient;
    scene_light_state.color.r = entry->color.r;
    scene_light_state.color.g = entry->color.g;
    scene_light_state.color.b = entry->color.b;
    scene_light_state.ambient_color.r = entry->ambient_color.r;
    scene_light_state.ambient_color.g = entry->ambient_color.g;
    scene_light_state.ambient_color.b = entry->ambient_color.b;
    scene_light_state.view_direction.x = entry->view_direction.x;
    scene_light_state.view_direction.y = entry->view_direction.y;
    scene_light_state.view_direction.z = entry->view_direction.z;
    new TUnk_804A6F90(tl_02);
    new TUnk_804A6FA8(tl_02);
}

void set_scene_light_color(f32 r, f32 g, f32 b) {
    scene_light_state.color.r = r;
    scene_light_state.color.g = g;
    scene_light_state.color.b = b;
}

TUnk_804A6F90::TUnk_804A6F90(TObject *parent) : TUnk_804A6FC0(parent) {
    rotate_vector_by_matrix(0, &scene_light_state.direction, &scene_light_state.view_direction);
    sub_8013397C();
    submit_scene_light_direction();
    set_scene_light_diffuse();
    lbl_805D5558 = this;
}

void TUnk_804A6F90::sub_8013397C() {}

void TUnk_804A6F90::submit_scene_light_direction() {
    init_distant_light(0, scene_light_state.view_direction.x, scene_light_state.view_direction.y, scene_light_state.view_direction.z);
    GXInitLightDir(gx_light_objects, scene_light_state.view_direction.x, scene_light_state.view_direction.y, scene_light_state.view_direction.z);
}

void TUnk_804A6F90::set_scene_light_diffuse() {
    set_gx_light_color(0, scene_light_state.color.r, scene_light_state.color.g, scene_light_state.color.b);
}


void TUnk_804A6F90::render() {
    Vec v;
    rotate_vector_by_matrix(0, &scene_light_state.direction, &scene_light_state.view_direction);
    v.x = scene_light_state.view_direction.x;
    v.y = scene_light_state.view_direction.y;
    v.z = scene_light_state.view_direction.z;
    f32 length = vector_length(&v);
    if (length) {
        normalize_vector(&v);
    }
    scene_light_state.view_direction.x = v.x;
    scene_light_state.view_direction.y = v.y;
    scene_light_state.view_direction.z = v.z;
    submit_light0(0, 1);
    submit_scene_light_direction();
    set_scene_light_diffuse();
    sub_8013397C();
    GXInitLightSpot(gx_light_objects, 180.0f, 1);
    GXInitLightDistAttn(gx_light_objects, 100000000.0f, 0.9f, 0);
    load_gx_light_slot(0);
}

void TObjLight__sub_801337FC(void *light) {}

void TObjLight::sub_801337F8() {}

void TObjLight::init_directional_light() {
    init_distant_light(0, scene_light_state.view_direction.x, scene_light_state.view_direction.y, scene_light_state.view_direction.z);
    GXInitLightDir(gx_light_objects, scene_light_state.view_direction.x, scene_light_state.view_direction.y, scene_light_state.view_direction.z);
}

void TObjLight::sub_8013379C(TObjLightSceneLightState *state) {}

TUnk_804A6F78::TUnk_804A6F78(TObject *parent) : TUnk_804A6FC0(parent) {
    s32 i;
    lbl_805D5564 = this;
    active_light_count = 1;
    submit_scene_ambient_color();
    sub_80133714();
    sub_801336DC();
    for (i = 0; i < 3; i++) {
        light_slots[i] = 0;
    }
}

void TUnk_804A6F78::sub_80133714() {}

void TUnk_804A6F78::submit_scene_ambient_color() {
    set_light_ambient_color(scene_light_state.ambient_color.r, scene_light_state.ambient_color.g, scene_light_state.ambient_color.b);
}


void TUnk_804A6F78::sub_801336DC() {}

PointLight *TObjLight::alloc_light_slot() {
    s32 i;
    PointLight **slot;
    slot = light_slots;
    for (i = 0; i < 3; slot++, i++) {
        if (*slot == NULL) {
            *slot = new PointLight(i);
            active_light_count++;
            return *slot;
        }
    }
    return 0;
}

void PointLight::unregister_and_free() {
    s32 i;
    PointLight **slot = light_slots;
    for (i = 0; i < 3; i++) {
        if (*slot == this) {
            *slot = NULL;
            active_light_count--;
            break;
        }
        slot++;
    }
    ::operator delete(this);
}

void TUnk_804A6F78::render() {  }

PointLight::PointLight(s32 index) {
    light_id = light_type_id_table[index];
    position.x = position.y = position.z = 0.0f;
    apply_position();
    range[0] = 5.0f;
    range[1] = 30.0f;
    apply_range();
    color[0] = 1.0f;
    color[1] = 1.0f;
    color[2] = 1.0f;
    apply_color();
}

LightEntry default_scene_light_config = {
    { 0.0f, -0.5f, 0.5f },
    { 0.0f, 0.0f, 1.0f },
    0.3f, 0.96f, 0.3f,
    { 0.0f, 0.7f, 0.8f, 0.8f },
    { 0.0f, 1.0f, 1.0f, 1.0f },
};

TUnk_804A6F90 *lbl_805D5558;
void *lbl_805D555C;
TObjLight *current_scene_light;
TUnk_804A6F78 *lbl_805D5564;
s32 active_light_count;
s32 actor_light_count;
s32 light_count;
LightEntry *light_entry_data;
s32 light_entry_file_size;
