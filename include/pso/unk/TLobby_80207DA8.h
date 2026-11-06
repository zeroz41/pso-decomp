#ifndef PSO_UNK_TLOBBY_80207DA8_H
#define PSO_UNK_TLOBBY_80207DA8_H

#include "types.h"

extern "C" {
int TLobby__sub_80207E24(void *p);
void TLobby__sub_80207E44(void);
int TLobby__sub_80207E48(void *p);
int TLobby__sub_80207F10(void *p);
void TLobby__sub_802083C0(void);
void TLobby__sub_80208648(void);
void TLobby__sub_80208884(void *a0);
}
s32 activate_first_floor_event(s32 idx, s32 id);
extern "C" {
void activate_triggered_floor_events(void);
}
void bswap_enemy_set_row(void *arg0);
void bswap_enemy_set_row_fields(void *arg0);
void bswap_floor_event_set(s32 idx);
void bswap_object_row_fields(void *arg0);
extern "C" {
void clear_floor_event_flags(void);
}
void create_empty_floor_event(void);
void dispatch_wave_event_action(s32 arg0);
extern "C" {
void free_team_buffers__6TLobbyFv(void);
s32 get_floor_scene_table(s32 arg0);
int link_matching_objects__6TLobbyFPv(void *p);
}
s32 load_area_event_set(s32 floor, s32 area, s32 terrain, s32 entities);
s32 read_be_u32(void);
u16 read_stream_u16(void);
unsigned char read_stream_u8(void);
void request_wave_event_stop(void);
extern "C" {
void reset_story_select__6TLobbyFv(void);
void run_floor_cleanup_callbacks__6TLobbyFi(s32 arg0);
}
s32 run_floor_initialize_callbacks(s32 arg0);
extern "C" {
s32 run_wave_event_actions(void);
}
void send_6x05_wave_clear_switch(s32 arg0);
void send_6x05_wave_set_switch(s16 arg0);
void send_6x67_wave_trigger_event(s32 arg0);
extern "C" {
void set_destroy_event__6TLobbyFi(int a0);
}
s32 set_floor_event_flags(s32 arg0, s32 arg1, s32 arg2);
extern "C" {
int spawn_objects_at_pos__6TLobbyFPv(void *p);
}
void swap_object_row_endian(void *arg0);

#endif
