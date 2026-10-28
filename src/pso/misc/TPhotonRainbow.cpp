#include "types.h"
#include "pso/misc/TPhotonRainbow.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/misc/TPhotonRainbow.h"
#include "pso/TParticleCtrl.h"
#include "pso/object/TObjFish.h"

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

extern s32 __vt__14TPhotonRainbow[];

}
TPhotonRainbow::~TPhotonRainbow() {

}
extern "C" {

}
