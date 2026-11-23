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
#include "pso/unk/TLobby.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/system/scene/TScene.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/object/base/TObjBase.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

struct ByteBlock_44 { u8 bytes[0x44]; };

struct LightEntry_801344A4 { f32 dir[3]; f32 color[4]; u8 pad[0xC]; u32 id; };

struct Light_801347A4 {
    f32 dir[3];
    f32 color[4];
    f32 f1C;
    f32 f20;
    s32 f24;
    u32 id;
};

struct Light_80133C1C {
    f32 f0, f4, f8, fC, f10, f14, f18, f1C, f20;
    s32 f24;
    s32 f28;
};

extern "C" {
s32 GXInitLightDir(s32 *, f32, f32, f32);
extern s32 gx_light_objects[];
s32 rotate_vector_by_matrix(int, void *, void *);
extern s32 actor_light_count;
f32 vector_length(void *);
extern f32 default_scene_light_config[];
extern uaddr light_entry_data;
extern s32 active_light_count;
extern s32 light_entry_file_size;
__declspec(section ".rodata") char lbl_8043ED80[] = "lightentry.bin";
void GXInitLightSpot(void *, s32, f32);
void GXInitLightDistAttn(void *, s32, f32, f32);
extern s32 light_count;
int TAdSinglePlyChrSelectGC__sub_801334E4(void*);
int TAdSinglePlyChrSelectGC__sub_80133544(void*);
int TAdSinglePlyChrSelectGC__sub_80133548(void);
void __dt__7TObjectFv(void *, int);

    extern int light_type_id_table[];
}
TObjLightSceneLightState scene_light_state;
extern "C" {
void *light_slots[3];
// register_actor_light appends one entry per actor in range (actor_light_count).
Light_801347A4 actor_light_table[32];
// publish_light_direction_color keeps one entry per light id (light_count).
Light_801347A4 light_table[8];
__declspec(section ".data") u32 TObjLight__data_80506A5C;
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

void TObjLight::bswap_data() { bswap_32((u32 *)this); bswap_32((u32 *)((char*)this + 0x4)); bswap_32((u32 *)((char*)this + 0x8)); bswap_32((u32 *)((char*)this + 0xc)); bswap_32((u32 *)((char*)this + 0x10)); bswap_32((u32 *)((char*)this + 0x14)); bswap_32((u32 *)((char*)this + 0x18)); bswap_32((u32 *)((char*)this + 0x1c)); bswap_32((u32 *)((char*)this + 0x20)); bswap_32((u32 *)((char*)this + 0x24)); bswap_32((u32 *)((char*)this + 0x28)); bswap_32((u32 *)((char*)this + 0x2c)); bswap_32(&this->actorFlags); bswap_32((u32 *)((char*)this + 0x34)); bswap_32((u32 *)((char*)this + 0x38)); bswap_32((u32 *)((char*)this + 0x3c)); bswap_32((u32 *)((char*)this + 0x40)); }

TUnk_804A6F90::~TUnk_804A6F90() {}

TUnk_804A6F78::~TUnk_804A6F78() {}

void TObjLight::init_light_tables() {
    s32 i;
    s32 j;
    for (i = 0; i < 0x20; i++) {
        ((Light_801347A4 *)&actor_light_table)[i].id = 0xFFFF;
        ((Light_801347A4 *)&actor_light_table)[i].dir[0] = 0.0f;
        ((Light_801347A4 *)&actor_light_table)[i].dir[1] = 0.0f;
        ((Light_801347A4 *)&actor_light_table)[i].dir[2] = 0.0f;
        ((Light_801347A4 *)&actor_light_table)[i].color[0] = 0.0f;
        ((Light_801347A4 *)&actor_light_table)[i].color[1] = 0.0f;
        ((Light_801347A4 *)&actor_light_table)[i].color[2] = 0.0f;
        ((Light_801347A4 *)&actor_light_table)[i].color[3] = 0.0f;
        ((Light_801347A4 *)&actor_light_table)[i].f20 = 0.0f;
        ((Light_801347A4 *)&actor_light_table)[i].f1C = 0.0f;
        ((Light_801347A4 *)&actor_light_table)[i].f24 = 0;
    }
    actor_light_count = 0;
    for (j = 0; j < 8; j++) {
        light_table[j].id = 0xFFFF;
        light_table[j].dir[0] = 0.0f;
        light_table[j].dir[1] = 0.0f;
        light_table[j].dir[2] = 0.0f;
        light_table[j].color[0] = 0.0f;
        light_table[j].color[1] = 0.0f;
        light_table[j].color[2] = 0.0f;
        light_table[j].color[3] = 0.0f;
        light_table[j].f20 = 0.0f;
        light_table[j].f1C = 0.0f;
        light_table[j].f24 = 0;
    }
    light_count = 0;
}

void register_actor_light(s32 arg0, TObjLight *light) {
    u8 *temp_r5;
    if ((s32) actor_light_count < 0x20) {
        temp_r5 = (u8 *)actor_light_table + (actor_light_count * 0x2C);
        *(s32 *)((s8 *)temp_r5 + 0x28) = arg0;
        VecCopy((Vec *)(temp_r5), &light->actor_direction);
        copy_argb((NJS_ARGB *)((u8 *)actor_light_table + (actor_light_count * 0x2C) + 0xC), &light->actor_color);
        actor_light_count += 1;
    }
}

void publish_light_direction_color(u32 id, void *dir, void *color) {
    s32 add;
    s32 i;
    Light_801347A4 *e;
    add = 1;
    if (light_count < 8) {
        for (i = 0; i < 8; i++) {
            e = &light_table[i];
            if (id == e->id) {
                light_table[i].id = id;
                VecCopy((Vec *)e, (const Vec *)dir);
                copy_argb((NJS_ARGB *)e->color, (NJS_ARGB *)color);
                add = 0;
                light_table[i].f24 |= 2;
                break;
            }
            if (e->id == 0xFFFF) {
                break;
            }
        }
        if (add) {
            light_table[light_count].id = id;
            VecCopy((Vec *)&light_table[light_count], (const Vec *)dir);
            copy_argb((NJS_ARGB *)light_table[light_count].color, (NJS_ARGB *)color);
            light_table[light_count].f24 |= 2;
            light_count++;
        }
    }
}

void publish_actor_light_scalars(u32 arg0, f32 farg0, f32 farg1) {
    s32 cnt = light_count;
    s32 found;
    s32 n;
    Light_801347A4 *q;
    found = 1;
    if (cnt < 8) {
        for (n = 0; n < 8; n++) {
            if (arg0 == light_table[n].id) {
                found = 0;
                light_table[n].id = arg0;
                light_table[n].f1C = farg0;
                light_table[n].f20 = farg1;
                light_table[n].f24 |= 1;
                break;
            }
            if (light_table[n].id == 0xFFFF) {
                break;
            }
        }
        if (found != 0) {
            q = &light_table[cnt];
            q->id = arg0;
            q->f1C = farg0;
            q->f20 = farg1;
            q->f24 |= 1;
            light_count++;
        }
    }
}

void TObjLight::find_light_params(f32 *dir, f32 *color, u32 id) {
    s32 i;
    for (i = 0; i < actor_light_count; i++) {
        LightEntry_801344A4 *e = &((LightEntry_801344A4 *)&actor_light_table)[i];
        if (id == e->id) {
            VecCopy((Vec *)dir, (const Vec *)e->dir);
            copy_argb((NJS_ARGB *)color, (NJS_ARGB *)e->color);
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
            if (((u32)light_table[i].f24 & 1) && ((u32)light_table[i].f24 & 2)) {
                set_light_ambient_color(light_table[i].f20, light_table[i].f20, light_table[i].f20);
                init_distant_light(0, light_table[i].dir[0], light_table[i].dir[1], light_table[i].dir[2]);
                GXInitLightDir(gx_light_objects, light_table[i].dir[0], light_table[i].dir[1], light_table[i].dir[2]);
                set_gx_light_color(0, light_table[i].color[1], light_table[i].color[2], light_table[i].color[3]);
                load_gx_light_slot(0);
                return;
            }
            if ((u32)light_table[i].f24 & 1) {
                set_light_ambient_color(scene_light_state.ambient, scene_light_state.ambient, scene_light_state.ambient);
                load_gx_light_slot(0);
                return;
            }
            if (get_current_floor_area() == AREA_LOBBY) {
                init_distant_light(0, light_table[i].dir[0], light_table[i].dir[1], light_table[i].dir[2]);
                GXInitLightDir(gx_light_objects, light_table[i].dir[0], light_table[i].dir[1], light_table[i].dir[2]);
                set_gx_light_color(0, light_table[i].color[1], light_table[i].color[2], light_table[i].color[3]);
                load_gx_light_slot(0);
                return;
            }
            init_distant_light(0, light_table[i].dir[0], light_table[i].dir[1], light_table[i].dir[2]);
            GXInitLightDir(gx_light_objects, light_table[i].dir[0], light_table[i].dir[1], light_table[i].dir[2]);
            set_gx_light_color(0, light_table[i].color[1], light_table[i].color[2], light_table[i].color[3]);
            return;
        }
    }
    for (i = 0; i < actor_light_count; i++) {
        if (actor_light_table[i].id == obj->get_entity_id()) {
            init_distant_light(0, actor_light_table[i].dir[0], actor_light_table[i].dir[1], actor_light_table[i].dir[2]);
            GXInitLightDir(gx_light_objects, actor_light_table[i].dir[0], actor_light_table[i].dir[1], actor_light_table[i].dir[2]);
            set_light_ambient_color(scene_light_state.ambient, scene_light_state.ambient, scene_light_state.ambient);
            set_gx_light_color(0, actor_light_table[i].color[1], actor_light_table[i].color[2], actor_light_table[i].color[3]);
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
        GXInitLightDir((s32 *)(&gx_light_objects[0]), scene_light_state.view_direction.x, scene_light_state.view_direction.y, scene_light_state.view_direction.z);
        set_gx_light_color(0, scene_light_state.color.r, scene_light_state.color.g, scene_light_state.color.b);
        load_gx_light_slot(0);
    } else {
        init_distant_light(0, scene_light_state.view_direction.x, scene_light_state.view_direction.y, scene_light_state.view_direction.z);
        GXInitLightDir((s32 *)(&gx_light_objects[0]), scene_light_state.view_direction.x, scene_light_state.view_direction.y, scene_light_state.view_direction.z);
        set_gx_light_color(0, scene_light_state.color.r, scene_light_state.color.g, scene_light_state.color.b);
        load_gx_light_slot(0);
    }
    set_light_ambient_color(scene_light_state.ambient, scene_light_state.ambient, scene_light_state.ambient);
}

void TObjLight::set_light(void *arg1, f32 farg0) {
    init_distant_light(0, *(f32 *)&this->m_name, *(f32 *)&this->m_flags, *(f32 *)&this->m_prev);
    GXInitLightDir(gx_light_objects, *(f32 *)&this->m_name, *(f32 *)&this->m_flags, *(f32 *)&this->m_prev);
    set_gx_light_color(0, *(f32 *)((s8 *)arg1 + 4), *(f32 *)((s8 *)arg1 + 8), *(f32 *)((s8 *)arg1 + 0xC));
    set_light_ambient_color(farg0, farg0, farg0);
    load_gx_light_slot(0);
}

void TObjLight::apply_distant_light() {
    set_light_ambient_color(scene_light_state.ambient, scene_light_state.ambient, scene_light_state.ambient);
    init_distant_light(0, scene_light_state.view_direction.x, scene_light_state.view_direction.y, scene_light_state.view_direction.z);
    GXInitLightDir((s32 *)(&gx_light_objects[0]), scene_light_state.view_direction.x, scene_light_state.view_direction.y, scene_light_state.view_direction.z);
    set_gx_light_color(0, scene_light_state.color.r, scene_light_state.color.g, scene_light_state.color.b);
    load_gx_light_slot(0);
}

TUnk_804A6FC0::TUnk_804A6FC0(TObject *parent) : TObject(parent) {}

TUnk_804A6FC0::~TUnk_804A6FC0() {}

}

void load_light_entry_file(void) {
    light_entry_data = 0;
    light_entry_file_size = get_resource_file_size(lbl_8043ED80);
    if (light_entry_file_size > 0) {
        light_entry_data = (saddr)TQuestVmDownLoadServer::alloc(light_entry_file_size);
        if (light_entry_data) {
            read_disc_file(lbl_8043ED80, (void *)light_entry_data);
        }
    }
}

void TObjLight::free_shared_data() {
    if ((u32) light_entry_data != 0U) {
        TAdSinglePlyChrSelectGC::safe_free((uaddr)((void*)light_entry_data));
        light_entry_data = 0U;
    }
}

void init_area_lights(void) {
    struct CopyStack_80133D78 { u8 bytes[0x44]; };
    CopyStack_80133D78 copy_storage_80133D78;
    s32 global_state;
    if ((u32) light_entry_data != 0U) {
        global_state = get_current_floor_area();
        if (TLobby::is_online_ready() != 0) {
            global_state += 48.0f;
        }
        *(ByteBlock_44 *)(copy_storage_80133D78.bytes) = *(const ByteBlock_44 *)(((light_entry_data + (global_state * 0x44)) - 4) + 4);
        ((TObjLight *)(copy_storage_80133D78.bytes))->bswap_data();
        init_map_lights((u8 *)((void *) ((copy_storage_80133D78.bytes))));
        return;
    }
    init_map_lights((u8 *)default_scene_light_config);
}

TUnk_804A6FA8::TUnk_804A6FA8(TObject *parent) : TObject(parent) {}

TUnk_804A6FA8::~TUnk_804A6FA8() {}

void TUnk_804A6FA8::run_task() {
    s32 i;
    s32 j;
    for (i = 0; i < 32; i++) {
        ((Light_80133C1C *)&actor_light_table)[i].f28 = 0xFFFF;
        ((Light_80133C1C *)&actor_light_table)[i].f0 = 0.0f;
        ((Light_80133C1C *)&actor_light_table)[i].f4 = 0.0f;
        ((Light_80133C1C *)&actor_light_table)[i].f8 = 0.0f;
        ((Light_80133C1C *)&actor_light_table)[i].fC = 0.0f;
        ((Light_80133C1C *)&actor_light_table)[i].f10 = 0.0f;
        ((Light_80133C1C *)&actor_light_table)[i].f14 = 0.0f;
        ((Light_80133C1C *)&actor_light_table)[i].f18 = 0.0f;
        ((Light_80133C1C *)&actor_light_table)[i].f20 = 0.0f;
        ((Light_80133C1C *)&actor_light_table)[i].f1C = 0.0f;
        ((Light_80133C1C *)&actor_light_table)[i].f24 = 0;
    }
    for (j = 0; j < 8; j++) {
        ((Light_80133C1C *)light_table)[j].f28 = 0xFFFF;
        ((Light_80133C1C *)light_table)[j].f0 = 0.0f;
        ((Light_80133C1C *)light_table)[j].f4 = 0.0f;
        ((Light_80133C1C *)light_table)[j].f8 = 0.0f;
        ((Light_80133C1C *)light_table)[j].fC = 0.0f;
        ((Light_80133C1C *)light_table)[j].f10 = 0.0f;
        ((Light_80133C1C *)light_table)[j].f14 = 0.0f;
        ((Light_80133C1C *)light_table)[j].f18 = 0.0f;
        ((Light_80133C1C *)light_table)[j].f20 = 0.0f;
        ((Light_80133C1C *)light_table)[j].f1C = 0.0f;
        ((Light_80133C1C *)light_table)[j].f24 = 0;
    }
    light_count = 0;
    actor_light_count = 0;
}

void init_map_lights(u8 *arg0) {
    Vec stack;
    stack.x = *(f32 *)((s8 *)arg0 + 0);
    stack.y = *(f32 *)((s8 *)arg0 + 4);
    stack.z = *(f32 *)((s8 *)arg0 + 8);
    if (0.0f != vector_length(&stack.x)) {
        normalize_vector(&stack);
    }
    scene_light_state.direction.x = stack.x;
    scene_light_state.direction.y = stack.y;
    scene_light_state.direction.z = stack.z;
    scene_light_state.pad_18 = (f32) *(f32 *)((s8 *)arg0 + 0x18);
    scene_light_state.intensity = (f32) *(f32 *)((s8 *)arg0 + 0x1C);
    scene_light_state.ambient = (f32) *(f32 *)((s8 *)arg0 + 0x20);
    scene_light_state.color.r = (f32) *(f32 *)((s8 *)arg0 + 0x28);
    scene_light_state.color.g = (f32) *(f32 *)((s8 *)arg0 + 0x2C);
    scene_light_state.color.b = (f32) *(f32 *)((s8 *)arg0 + 0x30);
    scene_light_state.ambient_color.r = (f32) *(f32 *)((s8 *)arg0 + 0x38);
    scene_light_state.ambient_color.g = (f32) *(f32 *)((s8 *)arg0 + 0x3C);
    scene_light_state.ambient_color.b = (f32) *(f32 *)((s8 *)arg0 + 0x40);
    TObjLight::init_light_tables();
    new TUnk_804A6F90(tl_02);
    new TUnk_804A6FA8(tl_02);
    new TUnk_804A6F78(tl_02);
}

void init_menu_scene_lights(u8 *arg0, s32 arg1) {
    Vec stack;
    stack.x = *(f32 *)((s8 *)arg0 + 0);
    stack.y = *(f32 *)((s8 *)arg0 + 4);
    stack.z = *(f32 *)((s8 *)arg0 + 8);
    if (0.0f != vector_length(&stack.x)) {
        normalize_vector(&stack);
    }
    scene_light_state.direction.x = stack.x;
    scene_light_state.direction.y = stack.y;
    scene_light_state.direction.z = stack.z;
    scene_light_state.pad_18 = (f32) *(f32 *)((s8 *)arg0 + 0x18);
    scene_light_state.intensity = (f32) *(f32 *)((s8 *)arg0 + 0x1C);
    scene_light_state.ambient = (f32) *(f32 *)((s8 *)arg0 + 0x20);
    scene_light_state.color.r = (f32) *(f32 *)((s8 *)arg0 + 0x28);
    scene_light_state.color.g = (f32) *(f32 *)((s8 *)arg0 + 0x2C);
    scene_light_state.color.b = (f32) *(f32 *)((s8 *)arg0 + 0x30);
    scene_light_state.ambient_color.r = (f32) *(f32 *)((s8 *)arg0 + 0x38);
    scene_light_state.ambient_color.g = (f32) *(f32 *)((s8 *)arg0 + 0x3C);
    scene_light_state.ambient_color.b = (f32) *(f32 *)((s8 *)arg0 + 0x40);
    scene_light_state.view_direction.x = (f32) *(f32 *)((s8 *)arg0 + 0xC);
    scene_light_state.view_direction.y = (f32) *(f32 *)((s8 *)arg0 + 0x10);
    scene_light_state.view_direction.z = (f32) *(f32 *)((s8 *)arg0 + 0x14);
    new TUnk_804A6F90(tl_02);
    new TUnk_804A6FA8(tl_02);
}

void TObjBoss2Tunnel__sub_801339EC(f32 farg0, f32 farg1, f32 farg2) {
    scene_light_state.color.r = farg0;
    scene_light_state.color.g = farg1;
    scene_light_state.color.b = farg2;
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
    GXInitLightDir((s32 *)(&gx_light_objects[0]), scene_light_state.view_direction.x, scene_light_state.view_direction.y, scene_light_state.view_direction.z);
}

void TUnk_804A6F90::set_scene_light_diffuse() {
    set_gx_light_color(0, (f32) (scene_light_state.color.r), (f32) (scene_light_state.color.g), (f32) (scene_light_state.color.b));
}


void TUnk_804A6F90::render() {
    Vec v;
    rotate_vector_by_matrix(0, &scene_light_state.direction, &scene_light_state.view_direction);
    v.x = scene_light_state.view_direction.x;
    v.y = scene_light_state.view_direction.y;
    v.z = scene_light_state.view_direction.z;
    f32 m = vector_length(&v);
    if (m) {
        normalize_vector(&v);
    }
    scene_light_state.view_direction.x = v.x;
    scene_light_state.view_direction.y = v.y;
    scene_light_state.view_direction.z = v.z;
    submit_light0(0, 1);
    submit_scene_light_direction();
    set_scene_light_diffuse();
    sub_8013397C();
    GXInitLightSpot(((s32 *)&gx_light_objects), 1, 180.0f);
    GXInitLightDistAttn(((s32 *)&gx_light_objects), 0, 100000000.0f, 0.9f);
    load_gx_light_slot(0);
}

void TObjLight__sub_801337FC(void *light) {}

void TObjLight::sub_801337F8() {}

void TObjLight::init_directional_light() {
    init_distant_light(0, scene_light_state.view_direction.x, scene_light_state.view_direction.y, scene_light_state.view_direction.z);
    GXInitLightDir((s32 *)(&gx_light_objects[0]), scene_light_state.view_direction.x, scene_light_state.view_direction.y, scene_light_state.view_direction.z);
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

uaddr TObjLight::alloc_light_slot() {
    s32 i;
    uaddr *p;
    void *r;
    p = ((uaddr *)&light_slots);
    for (i = 0; i < 3; p++, i++) {
        if (*p == 0) {
            r = ::operator new(0x2C);
            if (r != 0) {
                r = ((void *)((TObjLight *)r)->init_light(i));
            }
            *p = (uaddr)r;
            active_light_count++;
            return *p;
        }
    }
    return 0;
}

void TObjLight::unregister_and_free() {
    s32 i;
    void **q = light_slots;
    for (i = 0; i < 3; i++) {
        if (*q == this) {
            *q = 0;
            active_light_count--;
            break;
        }
        q++;
    }
    ::operator delete(this);
}

void TUnk_804A6F78::render() {  }

void*TObjLight::init_light(int a1) { *(int *)&this->m_name = light_type_id_table[a1]; *(float *)&this->m_up = 0.0f; *(float *)&this->m_next = 0.0f; *(float *)&this->m_prev = 0.0f; TAdSinglePlyChrSelectGC__sub_80133548(); *(float *)&this->m_down = 5.0f; *(float*)((char*)this + 0x18) = 30.0f; TAdSinglePlyChrSelectGC__sub_80133544(this); *(float *)&this->m_20 = 1.0f; *(float *)&this->texlist = 1.0f; *(float *)&this->room = 1.0f; TAdSinglePlyChrSelectGC__sub_801334E4(this); return this; }

int light_type_id_table[3] = { 2, 3, 4 };
f32 default_scene_light_config[17] = {
    0.0f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.3f, 0.96f, 0.3f,
    0.0f, 0.7f, 0.8f, 0.8f, 0.0f, 1.0f, 1.0f, 1.0f,
};

TUnk_804A6F90 *lbl_805D5558;
void *lbl_805D555C;
TObjLight *current_scene_light;
TUnk_804A6F78 *lbl_805D5564;
s32 active_light_count;
s32 actor_light_count;
s32 light_count;
uaddr light_entry_data;
s32 light_entry_file_size;
