#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#include <IRremote.h>
const int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results results;
unsigned long key_value = 0;

int DECIMAL = 0;
bool ADD = false;
bool SUB = false;

void setup()
{
  lcd.begin(16,2);
  irrecv.enableIRIn();
  irrecv.blink13(true);
}

void loop()
{
        if (irrecv.decode(&results))
        {

                switch(results.value)
                {

                        case 0xFFE01F:
                        {
                                /*If line is not clearned and "decimal reset" was displayed last
                                then the output would look like "DEC-mal reset" instead of DEC-*/
                                lcd.clear();
                                lcd.print("DEC-");
                                ADD = false; SUB = true;
                        }break;

                        case  0xFFA857:
                        {
                                lcd.clear();
                                lcd.print("DEC+");
                                ADD = true; SUB = false;
                        }break;

                        case 0xFF9867:
                        {
                                if (ADD == true && SUB == false)
                                {
                                        DECIMAL += 100;
                                }
                                else if (ADD == false && SUB == true)
                                {
                                        DECIMAL -= 100;
                                }
                        }break;

                        case 0xFFB04F:
                        {
                                if (ADD == true && SUB == false)
                                {
                                        DECIMAL += 200;
                                }
                                else if (ADD == false && SUB == true)
                                {
                                        DECIMAL -= 200;
                                }
                        }break;

                        case 0xFF629D:  //CH button
                        {
                                DECIMAL = 0;
                                lcd.clear();lcd.print("Decimal reset");
                                ADD = false; SUB = false;
                        }break;

                }
        irrecv.resume();
  }
  /*There isnt a good way to clear just one line on the LCD. This is to solve the issue of
   DECIMAL = -100:: -100 + 100 = 0000 >>>> 0000 + 100 = 1000. when the number went negative
   it added a zero onto the end of the number once it is brough back positive*/
  lcd.print("                ");
  /*Display DECIMAL outside of switch so even when lcd.clear() is used this will always display on
  second row of LCD*/
  lcd.setCursor(0,1);lcd.print("DEC: ");lcd.print(DECIMAL);
}
