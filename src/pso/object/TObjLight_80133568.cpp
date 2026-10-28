#include "pso/system/NinjaTypes.h"
#include "types.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/object/TUnk_804A6FA8.h"
#include "pso/object/TUnk_804A6F78.h"
#include "pso/object/TObjLight_80133568.h"
#include "pso/object/TObjLight_803DF220.h"
#include "pso/system/memory.h"
#include "pso/system/byteswap.h"
#include "pso/system/vector.h"
#include "pso/quest/TQuestThread.h"
#include "pso/map/FloorArea.h"

struct RecoveredGlobal_801336E0_TObjLight__data_80506320 {
    s32 value;
    u8 remaining[0x4C];
};

struct RecoveredGlobal_801337A0_TObjLight__data_80506320 {
    s32 value;
    u8 remaining[0x4C];
};

struct RecoveredGlobal_801337A0_TObjLight__data_8058D528 {
    s32 value;
    u8 remaining[0x13C];
};

struct RecoveredGlobal_801338EC_TObjLight__data_80506320 {
    s32 value;
    u8 remaining[0x4C];
};

struct RecoveredGlobal_80133924_TObjLight__data_80506320 {
    s32 value;
    u8 remaining[0x4C];
};

struct RecoveredGlobal_80133924_TObjLight__data_8058D528 {
    s32 value;
    u8 remaining[0x13C];
};

struct RecoveredGlobal_80133980_lbl_804A6F90 {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_80133980_TObjLight__data_80506320 {
    s32 value;
    u8 remaining[0x4C];
};

struct RecoveredGlobal_801339EC_TObjLight__data_80506320 {
    s32 value;
    u8 remaining[0x4C];
};

struct RecoveredGlobal_80133F6C_TObjLight__data_80506320 {
    s32 value;
    u8 remaining[0x4C];
};

struct RecoveredGlobal_80133F6C_TObjLight__data_8058D528 {
    s32 value;
    u8 remaining[0x13C];
};

struct RecoveredGlobal_80134098_TObjLight__data_80506320 {
    s32 value;
    u8 remaining[0x4C];
};

struct RecoveredGlobal_80134098_TObjLight__data_8058D528 {
    s32 value;
    u8 remaining[0x13C];
};

struct RecoveredGlobal_80134724_TObjLight__data_8050637C {
    s32 value;
    u8 remaining[0x57C];
};

#include <stddef.h>
#include "pso/object/TObjLight.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TQuestVmDownLoadServer.h"
#include "pso/misc/TScene.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
struct Stack_80133A04 {
    f32 sp8;
    f32 spC;
    f32 sp10;
};

struct RecoveredGlobal_80133A04_TObjLight__data_80506320 {
    s32 value;
    u8 remaining[0x4C];
};

struct Stack_80133B10 {
    f32 sp8;
    f32 spC;
    f32 sp10;
};

struct RecoveredGlobal_80133B10_TObjLight__data_80506320 { s32 value; u8 remaining[0x4C]; };

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

struct ByteBlock_44 { u8 bytes[0x44]; };

struct RecoveredGlobal_80133D78_lbl_804A6F34 {
    s32 value;
    u8 remaining[0x40];
};

struct LightEntry_801344A4 { f32 dir[3]; f32 color[4]; u8 pad[0xC]; u32 id; };

struct LightDefault_801344A4 { u8 pad0[0xC]; f32 dir[3]; u8 pad18[0xC]; f32 color[4]; u8 rest[0x5C - 0x34]; };

struct Vec_80133800 { f32 x, y, z; };

struct Light_80133800 {
    Vec_80133800 pos;
    Vec_80133800 dir;
    u8 rest[0x50 - 0x18];
};

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
extern s32 TObjLight__gx_light_objects[];
s32 rotate_vector_by_matrix(int, void *, void *);
extern s32 lbl_804A6F90[];
extern u8 *lbl_805D5558;
extern s32 TObjLight__actor_light_count;
u32 __nw__7TObjectFUl(int);
f32 vector_length(void *);
f32 normalize_vector(void *);
extern s32 tl_02;
extern const float TObjLight__data_805DB088;
extern RecoveredGlobal_80133D78_lbl_804A6F34 default_scene_light_config;
extern u32 TObjLight__light_entry_data;
extern const f32 lbl_805DB0A4;
extern s32 TObjLight__active_light_count;
extern s32 light_entry_file_size;
__declspec(section ".rodata") char lbl_8043ED80[] = "lightentry.bin";
s32 read_disc_file(void *, u32);
void GXInitLightSpot(void *, s32, f32);
void GXInitLightDistAttn(void *, s32, f32, f32);
extern const f32 lbl_805DB098;
extern const f32 lbl_805DB09C;
extern const f32 lbl_805DB0A0;
extern s32 TObjLight__light_count;
extern s32 lbl_804A6F78[];
extern void *lbl_805D5564;
int TAdSinglePlyChrSelectGC__sub_801334E4(void*);
int TAdSinglePlyChrSelectGC__sub_80133544(void*);
int TAdSinglePlyChrSelectGC__sub_80133548(void);
void __ct__7TObjectFP7TObject(void *);
void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);

    extern int light_type_id_table[];
    extern const float lbl_805DB08C;
    extern const float lbl_805DB090;
    extern const float lbl_805DB094;
u32 TObjLight__scene_light_state[20];
void *TObjLight__data_80506370[3];
Light_801347A4 TObjLight__data_8050637C[32];
Light_801347A4 TObjLight__data_805068FC[8];
__declspec(section ".data") u32 TObjLight__data_80506A5C;
#define TObjLight__scene_light_state (*(RecoveredGlobal_801336E0_TObjLight__data_80506320 *)TObjLight__scene_light_state)

void*TObjLight::init_light(int a1) { *(int *)&this->m_name = light_type_id_table[a1]; *(float *)&this->m_up = TObjLight__data_805DB088; *(float *)&this->m_next = TObjLight__data_805DB088; *(float *)&this->m_prev = TObjLight__data_805DB088; TAdSinglePlyChrSelectGC__sub_80133548(); *(float *)&this->m_down = lbl_805DB08C; *(float*)((char*)this + 0x18) = lbl_805DB090; TAdSinglePlyChrSelectGC__sub_80133544(this); *(float *)&this->m_20 = lbl_805DB094; *(float *)&this->texlist = lbl_805DB094; *(float *)&this->room = lbl_805DB094; TAdSinglePlyChrSelectGC__sub_801334E4(this); return this; }

void TUnk_804A6F78::render() {  }

void TObjLight::unregister_and_free() {
    s32 i;
    void **q = TObjLight__data_80506370;
    for (i = 0; i < 3; i++) {
        if (*q == this) {
            *q = 0;
            TObjLight__active_light_count--;
            break;
        }
        q++;
    }
    ::operator delete(this);
}

u32 TObjLight::alloc_light_slot() {
    s32 i;
    u32 *p;
    void *r;
    p = ((u32 *)&TObjLight__data_80506370);
    for (i = 0; i < 3; p++, i++) {
        if (*p == 0) {
            r = ::operator new(0x2C);
            if (r != 0) {
                r = ((void *)((TObjLight *)r)->init_light(i));
            }
            *p = (u32)r;
            TObjLight__active_light_count++;
            return *p;
        }
    }
    return 0;
}

void TObjLight__sub_801336DC(void) {  }
}

typedef char RecoveredGlobal_801336E0_TObjLight__data_80506320_size[sizeof(RecoveredGlobal_801336E0_TObjLight__data_80506320) == 0x50 ? 1 : -1];
void submit_scene_ambient_color(void) {
    set_light_ambient_color(*(f32 *)((s8 *)&TObjLight__scene_light_state.value + 0x38), *(f32 *)((s8 *)&TObjLight__scene_light_state.value + 0x3C), *(f32 *)((s8 *)&TObjLight__scene_light_state.value + 0x40));
}

void TObjLight__sub_80133714(void) {  }

void *TObjLight::init_map_light(int _w1) {
    s32 i;
    init_object();
    *(void ***)((u8 *)this + 0x18) = ((void * *)&lbl_804A6F78);
    lbl_805D5564 = this;
    TObjLight__active_light_count = 1;
    ((void (*)(void *))submit_scene_ambient_color)(this);
    ((void (*)(void *))TObjLight__sub_80133714)(this);
    ((void (*)(void *))TObjLight__sub_801336DC)(this);
    for (i = 0; i < 3; i++) {
        TObjLight__data_80506370[i] = 0;
    }
    return this;
}

void TObjLight__sub_8013379C(void) {  }

typedef char RecoveredGlobal_801337A0_TObjLight__data_80506320_size[sizeof(RecoveredGlobal_801337A0_TObjLight__data_80506320) == 0x50 ? 1 : -1];
typedef char RecoveredGlobal_801337A0_TObjLight__data_8058D528_size[sizeof(RecoveredGlobal_801337A0_TObjLight__data_8058D528) == 0x140 ? 1 : -1];
void TObjLight::init_directional_light() {
    init_distant_light(0, *(f32 *)((s8 *)(&(*(RecoveredGlobal_801337A0_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 0xC), *(f32 *)((s8 *)(&(*(RecoveredGlobal_801337A0_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 0x10), *(f32 *)((s8 *)(&(*(RecoveredGlobal_801337A0_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 0x14));
    GXInitLightDir((s32 *)(&(*(RecoveredGlobal_801337A0_TObjLight__data_8058D528 *)&TObjLight__gx_light_objects).value), *(f32 *)((s8 *)(&(*(RecoveredGlobal_801337A0_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 0xC), *(f32 *)((s8 *)(&(*(RecoveredGlobal_801337A0_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 0x10), *(f32 *)((s8 *)(&(*(RecoveredGlobal_801337A0_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 0x14));
}

void TObjLight__sub_801337F8(void) {  }
void TObjLight__sub_801337FC(void) {  }

typedef char RecoveredGlobal_801338EC_TObjLight__data_80506320_size[sizeof(RecoveredGlobal_801338EC_TObjLight__data_80506320) == 0x50 ? 1 : -1];

#define G_80133800 (*(Light_80133800 *)&TObjLight__scene_light_state)
void apply_environment_light(s32 arg0) {
    Vec_80133800 v;
    rotate_vector_by_matrix(0, &G_80133800, &G_80133800.dir);
    v.x = G_80133800.dir.x;
    v.y = G_80133800.dir.y;
    v.z = G_80133800.dir.z;
    f32 m = vector_length(&v);
    if (m != (*(const f32 *)&TObjLight__data_805DB088)) {
        normalize_vector(&v);
    }
    G_80133800.dir.x = v.x;
    G_80133800.dir.y = v.y;
    G_80133800.dir.z = v.z;
    submit_light0(0, 1);
    submit_scene_light_direction((void *)arg0);
    set_scene_light_diffuse((void *)arg0);
    TObjLight__sub_8013397C((void *)arg0);
    GXInitLightSpot(((s32 *)&TObjLight__gx_light_objects), 1, lbl_805DB098);
    GXInitLightDistAttn(((s32 *)&TObjLight__gx_light_objects), 0, lbl_805DB09C, lbl_805DB0A0);
    load_gx_light_slot(0);
}

void set_scene_light_diffuse(void * _w0) {
    set_gx_light_color(0, (f32) (*(f32 *)((s8 *)(&(*(RecoveredGlobal_801338EC_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 0x28)), (f32) (*(f32 *)((s8 *)(&(*(RecoveredGlobal_801338EC_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 0x2C)), (f32) (*(f32 *)((s8 *)(&(*(RecoveredGlobal_801338EC_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 0x30)));
}

typedef char RecoveredGlobal_80133924_TObjLight__data_80506320_size[sizeof(RecoveredGlobal_80133924_TObjLight__data_80506320) == 0x50 ? 1 : -1];
typedef char RecoveredGlobal_80133924_TObjLight__data_8058D528_size[sizeof(RecoveredGlobal_80133924_TObjLight__data_8058D528) == 0x140 ? 1 : -1];
void submit_scene_light_direction(void * _w0) {
    init_distant_light(0, *(f32 *)((s8 *)(&(*(RecoveredGlobal_80133924_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 0xC), *(f32 *)((s8 *)(&(*(RecoveredGlobal_80133924_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 0x10), *(f32 *)((s8 *)(&(*(RecoveredGlobal_80133924_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 0x14));
    GXInitLightDir((s32 *)(&(*(RecoveredGlobal_80133924_TObjLight__data_8058D528 *)&TObjLight__gx_light_objects).value), *(f32 *)((s8 *)(&(*(RecoveredGlobal_80133924_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 0xC), *(f32 *)((s8 *)(&(*(RecoveredGlobal_80133924_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 0x10), *(f32 *)((s8 *)(&(*(RecoveredGlobal_80133924_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 0x14));
}

void TObjLight__sub_8013397C(void * _w0) {  }

extern s32 lbl_804A6FA8[];

typedef char RecoveredGlobal_80133980_lbl_804A6F90_size[sizeof(RecoveredGlobal_80133980_lbl_804A6F90) == 0x18 ? 1 : -1];
typedef char RecoveredGlobal_80133980_TObjLight__data_80506320_size[sizeof(RecoveredGlobal_80133980_TObjLight__data_80506320) == 0x50 ? 1 : -1];
u8 *TObjLight__sub_80133980(u8 *light, int _w1) {
    ((TObjLight *)light)->init_object();
    *(s32 **)((s8 *)light + 0x18) = &(*(RecoveredGlobal_80133980_lbl_804A6F90 *)&lbl_804A6F90).value;
    rotate_vector_by_matrix(0, (void *) (&(*(RecoveredGlobal_80133980_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value), (void *) ((u8 *)&(*(RecoveredGlobal_80133980_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value + 0xC));
    TObjLight__sub_8013397C(light);
    submit_scene_light_direction(light);
    set_scene_light_diffuse(light);
    lbl_805D5558 = light;
    return light;
}

typedef char RecoveredGlobal_801339EC_TObjLight__data_80506320_size[sizeof(RecoveredGlobal_801339EC_TObjLight__data_80506320) == 0x50 ? 1 : -1];
void TObjBoss2Tunnel__sub_801339EC(f32 farg0, f32 farg1, f32 farg2) {
    *(f32 *)((s8 *)(&(*(RecoveredGlobal_801339EC_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 0x28) = farg0;
    *(f32 *)((s8 *)(&(*(RecoveredGlobal_801339EC_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 0x2C) = farg1;
    *(f32 *)((s8 *)(&(*(RecoveredGlobal_801339EC_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 0x30) = farg2;
}

typedef char RecoveredGlobal_80133A04_TObjLight__data_80506320_size[sizeof(RecoveredGlobal_80133A04_TObjLight__data_80506320) == 0x50 ? 1 : -1];
void init_menu_scene_lights(u8 *arg0) {
    typedef char sp8_offset[(offsetof(Stack_80133A04, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_80133A04, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_80133A04, sp10) == 0x8) ? 1 : -1];
    Stack_80133A04 stack;
    u32 light;
    u32 temp_r3_2;
    stack.sp8 = *(f32 *)((s8 *)arg0 + 0);
    stack.spC = *(f32 *)((s8 *)arg0 + 4);
    stack.sp10 = *(f32 *)((s8 *)arg0 + 8);
    if ((*(const f32 *)&TObjLight__data_805DB088) != vector_length(&stack.sp8)) {
        normalize_vector(&stack.sp8);
    }
    *(f32 *)((s8 *)(&(*(RecoveredGlobal_80133A04_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 0) = stack.sp8;
    *(f32 *)((s8 *)(&(*(RecoveredGlobal_80133A04_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 4) = stack.spC;
    *(f32 *)((s8 *)(&(*(RecoveredGlobal_80133A04_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 8) = stack.sp10;
    *(f32 *)((s8 *)(&(*(RecoveredGlobal_80133A04_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 0x18) = (f32) *(f32 *)((s8 *)arg0 + 0x18);
    *(f32 *)((s8 *)(&(*(RecoveredGlobal_80133A04_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 0x1C) = (f32) *(f32 *)((s8 *)arg0 + 0x1C);
    *(f32 *)((s8 *)(&(*(RecoveredGlobal_80133A04_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 0x20) = (f32) *(f32 *)((s8 *)arg0 + 0x20);
    *(f32 *)((s8 *)(&(*(RecoveredGlobal_80133A04_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 0x28) = (f32) *(f32 *)((s8 *)arg0 + 0x28);
    *(f32 *)((s8 *)(&(*(RecoveredGlobal_80133A04_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 0x2C) = (f32) *(f32 *)((s8 *)arg0 + 0x2C);
    *(f32 *)((s8 *)(&(*(RecoveredGlobal_80133A04_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 0x30) = (f32) *(f32 *)((s8 *)arg0 + 0x30);
    *(f32 *)((s8 *)(&(*(RecoveredGlobal_80133A04_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 0x38) = (f32) *(f32 *)((s8 *)arg0 + 0x38);
    *(f32 *)((s8 *)(&(*(RecoveredGlobal_80133A04_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 0x3C) = (f32) *(f32 *)((s8 *)arg0 + 0x3C);
    *(f32 *)((s8 *)(&(*(RecoveredGlobal_80133A04_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 0x40) = (f32) *(f32 *)((s8 *)arg0 + 0x40);
    *(f32 *)((s8 *)(&(*(RecoveredGlobal_80133A04_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 0xC) = (f32) *(f32 *)((s8 *)arg0 + 0xC);
    *(f32 *)((s8 *)(&(*(RecoveredGlobal_80133A04_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 0x10) = (f32) *(f32 *)((s8 *)arg0 + 0x10);
    *(f32 *)((s8 *)(&(*(RecoveredGlobal_80133A04_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 0x14) = (f32) *(f32 *)((s8 *)arg0 + 0x14);
    light = __nw__7TObjectFUl(0x1C);
    if (light != 0U) {
        TObjLight__sub_80133980((u8 *)light, (int)tl_02);
    }
    temp_r3_2 = __nw__7TObjectFUl(0x1C);
    if (temp_r3_2 != 0U) {
        ((TObjLight *)temp_r3_2)->init(tl_02);
    }
}

void init_map_lights(u8 *arg0) {
    typedef char sp8_offset[(offsetof(Stack_80133B10, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_80133B10, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_80133B10, sp10) == 0x8) ? 1 : -1];
    Stack_80133B10 stack;
    u32 light;
    u32 temp_r3_2;
    u32 temp_r3_3;
    stack.sp8 = *(f32 *)((s8 *)arg0 + 0);
    stack.spC = *(f32 *)((s8 *)arg0 + 4);
    stack.sp10 = *(f32 *)((s8 *)arg0 + 8);
    if ((*(const f32 *)&TObjLight__data_805DB088) != vector_length(&stack.sp8)) {
        normalize_vector(&stack.sp8);
    }
    *(f32 *)((s8 *)(&(*(RecoveredGlobal_80133B10_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 0) = stack.sp8;
    *(f32 *)((s8 *)(&(*(RecoveredGlobal_80133B10_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 4) = stack.spC;
    *(f32 *)((s8 *)(&(*(RecoveredGlobal_80133B10_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 8) = stack.sp10;
    *(f32 *)((s8 *)(&(*(RecoveredGlobal_80133B10_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 0x18) = (f32) *(f32 *)((s8 *)arg0 + 0x18);
    *(f32 *)((s8 *)(&(*(RecoveredGlobal_80133B10_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 0x1C) = (f32) *(f32 *)((s8 *)arg0 + 0x1C);
    *(f32 *)((s8 *)(&(*(RecoveredGlobal_80133B10_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 0x20) = (f32) *(f32 *)((s8 *)arg0 + 0x20);
    *(f32 *)((s8 *)(&(*(RecoveredGlobal_80133B10_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 0x28) = (f32) *(f32 *)((s8 *)arg0 + 0x28);
    *(f32 *)((s8 *)(&(*(RecoveredGlobal_80133B10_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 0x2C) = (f32) *(f32 *)((s8 *)arg0 + 0x2C);
    *(f32 *)((s8 *)(&(*(RecoveredGlobal_80133B10_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 0x30) = (f32) *(f32 *)((s8 *)arg0 + 0x30);
    *(f32 *)((s8 *)(&(*(RecoveredGlobal_80133B10_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 0x38) = (f32) *(f32 *)((s8 *)arg0 + 0x38);
    *(f32 *)((s8 *)(&(*(RecoveredGlobal_80133B10_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 0x3C) = (f32) *(f32 *)((s8 *)arg0 + 0x3C);
    *(f32 *)((s8 *)(&(*(RecoveredGlobal_80133B10_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 0x40) = (f32) *(f32 *)((s8 *)arg0 + 0x40);
    TObjLight::init_light_tables();
    light = __nw__7TObjectFUl(0x1C);
    if (light != 0U) {
        TObjLight__sub_80133980((u8 *)light, (int)tl_02);
    }
    temp_r3_2 = __nw__7TObjectFUl(0x1C);
    if (temp_r3_2 != 0U) {
        ((TObjLight *)temp_r3_2)->init(tl_02);
    }
    temp_r3_3 = __nw__7TObjectFUl(0x1C);
    if (temp_r3_3 != 0U) {
        ((TObjLight *)temp_r3_3)->init_map_light(tl_02);
    }
}

void TUnk_804A6FA8::run_task() {
    s32 i;
    s32 j;
    for (i = 0; i < 32; i++) {
        ((Light_80133C1C *)&TObjLight__data_8050637C)[i].f28 = 0xFFFF;
        ((Light_80133C1C *)&TObjLight__data_8050637C)[i].f0 = TObjLight__data_805DB088;
        ((Light_80133C1C *)&TObjLight__data_8050637C)[i].f4 = TObjLight__data_805DB088;
        ((Light_80133C1C *)&TObjLight__data_8050637C)[i].f8 = TObjLight__data_805DB088;
        ((Light_80133C1C *)&TObjLight__data_8050637C)[i].fC = TObjLight__data_805DB088;
        ((Light_80133C1C *)&TObjLight__data_8050637C)[i].f10 = TObjLight__data_805DB088;
        ((Light_80133C1C *)&TObjLight__data_8050637C)[i].f14 = TObjLight__data_805DB088;
        ((Light_80133C1C *)&TObjLight__data_8050637C)[i].f18 = TObjLight__data_805DB088;
        ((Light_80133C1C *)&TObjLight__data_8050637C)[i].f20 = TObjLight__data_805DB088;
        ((Light_80133C1C *)&TObjLight__data_8050637C)[i].f1C = TObjLight__data_805DB088;
        ((Light_80133C1C *)&TObjLight__data_8050637C)[i].f24 = 0;
    }
    for (j = 0; j < 8; j++) {
        ((Light_80133C1C *)TObjLight__data_805068FC)[j].f28 = 0xFFFF;
        ((Light_80133C1C *)TObjLight__data_805068FC)[j].f0 = TObjLight__data_805DB088;
        ((Light_80133C1C *)TObjLight__data_805068FC)[j].f4 = TObjLight__data_805DB088;
        ((Light_80133C1C *)TObjLight__data_805068FC)[j].f8 = TObjLight__data_805DB088;
        ((Light_80133C1C *)TObjLight__data_805068FC)[j].fC = TObjLight__data_805DB088;
        ((Light_80133C1C *)TObjLight__data_805068FC)[j].f10 = TObjLight__data_805DB088;
        ((Light_80133C1C *)TObjLight__data_805068FC)[j].f14 = TObjLight__data_805DB088;
        ((Light_80133C1C *)TObjLight__data_805068FC)[j].f18 = TObjLight__data_805DB088;
        ((Light_80133C1C *)TObjLight__data_805068FC)[j].f20 = TObjLight__data_805DB088;
        ((Light_80133C1C *)TObjLight__data_805068FC)[j].f1C = TObjLight__data_805DB088;
        ((Light_80133C1C *)TObjLight__data_805068FC)[j].f24 = 0;
    }
    TObjLight__light_count = 0;
    TObjLight__actor_light_count = 0;
}

void *TObjLight::dt(s16 arg1) {
    if (this != NULL) {
        *(s32 **)((s8 *)this + 0x18) = lbl_804A6FA8;
        __dt__7TObjectFv(this, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}

void *TObjLight::init(int _w1) {
    __ct__7TObjectFP7TObject(this);
    *(s32 **)((s8 *)this + 0x18) = lbl_804A6FA8;
    return this;
}

typedef char RecoveredGlobal_80133D78_lbl_804A6F34_size[sizeof(RecoveredGlobal_80133D78_lbl_804A6F34) == 0x44 ? 1 : -1];
void init_area_lights(void) {
    struct CopyStack_80133D78 { u8 bytes[0x44]; };
    CopyStack_80133D78 copy_storage_80133D78;
    s32 global_state;
    if ((u32) TObjLight__light_entry_data != 0U) {
        global_state = get_current_floor_area();
        if (TLobby::is_online_ready() != 0) {
            global_state = (s32) ((f32) global_state + lbl_805DB0A4);
        }
        *(ByteBlock_44 *)(copy_storage_80133D78.bytes) = *(const ByteBlock_44 *)(((TObjLight__light_entry_data + (global_state * 0x44)) - 4) + 4);
        ((TObjLight *)(copy_storage_80133D78.bytes))->bswap_data();
        init_map_lights((u8 *)((void *) ((copy_storage_80133D78.bytes))));
        return;
    }
    init_map_lights((u8 *)&default_scene_light_config.value);
}

void TObjLight::free_shared_data() {
    if ((u32) TObjLight__light_entry_data != 0U) {
        TAdSinglePlyChrSelectGC::safe_free((u32)((void*)TObjLight__light_entry_data));
        TObjLight__light_entry_data = 0U;
    }
}

extern s32 lbl_804A6FC0[];

void load_light_entry_file(void) {
    TObjLight__light_entry_data = 0;
    light_entry_file_size = ((TScene *)lbl_8043ED80)->update_lobby_scene();
    if (light_entry_file_size > 0) {
        TObjLight__light_entry_data = ((TQuestVmDownLoadServer *)light_entry_file_size)->alloc();
        if (TObjLight__light_entry_data) {
            read_disc_file(lbl_8043ED80, TObjLight__light_entry_data);
        }
    }
}
extern "C" {

void *TObjLight::dt2(s16 arg1) {
    if (this != NULL) {
        *(s32 **)((s8 *)this + 0x18) = lbl_804A6FC0;
        __dt__7TObjectFv(this, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}

void *TObjLight::init_object() {
    __ct__7TObjectFP7TObject(this);
    *(s32 **)((s8 *)this + 0x18) = lbl_804A6FC0;
    return this;
}

typedef char RecoveredGlobal_80133F6C_TObjLight__data_80506320_size[sizeof(RecoveredGlobal_80133F6C_TObjLight__data_80506320) == 0x50 ? 1 : -1];
typedef char RecoveredGlobal_80133F6C_TObjLight__data_8058D528_size[sizeof(RecoveredGlobal_80133F6C_TObjLight__data_8058D528) == 0x140 ? 1 : -1];
void TObjLight::apply_distant_light() {
    set_light_ambient_color(*(f32 *)((s8 *)(&(*(RecoveredGlobal_80133F6C_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 0x20), *(f32 *)((s8 *)(&(*(RecoveredGlobal_80133F6C_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 0x20), *(f32 *)((s8 *)(&(*(RecoveredGlobal_80133F6C_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 0x20));
    init_distant_light(0, *(f32 *)((s8 *)(&(*(RecoveredGlobal_80133F6C_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 0xC), *(f32 *)((s8 *)(&(*(RecoveredGlobal_80133F6C_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 0x10), *(f32 *)((s8 *)(&(*(RecoveredGlobal_80133F6C_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 0x14));
    GXInitLightDir((s32 *)(&(*(RecoveredGlobal_80133F6C_TObjLight__data_8058D528 *)&TObjLight__gx_light_objects).value), *(f32 *)((s8 *)(&(*(RecoveredGlobal_80133F6C_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 0xC), *(f32 *)((s8 *)(&(*(RecoveredGlobal_80133F6C_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 0x10), *(f32 *)((s8 *)(&(*(RecoveredGlobal_80133F6C_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 0x14));
    set_gx_light_color(0, *(f32 *)((s8 *)(&(*(RecoveredGlobal_80133F6C_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 0x28), *(f32 *)((s8 *)(&(*(RecoveredGlobal_80133F6C_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 0x2C), *(f32 *)((s8 *)(&(*(RecoveredGlobal_80133F6C_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 0x30));
    load_gx_light_slot(0);
}

void TObjLight::set_light(void *arg1, f32 farg0) {
    init_distant_light(0, *(f32 *)&this->m_name, *(f32 *)&this->m_flags, *(f32 *)&this->m_prev);
    GXInitLightDir(TObjLight__gx_light_objects, *(f32 *)&this->m_name, *(f32 *)&this->m_flags, *(f32 *)&this->m_prev);
    set_gx_light_color(0, *(f32 *)((s8 *)arg1 + 4), *(f32 *)((s8 *)arg1 + 8), *(f32 *)((s8 *)arg1 + 0xC));
    set_light_ambient_color(farg0, farg0, farg0);
    load_gx_light_slot(0);
}

typedef char RecoveredGlobal_80134098_TObjLight__data_80506320_size[sizeof(RecoveredGlobal_80134098_TObjLight__data_80506320) == 0x50 ? 1 : -1];
typedef char RecoveredGlobal_80134098_TObjLight__data_8058D528_size[sizeof(RecoveredGlobal_80134098_TObjLight__data_8058D528) == 0x140 ? 1 : -1];
void restore_scene_lighting(void) {
    if (get_current_floor_area() == AREA_LOBBY) {
        init_distant_light(0, *(f32 *)((s8 *)(&(*(RecoveredGlobal_80134098_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 0xC), *(f32 *)((s8 *)(&(*(RecoveredGlobal_80134098_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 0x10), *(f32 *)((s8 *)(&(*(RecoveredGlobal_80134098_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 0x14));
        GXInitLightDir((s32 *)(&(*(RecoveredGlobal_80134098_TObjLight__data_8058D528 *)&TObjLight__gx_light_objects).value), *(f32 *)((s8 *)(&(*(RecoveredGlobal_80134098_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 0xC), *(f32 *)((s8 *)(&(*(RecoveredGlobal_80134098_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 0x10), *(f32 *)((s8 *)(&(*(RecoveredGlobal_80134098_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 0x14));
        set_gx_light_color(0, *(f32 *)((s8 *)(&(*(RecoveredGlobal_80134098_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 0x28), *(f32 *)((s8 *)(&(*(RecoveredGlobal_80134098_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 0x2C), *(f32 *)((s8 *)(&(*(RecoveredGlobal_80134098_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 0x30));
        load_gx_light_slot(0);
    } else {
        init_distant_light(0, *(f32 *)((s8 *)(&(*(RecoveredGlobal_80134098_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 0xC), *(f32 *)((s8 *)(&(*(RecoveredGlobal_80134098_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 0x10), *(f32 *)((s8 *)(&(*(RecoveredGlobal_80134098_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 0x14));
        GXInitLightDir((s32 *)(&(*(RecoveredGlobal_80134098_TObjLight__data_8058D528 *)&TObjLight__gx_light_objects).value), *(f32 *)((s8 *)(&(*(RecoveredGlobal_80134098_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 0xC), *(f32 *)((s8 *)(&(*(RecoveredGlobal_80134098_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 0x10), *(f32 *)((s8 *)(&(*(RecoveredGlobal_80134098_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 0x14));
        set_gx_light_color(0, *(f32 *)((s8 *)(&(*(RecoveredGlobal_80134098_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 0x28), *(f32 *)((s8 *)(&(*(RecoveredGlobal_80134098_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 0x2C), *(f32 *)((s8 *)(&(*(RecoveredGlobal_80134098_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 0x30));
        load_gx_light_slot(0);
    }
    set_light_ambient_color(*(f32 *)((s8 *)(&(*(RecoveredGlobal_80134098_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 0x20), *(f32 *)((s8 *)(&(*(RecoveredGlobal_80134098_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 0x20), *(f32 *)((s8 *)(&(*(RecoveredGlobal_80134098_TObjLight__data_80506320 *)&TObjLight__scene_light_state).value) + 0x20));
}

typedef char RecoveredGlobal_80134724_TObjLight__data_8050637C_size[sizeof(RecoveredGlobal_80134724_TObjLight__data_8050637C) == 0x580 ? 1 : -1];

struct LightData_80134194 {
    u8 pad0[0xC];
    f32 dir[3];
    u8 pad18[0x8];
    f32 amb;
    u8 pad24[0x4];
    f32 color[3];
    u8 pad34[0x28];
};
u16 get_entity_id(s32);
#define LD_80134194 ((LightData_80134194 *)&TObjLight__scene_light_state)
#define L1_80134194 TObjLight__data_8050637C
#define L2_80134194 TObjLight__data_805068FC
void select_actor_lighting(s32 obj) {
    s32 i;

    for (i = 0; i < TObjLight__light_count; i++) {
        if (L2_80134194[i].id == get_entity_id(obj)) {
            if (((u32)L2_80134194[i].f24 & 1) && ((u32)L2_80134194[i].f24 & 2)) {
                set_light_ambient_color(L2_80134194[i].f20, L2_80134194[i].f20, L2_80134194[i].f20);
                init_distant_light(0, L2_80134194[i].dir[0], L2_80134194[i].dir[1], L2_80134194[i].dir[2]);
                GXInitLightDir(TObjLight__gx_light_objects, L2_80134194[i].dir[0], L2_80134194[i].dir[1], L2_80134194[i].dir[2]);
                set_gx_light_color(0, L2_80134194[i].color[1], L2_80134194[i].color[2], L2_80134194[i].color[3]);
                load_gx_light_slot(0);
                return;
            }
            if ((u32)L2_80134194[i].f24 & 1) {
                set_light_ambient_color(LD_80134194->amb, LD_80134194->amb, LD_80134194->amb);
                load_gx_light_slot(0);
                return;
            }
            if (get_current_floor_area() == AREA_LOBBY) {
                init_distant_light(0, L2_80134194[i].dir[0], L2_80134194[i].dir[1], L2_80134194[i].dir[2]);
                GXInitLightDir(TObjLight__gx_light_objects, L2_80134194[i].dir[0], L2_80134194[i].dir[1], L2_80134194[i].dir[2]);
                set_gx_light_color(0, L2_80134194[i].color[1], L2_80134194[i].color[2], L2_80134194[i].color[3]);
                load_gx_light_slot(0);
                return;
            }
            init_distant_light(0, L2_80134194[i].dir[0], L2_80134194[i].dir[1], L2_80134194[i].dir[2]);
            GXInitLightDir(TObjLight__gx_light_objects, L2_80134194[i].dir[0], L2_80134194[i].dir[1], L2_80134194[i].dir[2]);
            set_gx_light_color(0, L2_80134194[i].color[1], L2_80134194[i].color[2], L2_80134194[i].color[3]);
            return;
        }
    }
    for (i = 0; i < TObjLight__actor_light_count; i++) {
        if (L1_80134194[i].id == get_entity_id(obj)) {
            init_distant_light(0, L1_80134194[i].dir[0], L1_80134194[i].dir[1], L1_80134194[i].dir[2]);
            GXInitLightDir(TObjLight__gx_light_objects, L1_80134194[i].dir[0], L1_80134194[i].dir[1], L1_80134194[i].dir[2]);
            set_light_ambient_color(LD_80134194->amb, LD_80134194->amb, LD_80134194->amb);
            set_gx_light_color(0, L1_80134194[i].color[1], L1_80134194[i].color[2], L1_80134194[i].color[3]);
            load_gx_light_slot(0);
            return;
        }
    }
    set_light_ambient_color(LD_80134194->amb, LD_80134194->amb, LD_80134194->amb);
    init_distant_light(0, LD_80134194->dir[0], LD_80134194->dir[1], LD_80134194->dir[2]);
    GXInitLightDir(TObjLight__gx_light_objects, LD_80134194->dir[0], LD_80134194->dir[1], LD_80134194->dir[2]);
    set_gx_light_color(0, LD_80134194->color[0], LD_80134194->color[1], LD_80134194->color[2]);
    load_gx_light_slot(0);
}

void TObjLight::find_light_params(f32 *dir, f32 *color, u32 id) {
    s32 i;
    for (i = 0; i < TObjLight__actor_light_count; i++) {
        LightEntry_801344A4 *e = &((LightEntry_801344A4 *)&TObjLight__data_8050637C)[i];
        if (id == e->id) {
            VecCopy((Vec *)dir, (const Vec *)e->dir);
            copy_argb((NJS_ARGB *)color, (NJS_ARGB *)e->color);
            return;
        }
    }
    copy_argb((NJS_ARGB *)color, (NJS_ARGB *)((*(LightDefault_801344A4 *)&TObjLight__scene_light_state).color));
    VecCopy((Vec *)dir, (const Vec *)((*(LightDefault_801344A4 *)&TObjLight__scene_light_state).dir));
}

void publish_actor_light_scalars(u32 arg0, f32 farg0, f32 farg1) {
    s32 cnt = TObjLight__light_count;
    s32 found;
    s32 n;
    Light_801347A4 *q;
    found = 1;
    if (cnt < 8) {
        for (n = 0; n < 8; n++) {
            if (arg0 == TObjLight__data_805068FC[n].id) {
                found = 0;
                TObjLight__data_805068FC[n].id = arg0;
                TObjLight__data_805068FC[n].f1C = farg0;
                TObjLight__data_805068FC[n].f20 = farg1;
                TObjLight__data_805068FC[n].f24 |= 1;
                break;
            }
            if (TObjLight__data_805068FC[n].id == 0xFFFF) {
                break;
            }
        }
        if (found != 0) {
            q = &TObjLight__data_805068FC[cnt];
            q->id = arg0;
            q->f1C = farg0;
            q->f20 = farg1;
            q->f24 |= 1;
            TObjLight__light_count++;
        }
    }
}

void publish_light_direction_color(u32 id, void *dir, void *color) {
    s32 add;
    s32 i;
    Light_801347A4 *e;
    add = 1;
    if (TObjLight__light_count < 8) {
        for (i = 0; i < 8; i++) {
            e = &TObjLight__data_805068FC[i];
            if (id == e->id) {
                TObjLight__data_805068FC[i].id = id;
                VecCopy((Vec *)e, (const Vec *)dir);
                copy_argb((NJS_ARGB *)e->color, (NJS_ARGB *)color);
                add = 0;
                TObjLight__data_805068FC[i].f24 |= 2;
                break;
            }
            if (e->id == 0xFFFF) {
                break;
            }
        }
        if (add) {
            TObjLight__data_805068FC[TObjLight__light_count].id = id;
            VecCopy((Vec *)&TObjLight__data_805068FC[TObjLight__light_count], (const Vec *)dir);
            copy_argb((NJS_ARGB *)TObjLight__data_805068FC[TObjLight__light_count].color, (NJS_ARGB *)color);
            TObjLight__data_805068FC[TObjLight__light_count].f24 |= 2;
            TObjLight__light_count++;
        }
    }
}

void register_actor_light(s32 arg0, s32 arg1) {
    u8 *temp_r5;
    if ((s32) TObjLight__actor_light_count < 0x20) {
        temp_r5 = (u8 *)TObjLight__data_8050637C + (TObjLight__actor_light_count * 0x2C);
        *(s32 *)((s8 *)temp_r5 + 0x28) = arg0;
        VecCopy((Vec *)(temp_r5), (const Vec *)(arg1 + 0xE4));
        copy_argb((NJS_ARGB *)((u8 *)TObjLight__data_8050637C + (TObjLight__actor_light_count * 0x2C) + 0xC), (NJS_ARGB *)(arg1 + 0xF0));
        TObjLight__actor_light_count += 1;
    }
}

void TObjLight::init_light_tables() {
    s32 i;
    s32 j;
    for (i = 0; i < 0x20; i++) {
        ((Light_801347A4 *)&TObjLight__data_8050637C)[i].id = 0xFFFF;
        ((Light_801347A4 *)&TObjLight__data_8050637C)[i].dir[0] = TObjLight__data_805DB088;
        ((Light_801347A4 *)&TObjLight__data_8050637C)[i].dir[1] = TObjLight__data_805DB088;
        ((Light_801347A4 *)&TObjLight__data_8050637C)[i].dir[2] = TObjLight__data_805DB088;
        ((Light_801347A4 *)&TObjLight__data_8050637C)[i].color[0] = TObjLight__data_805DB088;
        ((Light_801347A4 *)&TObjLight__data_8050637C)[i].color[1] = TObjLight__data_805DB088;
        ((Light_801347A4 *)&TObjLight__data_8050637C)[i].color[2] = TObjLight__data_805DB088;
        ((Light_801347A4 *)&TObjLight__data_8050637C)[i].color[3] = TObjLight__data_805DB088;
        ((Light_801347A4 *)&TObjLight__data_8050637C)[i].f20 = TObjLight__data_805DB088;
        ((Light_801347A4 *)&TObjLight__data_8050637C)[i].f1C = TObjLight__data_805DB088;
        ((Light_801347A4 *)&TObjLight__data_8050637C)[i].f24 = 0;
    }
    TObjLight__actor_light_count = 0;
    for (j = 0; j < 8; j++) {
        TObjLight__data_805068FC[j].id = 0xFFFF;
        TObjLight__data_805068FC[j].dir[0] = TObjLight__data_805DB088;
        TObjLight__data_805068FC[j].dir[1] = TObjLight__data_805DB088;
        TObjLight__data_805068FC[j].dir[2] = TObjLight__data_805DB088;
        TObjLight__data_805068FC[j].color[0] = TObjLight__data_805DB088;
        TObjLight__data_805068FC[j].color[1] = TObjLight__data_805DB088;
        TObjLight__data_805068FC[j].color[2] = TObjLight__data_805DB088;
        TObjLight__data_805068FC[j].color[3] = TObjLight__data_805DB088;
        TObjLight__data_805068FC[j].f20 = TObjLight__data_805DB088;
        TObjLight__data_805068FC[j].f1C = TObjLight__data_805DB088;
        TObjLight__data_805068FC[j].f24 = 0;
    }
    TObjLight__light_count = 0;
}

void *__dt__13TUnk_804A6F78Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804A6F78;
        ((TObjLight *)arg0)->dt2((s16)(0));
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

void *__dt__13TUnk_804A6F90Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804A6F90;
        ((TObjLight *)arg0)->dt2((s16)(0));
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

void TObjLight::bswap_data() { bswap_32((u32 *)this); bswap_32((u32 *)((char*)this + 0x4)); bswap_32((u32 *)((char*)this + 0x8)); bswap_32((u32 *)((char*)this + 0xc)); bswap_32((u32 *)((char*)this + 0x10)); bswap_32((u32 *)((char*)this + 0x14)); bswap_32((u32 *)((char*)this + 0x18)); bswap_32((u32 *)((char*)this + 0x1c)); bswap_32((u32 *)((char*)this + 0x20)); bswap_32((u32 *)((char*)this + 0x24)); bswap_32((u32 *)((char*)this + 0x28)); bswap_32((u32 *)((char*)this + 0x2c)); bswap_32((u32 *)((char*)this + 0x30)); bswap_32((u32 *)((char*)this + 0x34)); bswap_32((u32 *)((char*)this + 0x38)); bswap_32((u32 *)((char*)this + 0x3c)); bswap_32((u32 *)((char*)this + 0x40)); }

extern s32 lbl_804A7008[];

void *__dt__13TUnk_804A7008Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804A7008;
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

int TLobby__sub_80134A20(void* p) { return (int)TQuestThread::create_in_root((s32)p); }

__declspec(section ".sdata2") extern const float TObjLight__data_805DB088 = 0.0f;
__declspec(section ".sdata2") extern const float lbl_805DB08C = 5.0f;
__declspec(section ".sdata2") extern const float lbl_805DB090 = 30.0f;
__declspec(section ".sdata2") extern const float lbl_805DB094 = 1.0f;
__declspec(section ".sdata2") extern const f32 lbl_805DB098 = 180.0f;
__declspec(section ".sdata2") extern const f32 lbl_805DB09C = 100000000.0f;
__declspec(section ".sdata2") extern const f32 lbl_805DB0A0 = 0.89999997615814209f;
__declspec(section ".sdata2") extern const f32 lbl_805DB0A4 = 48.0f;
}
