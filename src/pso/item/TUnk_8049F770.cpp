#include "types.h"
#include "pso/TMainTask.h"
#include "pso/item/TUnk_8049F770.h"
#include "pso/item/TItemProShield.h"
#include "pso/player/TObjPlayer.h"

extern "C" {
s32 add_actor_hp(u8 *arg0, s16 arg1);
s32 get_item_index__5TItemFv(void *);
extern s32 game_difficulty_selection;
}

// Monomate and dimate heal their PMT amount plus half of it per difficulty
// level; the trimate fills HP.
void TUnk_8049F770::apply_use_effect() {
  u8 (*new_var2)(void *);
  s32 t;
  new_var2 = (u8 (*)(void *)) get_item_index__5TItemFv;
  if (new_var2(this) != 2)
  {
    int new_var;
    t = get_pmt_amount();
    new_var = game_difficulty_selection;
    new_var = t + (new_var * (t / 2));
    add_actor_hp((u8 *)this->owner, new_var);
  }
  else
  {
    add_actor_hp((u8 *)this->owner, ((TItemProShield *)(this->owner))->get_field_2b8());
  }
}

TUnk_8049F770::~TUnk_8049F770() {}

TUnk_8049F770::TUnk_8049F770(TObject *parent, u8 *item) : TItemObject(parent, item) {}

TUnk_8049F770 *TUnk_8049F770::create(u8 *item) {
    if (item != NULL) {
        return new TUnk_8049F770(tl_05, item);
    }
    return NULL;
}
