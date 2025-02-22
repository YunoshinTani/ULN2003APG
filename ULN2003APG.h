#ifndef ULN2003APG_H
#define ULN2003APG_H

#include <mbed.h>

class ULN2003APG
{
public:
    /**
     * @brief コンストラクタです。ULN2003APGのIN1~IN4に接続されたピンを指定してください。
     * @param IN1 ULN2003APGのIN1に接続されたピン(DigitalOut)
     * @param IN2 ULN2003APGのIN2に接続されたピン(DigitalOut)
     * @param IN3 ULN2003APGのIN3に接続されたピン(DigitalOut)
     * @param IN4 ULN2003APGのIN4に接続されたピン(DigitalOut)
     */
    ULN2003APG(PinName IN1, PinName IN2, PinName IN3, PinName IN4);

    /**
     * @brief ステッピングモーターを停止します。
     */
    void stop();

    /**
     * @brief 1相励磁します。
     * @param pulse_frequency パルス周波数
     */
    void one_phase(int pulse_frequency);
    
    /**
     * @brief 2相励磁します。
     * @param pulse_frequency パルス周波数
     */
    void two_phase(int pulse_frequency);
    
    /**
     * @brief ハーフステップ励磁します。
     * @param pulse_frequency パルス周波数
     */
    void half_step(int pulse_frequency);

private:
    DigitalOut _IN1;
    DigitalOut _IN2;
    DigitalOut _IN3;
    DigitalOut _IN4;

    /**
     * @brief 周波数をミリ秒に変換します。
     * @param frequency 周波数
     * @return ミリ秒
     */
    int hz_to_ms(int frequency);
};

#endif // ULN2003APG_H