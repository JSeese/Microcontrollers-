#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

bool BIN_ARRAY[] = {0,1,1,1,0,1,1,0,0,1,1,0,1,1,1,1,0,0,1,1,1,0,1,0,1,1,0,0,0,0,1,1};
unsigned long DEC_VALUE = 0;
char HEX_VALUE[] = {"0123456789ABCDEF"};
int CONV_OUTPUT = 2; // 0 = BIN 1 = DEC 2 = HEX 3 = OCT

//Function to repalce the pow(8,i) while i is greater that 5
unsigned long _pow(int x, int y);

void setup()
{
        lcd.begin(16, 2);

        //binary to decimal conversion
        for (int i = 0; i < sizeof(BIN_ARRAY); i++)
        {
                if (i < 16)
                {
                        DEC_VALUE += (BIN_ARRAY[i] << ((sizeof(BIN_ARRAY)-17) - i))*65536;

                }
                else
                {
                        DEC_VALUE += BIN_ARRAY[i] << ((sizeof(BIN_ARRAY)-1) - i);

                }
        }

        switch (CONV_OUTPUT)
        {
                case 0:
                {
                        int b = 0;
                        lcd.print("\nBin Value: ");
                        lcd.setCursor(0,1);
                        while (b < sizeof(BIN_ARRAY))
                        {
                                for (int i = 0; i <=3; i++)
                                {
                                        lcd.print(BIN_ARRAY[b]);
                                        b++;
                                }
                                lcd.print(" ");
                        }
                break;
                }

                case 1:
                {
                        lcd.print("\nDec Value: ");lcd.setCursor(0,1);lcd.print(DEC_VALUE);
                break;
                }


                case 2:
                {
                        lcd.print("\nHex Value: ");
                        lcd.setCursor(0,1);

                        //increment nibble_index + 4 for every loop
                        for (int nibble_index = 0; nibble_index < sizeof(BIN_ARRAY); nibble_index += 4)
                        {
                                //Reset dec value for each nibble
                                int dec_value = 0;

                                for (int bit_index = 0; bit_index < 4; bit_index++)
                                {
                                        //nibble_index + bit_index is pointer
                                        dec_value += BIN_ARRAY[nibble_index + bit_index] << (3 - bit_index);
                                }
                                //Uses dec_value to index through HEX_VALUE[]
                                lcd.print(HEX_VALUE[dec_value]);
                        }
                break;
                }

                case 3:
                {
                //Code for binary to hex end
                        int i = 10;
                        lcd.print("\nOct Value: ");
                        lcd.setCursor(0,1);
                        while (i >= 0)
                        {
                                unsigned long pow_8_val = _pow(8,i);
                                //lcd.print("\n");lcd.print(i);lcd.print(" ");lcd.print(pow_8_val);lcd.print(" = ");
                                if (pow_8_val <= DEC_VALUE)
                                {

                                        lcd.print(int(DEC_VALUE/pow_8_val));
                                        DEC_VALUE -= int(DEC_VALUE/pow_8_val) * pow_8_val;
                                        //lcd.print("\nDEC: ");lcd.print(DEC_VALUE);
                                }

                                else
                                {

                                        lcd.print("0");
                                }
                                i--;
                        }
                break;
                }

                default:
                {
                        lcd.print("\nSelect Conversion");
                break;
                }

        }

}

void loop()
{


}

//Function to repalce the pow(8,i) while i is greater that 5

unsigned long _pow(int x, int y)
{
        unsigned long rtn_val = 1;
        //if y = 0 if statement on line 68 is skipped and a 0 is printed
        if (y > 0)
        {
                while(y>0)
                {
                        //y = 1; (rtn_val = 1) *= 8 = 8 == 8^1
                        //y = 2; (rtn_val = 8) *= 8 = 64 == 8^2
                        //y = 10; (rtn_val = 134217728) *= 8 = 1073741824 == 8^10
                        rtn_val *= x;
                        y--;
                }
        }

        return rtn_val;
}
