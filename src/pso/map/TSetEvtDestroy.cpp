#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/enemy/TEnemyTaskList.h"
#include "pso/unk/TLobby_80207DA8.h"
#include "pso/item/drop/TItemDrop_80105D0C.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/unk/TLobby.h"
#include "pso/system/EventShuffleTable.h"

#include "pso/map/TSetEvtDestroy.h"
#include "pso/system/task/TObject.h"
#include "pso/player/TUnk_804B6C24.h"
#include "pso/npc/NpcPartnerControl.h"

extern const char TSetEvtDestroy_class_name[] = "TSetEvtDestroy";
const char* TSetEvtDestroy_name = TSetEvtDestroy_class_name;

void queue_destroy_event_descendants(TObject* root) {
    TObject* p = root->m_down;
    TObject* cur;
    while (root->m_down != 0 && p != 0) {
        cur = p;
        p = p->m_next;
        if (cur->check_value_equals(TSetEvtDestroy_name) != 0) {
            cur->queue_destruction();
        } else {
            queue_destroy_event_descendants(cur);
        }
    }
}


void TSetEvtDestroy::run_task() {
    switch (m_phase) {
    case 0:
        if (m_event_record->flags & 0x10) {
            m_phase = 2;
        }
        if (--m_countdown < 0) {
            if (TLobby::spawn_matching_objects(m_event_record->spawn_arg0, m_event_record->spawn_arg1, (saddr)m_enemy_tasks) != 0) {
                m_phase = 1;
            } else {
                m_phase = 2;
            }
        }
        break;
    case 1:
        if (m_enemy_tasks->has_undefeated_entry() == 0) {
            m_event_record->flags |= 0x10;
            m_phase = 2;
        }
        break;
    case 2:
        if (!(m_event_record->flags & 8)) {
            m_event_record->flags |= 8;
            TLobby__sub_80208884(&m_event_context);
            if (run_wave_event_actions() == 0) {
                notify_partner_room_cleared(m_event_record->spawn_arg0);
            }
        }
        m_event_record->flags &= ~4;
        queue_destruction();
        break;
    }
}

TSetEvtDestroy::~TSetEvtDestroy() {
    if (m_enemy_tasks != nullptr) {
        m_enemy_tasks->queue_destruction();
        m_enemy_tasks = nullptr;
    }
    if (m_event_record != nullptr) {
        m_event_record->flags &= ~2;
    }
}

#include "types.h"

s32 next_event_shuffle_entry(EventShuffleTable *s);

void init_event_shuffle_table(EventShuffleTable *arg0, s32 arg1);
void shuffle_event_entries(EventShuffleTable *event_shuffle_table);

TSetEvtDestroy::TSetEvtDestroy(TObject* parent, SetDestroyEventRecord* event) : TObject(parent) {
    FloorEventSet* set;
    m_name = TSetEvtDestroy_name;
    set = get_area_event_data(get_current_floor());
    m_event_record = NULL;
    m_enemy_tasks = NULL;
    if (set != NULL) {
        m_event_record = event;
        m_event_context.stream = (u8*)set + set->action_stream_offset;
        m_event_context.cursor = event->action_offset;
        m_countdown = event->delay_ticks;
        m_phase = 0;
        m_enemy_tasks = new TEnemyTaskList(this, 0x20);
    } else {
        queue_destruction();
    }
}

FloorEventSet *get_area_event_data(s32 floor) {
    if (floor < 0x12) {
        return floor_event_sets[floor];
    }
    return NULL;
}

s32 next_event_shuffle_entry(EventShuffleTable *s) {
    if (s->count < s->cursor) return 0;
    return s->entries[s->cursor++];
}
void shuffle_event_entries(EventShuffleTable *event_shuffle_table) {
    EventShuffleTable *s = event_shuffle_table;
    s32 i = 0;
    for (; i < s->count; i++) {
        s32 k = item_drop_rng_below(s->rngState, s->count);
        s32 t = s->entries[i];
        s->entries[i] = s->entries[k];
        s->entries[k] = t;
    }
}

void init_event_shuffle_table(EventShuffleTable *event_shuffle_table, s32 arg1) {
    s32 off;
    s32 i = 0;
    event_shuffle_table->cursor = off = 0;
    event_shuffle_table->count = arg1;
    while (i < event_shuffle_table->count) {
        *(s32 *)((u8 *)event_shuffle_table->entries + off) = i;
        i++;
        off += 4;
    }
    shuffle_event_entries(event_shuffle_table);
    shuffle_event_entries(event_shuffle_table);
    shuffle_event_entries(event_shuffle_table);
    shuffle_event_entries(event_shuffle_table);
}
