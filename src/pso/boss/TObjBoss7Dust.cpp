#include "pso/boss/TObjBoss7Dust.h"
#include "pso/unk/text_802F0E24.h"
#include "pso/system/vector.h"

#include "types.h"
#include "pso/boss/TObjBoss7DustCtrl.h"

struct RecoveredGlobal_802F119C___vt__13TObjBoss7Dust {
    s32 value;
    u8 remaining[0x14];
};

extern "C" {
s32 __ct__7TObjectFP7TObject(void *, void *);
extern RecoveredGlobal_802F119C___vt__13TObjBoss7Dust __vt__13TObjBoss7Dust;
extern s32 lbl_805D3FE4;
void TObjBoss2Tunnel__sub_802F2C4C(void);
void TObjBoss2Tunnel__sub_802F2C50(void);
void TObjBoss2Tunnel__sub_802F2C84(void);
void TObjBoss7DustCtrl__sub_802F1450(void);
void boss7_dust_draw_at(s32 *arg0, s32 arg1);
void fn_802F1454(void);
void fn_802F19C0(void);
s32 queue_destruction__7TObjectFv();

void fn_802F105C(void) { TObjBoss7DustCtrl__sub_802F1450(); TObjBoss2Tunnel__sub_802F2C4C(); free_boss7_common_resources(); }
void fn_802F1084(void) { TObjBoss2Tunnel__sub_802F2C50(); fn_802F19C0(); TObjBoss7DustCtrl::create(); }
}
void init_scene_boss2_tunnel(void) { load_boss7_common_resources(); TObjBoss2Tunnel__sub_802F2C84(); fn_802F1454(); }
void TObjBoss7Dust::render() { boss7_dust_draw_at((s32 *)((char*)this + 0x24), (s32)(*(void**)((char*)this + 0x20))); }

extern const f32 lbl_805DEC68;

void TObjBoss7Dust::run_task() {
    *(f32 *)((s8 *)this + 0x2C) = (f32) (*(f32 *)((s8 *)this + 0x2C) - lbl_805DEC68);
    *(s32 *)((s8 *)this + 0x1C) = (s32) (*(s32 *)((s8 *)this + 0x1C) + 1);
    if ((s32) *(s32 *)((s8 *)this + 0x1C) >= 0x5A) {
        queue_destruction__7TObjectFv();
    }
}
typedef char RecoveredGlobal_802F119C___vt__13TObjBoss7Dust_size[sizeof(RecoveredGlobal_802F119C___vt__13TObjBoss7Dust) == 0x18 ? 1 : -1];
TObjBoss7Dust::~TObjBoss7Dust() {}
u8 *__ct__13TObjBoss7DustFv(u8 *object, s32 arg1, s32 arg2) {
    __ct__7TObjectFP7TObject((void *)object, (void *)arg1);
    *(s32 **)((s8 *)object + 0x18) = &__vt__13TObjBoss7Dust.value;
    *(s32 *)((s8 *)object + 0) = (s32) lbl_805D3FE4;
    VecCopy((Vec *)(object + 0x24), (const Vec *)(arg2));
    *(s32 *)((s8 *)object + 0x1C) = 0;
    *(s32 *)((s8 *)object + 0x20) = TObjBoss7DustCtrl__sub_802F125C();
    return object;
}
