#include "types.h"
#include "pso/ui/window/TWindowSubComCard_80265410.h"
#include "pso/unk/text_802754EC.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/window/TWindowSubComCardList.h"


u8 *fn_802754EC(saddr parent) {
    fn_80266378(7);
    return (u8 *)new TWindowSubComCardList((void *)parent);
}
