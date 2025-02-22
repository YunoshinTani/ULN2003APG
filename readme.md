## 概要 (about)
ステッピングモータードライバーIC "ULN2003APG" を制御するライブラリです。
GitHubのリンク [YunoshinTani/ULN2003APG](https://github.com/YunoshinTani/ULN2003APG.git).

## 機能 (function)
- ULN2003APG(PinName IN1, PinName IN2, PinName IN3, PinName IN4)
コンストラクタです。ULN2003APGのIN1~IN4を引数として渡してください。
- void one_phase(int pulse_frequency)
1相励磁させます。パルスを送る周波数を引数として渡してください。
- void two_phase(int pulse_frequency)
2相励磁させます。パルスを送る周波数を引数として渡してください。
- void half_step(int pulse_frequency)
1-2相励磁させます。パルスを送る周波数を引数として渡してください。
- void stop()
ステッピングモーターを止めます。

> [!TIP]
> 1相励磁 : 1つの電磁石のみを駆動させる制御方法。消費電力が小さいがトルクも小さい。
> 2相励磁 : 2つの電磁石を同時に駆動させる制御方法。トルクが1相励磁と比べて√2倍になるが、消費電力と発熱が増える。
> 1-2相励磁 : 1相励磁と2相励磁を交互に行う制御方法。分解能が倍(パルス毎に動く角は半分)になるが、トルクが脈動してしまう。

## コード例 (example)
```cpp
#include <mbed.h>
#include <ULN2003APG.h>

ULN2003APG motor1(D2, D3, D4, D5);
DigitalIn sw1(BUTTON1);

int main()
{
    bool is_state1 = false;
    bool was_state1 = false;
    
    while (true)
    {
        if (sw1 == 0) {
            if (!was_state1) {
                is_state1 = true;
                printf("1\n");
                motor1.one_phase(450);
            }
            else {
                is_state1 = false;
                printf("2\n");
                motor1.two_phase(450);
            }
        }
        else {
            was_state1 = is_state1;
            printf("0\n");
            motor1.half_step(450);
        }
    }
}
```
> [!NOTE]
> stop() は入れなくても各関数を実行し終えた後、自動的に止まります