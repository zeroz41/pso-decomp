#include "pso/system/BmlAccessors.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/boss/olgaflow/TBoss6CrushRock.h"
#include "pso/system/BmlResource.h"
#include "pso/boss/olgaflow/TBoss6CrushPtcl.h"
#include "pso/boss/olgaflow/TBoss6PlotFalz.h"
#include "pso/boss/olgaflow/TBoss6Rock.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/math/MatrixReflect.h"
#include "pso/render/TextureState.h"
#include "pso/system/vector.h"
#include "pso/math/AngleLookup.h"
#include "pso/system/task/TMainTask.h"
#include "types.h"
#include <stdlib.h>
#include "pso/system/task/TObject.h"
#include "pso/math/MatrixVector.h"

const char TBoss6CrushRock::class_name_string[] = "TBoss6CrushRock";
const char TBoss6CrushPtcl::class_name_string[] = "TBoss6CrushPtcl";
const char *TBoss6CrushRock::name = TBoss6CrushRock::class_name_string;
const char *TBoss6CrushPtcl::name = TBoss6CrushPtcl::class_name_string;

TBoss6PlotFalz *TBoss6PlotFalz::get_instance() {
    return TBoss6PlotFalz::instance;
}

void TBoss6Rock::spawn_crush_rocks(Vec *point, s32 kind) {
    f32 radius;
    s32 base;
    s32 n;
    s32 i;
    s32 j;

    if (TBoss6CrushRock::is_falz_alive() == 0) {
        return;
    }
    TBoss6CrushPtcl::create(point);
    radius = 7.5f;
    base = 5;
    n = 2;
    if (TBoss6PlotFalz::get_instance() == NULL) {
        return;
    }
    switch (kind) {
    case 0:
        break;
    case 1:
        radius = 15.0f;
        base = 1;
        n = 3;
        break;
    }
    for (i = 0; i < 0x12 / n; i++) {
        for (j = 0; j < n; j++) {
            Vec p = *point;
            s32 angle = (s32)(65535.0f * (0.000030517578f * (f32)rand()));
            p.x += radius * sin_table_lookup(angle);
            p.y += 35.0f * (0.000030517578f * (f32)rand());
            p.z += radius * cos_table_lookup(angle);
            new TBoss6CrushRock(tl_02, &p, base + j);
        }
    }
}

TBoss6CrushRock::TBoss6CrushRock(TObject *parent, const Vec *point, s32 model_index) : TObject(parent) {
    m_name = TBoss6CrushRock::name;
    model = get_bml_model((BmlResource *)TBoss6Rock::get_resource(), model_index);
    texture_list = TBoss6Rock::get_texture_list();
    VecCopy(&position, point);
    velocity.x = (0.5f * ((0.000030517578f * (f32) rand()) - 0.5f));
    velocity.y = (0.5f * ((0.000030517578f * (f32) rand()) - 0.5f));
    velocity.z = (0.5f * ((0.000030517578f * (f32) rand()) - 0.5f));
    angles.x = (s32)(65535.0f * (0.000030517578f * (f32) rand()));
    angles.y = (s32)(65535.0f * (0.000030517578f * (f32) rand()));
    angles.z = (s32)(65535.0f * (0.000030517578f * (f32) rand()));
    angular_velocity.x = (s32)(4096.0f * ((0.000030517578f * (f32) rand()) - 0.5f));
    angular_velocity.y = (s32)(4096.0f * ((0.000030517578f * (f32) rand()) - 0.5f));
    angular_velocity.z = (s32)(4096.0f * ((0.000030517578f * (f32) rand()) - 0.5f));
}

TBoss6CrushRock::~TBoss6CrushRock() {}

#pragma push
#pragma opt_common_subs off
void TBoss6CrushRock::run_task() {
    if (is_falz_alive() == 0) {
        queue_destruction();
        return;
    }
    angles.x += angular_velocity.x;
    angles.y += angular_velocity.y;
    angles.z += angular_velocity.z;
    velocity.y += -0.25f;
    vec3_add_to(&position, &velocity);
    if (position.y < 0.0f) {
        position.y = 0.0f;
        velocity.x *= 0.25f;
        velocity.y *= -0.25f;
        velocity.z *= 0.25f;
        if (vector_length(&velocity) < 0.1f) {
            queue_destruction();
        }
    }
}
#pragma pop

void TBoss6CrushRock::render() {
    if (is_falz_alive() != 0) {
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, angles.y);
        rotate_matrix_x(NULL, angles.x);
        rotate_matrix_z(NULL, angles.z);
        set_texture_list(texture_list);
        draw_ginja_object(model);
        pop_matrix();
    }
}

s32 TBoss6CrushRock::is_falz_alive() {
    return TBoss6PlotFalz::get_instance() ? 1 : 0;
}

TBoss6CrushPtcl *TBoss6CrushPtcl::create(Vec *point) {
    return new TBoss6CrushPtcl(tl_02, point);
}

TBoss6CrushPtcl::TBoss6CrushPtcl(TObject *parent, Vec *point) : TObject(parent) {
    m_name = TBoss6CrushPtcl::name;
    Vec position = *point;
    dust_emitter = create_particle_emitter(&position, 0x203);
    debris_emitter = create_particle_emitter(&position, 0x204);
    age = 0;
}

TBoss6CrushPtcl::~TBoss6CrushPtcl() {}

void TBoss6CrushPtcl::run_task() {
    age++;
    if (age >= 6) {
        if (dust_emitter != NULL) {
            TParticleCtrl::release(dust_emitter);
            dust_emitter = NULL;
        }
        if (debris_emitter != NULL) {
            TParticleCtrl::release(debris_emitter);
            debris_emitter = NULL;
        }
        queue_destruction();
    }
}
