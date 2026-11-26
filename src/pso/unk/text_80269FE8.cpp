#include "pso/ui/window/MessageWindowSettingsAbi.h"
#include "types.h"
#include "pso/unk/TLobby_80269C6C.h"
#include "pso/unk/text_80269FE8.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/window/TWindowMessageInfomation.h"
saddr create_message_information_window(const NJS_POINT2 *position, saddr extent, saddr client) {
  u8 *state;
  s32 window;
  state = (u8 *) get_message_window_settings();
  *((s32 *) (((s8 *) state) + 0x10)) = (s32) ((*((s32 *) (((s8 *) state) + 0x10))) | 0x20);
  set_message_window_size((void *) extent, 0x10);
  window = (saddr)new TWindowMessageInfomation(position, client);
  *((s32 *) (((s8 *) state) + 0x10)) = (s32) ((*((s32 *) (((s8 *) state) + 0x10))) & 0xFFFFFFDF);
  return window;
}
