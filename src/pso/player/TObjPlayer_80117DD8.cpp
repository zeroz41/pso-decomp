#include "types.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItemData.h"
#include "pso/item/armor/TItemProShield.h"

struct Pl_80117F14 { u8 pad0[0x38]; f32 pos[3]; };

extern "C" {
f32 horizontal_distance_squared(void *, void *);
void *get_player_by_client_id(s32 i);
extern const f64 lbl_8043E650[];
extern const f64 lbl_8043E648[];
#pragma push
#pragma dont_inline off
s32 TObjPlayer__sub_80117E50(s32 id) {
  u8 *base;
  u8 *self;
  u8 *new_var2;
  u8 *p;
  s32 mask;
  s32 k;
  void *new_var;
  s32 result = 0;
  u16 i;
  new_var = ((u8 * (*)(s32))get_player_by_client_id)((u16) id);
  base = (unsigned char *)(new_var);
  self = base;
  new_var2 = self;
  if (new_var2 != ((void *) 0))
  {
    mask = 1;
    mask = (((TObjPlayer *) new_var2)->class_flags & 1) + mask;
    k = ((TObjPlayer *) self)->get_floor();
    for (i = 0; i != 4; i++)
    {
      if (i == ((u16) id))
      {
        continue;
      }
      p = ((u8 * (*)(s32))get_player_by_client_id)(i);
      if ((p != ((void *) 0)) && ((((TObjPlayer *) p)->class_flags & mask) != 0))
      {
        if (((TObjPlayer *) p)->get_floor() == k)
        {
          if (((f32 (*)(void *, void *))horizontal_distance_squared)(new_var2 + 0x38, p + 0x38) < lbl_8043E648[0])
          {
            result = 1;
            break;
          }
        }
      }
    }

  }
  return result;
}
#pragma pop
s32 TObjPlayer::count_nearby_players_with_shield(u16 idx, u8 *item) {
    s32 key;
    Pl_80117F14 *me;
    s32 count;
    u16 i;
    Pl_80117F14 *other;
    void *it;
    count = 0;
    me = (Pl_80117F14 *)get_player_by_client_id(idx);
    if (me != NULL && item != NULL) {
        key = ((TObjPlayer *)me)->get_floor();
        for (i = 0; i != 4; i++) {
            if (i != idx) {
                other = (Pl_80117F14 *)get_player_by_client_id(i);
                if (other != NULL && key == ((TObjPlayer *)other)->get_floor() &&
                    horizontal_distance_squared(me->pos, other->pos) < lbl_8043E650[0] &&
                    (it = (void *)((TItemData *)other)->test_flag3()) != NULL &&
                    item[2] == ((TItem *)it)->get_item_index()) {
                    count++;
                }
            }
        }
    }
    return count;
}

}
