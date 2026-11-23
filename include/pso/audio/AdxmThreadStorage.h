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
// adxm_busy_wait_run_flag/adxm_busy_wait_spin_count are polled in the call-free loop of
// TLobby::wait_for_lock_release; the others are each written by one thread and
// read by another (worker_thread_loop, vblank_thread_loop,
// adxm_goto_mwidle_border, __OSCallResetFunctions), and init_runtime_threads
// stores them in source order, which CodeWarrior keeps only for volatile objects.
extern volatile s32 adxm_busy_wait_spin_count;
extern volatile s32 adxm_lock_transition_flag;
extern volatile s32 adxm_vblank_thread_stopped;
extern volatile s32 adxm_vblank_thread_run_flag;
extern volatile s32 adxm_worker_thread_stopped;
extern volatile s32 lobby_worker_thread_run_flag;
extern volatile s32 adxm_busy_wait_stopped;
extern volatile s32 adxm_busy_wait_run_flag;

// SVM lock/unlock callbacks init_runtime_threads registers.
void __OSCallResetFunctions(s32 context);
void adxm_svm_unlock_callback(s32 context);
}
#endif
