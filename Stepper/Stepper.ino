#include <Unistep2.h>

Unistep2 stepper(8, 9, 10, 11, 4096, 1000);// IN1, IN2, IN3, IN4, 總step數, 每步的延遲(in micros)
int state = 0;

void setup()
{
}

void loop()
{
  stepper.run();  //步進機啟動

  if ( stepper.stepsToGo() == 0 )   // 如果stepsToGo=0，表示步進馬達已轉完應走的step了
  {
    switch (state)
    {
      case 0:
        stepper.move(4096);    //正轉一圈
        state = 1;
        break;

      case 1:
        stepper.move(-4096);  //負數就是反轉，反轉一圈
        state = 0;
        break;
    }
  }
}
