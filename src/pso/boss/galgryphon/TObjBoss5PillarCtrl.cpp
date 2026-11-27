#include "pso/boss/galgryphon/Boss5CommonResource.h"
#include "types.h"
#include "pso/boss/galgryphon/TObjBoss5PillarCtrl.h"

#include "pso/boss/galgryphon/TObjBoss5Pillar.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/task/TObject.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/system/BmlResource.h"
#include "pso/system/NinjaTypes.h"

#pragma readonly_strings on


const char *TObjBoss5PillarCtrl::name = "TObjBoss5PillarCtrl";


void TObjBoss5PillarCtrl::render() {  }
void TObjBoss5PillarCtrl::run_task() {  }
TObjBoss5PillarCtrl::~TObjBoss5PillarCtrl() {
    s32 i;
    for (i = this->count - 1; i >= 0; i--) {
        if (this->pillars[i] != NULL) {
            this->pillars[i]->queue_destruction();
            this->pillars[i] = NULL;
        }
    }
    mem_free(this->pillars);
}


TObjBoss5PillarCtrl::TObjBoss5PillarCtrl(TObject *parent) : TObject(parent) {
    NJS_OBJECT *node;
    s32 i;
    NJS_OBJECT *root;
    m_name = TObjBoss5PillarCtrl::name;
    this->count = 0;
    this->pillars = NULL;
    for (node = boss5_common_bml_resource->models[2].model->child; node != NULL; node = node->sibling) {
        this->count++;
    }
    if (this->count <= 0) {
        queue_destruction();
        return;
    }
    root = boss5_common_bml_resource->models[2].model;
    this->pillars = (TObjBoss5Pillar **)mem_alloc(this->count * 4);
    for (i = 0, node = root->child; i < this->count; i++) {
        this->pillars[i] = TObjBoss5Pillar::create((Vec *)node->pos);
        node = node->sibling;
    }
}

TObjBoss5PillarCtrl *TObjBoss5PillarCtrl::create(TObject *parent) {
    return new TObjBoss5PillarCtrl(parent);
}

void TObjBoss5PillarCtrl::update_pillar() { pillar_update_stub(); }
void TObjBoss5PillarCtrl::forward_pillar_2B710() { pillar_forward_stub(); }
void TObjBoss5Pillar::play_sound_once() {
    if (this->state == 0) {
        play_sound_effect(0x4003A819, 0, 0, 0);
        this->state = 1;
    }
}

