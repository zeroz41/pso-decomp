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
}
#endif
