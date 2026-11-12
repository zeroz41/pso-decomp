#ifndef PSO_SYSTEM_MOVIE_TMOVIE_H
#define PSO_SYSTEM_MOVIE_TMOVIE_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TMovie : public TObject {
    TMovie(TObject *parent, s8 *name, s32 a3, s32 a4, s32 a5);
    virtual ~TMovie();
    virtual void run_task();
    u32 m_1c;
    u32 m_20;
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
    static void calc_frame_buffer_size(s32 arg0, s32 arg1);
    s32 stop_if_advanced();
    s32 check_finished();
    bool is_playback_finished();
    void update_stop();
    void release();
    void init_sfd_player(s32 arg1, s32 arg2);
    s32 decode_frame();
    void copy(void* q);
    void free_buffer();
    void render_until_finished();
    s32 check_skip_input();
    static void run_callback();
};

typedef char TMovie_size[sizeof(TMovie) == 0x4C ? 1 : -1];

extern "C" {
s32 close__6TMovieFis(s32 arg0, s16 arg1);
void *__dt__6TMovieFv(TMovie *arg0, s16 arg1);
}

#endif
