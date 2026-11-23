#include "types.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/object/ambient/TObjMistCtrl.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/effect/particle/TParticleCtrl.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/task/TObject_80019A50.h"
#include "pso/render/render_util.h"
#include "pso/unk/text_803DA798.h"
#include "pso/player/TPlayerFootStamp.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TObject.h"
#include "pso/math/MatrixVector.h"
#pragma readonly_strings on

struct Obj_802AF64C { u8 pad[0x38]; Vec pos; u8 pad2[0x90 - 0x44]; void *x90; };

extern "C" {
s32 vec3_add_to(void *, void *);
extern Vec lbl_804707E8;
extern u8 identity_matrix[];
void TObjMistCtrl::sub_802AF64C() {
    Obj_802AF64C *arg0 = (Obj_802AF64C *)this;
    Vec v = lbl_804707E8;
    push_matrix_from(identity_matrix);
    rotate_matrix_zyx(0, camera_ctrl_instance->pitch, camera_ctrl_instance->yaw, camera_ctrl_instance->roll);
    rotate_vector_by_matrix(0, &v, &v);
    pop_matrix();
    normalize_vector(&v);
    v.x *= 60.0f;
    v.y *= 60.0f;
    v.z *= 60.0f;
    vec3_add_to(&v, &camera_ctrl_instance->pos.x);
    VecCopy((Vec *)&arg0->pos, (const Vec *)&v);
    if (arg0->x90 != NULL) {
        ((TParticleCtrl *)arg0->x90)->set_position(&arg0->pos);
    }
}

const char *lbl_805D3E80 = "TObjMistCtrl";

void TObjMistCtrl::run_task() { { (void)(sub_802AF64C()); return; } }

}
TObjMistCtrl::~TObjMistCtrl() {
    if (*(void **)((s8 *)this + 0x90) != NULL) { ((TObject *)(*(void **)((s8 *)this + 0x90)))->queue_destruction(); *(s32 *)((s8 *)this + 0x90) = 0; }
}


TObjMistCtrl::TObjMistCtrl(saddr parent, uaddr set_data) : TObjBase((TObject *)((void *)parent)) {
    this->m_name = lbl_805D3E80;
    if (set_data != 0U) {
        ((TObjMistCtrl *)(((u8 *)this)))->apply_object_set_data((void *)set_data);
    }
    *(saddr *)((s8 *)this + 0x90) = (saddr)spawn_continuous_particle_effect_with_flags((((u8 *)this) + 0x38), 0x200, 0x800);
}

__declspec(section ".rodata") Vec lbl_804707E8 = { 0, 0, -1.0f };
