#include "types.h"
#include "pso/effect/photon/TPhotonRainbow.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/effect/photon/TPhotonRainbow_801AE640.h"
#include "pso/system/vector.h"

extern "C" {

s32 post_translate_matrix(void *);
s32 rotate_matrix_y(s32, s32);
s32 push_matrix();
void __dl__7TObjectFPv(void *);

extern u8 *camera_ctrl_instance;

void TPhotonRainbow::render() {
    u8 *arg0 = (u8 *)this;
    if ((void *) camera_ctrl_instance != NULL) {
        *(f32 *)((s8 *)arg0 + 0x38) = (f32) *(f32 *)((s8 *)camera_ctrl_instance + 0x178);
        *(f32 *)((s8 *)arg0 + 0x40) = (f32) *(f32 *)((s8 *)camera_ctrl_instance + 0x180);
    }
    TParticleCtrl::begin_effect_render();
    push_matrix();
    this->texlist = (s32) this->m_90;
    post_translate_matrix((u8 *)&this->position);
    rotate_matrix_y(0, (s32) this->rotation_y / 2);
    TObjFish::set_global_param(this->texlist);
    draw_chunk_object((void *)this->m_98);
    pop_matrix();
    push_matrix();
    this->texlist = (s32) this->m_94;
    post_translate_matrix((u8 *)&this->position);
    rotate_matrix_y(0, 0x10000 - this->rotation_y);
    TObjFish::set_global_param(this->texlist);
    draw_chunk_object((void *)this->m_9c);
    pop_matrix();
    TParticleCtrl::end_effect_render();
}

void TPhotonRainbow::run_task() {
    this->rotation_y = (this->rotation_y + 0xB6);
}


}
TPhotonRainbow::~TPhotonRainbow() {

}
extern "C" {

}

#pragma readonly_strings on

extern "C" {
const char *TPhotonRainbow__name = "TPhotonRainbow";
}


extern "C" {

s32 __ct__8TObjBaseFP7TObject();

extern void *__vt__14TPhotonRainbow[];
extern const char *TPhotonRainbow__name;
extern u8 *photon_blast_shared_resource;

u8 *TPhotonRainbow__ct(u8 *photon_rainbow, s32 arg1_unused, s32 arg2) {
    __ct__8TObjBaseFP7TObject();
    *(s32 **)((s8 *)photon_rainbow + 0x18) = (s32 *)&__vt__14TPhotonRainbow;
    *(s32 *)((s8 *)photon_rainbow + 0) = (s32) ((s32)TPhotonRainbow__name);
    if ((s32) ((TPhotonRainbow *)photon_rainbow)->m_a8 == 1) {
        ((TPhotonRainbow *)photon_rainbow)->m_90 = (s32) *(s32 *)((s8 *)(*(void **)((s8 *)photon_blast_shared_resource + 0x42C)) + 0x6C);
        ((TPhotonRainbow *)photon_rainbow)->m_94 = (s32) *(s32 *)((s8 *)(*(void **)((s8 *)photon_blast_shared_resource + 0x42C)) + 0x8C);
        ((TPhotonRainbow *)photon_rainbow)->m_98 = (s32) *(s32 *)((s8 *)(*(void **)((s8 *)photon_blast_shared_resource + 0x42C)) + 0x68);
        ((TPhotonRainbow *)photon_rainbow)->m_9c = (s32) *(s32 *)((s8 *)(*(void **)((s8 *)photon_blast_shared_resource + 0x42C)) + 0x88);
    } else {
        ((TPhotonRainbow *)photon_rainbow)->m_90 = (s32) *(s32 *)((s8 *)(*(void **)((s8 *)photon_blast_shared_resource + 0x42C)) + 0x5C);
        ((TPhotonRainbow *)photon_rainbow)->m_94 = (s32) *(s32 *)((s8 *)(*(void **)((s8 *)photon_blast_shared_resource + 0x42C)) + 0x7C);
        ((TPhotonRainbow *)photon_rainbow)->m_98 = (s32) *(s32 *)((s8 *)(*(void **)((s8 *)photon_blast_shared_resource + 0x42C)) + 0x58);
        ((TPhotonRainbow *)photon_rainbow)->m_9c = (s32) *(s32 *)((s8 *)(*(void **)((s8 *)photon_blast_shared_resource + 0x42C)) + 0x78);
    }
    VecCopy((Vec *)(photon_rainbow + 0x38), (const Vec *)arg2);
    return photon_rainbow;
}

void TObjPlayer__sub_801AE724(void) {  }
void TObjPlayer__sub_801AE728(void) {  }

}
