#ifndef PSO_UNK_TLOBBY_80207DA8_H
#define PSO_UNK_TLOBBY_80207DA8_H

#include "types.h"

extern "C" {
void TLobby__sub_80207E24(void *p, s32 size);
void TLobby__sub_80207E44(void);
void TLobby__sub_80207E48(void);
void TLobby__sub_80207F10(void);
}
void free_forest_rel_work_buffer(void);
extern "C" {
void TLobby__sub_80208648(void);
void TLobby__sub_80208884(void *a0);
}
s32 activate_first_floor_event(s32 idx, s32 id);
void activate_triggered_floor_events(void);
void bswap_enemy_set_row(void *row_ptr);
void bswap_enemy_set_row_fields(void *placement_ptr);
void bswap_floor_event_set(s32 idx);
void bswap_object_row_fields(void *placement_ptr);
void clear_floor_event_flags(void);
struct SetDestroyEventRecord;
void create_empty_floor_event(SetDestroyEventRecord *event);
void spawn_destroy_event(SetDestroyEventRecord *event);
void dispatch_wave_event_action(u8 opcode);
saddr get_floor_scene_table(s32 area);
extern "C" {
int link_matching_objects__6TLobbyFPv(void *p);
}
s32 load_area_event_set(s32 floor, s32 area, s32 terrain, s32 entities);
s32 read_be_u32(void);
u16 read_stream_u16(void);
unsigned char read_stream_u8(void);
void request_wave_event_stop(void);
extern "C" {
void run_floor_cleanup_callbacks__6TLobbyFi(s32 floor);
}
s32 run_floor_initialize_callbacks(s32 floor);
s32 run_wave_event_actions(void);
void send_6x05_wave_clear_switch(s32 switch_id);
void send_6x05_wave_set_switch(s16 switch_id);
void send_6x67_wave_trigger_event(s32 event_id);
s32 set_floor_event_flags(s32 floor, s32 id, s32 flags);
extern "C" {
int spawn_objects_at_pos__6TLobbyFPv(void *p);
}
void swap_object_row_endian(void *row_ptr);

struct FloorSceneEntry {
    const char **names;
    s32 count;
};

struct Send6x05WaveSetSwitchPacket { u8 hdr[2]; u16 a; s16 b; s16 pad; s16 c; s8 d; s8 e; };

struct Send6x05WaveClearSwitchPacket {
    u8 cmd;
    u8 size;
    u16 a;
    u16 b;
    u16 pad;
    u16 c;
    u8 d;
    u8 e;
};

#endif
