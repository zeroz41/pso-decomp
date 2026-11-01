#include "pso/math/FloatRounding.h"
#include "types.h"
#include "pso/misc/TChCrLoadAfs.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/unk/text_803CC294.h"
#include "pso/TChCrLoadAfs.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TQuestVmDownLoadServer.h"

extern "C" {

void release_load_slot__12TChCrLoadAfsFv(void *arg0);

int TChCrLoadAfs::is_unloaded() { return *(u32*)((char*)this + 0x4a8) == 0; }

extern s32 chcr_load_afs_busy_flag;

void TChCrLoadAfs::release_load_slot() {
    if ((s32) *(s32 *)((s8 *)this + 0x30) != 0) {
        if ((s32) chcr_load_afs_busy_flag == 0) {
            *(s32 *)((s8 *)this + 0x2C) = 3;
            return;
        }
        *(s32 *)((s8 *)this + 0x30) = 0;
        chcr_load_afs_busy_flag = 0;
    }
}

s32 try_begin_load__12TChCrLoadAfsFPv(void *arg0) {
    if ((s32) *(s32 *)((s8 *)arg0 + 0x30) != 0) {
        *(s32 *)((s8 *)arg0 + 0x2C) = 3;
        return 0;
    }
    if ((s32) chcr_load_afs_busy_flag != 0) {
        return 0;
    }
    *(s32 *)((s8 *)arg0 + 0x30) = 1;
    chcr_load_afs_busy_flag = 1;
    return 1;
}

}

#define try_begin_load__12TChCrLoadAfsFPv (*(s32 (*)())&try_begin_load__12TChCrLoadAfsFPv)
#define release_load_slot__12TChCrLoadAfsFv (*(void (*)(void *))&release_load_slot__12TChCrLoadAfsFv)

struct L_8028B948 { u8 pad[0x1c]; s32 f1c; u8 pad2[0xc]; s32 f2c; };

extern "C" {
s32 TLobby__sub_803CC4C0(int);
void close_adxf_handle__6TLobbyFv(int);
void poll_load__12TChCrLoadAfsFv(L_8028B948 *arg0);
u32 adxf_open_afs__6TLobbyFii(s32, s32);

void sub_8028B940__12TChCrLoadAfsFv(void) {  }
void sub_8028B944__12TChCrLoadAfsFv(void) {  }
void poll_load__12TChCrLoadAfsFv(L_8028B948 *arg0) {
    switch (TLobby__sub_803CC4C0(arg0->f1c)) {
    case 2:
        return;
    case 3:
        close_adxf_handle__6TLobbyFv(arg0->f1c);
        arg0->f1c = 0;
        break;
    case 1:
    default:
        arg0->f2c = 3;
        return;
    }
    release_load_slot__12TChCrLoadAfsFv(arg0);
    arg0->f2c = 2;
}

}

#undef release_load_slot__12TChCrLoadAfsFv
#undef try_begin_load__12TChCrLoadAfsFPv

#define try_begin_load__12TChCrLoadAfsFPv (*(s32 (*)())&try_begin_load__12TChCrLoadAfsFPv)
#define release_load_slot__12TChCrLoadAfsFv (*(int (*)(void *))&release_load_slot__12TChCrLoadAfsFv)
#define close_adxf_handle__6TLobbyFv (*(int (*)(int))&close_adxf_handle__6TLobbyFv)
#define TLobby__sub_803CC4C0 (*(int (*)(int))&TLobby__sub_803CC4C0)

struct Te_8028BFA4 { s32 id; u8 pad[0xC]; };

struct Cl_8028BFA4 { u8 pad0[0x20]; s32 f20; s32 f24; u8 pad28[4]; s32 f2c; u8 pad30[8]; void *bufs[8]; s32 f58; s32 f5c; s32 f60; u8 pad64[8]; s32 f6c; s32 f70; };

struct Ent_8028BE00 { u8 pad[0xC]; };

struct List_8028BE00 { Ent_8028BE00 *ents; };

struct Rect_8028BE00 { u8 pad[0x24]; };

struct Ld_8028BE00 {
    u8 pad0[0x1C];
    s32 f1c;
    s32 f20;
    s32 f24;
    u8 pad28[4];
    s32 f2c;
    List_8028BE00 *f30;
    u8 pad34[4];
    s32 bufs[8];
    s32 f58;
    s32 f5c;
    s32 f60;
    u8 pad64[0x10];
    Rect_8028BE00 rects[8];
};

extern "C" {
extern Te_8028BFA4 player_class_texture_archive_table[];
f32 TLobby__sub_8028C50C(f32);
s32 strcmp(const char *, const char *);
extern const f32 lbl_805DD920;
void set_texture_name(void *, void *, s32, s32);
s32 load_texture_list(void *);
void *__ct__12TChCrLoadAfsFP7TObjectPvPv(void *arg0, void *arg1, void *arg2, void *arg3);
void *__nw__7TObjectFUl(int);

void TChCrLoadAfs::start_download() {
    s32 count;
    u32 temp_r3;
    u32 temp_r3_3;

    if (try_begin_load__12TChCrLoadAfsFPv() != 0) {
        temp_r3 = adxf_open_afs__6TLobbyFii(*(s32 *)((s8 *)this + 0x20), *(s32 *)((s8 *)this + 0x24));
        *(u32 *)((s8 *)this + 0x1C) = temp_r3;
        if (temp_r3 == 0U) {
            *(s32 *)((s8 *)this + 0x2C) = 3;
            return;
        }
        count = TLobby__sub_803CC53C((u8 *)(*(u32 *)((s8 *)this + 0x1C)));
        temp_r3_3 = (s32)TQuestVmDownLoadServer::alloc(count << 0xB);
        *(u32 *)((s8 *)this + 0x28) = temp_r3_3;
        if (temp_r3_3 == 0U) {
            *(s32 *)((s8 *)this + 0x2C) = 3;
            return;
        }
        TLobby::read_checked_align(*(u32 *)((s8 *)this + 0x1C), count, *(u32 *)((s8 *)this + 0x28));
        *(s32 *)((s8 *)this + 0x2C) = 1;
    }
}
}

#include "pso/misc/TChCrLoadAfsTextureReq.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

class Afs_8028BA64 {
public:
    u8 pad[0x2C];
    s32 state;
    u8 pad2[0x34 - 0x30];
    s32 wait;
};

typedef void (TChCrLoadAfs::*Handler_8028BA64)();

s32 chcr_load_afs_busy_flag;

void TChCrLoadAfs::run_task() {
    Afs_8028BA64 *arg0 = (Afs_8028BA64 *)this;
    if (--arg0->wait < 0) {
        arg0->state = 3;
        return;
    }
    static Handler_8028BA64 tbl[] = {
        &TChCrLoadAfs::start_download,
        &TChCrLoadAfs::poll_load,
        &TChCrLoadAfs::sub_8028B944,
        &TChCrLoadAfs::sub_8028B940,
    };
    (this->*tbl[arg0->state])();
}

TChCrLoadAfs::~TChCrLoadAfs() {
    u32 handle = load_handle;
    if (handle != 0) {
        if (TLobby__sub_803CC4C0((int)handle) == 2) ((TLobby *)load_handle)->adxf_stop();
        close_adxf_handle__6TLobbyFv((int)load_handle);
        load_handle = 0;
    }
    u32 buffer = buffer_address;
    if (buffer != 0) {
        TAdSinglePlyChrSelectGC::safe_free((int)buffer);
        buffer_address = 0;
    }
    release_load_slot__12TChCrLoadAfsFv(this);
}

extern void *lbl_805D3B48;
TChCrLoadAfs::TChCrLoadAfs(TObject *object, void *arg2, void *arg3) : TObject(object) {
    *(void **)((s8 *)this + 0x0) = lbl_805D3B48;
    *(u32 *)((s8 *)this + 0x1C) = 0;
    *(void **)((s8 *)this + 0x20) = arg2;
    *(void **)((s8 *)this + 0x24) = arg3;
    *(u32 *)((s8 *)this + 0x28) = 0;
    *(u32 *)((s8 *)this + 0x2C) = 0;
    *(u32 *)((s8 *)this + 0x30) = 0;
    *(u32 *)((s8 *)this + 0x34) = 900;
}

void *TChCrLoadAfs::create(void *arg1, void *arg2) {
    void *o;
    o = __nw__7TObjectFUl(0x38);
    if (o != NULL) {
        o = __ct__12TChCrLoadAfsFP7TObjectPvPv(o, this, arg1, arg2);
    }
    return o;
}

s32 find_player_texture_name_ordinal(u8 *object) {
    char *name;
    s32 count;
    s32 steps;
    s32 mid;
    s32 step;
    char **list;
    s32 i;
    f32 l2;
    s32 r;
    name = *(char **)(**(u8 ***)((s8 *)object + 0x30) + *(s32 *)((s8 *)object + 0x5C) * 0xC);
    count = (&player_class_texture_archive_table[*(s32 *)((s8 *)object + 0x70)].id)[1];
    l2 = TLobby__sub_8028C50C(lbl_805DD920);
    steps = (s32)ceil_to_float(TLobby__sub_8028C50C(count) / l2) + 1;
    mid = (count + 1) >> 1;
    step = (mid + 1) >> 1;
    list = (char **)(&player_class_texture_archive_table[*(s32 *)((s8 *)object + 0x70)].id)[3];
    for (i = 0; i < steps; i++) {
        r = strcmp(name + 3, list[mid] + 3);
        if (r == 0) {
            return mid;
        }
        if (r < 0) {
            mid -= step;
            if (mid < 0) {
                mid = 0;
            }
        } else {
            mid += step;
            if (mid >= count) {
                mid = count - 1;
            }
        }
        step = (step + 1) >> 1;
        if (step < 1) {
            step = 1;
        }
    }
    queue_destruction__7TObjectFv(object);
    return 0;
}

void TChCrLoadAfsTextureReq::update_loading(void *) {
    Ld_8028BE00 *arg0 = (Ld_8028BE00 *)this;
    s32 retry;
    s32 i;
    retry = 0;
    switch (TLobby__sub_803CC4C0(arg0->f60)) {
    case 1:
        if (++arg0->f20 >= 3) {
            return;
        }
        retry = 1;
        break;
    case 2:
        if (++arg0->f24 >= 150) {
            retry = 1;
            break;
        }
        return;
    case 3:
        break;
    default:
        return;
    }
    if (retry != 0) {
        close_adxf_handle__6TLobbyFv(arg0->f60);
        arg0->f60 = 0;
        TAdSinglePlyChrSelectGC::safe_free(arg0->bufs[arg0->f5c]);
        arg0->bufs[arg0->f5c] = 0;
        arg0->f2c = 1;
        return;
    }
    close_adxf_handle__6TLobbyFv(arg0->f60);
    arg0->f60 = 0;
    if (++arg0->f5c != arg0->f58) {
        arg0->f2c = 1;
        return;
    }
    for (i = 0; i < arg0->f58; i++) {
        ((TObjPlayer *)(&arg0->rects[i]))->set_render_rect(arg0->bufs[i], 0, 0, 0);
        set_texture_name(&arg0->f30->ents[i], &arg0->rects[i], 0, 0x40000000);
    }
    if (load_texture_list(arg0->f30) != -1) {
        arg0->f1c = 1;
        queue_destruction__7TObjectFv(arg0);
    }
}

void TChCrLoadAfsTextureReq::start_read(void *) {
    Cl_8028BFA4 *arg0 = (Cl_8028BFA4 *)this;
    s32 n;
    u32 t;
    void *buf;
    t = adxf_open_afs__6TLobbyFii(player_class_texture_archive_table[arg0->f70].id, find_player_texture_name_ordinal((u8 *)arg0));
    arg0->f60 = t;
    if (t != 0) {
        arg0->f20 = 0;
        arg0->f24 = 0;
        n = TLobby__sub_803CC53C((u8 *)arg0->f60);
        buf = ((void *)TQuestVmDownLoadServer::alloc(n << 11));
        arg0->bufs[arg0->f5c] = buf;
        if (buf != NULL) {
            TLobby::read_checked_align((u32)arg0->f60, (s32)n, (u32)arg0->bufs[arg0->f5c]);
            arg0->f2c = 2;
        }
    }
}

#undef TLobby__sub_803CC4C0
#undef close_adxf_handle__6TLobbyFv
#undef release_load_slot__12TChCrLoadAfsFv
#undef try_begin_load__12TChCrLoadAfsFPv
