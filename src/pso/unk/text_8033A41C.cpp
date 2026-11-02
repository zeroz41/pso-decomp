#include "types.h"
#include "pso/TSaveChCr.h"

// Per-state actions of TSaveChCr: the first runs when set_state enters the
// state, the task runs every frame from run_task.
TSaveChCrStateActions lbl_804EF658[5] = {
    {&TSaveChCr::fn_80339D78, &TSaveChCr::update_save_state},
    {&TSaveChCr::save_1, &TSaveChCr::sub_80339CE4},
    {&TSaveChCr::close_and_advance_step2, &TSaveChCr::update_save_status},
    {&TSaveChCr::close_and_advance_to_3, &TSaveChCr::save_if_dirty},
    {&TSaveChCr::sub_80339B94, &TSaveChCr::destroy_if_keyboard_idle},
};
