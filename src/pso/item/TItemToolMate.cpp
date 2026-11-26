#include "types.h"
#include "pso/item/TItem.h"
#include "pso/system/task/TMainTask.h"
#include "pso/item/TItemToolMate.h"
#include "pso/object/base/TObjChara.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/ui/TLevelSelect.h"

extern "C" {
s32 get_item_index__5TItemFv(void *);
}

// Monomate and dimate heal their PMT amount plus half of it per difficulty
// level; the trimate fills HP.
void TItemToolMate::apply_use_effect() {
  u8 (*get_index)(void *);
  s32 t;
  get_index = (u8 (*)(void *)) get_item_index__5TItemFv;
  if (get_index(this) != 2)
  {
    int heal;
    t = get_pmt_amount();
    heal = game_difficulty_selection;
    heal = t + (heal * (t / 2));
    add_actor_hp((TObjChara *)this->owner, heal);
  }
  else
  {
    add_actor_hp((TObjChara *)this->owner, ((TObjChara *)(this->owner))->get_hpmax());
  }
}

TItemToolMate::~TItemToolMate() {}

TItemToolMate::TItemToolMate(TObject *parent, u8 *item) : TItemObject(parent, item) {}

TItem *TItemToolMate::create(u8 *item) {
    if (item != NULL) {
        return new TItemToolMate(tl_05, item);
    }
    return NULL;
}
