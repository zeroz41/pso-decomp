#include "types.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/object/ambient/TObjMistCtrl.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/effect/particle/TParticleCtrl.h"

struct Vec_802AF64C { f32 x, y, z; };

struct Obj_802AF64C { u8 pad[0x38]; Vec_802AF64C pos; u8 pad2[0x90 - 0x44]; void *x90; };

struct Cam_802AF64C { u8 pad[0x178]; Vec_802AF64C v178; u8 pad2[0x190 - 0x184]; s32 a, b, c; };

extern "C" {
s32 vec3_add_to(void *, void *);
s32 rotate_vector_by_matrix(s32, void *, void *);
s32 normalize_vector(void *);
extern Vec_802AF64C lbl_804707E8;
extern u8 identity_matrix[];
extern Cam_802AF64C *camera_ctrl_instance;
void TObjMistCtrl::sub_802AF64C() {
    Obj_802AF64C *arg0 = (Obj_802AF64C *)this;
    Vec_802AF64C v = lbl_804707E8;
    push_matrix_from(identity_matrix);
    rotate_matrix_zyx(0, camera_ctrl_instance->a, camera_ctrl_instance->b, camera_ctrl_instance->c);
    rotate_vector_by_matrix(0, &v, &v);
    pop_matrix();
    normalize_vector(&v);
    v.x *= 60.0f;
    v.y *= 60.0f;
    v.z *= 60.0f;
    vec3_add_to(&v, &camera_ctrl_instance->v178);
    VecCopy((Vec *)&arg0->pos, (const Vec *)&v);
    if (arg0->x90 != NULL) {
        ((TParticleCtrl *)arg0->x90)->set_position(&arg0->pos);
    }
}

}
