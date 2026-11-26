#ifndef PSO_MAP_AREAEVENTSET_H
#define PSO_MAP_AREAEVENTSET_H

#include "types.h"

void clear_floor_event_flags(void);
// The TSetEvtDestroy event id a destroy-event spawn reports, -1 for none.
void set_destroy_event_id(int destroy_event);
int get_destroy_event_id();
// Bytes of the per-record flags every loaded floor event set shares in a sync.
s32 count_floor_event_sync_bytes();
void import_floor_event_flags(s16 *records, u16 size);
s32 export_floor_event_flags(s16 *dest);
// The floor's event set storage from the area event set heap, NULL when taken.
u8 *alloc_floor_event_set(s32 floor, s32 size);
// Copies a received event set in as the floor's; 0 when the floor has one.
s32 add_floor_event_set(s32 floor, saddr data, s32 size);
void free_floor_event_sets();
s32 load_all_floor_event_sets();
void free_area_event_sets();
// Loads every floor's ".evt" set from gsl_set_event.gsl.
void load_area_event_sets();
void free_area_event_set_heap();
void create_area_event_set_heap();

#endif
