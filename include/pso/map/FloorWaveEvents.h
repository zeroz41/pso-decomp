#ifndef PSO_MAP_FLOORWAVEEVENTS_H
#define PSO_MAP_FLOORWAVEEVENTS_H

#include "types.h"

struct EnemyPlacement;
struct ObjectSetData;

void copy_game_variations(u32 *variations, s32 size);
void init_city_area_stub(void);
void randomize_offline_maps(void);
void reset_online_story_select(void);
void free_forest_rel_work_buffer(void);
void command_exit_stub(void);
void set_wave_event_stream(void *a0);
s32 activate_first_floor_event(s32 idx, s32 id);
void activate_triggered_floor_events(void);
void bswap_enemy_set_row(void *row_ptr);
void bswap_enemy_set_row_fields(EnemyPlacement *placement);
void bswap_floor_event_set(s32 idx);
void bswap_object_row_fields(ObjectSetData *placement);
void clear_floor_event_flags(void);
struct SetDestroyEventRecord;
void create_empty_floor_event(SetDestroyEventRecord *event);
void spawn_destroy_event(SetDestroyEventRecord *event);
void dispatch_wave_event_action(u8 opcode);
saddr get_floor_scene_table(s32 area);
// Wave event opcode 9: links the objects of a room's wave.
s32 wave_event_link_objects(s16 room, s16 wave);
s32 load_area_event_set(s32 floor, s32 area, s32 terrain, s32 entities);
s32 read_be_u32(void);
u16 read_stream_u16(void);
unsigned char read_stream_u8(void);
void request_wave_event_stop(void);
s32 run_floor_initialize_callbacks(s32 floor);
s32 run_wave_event_actions(void);
void send_6x05_wave_clear_switch(s32 switch_id);
void send_6x05_wave_set_switch(s16 switch_id);
void send_6x67_wave_trigger_event(s32 event_id);
s32 set_floor_event_flags(s32 floor, s32 id, s32 flags);
// Wave event opcode 8: spawns the objects of a room's wave.
s32 wave_event_spawn_objects(s16 room, s16 wave);
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

// Wave event script opcodes, indexed by the opcode byte: decode reads the opcode's operands from the script
// stream and calls action with them, so each action has the signature its decoder calls it with.
typedef void (*WaveEventActionFunc)();
struct WaveEventAction {
    void (*decode)(u8 opcode);
    WaveEventActionFunc action;
};

void update_drop_item();
void load_item_data();
void dispatch_opcode_two_u16(u8 opcode);
void dispatch_stream_command(u8 opcode);
void invoke_command(u8 opcode);
void update_current_floor();
void relink_objects(s16 a, s16 b);
void run_floor_cleanup_callbacks(int floor);
s32 get_drop_item_mode();

#endif
