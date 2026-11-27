#include "pso/render/GinjaTextureInput.h"
#include "types.h"
#include "pso/network/TLobby.h"
#include "pso/enemy/flower/TObjEneRe2Flower_EffCurse3.h"
#include "pso/system/vector.h"
#include "pso/system/task/TObject.h"

#include "pso/enemy/beast/TObjEneBeastBase.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/enemy/flower/TObjEneRe2Flower_Bomb.h"
#include "pso/object/base/TAttackCollider.h"
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
#include "pso/render/GinjaTexture.h"
#include "pso/render/psoLoadTexture.h"


void * player_render_texture_buffer;

extern const char re2_flower_eff_curse3_class_name_string[0x1C] = "TObjEneRe2Flower_EffCurse3";
const char *TObjEneRe2Flower_EffCurse3::class_name = re2_flower_eff_curse3_class_name_string;
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
        VecCopy(&b, &camera_ctrl_instance->pos);
        subtract_vector(&b, &a);
        normalize_vector_safe(&b);
        a.x = (2e+01f) * b.x + a.x;
        a.y = (2e+01f) * b.y + a.y;
        a.z = (2e+01f) * b.z + a.z;
        effect->set_position(&a);
    }
}
#pragma pop

TObjEneRe2Flower_EffCurse3::~TObjEneRe2Flower_EffCurse3() {
    if (effect != NULL) {
        effect->queue_destruction();
        effect = NULL;
    }
}

TObjEneRe2Flower_EffCurse3::TObjEneRe2Flower_EffCurse3(TObject *parent, TObjBase *target) : TObject(parent) {
    m_name = TObjEneRe2Flower_EffCurse3::class_name;
    timer = 0;
    this->target = target;
    if (this->target->is_alive() != 0) {
        effect = spawn_continuous_particle_effect_with_flags(&this->target->position, 0xDE, 0x40);
    }
}

GinjaTextureInput player_render_target;
NJS_TEXNAME player_render_texture_name;
__declspec(section ".data") NJS_TEXLIST player_render_texlist;

void free_curse_resources(void) {
    NJS_TEXLIST *texlist = &player_render_texlist;
    if (texlist != NULL) {
        release_texture_list(texlist);
    }
    if (player_render_texture_buffer != 0) {
        ::operator delete[](player_render_texture_buffer);
        player_render_texture_buffer = 0;
    }
}

void create_render_texture() {
    player_render_target.set_render_rect(player_render_texture_buffer = ::operator new[](0x800), 0x902, 0x20, 0x20);
    set_texture_name(&player_render_texture_name, &player_render_target, 0x18696, 0x40800000);
    player_render_texlist.textures = &player_render_texture_name;
    player_render_texlist.nbTexture = 1;
    psoLoadTexture(&player_render_texlist);
}
