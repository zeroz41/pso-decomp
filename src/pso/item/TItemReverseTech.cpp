#include "pso/TItemReverseTech.h"
#include "pso/item/TItemReverseTechPart2.h"
#include "pso/item/TItemReverseTech.h"
#include "pso/misc/TCameraCtrl_800687BC.h"
#include "pso/misc/TKeyBoardControl_8000F764.h"
#include "pso/misc/TLoadCtrl_80227390.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/misc/TLobby.h"
#include "types.h"
#include <stddef.h>
#include "pso/TObject.h"
#include "pso/TMainTask.h"
#include "pso/system/memory.h"
#include "pso/system/main_loop.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TQuestVmDownLoadServer.h"
#include "pso/misc/TKeyBoardControl.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

#pragma opt_common_subs off

struct Stack_8011A00C {
    s32 sp8;
    s32 spC;
    s32 sp10;
    s32 sp14;
    s32 sp18;
    s32 sp1C;
};
extern "C" {

void *__nw__7TObjectFUl(int);
struct RecoveredGlobal_8011A00C_lbl_8043E6A4 {
    s32 value;
    u8 remaining[0x8];
};
typedef char RecoveredGlobal_8011A00C_lbl_8043E6A4_size[sizeof(RecoveredGlobal_8011A00C_lbl_8043E6A4) == 0xC ? 1 : -1];
extern RecoveredGlobal_8011A00C_lbl_8043E6A4 lbl_8043E6A4;
struct RecoveredGlobal_8011A00C_lbl_8043E6B0 {
    s32 value;
    u8 remaining[0x8];
};
typedef char RecoveredGlobal_8011A00C_lbl_8043E6B0_size[sizeof(RecoveredGlobal_8011A00C_lbl_8043E6B0) == 0xC ? 1 : -1];
extern RecoveredGlobal_8011A00C_lbl_8043E6B0 lbl_8043E6B0;
extern void *TItemReverseTech__texture_archive;

}

void TItemReverseTech::run_task() {
    typedef char sp8_offset[(offsetof(Stack_8011A00C, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_8011A00C, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_8011A00C, sp10) == 0x8) ? 1 : -1];
    typedef char sp14_offset[(offsetof(Stack_8011A00C, sp14) == 0xC) ? 1 : -1];
    typedef char sp18_offset[(offsetof(Stack_8011A00C, sp18) == 0x10) ? 1 : -1];
    typedef char sp1C_offset[(offsetof(Stack_8011A00C, sp1C) == 0x14) ? 1 : -1];
    Stack_8011A00C stack;

    u32 temp_r3;
    u32 object;
    u32 temp_r3_3;
    u32 var_r0;

    stack.sp14 = *(s32 *)((s8 *)&lbl_8043E6A4.value + 0);
    stack.sp18 = *(s32 *)((s8 *)&lbl_8043E6A4.value + 4);
    stack.sp1C = *(s32 *)((s8 *)&lbl_8043E6A4.value + 8);
    stack.sp8 = *(s32 *)((s8 *)&lbl_8043E6B0.value + 0);
    stack.spC = *(s32 *)((s8 *)&lbl_8043E6B0.value + 4);
    stack.sp10 = *(s32 *)((s8 *)&lbl_8043E6B0.value + 8);
    activate_camera_mode(9);
    set_active_camera_pose((u8 *)&stack.sp14, (u8 *)&stack.sp8);
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
        queue_destruction__7TObjectFv((this));
    }
}
#pragma opt_common_subs reset

TItemReverseTech::~TItemReverseTech() {
    TLobby::stop_audio_streams();
    request_queued_main_phase();
}


extern "C" {

void *__ct__10TAdEndTextFv(void *, void *);
void __ct__7TObjectFP7TObject(void *, void *);

extern s32 __vt__16TItemReverseTech[];
extern void *lbl_805D2C48;
extern s32 lbl_8043E708[];

void *TItemReverseTechPart1__ct(void *, void *, void *);
void *TItemReverseTech__ct(void *item_reverse_tech, void *parent) {
    void *o;
    void *o2;
    __ct__7TObjectFP7TObject(item_reverse_tech, parent);
    *(s32 **)((s8 *)item_reverse_tech + 0x18) = __vt__16TItemReverseTech;
    *(void * *)&((TItemReverseTech *)item_reverse_tech)->m_name = lbl_805D2C48;
    o = __nw__7TObjectFUl(0x34);
    if (o != NULL) {
        o = TItemReverseTechPart1__ct(o, item_reverse_tech, TItemReverseTech__texture_archive);
    }
    *(void * *)&((TItemReverseTech *)item_reverse_tech)->part_one = o;
    *(u32 *)((s8 *)item_reverse_tech + 0x24) = 0;
    o2 = __nw__7TObjectFUl(0x197C);
    if (o2 != NULL) {
        __ct__10TAdEndTextFv(o2, item_reverse_tech);
    }
    play_area_music((char *)lbl_8043E708);
    return item_reverse_tech;
}

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
extern const Vec_8011A43C lbl_8043E68C[];
extern const Vec_8011A43C lbl_8043E698[];
extern u8 default_scene_light_config[];
extern const float lbl_805DAC4C;
extern const f32 lbl_805DAC50;
extern "C" {
void TItemReverseTech__sub_8011A54C(void* a0);
int TItemReverseTech__sub_8011A55C(void);
int TItemReverseTech__sub_8011A580(void);
void TItemReverseTech__sub_8011A5A4(void);
void free__16TItemReverseTechFv(void);
s32 free_texture_if_valid(u32 arg0);
int set_global_flags__6TLobbyFl(void*);


void TItemReverseTech::create() {
    void *obj = __nw__7TObjectFUl(0x28);
    if (obj != 0) {
        TItemReverseTech__ct(obj, tl_01);
    }
}

void free__16TItemReverseTechFv(void) { free_texture_if_valid((u32)TItemReverseTech__texture_archive); mem_free((void *)TItemReverseTech__name_buffer); TItemReverseTech__name_buffer = 0; mem_free((void *)TItemReverseTech__entry_table); TItemReverseTech__entry_table = 0; ::operator delete((void *)TItemReverseTech__texture_archive); TItemReverseTech__texture_archive = 0; }

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

void TItemReverseTech::init_scene() {
    Ent_8011A43C *e;
    u32 i;
    void (*fn)();
    void *cam;
    set_screen_size((*(const f32 *)&lbl_805DAC4C), lbl_805DAC50);
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
    Vec_8011A43C eye = lbl_8043E68C[0];
    Vec_8011A43C at = lbl_8043E698[0];
    TCameraCtrl::select_active_controller(9);
    set_active_camera_pose((u8 *)&eye, (u8 *)&at);
    TKeyBoardControl__sub_8000F90C(2);
    TKeyBoardControl__sub_8000F91C(2);
    TParticleCtrl::create_quad_sprites();
    TItemReverseTech::create();
    render_tick();
}

void TItemReverseTech__sub_8011A54C(void* a0) { *(float*)((char*)a0 + 0x20) = lbl_805DAC4C; *(float*)((char*)a0 + 0x24) = lbl_805DAC4C; }

int TItemReverseTech__sub_8011A55C(void) { return set_global_flags__6TLobbyFl((void*)(2)); }
int TItemReverseTech__sub_8011A580(void) { return set_global_flags__6TLobbyFl((void*)(1)); }
void TItemReverseTech__sub_8011A5A4(void) {  }
}
