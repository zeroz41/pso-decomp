#ifndef PSO_SYSTEM_MOVIE_TMOVIE_H
#define PSO_SYSTEM_MOVIE_TMOVIE_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct RelModuleBuffer;

struct TMovie : public TObject {
    TMovie(TObject *parent, s8 *filename, s32 movie_id, s32 movie_mode, s32 audio_mode);
    virtual ~TMovie();
    virtual void run_task();
    RelModuleBuffer *module;
    TMovie *player; // 0x20: the 0xD0-byte player initialize_movie_with_soundtrack builds (inferred)
    void* m_24;
    u8 unk_28[0x4];
    u32 m_2c;
    u8 unk_30[0x4];
    u32 m_34;
    u8 unk_38[0x4];
    u32 m_3c;
    u8 unk_40[0x4];
    u32 m_44;
    u32 m_48;
    static void flush_cache();
    static void flip_frame_buffer();
    static void flush_and_reset();
    static void calc_frame_buffer_size(saddr fb_a, saddr fb_b);
    s32 stop_if_advanced();
    s32 check_finished();
    s32 is_playback_finished();
    void update_stop();
    void release();
    void init_sfd_player(s32 is_ending, s32 is_normal_ending);
    s32 decode_frame();
    void copy(void *src_frame);
    void free_buffer();
    void render_until_finished();
    s32 check_skip_input();
    static void run_callback();
    static TMovie *close(TMovie *movie, short dealloc);
};

LAYOUT_ASSERT(TMovie_size, sizeof(TMovie) == 0x4C);

u8 *initialize_movie_with_soundtrack(u8 *state_buf, s8 *filename, s32 movie_mode, s32 is_ending, s32 is_normal_ending);

// Planes of one decoded movie frame, filled by the decoder callback that
// TMovie::flip_frame_buffer() calls (inferred from pack_movie_frame's use:
// three 8-bit planes Y, U, V and their pitches in bytes).
struct MovieFramePlanes {
    u32 *y;
    u32 *u;
    u32 *v;
    u32 y_pitch;
    u32 uv_pitch;
};

extern void *movie_current_frame_buffer;
extern s32 movie_pending_frame_width;
extern s32 movie_pending_frame_height;

void pack_movie_frame(MovieFramePlanes *planes);
void wait_for_movie_retrace();

#endif
