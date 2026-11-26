#ifndef PSO_SYSTEM_MOVIE_TMOVIE_H
#define PSO_SYSTEM_MOVIE_TMOVIE_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct RelModuleBuffer;
struct MovieState;

// A movie task: loads movie.rel (CRI Sofdec), plays one SFD file through a MovieState and calls
// finish_callback with itself when it is destroyed.
struct TMovie : public TObject {
    static const char *class_name;
    TMovie(TObject *parent, s8 *filename, void (*finish_callback)(TMovie *), s32 movie_mode, s32 is_normal_ending);
    virtual ~TMovie();
    virtual void run_task();
    RelModuleBuffer *module;
    MovieState *player;
    char filename[0x20];
    void (*finish_callback)(TMovie *);
    s32 movie_mode;  // nonzero: the opening, shown straight in the frame buffer; 0: the ending
    void render_until_finished();
    s32 check_skip_input();
};

LAYOUT_ASSERT(TMovie_size, sizeof(TMovie) == 0x4C);

// CRI Sofdec player handle (mwPlyCreateSofdec result): calls go through its interface table.
struct MwsfdPly;
struct MwsfdPlyVtbl {
    u8 pad_00[0x14];
    void (*destroy)(MwsfdPly *ply);
    void (*start_fname)(MwsfdPly *ply, const char *filename);
    u8 pad_1C[0x20 - 0x1C];
    s32 (*get_status)(MwsfdPly *ply);
    u8 pad_24[0x2C - 0x24];
    void (*f2C)(MwsfdPly *ply, s32 value);
};
struct MwsfdPly {
    MwsfdPlyVtbl *vt;
};

// mwPlyGetStat: the stream has played to its end.
enum { MWSFD_STAT_PLAYEND = 3 };

// Sofdec's init parameters (MwsfdInitPrm) for mwPlyInitSfdFx.
struct MovieFrameRate {
    f32 vsync_hz;
    s32 display_cycle;
    s32 display_latency;
    s32 decode_server;
};

// Sofdec's player create parameters (MwsfdCrePrm) for mwPlyCreateSofdec.
struct MwsfdCrePrm {
    s32 file_type;
    s32 max_bps;
    s32 max_width;
    s32 max_height;
    s32 frame_pool_count;
    s32 pad_14;
    void *work;
    s32 work_size;
};

// The frame mwPlyGetCurFrm hands out (Sofdec's MwsfdFrmObj): the decoded picture and its size.
struct MovieFrameInfo {
    u32 buffer;
    s32 frame_id;
    s32 width;
    s32 height;
    u32 pad_10[12];
    void copy(MovieFrameInfo *src);
};

// One Sofdec playback: the player handle, its parameters and the 0x420000-byte work buffer.
struct MovieState {
    s32 pad_00;
    MwsfdPly *handle;
    MovieFrameRate init_params;
    u8 pad_18[0x28 - 0x18];
    MwsfdCrePrm create_params;
    s32 pad_48;
    u8 pad_4C[0x58 - 0x4C];
    s32 status;  // mwPlyGetStat of the last decoded frame
    MovieFrameInfo frame;
    void *buffer;
    void *work;
    char filename[0x20];
    s32 pad_C4;
    s32 pad_C8;
    s32 movie_mode;

    MovieState(s8 *filename, s32 movie_mode, s32 is_ending, s32 is_normal_ending);
    ~MovieState();
    void init(const s8 *filename);
    s32 stop_if_advanced();
    s32 check_finished();
    s32 is_playback_finished();
    void update_stop();
    void release();
    void init_sfd_player(s32 is_ending, s32 is_normal_ending);
    s32 decode_frame();
    void free_buffer();
};

LAYOUT_ASSERT(MovieState_frame, offsetof(MovieState, frame) == 0x5C);
LAYOUT_ASSERT(MovieState_size, sizeof(MovieState) == 0xD0);

// The movie frame-buffer helpers: double-buffered XFB flips driven by VI retrace.
void flush_cache();
void flip_frame_buffer();
void flush_and_reset();
void calc_frame_buffer_size(saddr fb_a, saddr fb_b);
void set_pending_movie_frame(u32 frame_addr, s32 width, s32 height);
void flush_framebuffer(MovieState *movie, MwsfdPly *ply, MovieFrameInfo *frame);

// Planes of one decoded movie frame, filled by the decoder callback that
// flip_frame_buffer() calls (from pack_movie_frame's use:
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
