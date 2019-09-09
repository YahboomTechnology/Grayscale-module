
int LDR_pin = A5; //LDR connect to port A5 of Arduino UNO

int Intensity = 0;  

#define ON 1      
#define OFF 0       

int LED_R = 9;    //LED_R connect pin9 of Arduino UNO
int LED_G = 10;   //LED_G connect pin10 of Arduino UNO
int LED_B = 11;   //LED_B connect pin11 of Arduino UNO


void setup()
{
  //the baud rate is 9600
  Serial.begin(9600);

  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);

  digitalWrite(LED_R, LOW);
  digitalWrite(LED_G, LOW);
  digitalWrite(LED_B, LOW);
}


void color_led_pwm(int v_iRed, int v_iGreen, int v_iBule)
{
  analogWrite(LED_R, v_iRed);
  analogWrite(LED_G, v_iGreen);
  analogWrite(LED_B, v_iBule);
  return;
}

void LDR_test()
{
  unsigned long color[7] = {0};
  int num = 0;
  while (num < 7)
  {
    color[num] = analogRead(LDR_pin);
    num++;
  }
  num = 0;
  bubble(color, 7);
  Intensity = (color[1] + color[2] + color[3]) / 3;
  Serial.print("Intensity = ");         
  Serial.println(Intensity);         
  return;
}

void bubble(unsigned long *a, int n) /*Define two parameters: array first address and array size*/

{
  int i, j, temp;
  for (i = 0; i < n - 1; i++)
  {
    for (j = i + 1; j < n; j++) 
    {
      if (a[i] > a[j])
      {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
      }
    }
  }
}

void loop()
{
  LDR_test(); 
  if (Intensity >= 520 && Intensity <= 600)
  {
    color_led_pwm(0, 255, 0);   //Green
  }
  if (Intensity  >= 500 && Intensity <= 520)
  {
    color_led_pwm(0, 0, 255);   //Blue
  }
  if (Intensity >= 430 && Intensity <= 440)
  {
    color_led_pwm(255, 255, 0); //Yellow
  }
  if (Intensity >= 620 && Intensity <= 740)
  {
    color_led_pwm(255, 0, 0);   //Red
  }
  if(Intensity >= 350 && Intensity<=360)
  {
    color_led_pwm(255, 255, 255); //White
  }
   if(Intensity >= 450 && Intensity<=480)
   {
     color_led_pwm(255, 0, 255);   //purple
   }
    if(Intensity >= 390 && Intensity<=400)
   {
     color_led_pwm(0, 255, 255);  // Cyan
   }
}
