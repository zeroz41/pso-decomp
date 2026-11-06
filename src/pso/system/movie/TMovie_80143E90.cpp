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

extern "C" void TMovie__sub_80144324(MovieState *movie, const s8 *name);

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
