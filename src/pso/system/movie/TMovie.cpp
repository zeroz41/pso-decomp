#include "pso/system/RelModuleBuffer.h"
#include "pso/ui/keyboard/SystemBootInit.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/render/gjSystem.h"
#include "pso/render/GinjaView.h"
#include <stddef.h>
#include <string.h>
#include "pso/system/movie/TMovie.h"
#include "pso/network/TLobby.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/CameraCapture.h"
#include "pso/system/memory.h"
#include "pso/system/main_loop.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/system/TLoadCtrl_80227390.h"
#include "pso/ui/frontend/TAdEndText.h"
#include "pso/system/ControllerInput.h"
#include "pso/system/task/TObject.h"
#include "pso/unk/text_80320358.h"
#include "pso/ui/frontend/EndingSequence.h"

int get_opening_movie_selector(void);
void activate_main_menu_scene(void);
extern "C" {
void fn_801449F0(void);

s32 DVDCheckDisk();
}
extern "C" {
s8 get_opening_movie_purpose();
}

extern int opening_movie_selector;
extern unsigned char main_menu_scene_active_flag;

const char *TMovie::name = "TMovie";
// The eye, target and up of the view a movie plays in.
static const Vec movie_camera_eye = {0.0f, 0.0f, 0.0f};
static const Vec movie_camera_target = {0.0f, 0.0f, 1.0f};
static const Vec movie_camera_up = {0.0f, 1.0f, 0.0f};

MovieState::~MovieState() {
    release();
    free_buffer();
    TLobby::stop_audio_streams();
}

MovieState::MovieState(s8 *filename, s32 movie_mode, s32 is_ending, s32 is_normal_ending) {
    this->movie_mode = movie_mode;
    pad_00 = 0;
    init(filename);
    init_sfd_player(is_ending, is_normal_ending);
    if (is_ending != 0) {
        play_area_music("CUBE_ENDING.adx");
    } else if ((get_opening_movie_purpose() == 0) && (get_opening_movie_selector() == 1)) {
        play_area_music("CUBE_OPENING.adx");
    } else {
        play_area_music("OPENING.ADX");
    }
}

s32 MovieState::stop_if_advanced() {
    if (status >= 2) {
        draw_screen_quad(-1, 0, 0.0f);
    }
    return 1;
}

s32 MovieState::check_finished() {
    if (status >= 2) {
        TMovie::flip_frame_buffer();
    }
    return 1;
}

s32 MovieState::is_playback_finished() {
    if (handle->vt->get_status(handle) == MWSFD_STAT_PLAYEND) {
        return 1;
    }
    return 0;
}

void MovieState::update_stop() {
    if (movie_mode != 0) {
        check_finished();
        return;
    }
    stop_if_advanced();
}

void MovieState::release() {
    handle->vt->destroy(handle);
    handle = NULL;
}

void MovieState::init_sfd_player(s32 is_ending, s32 is_normal_ending) {
    MwsfdCrePrm *params = &create_params;
    MwsfdPly *ply;

    work = buffer;
    pad_48 = 0x11;
    if (is_ending != 0) {
        params->file_type = 1;
    } else {
        params->file_type = 2;
    }
    params->max_bps = 6000000;
    params->max_width = 640;
    params->max_height = 480;
    params->frame_pool_count = 3;
    params->work_size = mwPlyCalcWorkCprmSfd_hook(params);
    if (params->work_size > 0x420000) {
        return;
    }
    params->work = work;
    params->pad_14 = 1;
    ply = mwPlyCreateSofdec_hook(params);
    handle = ply;
    if (is_ending != 0) {
        if (is_normal_ending != 0) {
            mwPlyEntryFname_hook(ply, "ending_normal.sfd");
        } else {
            mwPlyEntryFname_hook(ply, "ult01.sfd");
            mwPlyEntryFname_hook(ply, "ult02.sfd");
            mwPlyEntryFname_hook(ply, "ult03.sfd");
            mwPlyEntryFname_hook(ply, "ult03.sfd");
            mwPlyEntryFname_hook(ply, "ult03.sfd");
            mwPlyEntryFname_hook(ply, "ult04.sfd");
        }
        mwPlyStartSeamless_hook(ply);
        mwPlyReleaseSeamless_hook(ply);
    } else {
        ply->vt->start_fname(ply, filename);
    }
    ply->vt->f2C(ply, TLobby::get_lobby_data());
}

s32 MovieState::decode_frame() {
    MovieFrameInfo current;
    s32 stat;

    if (movie_mode != 0) {
        TMovie::flush_and_reset();
    }
    mwPlyGetCurFrm_hook(handle, &current);
    if (current.buffer != 0U) {
        if (movie_mode != 0) {
            set_pending_movie_frame(current.buffer, current.width, current.height);
        } else {
            flush_framebuffer(this, handle, &current);
        }
        frame.copy(&current);
        mwPlyRelCurFrm_hook(handle);
    }
    stat = handle->vt->get_status(handle);
    if (stat == MWSFD_STAT_PLAYEND) {
        return 0;
    }
    status = stat;
    return 1;
}

void MovieFrameInfo::copy(MovieFrameInfo *src) {
    buffer = src->buffer;
    frame_id = src->frame_id;
    width = src->width;
    height = src->height;
    pad_10[0] = src->pad_10[0];
    pad_10[1] = src->pad_10[1];
    pad_10[2] = src->pad_10[2];
    pad_10[3] = src->pad_10[3];
    pad_10[4] = src->pad_10[4];
    pad_10[5] = src->pad_10[5];
    pad_10[6] = src->pad_10[6];
    pad_10[7] = src->pad_10[7];
    pad_10[8] = src->pad_10[8];
    pad_10[9] = src->pad_10[9];
    pad_10[10] = src->pad_10[10];
    pad_10[11] = src->pad_10[11];
}

void MovieState::free_buffer() {
    if (buffer != NULL) {
        xfree(buffer);
        buffer = NULL;
    }
    mwPlyFinishSfdFx_hook();
    reset_and_release_capture_texture();
}

void MovieState::init(const s8 *filename) {
    reset_movie_state();
    memset(&handle, 0, 0xC8);
    buffer = xmalloc(0x420000);
    handle = NULL;
    pad_C8 = 1;
    pad_C4 = 0;
    strcpy(this->filename, (const char *)filename);
    init_params.vsync_hz = 59.94f;
    init_params.display_cycle = 1;
    init_params.display_latency = 2;
    init_params.decode_server = 0;
    mwPlyInitSfdFx_hook(&init_params);
}

TMovie::~TMovie() {
    this->render_until_finished();
    render_tick();
    if (player != NULL) {
        delete player;
        player = NULL;
    }
    render_tick();
    render_tick();
    RelModuleBuffer *loaded = module;
    if (loaded != NULL) {
        destroy_rel_module(loaded, 1);
        module = NULL;
    }
    render_tick();
    if (finish_callback != NULL) {
        finish_callback(this);
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
        if ((TLobby::run_disk_error_check() == 0) || (this->player->is_playback_finished() != 0) || (static_cast<s8>(poll_reset_request()) != 0)) {
            if ((TLobby::run_disk_error_check() == 0) || (static_cast<s8>(poll_reset_request()) != 0)) {
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
        if ((static_cast<s8>(poll_reset_request()) != 0) || (var_r30 != 0)) {
            activate_main_menu_scene();
        }
        return 1;
    }
block_return0:
    return 0;
}

void TMovie::run_task() {
    TAdEndText *txt;
    if (this->module == NULL || this->player == NULL) {
        this->queue_destruction();
        return;
    }
    render_tick();
    render_tick();
    TMovie::calc_frame_buffer_size((saddr)video_initial_display_framebuffer, (saddr)video_initial_draw_framebuffer);
    txt = NULL;
    if (is_ending_sequence_active() != 0) {
        txt = new TAdEndText(this);
    }
    for (;;) {
        if (this->check_skip_input() != 0) {
            break;
        }
        begin_gx_frame();
        controller_stuff();
        TKeyBoardControl::update_input_frame();
        this->player->decode_frame();
        if (movie_mode != 0) {
            this->player->update_stop();
            run_frame_update_callback();
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

TMovie::TMovie(TObject *parent, s8 *filename, void (*finish_callback)(TMovie *), s32 movie_mode, s32 is_normal_ending) : TObject(parent) {
    m_name = TMovie::name;
    this->finish_callback = finish_callback;
    module = NULL;
    this->movie_mode = movie_mode;
    player = NULL;
    strncpy(this->filename, (const char *)filename, 0x20);
    RelModuleBuffer *loaded = new RelModuleBuffer;
    if (loaded != NULL) {
        loaded = load_rel_module(loaded, "movie.rel");
    }
    module = loaded;
    player = new MovieState(filename, this->movie_mode, (u8)!this->movie_mode, is_normal_ending);
}

int get_opening_movie_selector(void) { return opening_movie_selector; }

void activate_main_menu_scene(void) { main_menu_scene_active_flag = 1; }

void fn_801449F0(void) { ending_movie_active_flag = 1; }
