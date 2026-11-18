#include "pso/port/ExiEthernetFallbacks.h"
#include <cassert>

int main() {
    using namespace pso::port;
    for (uint32_t value = 0; value != 65536; ++value) {
        uint16_t swapped = exi_swap16(static_cast<uint16_t>(value));
        assert((swapped & 255) == value / 256);
        assert(swapped / 256 == (value & 255));
        assert(exi_swap16(swapped) == value);

        uint32_t command = exi_read_command(value | 0xABCD0000u);
        assert((command & 0xFF0000FFu) == 0x80000000u);
        assert(((command >> 8) & 65535) == value);

        int significant_bits = 0;
        for (uint32_t remaining = value; remaining; remaining /= 2) {
            ++significant_bits;
        }
        assert(exi_leading_zeroes(value) == 32 - significant_bits);
    }
    for (unsigned bit = 0; bit < 32; ++bit) {
        uint32_t value = uint32_t(1) << bit;
        assert(exi_leading_zeroes(value) == static_cast<int>(31 - bit));
        assert(exi_leading_zeroes(value | (value - 1)) == static_cast<int>(31 - bit));
    }
}
