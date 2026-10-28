#include "types.h"
#include "pso/object/TObjMotion.h"
#include "pso/player/TUnk_804806E8.h"
#include "pso/misc/TOSymbolchatColli.h"
#include "pso/misc/TWindowSubSymbolChat.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct Stack_80178830 {
    f32 sp8;
    f32 spC;
    f32 sp10;
    f32 sp14;
};

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
  u32 ptrs[3];
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
f32 newton_sqrtf(f32 x);
s32 TObjRoomId__sub_80141CF4(void *, void *);
extern const f32 lbl_805DBA2C;
extern const f32 lbl_805DBA30;
void __ct__13TUnk_804806E8FP7TObject(void *);
void init_collision_body_parts(void *, void *, int);
extern u8 lbl_804B4550[];
extern s32 __vt__17TOSymbolchatColli[];
extern s32 lbl_805D3194;
Obj_80178AD4 *TOSymbolchatColli__ct(Obj_80178AD4 *arg0, void *arg1, s32 arg2);
s32 is_locally_controlled__10TObjPlayerFPv();
f32 horizontal_distance_squared(void *, void *);
void *find_entity_by_id(u16 id);
void fn_8017866C(void *, s32, u16);
void run_task__17TOSymbolchatColliFv(Obj_80178890 *self);
u32 prs_decompress_buffer(s32 arg0, s32 arg1);
s32 set_stream_and_load_file__6TLobbyFi(s32);
void *mem_alloc(u32 size);
extern u32 symbolchat_colli_param_table[];
extern s32 lbl_805D3190;
extern int symbol_chat_colli_entries;
void *memset(void *, int, u32);
extern const f32 lbl_805DBA28;
void *__dt__17TOSymbolchatColliFv(void *arg0, s16 arg1);
u8 is_current_floor_switch_set(u16);
s32 free_collision_body_parts(void *);
s32 __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);
void mem_free(void *p);

s32 TOSymbolchatColli::get_state() {
    if (is_current_floor_switch_set(this->m_37c) == 1) {
        return 3;
    }
    if (is_current_floor_switch_set(*(u16 *)&this->unk_37A) == 1) {
        return 2;
    }
    return (u32) __cntlzw(1 - is_current_floor_switch_set(this->m_378)) >> 5;
}

extern void *tl_05;

typedef struct Ent_8017873C Ent_8017873C;
typedef struct HL_8017873C HL_8017873C;
typedef struct Obj_8017873C Obj_8017873C;
void TOSymbolchatColli::init_collision_params() {
  Obj_8017873C *self = (Obj_8017873C *) this;
  s32 i;
  self->radiusSq = this->scale.x * this->scale.x;
  memset(self->coll, 0, 0x24);
  this->m_358 = self->y3c / lbl_805DBA28;
  ((TUnk_804806E8 *)self)->set_motion_params(self->coll);
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
        self->ptrs[i] = (u32) (&((Ent_8017873C *) symbol_chat_colli_entries)[lo].f1c);
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
    Stack_80178830 stack;
    if (TObjPlayer::check_demo_mode() == 1) {
        stack.sp8 = lbl_805DBA2C;
        stack.spC = lbl_805DBA30;
        stack.sp10 = lbl_805DBA2C;
        stack.sp14 = lbl_805DBA2C;
        newton_sqrtf((f32) (*(f32 *)((s8 *)arg0 + 0x334)));
        TObjRoomId__sub_80141CF4((u8 *)&this->position, &stack.sp8);
    }
}

void run_task__17TOSymbolchatColliFv(Obj_80178890 *self) {
    u16 i;
    Player_80178890 *pl;
    for (i = 0; i != 4; i++) {
        pl = (Player_80178890 *)find_entity_by_id(i);
        if (pl != NULL && is_locally_controlled__10TObjPlayerFPv() != 0) {
            if (horizontal_distance_squared(pl->pos, self->pos) < self->radiusSq) {
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
    void *o = __nw__7TObjectFUl(0x384);
    if (o != NULL) {
        o = TOSymbolchatColli__ct((Obj_80178AD4 *)(o), (void *)tl_05, (s32)arg0);
    }
    return o;
}

void TOSymbolchatColli::free_rock() { mem_free((void *)symbol_chat_colli_entries); symbol_chat_colli_entries = 0; }

void TOSymbolchatColli::load_symbol_chat_data() {
    s32 h;
    s32 i;
    symbol_chat_colli_entries = (int)mem_alloc(0x840);
    h = set_stream_and_load_file__6TLobbyFi(lbl_805D3190);
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

void *__dt__17TOSymbolchatColliFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__17TOSymbolchatColli;
        ((TUnk_804AF8A0 *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        ((TUnk_804806E8 *)arg0)->destroy_motion_object(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
Obj_80178AD4 *TOSymbolchatColli__ct(Obj_80178AD4 *arg0, void *arg1, s32 arg2) {
    s32 i;
    __ct__13TUnk_804806E8FP7TObject(arg0);
    *(u8 **)((u8 *)arg0 + 0x18) = ((u8 *)&__vt__17TOSymbolchatColli);
    *(s32 *)arg0 = lbl_805D3194;
    arg0->v5(arg2);
    init_collision_body_parts(arg0, lbl_804B4550, 1);
    ((TObjPlayer *)arg0)->reset_photon_effect();
    ((TOSymbolchatColli *)arg0)->init_collision_params();
    for (i = 0; i < 4; i++) {
        arg0->arr[i] = 0;
    }
    return arg0;
}

}
