#include <thread>
#include "windows.h"
#include "Audio.h"

void Audio::PlayFrequency(int frequency, int duration) {
    std::thread t(Beep, frequency, duration);
    t.detach();
}
