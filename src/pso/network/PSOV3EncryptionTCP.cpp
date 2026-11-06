#include "pso/network/PSOV3EncryptionTCP.h"
#include <stddef.h>

typedef char TcpCipherSize[(sizeof(PSOV3EncryptionTCP) == 0x838) ? 1 : -1];
typedef char TcpCipherOffset[(offsetof(PSOV3EncryptionTCP, m_encryption) == 0) ? 1 : -1];
typedef char TcpSeedOffset[(offsetof(PSOV3EncryptionTCP, m_seed) == 0x834) ? 1 : -1];

void PSOV3EncryptionTCP::encrypt(void *void_data, int size) {
    u32 *data = reinterpret_cast<u32 *>(void_data);
    size = (size + 3) / 4;
    for (int i = 0; i < size; ++i) {
        bswap_32(&data[i]);
        data[i] ^= m_encryption.next();
        bswap_32(&data[i]);
    }
}

void PSOV3EncryptionTCP::reset(u32 seed) {
    m_seed = seed;
    m_encryption.init(seed);
}

PSOV3EncryptionTCP::~PSOV3EncryptionTCP() {}

PSOV3EncryptionTCP::PSOV3EncryptionTCP() {
    reset(0);
}
