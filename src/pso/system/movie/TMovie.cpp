#include "pso/system/RelModuleBuffer.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/render/GinjaView.h"
#include <stddef.h>
#include <string.h>
#include "pso/system/movie/TMovie.h"
#include "pso/system/movie/TMovie_80143C94.h"
#include "pso/system/movie/TMovie_80143CE8.h"
#include "pso/unk/TLobby.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80083B38.h"
#include "pso/system/memory.h"
#include "pso/system/main_loop.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/system/TLoadCtrl_80227390.h"
#include "pso/ui/frontend/TAdEndText.h"
#include "pso/system/ControllerInput.h"
#include "pso/system/task/TObject.h"
#include "pso/unk/text_80320358.h"
#include "pso/ui/frontend/TAdEndText_80307A34.h"

struct MovieState;

extern "C" {
void TMovie__sub_80144324(MovieState *movie, const s8 *name);
}
int get_opening_movie_selector(void);
void activate_main_menu_scene(void);
extern "C" {
void fn_801449F0(void);

s32 DVDCheckDisk();
s32 set_queued_main_phase(s32);
s8 get_opening_movie_purpose();
void func_803DCDFC__Fv(void);
}

extern saddr video_initial_draw_framebuffer;
extern saddr video_initial_display_framebuffer;
extern int opening_movie_selector;
extern unsigned char main_menu_scene_active_flag;

const char *TMovie__name = "TMovie";
// The eye, target and up of the view a movie plays in.
static const Vec movie_camera_eye = {0.0f, 0.0f, 0.0f};
static const Vec movie_camera_target = {0.0f, 0.0f, 1.0f};
static const Vec movie_camera_up = {0.0f, 1.0f, 0.0f};

TMovie *TMovie::close(TMovie *movie, short dealloc) {
    if (movie != NULL) {
        movie->release();
        movie->free_buffer();
        TLobby::stop_audio_streams();
        if (dealloc > 0) {
            ::operator delete(movie);
        }
    }
    return movie;
}

u8 *initialize_movie_with_soundtrack(u8 *movie, s8 *name, s32 arg2, s32 arg3, s32 arg4) {
    *(s32 *)((s8 *)movie + 0xCC) = arg2;
    *(s32 *)((s8 *)movie + 0) = 0;
    TMovie__sub_80144324((MovieState *)movie, name);
    ((TMovie *)movie)->init_sfd_player(arg3, arg4);
    if (arg3 != 0) {
        play_area_music("CUBE_ENDING.adx");
    } else if ((get_opening_movie_purpose() == 0) && (get_opening_movie_selector() == 1)) {
        play_area_music("CUBE_OPENING.adx");
    } else {
        play_area_music("OPENING.ADX");
    }
    return movie;
}

s32 TMovie::stop_if_advanced() {
    if ((s32) *(s32 *)((s8 *)this + 0x58) >= 2) {
        TObjPlayer::draw_screen_quad(-1, 0, 0.0f);
    }
    return 1;
}

s32 TMovie::check_finished() {
    if ((s32) *(s32 *)((s8 *)this + 0x58) >= 2) {
        TMovie::flip_frame_buffer();
    }
    return 1;
}

s32 TMovie::is_playback_finished() {
    void **temp_r3;
    u8 *temp_r4;
    temp_r3 = (void **)(*(void ** *)&this->m_flags);
    temp_r4 = (u8 *)(*temp_r3);
    if ((*(s32 (**)(void **, void *))((s8 *)temp_r4 + 0x20))(temp_r3, temp_r4) == 3) {
        return 1;
    }
    return 0;
}

void TMovie::update_stop() {
    if ((s32) *(s32 *)((s8 *)this + 0xCC) != 0) {
        check_finished();
        return;
    }
    stop_if_advanced();
}

void TMovie::release() {
    void **temp_r3;
    void *temp_r4;

    temp_r3 = *(void ** *)&this->m_flags;
    temp_r4 = *temp_r3;
    (*(s32 (**)(void **, void *))((s8 *)temp_r4 + 0x14))(temp_r3, temp_r4);
    *(void ** *)&this->m_flags = NULL;
}

struct MovieFrameInfo {
    u32 field_00;
    u8 pad_C[0x4];
    s32 field_08;
    s32 field_0c;
    u8 trailing_storage[0x30];
};
// CRI Sofdec player handle (mwPlyCreateSofdec result); MwsfdCrePrm is its create-parameter block.
struct MwsfdPly;
struct MwsfdPlyVtbl {
    u8 pad0[0x18];
    void (*f18)(struct MwsfdPly *, void *);
    u8 pad1C[0x2C - 0x1C];
    void (*f2C)(struct MwsfdPly *, s32);
};
struct MwsfdPly { MwsfdPlyVtbl *vt; };
struct MwsfdCrePrm {
    s32 mode;
    s32 rate;
    s32 width;
    s32 height;
    s32 f10;
    s32 f14;
    s32 f18;
    s32 size;
};
struct Movie_80143FB0 {
    u8 pad0[4];
    MwsfdPly *iface;
    u8 pad8[0x28 - 0x8];
    MwsfdCrePrm info;
    s32 f48;
    u8 pad4C[0x9C - 0x4C];
    s32 f9C;
    s32 fA0;
    u8 fA4[4];
};

void TMovie::init_sfd_player(s32 arg1, s32 arg2) {
    Movie_80143FB0 *o = (Movie_80143FB0 *)this;
    MwsfdCrePrm *info = &o->info;
    MwsfdPly *f;

    o->fA0 = o->f9C;
    o->f48 = 0x11;
    if (arg1 != 0) {
        info->mode = 1;
    } else {
        info->mode = 2;
    }
    info->rate = 0x5B8D80;
    info->width = 0x280;
    info->height = 0x1E0;
    info->f10 = 3;
    info->size = mwPlyCalcWorkCprmSfd_hook(info);
    if (info->size > 0x420000) {
        return;
    }
    info->f18 = o->fA0;
    info->f14 = 1;
    f = mwPlyCreateSofdec_hook(info);
    o->iface = f;
    if (arg1 != 0) {
        if (arg2 != 0) {
            mwPlyEntryFname_hook(f, "ending_normal.sfd");
        } else {
            mwPlyEntryFname_hook(f, "ult01.sfd");
            mwPlyEntryFname_hook(f, "ult02.sfd");
            mwPlyEntryFname_hook(f, "ult03.sfd");
            mwPlyEntryFname_hook(f, "ult03.sfd");
            mwPlyEntryFname_hook(f, "ult03.sfd");
            mwPlyEntryFname_hook(f, "ult04.sfd");
        }
        mwPlyStartSeamless_hook(f);
        mwPlyReleaseSeamless_hook(f);
    } else {
        f->vt->f18(f, o->fA4);
    }
    f->vt->f2C(f, TLobby::get_lobby_data());
}

s32 TMovie::decode_frame() {
    u8 *arg0 = (u8 *)this;
    LAYOUT_ASSERT(sp8_offset, offsetof(MovieFrameInfo, field_00) == 0x0);
    LAYOUT_ASSERT(sp10_offset, offsetof(MovieFrameInfo, field_08) == 0x8);
    LAYOUT_ASSERT(sp14_offset, offsetof(MovieFrameInfo, field_0c) == 0xC);
    MovieFrameInfo frame;

    s32 temp_r3_2;
    void **temp_r3;
    u8 *temp_r4;

    if ((s32) *(s32 *)((s8 *)arg0 + 0xCC) != 0) {
        TMovie::flush_and_reset();
    }
    mwPlyGetCurFrm_hook(*(void ** *)&this->m_flags, &frame.field_00);
    if (frame.field_00 != 0U) {
        if ((s32) *(s32 *)((s8 *)arg0 + 0xCC) != 0) {
            TMovie__sub_80143C94((frame.field_00), (frame.field_08), (frame.field_0c));
        } else {
            flush_framebuffer((saddr)arg0, (saddr)(*(void ** *)&this->m_flags), (saddr)&frame.field_00);
        }
        ((TMovie *)(arg0 + 0x5C))->copy(&frame.field_00);
        mwPlyRelCurFrm_hook(*(void ** *)&this->m_flags);
    }
    temp_r3 = (void **)(*(void ** *)&this->m_flags);
    temp_r4 = (u8 *)(*temp_r3);
    temp_r3_2 = (*(s32 (**)(void **, void *))((s8 *)temp_r4 + 0x20))(temp_r3, temp_r4);
    if (temp_r3_2 == 3) {
        return 0;
    }
    *(s32 *)((s8 *)arg0 + 0x58) = temp_r3_2;
    return 1;
}

void TMovie::copy(void* q) { *(u32 *)&this->m_name = *(u32*)((char*)q + 0x0); *(u32 *)&this->m_flags = *(u32*)((char*)q + 0x4); *(u32 *)&this->m_prev = *(u32*)((char*)q + 0x8); *(u32 *)&this->m_next = *(u32*)((char*)q + 0xc); *(u32 *)&this->m_up = *(u32*)((char*)q + 0x10); *(u32 *)&this->m_down = *(u32*)((char*)q + 0x14); *(u32*)((char*)this + 0x18) = *(u32*)((char*)q + 0x18); module = ((const TMovie *)q)->module; this->player = ((const TMovie *)q)->player; *(u32 *)&this->m_24 = *(u32*)((char*)q + 0x24); *(u32 *)&this->unk_28 = *(u32*)((char*)q + 0x28); this->m_2c = *(u32*)((char*)q + 0x2c); *(u32 *)&this->unk_30 = *(u32*)((char*)q + 0x30); this->m_34 = *(u32*)((char*)q + 0x34); *(u32 *)&this->unk_38 = *(u32*)((char*)q + 0x38); this->m_3c = *(u32*)((char*)q + 0x3c); }

void TMovie::free_buffer() {
    if ((u32) *(u32 *)((s8 *)this + 0x9C) != 0U) {
        xfree(*(void **)((s8 *)this + 0x9C));
        *(u32 *)((s8 *)this + 0x9C) = 0U;
    }
    mwPlyFinishSfdFx_hook();
    reset_and_release_capture_texture();
}

struct MovieFrameRate {
    f32 rate;
    s32 m_04;
    s32 m_08;
    s32 m_0c;
};

struct MovieState {
    s32 m_00;
    s32 m_04;
    MovieFrameRate frame_rate;
    u8 unk_18[0x84];
    void *buffer;
    u8 unk_a0[0x4];
    char name[0x20];
    s32 m_c4;
    s32 m_c8;
    s32 m_cc;
};

void TMovie__sub_80144324(MovieState *movie, const s8 *name) {
    TObjPlayer::reset_movie_state();
    memset(&movie->m_04, 0, 0xC8);
    movie->buffer = xmalloc(0x420000);
    movie->m_04 = 0;
    movie->m_c8 = 1;
    movie->m_c4 = 0;
    strcpy(movie->name, (const char *)name);
    movie->frame_rate.rate = 59.94f;
    movie->frame_rate.m_04 = 1;
    movie->frame_rate.m_08 = 2;
    movie->frame_rate.m_0c = 0;
    mwPlyInitSfdFx_hook(&movie->frame_rate);
}

TMovie::~TMovie() {
    s32 (*temp_r12)(void *);
    TMovie *t;

    this->render_until_finished();
    render_tick();
    t = this->player;
    if (t != NULL) {
        TMovie::close(t, 1);
        this->player = NULL;
    }
    render_tick();
    render_tick();
    RelModuleBuffer *loaded = module;
    if (loaded != NULL) {
        destroy_rel_module(loaded, 1);
        module = NULL;
    }
    render_tick();
    temp_r12 = *(s32 (**)(void *))((s8 *)this + 0x44);
    if (temp_r12 != NULL) {
        temp_r12(this);
    }
    TLobby::set_pre_retrace_callback();
}

void TMovie::render_until_finished() {
loop_1:
    if ((DVDCheckDisk() == 0) && (TLobby::run_disk_error_check() == 0)) {
        render_tick();
        goto loop_1;
    }
}

s32 TMovie::check_skip_input() {
    ControllerInputContext *context;
    s32 var_r30;

    if (is_ending_sequence_active() != 0) {
        if ((TLobby::run_disk_error_check() == 0) || (this->player->is_playback_finished() != 0) || (static_cast<s8>(func_801A5E54()) != 0)) {
            if ((TLobby::run_disk_error_check() == 0) || (static_cast<s8>(func_801A5E54()) != 0)) {
                fn_801449F0();
            }
            return 1;
        }
        goto block_return0;
    }
    switch (get_opening_movie_purpose()) {
    case 0:
        context = &controller_physical_port_bank.controllers[0];
        if (test_pressed_buttons_packed(context, 4) != 0) goto block_fn_8000F91C;
        if (test_pressed_buttons_packed(context, 2) != 0) goto block_fn_8000F91C;
        if (test_pressed_buttons_packed(context, 0x400) != 0) goto block_fn_8000F91C;
        if (test_pressed_buttons_packed(context, 0x200) != 0) goto block_fn_8000F91C;
        if (test_pressed_buttons_packed(context, 8) != 0) goto block_fn_8000F91C;
        if (test_pressed_buttons_packed(context, 0x10) != 0) goto block_fn_8000F91C;
        if (test_pressed_buttons_packed(context, 0x20) != 0) goto block_fn_8000F91C;
        if (test_pressed_buttons_packed(context, 0x40) != 0) goto block_fn_8000F91C;
        if (test_pressed_buttons_packed(context, 0x80) != 0) goto block_fn_8000F91C;
        if (test_pressed_buttons_packed(context, 0x20000) != 0) goto block_fn_8000F91C;
        if (test_pressed_buttons_packed(context, 0x10000) != 0) goto block_fn_8000F91C;
        context = &controller_input_state.keyboard;
        if (test_controller_flag_4c_color(context, 4) != 0) goto block_fn_8000F91C;
        if (test_controller_flag_4c_color(context, 2) != 0) goto block_fn_8000F91C;
        if (TLobby::run_disk_error_check() == 0) goto block_fn_8000F91C;
        if (TKeyBoardControl::check_reset_button() != 0) goto block_fn_8000F91C;
        if (this->player->is_playback_finished() == 0) goto block_return0;
block_fn_8000F91C:
        set_queued_main_phase(9);
        return 1;
    case 1:
        var_r30 = 0;
        if (TKeyBoardControl::check_reset_button() != 0) {
            var_r30 = 1;
        }
        context = &controller_physical_port_bank.controllers[0];
        if (test_pressed_buttons_packed(context, 2) != 0) goto block_call_func;
        if (test_pressed_buttons_packed(context, 8) != 0) goto block_call_func;
        context = &controller_input_state.keyboard;
        if (test_controller_flag_4c_color(context, 4) != 0) goto block_call_func;
        if (test_controller_flag_4c_color(context, 2) != 0) goto block_call_func;
        if (TLobby::run_disk_error_check() == 0) goto block_call_func;
        if (var_r30 != 0) goto block_call_func;
        if (this->player->is_playback_finished() == 0) goto block_return0;
block_call_func:
        if ((static_cast<s8>(func_801A5E54()) != 0) || (var_r30 != 0)) {
            activate_main_menu_scene();
        }
        return 1;
    }
block_return0:
    return 0;
}

struct TMovie_80144910 {
    const char *name;
    u8 pad4[0x14];
    void *vt;
    RelModuleBuffer *obj1C;
    u8 *obj20;
    char path[0x20];
    s32 f44;
    s32 f48;
};

void TMovie::run_task() {
    TAdEndText *txt;
    if (this->module == NULL || this->player == NULL) {
        this->queue_destruction();
        return;
    }
    render_tick();
    render_tick();
    TMovie::calc_frame_buffer_size((saddr)((void *)video_initial_display_framebuffer), (saddr)((void *)video_initial_draw_framebuffer));
    txt = NULL;
    if (is_ending_sequence_active() != 0) {
        txt = new TAdEndText(this);
    }
    for (;;) {
        if (this->check_skip_input() != 0) {
            break;
        }
        func_803DCDFC__Fv();
        controller_stuff();
        TKeyBoardControl::update_input_frame();
        this->player->decode_frame();
        if (*(s32 *)&this->m_48 != 0) {
            this->player->update_stop();
            TMovie::run_callback();
        } else {
            Vec eye = movie_camera_eye;
            Vec at = movie_camera_target;
            Vec up = movie_camera_up;
            set_perspective_projection_from_fov(0x4B, 1.1333334f, 1.0f, 21000.0f);
            set_camera_look_at(&eye, &at, &up);
            this->player->update_stop();
            if (txt != NULL) {
                txt->run_task();
                txt->render();
            }
            render_tick();
        }
    }
    this->queue_destruction();
}

TMovie::TMovie(TObject *parent, s8 *name, s32 a3, s32 a4, s32 a5) : TObject(parent) {
    u8 *p;
    ((TMovie_80144910 *)this)->name = TMovie__name;
    ((TMovie_80144910 *)this)->f44 = a3;
    module = NULL;
    ((TMovie_80144910 *)this)->f48 = a4;
    ((TMovie_80144910 *)this)->obj20 = 0;
    strncpy(((TMovie_80144910 *)this)->path, (const char *)name, 0x20);
    RelModuleBuffer *loaded = new RelModuleBuffer;
    if (loaded != NULL) {
        loaded = load_rel_module(loaded, "movie.rel");
    }
    module = loaded;
    p = (u8 *)::operator new(0xD0);
    if (p != 0) {
        p = initialize_movie_with_soundtrack(p, name, ((TMovie_80144910 *)this)->f48, (u8)!((TMovie_80144910 *)this)->f48, a5);
    }
    ((TMovie_80144910 *)this)->obj20 = p;
}

int get_opening_movie_selector(void) { return opening_movie_selector; }

void activate_main_menu_scene(void) { main_menu_scene_active_flag = 1; }

void fn_801449F0(void) { ending_movie_active_flag = 1; }
