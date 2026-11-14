#include "types.h"
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
#include "pso/ui/frontend/TAdEndText.h"

struct MovieState;
struct Vec_80144778 { s32 x, y, z; };

extern "C" {
void TMovie__sub_80144324(MovieState *movie, const s8 *name);
void run_task__6TMovieFv(TMovie *movie);
int get_opening_movie_selector(void);
void activate_main_menu_scene(void);
void fn_801449F0(void);

s32 is_playback_finished__6TMovieFv(s32);
s32 __dl__7TObjectFPv(void *);
s32 __dt__7TObjectFv(void *, s32);
u8 *__nw__7TObjectFUl(s32);
void queue_destruction__7TObjectFv(void *arg0);
s32 fn_80320358(u32, s32);
s32 DVDCheckDisk();
s32 TWindowShortListCtrl__check_controller_button(void *, s32);
s32 TKeyBoardControl__sub_8000F91C(s32);
s32 test_flag_4c__23TAdSinglePlyChrSelectGCFv(void *, s32);
s8 get_opening_movie_purpose();
s8 func_801A5E54__Fv();
u8 *load_rel_module(u8 *arg0, s32 arg1);
void set_perspective_projection_from_fov(s32 arg0, f32 farg0, f32 farg1, f32 farg2);
void func_803DCDFC__Fv(void);

extern void *__vt__6TMovie[];
extern s32 TMovie__name;
extern s8 controller_input_state[];
extern s8 controller_physical_port_bank[];
extern Vec_80144778 lbl_8043F2E8;
extern Vec_80144778 lbl_8043F2F4;
extern Vec_80144778 lbl_8043F300;
extern s32 video_initial_draw_framebuffer;
extern s32 video_initial_display_framebuffer;
extern int opening_movie_selector;
extern unsigned char main_menu_scene_active_flag;
extern int ending_movie_active_flag;

void play_area_music(const s8 *);
extern s8 lbl_8043F30C[];
extern s8 lbl_8043F31C[];
extern s8 lbl_8043F330[];
}

void set_camera_look_at(u8 *eye, u8 *target, u8 *up);

s32 TMovie::close(int arg0, short arg1) {
    if (arg0 != 0) {
        ((TMovie *)arg0)->release();
        ((TMovie *)arg0)->free_buffer();
        TLobby::stop_audio_streams();
        if (arg1 > 0) {
            ::operator delete((void *)arg0);
        }
    }
    return arg0;
}

u8 *initialize_movie_with_soundtrack(u8 *movie, s8 *arg1, s32 arg2, s32 arg3, s32 arg4) {
    *(s32 *)((s8 *)movie + 0xCC) = arg2;
    *(s32 *)((s8 *)movie + 0) = 0;
    TMovie__sub_80144324((MovieState *)movie, arg1);
    ((TMovie *)movie)->init_sfd_player(arg3, arg4);
    if (arg3 != 0) {
        play_area_music(lbl_8043F30C);
    } else if ((get_opening_movie_purpose() == 0) && (get_opening_movie_selector() == 1)) {
        play_area_music(lbl_8043F31C);
    } else {
        play_area_music(lbl_8043F330);
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

bool TMovie::is_playback_finished() {
    void **temp_r3;
    u8 *temp_r4;
    temp_r3 = (void **)(*(void ** *)&this->m_flags);
    temp_r4 = (u8 *)(*temp_r3);
    return (*(s32 (**)(void **, void *))((s8 *)temp_r4 + 0x20))(temp_r3, temp_r4) == 3;
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
struct Iface_80143FB0;
struct IfaceVt_80143FB0 {
    u8 pad0[0x18];
    void (*f18)(struct Iface_80143FB0 *, void *);
    u8 pad1C[0x2C - 0x1C];
    void (*f2C)(struct Iface_80143FB0 *, s32);
};
struct Iface_80143FB0 { IfaceVt_80143FB0 *vt; };
struct Info_80143FB0 {
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
    Iface_80143FB0 *iface;
    u8 pad8[0x28 - 0x8];
    Info_80143FB0 info;
    s32 f48;
    u8 pad4C[0x9C - 0x4C];
    s32 f9C;
    s32 fA0;
    u8 fA4[4];
};

extern s32 (*TMovie__decode_frame_callback)(void **, u32 *);
extern s32 (*lbl_805D6B3C)(void **);

extern u8 lbl_8043F33C[];
extern u8 lbl_8043F350[];
extern u8 lbl_8043F35C[];
extern u8 lbl_8043F368[];
extern u8 lbl_8043F374[];
extern s32 (*movie_sfd_info_size_fn)(Info_80143FB0 *);
extern Iface_80143FB0 *(*lbl_805D6B34)(Info_80143FB0 *);
extern void (*lbl_805D6B9C)(Iface_80143FB0 *, void *);
extern void (*lbl_805D6BA0)(Iface_80143FB0 *);
extern void (*lbl_805D6BA4)(Iface_80143FB0 *);

void TMovie::init_sfd_player(s32 arg1, s32 arg2) {
    Movie_80143FB0 *o = (Movie_80143FB0 *)this;
    Info_80143FB0 *info = &o->info;
    Iface_80143FB0 *f;

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
    info->size = movie_sfd_info_size_fn(info);
    if (info->size > 0x420000) {
        return;
    }
    info->f18 = o->fA0;
    info->f14 = 1;
    f = lbl_805D6B34(info);
    o->iface = f;
    if (arg1 != 0) {
        if (arg2 != 0) {
            lbl_805D6B9C(f, lbl_8043F33C);
        } else {
            lbl_805D6B9C(f, lbl_8043F350);
            lbl_805D6B9C(f, lbl_8043F35C);
            lbl_805D6B9C(f, lbl_8043F368);
            lbl_805D6B9C(f, lbl_8043F368);
            lbl_805D6B9C(f, lbl_8043F368);
            lbl_805D6B9C(f, lbl_8043F374);
        }
        lbl_805D6BA0(f);
        lbl_805D6BA4(f);
    } else {
        f->vt->f18(f, o->fA4);
    }
    f->vt->f2C(f, TLobby::get_lobby_data());
}

s32 TMovie::decode_frame() {
    u8 *arg0 = (u8 *)this;
    typedef char sp8_offset[(offsetof(MovieFrameInfo, field_00) == 0x0) ? 1 : -1];
    typedef char sp10_offset[(offsetof(MovieFrameInfo, field_08) == 0x8) ? 1 : -1];
    typedef char sp14_offset[(offsetof(MovieFrameInfo, field_0c) == 0xC) ? 1 : -1];
    MovieFrameInfo frame;

    s32 temp_r3_2;
    void **temp_r3;
    u8 *temp_r4;

    if ((s32) *(s32 *)((s8 *)arg0 + 0xCC) != 0) {
        TMovie::flush_and_reset();
    }
    TMovie__decode_frame_callback(*(void ** *)&this->m_flags, &frame.field_00);
    if (frame.field_00 != 0U) {
        if ((s32) *(s32 *)((s8 *)arg0 + 0xCC) != 0) {
            TMovie__sub_80143C94((frame.field_00), (frame.field_08), (frame.field_0c));
        } else {
            flush_framebuffer((s32)arg0, (s32)(*(void ** *)&this->m_flags), (s32)&frame.field_00);
        }
        ((TMovie *)(arg0 + 0x5C))->copy(&frame.field_00);
        lbl_805D6B3C(*(void ** *)&this->m_flags);
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

void TMovie::copy(void* q) { *(u32 *)&this->m_name = *(u32*)((char*)q + 0x0); *(u32 *)&this->m_flags = *(u32*)((char*)q + 0x4); *(u32 *)&this->m_prev = *(u32*)((char*)q + 0x8); *(u32 *)&this->m_next = *(u32*)((char*)q + 0xc); *(u32 *)&this->m_up = *(u32*)((char*)q + 0x10); *(u32 *)&this->m_down = *(u32*)((char*)q + 0x14); *(u32*)((char*)this + 0x18) = *(u32*)((char*)q + 0x18); this->m_1c = *(u32*)((char*)q + 0x1c); this->m_20 = *(u32*)((char*)q + 0x20); *(u32 *)&this->m_24 = *(u32*)((char*)q + 0x24); *(u32 *)&this->unk_28 = *(u32*)((char*)q + 0x28); this->m_2c = *(u32*)((char*)q + 0x2c); *(u32 *)&this->unk_30 = *(u32*)((char*)q + 0x30); this->m_34 = *(u32*)((char*)q + 0x34); *(u32 *)&this->unk_38 = *(u32*)((char*)q + 0x38); this->m_3c = *(u32*)((char*)q + 0x3c); }

extern s32 (*movie_free_buffer_callback)();

void TMovie::free_buffer() {
    if ((u32) *(u32 *)((s8 *)this + 0x9C) != 0U) {
        xfree(*(void **)((s8 *)this + 0x9C));
        *(u32 *)((s8 *)this + 0x9C) = 0U;
    }
    movie_free_buffer_callback();
    TObjPlayer__sub_80084614();
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

extern void (*lbl_805D6B28)(MovieFrameRate *);

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
    lbl_805D6B28(&movie->frame_rate);
}

void *__dt__6TMovieFv(TMovie *arg0, s16 arg1) {
    s32 (*temp_r12)(void *);
    u32 t;

    if (arg0 != NULL) {
        *(void **)((s8 *)arg0 + 0x18) = __vt__6TMovie;
        arg0->render_until_finished();
        render_tick();
        t = arg0->m_20;
        if (t != 0U) {
            TMovie::close(t, 1);
            arg0->m_20 = 0U;
        }
        render_tick();
        render_tick();
        t = arg0->m_1c;
        if (t != 0U) {
            fn_80320358(t, 1);
            arg0->m_1c = 0U;
        }
        render_tick();
        temp_r12 = *(s32 (**)(void *))((s8 *)arg0 + 0x44);
        if (temp_r12 != NULL) {
            temp_r12(arg0);
        }
        TLobby::set_pre_retrace_callback();
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

void TMovie::render_until_finished() {
loop_1:
    if ((DVDCheckDisk() == 0) && (TLobby::run_disk_error_check() == 0)) {
        render_tick();
        goto loop_1;
    }
}

s32 TMovie::check_skip_input() {
    void *var_r31;
    s32 var_r30;

    if (TAdEndText__sub_8001B41C() != 0) {
        if ((TLobby::run_disk_error_check() == 0) || (is_playback_finished__6TMovieFv(this->m_20) != 0) || (func_801A5E54__Fv() != 0)) {
            if ((TLobby::run_disk_error_check() == 0) || (func_801A5E54__Fv() != 0)) {
                fn_801449F0();
            }
            return 1;
        }
        goto block_return0;
    }
    switch (get_opening_movie_purpose()) {
    case 0:
        var_r31 = controller_physical_port_bank + 0x20;
        if (TWindowShortListCtrl__check_controller_button(var_r31, 4) != 0) goto block_fn_8000F91C;
        if (TWindowShortListCtrl__check_controller_button(var_r31, 2) != 0) goto block_fn_8000F91C;
        if (TWindowShortListCtrl__check_controller_button(var_r31, 0x400) != 0) goto block_fn_8000F91C;
        if (TWindowShortListCtrl__check_controller_button(var_r31, 0x200) != 0) goto block_fn_8000F91C;
        if (TWindowShortListCtrl__check_controller_button(var_r31, 8) != 0) goto block_fn_8000F91C;
        if (TWindowShortListCtrl__check_controller_button(var_r31, 0x10) != 0) goto block_fn_8000F91C;
        if (TWindowShortListCtrl__check_controller_button(var_r31, 0x20) != 0) goto block_fn_8000F91C;
        if (TWindowShortListCtrl__check_controller_button(var_r31, 0x40) != 0) goto block_fn_8000F91C;
        if (TWindowShortListCtrl__check_controller_button(var_r31, 0x80) != 0) goto block_fn_8000F91C;
        if (TWindowShortListCtrl__check_controller_button(var_r31, 0x20000) != 0) goto block_fn_8000F91C;
        if (TWindowShortListCtrl__check_controller_button(var_r31, 0x10000) != 0) goto block_fn_8000F91C;
        var_r31 = controller_input_state + 0x160;
        if (test_flag_4c__23TAdSinglePlyChrSelectGCFv(var_r31, 4) != 0) goto block_fn_8000F91C;
        if (test_flag_4c__23TAdSinglePlyChrSelectGCFv(var_r31, 2) != 0) goto block_fn_8000F91C;
        if (TLobby::run_disk_error_check() == 0) goto block_fn_8000F91C;
        if (TKeyBoardControl::check_reset_button() != 0) goto block_fn_8000F91C;
        if (is_playback_finished__6TMovieFv(this->m_20) == 0) goto block_return0;
block_fn_8000F91C:
        TKeyBoardControl__sub_8000F91C(9);
        return 1;
    case 1:
        var_r30 = 0;
        if (TKeyBoardControl::check_reset_button() != 0) {
            var_r30 = 1;
        }
        var_r31 = controller_physical_port_bank + 0x20;
        if (TWindowShortListCtrl__check_controller_button(var_r31, 2) != 0) goto block_call_func;
        if (TWindowShortListCtrl__check_controller_button(var_r31, 8) != 0) goto block_call_func;
        var_r31 = controller_input_state + 0x160;
        if (test_flag_4c__23TAdSinglePlyChrSelectGCFv(var_r31, 4) != 0) goto block_call_func;
        if (test_flag_4c__23TAdSinglePlyChrSelectGCFv(var_r31, 2) != 0) goto block_call_func;
        if (TLobby::run_disk_error_check() == 0) goto block_call_func;
        if (var_r30 != 0) goto block_call_func;
        if (is_playback_finished__6TMovieFv(this->m_20) == 0) goto block_return0;
block_call_func:
        if ((func_801A5E54__Fv() != 0) || (var_r30 != 0)) {
            activate_main_menu_scene();
        }
        return 1;
    }
block_return0:
    return 0;
}

struct TMovie_80144910 {
    s32 name;
    u8 pad4[0x14];
    void *vt;
    u8 *obj1C;
    u8 *obj20;
    char path[0x20];
    s32 f44;
    s32 f48;
};

struct VBase_18_a28850 { char pad[0x18]; };

struct VObj_18_a28850 : VBase_18_a28850 {
    virtual void m0();
    virtual s32 m1();
    virtual s32 m2();
};

void run_task__6TMovieFv(TMovie *movie) {
    VObj_18_a28850 *txt;
    u8 *p;
    if (movie->m_1c == 0 || movie->m_20 == 0) {
        queue_destruction__7TObjectFv(movie);
        return;
    }
    render_tick();
    render_tick();
    TMovie::calc_frame_buffer_size((s32)((void *)video_initial_display_framebuffer), (s32)((void *)video_initial_draw_framebuffer));
    txt = NULL;
    if (TAdEndText__sub_8001B41C() != 0) {
        p = __nw__7TObjectFUl(0x197C);
        if (p != NULL) {
            p = __ct__10TAdEndTextFv(p, movie);
        }
        txt = (VObj_18_a28850 *)p;
    }
    for (;;) {
        if (movie->check_skip_input() != 0) {
            break;
        }
        func_803DCDFC__Fv();
        controller_stuff();
        TKeyBoardControl::update_input_frame();
        ((TMovie *)(movie->m_20))->decode_frame();
        if (*(s32 *)&movie->m_48 != 0) {
            ((TMovie *)(movie->m_20))->update_stop();
            TMovie::run_callback();
        } else {
            Vec_80144778 eye = lbl_8043F2E8;
            Vec_80144778 at = lbl_8043F2F4;
            Vec_80144778 up = lbl_8043F300;
            set_perspective_projection_from_fov(0x4B, 1.1333334f, 1.0f, 21000.0f);
            set_camera_look_at((u8 *)&eye, (u8 *)&at, (u8 *)&up);
            ((TMovie *)(movie->m_20))->update_stop();
            if (txt != NULL) {
                txt->m1();
                txt->m2();
            }
            render_tick();
        }
    }
    queue_destruction__7TObjectFv(movie);
}

TMovie::TMovie(TObject *parent, s8 *name, s32 a3, s32 a4, s32 a5) : TObject(parent) {
    u8 *p;
    ((TMovie_80144910 *)this)->name = TMovie__name;
    ((TMovie_80144910 *)this)->f44 = a3;
    ((TMovie_80144910 *)this)->obj1C = 0;
    ((TMovie_80144910 *)this)->f48 = a4;
    ((TMovie_80144910 *)this)->obj20 = 0;
    strncpy(((TMovie_80144910 *)this)->path, (const char *)name, 0x20);
    p = (u8 *)::operator new(8);
    if (p != 0) {
        p = load_rel_module(p, (s32)"movie.rel");
    }
    ((TMovie_80144910 *)this)->obj1C = p;
    p = (u8 *)::operator new(0xD0);
    if (p != 0) {
        p = initialize_movie_with_soundtrack(p, name, ((TMovie_80144910 *)this)->f48, (u8)!((TMovie_80144910 *)this)->f48, a5);
    }
    ((TMovie_80144910 *)this)->obj20 = p;
}

int get_opening_movie_selector(void) { return opening_movie_selector; }

void activate_main_menu_scene(void) { main_menu_scene_active_flag = 1; }

void fn_801449F0(void) { ending_movie_active_flag = 1; }
