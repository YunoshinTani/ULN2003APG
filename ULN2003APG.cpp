#include "ULN2003APG.h"
#include <mbed.h>

// public
ULN2003APG::ULN2003APG(PinName IN1, PinName IN2, PinName IN3, PinName IN4) : _IN1(IN1), _IN2(IN2), _IN3(IN3), _IN4(IN4)
{
    stop();
}

void ULN2003APG::stop()
{
    _IN1 = 0;
    _IN2 = 0;
    _IN3 = 0;
    _IN4 = 0;
}

void ULN2003APG::one_phase(int pulse_frequency)
{
    int v = hz_to_ms(pulse_frequency);

    _IN1 = 1;
    ThisThread::sleep_for(chrono::milliseconds(v));
    _IN1 = 0;

    _IN2 = 1;
    ThisThread::sleep_for(chrono::milliseconds(v));
    _IN2 = 0;

    _IN3 = 1;
    ThisThread::sleep_for(chrono::milliseconds(v));
    _IN3 = 0;

    _IN4 = 1;
    ThisThread::sleep_for(chrono::milliseconds(v));
    _IN4 = 0;
}

void ULN2003APG::two_phase(int pulse_frequency)
{
    int v = hz_to_ms(pulse_frequency);

    _IN1 = 1;
    _IN2 = 1;
    ThisThread::sleep_for(chrono::milliseconds(v));
    _IN1 = 0;
    _IN2 = 0;

    _IN2 = 1;
    _IN3 = 1;
    ThisThread::sleep_for(chrono::milliseconds(v));
    _IN2 = 0;
    _IN3 = 0;

    _IN3 = 1;
    _IN4 = 1;
    ThisThread::sleep_for(chrono::milliseconds(v));
    _IN3 = 0;
    _IN4 = 0;

    _IN4 = 1;
    _IN1 = 1;
    ThisThread::sleep_for(chrono::milliseconds(v));
    _IN4 = 0;
    _IN1 = 0;
}

void ULN2003APG::half_step(int pulse_frequency)
{
    int v = hz_to_ms(pulse_frequency);
    
    _IN1 = 1;
    ThisThread::sleep_for(chrono::milliseconds(v));
    _IN1 = 0;

    _IN1 = 1;
    _IN2 = 1;
    ThisThread::sleep_for(chrono::milliseconds(v));
    _IN1 = 0;
    _IN2 = 0;

    _IN2 = 1;
    ThisThread::sleep_for(chrono::milliseconds(v));
    _IN2 = 0;

    _IN2 = 1;
    _IN3 = 1;
    ThisThread::sleep_for(chrono::milliseconds(v));
    _IN2 = 0;
    _IN3 = 0;

    _IN3 = 1;
    ThisThread::sleep_for(chrono::milliseconds(v));
    _IN3 = 0;

    _IN3 = 1;
    _IN4 = 1;
    ThisThread::sleep_for(chrono::milliseconds(v));
    _IN3 = 0;
    _IN4 = 0;

    _IN4 = 1;
    ThisThread::sleep_for(chrono::milliseconds(v));
    _IN4 = 0;

    _IN4 = 1;
    _IN1 = 1;
    ThisThread::sleep_for(chrono::milliseconds(v));
    _IN4 = 0;
    _IN1 = 0;
}

// private
int ULN2003APG::hz_to_ms(int frequency)
{
    return (int)(1000.0 / frequency);
}