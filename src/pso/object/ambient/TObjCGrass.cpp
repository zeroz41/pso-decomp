#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/EnemyBmlResource.h"
#include "pso/system/BmlResource.h"
#include "types.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/object/ambient/TObjCGrass.h"
#include "pso/map/CsnGroundCandidates.h"
#include "pso/map/CsnGroundQuery.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/BmlResourceLoad.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "pso/system/vector.h"
#include "pso/enemy/wolf/TObjEneBm5Wolf.h"

#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/unk/TLobby.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/render/render_util.h"
#include "pso/unk/text_803D8F74.h"
#include <stdlib.h>
#include "pso/unk/text_803D96A8.h"
#include "pso/system/task/TObject.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/task/TMainTask.h"

extern "C" {
void translate_matrix_vec3(u8 *arg0, u8 *arg1);
void draw_model_motion(void *model, void *motion, f32 frame);
s32 vec3_add_to(void *, void *);
extern s32 actor_frame_tick;
s32 rotate_vector_by_matrix(int, void *, void *);
extern u8 identity_matrix[];
BmlResource *TObjCGrass_bml_resource;


const char *bm_ene_cgrass_model_names[2] = {"re1c_b_cgrass_base.nj", NULL};
const char *bm_ene_cgrass_motion_names[2] = {"re1c_b_cgrass_base.njm", NULL};
BmlResourceDescriptor bm_ene_cgrass_resource_descriptor = {
    "bm_ene_cgrass.bml", bm_ene_cgrass_model_names, bm_ene_cgrass_motion_names, 1, 1,
};
TObjMotionAction cgrass_action_desc[1] = {{1, 0, 0, 4.0f, 1}};
// inferred: the class name pointer the TObjCGrass constructor stores in the object's name field
const char *TObjCGrass__name = "TObjCGrass";
const NpcAnimationBinding cgrass_anim_binding = {NULL, cgrass_action_desc, 0, 0, 1};

Vec *TObjEneBm5Wolf::get_spawn_position() { return &spawn_position; }

void TObjCGrass::render() {
    s32 i;
    TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(this->texlist));
    for (i = 0; i < fragment_count; i++) {
        if (!(fragments[i].flags & 1)) {
            push_matrix_from(0);
            translate_matrix_vec3((u8 *)(0), (u8 *)&fragments[i].position);
            rotate_matrix_y(0, fragments[i].yaw);
            draw_model_motion(model, current_motion, this->frame);
            set_default_alpha_blend();
            pop_matrices(1);
        }
    }
}

void TObjCGrass::run_task() {
    s32 i;
    Vec a;
    Vec b;
    CsnHit *hit;
    frame += play_speed;
    if (last_animation_frame < frame) {
        frame -= last_animation_frame;
    }
    for (i = 0; i < fragment_count; i++) {
        VecCopy(&a, &fragments[i].position);
        VecCopy(&b, &fragments[i].velocity);
        VecCopy(&prev_position, &a);
        vec3_add_to(&a, &b);
        if (i == actor_frame_tick % fragment_count) {
            hit = csnVectorUnder(&a, ground_candidates.groups, 1);
            if (hit != NULL) {
                VecCopy(&a, &hit->contact->point);
                b.y += -0.10888889f;
                prev_position.y += b.y;
                if (a.y < prev_position.y) {
                    a.y = prev_position.y;
                } else {
                    b.y = 0.0f;
                }
                VecCopy(&fragments[i].position, &a);
                VecCopy(&fragments[i].velocity, &b);
            } else {
                fragments[i].flags |= 1;
            }
        } else if (position.y <= a.y) {
            b.y = 0.0f;
        } else {
            b.y += -0.10888889f;
        }
        VecCopy(&fragments[i].position, &a);
        VecCopy(&fragments[i].velocity, &b);
    }
    if (remaining_frames-- < 0) {
        queue_destruction();
    }
}

void TObjCGrass::release_global_805D5130() {
    if (TObjCGrass_bml_resource != NULL) {
        delete (BmlResource *)TObjCGrass_bml_resource;
        TObjCGrass_bml_resource = NULL;
    }
}

void TObjCGrass::load_resources() {
    if (TObjEneDD::check_v2_mode() != 0) {
        TObjCGrass_bml_resource = (BmlResource *)load_enemy_bml_resource_named(
            &bm_ene_cgrass_resource_descriptor, "bm_ene_cgrass_a.bml");
    } else {
        BmlResource *archive = new BmlResource(1, (BmlResourceDescriptor *)&bm_ene_cgrass_resource_descriptor, 0, 0, NULL);
        TObjCGrass_bml_resource = archive;
    }
    NpcAnimationBinding binding = cgrass_anim_binding;
    binding.motions = TObjCGrass_bml_resource->motions;
    BmlModelEntry *model = TObjCGrass_bml_resource->models;
    TObjNpcEnemy::register_animated_chunk(0x36, model->model, model->texlist, &binding, 2.0f, 0.0f);
}

}
TObjCGrass::~TObjCGrass() {
    if (fragments != NULL) { mem_free(fragments); }
}

#pragma push
#pragma fp_contract on
TObjCGrass::TObjCGrass(Vec origin, s32 count, s32 lifetime) : TObjMotion(tl_06) {
    CsnHit *hit;
    m_name = TObjCGrass__name;
    hit = csnVectorUnder(&origin, ground_candidates.groups, 1);
    if (hit != NULL) {
        VecCopy(&position, &hit->contact->point);
    } else {
        VecCopy(&position, &origin);
    }
    model = (void *)TObjCGrass_bml_resource->models[0].model;
    texlist = TObjCGrass_bml_resource->models[0].texlist;
    motion_list = TObjCGrass_bml_resource->motions;
    action_table = cgrass_action_desc;
    set_action_table(action_table);
    set_animation(0);
    last_animation_frame = frame_count - 1.0f;
    fragment_count = count;
    if (count != 0) {
        fragments = (CGrassFragment *)mem_alloc(fragment_count * sizeof(CGrassFragment));
    } else {
        fragments = NULL;
    }
    {
    s32 i;
    for (i = 0; i < fragment_count; i++) {
        s32 a;
        Vec v;
        VecCopy(&fragments[i].position, &position);
        v.x = 0.0f;
        v.y = 3.0517578e-05f * (f32)rand();
        v.z = 3.0517578e-05f * (f32)rand() + 1.0f;
        a = (s32)(182.04445f * (360.0f * (3.0517578e-05f * (f32)rand())));
        fragments[i].yaw = a;
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, a);
        rotate_vector_by_matrix(0, &v, &fragments[i].velocity);
        pop_matrices(1);
        fragments[i].flags = 0;
    }
    }
    remaining_frames = lifetime;
}
#pragma pop

