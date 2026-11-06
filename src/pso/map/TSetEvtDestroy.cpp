#include "pso/enemy/TEnemyTaskList.h"
#include "pso/item/drop/TItemDrop_80105D0C.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/unk/TLobby.h"
#include "pso/system/EventShuffleTable.h"

#include "pso/map/TSetEvtDestroy.h"

extern "C" void queue_destruction__7TObjectFv(void*);

extern "C" {
extern const char TSetEvtDestroy_class_name[] = "TSetEvtDestroy";
const char* TSetEvtDestroy_name = TSetEvtDestroy_class_name;
s32 check_value_equals__13TUnk_804B6C24Fl(void*, s32);
}

void queue_destroy_event_descendants(TObject* root) {
    TObject* p = root->m_down;
    TObject* cur;
    while (root->m_down != 0 && p != 0) {
        cur = p;
        p = p->m_next;
        if (check_value_equals__13TUnk_804B6C24Fl(cur, (s32)TSetEvtDestroy_name) != 0) {
            queue_destruction__7TObjectFv(cur);
        } else {
            queue_destroy_event_descendants(cur);
        }
    }
}

extern "C" {

s32 run_wave_event_actions();
void TLobby__sub_80208884(void*);
}
void notify_partner_room_cleared(s32);

void TSetEvtDestroy::run_task() {
    switch (m_phase) {
    case 0:
        if (m_event_record->flags & 0x10) {
            m_phase = 2;
        }
        if (--m_countdown < 0) {
            if (TLobby::spawn_matching_objects(m_event_record->spawn_arg0, m_event_record->spawn_arg1, (s32)m_enemy_tasks) != 0) {
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
        queue_destruction__7TObjectFv(this);
        break;
    }
}

TSetEvtDestroy::~TSetEvtDestroy() {
    if (m_enemy_tasks != nullptr) {
        queue_destruction__7TObjectFv(m_enemy_tasks);
        m_enemy_tasks = nullptr;
    }
    if (m_event_record != nullptr) {
        m_event_record->flags &= ~2;
    }
}

#include "types.h"

struct RecoveredGlobal_802093EC_lbl_805139F8 {
    s32 value;
    u8 remaining[0x44];
};

extern RecoveredGlobal_802093EC_lbl_805139F8 lobby_slot_ptr_table;
s32 get_area_event_data(s32 arg0);
s32 next_event_shuffle_entry(EventShuffleTable *s);

void queue_destruction__7TObjectFv(void *);
void init_event_shuffle_table(EventShuffleTable *arg0, s32 arg1);
void shuffle_event_entries(EventShuffleTable *arg0);
typedef char RecoveredGlobal_802093EC_lbl_805139F8_size[sizeof(RecoveredGlobal_802093EC_lbl_805139F8) == 0x48 ? 1 : -1];

TSetEvtDestroy::TSetEvtDestroy(TObject* parent, SetDestroyEventRecord* event) : TObject(parent) {
    s32* p;
    void* t;
    m_name = TSetEvtDestroy_name;
    p = (s32*)get_area_event_data(get_current_floor());
    m_event_record = NULL;
    m_enemy_tasks = NULL;
    if (p != NULL) {
        m_event_record = event;
        m_event_context.stream = (u8*)p + *p;
        m_event_context.cursor = event->action_offset;
        m_countdown = event->delay_ticks;
        m_phase = 0;
        t = new TEnemyTaskList(this, 0x20);
        m_enemy_tasks = (TEnemyTaskList*)t;
    } else {
        queue_destruction__7TObjectFv(this);
    }
}

s32 get_area_event_data(s32 arg0) {
    if (arg0 < 0x12) {
        return *(s32 *)((s8 *)&lobby_slot_ptr_table.value + (arg0 * 4));
    }
    return 0;
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
