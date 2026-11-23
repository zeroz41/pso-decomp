#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/frontend/TAdFloorLoadPrtGC.h"
#include "pso/system/vector.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include <string.h>

#pragma readonly_strings on
#pragma pool_data off

void fn_8034AD28(void) {  }
void fn_8034AD2C(void) {  }
void TAdFloorLoadPrtGC::render() {  }
void TAdFloorLoadPrtGC::run_task() {  }

const Vec floor_load_particle_positions[12] = {
    { 0.0f, 0.0f, 100.0f },
    { 0.0f, 49.0f, 86.2f },
    { 0.0f, 86.2f, 49.8f },
    { 0.0f, 100.0f, 0.0f },
    { 0.0f, 86.2f, -49.8f },
    { 0.0f, 49.8f, -86.2f },
    { 0.0f, 0.0f, -100.0f },
    { 0.0f, -49.0f, -86.2f },
    { 0.0f, -86.2f, -49.8f },
    { 0.0f, -100.0f, 0.0f },
    { 0.0f, -86.2f, 49.8f },
    { 0.0f, -49.8f, 86.2f },
};
const ParticleAngles TAdFloorLoadPrtGC__emitter_angles[12] = {
    { 0x0, 0x0, 0x0 },
    { 0x1555, 0x0, 0x0 },
    { 0x2AAA, 0x0, 0x0 },
    { 0x4000, 0x0, 0x0 },
    { 0x5555, 0x0, 0x0 },
    { 0x6AAA, 0x0, 0x0 },
    { 0x8000, 0x0, 0x0 },
    { 0x9555, 0x0, 0x0 },
    { 0xAAAA, 0x0, 0x0 },
    { 0xC000, 0x0, 0x0 },
    { 0xD555, 0x0, 0x0 },
    { 0xEAAA, 0x0, 0x0 },
};
const Vec lbl_80478B48[1] = { { 0.0f, 0.0f, 0.0f } };
const ParticleAngles lbl_80478B54[1] = { { 0x0, 0x0, 0x4000 } };
const char *TAdFloorLoadPrtGC__class_name = "TAdFloorLoadPrtGC";

TAdFloorLoadPrtGC::~TAdFloorLoadPrtGC() {
    s32 i;
    if (origin_particle) {
        origin_particle->queue_destruction();
        origin_particle = NULL;
    }
    for (i = 0; i < 32; i++) {
        if (emitters[i].particle) {
            emitters[i].particle->queue_destruction();
            emitters[i].particle = NULL;
        }
    }
}

TAdFloorLoadPrtGC::TAdFloorLoadPrtGC(TObject *parent) : TObject(parent) {
    s32 i;
    m_name = TAdFloorLoadPrtGC__class_name;
    memset(emitters, 0, sizeof(emitters));
    origin_particle = NULL;
    for (i = 0; i < 12; i++) {
        VecCopy(&emitters[i].position, &floor_load_particle_positions[i]);
        copy_xyz(&emitters[i].angles, (void *)&TAdFloorLoadPrtGC__emitter_angles[i]);
        emitters[i].particle = (TObject *)create_particle_controller_with_angles(
            (void *)&floor_load_particle_positions[i], (void *)&TAdFloorLoadPrtGC__emitter_angles[i], 0x65, 1, 0x40);
    }
    origin_particle = (TObject *)create_particle_controller_with_angles((void *)lbl_80478B48, (void *)lbl_80478B54, 0x2F, 1, 0x40);
}
