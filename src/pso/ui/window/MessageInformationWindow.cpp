#include "pso/ui/window/MessageWindowSettingsAbi.h"
#include "types.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/ui/window/MessageInformationWindow.h"
#include "pso/system/task/TObject.h"
#include "pso/unk/WindowLayoutRecord.h"
#include "pso/ui/window/TWindowMessageInfomation.h"
TWindowMessageInfomation *create_message_information_window(const NJS_POINT2 *position, const NJS_POINT2 *extent, s32 client) {
  WindowDescriptor *state;
  TWindowMessageInfomation *window;
  state = get_message_window_settings();
  state->flags |= 0x20;
  set_message_window_size(extent, 0x10);
  window = new TWindowMessageInfomation(position, client);
  state->flags &= 0xFFFFFFDF;
  return window;
}
