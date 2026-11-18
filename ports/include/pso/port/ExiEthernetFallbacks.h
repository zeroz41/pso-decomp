#ifndef PSO_PORT_EXI_ETHERNET_FALLBACKS_H
#define PSO_PORT_EXI_ETHERNET_FALLBACKS_H

#include <stdint.h>

#ifdef __cplusplus
namespace pso { namespace port {
#endif

static inline uint16_t exi_swap16(uint16_t value) {
    return (uint16_t)((value >> 8) | (value << 8));
}

static inline uint32_t exi_read_command(uint32_t reg) {
    return ((reg << 8) & 0x00FFFF00u) | 0x80000000u;
}

static inline int exi_leading_zeroes(uint32_t value) {
    int count = 0;
    for (uint32_t bit = 0x80000000u; bit && !(value & bit); bit >>= 1) {
        ++count;
    }
    return count;
}

#ifdef __cplusplus
} }
#endif

#endif
