#include "types.h"
#include "pso/system/main_loop.h"
#include "pso/misc/TMovie.h"
#include "pso/misc/TKeyBoardControl.h"

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

struct Vec_80144778 { s32 x, y, z; };

extern "C" {
u8 *load_rel_module(u8 *arg0, s32 arg1);
char *strncpy(char *, const char *, u32);
extern u8 lbl_8043F380[];
extern s32 TMovie__name;
void queue_destruction__7TObjectFv(void *arg0);
u8 *__ct__10TAdEndTextFv(void *, void *);
s32 TAdEndText__sub_8001B41C();
u8 *__nw__7TObjectFUl(s32);
}
u8 *initialize_movie_with_soundtrack(u8 *arg0, s8 *arg1, s32 arg2, s32 arg3, s32 arg4);
void set_camera_look_at(u8 *eye, u8 *target, u8 *up);
extern "C" {
void set_perspective_projection_from_fov(s32 arg0, f32 farg0, f32 farg1, f32 farg2);
void func_803DCDFC__Fv(void);
extern Vec_80144778 lbl_8043F2E8;
extern Vec_80144778 lbl_8043F2F4;
extern Vec_80144778 lbl_8043F300;
extern s32 video_initial_draw_framebuffer;
extern s32 video_initial_display_framebuffer;
extern const f32 lbl_805DB180;
extern const f32 lbl_805DB184;
extern const f32 lbl_805DB188;
void run_task__6TMovieFv(TMovie *arg0);

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
            set_perspective_projection_from_fov(0x4B, lbl_805DB180, lbl_805DB184, lbl_805DB188);
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
        p = load_rel_module(p, (s32)lbl_8043F380);
    }
    ((TMovie_80144910 *)this)->obj1C = p;
    p = (u8 *)::operator new(0xD0);
    if (p != 0) {
        p = initialize_movie_with_soundtrack(p, name, ((TMovie_80144910 *)this)->f48, (u8)!((TMovie_80144910 *)this)->f48, a5);
    }
    ((TMovie_80144910 *)this)->obj20 = p;
}
extern "C" {

    extern int opening_movie_selector;
int get_opening_movie_selector(void) {  return opening_movie_selector; }

    extern unsigned char main_menu_scene_active_flag;
void activate_main_menu_scene(void) { main_menu_scene_active_flag = 1; }

    extern int ending_movie_active_flag;
void fn_801449F0(void) { ending_movie_active_flag = 1; }

}
