#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/frontend/TAdEndText.h"
#include "pso/item/TItemReverseTechBG.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItemReverseTechPart2_801198F8.h"
#include "pso/item/TItemReverseTechPart2.h"
#include "pso/item/TItemReverseTech_8011A1E8.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/render/render_util.h"
#include "pso/item/TItemReverseTechPart1.h"
#include "pso/ui/frontend/TAdRicoRingCtrl_8001B4A0.h"
#include "pso/ui/frontend/TAdRicoRingCtrl.h"
#include "pso/unk/TLobby.h"
#include "pso/item/TItemReverseTech.h"
#include "pso/camera/TCameraCtrl_800687BC.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/system/TLoadCtrl_80227390.h"
#include <stddef.h>
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/memory.h"
#include "pso/system/main_loop.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/task/TObject.h"

struct TItemReverseTechBG_80119658 {
    u8 pad0[0x1C];
    s32 m1C;
    s32 m20;
    u32 alpha;
    s32 step;
    u8 pad2C[0x34 - 0x2C];
    u32 color;
    u8 pad38[0x5C - 0x38];
    s32 timer;
    s32 state;
};

extern "C" {
void __ct__7TObjectFP7TObject(void *, void *);
void *__nw__7TObjectFUl(int);

extern void *__vt__18TItemReverseTechBG[];

}

struct RecoveredGlobal_80119B28___vt__21TItemReverseTechPart2 { s32 value; u8 remaining[0x14]; };
typedef char RecoveredGlobal_80119B28___vt__21TItemReverseTechPart2_size[sizeof(RecoveredGlobal_80119B28___vt__21TItemReverseTechPart2) == 0x18 ? 1 : -1];

extern "C" {

extern RecoveredGlobal_80119B28___vt__21TItemReverseTechPart2 __vt__21TItemReverseTechPart2;

extern void *TItemReverseTechPart1__instance;

}

static const f32 lbl_805DAC08[1] = {0.0f};
static const f32 lbl_805DAC0C[1] = {480.0f};

extern "C" {

struct Self_80119DA0 {
    u8 pad0[0x1C];
    s32 state;
    s32 timer;
    s32 t1;
    s32 t2;
    s32 t3;
    void *ring;
};

void TAdRicoRingCtrl__sub_8001B4A0(void *, f32);
void *__nw__7TObjectFUl(int);

extern s32 __vt__21TItemReverseTechPart1[];
extern s32 destroy_and_flag__21TItemReverseTechPart2Fv[];

}

extern "C" {
extern void *TItemReverseTech__texture_archive;

}

extern "C" {

extern s32 __vt__16TItemReverseTech[];
const char *TItemReverseTech__name = "TItemReverseTech";
extern s32 lbl_8043E708[];

}

struct RecoveredGlobal_8011A350_main_task {
    s32 value;
    u8 remaining[0x30];
};

struct RecoveredGlobal_8011A3D8_lbl_804A03A8
{
  s32 value;
  u8 remaining[0x34];
};

struct RecoveredGlobal_8011A3D8_main_task
{
  s32 value;
  u8 remaining[0x30];
};

struct Ent_8011A270 { int name; int a; int b; };

struct Hdr_8011A270 { int entries; int x4; };

struct Name_8011A270 { char s[0x1C]; };

struct Vec_8011A43C { f32 x, y, z; };

struct Ent_8011A43C { void (*fn)(); s32 arg; };

extern "C" {
s32 TKeyBoardControl__sub_8000F92C();
void TKeyBoardControl__sub_8000F9CC(s32 arg0);
s8 func_801A5E54__Fv();
extern RecoveredGlobal_8011A3D8_lbl_804A03A8 TItemReverseTech__cleanup_callback_table;
s32 prs_decompress_alloc(int, int, int);
int set_stream_and_load_file__6TLobbyFi(char *);
void mem_free(void *p);
void *mem_alloc(u32 size);
char *strncpy(char *, const char *, u32);
void load_gvm_texture_archive(int, void *);
extern Name_8011A270 lbl_8043E714;
extern int TItemReverseTech__entry_table;
extern int TItemReverseTech__name_buffer;
void TKeyBoardControl__sub_8000F90C(s32);
void TKeyBoardControl__sub_8000F91C(s32);
void set_active_camera_pose(u8 *arg0, u8 *arg1);
u8 *TCameraCtrl__ct(u8 *arg0, void *parent);
void reset_controller_input_state();
void set_copy_clear_color_argb(s32, s32, s32);
}
void process_async_file_reads(void);
void update_sound_request_slots(void);
void clear_resource_load_tasks();
void init_map_lights(u8 *arg0);
void set_screen_size(f32, f32);
extern u8 default_scene_light_config[];
extern "C" {
void TItemReverseTech__sub_8011A54C(void* a0);
int TItemReverseTech__sub_8011A55C(void);
int TItemReverseTech__sub_8011A580(void);
void TItemReverseTech__sub_8011A5A4(void);
void free__16TItemReverseTechFv(void);
s32 free_texture_if_valid(u32 arg0);
int set_global_flags__6TLobbyFl(void*);
}

#pragma defer_codegen on

extern "C" {
void TItemReverseTech__sub_8011A5A4(void) {  }
int TItemReverseTech__sub_8011A580(void) { return set_global_flags__6TLobbyFl((void*)(1)); }
int TItemReverseTech__sub_8011A55C(void) { return set_global_flags__6TLobbyFl((void*)(2)); }

void TItemReverseTech__sub_8011A54C(void* a0) { *(float*)((char*)a0 + 0x20) = 1.0f; *(float*)((char*)a0 + 0x24) = 1.0f; }

void TItemReverseTech::init_scene() {
    Ent_8011A43C *e;
    u32 i;
    void (*fn)();
    void *cam;
    set_screen_size(1.0f, 0.85f);
    set_copy_clear_color_argb(0, 0, 0);
    reset_controller_input_state();
    clear_resource_load_tasks();
    e = ((Ent_8011A43C *)&TItemReverseTech__cleanup_callback_table);
    for (i = 0; i != 7; i++) {
        fn = e->fn;
        e++;
        if (fn != NULL) {
            fn();
        }
    }
    init_map_lights(default_scene_light_config);
    cam = __nw__7TObjectFUl(0x1D4);
    if (cam != NULL) {
        TCameraCtrl__ct((u8 *)cam, (void *)tl_camera);
    }
    Vec_8011A43C eye = {0.0f, 0.0f, 0.0f};
    Vec_8011A43C at = {0.0f, 0.0f, -100.0f};
    TCameraCtrl::select_active_controller(9);
    set_active_camera_pose((u8 *)&eye, (u8 *)&at);
    TKeyBoardControl__sub_8000F90C(2);
    TKeyBoardControl__sub_8000F91C(2);
    TParticleCtrl::create_quad_sprites();
    TItemReverseTech::create();
    render_tick();
}

typedef struct RecoveredGlobal_8011A3D8_lbl_804A03A8 RecoveredGlobal_8011A3D8_lbl_804A03A8;
typedef struct RecoveredGlobal_8011A3D8_main_task RecoveredGlobal_8011A3D8_main_task;
typedef char RecoveredGlobal_8011A3D8_lbl_804A03A8_size[((sizeof(RecoveredGlobal_8011A3D8_lbl_804A03A8)) == 0x38) ? (1) : (-1)];
typedef char RecoveredGlobal_8011A3D8_main_task_size[((sizeof(RecoveredGlobal_8011A3D8_main_task)) == 0x34) ? (1) : (-1)];
void TItemReverseTech::run_cleanup_callbacks() {
  s32 (*temp_r12)();
  u8 *var_r31;
  s32 var_r30;
  main_task.delete_layer_children();
  var_r30 = 6;
  var_r31 = ((u8 *)&TItemReverseTech__cleanup_callback_table.value) + 0x30;
  do
  {
    temp_r12 = *((s32 (**)()) (((s8 *) var_r31) + 4));
    var_r31 -= 8;
    if (temp_r12 != 0)
    {
      temp_r12();
    }
    var_r30 -= 1;
  }
  while (var_r30 >= 0);
  render_tick();
}

void TItemReverseTech::run_frame() {
    s32 *var_r3;
    controller_stuff();
    TKeyBoardControl::update_input_frame();
    var_r3 = (s32 *)(&(*(RecoveredGlobal_8011A350_main_task *)&main_task).value);
    var_r3 = (s32 *)(&(*(RecoveredGlobal_8011A350_main_task *)&main_task).value);
    main_task.begin_frame();
    var_r3 = (s32 *)(&(*(RecoveredGlobal_8011A350_main_task *)&main_task).value);
    var_r3 = (s32 *)(&(*(RecoveredGlobal_8011A350_main_task *)&main_task).value);
    main_task.run_task();
    var_r3 = (s32 *)(&(*(RecoveredGlobal_8011A350_main_task *)&main_task).value);
    var_r3 = (s32 *)(&(*(RecoveredGlobal_8011A350_main_task *)&main_task).value);
    main_task.render();
    var_r3 = (s32 *)(&(*(RecoveredGlobal_8011A350_main_task *)&main_task).value);
    var_r3 = (s32 *)(&(*(RecoveredGlobal_8011A350_main_task *)&main_task).value);
    main_task.render_screen_overlay();
    process_async_file_reads();
    update_sound_request_slots();
    TAdSinglePlyChrSelectGC::noop();
    if (func_801A5E54__Fv() != 0) {
        TKeyBoardControl__sub_8000F92C();
    }
    if (TQuestVmDownLoadServer::is_ready() != 0) {
        var_r3 = NULL;
        TKeyBoardControl__sub_8000F9CC(0);
    }
    render_tick();
}

typedef char RecoveredGlobal_8011A350_main_task_size[sizeof(RecoveredGlobal_8011A350_main_task) == 0x34 ? 1 : -1];

#pragma push
#pragma opt_propagation off
void TItemReverseTech::load_textures() {
    Name_8011A270 *name = &lbl_8043E714;
    Ent_8011A270 *e;
    s32 i;
    Hdr_8011A270 *hdr;
    int file;
    int buf;
    TItemReverseTech__name_buffer = (int)mem_alloc(0x1C);
    strncpy((char *)TItemReverseTech__name_buffer, name->s, 0x1B);
    e = (Ent_8011A270 *)mem_alloc(0xCC);
    TItemReverseTech__entry_table = (int)e;
    for (i = 0; i < 17; i++, e++) {
        e->name = TItemReverseTech__name_buffer;
        e->a = 0;
        e->b = 0;
    }
    hdr = (Hdr_8011A270 *)::operator new(8);
    TItemReverseTech__texture_archive = hdr;
    hdr->entries = TItemReverseTech__entry_table;
    file = set_stream_and_load_file__6TLobbyFi(name->s);
    if (file != 0) {
        buf = (int)mem_alloc(0x200000);
        if (buf != 0 && prs_decompress_alloc(file, buf, 0x200000) > 0) {
            load_gvm_texture_archive(buf, TItemReverseTech__texture_archive);
        }
        mem_free((void *)buf);
    }
    TAdSinglePlyChrSelectGC::safe_free(file);
}
#pragma pop

void free__16TItemReverseTechFv(void) { free_texture_if_valid((u32)TItemReverseTech__texture_archive); mem_free((void *)TItemReverseTech__name_buffer); TItemReverseTech__name_buffer = 0; mem_free((void *)TItemReverseTech__entry_table); TItemReverseTech__entry_table = 0; ::operator delete((void *)TItemReverseTech__texture_archive); TItemReverseTech__texture_archive = 0; }

void TItemReverseTech::create() {
    void *obj = __nw__7TObjectFUl(0x28);
    if (obj != 0) {
        TItemReverseTech__ct(obj, tl_01);
    }
}

}

extern "C" {

void *TItemReverseTech__ct(void *item_reverse_tech, void *parent) {
    void *o;
    void *o2;
    __ct__7TObjectFP7TObject(item_reverse_tech, parent);
    *(s32 **)((s8 *)item_reverse_tech + 0x18) = __vt__16TItemReverseTech;
    ((TItemReverseTech *)item_reverse_tech)->m_name = TItemReverseTech__name;
    o = __nw__7TObjectFUl(0x34);
    if (o != NULL) {
        o = TItemReverseTechPart1__ct(o, item_reverse_tech, TItemReverseTech__texture_archive);
    }
    *(void * *)&((TItemReverseTech *)item_reverse_tech)->part_one = o;
    *(u32 *)((s8 *)item_reverse_tech + 0x24) = 0;
    o2 = __nw__7TObjectFUl(0x197C);
    if (o2 != NULL) {
        __ct__10TAdEndTextFv((u8 *)o2, (TObject *)item_reverse_tech);
    }
    play_area_music((char *)lbl_8043E708);
    return item_reverse_tech;
}

}

TItemReverseTech::~TItemReverseTech() {
    TLobby::stop_audio_streams();
    request_queued_main_phase();
}

#pragma opt_common_subs off

void TItemReverseTech::run_task() {
    Vec_8011A43C eye = {0.0f, 0.0f, 0.0f};
    Vec_8011A43C at = {0.0f, 0.0f, -100.0f};

    u32 temp_r3;
    u32 object;
    u32 temp_r3_3;
    u32 var_r0;

    activate_camera_mode(9);
    set_active_camera_pose((u8 *)&eye, (u8 *)&at);
    temp_r3 = (u32)part_one;
    if ((temp_r3 != 0U) && (((TObject *)temp_r3)->all_parents_unqueued_for_destruction() == 0)) {
        part_one = NULL;
        object = (u32)__nw__7TObjectFUl(0x158);
        var_r0 = object;
        if (var_r0 != 0U) {
            var_r0 = (u32)__ct__21TItemReverseTechPart2Fv((u8 *)object, (s32)this, (s32)TItemReverseTech__texture_archive);
        }
        part_two = (TObject *)var_r0;
    }
    temp_r3_3 = (u32)part_two;
    if ((temp_r3_3 != 0U) && (((TObject *)temp_r3_3)->all_parents_unqueued_for_destruction() == 0)) {
        part_two = NULL;
        queue_destruction();
    }
}
#pragma opt_common_subs reset

const char *TItemReverseTechPart1__name = "TItemReverseTechPart1";

extern "C" {

void *TItemReverseTechPart1__ct(void *item_reverse_tech_part1, void *parent, void *texture_archive) {
    void *o;
    __ct__7TObjectFP7TObject(item_reverse_tech_part1, parent);
    *(s32 **)((s8 *)item_reverse_tech_part1 + 0x18) = __vt__21TItemReverseTechPart1;
    ((TItemReverseTechPart1 *)item_reverse_tech_part1)->m_name = TItemReverseTechPart1__name;
    *(u32 *)((s8 *)item_reverse_tech_part1 + 0x1C) = 0;
    *(u32 *)((s8 *)item_reverse_tech_part1 + 0x20) = 0;
    *(u32 *)((s8 *)item_reverse_tech_part1 + 0x24) = 150;
    *(u32 *)((s8 *)item_reverse_tech_part1 + 0x28) = 3900;
    *(u32 *)((s8 *)item_reverse_tech_part1 + 0x2C) = 150;
    *(u32 *)((s8 *)item_reverse_tech_part1 + 0x30) = 0;
    TItemReverseTechPart1__instance = item_reverse_tech_part1;
    o = __nw__7TObjectFUl(0x28);
    if (o != NULL) {
        ((TLobby *)o)->init_fade(tl_00, destroy_and_flag__21TItemReverseTechPart2Fv);
    }
    return item_reverse_tech_part1;
}

}

TItemReverseTechPart1::~TItemReverseTechPart1() {}

extern "C" {

void TItemReverseTechPart1::run_task() {
    Self_80119DA0 *self = (Self_80119DA0 *)this;
    void *p;

    switch (self->state) {
    case 0:
        break;
    case 1:
        if (self->ring == NULL) {
            p = __nw__7TObjectFUl(0x2C);
            if (p != NULL) {
                p = TAdRicoRingCtrl__ct((TAdRicoRingCtrl *)((u8 *)p), (s32)self);
            }
            self->ring = p;
            if (self->ring != NULL) {
                ((TAdRicoRingCtrl *)(self->ring))->start_fade_all(self->t1);
            }
        }
        if (self->timer == self->t1) {
            self->state = 2;
            self->timer = 0;
        } else {
            self->timer++;
        }
        break;
    case 2:
        if (self->timer == self->t2) {
            self->state = 3;
            self->timer = 0;
            if (self->ring != NULL) {
                TAdRicoRingCtrl__sub_8001B4A0(self->ring, self->t1);
                self->ring = NULL;
            }
        } else {
            self->timer++;
        }
        break;
    case 3:
        if (self->timer == self->t3) {
            self->state = 4;
            self->timer = 0;
        } else {
            self->timer++;
        }
        break;
    case 4:
        ((TObject *)self)->queue_destruction();
        break;
    }
}

}

void TItemReverseTechPart2::destroy_and_flag() {
    queue_destruction();
    if ((void *) TItemReverseTechPart1__instance != NULL) {
        *(s32 *)((s8 *)TItemReverseTechPart1__instance + 0x1C) = 1;
    }
}

const char *TItemReverseTechPart2__name = "TItemReverseTechPart2";

extern "C" {
u8 *__ct__21TItemReverseTechPart2Fv(u8 *object, s32 arg1, s32 arg2) {
    void *temp_r3;
    __ct__7TObjectFP7TObject((void *)object, (void *)arg1);
    *(s32 **)((s8 *)object + 0x18) = &__vt__21TItemReverseTechPart2.value;
    TItemReverseTech__sub_8011A54C((object + 0x1C));
    TItemReverseTech__sub_8011A54C((object + 0x48));
    TItemReverseTech__sub_8011A54C((object + 0x74));
    TItemReverseTech__sub_8011A54C((object + 0xA0));
    TItemReverseTech__sub_8011A54C((object + 0xCC));
    TItemReverseTech__sub_8011A54C((object + 0xF8));
    TItemReverseTech__sub_8011A54C((object + 0x124));
    *(s32 *)((s8 *)object + 0) = (s32) TItemReverseTechPart2__name;
    *(s32 *)((s8 *)object + 0x1C) = 0x12C;
    *(s32 *)((s8 *)object + 0x20) = 0;
    *(s32 *)((s8 *)object + 0x24) = arg2;
    *(s32 *)((s8 *)object + 0x28) = 0;
    *(f32 *)((s8 *)object + 0x2C) = 128.0f;
    *(f32 *)((s8 *)object + 0x30) = (f32) lbl_805DAC08[0];
    *(f32 *)((s8 *)object + 0x34) = 512.0f;
    *(f32 *)((s8 *)object + 0x38) = 512.0f;
    *(f32 *)((s8 *)object + 0x44) = 0.5f;
    *(s32 *)((s8 *)object + 0x48) = 0x12C;
    *(s32 *)((s8 *)object + 0x4C) = 0;
    *(s32 *)((s8 *)object + 0x50) = arg2;
    *(s32 *)((s8 *)object + 0x54) = 0xE;
    *(f32 *)((s8 *)object + 0x58) = (f32) lbl_805DAC08[0];
    *(f32 *)((s8 *)object + 0x5C) = (f32) lbl_805DAC08[0];
    *(f32 *)((s8 *)object + 0x60) = 1e+02f;
    *(f32 *)((s8 *)object + 0x64) = (f32) lbl_805DAC0C[0];
    *(f32 *)((s8 *)object + 0x70) = 0.5f;
    *(f32 *)((s8 *)object + 0x68) = 0.1953125f;
    *(f32 *)((s8 *)object + 0x6C) = 0.9375f;
    *(s32 *)((s8 *)object + 0x74) = 0x3C;
    *(s32 *)((s8 *)object + 0x78) = 0x3C;
    *(s32 *)((s8 *)object + 0x7C) = arg2;
    *(s32 *)((s8 *)object + 0x80) = 0xE;
    *(f32 *)((s8 *)object + 0x84) = 128.0f;
    *(f32 *)((s8 *)object + 0x88) = (f32) lbl_805DAC08[0];
    *(f32 *)((s8 *)object + 0x8C) = 512.0f;
    *(f32 *)((s8 *)object + 0x90) = 512.0f;
    *(f32 *)((s8 *)object + 0x9C) = 0.6f;
    *(s32 *)((s8 *)object + 0xA0) = 0x3C;
    *(s32 *)((s8 *)object + 0xA4) = 0x3C;
    *(s32 *)((s8 *)object + 0xA8) = arg2;
    *(s32 *)((s8 *)object + 0xAC) = 0xE;
    *(f32 *)((s8 *)object + 0xB0) = (f32) lbl_805DAC08[0];
    *(f32 *)((s8 *)object + 0xB4) = (f32) lbl_805DAC08[0];
    *(f32 *)((s8 *)object + 0xB8) = 1e+02f;
    *(f32 *)((s8 *)object + 0xBC) = (f32) lbl_805DAC0C[0];
    *(f32 *)((s8 *)object + 0xC8) = 0.6f;
    *(f32 *)((s8 *)object + 0xC0) = 0.1953125f;
    *(f32 *)((s8 *)object + 0xC4) = 0.9375f;
    *(s32 *)((s8 *)object + 0xCC) = 0x12C;
    *(s32 *)((s8 *)object + 0xD0) = 0;
    *(s32 *)((s8 *)object + 0xD4) = arg2;
    *(s32 *)((s8 *)object + 0xD8) = 0;
    *(f32 *)((s8 *)object + 0xDC) = 316.0f;
    *(f32 *)((s8 *)object + 0xE0) = 32.0f;
    *(f32 *)((s8 *)object + 0xE4) = 3e+02f;
    *(f32 *)((s8 *)object + 0xE8) = 3e+02f;
    *(f32 *)((s8 *)object + 0xF4) = 0.3f;
    *(s32 *)((s8 *)object + 0xF8) = 0x12C;
    *(s32 *)((s8 *)object + 0xFC) = 0;
    *(s32 *)((s8 *)object + 0x100) = arg2;
    *(s32 *)((s8 *)object + 0x104) = 0;
    *(f32 *)((s8 *)object + 0x108) = 316.0f;
    *(f32 *)((s8 *)object + 0x10C) = 148.0f;
    *(f32 *)((s8 *)object + 0x110) = 3e+02f;
    *(f32 *)((s8 *)object + 0x114) = 3e+02f;
    *(f32 *)((s8 *)object + 0x120) = 0.3f;
    *(s32 *)((s8 *)object + 0x124) = 0x1194;
    *(s32 *)((s8 *)object + 0x128) = 0x1E;
    *(s32 *)((s8 *)object + 0x12C) = arg2;
    *(s32 *)((s8 *)object + 0x130) = 0xF;
    *(f32 *)((s8 *)object + 0x134) = 1e+01f;
    *(f32 *)((s8 *)object + 0x138) = (f32) lbl_805DAC08[0];
    *(f32 *)((s8 *)object + 0x13C) = 3.4e+02f;
    *(f32 *)((s8 *)object + 0x140) = (f32) lbl_805DAC0C[0];
    *(f32 *)((s8 *)object + 0x14C) = 0.75f;
    temp_r3 = __nw__7TObjectFUl(0x64);
    if (temp_r3 != NULL) {
        __ct__18TItemReverseTechBGFv(temp_r3, (void *)object, object + 0x124);
    }
    *(s32 *)((s8 *)object + 0x150) = 0;
    *(s32 *)((s8 *)object + 0x154) = 0;
    return object;
}
}

TItemReverseTechPart2::~TItemReverseTechPart2() {}

extern "C" {
void run_task__21TItemReverseTechPart2Fv(u8 *object) {
    s32 temp_r3;
    s32 temp_r3_2;
    void *nw;

    if ((*(s32 *)((s8 *)object + 0x150) % 360) == 0) {
        if ((nw = __nw__7TObjectFUl(0x64)) != 0U) {
            __ct__18TItemReverseTechBGFv(nw, object, object + 0x74);
        }
        if ((nw = __nw__7TObjectFUl(0x64)) != 0U) {
            __ct__18TItemReverseTechBGFv(nw, object, object + 0xA0);
        }
    }
    if ((s32) *(s32 *)((s8 *)object + 0x154) < 0xC) {
        temp_r3 = *(s32 *)((s8 *)object + 0x150);
        if ((temp_r3 >= 0x78) && (((temp_r3 - 0x78) % 720) == 0)) {
            *(s32 *)((s8 *)object + 0x28) = 0xC;
            if ((nw = __nw__7TObjectFUl(0x64)) != 0U) {
                __ct__18TItemReverseTechBGFv(nw, object, object + 0x1C);
            }
            if ((nw = __nw__7TObjectFUl(0x64)) != 0U) {
                __ct__18TItemReverseTechBGFv(nw, object, object + 0x48);
            }
            *(s32 *)((s8 *)object + 0xD8) = (s32) *(s32 *)((s8 *)object + 0x154);
            if ((nw = __nw__7TObjectFUl(0x64)) != 0U) {
                __ct__18TItemReverseTechBGFv(nw, object, object + 0xCC);
            }
            *(s32 *)((s8 *)object + 0x154) = (s32) (*(s32 *)((s8 *)object + 0x154) + 1);
        }
        temp_r3_2 = *(s32 *)((s8 *)object + 0x150);
        if ((temp_r3_2 >= 0x1E0) && (((temp_r3_2 - 0x1E0) % 720) == 0)) {
            *(s32 *)((s8 *)object + 0x28) = 0xD;
            if ((nw = __nw__7TObjectFUl(0x64)) != 0U) {
                __ct__18TItemReverseTechBGFv(nw, object, object + 0x1C);
            }
            if ((nw = __nw__7TObjectFUl(0x64)) != 0U) {
                __ct__18TItemReverseTechBGFv(nw, object, object + 0x48);
            }
            *(s32 *)((s8 *)object + 0x104) = (s32) *(s32 *)((s8 *)object + 0x154);
            if ((nw = __nw__7TObjectFUl(0x64)) != 0U) {
                __ct__18TItemReverseTechBGFv(nw, object, object + 0xF8);
            }
            *(s32 *)((s8 *)object + 0x154) = (s32) (*(s32 *)((s8 *)object + 0x154) + 1);
        }
        goto block_26;
    }
    if ((u32) *(u32 *)((s8 *)object + 0x14) == 0U) {
        ((TObject *)object)->queue_destruction();
        return;
    }
block_26:
    *(s32 *)((s8 *)object + 0x150) = (s32) (*(s32 *)((s8 *)object + 0x150) + 1);
}
}

void TItemReverseTechPart2::render() {  }

const char *TItemReverseTechBG__name = "TItemReverseTechBG";

extern "C" {
void *__ct__18TItemReverseTechBGFv(void *arg0, void *parent, void *arg3) {
    s32 temp_r3;

    __ct__7TObjectFP7TObject(arg0, parent);
    *(void **)((s8 *)arg0 + 0x18) = __vt__18TItemReverseTechBG;
    *(s32 *)((s8 *)arg0 + 0) = (s32) TItemReverseTechBG__name;
    *(s32 *)((s8 *)arg0 + 0x1C) = (s32) *(s32 *)((s8 *)arg3 + 0);
    *(s32 *)((s8 *)arg0 + 0x20) = (s32) *(s32 *)((s8 *)arg3 + 4);
    *(s32 *)((s8 *)arg0 + 0x2C) = (s32) *(s32 *)((s8 *)arg3 + 8);
    *(s32 *)((s8 *)arg0 + 0x30) = (s32) *(s32 *)((s8 *)arg3 + 0xC);
    *(s32 *)((s8 *)arg0 + 0x24) = 0;
    temp_r3 = *(s32 *)((s8 *)arg0 + 0x20);
    if (temp_r3 != 0) {
        *(s32 *)((s8 *)arg0 + 0x28) = (s32) (0xFF / temp_r3);
        if ((u32) *(s32 *)((s8 *)arg0 + 0x28) == 0U) {
            *(s32 *)((s8 *)arg0 + 0x28) = 1;
        }
    }
    *(s32 *)((s8 *)arg0 + 0x34) = -1;
    *(f32 *)((s8 *)arg0 + 0x38) = (f32) *(f32 *)((s8 *)arg3 + 0x10);
    *(f32 *)((s8 *)arg0 + 0x3C) = (f32) *(f32 *)((s8 *)arg3 + 0x14);
    *(f32 *)((s8 *)arg0 + 0x40) = (f32) (*(f32 *)((s8 *)arg3 + 0x10) + *(f32 *)((s8 *)arg3 + 0x18));
    *(f32 *)((s8 *)arg0 + 0x44) = (f32) (*(f32 *)((s8 *)arg3 + 0x14) + *(f32 *)((s8 *)arg3 + 0x1C));
    *(f32 *)((s8 *)arg0 + 0x48) = (f32) lbl_805DAC08[0];
    *(f32 *)((s8 *)arg0 + 0x4C) = (f32) lbl_805DAC08[0];
    *(f32 *)((s8 *)arg0 + 0x50) = (f32) *(f32 *)((s8 *)arg3 + 0x20);
    *(f32 *)((s8 *)arg0 + 0x54) = (f32) *(f32 *)((s8 *)arg3 + 0x24);
    *(f32 *)((s8 *)arg0 + 0x58) = (f32) *(f32 *)((s8 *)arg3 + 0x28);
    *(s32 *)((s8 *)arg0 + 0x60) = 0;
    *(s32 *)((s8 *)arg0 + 0x5C) = 0;
    return arg0;
}
}

TItemReverseTechBG::~TItemReverseTechBG() {}

void TItemReverseTechBG::run_task() {
    TItemReverseTechBG_80119658 *o = (TItemReverseTechBG_80119658 *)this;
    switch (o->state) {
    case 0:
        if (o->alpha != 0xFF) {
            o->alpha += o->step;
            if (o->alpha > 0xFF) {
                o->alpha = 0xFF;
            }
        }
        if (o->timer == o->m20) {
            o->alpha = 0xFF;
            o->state = 1;
            o->timer = 0;
        } else {
            o->timer++;
        }
        break;
    case 1:
        if (o->timer == o->m1C) {
            o->state = 2;
            o->timer = 0;
        } else {
            o->timer++;
        }
        break;
    case 2:
        if (o->alpha != 0) {
            o->alpha -= o->step;
        }
        if (o->timer == o->m20) {
            o->alpha = 0;
            o->state = 3;
            o->timer = 0;
        } else {
            o->timer++;
        }
        break;
    case 3:
        ((TObject *)o)->queue_destruction();
        return;
    }
    o->color = (o->alpha << 24) | 0xFFFFFF;
}

void TItemReverseTechBG::render() {
    set_default_alpha_blend();
    set_texlist((u32)(*(void **)((s8 *)this + 0x2C)));
    begin_screen_draw(1);
    set_draw_texture_and_color((s32)(*(void **)((s8 *)this + 0x30)), (s32)(*(void **)((s8 *)this + 0x34)));
    draw_textured_quad_at_depth((f32 *)((char *)this + 56), *(f32 *)((s8 *)this + 0x58));
    TWindowSubStatusDisp::get_player();
}
