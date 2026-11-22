#include "pso/ui/window/MessageWindowSettingsAbi.h"
#include "types.h"
#include "pso/unk/TLobby_80269C6C.h"
#include "pso/unk/text_80269FE8.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/window/TWindowMessageInfomation.h"
saddr create_message_information_window(saddr parent, saddr extent, saddr client) {
  u8 *temp_r3;
  s32 phi_r4;
  temp_r3 = (u8 *) TLobby__sub_80269CB4();
  *((s32 *) (((s8 *) temp_r3) + 0x10)) = (s32) ((*((s32 *) (((s8 *) temp_r3) + 0x10))) | 0x20);
  TLobby__sub_80269DA4((void *) extent, 0x10);
  phi_r4 = (saddr)new TWindowMessageInfomation(parent, client);
  *((s32 *) (((s8 *) temp_r3) + 0x10)) = (s32) ((*((s32 *) (((s8 *) temp_r3) + 0x10))) & 0xFFFFFFDF);
  return phi_r4;
}
