#include "pso/render/GinjaTextureInput.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/unk/TLobby.h"
#include "pso/enemy/flower/TObjEneRe2Flower_EffCurse3.h"
#include "pso/enemy/flower/TObjEneRe2Flower_800C4B78.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/vector.h"
#include "pso/system/task/TObject.h"

#include "pso/enemy/TUnk_80493450.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/enemy/flower/TObjEneRe2Flower_Bomb.h"
#include "pso/player/TUnk_804928CC.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/player/TObjPlayer.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/enemy/beast/TObjEneBeast.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/camera/TCameraCtrl.h"


typedef struct Coll_800C4A5C {
    u8 pad0[0xC];
    f32 radius;
} Coll_800C4A5C;

typedef struct Obj_800C4A5C {
    s32 f0;
    u8 pad4[0x18 - 0x4];
    void *vptr;
    u8 pad1C[0x38 - 0x1C];
    Vec pos;
    u8 pad44[0xA4 - 0x44];
    Coll_800C4A5C *coll;
    u8 padA8[0xB0 - 0xA8];
    u16 ownerId;
    u8 padB2[0xB4 - 0xB2];
    Vec start;
    Vec velA;
    Vec velB;
    Vec accel;
    f32 fE4;
    s32 fE8;
    s32 angle;
    f32 fF0;
    s32 fF4;
    s32 fF8;
    s32 fFC;
    s32 f100;
} Obj_800C4A5C;

typedef struct Obj_800C55E0 {
    u8 pad0[0xB8];
    s16 fB8;
    u8 padBA[0x326 - 0xBA];
    s16 state;
    s16 f328;
    u8 pad32A[0x34C - 0x32A];
    void *f34C;
} Obj_800C55E0;

extern "C" {

void * player_render_texture_buffer;
void release_texture_list(void *);

extern const char TObjEneRe2Flower_EffCurse3__class_name_string[0x1C] = "TObjEneRe2Flower_EffCurse3";
const char *TObjEneRe2Flower_EffCurse3__name = TObjEneRe2Flower_EffCurse3__class_name_string;
#pragma push
#pragma fp_contract on
void TObjEneRe2Flower_EffCurse3::run_task() {
    Vec a;
    Vec b;
    timer++;
    if (timer > 20) {
        queue_destruction();
        return;
    }
    if (target->is_alive() != 0) {
        VecCopy(&a, &target->position);
        a.y += (14.0f);
        VecCopy((Vec *)&b, &camera_ctrl_instance->pos);
        subtract_vector(&b, &a);
        normalize_vector_safe(&b);
        a.x = (2e+01f) * b.x + a.x;
        a.y = (2e+01f) * b.y + a.y;
        a.z = (2e+01f) * b.z + a.z;
        effect->set_position(&a);
    }
}
#pragma pop

}
TObjEneRe2Flower_EffCurse3::~TObjEneRe2Flower_EffCurse3() {
    if (effect != NULL) {
        effect->queue_destruction();
        effect = NULL;
    }
}

TObjEneRe2Flower_EffCurse3::TObjEneRe2Flower_EffCurse3(TObject *parent, TObjBase *target) : TObject(parent) {
    m_name = TObjEneRe2Flower_EffCurse3__name;
    timer = 0;
    this->target = target;
    if (this->target->is_alive() != 0) {
        effect = spawn_continuous_particle_effect_with_flags(&this->target->position, 0xDE, 0x40);
    }
}
extern "C" {

struct Node_800C4D88 { void *p; s32 v; };
GinjaTextureInput player_render_target;
NJS_TEXNAME player_render_texture_name;
__declspec(section ".data") Node_800C4D88 lbl_80500C30;

void TObjPlayer__sub_800C4D44(void) {
    void *p = &lbl_80500C30;
    if (p != 0) {
        release_texture_list(p);
    }
    if (player_render_texture_buffer != 0) {
        mem_free(player_render_texture_buffer);
        player_render_texture_buffer = 0;
    }
}

void TObjPlayer::create_render_texture() {
    player_render_target.set_render_rect(player_render_texture_buffer = mem_alloc(0x800), 0x902, 0x20, 0x20);
    set_texture_name(&player_render_texture_name, &player_render_target, 0x18696, 0x40800000);
    lbl_80500C30.p = &player_render_texture_name;
    lbl_80500C30.v = 1;
    pso_load_texture((NJS_TEXLIST *)&lbl_80500C30);
}
}
