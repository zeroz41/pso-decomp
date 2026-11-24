#include "pso/effect/photon/PhotonBlastSummon.h"
#include "pso/system/BmlResource.h"
#include "types.h"
#include "pso/effect/photon/TPhotonRainbow.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/PhotonBlastResults.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/vector.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/unk/text_803E2F28.h"

void TPhotonRainbow::render() {
    if (camera_ctrl_instance != NULL) {
        position.x = camera_ctrl_instance->pos.x;
        position.z = camera_ctrl_instance->pos.z;
    }
    TParticleCtrl::begin_effect_render();
    push_matrix();
    texlist = ring_texlist[0];
    post_translate_matrix(&position.x);
    rotate_matrix_y(0, rotation_y / 2);
    TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(texlist));
    draw_chunk_object(ring_model[0]);
    pop_matrix();
    push_matrix();
    texlist = ring_texlist[1];
    post_translate_matrix(&position.x);
    rotate_matrix_y(0, 0x10000 - rotation_y);
    TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(texlist));
    draw_chunk_object(ring_model[1]);
    pop_matrix();
    TParticleCtrl::end_effect_render();
}

void TPhotonRainbow::run_task() {
    rotation_y = rotation_y + 0xB6;
}

TPhotonRainbow::~TPhotonRainbow() {
}

#pragma readonly_strings on

const char *photon_rainbow_class_name = "TPhotonRainbow";

TPhotonRainbow::TPhotonRainbow(TObject *parent, const Vec *pos, s32 boss_area) : TObjBase(parent) {
    m_name = photon_rainbow_class_name;
    if (this->boss_area == 1) {
        ring_texlist[0] = photon_blast_shared_resource->models[6].texlist;
        ring_texlist[1] = photon_blast_shared_resource->models[8].texlist;
        ring_model[0] = photon_blast_shared_resource->models[6].model;
        ring_model[1] = photon_blast_shared_resource->models[8].model;
    } else {
        ring_texlist[0] = photon_blast_shared_resource->models[5].texlist;
        ring_texlist[1] = photon_blast_shared_resource->models[7].texlist;
        ring_model[0] = photon_blast_shared_resource->models[5].model;
        ring_model[1] = photon_blast_shared_resource->models[7].model;
    }
    VecCopy(&position, pos);
}

void release_photon_rainbow_resources(void) {
}

void load_photon_rainbow_resources(void) {
}
