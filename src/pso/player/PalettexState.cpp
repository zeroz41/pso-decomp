#include "types.h"
#include "pso/player/PalettexState.h"
#include "pso/ui/frontend/TAdPlyPltAnimCtrlGC.h"
#include "pso/ui/frontend/TAdRicoRing_8001BEE8.h"

s32 PalettexState::get_callback_label() { return callback_label; }

void PalettexState::set_callback_label(s32 label) { callback_label = label; }

s32 PalettexState::is_enabled() { return test_flags_all(&flags.bits, 3); }

void PalettexState::disable() { flags.clear(2); }

void PalettexState::enable() { flags.set(3); }

s32 PalettexState::is_activated() { return test_flags_any(&flags.bits, 1); }

void PalettexState::restore() { flags.clear(3); }

void PalettexState::activate() { flags.set(1); }

void PalettexState::reset() {
    flags.reset();
    callback_label = 0;
}

PalettexState::~PalettexState() {}

PalettexState::PalettexState() { reset(); }
