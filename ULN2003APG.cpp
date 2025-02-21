#include "ULN2003APG.h"
#include <mbed.h>

ULN2003APG::ULN2003APG(PinName IN1, PinName IN2, PinName IN3, PinName IN4) : _IN1(IN1), _IN2(IN2), _IN3(IN3), _IN4(IN4), _step_in{_IN1, _IN2, _IN3, _IN4}
{
    _IN1.write(0);
    _IN2.write(0);
    _IN3.write(0);
    _IN4.write(0);
}

int ULN2003APG::hz_to_ms(int frequency)
{
    return (int)(1000.0 / frequency);
}

void ULN2003APG::one_phase(int pulse_frequency)
{
    int v = 1000.0 / pulse_frequency;

    _IN1 = 1;
    ThisThread::sleep_for(chrono::milliseconds(v));
    _IN1 = 0;

    _IN2 = 1;
    ThisThread::sleep_for(chrono::milliseconds(v));
    _IN2 = 0;

    _IN3 = 1;
    ThisThread::sleep_for(chrono::milliseconds(v));
    _IN3 = 0;
}