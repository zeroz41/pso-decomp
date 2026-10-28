#include "types.h"
#include "pso/unk/text_803D853C.h"
#include "pso/boss/TBoss1DragonColli.h"
#include "pso/math/MatrixVector.h"
#include "pso/unk/TUnk_804E4B24.h"
#include "pso/object/TObjMotion.h"
#include "pso/boss/TObjBoss7TunnelCol.h"
#include "pso/player/TObjPlayer.h"
extern "C" void *__ct__14TObjCollidableFP7TObject(void *, TObject *);

extern "C" {

struct VOff_802F1BEC_arg0_802F1B7C { char pad_0[0xAC]; char f_AC[1]; };
struct VOff_802F1C68_arg0_802f1c68_802F1B7C { char pad_0[0x48]; char f_48[1]; };

void __dl__7TObjectFPv(void *);
s32 get_mode__11TCameraCtrlFPv(void *p);

void TObjBoss7TunnelCol::render() {  }
void TObjBoss7TunnelCol::run_task() {  }

extern s32 __vt__18TObjBoss7TunnelCol[];

void *__dt__18TObjBoss7TunnelColFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__18TObjBoss7TunnelCol;
        ((TObjCollidable *)arg0)->unregister_object_by_id();
        ((TObjCollidable *)arg0)->clear_collision_bodies();
        __dt__14TObjCollidableFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

extern s32 TObjBoss7TunnelCol__col_desc[];
extern void *lbl_805D3FF0;
extern const f32 lbl_805DECA0;
extern const f32 lbl_805DEC9C;

void *TObjBoss7TunnelCol__ct(void *arg0, TObject *parent) {
    struct VOff_802F1BEC_arg0_802F1B7C *self = (struct VOff_802F1BEC_arg0_802F1B7C *)arg0;
    __ct__14TObjCollidableFP7TObject(arg0, parent);
    *(s32 **)((s8 *)arg0 + 0x18) = __vt__18TObjBoss7TunnelCol;
    *(void * *)&((TObjBoss7TunnelCol *)arg0)->m_name = lbl_805D3FF0;
    copy_collision_body((CollisionBody *)self->f_AC, (const CollisionBody *)TObjBoss7TunnelCol__col_desc);
    *(f32 *)((s8 *)arg0 + 0x38) = lbl_805DECA0;
    *(f32 *)((s8 *)arg0 + 0x3C) = lbl_805DEC9C;
    *(f32 *)((s8 *)arg0 + 0x40) = lbl_805DEC9C;
    ((TObjCollidable *)arg0)->set_collision_body(self->f_AC);
    ((TObjPlayer *)arg0)->register_object_by_id();
    return arg0;
}

void TUnk_804E4B24::update_collision() {
    struct VOff_802F1C68_arg0_802f1c68_802F1B7C *self = (struct VOff_802F1C68_arg0_802f1c68_802F1B7C *)this;
    set_matrix_identity((u8 *)self->f_48);
    translate_matrix_vec3((u8 *)self->f_48, (u8 *)((char *)this + 28));
    rotate_matrix_yxz((s32)self->f_48, (s32)(*(void * *)&(*(void * *)((u8 *)this + 0x28))), (s32)this->m_2c, (s32)(*(void * *)&(this->unk_30)));
}

extern f32 lbl_805DECA4;
extern f32 lbl_805DECA8;

s32 TObjBoss7TunnelCol::is_in_camera_range() {
    f32 temp_f1;

    if (get_mode__11TCameraCtrlFPv(((s32 *)&main_task)) & 0x20) {
        temp_f1 = *(f32 *)&this->texlist;
        if ((temp_f1 < lbl_805DECA4) && (lbl_805DECA8 < temp_f1)) {
            return 0;
        }
    }
    return 1;
}

}
