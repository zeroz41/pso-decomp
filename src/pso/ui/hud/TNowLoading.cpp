#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/ui/hud/TLoadingCur.h"
#include "pso/ui/frontend/TAdLoadNetworkGC.h"
#include "pso/render/render_util.h"
#include "pso/unk/TLobby_8001D6A0.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/vector.h"

#include <stddef.h>
#include "pso/unk/TLobby.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/task/TObject.h"

typedef struct Cam_8001D3A8 {
    Vec eye;
    Vec dir;
    u8 pad18[0x10];
} Cam_8001D3A8;

typedef struct TNowLoading_8001D3A8 {
    const char *unk0; // TObject::m_name
    u8 pad4[0x18 - 0x4];
    void *vtable;
    void *children[4];
    Vec pos;
} TNowLoading_8001D3A8;

volatile s32 aram_dma_pending;

extern "C" {
extern f32 lbl_804FF5E8[];
extern u32 camera_ctrl_instance;
void DCInvalidateRange(void *, u32);
void ARQPostRequest(void *, uaddr, u32, u32, uaddr, uaddr, u32, void *);
const char *TNowLoading__class_name = "TNowLoading";
void DCFlushRange(void *, u32);
void TNowLoading__sub_8001D4D0(void);
void TNowLoading__sub_8001D4D4(void);

void TNowLoading::render() {  }

#pragma push
#pragma fp_contract on
void TNowLoading::run_task() {
    Vec stack;
    uaddr temp_r3;
    uaddr temp_r3_2;
    uaddr temp_r3_3;
    uaddr temp_r3_4;
    uaddr temp_r3_5;
    uaddr temp_r3_6;
    uaddr temp_r3_7;
    uaddr temp_r3_8;
    if ((u32) camera_ctrl_instance == 0U) {
        *(f32 *)&this->m_2c = (f32) ((65.0f * *(f32 *)((s8 *)&lbl_804FF5E8 + 0xC)) + *(f32 *)((s8 *)&lbl_804FF5E8 + 0));
        *(f32 *)&this->unk_30 = (f32) ((65.0f * *(f32 *)((s8 *)&lbl_804FF5E8 + 0x10)) + *(f32 *)((s8 *)&lbl_804FF5E8 + 4));
        this->m_34 = (f32) ((65.0f * *(f32 *)((s8 *)&lbl_804FF5E8 + 0x14)) + *(f32 *)((s8 *)&lbl_804FF5E8 + 8));
        temp_r3 = this->m_1c;
        if (temp_r3 != 0U) {
            ((TParticleCtrl *)temp_r3)->set_position((u8 *)&this->m_2c);
        }
        temp_r3_2 = this->m_20;
        if (temp_r3_2 != 0U) {
            ((TParticleCtrl *)temp_r3_2)->set_position((u8 *)&this->m_2c);
        }
        temp_r3_3 = this->m_24;
        if (temp_r3_3 != 0U) {
            ((TParticleCtrl *)temp_r3_3)->set_position((u8 *)&this->m_2c);
        }
        temp_r3_4 = this->m_28;
        if (temp_r3_4 != 0U) {
            ((TParticleCtrl *)temp_r3_4)->set_position((u8 *)&this->m_2c);
        }
    } else {
        stack.x = (65.0f * *(f32 *)((s8 *)&lbl_804FF5E8 + 0xC)) + *(f32 *)((s8 *)&lbl_804FF5E8 + 0);
        stack.y = (65.0f * *(f32 *)((s8 *)&lbl_804FF5E8 + 0x10)) + *(f32 *)((s8 *)&lbl_804FF5E8 + 4);
        stack.z = (65.0f * *(f32 *)((s8 *)&lbl_804FF5E8 + 0x14)) + *(f32 *)((s8 *)&lbl_804FF5E8 + 8);
        temp_r3_5 = this->m_1c;
        if (temp_r3_5 != 0U) {
            ((TParticleCtrl *)temp_r3_5)->set_position((void *)&stack.x);
        }
        temp_r3_6 = this->m_20;
        if (temp_r3_6 != 0U) {
            ((TParticleCtrl *)temp_r3_6)->set_position((void *)&stack.x);
        }
        temp_r3_7 = this->m_24;
        if (temp_r3_7 != 0U) {
            ((TParticleCtrl *)temp_r3_7)->set_position((void *)&stack.x);
        }
        temp_r3_8 = this->m_28;
        if (temp_r3_8 != 0U) {
            ((TParticleCtrl *)temp_r3_8)->set_position((void *)&stack.x);
        }
    }
}
#pragma pop

}
TNowLoading::~TNowLoading() {
    if (*(void **)((s8 *)this + 0x1C) != NULL) { ((TObject *)(*(void **)((s8 *)this + 0x1C)))->queue_destruction(); this->m_1c = 0; }
    if (*(void **)((s8 *)this + 0x20) != NULL) { ((TObject *)(*(void **)((s8 *)this + 0x20)))->queue_destruction(); this->m_20 = 0; }
    if (*(void **)((s8 *)this + 0x24) != NULL) { ((TObject *)(*(void **)((s8 *)this + 0x24)))->queue_destruction(); this->m_24 = 0; }
    if (*(void **)((s8 *)this + 0x28) != NULL) { ((TObject *)(*(void **)((s8 *)this + 0x28)))->queue_destruction(); this->m_28 = 0; }
}


#pragma push
#pragma fp_contract on
#define self ((TNowLoading_8001D3A8 *)this)
TNowLoading::TNowLoading(TObject *parent, Vec *arg2) : TObject(parent) {
    Vec dir;
    s32 out[3];
    Cam_8001D3A8 *cam;
    self->unk0 = TNowLoading__class_name;
    VecCopy((Vec *)&self->pos, (const Vec *)arg2);
    cam = (Cam_8001D3A8 *) &lbl_804FF5E8;
    out[0] = 0;
    out[1] = 0;
    out[2] = 0;
    dir.x = -cam->dir.x;
    dir.y = -cam->dir.y;
    dir.z = -cam->dir.z;
    direction_to_rotation_xz((u8 *)&dir, &out[0], &out[2]);
    self->pos.x = 65.0f * cam->dir.x + *(f32 *)((s8 *)&lbl_804FF5E8 + 0);
    self->pos.y = 65.0f * cam->dir.y + *(f32 *)((s8 *)&lbl_804FF5E8 + 4);
    self->pos.z = 65.0f * cam->dir.z + *(f32 *)((s8 *)&lbl_804FF5E8 + 8);
    self->children[0] = NULL;
    self->children[1] = NULL;
    self->children[2] = NULL;
    self->children[3] = NULL;
    new TAdLoadNetworkGC(this, &self->pos);
    new TLoadingCur(this, &self->pos);
}
#undef self
#pragma pop

void TNowLoading__sub_8001D4D0(void) {  }
void TNowLoading__sub_8001D4D4(void) {  }

s32 TLobby::aram_dma_blocking(s32 owner, s32 aram, saddr dest, s32 length) {
    u8 request[0x20];
    s32 len;
    len = (length + 0x1F) & ~0x1F;
    aram_dma_pending = 1;
    DCInvalidateRange((void *)dest, len);
    ARQPostRequest(request, owner, 1, 1, aram, dest, len, (void *)TLobby__sub_8001D9DC);
    for (;;) {
        if (aram_dma_pending == 0) break;
    }
    DCInvalidateRange((void *)dest, len);
    return 1;
}

s32 TLobby::aram_read_sync(s32 owner, s32 aram, saddr dest, s32 length) {
    u8 request[0x20];
    s32 len;
    len = (length + 0x1F) & ~0x1F;
    aram_dma_pending = 1;
    DCInvalidateRange((void *)dest, len);
    ARQPostRequest(request, owner, 1, 1, aram, dest, len, (void *)TLobby__sub_8001D9DC);
    for (;;) {
        if (aram_dma_pending == 0) break;
        TLobby::run_frame();
    }
    DCInvalidateRange((void *)dest, len);
    return 1;
}
s32 TLobby::aram_transfer_sync(s32 owner, uaddr source, s32 aram, s32 length) {
    u8 request[0x20];
    s32 len;
    if (aram == 0 && source == 0) {
        return 0;
    }
    len = (length + 0x1F) & ~0x1F;
    aram_dma_pending = 1;
    DCFlushRange((void *)source, len);
    ARQPostRequest(request, owner, 0, 1, source, aram, len, (void *)TLobby__sub_8001D9DC);
    for (;;) {
        if (aram_dma_pending == 0) break;
        TLobby::run_frame();
    }
    return 1;
}
