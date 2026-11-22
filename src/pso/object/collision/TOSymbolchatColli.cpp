#include "pso/system/ResourceFile.h"
#include "pso/render/render_util.h"
#include "pso/object/collision/TOSymbolchatColli.h"

#include "pso/system/NinjaTypes.h"
#include "types.h"
#include <string.h>
#include "pso/object/base/TObjMotion.h"
#include "pso/object/base/TObjChara.h"

#include "pso/ui/chat/TWindowSubSymbolChat.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/task/TObject.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/system/task/TMainTask.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/unk/text_800F7DAC.h"
#include "pso/object/switch/TSwitch.h"
#include "pso/object/base/CollisionActorLookup.h"

struct VBase_80178AD4 { u8 pad[0x18]; };

struct Obj_80178AD4 : VBase_80178AD4 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(s32);
    u8 pad1[0x338 - 0x1C];
    s32 arr[4];
};

struct Obj_80178890 { u8 pad[0x38]; f32 pos[3]; u8 pad44[0x334 - 0x44]; f32 radiusSq; s32 inside[4]; };

struct Player_80178890 { u8 pad[0x38]; f32 pos[3]; };

struct Obj_8017873C
{
  u8 pad[0x3C];
  f32 y3c;
  u8 pad40[0x68 - 0x40];
  f32 radius;
  u8 pad6c[0x84 - 0x6C];
  u32 ids[3];
  u8 pad90[0x334 - 0x90];
  f32 radiusSq;
  u8 pad338[0x348 - 0x338];
  u8 coll[0x10];
  f32 y358;
  u8 pad35c[0x36C - 0x35C];
  uaddr ptrs[3];
  u16 hi[3];
  u16 lo[3];
};

struct HL_8017873C
{
  u8 pad[0x378];
  u16 hi;
  u16 pad37a[2];
  u16 lo;
};

struct Ent_8017873C
{
  u8 pad[0x1C];
  u8 f1c[0x3C];
};

extern "C" {
void init_collision_body_parts(void *, void *, int);
CollisionBody lbl_804B4550[1] = {
    { { 0.0f, 80.0f, 0.0f }, 1.0f, 1.0f, 0, 0x10002, { 0.0f, 0.0f, 0.0f }, 0.0f },
};
const char *lbl_805D3190 = "symbolchatcolli.prs";
const char *TOSymbolchatColli__name = "TOSymbolchatColli";
Obj_80178AD4 *__ct__17TOSymbolchatColliFP7TObjectl(Obj_80178AD4 *arg0, void *arg1, s32 arg2);
void fn_8017866C(void *, s32, u16);
void run_task__17TOSymbolchatColliFv(Obj_80178890 *self);
u32 symbolchat_colli_param_table[4];
saddr symbol_chat_colli_entries;
s32 free_collision_body_parts(void *);

s32 TOSymbolchatColli::get_state() {
    if (is_current_floor_switch_set(this->m_37c) == 1) {
        return 3;
    }
    if (is_current_floor_switch_set(*(u16 *)&this->unk_37A) == 1) {
        return 2;
    }
    return (u32) __cntlzw(1 - is_current_floor_switch_set(this->m_378)) >> 5;
}


typedef struct Ent_8017873C Ent_8017873C;
typedef struct HL_8017873C HL_8017873C;
typedef struct Obj_8017873C Obj_8017873C;
void TOSymbolchatColli::init_collision_params() {
  Obj_8017873C *self = (Obj_8017873C *) this;
  s32 i;
  self->radiusSq = this->scale.x * this->scale.x;
  memset(self->coll, 0, 0x24);
  this->m_358 = self->y3c / 0.92f;
  ((TObjChara *)self)->set_motion_params(self->coll);
  for (i = 0; i < 3; i++)
  {
    u32 v = self->ids[i];
    u32 hi;
    u32 lo;
    hi = v >> 16;
    lo = (u16) v;
    if (symbolchat_colli_param_table[i] == 0)
    {
      hi = v >> 16;
      if (lo < 0x18)
      {
        self->ptrs[i] = (uaddr) (&((Ent_8017873C *) symbol_chat_colli_entries)[lo].f1c);
      }
      else
      {
        self->ptrs[i] = 0;
      }
    }
    else
    {
      self->ptrs[i] = symbolchat_colli_param_table[i];
    }
    {
      HL_8017873C *h = (HL_8017873C *) (((u8 *) self) + (i * 2));
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
    u8 *arg0 = (u8 *)this;
    if (TObjPlayer::check_demo_mode() == 1) {
        NJS_ARGB color;
        color.a = 0.3f;
        color.r = 0.0f;
        color.g = 0.3f;
        color.b = 0.3f;
        debug_draw_sphere(&position, &color, newton_sqrtf(*(f32 *)(arg0 + 0x334)));
    }
}

void run_task__17TOSymbolchatColliFv(Obj_80178890 *self) {
    u16 i;
    Player_80178890 *pl;
    for (i = 0; i != 4; i++) {
        pl = (Player_80178890 *)find_entity_by_id(i);
        if (pl != NULL && TObjPlayer::is_locally_controlled(pl) != 0) {
            if (horizontal_distance_squared((const Vec *)pl->pos, (const Vec *)self->pos) < self->radiusSq) {
                if (self->inside[i] == 0) {
                    self->inside[i] = 1;
                    s32 st = ((TOSymbolchatColli *)self)->get_state();
                    fn_8017866C(self, st, i);
                }
            } else {
                if (self->inside[i] != 0) {
                    self->inside[i] = 0;
                }
            }
        }
    }
}

void *TOSymbolchatColli::create(void *arg0) {
    void *o = TObject::operator new(0x384);
    if (o != NULL) {
        o = __ct__17TOSymbolchatColliFP7TObjectl((Obj_80178AD4 *)(o), tl_05, (saddr)arg0);
    }
    return o;
}

void TOSymbolchatColli::free_rock() { mem_free((void *)symbol_chat_colli_entries); symbol_chat_colli_entries = 0; }

void TOSymbolchatColli::load_symbol_chat_data() {
    saddr h;
    s32 i;
    symbol_chat_colli_entries = (saddr)mem_alloc(0x840);
    h = (saddr)load_disc_file(lbl_805D3190);
    if (h != 0) {
        prs_decompress_buffer(h, symbol_chat_colli_entries);
    }
    TAdSinglePlyChrSelectGC::safe_free(h);
    for (i = 0; i < 0x18; i++) {
        ((TWindowSubSymbolChat *)((u8 *)symbol_chat_colli_entries + i * 0x58))->bswap_entry();
    }
    for (i = 0; i < 3; i++) {
        symbolchat_colli_param_table[i] = 0;
    }
}

}
TOSymbolchatColli::~TOSymbolchatColli() {
    this->unregister_object_by_id();
    free_collision_body_parts(this);
}
TOSymbolchatColli::TOSymbolchatColli(TObject *parent, s32 arg2) : TObjChara(parent) {
    s32 i;
    m_name = TOSymbolchatColli__name;
    ((Obj_80178AD4 *)this)->v5(arg2);
    init_collision_body_parts(this, lbl_804B4550, 1);
    this->register_object_by_id();
    this->init_collision_params();
    for (i = 0; i < 4; i++) {
        ((Obj_80178AD4 *)this)->arr[i] = 0;
    }
}
