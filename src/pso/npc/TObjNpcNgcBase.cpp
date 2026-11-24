#include "pso/npc/TObjNpcNgcBase.h"
#include "pso/map/FloorArea.h"
#include "pso/object/TObjControl.h"
#include "pso/system/BmlAccessors.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/task/TMainTask.h"

// Per-NPC body BML descriptors: one model (<name>.nj), no motions.
static const char *npc_delta_w_body_motion_names[1] = { NULL };
static const char *npc_delta_w_body_model_names[2] = { "n_delta_w_body.nj", NULL };
static BmlResourceDescriptor npc_delta_w_body_resource_descriptor = { "bm_n_delta_w_body.bml", npc_delta_w_body_model_names, npc_delta_w_body_motion_names, 1, 0 };
static const char *npc_elly_t_body_motion_names[1] = { NULL };
static const char *npc_elly_t_body_model_names[2] = { "n_elly_t_body.nj", NULL };
static BmlResourceDescriptor npc_elly_t_body_resource_descriptor = { "bm_n_elly_t_body.bml", npc_elly_t_body_model_names, npc_elly_t_body_motion_names, 1, 0 };
static const char *npc_karen_t_body_motion_names[1] = { NULL };
static const char *npc_karen_t_body_model_names[2] = { "n_karen_t_body.nj", NULL };
static BmlResourceDescriptor npc_karen_t_body_resource_descriptor = { "bm_n_karen_t_body.bml", npc_karen_t_body_model_names, npc_karen_t_body_motion_names, 1, 0 };
static const char *npc_leo_w_body_motion_names[1] = { NULL };
static const char *npc_leo_w_body_model_names[2] = { "n_leo_w_body.nj", NULL };
static BmlResourceDescriptor npc_leo_w_body_resource_descriptor = { "bm_n_leo_w_body.bml", npc_leo_w_body_model_names, npc_leo_w_body_motion_names, 1, 0 };
static const char *npc_michel_t_body_motion_names[1] = { NULL };
static const char *npc_michel_t_body_model_names[2] = { "n_michel_t_body.nj", NULL };
static BmlResourceDescriptor npc_michel_t_body_resource_descriptor = { "bm_n_michel_t_body.bml", npc_michel_t_body_model_names, npc_michel_t_body_motion_names, 1, 0 };
static const char *npc_nol_t_body_motion_names[1] = { NULL };
static const char *npc_nol_t_body_model_names[2] = { "n_nol_t_body.nj", NULL };
static BmlResourceDescriptor npc_nol_t_body_resource_descriptor = { "bm_n_nol_t_body.bml", npc_nol_t_body_model_names, npc_nol_t_body_motion_names, 1, 0 };
static const char *npc_paganini_t_body_motion_names[1] = { NULL };
static const char *npc_paganini_t_body_model_names[2] = { "n_paganini_t_body.nj", NULL };
static BmlResourceDescriptor npc_paganini_t_body_resource_descriptor = { "bm_n_paganini_t_body.bml", npc_paganini_t_body_model_names, npc_paganini_t_body_motion_names, 1, 0 };
static const char *npc_gunsinei_body_motion_names[1] = { NULL };
static const char *npc_gunsinei_body_model_names[2] = { "gunsinei_body.nj", NULL };
static BmlResourceDescriptor npc_gunsinei_body_resource_descriptor = { "bm_gunsinei_body.bml", npc_gunsinei_body_model_names, npc_gunsinei_body_motion_names, 1, 0 };
static const char *npc_kenkyuw2_body_motion_names[1] = { NULL };
static const char *npc_kenkyuw2_body_model_names[2] = { "kenkyuw2_body.nj", NULL };
static BmlResourceDescriptor npc_kenkyuw2_body_resource_descriptor = { "bm_kenkyuw2_body.bml", npc_kenkyuw2_body_model_names, npc_kenkyuw2_body_motion_names, 1, 0 };
static const char *npc_ncchild_body_motion_names[1] = { NULL };
static const char *npc_ncchild_body_model_names[2] = { "ncchild_body.nj", NULL };
static BmlResourceDescriptor npc_ncchild_body_resource_descriptor = { "bm_ncchild_body.bml", npc_ncchild_body_model_names, npc_ncchild_body_motion_names, 1, 0 };
static const char *npc_ncman_body_motion_names[1] = { NULL };
static const char *npc_ncman_body_model_names[2] = { "ncman_body.nj", NULL };
static BmlResourceDescriptor npc_ncman_body_resource_descriptor = { "bm_ncman_body.bml", npc_ncman_body_model_names, npc_ncman_body_motion_names, 1, 0 };
static const char *npc_nctrunk_body_motion_names[1] = { NULL };
static const char *npc_nctrunk_body_model_names[2] = { "nctrunk_body.nj", NULL };
static BmlResourceDescriptor npc_nctrunk_body_resource_descriptor = { "bm_nctrunk_body.bml", npc_nctrunk_body_model_names, npc_nctrunk_body_motion_names, 1, 0 };
static const char *npc_nctrunk2_body_motion_names[1] = { NULL };
static const char *npc_nctrunk2_body_model_names[2] = { "nctrunk2_body.nj", NULL };
static BmlResourceDescriptor npc_nctrunk2_body_resource_descriptor = { "bm_nctrunk2_body.bml", npc_nctrunk2_body_model_names, npc_nctrunk2_body_motion_names, 1, 0 };
static const char *npc_ncwoman_body_motion_names[1] = { NULL };
static const char *npc_ncwoman_body_model_names[2] = { "ncwoman_body.nj", NULL };
static BmlResourceDescriptor npc_ncwoman_body_resource_descriptor = { "bm_ncwoman_body.bml", npc_ncwoman_body_model_names, npc_ncwoman_body_motion_names, 1, 0 };

// {resource slot, descriptor} lists, terminated by slot -1 (load_resources picks one per area).
static NpcBodyResourceSlot npc_pioneer2_ep_resource_descriptor_list[] = {
    { 0, &npc_michel_t_body_resource_descriptor },
    { 1, &npc_karen_t_body_resource_descriptor },
    { 2, &npc_leo_w_body_resource_descriptor },
    { 3, &npc_paganini_t_body_resource_descriptor },
    { 4, &npc_delta_w_body_resource_descriptor },
    { 5, &npc_nol_t_body_resource_descriptor },
    { 6, &npc_elly_t_body_resource_descriptor },
    { 7, &npc_ncchild_body_resource_descriptor },
    { 8, &npc_ncwoman_body_resource_descriptor },
    { 9, &npc_ncman_body_resource_descriptor },
    { 10, &npc_gunsinei_body_resource_descriptor },
    { 11, &npc_nctrunk_body_resource_descriptor },
    { 12, &npc_nctrunk2_body_resource_descriptor },
    { 13, &npc_kenkyuw2_body_resource_descriptor },
    { -1, NULL },
};
static NpcBodyResourceSlot npc_group_selection_resource_descriptor_list[] = {
    { 4, &npc_delta_w_body_resource_descriptor },
    { 11, &npc_nctrunk_body_resource_descriptor },
    { -1, NULL },
};
static NpcBodyResourceSlot npc_seabed_resource_descriptor_list[] = {
    { 2, &npc_leo_w_body_resource_descriptor },
    { -1, NULL },
};

BmlResource *TObjNpcNgcBase::body_resources[14];

void *TObjNpcNgcBase::create_kenkyuw2(void *set_data) {
    if (body_resources[13] != NULL) {
        TObjControl *control = new TObjControl(tl_04);
        return new TObjNpcNgcBase(control, set_data, body_resources[13]);
    }
    return NULL;
}

void *TObjNpcNgcBase::create_nctrunk2(void *set_data) {
    if (body_resources[12] != NULL) {
        TObjControl *control = new TObjControl(tl_04);
        return new TObjNpcNgcBase(control, set_data, body_resources[12]);
    }
    return NULL;
}

void *TObjNpcNgcBase::create_nctrunk(void *set_data) {
    if (body_resources[11] != NULL) {
        TObjControl *control = new TObjControl(tl_04);
        return new TObjNpcNgcBase(control, set_data, body_resources[11]);
    }
    return NULL;
}

void *TObjNpcNgcBase::create_gunsinei(void *set_data) {
    if (body_resources[10] != NULL) {
        TObjControl *control = new TObjControl(tl_04);
        return new TObjNpcNgcBase(control, set_data, body_resources[10]);
    }
    return NULL;
}

void *TObjNpcNgcBase::create_ncman(void *set_data) {
    if (body_resources[9] != NULL) {
        TObjControl *control = new TObjControl(tl_04);
        return new TObjNpcNgcBase(control, set_data, body_resources[9]);
    }
    return NULL;
}

void *TObjNpcNgcBase::create_ncwoman(void *set_data) {
    if (body_resources[8] != NULL) {
        TObjControl *control = new TObjControl(tl_04);
        return new TObjNpcNgcBase(control, set_data, body_resources[8]);
    }
    return NULL;
}

void *TObjNpcNgcBase::create_ncchild(void *set_data) {
    if (body_resources[7] != NULL) {
        TObjControl *control = new TObjControl(tl_04);
        return new TObjNpcNgcBase(control, set_data, body_resources[7]);
    }
    return NULL;
}

void *TObjNpcNgcBase::create_elly_t(void *set_data) {
    if (body_resources[6] != NULL) {
        TObjControl *control = new TObjControl(tl_04);
        return new TObjNpcNgcBase(control, set_data, body_resources[6]);
    }
    return NULL;
}

void *TObjNpcNgcBase::create_nol_t(void *set_data) {
    if (body_resources[5] != NULL) {
        TObjControl *control = new TObjControl(tl_04);
        return new TObjNpcNgcBase(control, set_data, body_resources[5]);
    }
    return NULL;
}

void *TObjNpcNgcBase::create_delta_w(void *set_data) {
    if (body_resources[4] != NULL) {
        TObjControl *control = new TObjControl(tl_04);
        return new TObjNpcNgcBase(control, set_data, body_resources[4]);
    }
    return NULL;
}

void *TObjNpcNgcBase::create_paganini_t(void *set_data) {
    if (body_resources[3] != NULL) {
        TObjControl *control = new TObjControl(tl_04);
        return new TObjNpcNgcBase(control, set_data, body_resources[3]);
    }
    return NULL;
}

void *TObjNpcNgcBase::create_leo_w(void *set_data) {
    if (body_resources[2] != NULL) {
        TObjControl *control = new TObjControl(tl_04);
        return new TObjNpcNgcBase(control, set_data, body_resources[2]);
    }
    return NULL;
}

void *TObjNpcNgcBase::create_karen_t(void *set_data) {
    if (body_resources[1] != NULL) {
        TObjControl *control = new TObjControl(tl_04);
        return new TObjNpcNgcBase(control, set_data, body_resources[1]);
    }
    return NULL;
}

void *TObjNpcNgcBase::create_michel_t(void *set_data) {
    if (body_resources[0] != NULL) {
        TObjControl *control = new TObjControl(tl_04);
        return new TObjNpcNgcBase(control, set_data, body_resources[0]);
    }
    return NULL;
}

void TObjNpcNgcBase::free_shared_resources() {
    s32 i;
    for (i = 13; i >= 0; i--) {
        if (body_resources[i] != NULL) {
            delete body_resources[i];
            body_resources[i] = NULL;
        }
    }
}

void TObjNpcNgcBase::load_resources() {
    NpcBodyResourceSlot *entry;
    s32 i;
    for (i = 0; i < 14; i++) {
        body_resources[i] = NULL;
    }
    entry = NULL;
    switch (get_current_floor_area()) {
    case AREA_PIONEER2_EP1:
    case AREA_PIONEER2_EP2:
        entry = npc_pioneer2_ep_resource_descriptor_list;
        break;
    case AREA_CENTRAL_CONTROL_AREA:
    case AREA_JUNGLE_NORTH:
    case AREA_JUNGLE_EAST:
    case AREA_MOUNTAIN:
    case AREA_SEASIDE:
    case AREA_SEASIDE_NIGHT:
    case AREA_TOWER:
        entry = npc_group_selection_resource_descriptor_list;
        break;
    case AREA_SEABED_UPPER:
    case AREA_SEABED_LOWER:
        entry = npc_seabed_resource_descriptor_list;
        break;
    }
    if (entry != NULL) {
        while (entry->slot != -1) {
            body_resources[entry->slot] = new BmlResource(1, entry->descriptor, 0, 0, NULL);
            entry++;
        }
    }
}

TObjNpcNgcBase::~TObjNpcNgcBase() {}

const char *TObjNpcNgcBase::class_name = "TObjNpcNgcBase";

TObjNpcNgcBase::TObjNpcNgcBase(TObject *parent, void *set_data, BmlResource *resource) : TObjNpcMale(parent) {
    m_name = class_name;
    apply_set_data(set_data);
    init_position_vectors();
    model = get_bml_model(resource, 0);
    texlist = get_bml_texlist(resource, 0);
    setup_common();
}
