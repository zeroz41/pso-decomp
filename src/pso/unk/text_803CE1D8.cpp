#include "types.h"
#include "pso/unk/text_803CE1D8.h"
// Object view exposing the 0xAC byte that TLobby__sub_803CE1D8 returns as the
// per-lobby track count (consumed as the tracks[] loop bound in text_803CE240).
struct LobbyTrackCountSource
{
  u8 unknown_0[0xAC];
  u8 trackCount;
};

s8 TLobby__sub_803CE1D8(u8 *lobby) {
  s8 new_var;
  int new_var2;
  new_var2 = ((LobbyTrackCountSource *) lobby)->trackCount & 0xFFFFFFFFFFFFFFFFu;
  new_var = (s8) new_var2;
  return new_var;
}
