#ifndef PSO_MAP_TSETEVTDESTROY_H
#define PSO_MAP_TSETEVTDESTROY_H

#include "pso/system/task/TObject.h"
#include "types.h"

struct SetDestroyEventRecord {
    s32 id;          // matched by activate_first_floor_event and set_floor_event_flags (name inferred)
    s16 flags;
    s16 create_type; // index into floor_event_create_table: 0 none, 1 TSetEvtDestroy (name inferred)
    s16 spawn_arg0;
    s16 spawn_arg1;
    s32 delay_ticks;
    s32 action_offset;
};
struct WaveEventContext { u8* stream; s32 cursor; };

// One floor's ".evt" file from gsl_set_event.gsl: a header, then count event records. TSetEvtDestroy runs
// the action stream that starts action_stream_offset bytes into the file (name inferred).
struct FloorEventSet {
    s32 action_stream_offset;
    s32 pad_4;
    s32 count;
    s32 pad_C;
    SetDestroyEventRecord records[1];
};

// Each floor's loaded event set, NULL when the floor has none.
extern FloorEventSet *floor_event_sets[18];

FloorEventSet *get_area_event_data(s32 floor);

class TEnemyTaskList;

class TSetEvtDestroy : public TObject {
public:
 SetDestroyEventRecord* m_event_record;
 WaveEventContext m_event_context;
 s32 m_countdown;
 s32 m_phase;
 TEnemyTaskList* m_enemy_tasks;

public:
    TSetEvtDestroy(TObject* parent, SetDestroyEventRecord* event);
    virtual ~TSetEvtDestroy();
    virtual void run_task();
};

void queue_destroy_event_descendants(TObject* root);

#include <stddef.h>
LAYOUT_ASSERT(TSetEvtDestroySize, sizeof(TSetEvtDestroy) == 0x34);
LAYOUT_ASSERT(TSetEvtDestroyEventOffset, offsetof(TSetEvtDestroy, m_event_record) == 0x1C);
LAYOUT_ASSERT(SetDestroyEventRecordSize, sizeof(SetDestroyEventRecord) == 0x14);
LAYOUT_ASSERT(SetDestroyEventFlagsOffset, offsetof(SetDestroyEventRecord, flags) == 4);
LAYOUT_ASSERT(SetDestroyEventDelayOffset, offsetof(SetDestroyEventRecord, delay_ticks) == 0xC);
LAYOUT_ASSERT(SetDestroyEventActionOffset, offsetof(SetDestroyEventRecord, action_offset) == 0x10);
LAYOUT_ASSERT(TSetEvtDestroyContextOffset, offsetof(TSetEvtDestroy, m_event_context) == 0x20);
LAYOUT_ASSERT(TSetEvtDestroyCountdownOffset, offsetof(TSetEvtDestroy, m_countdown) == 0x28);
LAYOUT_ASSERT(TSetEvtDestroyPhaseOffset, offsetof(TSetEvtDestroy, m_phase) == 0x2C);
LAYOUT_ASSERT(TSetEvtDestroyTaskListOffset, offsetof(TSetEvtDestroy, m_enemy_tasks) == 0x30);
LAYOUT_ASSERT(FloorEventSetCountOffset, offsetof(FloorEventSet, count) == 8);
LAYOUT_ASSERT(FloorEventSetRecordsOffset, offsetof(FloorEventSet, records) == 0x10);
LAYOUT_ASSERT(WaveEventContextSize, sizeof(WaveEventContext) == 8);
LAYOUT_ASSERT(WaveEventStreamOffset, offsetof(WaveEventContext, stream) == 0);
LAYOUT_ASSERT(WaveEventCursorOffset, offsetof(WaveEventContext, cursor) == 4);
LAYOUT_ASSERT(SetDestroyEventSpawn0Offset, offsetof(SetDestroyEventRecord, spawn_arg0) == 8);
LAYOUT_ASSERT(SetDestroyEventSpawn1Offset, offsetof(SetDestroyEventRecord, spawn_arg1) == 0xA);
LAYOUT_ASSERT(SetDestroyBaseSize, sizeof(TObject) == 0x1C);
LAYOUT_ASSERT(SetDestroyBaseNameOffset, offsetof(TObject, m_name) == 0);
LAYOUT_ASSERT(SetDestroyBaseFlagsOffset, offsetof(TObject, m_flags) == 4);
LAYOUT_ASSERT(SetDestroyBaseIdOffset, offsetof(TObject, m_id) == 6);
LAYOUT_ASSERT(SetDestroyBasePrevOffset, offsetof(TObject, m_prev) == 8);
LAYOUT_ASSERT(SetDestroyBaseNextOffset, offsetof(TObject, m_next) == 0xC);
LAYOUT_ASSERT(SetDestroyBaseParentOffset, offsetof(TObject, m_up) == 0x10);
LAYOUT_ASSERT(SetDestroyBaseChildOffset, offsetof(TObject, m_down) == 0x14);

#endif
