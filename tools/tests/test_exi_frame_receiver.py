"""Characterize the actual receive wrapper with a synthetic dispatcher.

This host test covers null handling and opaque argument forwarding. It does not
execute the EXI driver or establish callback ABI, packet extent, or lifetime.
"""

from pathlib import Path
import shutil
import subprocess
import tempfile
import unittest


ROOT = Path(__file__).resolve().parents[2]


def receiver_body():
    source = (ROOT / "src/pso/network/NetworkMessageTransport.c").read_text()
    signature = "void forward_to_channel(void *frame, void *b)"
    start = source.index(signature + " {")
    opening = source.index("{", start)
    depth = 1
    end = opening + 1
    while depth:
        depth += (source[end] == "{") - (source[end] == "}")
        end += 1
    return source[start:end]


HARNESS = r"""
#include <cstddef>
#include <cstdint>
#include <cstring>

#include "pso/network/EthernetReceiveFilter.h"

static struct { EthernetReceiveFilter filter; } lobby_net_channel_table;
static unsigned calls;
static void *seen_queue;
static void *seen_frame;
static void *seen_word;
void dispatch_received_ethernet_frame(EthernetReceiveFilter *q, void *frame, void *word) {
    ++calls;
    seen_queue = q;
    seen_frame = frame;
    seen_word = word;
}

@RECEIVER@

int main(int argc, char **argv) {
    if (argc != 2) return 1;
    const uintptr_t words[] = {0, 1, 0x5EE, 0xFFFF, 0xFFFFFFFF};
    static unsigned char frame[16];
    static unsigned char before[16];
    std::memset(frame, 0xA5, sizeof(frame));
    std::memcpy(before, frame, sizeof(frame));
    const bool null_frame = argv[1][0] == 'n';
    for (unsigned i = 0; i < sizeof(words) / sizeof(words[0]); ++i) {
        calls = 0;
        seen_queue = before;
        seen_frame = before;
        seen_word = before;
        void *word = reinterpret_cast<void *>(words[i]);
        forward_to_channel(null_frame ? NULL : frame, word);
        if (null_frame) {
            if (calls != 0 || seen_queue != before || seen_frame != before ||
                seen_word != before) return 2;
        } else {
            if (calls != 1 || seen_queue != &lobby_net_channel_table.filter ||
                seen_frame != frame || seen_word != word) return 3;
        }
        if (std::memcmp(frame, before, sizeof(frame)) != 0) return 4;
    }
    return 0;
}
"""


class ExiFrameReceiverTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        compiler = shutil.which("g++")
        if compiler is None:
            raise unittest.SkipTest("g++ is required for the host characterization")
        cls.temp = tempfile.TemporaryDirectory(prefix="pso-exi-receiver-")
        cls.addClassCleanup(cls.temp.cleanup)
        root = Path(cls.temp.name)
        source = root / "receiver.cpp"
        cls.exe = root / "receiver"
        source.write_text(HARNESS.replace("@RECEIVER@", receiver_body()))
        subprocess.run(
            [compiler, "-std=c++17", "-O2", "-Wall", "-Wextra", "-Werror",
             "-iquote", str(ROOT / "include"), str(source), "-o", str(cls.exe)],
            check=True, capture_output=True, text=True,
        )

    def test_null_frame_does_not_dispatch(self):
        subprocess.run([str(self.exe), "null"], check=True)

    def test_frame_and_opaque_word_are_forwarded_unchanged(self):
        subprocess.run([str(self.exe), "frame"], check=True)


if __name__ == "__main__":
    unittest.main()
