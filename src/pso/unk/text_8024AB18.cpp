#include "types.h"
#include "pso/unk/text_8024AB18.h"
#include "pso/unk/text_8024AB98.h"
#include "pso/ui/window/TWindowCtrl.h"


void close_window_if_active(void* p) { if (TWindowCtrl::get_flag_bit4() == 0) { TObjPlayer__sub_8024ABDC((s32)p); } }
