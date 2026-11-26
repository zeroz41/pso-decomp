// The quest collision triggers (TObjQuestColBase and its subclasses) and TQuestColCtrl, the task that owns them.
// One TU: the class names in .rodata/.sdata run ColBase..Col2 in this source order, while the text runs Col2..ColBase
// and the vtables Col2..ColBase (reverse key-function order): built -inline off,deferred (configure.py).
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/unk/TQuestManager.h"
#include "types.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/vector.h"
#include "pso/render/NinjaUtil.h"
#include "pso/network/client_id.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/base/TObjChara.h"
#include "pso/object/quest/TObjQuestColBase.h"
#include "pso/object/quest/TObjQuestCol.h"
#include "pso/object/quest/TObjQuestColA.h"
#include "pso/object/quest/TObjQuestColALock.h"
#include "pso/object/quest/TObjQuestColApc.h"
#include "pso/object/quest/TObjQuestColApcIN.h"
#include "pso/object/quest/TObjQuestColApcINW.h"
#include "pso/object/quest/TObjQuestColALock2.h"
#include "pso/object/quest/TObjQuestCol2.h"
#include "pso/quest/TQuestColCtrl.h"
#include "pso/quest/TQuestThread.h"
#include "pso/npc/TNpcPlayer.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/object/base/ActorCollision.h"
#include "pso/player/TObjContainerCommon.h"
#include "pso/system/ControllerInput.h"
#include "pso/network/TLobby.h"
#include "pso/system/task/TMainTask.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/object/base/TObjBase.h"
#include "pso/player/PlayerSlots.h"
#include "pso/npc/NpcPartnerControl.h"

extern NJS_ARGB debug_color_green_half_alpha;
extern NJS_ARGB debug_color_purple_half_alpha;

extern "C" {
void debug_draw_sphere(const Vec *pos, const NJS_ARGB *color, f32 radius);
// render_util.h declares (pos, color, size); the lock code still loads its collision body into r5 first, which
// only a third argument explains, though debug_draw_uniform_scaled never reads r5 (TObjRoomId passes nothing there).
void debug_draw_uniform_scaled(const Vec *pos, const NJS_ARGB *color, CollisionBody *body, f32 size);
}

u16 quest_collision_next_id;
s32 quest_collision_warp_pending;
TObject *quest_collision_task_root;
s32 quest_col_base_instance_count;

// Written first, so emitted last (after TObjQuestColBase's ctor), ahead of the implicit dtors.
int TObjQuestColBase::is_triggered() {
    return 0;
}

TQuestThread *TObjQuestColBase::start_quest_thread() {
    return NULL;
}

void TQuestColCtrl::sub_80196EC0() {
    quest_collision_warp_pending = 0;
}

TObjQuestCol2::~TObjQuestCol2() { }

// --- TObjQuestColBase ---

const char *quest_col_base_class_name = "TObjQuestColBase";

TObjQuestColBase::TObjQuestColBase(TObject *parent, void *set_data) : TObjCollidable(parent) {
    m_name = quest_col_base_class_name;
    apply_object_set_data(set_data);
    if (entity_id == 0xFFFF) {
        entity_id = alloc_object_ids(0);
    }
    m_id = quest_collision_next_id++;
    radius = scale.x;
    label = set_params[0];
    outside = 1;
    quest_thread = NULL;
    quest_col_base_instance_count++;
}

TObjQuestColBase::~TObjQuestColBase() {
    quest_col_base_instance_count--;
}

void TObjQuestColBase::run_task() {
    if (quest_thread != NULL && quest_thread->all_parents_unqueued_for_destruction() == 0) {
        quest_thread = NULL;
    }
    if (quest_thread == NULL && is_triggered() != 0) {
        quest_thread = start_quest_thread();
    }
}

void TObjQuestColBase::render() { }

void TObjQuestColBase::draw_debug_bounds() {
    if (update_object_view_visibility(200.0f, 10.0f) != 0) {
        debug_draw_sphere(&position, &debug_color_green_half_alpha, 2.0f * radius);
    }
}

s32 TObjQuestColBase::is_within_range(f32 range_sq) {
    TObjPlayer *player = get_player_by_client_id(local_client_id);
    if (player != NULL && xyz_distance_squared(&player->position, &position) < range_sq) {
        return 1;
    }
    return 0;
}

s32 TObjQuestColBase::update_trigger_state(f32 range) {
    if (is_within_range(range * range) != 0) {
        if ((s32)outside != 0) {
            outside = 0;
            return 1;
        }
        return 0;
    }
    if ((s32)outside != 0) {
        return 2;
    }
    outside = 1;
    return 3;
}

// --- TObjQuestCol ---

const char *quest_col_class_name = "TObjQuestCol";

TObjQuestCol::TObjQuestCol(TObject *parent, void *set_data) : TObjQuestColBase(parent, set_data) {
    m_name = quest_col_class_name;
}

int TObjQuestCol::is_triggered() {
    if (update_trigger_state(radius) == 1) {
        return 1;
    }
    return 0;
}

TQuestThread *TObjQuestCol::start_quest_thread() {
    TQuestThreadBoard::destroy_board();
    return TQuestThread::create(label);
}

void *TObjQuestCol::create(void *set_data) {
    return new TObjQuestCol(quest_collision_task_root, set_data);
}

TObjQuestCol *create_quest_col(ObjectSetData *arg, s32 *out_id) {
    TObjQuestCol *o = new TObjQuestCol(quest_collision_task_root, arg);
    if (o != NULL) {
        *out_id = o->m_id;
    } else {
        *out_id = -1;
    }
    return o;
}

// --- TObjQuestColA ---

const char *quest_col_a_class_name = "TObjQuestColA";

TObjQuestColA::TObjQuestColA(TObject *parent, void *set_data) : TObjQuestColBase(parent, set_data) {
    m_name = quest_col_a_class_name;
}

int TObjQuestColA::is_triggered() {
    TObjPlayer *player;
    s32 trigger_state;

    player = get_player_by_client_id(local_client_id);
    if (player != NULL) {
        if (player->is_controls_locked() != 0) {
            player->enable_action_input();
            return 0;
        }
        if (player->is_quest_interaction_blocked() != 0) {
            player->enable_action_input();
            return 0;
        }
        trigger_state = update_trigger_state(radius);
        if (trigger_state == 1) {
            player->disable_primary_action_input();
        }
        if (trigger_state == 3) {
            player->enable_action_input();
        }
        if (trigger_state == 0) {
            player->disable_primary_action_input();
            if (test_pressed_buttons_packed(&controller_input_state.controllers[0], 4) != 0) {
                return 1;
            }
        }
    }
    return 0;
}

TQuestThread *TObjQuestColA::start_quest_thread() {
    TQuestThreadBoard::destroy_board();
    return TQuestThread::create(label);
}

void *TObjQuestColA::create(void *set_data) {
    return new TObjQuestColA(quest_collision_task_root, set_data);
}

TObjQuestColA *create_quest_col_a(ObjectSetData *arg, s32 *out_id) {
    TObjQuestColA *o = new TObjQuestColA(quest_collision_task_root, arg);
    if (o != NULL) {
        *out_id = o->m_id;
    } else {
        *out_id = -1;
    }
    return o;
}

// --- TObjQuestColALock ---

// The lock's one collision body; init_collision_body_parts copies it, the ctors raise it by scale.y.
static const CollisionBody quest_col_a_lock_collision_desc = {
    { 0.0f, 0.0f, 0.0f }, 5.0f, 0.0f, 0, 0x30003, { 0.0f, 0.0f, 0.0f }, 0.0f,
};

const char *obj_quest_col_alock_class_name = "TObjQuestColALock";

TObjQuestColALock::TObjQuestColALock(TObject *parent, void *set_data) : TObjQuestColBase(parent, set_data) {
    m_name = obj_quest_col_alock_class_name;
    init_collision_body_parts(this, &quest_col_a_lock_collision_desc, 1);
    set_indexed_flags(0, 0xF0);
    bodies->offset.y += scale.y;
    refresh_collision_body_centers();
    actorFlags |= 0x40000000;
    register_object_by_id();
}

TObjQuestColALock::~TObjQuestColALock() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

int TObjQuestColALock::is_triggered() {
    TObjPlayer *player;
    s32 trigger_state;

    player = get_player_by_client_id(local_client_id);
    if (player != NULL) {
        if (player->is_controls_locked() != 0) {
            player->enable_action_input();
            return 0;
        }
        if (player->is_quest_interaction_blocked() != 0) {
            player->enable_action_input();
            return 0;
        }
        submit_cursor_candidate(this, -1);
        trigger_state = update_trigger_state(radius);
        if (trigger_state == 1) {
            player->disable_primary_action_input();
        }
        if (trigger_state == 3) {
            player->enable_action_input();
        }
        if (trigger_state == 0) {
            player->disable_primary_action_input();
            if (test_pressed_buttons_packed(&controller_input_state.controllers[0], 4) != 0) {
                return 1;
            }
        }
    }
    return 0;
}

TQuestThread *TObjQuestColALock::start_quest_thread() {
    TQuestThreadBoard::destroy_board();
    return TQuestThread::create(label);
}

void TObjQuestColALock::draw_debug_bounds() {
    if (update_object_view_visibility(200.0f, 10.0f) != 0) {
        debug_draw_sphere(&position, &debug_color_green_half_alpha, 2.0f * radius);
        debug_draw_uniform_scaled(&position, &debug_color_purple_half_alpha, bodies, 2.0f * bodies->radius);
    }
}

TObjQuestColALock *create_quest_col_alock(ObjectSetData *arg, s32 *out_id) {
    TObjQuestColALock *o = new TObjQuestColALock(quest_collision_task_root, arg);
    if (o != NULL) {
        *out_id = o->m_id;
    } else {
        *out_id = -1;
    }
    return o;
}

// --- TObjQuestColApc ---

const char *obj_quest_col_apc_class_name = "TObjQuestColApc";

TObjQuestColApc::TObjQuestColApc(TObject *parent, void *set_data) : TObjQuestColBase(parent, set_data) {
    m_name = obj_quest_col_apc_class_name;
}

int TObjQuestColApc::is_triggered() {
    s32 i;
    TObjPlayer *p;
    for (i = 0; i < 12; i++) {
        p = get_player_by_client_id(i);
        if (p != NULL && ((TObjChara *)p)->obj_isState3_324() == 1) {
            if (xyz_distance_squared(&p->position, &position) < radius * radius) {
                return 1;
            }
        }
    }
    return 0;
}

TQuestThread *TObjQuestColApc::start_quest_thread() {
    TQuestThreadBoard::destroy_board();
    return TQuestThread::create(label);
}

TObjQuestColApc *create_quest_col_apc(ObjectSetData *arg, s32 *out_id) {
    TObjQuestColApc *o = new TObjQuestColApc(quest_collision_task_root, arg);
    if (o != NULL) {
        *out_id = o->m_id;
    } else {
        *out_id = -1;
    }
    return o;
}

// --- TObjQuestColApcIN ---

const char *quest_col_apc_in_name = "TObjQuestColApcIN";

TObjQuestColApcIN::TObjQuestColApcIN(TObject *parent, void *set_data) : TObjQuestColBase(parent, set_data) {
    m_name = quest_col_apc_in_name;
    party_radius = scale.y;
}

int TObjQuestColApcIN::is_triggered() {
    TObjPlayer *p = get_player_by_client_id(local_client_id);
    if (p != NULL) {
        if (xyz_distance_squared(&p->position, &position) < radius * radius) {
            s32 i;
            for (i = 0; i < 12; i++) {
                if (i != local_client_id) {
                    TObjPlayer *q = get_player_by_client_id(i);
                    if (q != NULL) {
                        if (xyz_distance_squared(&p->position, &q->position) < party_radius * party_radius) {
                            return 1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}

TQuestThread *TObjQuestColApcIN::start_quest_thread() {
    TQuestThreadBoard::destroy_board();
    return TQuestThread::create(label);
}

TObjQuestColApcIN *create_quest_col_apc_in(ObjectSetData *arg, s32 *out_id) {
    TObjQuestColApcIN *o = new TObjQuestColApcIN(quest_collision_task_root, arg);
    if (o != NULL) {
        *out_id = o->m_id;
    } else {
        *out_id = -1;
    }
    return o;
}

// --- TObjQuestColApcINW ---

const char *quest_col_apc_inw_name = "TObjQuestColApcINW";

// Where the warp sends the other players once one strays too far (is_triggered sets it).
Vec quest_col_apc_warp_target_pos;

TObjQuestColApcINW::TObjQuestColApcINW(TObject *parent, void *set_data) : TObjQuestColBase(parent, set_data) {
    m_name = quest_col_apc_inw_name;
    party_radius = scale.y;
    warp_pos.z = 0.0f;
    warp_pos.y = 0.0f;
    warp_pos.x = 0.0f;
}

int TObjQuestColApcINW::is_triggered() {
    if (update_trigger_state(radius) == 1) {
        TObjPlayer *p = get_player_by_client_id(local_client_id);
        if (p == NULL) {
            return 0;
        }
        s32 i;
        for (i = 0; i < 12; i++) {
            if (i != local_client_id) {
                TObjPlayer *q = get_player_by_client_id(i);
                if (q != NULL) {
                    if (xz_distance_squared(&q->position, &p->position) > party_radius * party_radius) {
                        quest_collision_warp_pending = 1;
                        VecCopy(&quest_col_apc_warp_target_pos, &warp_pos);
                    }
                }
            }
        }
        return 1;
    }
    return 0;
}

TQuestThread *TObjQuestColApcINW::start_quest_thread() {
    TQuestThreadBoard::destroy_board();
    return TQuestThread::create(label);
}

void send_quest_collision_warp(void) {
    if (quest_collision_warp_pending != 0) {
        send_warp_toward_player(1, &quest_col_apc_warp_target_pos);
    }
}

TObjQuestColApcINW *create_quest_col_apc_inw__6TLobbyFPvPv(ObjectSetData *arg, s32 *out_id) {
    TObjQuestColApcINW *o = new TObjQuestColApcINW(quest_collision_task_root, arg);
    if (o != NULL) {
        *out_id = o->m_id;
        return o;
    } else {
        *out_id = -1;
        return NULL;
    }
}

// --- TQuestColCtrl ---

const char *quest_col_ctrl_name = "TQuestColCtrl";

TQuestColCtrl::TQuestColCtrl(TObject *parent) : TObject(parent) {
    m_name = quest_col_ctrl_name;
}

TQuestColCtrl::~TQuestColCtrl() {
    if (quest_collision_task_root != NULL) {
        delete quest_collision_task_root;
        quest_collision_task_root = NULL;
    }
}

void TQuestColCtrl::run_task() {
    sub_80196EC0();
    if (quest_collision_task_root != NULL) {
        quest_collision_task_root->run_tasks();
    }
}

void TQuestColCtrl::render() { }

void TQuestColCtrl::init() {
    quest_collision_task_root = new TObject(NULL);
    new TQuestColCtrl(tl_05);
}

void TQuestColCtrl::delete_by_param(s32 id) {
    TObject *next;
    TObject *cur;
    if (id < 0) {
        return;
    }
    next = quest_collision_task_root->m_down;
    while (quest_collision_task_root->m_down != 0 && next != 0) {
        cur = next;
        next = cur->m_next;
        if ((cur->check_value_equals(quest_col_class_name) != 0
             || cur->check_value_equals(quest_col_a_class_name) != 0
             || cur->check_value_equals(obj_quest_col_alock_class_name) != 0
             || cur->check_value_equals(obj_quest_col_apc_class_name) != 0
             || cur->check_value_equals(quest_col_apc_in_name) != 0
             || cur->check_value_equals(quest_col_apc_inw_name) != 0)
            && cur->m_id == id) {
            cur->queue_destruction();
            return;
        }
    }
}

TObjQuestColBase *TQuestColCtrl::find_by_id(u16 id) {
    TObject *next;
    TObject *cur;
    next = quest_collision_task_root->m_down;
    while (quest_collision_task_root->m_down != 0 && next != 0) {
        cur = next;
        next = cur->m_next;
        if ((cur->check_value_equals(quest_col_class_name) != 0
             || cur->check_value_equals(quest_col_a_class_name) != 0
             || cur->check_value_equals(obj_quest_col_alock_class_name) != 0
             || cur->check_value_equals(obj_quest_col_apc_class_name) != 0
             || cur->check_value_equals(quest_col_apc_in_name) != 0
             || cur->check_value_equals(quest_col_apc_inw_name) != 0)
            && id == static_cast<TObjQuestColBase *>(cur)->get_entity_id()) {
            return static_cast<TObjQuestColBase *>(cur);
        }
    }
    return 0;
}

// --- TObjQuestColALock2 ---

const char *quest_col_a_lock2_name = "TObjQuestColALock2";

TObjQuestColALock2::TObjQuestColALock2(TObject *parent, void *set_data) : TObjQuestColBase(parent, set_data) {
    m_name = quest_col_a_lock2_name;
    init_collision_body_parts(this, &quest_col_a_lock_collision_desc, 1);
    set_indexed_flags(0, 0xF0);
    bodies->offset.y += scale.y;
    refresh_collision_body_centers();
    actorFlags |= 0x40000000;
    register_object_by_id();
    manager_kind = set_params[1];
    if (manager_kind < 0) {
        manager_kind = 0;
    }
    if (manager_kind > 1) {
        manager_kind = 1;
    }
    switch (manager_kind) {
    case 0:
        thread_root = quest_mission_manager;
        break;
    case 1:
        thread_root = quest_area_manager;
        break;
    default:
        thread_root = NULL;
        break;
    }
}

TObjQuestColALock2::~TObjQuestColALock2() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

int TObjQuestColALock2::is_triggered() {
    TObjPlayer *player;
    s32 trigger_state;

    player = get_player_by_client_id(local_client_id);
    if (player != NULL) {
        if (player->is_controls_locked() != 0) {
            player->enable_action_input();
            return 0;
        }
        if (player->is_quest_interaction_blocked() != 0) {
            player->enable_action_input();
            return 0;
        }
        submit_cursor_candidate(this, -1);
        trigger_state = update_trigger_state(radius);
        if (trigger_state == 1) {
            player->disable_primary_action_input();
        }
        if (trigger_state == 3) {
            player->enable_action_input();
        }
        if (trigger_state == 0) {
            player->disable_primary_action_input();
            if (test_pressed_buttons_packed(&controller_input_state.controllers[0], 4) != 0) {
                return 1;
            }
        }
    }
    return 0;
}

TQuestThread *TObjQuestColALock2::start_quest_thread() {
    TQuestThread *thread;
    TQuestThreadBoard::destroy_board();
    thread = NULL;
    if (thread_root != NULL) {
        thread = new TQuestThread(thread_root, label);
        if (thread != NULL) {
            thread->set_parent(tl_00);
        }
    }
    return thread;
}

void TObjQuestColALock2::draw_debug_bounds() {
    if (update_object_view_visibility(200.0f, 10.0f) != 0) {
        debug_draw_sphere(&position, &debug_color_green_half_alpha, 2.0f * radius);
        debug_draw_uniform_scaled(&position, &debug_color_purple_half_alpha, bodies, 2.0f * bodies->radius);
    }
}

void *TObjQuestColALock2::create(void *set_data) {
    return new TObjQuestColALock2(quest_collision_task_root, set_data);
}

// --- TObjQuestCol2 ---

const char *quest_col2_name = "TObjQuestCol2";

TObjQuestCol2::TObjQuestCol2(TObject *parent, void *set_data) : TObjQuestColBase(parent, set_data) {
    m_name = quest_col2_name;
    manager_kind = set_params[1];
    if (manager_kind < 0) {
        manager_kind = 0;
    }
    if (manager_kind > 1) {
        manager_kind = 1;
    }
    switch (manager_kind) {
    case 0:
        thread_root = quest_mission_manager;
        break;
    case 1:
        thread_root = quest_area_manager;
        break;
    default:
        thread_root = NULL;
        break;
    }
}

int TObjQuestCol2::is_triggered() {
    if (update_trigger_state(radius) == 1) {
        return 1;
    }
    return 0;
}

TQuestThread *TObjQuestCol2::start_quest_thread() {
    TQuestThread *thread;
    TQuestThreadBoard::destroy_board();
    thread = NULL;
    if (thread_root != NULL) {
        thread = new TQuestThread(thread_root, label);
        if (thread != NULL) {
            thread->set_parent(tl_00);
        }
    }
    return thread;
}

void *TObjQuestCol2::create(void *set_data) {
    return new TObjQuestCol2(quest_collision_task_root, set_data);
}
