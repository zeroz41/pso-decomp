#include "types.h"
#include "pso/unk/text_803CE1D8.h"
struct RecoveredFields_803CE1D8_arg0
{
  u8 unknown_0[0xAC];
  u8 field_AC;
};

typedef struct RecoveredFields_803CE1D8_arg0 RecoveredFields_803CE1D8_arg0;
s8 TLobby__sub_803CE1D8(u8 *lobby) {
  s8 new_var;
  int new_var2;
  new_var2 = ((RecoveredFields_803CE1D8_arg0 *) lobby)->field_AC & 0xFFFFFFFFFFFFFFFFu;
  new_var = (s8) new_var2;
  return new_var;
}
