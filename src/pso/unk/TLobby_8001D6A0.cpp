#include "pso/system/CharacterSaveRecordLookup.h"
#include "pso/system/ResourceFile.h"
#include "types.h"
#include "pso/network/TProtocol.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/ui/keyboard/SystemBootInit.h"
#include "pso/unk/TLobby_8001D6A0.h"
#include "pso/enemy/BattleParameters.h"
#include "pso/ui/window/TWindowSubStatusDisp_80228CC0.h"
#include "pso/ui/window/TWindowSubStatusDisp_80228F5C.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801FBF54.h"
#include "pso/system/date.h"
#include "pso/system/byteswap.h"
#include "pso/system/memory.h"
#include "pso/network/TLobby.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowSubStatusDisp_800FBD74.h"
#include "pso/unk/TLobby_801E2F94.h"
#include "pso/network/TPlyJoinLobbyEntry.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/unk/TLobby_803DE778.h"
#include "pso/ui/TLevelSelect.h"

#pragma readonly_strings on


BattleParameterBank *battle_parameter_buffer;
player_stats *battle_param_stats;
AttackParams *battle_param_attacks;
ActorParamBlock *battle_param_resistances;
BattleMovementParams *battle_param_movement;
s32 battle_parameter_difficulty;
s32 battle_param_lab_variant;
s32 override_enemy_bp_index;

struct TextBuilderBuffer { s32 value; u8 remaining[0xFC]; };
extern TextBuilderBuffer text_builder_buffer;



s32 *get_shared_text_buffer(void) {
    return &text_builder_buffer.value;
}

void load_battle_param_entry(void) {
  s32 idx;
  const char *name;
  BattleParameterFile *file;
  BattleParameterBank *dst;
  BattleParameterBank *bank;
  name = "BattleParamEntry.dat";
  if (TObjEneDD::is_main_phase_15() != 0)
  {
    name = "BattleParamEntry_on.dat";
  }
  if (TRaderMapCore::is_not_split_screen() == 1)
  {
    name = "BattleParamEntry_on.dat";
  }
  if (battle_param_lab_variant == 1)
  {
    name = "BattleParamEntry_lab.dat";
    if (TObjEneDD::is_main_phase_15() != 0)
    {
      name = "BattleParamEntry_lab_on.dat";
    }
    if (TRaderMapCore::is_not_split_screen() == 1)
    {
      name = "BattleParamEntry_lab_on.dat";
    }
  }
  file = (BattleParameterFile *) mem_alloc(sizeof(BattleParameterFile));
  if (file != 0)
  {
    read_disc_file(name, file);
    idx = battle_parameter_difficulty;
    bank = (dst = battle_parameter_buffer);
    move_data(((dst->stats)), (const void *)(file->stats[idx]), sizeof(dst->stats));
    {
      player_stats *p = ((0, dst))->stats;
      s32 i;
      for (i = 0; i < 0x60; i++)
      {
        bswap__12player_statsFv(p);
        p++;
      }

    }
    move_data(((bank->attacks)), (const void *)((void *) ((((saddr) file) + offsetof(BattleParameterFile, attacks)) + (idx * (saddr)sizeof(dst->attacks)))), sizeof(dst->attacks));
    {
      AttackParams *p = bank->attacks;
      s32 i;
      for (i = 0; i < 0x60; i++)
      {
        p->byteswap_packet();
        p++;
      }

    }
    move_data(((bank->resistances)), (const void *)((void *) ((((saddr) file) + offsetof(BattleParameterFile, resistances)) + (idx * (saddr)sizeof(dst->resistances)))), sizeof(dst->resistances));
    {
      s32 i;
      ActorParamBlock *p = bank->resistances;
      for (i = 0; i < 0x60; i++)
      {
        p->swap_endian();
        p++;
      }

    }
    move_data(((bank->movement)), (const void *)((void *) ((((saddr) file) + offsetof(BattleParameterFile, movement)) + ((saddr)sizeof(dst->movement) * idx))), sizeof(dst->movement));
    {
      s32 i;
      BattleMovementParams *p = bank->movement;
      for (i = 0; i < 0x60; i++)
      {
        s32 j;
        for (j = 0; j < 6; j++)
        {
          bswap_32(&p->words.floats[j]);
          bswap_32(&p->words.integers[j]);
        }

        p++;
      }

    }
    mem_free(file);
 ;
  }
}

void set_enemy_movement_data(BattleMovementParams *params) { set_battle_param_movement(override_enemy_bp_index, params); }

void set_enemy_resist_data(ActorParamBlock *params) { set_battle_param_resistance(override_enemy_bp_index, params); }

void set_enemy_attack_data(AttackParams *params) { set_battle_param_attack(override_enemy_bp_index, params); }

void set_enemy_physical_data(player_stats *stats) { set_battle_param_stats(override_enemy_bp_index, stats); }

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct CopyDataBlk { s32 w[6]; };

struct CopyDataObject { CopyDataBlk a; CopyDataBlk b; };

void set_override_enemy_bp_index(s32 index) {
    override_enemy_bp_index = index;
}

void set_battle_param_movement(s32 index, BattleMovementParams *src) {
    s32 i;

    if (is_valid_battle_param_index(index) != 0) {
        i = 0;
        do {
            TLobby::copy_pair((BattleMovementParams *)((saddr (*)(s32, s32))get_battle_param_movement)(i, index), src);
            i += 1;
        } while (i < 4);
    }
}
void *TLobby::copy_pair(void *dst, void *src) {
    CopyDataObject *d = (CopyDataObject *)dst;
    CopyDataObject *s = (CopyDataObject *)src;
    d->a = s->a;
    d->b = s->b;
    return dst;
}

void set_battle_param_resistance(s32 index, ActorParamBlock *src) {
    s32 i;

    if (is_valid_battle_param_index(index) != 0) {
        i = 0;
        do {
            ((TLobby *)((saddr (*)(s32, s32))get_battle_param_resistance)(i, index))->copy_entry(src);
            i += 1;
        } while (i < 4);
    }
}

void TLobby::copy_entry(void *ent) {
    *(s16 *)&this->m_name = (s16) *(s16 *)((s8 *)ent + 0);
    *(s16 *)((s8 *)this + 2) = (s16) *(s16 *)((s8 *)ent + 2);
    this->m_flags = (s16) *(s16 *)((s8 *)ent + 4);
    this->m_id = (s16) *(s16 *)((s8 *)ent + 6);
    *(s16 *)&this->m_prev = (s16) *(s16 *)((s8 *)ent + 8);
    *(s16 *)((s8 *)this + 0xA) = (s16) *(s16 *)((s8 *)ent + 0xA);
    *(s32 *)&this->m_next = (s32) *(s32 *)((s8 *)ent + 0xC);
    *(s32 *)&this->m_up = (s32) *(s32 *)((s8 *)ent + 0x10);
    *(s32 *)&this->m_down = (s32) *(s32 *)((s8 *)ent + 0x14);
    *(s32 *)((s8 *)this + 0x18) = (s32) *(s32 *)((s8 *)ent + 0x18);
    *(s32 *)((s8 *)this + 0x1C) = (s32) *(s32 *)((s8 *)ent + 0x1C);
}

void set_battle_param_attack(s32 index, AttackParams *src) {
    s32 i;

    if (is_valid_battle_param_index(index) != 0) {
        i = 0;
        do {
            ((TLobby *)((saddr (*)(s32, s32))get_battle_param_attack)(i, index))->copy_from(src);
            i += 1;
        } while (i < 4);
    }
}

void TLobby::copy_from(void *src) {
    *(s16 *)&this->m_name = (s16) *(s16 *)((s8 *)src + 0);
    *(s16 *)((s8 *)this + 2) = (s16) *(s16 *)((s8 *)src + 2);
    this->m_flags = (s16) *(s16 *)((s8 *)src + 4);
    this->m_id = (s16) *(s16 *)((s8 *)src + 6);
    *(f32 *)&this->m_prev = (f32) *(f32 *)((s8 *)src + 8);
    *(s32 *)&this->m_next = (s32) *(s32 *)((s8 *)src + 0xC);
    *(f32 *)&this->m_up = (f32) *(f32 *)((s8 *)src + 0x10);
    *(s16 *)&this->m_down = (s16) *(s16 *)((s8 *)src + 0x14);
    *(s16 *)((s8 *)this + 0x16) = (s16) *(s16 *)((s8 *)src + 0x16);
    *(s16 *)((s8 *)this + 0x18) = (s16) *(s16 *)((s8 *)src + 0x18);
    *(s16 *)((s8 *)this + 0x1A) = (s16) *(s16 *)((s8 *)src + 0x1A);
    *(s32 *)((s8 *)this + 0x1C) = (s32) *(s32 *)((s8 *)src + 0x1C);
    *(s32 *)((s8 *)this + 0x20) = (s32) *(s32 *)((s8 *)src + 0x20);
    *(s32 *)((s8 *)this + 0x24) = (s32) *(s32 *)((s8 *)src + 0x24);
    *(s32 *)((s8 *)this + 0x28) = (s32) *(s32 *)((s8 *)src + 0x28);
    *(s32 *)((s8 *)this + 0x2C) = (s32) *(s32 *)((s8 *)src + 0x2C);
}

void set_battle_param_stats(s32 index, player_stats *src) {
    s32 i;

    if (is_valid_battle_param_index(index) != 0) {
        i = 0;
        do {
            TLobby::copy_data((void *)((saddr (*)(s32, s32))get_battle_param_stats)(i, index), src);
            i += 1;
        } while (i < 4);
    }
}

void TLobby::copy_data(void *stats, void *src) {
    *(s16 *)((s8 *)stats + 0) = (s16) *(s16 *)((s8 *)src + 0);
    *(s16 *)((s8 *)stats + 2) = (s16) *(s16 *)((s8 *)src + 2);
    *(s16 *)((s8 *)stats + 4) = (s16) *(s16 *)((s8 *)src + 4);
    *(s16 *)((s8 *)stats + 6) = (s16) *(s16 *)((s8 *)src + 6);
    *(s16 *)((s8 *)stats + 8) = (s16) *(s16 *)((s8 *)src + 8);
    *(s16 *)((s8 *)stats + 0xA) = (s16) *(s16 *)((s8 *)src + 0xA);
    *(s16 *)((s8 *)stats + 0xC) = (s16) *(s16 *)((s8 *)src + 0xC);
    *(s16 *)((s8 *)stats + 0xE) = (s16) *(s16 *)((s8 *)src + 0xE);
    *(f32 *)((s8 *)stats + 0x10) = (f32) *(f32 *)((s8 *)src + 0x10);
    *(f32 *)((s8 *)stats + 0x14) = (f32) *(f32 *)((s8 *)src + 0x14);
    *(s32 *)((s8 *)stats + 0x18) = (s32) *(s32 *)((s8 *)src + 0x18);
    *(s32 *)((s8 *)stats + 0x1C) = (s32) *(s32 *)((s8 *)src + 0x1C);
    *(s32 *)((s8 *)stats + 0x20) = (s32) *(s32 *)((s8 *)src + 0x20);
}

s32 is_valid_battle_param_index(s32 index) {
    u8 valid;

    valid = 0;
    if ((index >= 0) && (index < 0x60)) {
        valid = 1;
    }
    return valid;
}

BattleMovementParams *TLobby::dispatch_shared_handler_a(s32 index) { return get_battle_param_movement(battle_parameter_difficulty, index); }

BattleMovementParams *get_battle_param_movement(int difficulty, int index) { return &battle_param_movement[index]; }

ActorParamBlock *TLobby::register_object(s32 index) { return get_battle_param_resistance(battle_parameter_difficulty, index); }

ActorParamBlock *get_battle_param_resistance(int difficulty, int index) { return &battle_param_resistances[index]; }

AttackParams *TLobby::dispatch_shared_handler_b(s32 index) { return get_battle_param_attack(battle_parameter_difficulty, index); }

AttackParams *get_battle_param_attack(int difficulty, int index) { return &battle_param_attacks[index]; }

player_stats *TLobby::register_boss(s32 index) { return get_battle_param_stats(battle_parameter_difficulty, index); }

player_stats *get_battle_param_stats(int difficulty, int index) { return &battle_param_stats[index]; }
void set_battle_param_episode(s32 episode) {
    battle_param_lab_variant = episode;
}


void TLobby::clamp_difficulty(s32 difficulty) {
    s32 clamped;

    clamped = difficulty;
    if (clamped < 0) {
        clamped = 0;
    } else if ((s32) enable_v2_features != 0) {
        if (clamped >= 4) {
            clamped = 3;
        }
    } else if (clamped >= 3) {
        clamped = 2;
    }
    battle_parameter_difficulty = clamped;
}

void TLobby::update_difficulty() {
    s32 old_difficulty;
    s32 old_variant;

    old_difficulty = battle_parameter_difficulty;
    old_variant = battle_param_lab_variant;
    TLobby::clamp_difficulty(game_difficulty_selection);
    set_battle_param_episode(TLobby::get_instance());
    if ((battle_parameter_difficulty != old_difficulty) || (battle_param_lab_variant != old_variant)) {
        load_battle_param_entry();
    }
}

void TLobby::free_boss4_rock() {
    if (battle_parameter_buffer != NULL) {
        mem_free(battle_parameter_buffer);
        battle_parameter_buffer = NULL;
    }
    battle_param_stats = NULL;
    battle_param_attacks = NULL;
    battle_param_resistances = NULL;
    battle_param_movement = NULL;
}

void alloc_battle_param_tables(void) {
    u8 *buf = (u8 *)mem_alloc(sizeof(BattleParameterBank));
    s32 i;
    for (i = 0; i < sizeof(BattleParameterBank); i++) {
        buf[i] = 0;
    }
    BattleParameterBank *bank = (BattleParameterBank *)buf;
    battle_parameter_buffer = bank;
    battle_param_stats = bank->stats;
    battle_param_attacks = bank->attacks;
    battle_param_resistances = bank->resistances;
    battle_param_movement = bank->movement;
    TLobby::clamp_difficulty(game_difficulty_selection);
    set_battle_param_episode(TLobby::get_instance());
    load_battle_param_entry();
    override_enemy_bp_index = 0;
}
void ActorParamBlock::swap_endian() {
    bswap_16(reinterpret_cast<u16 *>(&values[0]));
    bswap_16(reinterpret_cast<u16 *>(&values[1]));
    bswap_16(reinterpret_cast<u16 *>(&values[2]));
    bswap_16(reinterpret_cast<u16 *>(&values[3]));
    bswap_16(reinterpret_cast<u16 *>(&values[4]));
    bswap_16(reinterpret_cast<u16 *>(&values[5]));
    bswap_32(reinterpret_cast<u32 *>(pad_c));
    bswap_32(reinterpret_cast<u32 *>(pad_c + 4));
    bswap_32(reinterpret_cast<u32 *>(pad_c + 8));
    bswap_32(reinterpret_cast<u32 *>(pad_c + 12));
    bswap_32(reinterpret_cast<u32 *>(&value_1c));
}

void AttackParams::byteswap_packet() {
    bswap_16(reinterpret_cast<u16 *>(&atp_min));
    bswap_16(reinterpret_cast<u16 *>(&atp_max));
    bswap_16(reinterpret_cast<u16 *>(&ata));
    bswap_16(reinterpret_cast<u16 *>(pad_6));
    bswap_32(reinterpret_cast<u32 *>(&attack_range));
    bswap_32(reinterpret_cast<u32 *>(&attack_angle));
    bswap_32(reinterpret_cast<u32 *>(&damage_radius));
    bswap_16(reinterpret_cast<u16 *>(pad_14));
    bswap_16(reinterpret_cast<u16 *>(pad_14 + 2));
    bswap_16(reinterpret_cast<u16 *>(pad_14 + 4));
    bswap_16(reinterpret_cast<u16 *>(pad_14 + 6));
    bswap_32(reinterpret_cast<u32 *>(pad_14 + 8));
    bswap_32(reinterpret_cast<u32 *>(pad_14 + 12));
    bswap_32(reinterpret_cast<u32 *>(pad_14 + 16));
    bswap_32(reinterpret_cast<u32 *>(pad_14 + 20));
    bswap_32(reinterpret_cast<u32 *>(pad_14 + 24));
}
extern "C" {

void bswap__12player_statsFv(void *stats) {
    bswap_16((u16 *)stats);
    bswap_16((u16 *)((void *)((char *)stats + 2)));
    bswap_16((u16 *)((void *)((char *)stats + 4)));
    bswap_16((u16 *)((void *)((char *)stats + 6)));
    bswap_16((u16 *)((void *)((char *)stats + 8)));
    bswap_16((u16 *)((void *)((char *)stats + 10)));
    bswap_16((u16 *)((void *)((char *)stats + 12)));
    bswap_16((u16 *)((void *)((char *)stats + 14)));
    bswap_32((u32 *)((void *)((char *)stats + 16)));
    bswap_32((u32 *)((void *)((char *)stats + 20)));
    bswap_32((u32 *)((void *)((char *)stats + 24)));
    bswap_32((u32 *)((void *)((char *)stats + 28)));
    bswap_32((u32 *)((void *)((char *)stats + 32)));
}

extern s32 selected_episode;

s32 TLobby::get_instance() {
    return selected_episode;
}

void set_clock_offset_from_server_time(TLobby *packet) {
    u8 *save;
    DateStamp date;
    s32 minutes;
    s32 local_time;
    s32 offset;

    save = (u8 *)TAdSinglePlyChrSelectGC::get_global_state();
    if (save != 0) {
        getDateStamp(&date);
        minutes = date.hour * 60;
        local_time = (date.minute + minutes) * 60;
        local_time = date.second + local_time;
        local_time = (s32)(30.0f * (f32)local_time);
        offset = packet->calc_time_from_hms() - local_time;
        offset += 108000.0f;
        while (offset < 0) {
            offset += 2592000.0f;
        }
        *(s32 *)(save + 8) = offset;
    }
}
}

s32 TLobby::calc_time_from_hms() {
    saddr text = (saddr)this;
  saddr *text_ref;
  int seconds;
  s32 hours;
  s32 minutes;
  hours = parse_two_digit_number((void *)(text + 0xC));
  text_ref = &text;
  minutes = (hours * 0x3C) + parse_two_digit_number((void *)(text + 0xF));
  seconds = (minutes * 0x3C) + parse_two_digit_number((void *)((void *) ((*text_ref) + 0x12)));
  return (s32) (30.0f * ((f32) seconds));
}
s32 parse_two_digit_number(void *text) {
    s8 *s = (s8 *)text;
    s32 v = (s[0] - '0') * 10;
    v += s[1] - '0';
    return v;
}
extern "C" {

s32 __cvt_fp2unsigned(f32);
}

s32 TLobby::calc_alpha_shifted(f32 alpha) {
    return __cvt_fp2unsigned(255.0f * alpha) << 0x18;
}


void TLobby::close_result_windows() {
    text_builder_reset();
    text_builder_append((u8 *)lobby_ship_name);
    text_builder_append((u8 *)":");
    append_padded_number(block_number, 2);
    text_builder_append((u8 *)"-");
    append_padded_number(lobby_number + 1, 2);
}


f32 TLobby::calc_result_offset() {
    f32 offset;

    offset = 0.0f;
    if (get_main_phase() == 0xF) {
        TLobby::close_result_windows();
        offset -= (f32)(u32)get_name_text_width(get_shared_text_buffer());
    }
    return offset;
}

static f32 clock_bar_pulse;


f32 TLobby::calc_phase_offset() {
    f32 offset;

    offset = -163.0f;
    if (get_main_phase() == 0xF) {
        offset -= 57.0f;
    }
    return offset;
}

s32 default_clock_offset_frames(void) {
    return 0x1A5E00;
}

s32 TLobby::get_internet_beat() {
    return (TLobby::get_clock_frames() / 2592) % 1000;
}

typedef struct GetInternetBeatDateStamp GetInternetBeatDateStamp;
struct GetInternetBeatDateStamp
{
  u8 pad0[4];
  u8 h;
  u8 m;
  u8 s;
  u8 pad7;
  u8 pad8[4];
};
s32 TLobby::get_clock_frames() {
  u8 *hour;
  u8 *g;
  s32 base;
  GetInternetBeatDateStamp d;
  hour = &d.h;
  g = TAdSinglePlyChrSelectGC::get_global_state();
  if (g == 0)
  {
    base = default_clock_offset_frames();
  }
  else
  {
    base = *((s32 *)(g + 8));
  }
  getDateStamp((DateStamp *)&d);
  s32 secs = (*hour) * 60;
  s32 mins = d.m;
  if (g && g)
  {
  }
  secs = (mins + secs) * 60;
  secs = d.s + secs;
  s32 t = (s32) (30.0f * ((f32) (secs)));
  t += base;
  return t;
}
void draw_lobby_location_text(f32 x, f32 y, f32 size, f32 alpha) {
    f32 scale;
    f32 clamped;
    saddr color;
    clamped = alpha;
    if (!(clamped <= 0.0f)) {
        if (clamped > 1.0f) {
            clamped = 1.0f;
        }
        scale = -1.0f / size;
        color = TLobby::calc_alpha_shifted(clamped);
        if (get_main_phase() == 0xF) {
            TLobby::close_result_windows();
            draw_small_font_text(color | 0xFF0000 | 0xFFFF, (const char *)get_shared_text_buffer(), x, (f32)(-1.0f + y), scale);
        }
    }
}

#pragma fp_contract on
void draw_play_time_clock(f32 x, f32 y, f32 size, f32 alpha) {
    s32 frames;
    saddr text_color;
    saddr color;
    s32 beat;
    f32 scale;
    u32 elapsed;
    DateStamp date;
    ColorLineList lines;
    u32 colors[3];
    ColorLineVertex verts[3];
    s32 pulse;
    f32 progress;
    f32 bar_end;
    f32 bar_y;

    if (!(alpha <= 0.0f)) {
        if (alpha > 1.0f) {
            alpha = 1.0f;
        }
        frames = TLobby::get_clock_frames();
        beat = frames / 2592;
        beat %= 1000;
        scale = -1.0f / size;
        color = TLobby::calc_alpha_shifted(alpha);
        if (get_main_phase() == 0xF) {
            getDateStamp(&date);
            DateToSeconds(&date, (int *)&elapsed);
            elapsed -= TLobby::date_seconds;
            text_builder_reset();
            if (elapsed / 3600 > 99) {
                text_builder_append((u8 *)"99:59");
            } else {
                append_padded_number(elapsed / 3600, 2);
                text_builder_append((u8 *)":");
                append_padded_number((elapsed / 60) % 60, 2);
                text_builder_append((u8 *)"/");
            }
            draw_small_font_text(color | 0xFF0000 | 0xFFFF, (const char *)get_shared_text_buffer(), x,
                                 -1.0f + y, scale);
            x += 57.0f;
        }
        text_color = color | 0xFF0000 | 0xFFFF;
        TWindowSubStatusDisp__sub_800FBD74(text_color, x, y, scale);
        TWindowSubStatusDisp::draw_number_digits((void *)text_color, beat, 3, 163.0f + x, -1.0f + y, scale);
        clock_bar_pulse += 0.01f;
        if (clock_bar_pulse >= 1.0f) {
            clock_bar_pulse -= 1.0f;
        }
        progress = 163.0f * (frames % 2592);
        progress /= 2592.0f;
        lines.verts = verts;
        lines.colors = colors;
        lines.tex = 0;
        lines.count = 3;
        lines.colors[0] = color | 0xFF00;
        lines.colors[1] = color | 0xFF00;
        lines.colors[2] = color | 0xFF00;
        if (clock_bar_pulse > 0.5f) {
            pulse = 2.0f * (255.0f * (1.0f - clock_bar_pulse));
        } else {
            pulse = 255.0f * (2.0f * clock_bar_pulse);
        }
        lines.colors[1] |= (pulse & 0xFF) | ((pulse << 16) & 0xFF0000);
        bar_end = x + progress;
        bar_y = 18.0f + y;
        verts[0].x = bar_end;
        verts[2].x = x;
        verts[1].x = clock_bar_pulse * (verts[0].x - verts[2].x) + verts[2].x;
        verts[0].y = bar_y;
        verts[1].y = bar_y;
        verts[2].y = bar_y;
        draw_color_lines(&lines, 3, 20, size);
    }
}
#pragma fp_contract reset
extern "C" {

void TLobby__sub_8001ED70(void) {  }
void reset_clock_bar_pulse(void) {
    clock_bar_pulse = 0.0f;
}
}
