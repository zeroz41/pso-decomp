#include "types.h"
#include "pso/misc/TLobby.h"
#include "pso/TAdStorySelectGC.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/map/FloorArea.h"

struct RecoveredGlobal_80207798_lbl_80513920 {
    s32 value;
    u8 remaining[0xD4];
};

struct RecoveredGlobal_802077CC_lbl_80513920 {
    s32 value;
    u8 remaining[0xD4];
};

struct RecoveredGlobal_802078A4_lbl_8044B658
{
  s32 value;
  u8 remaining[0x11C];
};

struct RecoveredGlobal_802078A4_lbl_8044B778
{
  s32 value;
  u8 remaining[0x11C];
};

struct RecoveredGlobal_802078A4_lbl_80513920
{
  s32 value;
  u8 remaining[0xD4];
};

struct Map_80207C60 { s32 map; s32 layout; s32 entities; };

struct Ids_80207C60 { s32 w[18]; };

struct Tbl_8020765C { s32 w[2][18]; };

struct Ent_8020780C { s32 pad; s32 a; s32 b; };

typedef struct FloorEntry_80207770 { s32 a; s32 b; s32 c; } FloorEntry_80207770;

extern RecoveredGlobal_80207798_lbl_80513920 floor_map_registry;
s32 set_floor_map_selection(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern "C" {
s32 get_floor_map_selection(s32 arg0, u8 *arg1);
s32 get_main_phase(void);
s32 rand(void);
extern RecoveredGlobal_802078A4_lbl_8044B658 adventure_map_variation_count_table;
extern RecoveredGlobal_802078A4_lbl_8044B778 online_floor_map_variation_dimension_table;
extern int selected_episode;
extern const f32 lbl_805DC610;
void randomize_adventure_maps(void);
s32 memset(void *, int, int);
void TLobby__sub_80207BB0(void);
s32 get_current_floor();
s32 get_game_play_mode();
extern Tbl_8020765C boss_warp_destination_table;
extern Tbl_8020765C boss_warp_destination_table_b;
s32 get_boss_warp_destination(void);
s32 get_floor_map_terrain(s32 arg0);
struct Buf12_80207718_80207644 { s32 a, b, c; };

    extern int story_select_current;
void TLobby::backup_story_select() { selected_episode = story_select_current; }

void TLobby::sync_story_select() { story_select_current = selected_episode; }

s32 get_boss_warp_destination(void) {
    Tbl_8020765C a = boss_warp_destination_table;
    Tbl_8020765C b = boss_warp_destination_table_b;
    if (get_game_play_mode() == 1) {
        return b.w[0][get_current_floor_area()];
    }
    s32 i = TLobby::get_instance();
    s32 p = get_current_floor();
    return a.w[i][p];
}

}

s32 get_floor_area(s32 floor) {
    struct Buf12_80207718_80207644 buf;

    if (get_floor_map_selection(floor, (u8 *)&buf) == 1) {
        return buf.a;
    }
    return -1;
}
extern struct Ids_80207C60 floor_map_registry_id_table;
void init_floor_map_registry(void);
extern struct Ids_80207C60 boss_warp_area_id_table;
extern s32 story_select_pending_state;

void set_floor_map_variant(s32 arg0, s32 arg1) {
    if (arg0 <= 0x11) {
        s32 *p = (s32 *)&floor_map_registry;
        p[arg0 * 3 + 1] = arg1;
    }
}

#pragma push
#pragma opt_common_subs off
typedef char RecoveredGlobal_80207798_lbl_80513920_size[sizeof(RecoveredGlobal_80207798_lbl_80513920) == 0xD8 ? 1 : -1];

s32 get_floor_map_terrain(s32 arg0) {
    if (arg0 > 0x11) {
        return 0;
    }
    s32 *p = (s32 *)&floor_map_registry;
    return p[arg0 * 3 + 1];
}

s32 set_floor_map_selection(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_r0;
    u8 *temp_r4;
    if (arg0 > 0x11) {
        return 0;
    }
    temp_r0 = arg0 * 0xC;
    *(s32 *)((s8 *)((u8 *)&floor_map_registry.value + temp_r0) + 0) = arg1;
    temp_r4 = (u8 *)&floor_map_registry.value + temp_r0;
    *(s32 *)((s8 *)temp_r4 + 4) = arg2;
    *(s32 *)((s8 *)temp_r4 + 8) = arg3;
    return 1;
}
#pragma pop

#pragma push
#pragma opt_common_subs off
typedef char RecoveredGlobal_802077CC_lbl_80513920_size[sizeof(RecoveredGlobal_802077CC_lbl_80513920) == 0xD8 ? 1 : -1];

s32 get_floor_map_selection(s32 arg0, u8 *arg1) {
    s32 temp_r6;
    u8 *temp_r5;
    if (arg0 > 0x11) {
        return 0;
    }
    temp_r6 = arg0 * 0xC;
    temp_r5 = (u8 *)(&(*(RecoveredGlobal_802077CC_lbl_80513920 *)&floor_map_registry).value) + temp_r6;
    *(s32 *)((s8 *)arg1 + 0) = (s32) *(s32 *)((s8 *)((u8 *)(&(*(RecoveredGlobal_802077CC_lbl_80513920 *)&floor_map_registry).value) + temp_r6) + 0);
    *(s32 *)((s8 *)arg1 + 4) = (s32) *(s32 *)((s8 *)temp_r5 + 4);
    *(s32 *)((s8 *)arg1 + 8) = (s32) *(s32 *)((s8 *)temp_r5 + 8);
    return 1;
}
#pragma pop

typedef struct RecoveredGlobal_802078A4_lbl_8044B658 RecoveredGlobal_802078A4_lbl_8044B658;
typedef struct RecoveredGlobal_802078A4_lbl_8044B778 RecoveredGlobal_802078A4_lbl_8044B778;
typedef struct RecoveredGlobal_802078A4_lbl_80513920 RecoveredGlobal_802078A4_lbl_80513920;
typedef char RecoveredGlobal_802078A4_lbl_8044B658_size[((sizeof(RecoveredGlobal_802078A4_lbl_8044B658)) == 0x120) ? (1) : (-1)];
typedef char RecoveredGlobal_802078A4_lbl_8044B778_size[((sizeof(RecoveredGlobal_802078A4_lbl_8044B778)) == 0x120) ? (1) : (-1)];
typedef char RecoveredGlobal_802078A4_lbl_80513920_size[((sizeof(RecoveredGlobal_802078A4_lbl_80513920)) == 0xD8) ? (1) : (-1)];

void TLobby::copy_table_entries(u32 size) {
    s32 *src = (s32 *)this;
    s32 n = size >> 3;
    s32 i;
    if (n <= 0x12) {
        switch ((*(s32 *)&selected_episode)) {
        case 1:
            for (i = 0; i < n; i++, src += 2) {
                ((Ent_8020780C *)&floor_map_registry)[i].a = src[0];
                ((Ent_8020780C *)&floor_map_registry)[i].b = src[1];
            }
            break;
        case 0:
        default:
            for (i = 0; i < n; i++, src += 2) {
                ((Ent_8020780C *)&floor_map_registry)[i].a = src[0];
                ((Ent_8020780C *)&floor_map_registry)[i].b = src[1];
            }
            break;
        }
    }
}

void randomize_adventure_maps(void) {
  s32 *var_r31;
  s32 main_phase;
  s32 var_r29;
  var_r31 = (s32 *) (&(*(RecoveredGlobal_802078A4_lbl_80513920 *)&floor_map_registry).value);
  TAdStorySelectGC::set_state((s32)((void*)((*(s32 *)&selected_episode))));
  main_phase = get_main_phase();
  if (TRaderMapCore::is_not_split_screen() == 1)
  {
    main_phase = 0xF;
  }
  var_r29 = 0;
  do
  {
    if (((s32) (*((s32 *) (((s8 *) var_r31) + 0)))) >= 0)
    {
      switch (main_phase)
      {
        case 14:
          *((s32 *) (((s8 *) var_r31) + 4)) = (s32) (((f32) (*((s32 *) (((s8 *)&adventure_map_variation_count_table.value) + ((*((s32 *) (((s8 *) var_r31) + 0))) * 8))))) * (lbl_805DC610 * ((f32) rand())));
          *((s32 *) (((s8 *) var_r31) + 8)) = (s32) (((f32) (*((s32 *) (((s8 *) (((u8 *)&adventure_map_variation_count_table.value) + ((*((s32 *) (((s8 *) var_r31) + 0))) * 8))) + 4)))) * (lbl_805DC610 * ((f32) rand())));
          break;
        case 15:
          *((s32 *) (((s8 *) var_r31) + 4)) = (s32) (((f32) (*((s32 *) (((s8 *)&online_floor_map_variation_dimension_table.value) + ((*((s32 *) (((s8 *) var_r31) + 0))) * 8))))) * (lbl_805DC610 * ((f32) rand())));
          *((s32 *) (((s8 *) var_r31) + 8)) = (s32) (((f32) (*((s32 *) (((s8 *) (((u8 *)&online_floor_map_variation_dimension_table.value) + ((*((s32 *) (((s8 *) var_r31) + 0))) * 8))) + 4)))) * (lbl_805DC610 * ((f32) rand())));
          break;
        default:
          *((s32 *) (((s8 *) var_r31) + 4)) = (s32) (((f32) (*((s32 *) (((s8 *)&adventure_map_variation_count_table.value) + ((*((s32 *) (((s8 *) var_r31) + 0))) * 8))))) * (lbl_805DC610 * ((f32) rand())));
          *((s32 *) (((s8 *) var_r31) + 8)) = (s32) (((f32) (*((s32 *) (((s8 *) (((u8 *)&adventure_map_variation_count_table.value) + ((*((s32 *) (((s8 *) var_r31) + 0))) * 8))) + 4)))) * (lbl_805DC610 * ((f32) rand())));
          break;
      }
    }
    var_r29 += 1;
    var_r31 = (s32 *) (((u8 *) var_r31) + 0xC);
  }
  while (var_r29 < 0x12);
}

#pragma push
#pragma opt_common_subs off
void TLobby__sub_80207BB0(void) {
    struct Ids_80207C60 ids = boss_warp_area_id_table;
    s32 i;
    memset((void *) ((struct Map_80207C60 *)&floor_map_registry), 0, 0xD8);
    for (i = 0; i < 18; i++) {
        ((struct Map_80207C60 *)&floor_map_registry)[i].map = -1;
    }
    for (i = 0; i < 18; i++) {
        ((struct Map_80207C60 *)&floor_map_registry)[i].map = ids.w[i];
    }
}
#pragma pop

void init_floor_map_registry(void) {
    struct Ids_80207C60 ids = floor_map_registry_id_table;
    s32 i;
    memset((void *) ((struct Map_80207C60 *)&floor_map_registry), 0, 0xD8);
    for (i = 0; i < 18; i++) {
        ((struct Map_80207C60 *)&floor_map_registry)[i].map = -1;
    }
    for (i = 0; i < 18; i++) {
        ((struct Map_80207C60 *)&floor_map_registry)[i].map = ids.w[i];
    }
}

void TLobby::reset_story_select_state() {
    if ((s32) story_select_pending_state != -1) {
        TAdStorySelectGC::set_state((s32)((void*)story_select_pending_state));
        story_select_pending_state = -1;
    }
}
