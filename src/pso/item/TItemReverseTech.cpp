#include "pso/render/GvmTextureArchive.h"
#include "pso/system/ResourceFile.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include <string.h>
#include "pso/ui/frontend/TAdEndText.h"
#include "pso/item/TItemReverseTechBG.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItemReverseTechPart2.h"
#include "pso/item/TItemReverseTech_8011A1E8.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/render/render_util.h"
#include "pso/item/TItemReverseTechPart1.h"
#include "pso/ui/frontend/TAdRicoRingCtrl.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/TLobby_800FC3CC.h"
#include "pso/item/TItemReverseTech.h"
#include "pso/object/ambient/TObjLight_80133568.h"
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
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/player/TObjPlayer_801A5AEC.h"
#include "pso/unk/TScreenFadeIn.h"
#include "pso/system/ControllerInput.h"




NJS_TEXLIST *TItemReverseTech::texture_list;
NJS_TEXNAME *TItemReverseTech::texnames;
char *TItemReverseTech::name_buffer;
TItemReverseTechPart1 *TItemReverseTechPart1::instance;

static const f32 lbl_805DAC08[1] = {0.0f};
static const f32 lbl_805DAC0C[1] = {480.0f};






const char *TItemReverseTech__name = "TItemReverseTech";


extern "C" {
s32 prs_decompress_alloc(int, void *, int);
void activate_fast_rotation_code(void);
void activate_reverse_rotation_code(void);
void activate_uraending_code(void);
}
void process_async_file_reads(void);
void update_sound_request_slots(void);
void clear_resource_load_tasks();
void set_screen_size(f32, f32);
TItemReverseTechSceneHook TItemReverseTech::cleanup_callback_table[7] = {
    {TCameraCtrl::reset_view_state, TCameraCtrl::reset},
    {TCameraCtrl::init_default_view, TCameraCtrl::reset_default_view},
    {TLobby::update_keyboard_menu, TLobby::free_keyboard_soft_resources},
    {TLobby::set_ending_callback, TLobby::free_ending_callback},
    {TAdRicoRingCtrl::load_static_resource, TAdRicoRingCtrl::release_global_805D4A00},
    {TAdEndText::load_ending_font, TAdEndText::free_resources},
    {TItemReverseTech::load_textures, TItemReverseTech::free},
};

#pragma defer_codegen on


void activate_uraending_code(void) {  }
void activate_reverse_rotation_code(void) { TLobby::set_global_flags(1); }
void activate_fast_rotation_code(void) { TLobby::set_global_flags(2); }

TItemReverseTechPicture::TItemReverseTechPicture() {
    u1 = 1.0f;
    v1 = 1.0f;
}

void TItemReverseTech::init_scene() {
    TItemReverseTechSceneHook *e;
    u32 i;
    void (*fn)();
    set_screen_size(1.0f, 0.85f);
    set_copy_clear_color_argb(0, 0, 0);
    reset_controller_input_state();
    clear_resource_load_tasks();
    e = cleanup_callback_table;
    for (i = 0; i != 7; i++) {
        fn = e->load;
        e++;
        if (fn != NULL) {
            fn();
        }
    }
    init_map_lights(&default_scene_light_config);
    new TCameraCtrl(tl_camera);
    Vec eye = {0.0f, 0.0f, 0.0f};
    Vec at = {0.0f, 0.0f, -100.0f};
    TCameraCtrl::select_active_controller(9);
    set_active_camera_pose(&eye, &at);
    TKeyBoardControl__sub_8000F90C(2);
    set_queued_main_phase(2);
    TParticleCtrl::create_quad_sprites();
    TItemReverseTech::create();
    render_tick();
}

void TItemReverseTech::run_cleanup_callbacks() {
    void (*fn)(void);
    TItemReverseTechSceneHook *e;
    s32 i;
    main_task.delete_layer_children();
    i = 6;
    e = &cleanup_callback_table[6];
    do {
        fn = e->release;
        e--;
        if (fn != NULL) {
            fn();
        }
        i--;
    } while (i >= 0);
    render_tick();
}

void TItemReverseTech::run_frame() {
    controller_stuff();
    TKeyBoardControl::update_input_frame();
    main_task.begin_frame();
    main_task.run_task();
    main_task.render();
    main_task.render_screen_overlay();
    process_async_file_reads();
    update_sound_request_slots();
    TAdSinglePlyChrSelectGC::noop();
    if (static_cast<s8>(func_801A5E54()) != 0) {
        TKeyBoardControl__sub_8000F92C();
    }
    if (TQuestVmDownLoadServer::is_ready() != 0) {
        request_main_phase(0);
    }
    render_tick();
}

#pragma push
#pragma opt_propagation off
void TItemReverseTech::load_textures() {
    const char *name = "ItemRTT.prs";
    NJS_TEXNAME *e;
    s32 i;
    NJS_TEXLIST *list;
    int file;
    void *buf;
    name_buffer = (char *)mem_alloc(0x1C);
    strncpy(name_buffer, name, 0x1B);
    e = (NJS_TEXNAME *)mem_alloc(17 * sizeof(NJS_TEXNAME));
    texnames = e;
    for (i = 0; i < 17; i++, e++) {
        e->filename = name_buffer;
        e->attr = 0;
        e->texaddr = 0;
    }
    list = new NJS_TEXLIST;
    texture_list = list;
    list->textures = texnames;
    file = (saddr)load_disc_file(name);
    if (file != 0) {
        buf = mem_alloc(0x200000);
        if (buf != NULL && prs_decompress_alloc(file, buf, 0x200000) > 0) {
            load_gvm_texture_archive(buf, texture_list);
        }
        mem_free(buf);
    }
    safe_free(reinterpret_cast<void *>(file));
}
#pragma pop

void TItemReverseTech::free() {
    free_texture_if_valid(texture_list);
    mem_free(name_buffer);
    name_buffer = NULL;
    mem_free(texnames);
    texnames = NULL;
    delete texture_list;
    texture_list = NULL;
}

void TItemReverseTech::create() {
    new TItemReverseTech((TObject *)tl_01);
}

TItemReverseTech::TItemReverseTech(TObject *parent) : TObject(parent) {
    m_name = TItemReverseTech__name;
    part_one = new TItemReverseTechPart1(this, texture_list);
    part_two = NULL;
    new TAdEndText(this);
    play_area_music("ending.adx");
}


TItemReverseTech::~TItemReverseTech() {
    TLobby::stop_audio_streams();
    request_queued_main_phase();
}

#pragma opt_common_subs off

void TItemReverseTech::run_task() {
    Vec eye = {0.0f, 0.0f, 0.0f};
    Vec at = {0.0f, 0.0f, -100.0f};

    activate_camera_mode(9);
    set_active_camera_pose(&eye, &at);
    if (part_one != NULL && part_one->all_parents_unqueued_for_destruction() == 0) {
        part_one = NULL;
        part_two = new TItemReverseTechPart2(this, texture_list);
    }
    if (part_two != NULL && part_two->all_parents_unqueued_for_destruction() == 0) {
        part_two = NULL;
        queue_destruction();
    }
}
#pragma opt_common_subs reset

const char *TItemReverseTechPart1__name = "TItemReverseTechPart1";


TItemReverseTechPart1::TItemReverseTechPart1(TObject *parent, NJS_TEXLIST *texlist) : TObject(parent) {
    m_name = TItemReverseTechPart1__name;
    state = 0;
    timer = 0;
    fade_in_time = 150;
    hold_time = 3900;
    fade_out_time = 150;
    ring = NULL;
    instance = this;
    new TScreenFadeIn(tl_00, TItemReverseTechPart2::destroy_and_flag);
}


TItemReverseTechPart1::~TItemReverseTechPart1() {}


void TItemReverseTechPart1::run_task() {
    switch (state) {
    case 0:
        break;
    case 1:
        if (ring == NULL) {
            ring = new TAdRicoRingCtrl(this);
            if (ring != NULL) {
                ring->start_fade_all(fade_in_time);
            }
        }
        if (timer == fade_in_time) {
            state = 2;
            timer = 0;
        } else {
            timer++;
        }
        break;
    case 2:
        if (timer == hold_time) {
            state = 3;
            timer = 0;
            if (ring != NULL) {
                ring->sub_8001B4A0(fade_in_time);
                ring = NULL;
            }
        } else {
            timer++;
        }
        break;
    case 3:
        if (timer == fade_out_time) {
            state = 4;
            timer = 0;
        } else {
            timer++;
        }
        break;
    case 4:
        queue_destruction();
        break;
    }
}


void TItemReverseTechPart2::destroy_and_flag(TObject *fade) {
    fade->queue_destruction();
    if (TItemReverseTechPart1::instance != NULL) {
        TItemReverseTechPart1::instance->state = 1;
    }
}

const char *TItemReverseTechPart2__name = "TItemReverseTechPart2";


TItemReverseTechPart2::TItemReverseTechPart2(TObject *parent, NJS_TEXLIST *texlist) : TObject(parent) {
    m_name = TItemReverseTechPart2__name;
    picture_0.hold_time = 300;
    picture_0.fade_time = 0;
    picture_0.texlist = texlist;
    picture_0.texture = 0;
    picture_0.x = 128.0f;
    picture_0.y = lbl_805DAC08[0];
    picture_0.width = 512.0f;
    picture_0.height = 512.0f;
    picture_0.depth = 0.5f;
    picture_1.hold_time = 300;
    picture_1.fade_time = 0;
    picture_1.texlist = texlist;
    picture_1.texture = 14;
    picture_1.x = lbl_805DAC08[0];
    picture_1.y = lbl_805DAC08[0];
    picture_1.width = 100.0f;
    picture_1.height = lbl_805DAC0C[0];
    picture_1.depth = 0.5f;
    picture_1.u1 = 0.1953125f;
    picture_1.v1 = 0.9375f;
    picture_2.hold_time = 60;
    picture_2.fade_time = 60;
    picture_2.texlist = texlist;
    picture_2.texture = 14;
    picture_2.x = 128.0f;
    picture_2.y = lbl_805DAC08[0];
    picture_2.width = 512.0f;
    picture_2.height = 512.0f;
    picture_2.depth = 0.6f;
    picture_3.hold_time = 60;
    picture_3.fade_time = 60;
    picture_3.texlist = texlist;
    picture_3.texture = 14;
    picture_3.x = lbl_805DAC08[0];
    picture_3.y = lbl_805DAC08[0];
    picture_3.width = 100.0f;
    picture_3.height = lbl_805DAC0C[0];
    picture_3.depth = 0.6f;
    picture_3.u1 = 0.1953125f;
    picture_3.v1 = 0.9375f;
    picture_4.hold_time = 300;
    picture_4.fade_time = 0;
    picture_4.texlist = texlist;
    picture_4.texture = 0;
    picture_4.x = 316.0f;
    picture_4.y = 32.0f;
    picture_4.width = 300.0f;
    picture_4.height = 300.0f;
    picture_4.depth = 0.3f;
    picture_5.hold_time = 300;
    picture_5.fade_time = 0;
    picture_5.texlist = texlist;
    picture_5.texture = 0;
    picture_5.x = 316.0f;
    picture_5.y = 148.0f;
    picture_5.width = 300.0f;
    picture_5.height = 300.0f;
    picture_5.depth = 0.3f;
    picture_6.hold_time = 4500;
    picture_6.fade_time = 30;
    picture_6.texlist = texlist;
    picture_6.texture = 15;
    picture_6.x = 10.0f;
    picture_6.y = lbl_805DAC08[0];
    picture_6.width = 340.0f;
    picture_6.height = lbl_805DAC0C[0];
    picture_6.depth = 0.75f;
    new TItemReverseTechBG(this, &picture_6);
    frame = 0;
    shown_count = 0;
}

TItemReverseTechPart2::~TItemReverseTechPart2() {}


void TItemReverseTechPart2::run_task() {
    if (frame % 360 == 0) {
        new TItemReverseTechBG(this, &picture_2);
        new TItemReverseTechBG(this, &picture_3);
    }
    if (shown_count < 12) {
        if (frame >= 120 && (frame - 120) % 720 == 0) {
            picture_0.texture = 12;
            new TItemReverseTechBG(this, &picture_0);
            new TItemReverseTechBG(this, &picture_1);
            picture_4.texture = shown_count;
            new TItemReverseTechBG(this, &picture_4);
            shown_count++;
        }
        if (frame >= 480 && (frame - 480) % 720 == 0) {
            picture_0.texture = 13;
            new TItemReverseTechBG(this, &picture_0);
            new TItemReverseTechBG(this, &picture_1);
            picture_5.texture = shown_count;
            new TItemReverseTechBG(this, &picture_5);
            shown_count++;
        }
    } else if (m_down == NULL) {
        queue_destruction();
        return;
    }
    frame++;
}

void TItemReverseTechPart2::render() {  }

const char *TItemReverseTechBG__name = "TItemReverseTechBG";


TItemReverseTechBG::TItemReverseTechBG(TObject *parent, TItemReverseTechPicture *picture) : TObject(parent) {
    m_name = TItemReverseTechBG__name;
    hold_time = picture->hold_time;
    fade_time = picture->fade_time;
    texlist = picture->texlist;
    texture = picture->texture;
    alpha = 0;
    if (fade_time != 0) {
        alpha_step = 0xFF / fade_time;
        if (alpha_step == 0) {
            alpha_step = 1;
        }
    }
    color = 0xFFFFFFFF;
    quad.x0 = picture->x;
    quad.y0 = picture->y;
    quad.x1 = picture->x + picture->width;
    quad.y1 = picture->y + picture->height;
    quad.u0 = lbl_805DAC08[0];
    quad.v0 = lbl_805DAC08[0];
    quad.u1 = picture->u1;
    quad.v1 = picture->v1;
    depth = picture->depth;
    state = 0;
    timer = 0;
}

TItemReverseTechBG::~TItemReverseTechBG() {}

void TItemReverseTechBG::run_task() {
    switch (state) {
    case 0:
        if (alpha != 0xFF) {
            alpha += alpha_step;
            if (alpha > 0xFF) {
                alpha = 0xFF;
            }
        }
        if (timer == fade_time) {
            alpha = 0xFF;
            state = 1;
            timer = 0;
        } else {
            timer++;
        }
        break;
    case 1:
        if (timer == hold_time) {
            state = 2;
            timer = 0;
        } else {
            timer++;
        }
        break;
    case 2:
        if (alpha != 0) {
            alpha -= alpha_step;
        }
        if (timer == fade_time) {
            alpha = 0;
            state = 3;
            timer = 0;
        } else {
            timer++;
        }
        break;
    case 3:
        queue_destruction();
        return;
    }
    color = (alpha << 24) | 0xFFFFFF;
}

void TItemReverseTechBG::render() {
    set_default_alpha_blend();
    set_texlist(texlist);
    begin_screen_draw(1);
    set_draw_texture_and_color(texture, color);
    draw_textured_quad_at_depth((f32 *)&quad, depth);
    TWindowSubStatusDisp::get_player();
}
