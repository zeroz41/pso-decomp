#ifndef PSO_SYSTEM_GBADOWNLOADRUNTIME_H
#define PSO_SYSTEM_GBADOWNLOADRUNTIME_H

#include "types.h"

extern u8 *gba_download_data_buffer;
extern u32 gba_download_data_size;
extern volatile s32 gba_download_state;
extern u8 gba_identifier_value;
extern u16 gba_identifier_slot_plus_1;

void gba_init(void);
void stamp_joyboot_image(s32 unused, s32 stamp_enabled);
void probe_gba_device(void);
void gba_clear_identifiers(void);
struct GbaJoybootState;
void reset_joyboot_state(GbaJoybootState *state);

void gba_download_destroy_graph();
void gba_download_create_graph();
void gba_download_free_buffer();
void gba_download_alloc_buffer();
void gba_download_load_file(const char *filename);
u8 gba_download_update_graph();
void gba_calc_joyboot_checksum();
s32 gba_start_joyboot();
void gba_joyboot_set_send_buffer(u8 *buffer, s32 length);

struct DayMinuteTicks { s32 days; s32 mins; s32 ticks; };

#endif
