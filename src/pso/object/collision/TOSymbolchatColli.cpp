#include "types.h"
#include "pso/object/collision/TOSymbolchatColli.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/system/memory.h"
#include "pso/system/ResourceFile.h"
#include "pso/render/render_util.h"
#include "pso/system/NinjaTypes.h"
#include <string.h>
#include "pso/object/base/TObjMotion.h"
#include "pso/object/base/TObjChara.h"
#include "pso/ui/chat/TWindowSubSymbolChat.h"
#include "pso/ui/chat/SymbolChatPreset.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/task/TObject.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/system/task/TMainTask.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/system/prs.h"
#include "pso/object/switch/TSwitch.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/object/base/ActorCollision.h"

void TOSymbolchatColli::open_balloon_chat(s32 state, u16 player) {
    if (state < 3) {
        u8 *chat = balloon_chats[state];
        if (chat != 0) {
            TWindowCtrl::open_balloon(get_entity_id(), chat, 10, player);
        }
    }
}

// switch_ids[i] and preset_ids[i] through one base; the array spellings give sthx per store
struct HL_8017873C
{
  u8 pad[0x378];
  u16 hi;
  u16 pad37a[2];
  u16 lo;
};


CollisionBody symbolchatcolli_collision_body_parts[1] = {
    { { 0.0f, 80.0f, 0.0f }, 1.0f, 1.0f, 0, 0x10002, { 0.0f, 0.0f, 0.0f }, 0.0f },
};
const char *symbolchatcolli_prs = "symbolchatcolli.prs";
const char *symbolchat_colli_name = "TOSymbolchatColli";
u8 *symbolchat_colli_param_table[4];
SymbolChatPreset *symbol_chat_colli_entries;

s32 TOSymbolchatColli::get_state() {
    if (is_current_floor_switch_set(switch_ids[2]) == 1) {
        return 3;
    }
    if (is_current_floor_switch_set(switch_ids[1]) == 1) {
        return 2;
    }
    return (u32) __cntlzw(1 - is_current_floor_switch_set(switch_ids[0])) >> 5;
}


void TOSymbolchatColli::init_collision_params() {
  s32 i;
  radius_sq = scale.x * scale.x;
  memset(&collision_stats, 0, sizeof(collision_stats));
  collision_stats.proportions = position.y / 0.92f;
  set_motion_params(&collision_stats);
  for (i = 0; i < 3; i++)
  {
    u32 v = set_params[i];
    u32 hi;
    u32 lo;
    hi = v >> 16;
    lo = (u16) v;
    if (symbolchat_colli_param_table[i] == 0)
    {
      hi = v >> 16;
      if (lo < 0x18)
      {
        balloon_chats[i] = (u8 *)&symbol_chat_colli_entries[lo].payload;
      }
      else
      {
        balloon_chats[i] = 0;
      }
    }
    else
    {
      balloon_chats[i] = symbolchat_colli_param_table[i];
    }
    {
      HL_8017873C *h = (HL_8017873C *) (((u8 *) this) + (i * 2));
      if (hi < 0x100)
      {
        h->hi = hi;
      }
      else
      {
        h->hi = 0xFFFF;
      }
      h->lo = lo;
    }
  }
}

void TOSymbolchatColli::render() {
    if (check_demo_mode() == 1) {
        NJS_ARGB color;
        color.a = 0.3f;
        color.r = 0.0f;
        color.g = 0.3f;
        color.b = 0.3f;
        debug_draw_sphere(&position, &color, newton_sqrtf(radius_sq));
    }
}

void TOSymbolchatColli::run_task() {
    u16 i;
    TObjCollidable *player;
    for (i = 0; i != 4; i++) {
        player = find_entity_by_id(i);
        if (player != NULL && ((TObjChara *)player)->is_locally_controlled() != 0) {
            if (horizontal_distance_squared(&player->position, &position) < radius_sq) {
                if (player_inside[i] == 0) {
                    player_inside[i] = 1;
                    s32 state = get_state();
                    open_balloon_chat(state, i);
                }
            } else {
                if (player_inside[i] != 0) {
                    player_inside[i] = 0;
                }
            }
        }
    }
}

void *TOSymbolchatColli::create(void *set_data) {
    return new TOSymbolchatColli(tl_05, set_data);
}

void TOSymbolchatColli::free_rock() { mem_free(symbol_chat_colli_entries); symbol_chat_colli_entries = NULL; }

void TOSymbolchatColli::load_symbol_chat_data() {
    void *h;
    s32 i;
    symbol_chat_colli_entries = (SymbolChatPreset *)mem_alloc(0x840);
    h = load_disc_file(symbolchatcolli_prs);
    if (h != NULL) {
        prs_decompress_buffer(h, symbol_chat_colli_entries);
    }
    safe_free(h);
    for (i = 0; i < 0x18; i++) {
        symbol_chat_colli_entries[i].bswap_entry();
    }
    for (i = 0; i < 3; i++) {
        symbolchat_colli_param_table[i] = 0;
    }
}

TOSymbolchatColli::~TOSymbolchatColli() {
    this->unregister_object_by_id();
    free_collision_body_parts(this);
}
TOSymbolchatColli::TOSymbolchatColli(TObject *parent, void *set_data) : TObjChara(parent) {
    s32 i;
    m_name = symbolchat_colli_name;
    apply_object_set_data(set_data);
    init_collision_body_parts(this, symbolchatcolli_collision_body_parts, 1);
    this->register_object_by_id();
    this->init_collision_params();
    for (i = 0; i < 4; i++) {
        player_inside[i] = 0;
    }
}
