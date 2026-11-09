#ifndef PSO_AUDIO_ADXMTHREADSTORAGE_H
#define PSO_AUDIO_ADXMTHREADSTORAGE_H
#include "types.h"
struct OSThread;
enum { ADXM_WORKER_STACK_BYTES = 0x2000, ADXM_VBLANK_STACK_BYTES = 0x2000,
       ADXM_BUSY_WAIT_STACK_BYTES = 0x1000 };
extern "C" {
extern OSThread adxm_worker_thread;
extern OSThread adxm_vblank_thread;
extern OSThread adxm_busy_wait_thread;
extern u8 adxm_worker_stack[ADXM_WORKER_STACK_BYTES];
extern u8 adxm_vblank_stack[ADXM_VBLANK_STACK_BYTES];
extern u8 adxm_busy_wait_stack[ADXM_BUSY_WAIT_STACK_BYTES];

// Flags shared between the ADXM threads (main, worker, vblank, busy-wait).
// lbl_805D75C8/lbl_805D759C are polled in the call-free loop of
// TLobby::wait_for_lock_release; the others are each written by one thread and
// read by another (worker_thread_loop, TLobby__sub_803CBB14,
// adxm_goto_mwidle_border, __OSCallResetFunctions), and TLobby__sub_803CB858
// stores them in source order, which CodeWarrior keeps only for volatile objects.
extern volatile s32 lbl_805D759C;
extern volatile s32 lbl_805D75B0;
extern volatile s32 lbl_805D75B4;
extern volatile s32 lbl_805D75B8;
extern volatile s32 lbl_805D75BC;
extern volatile s32 lobby_worker_thread_run_flag;
extern volatile s32 lbl_805D75C4;
extern volatile s32 lbl_805D75C8;
}
#endif
