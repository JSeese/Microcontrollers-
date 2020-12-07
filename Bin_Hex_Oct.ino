bool BIN_ARRAY[] = {0,1,1,1,0,1,1,0,0,1,1,0,1,1,1,1,0,0,1,1,1,0,1,0,1,1,0,0,0,0,1,1};
unsigned long DEC_VALUE = 0;
char HEX_VALUE[] = {"0123456789ABCDEF"};

//Function to repalce the pow(8,i) while i is greater that 5
unsigned long _pow(int x, int y);

void setup()
{

        Serial.begin(115200);
        Serial.print("\nSTART");

                        int b = 0;
                        Serial.print("\nBin Value: ");
                        while (b < sizeof(BIN_ARRAY))
                        {
                                for (int i = 0; i <=3; i++)
                                {
                                        Serial.print(BIN_ARRAY[b]);
                                        b++;
                                }
                                Serial.print(" ");
                        }

                        //Code for binary to decimal start
                        for (int i = 0; i < sizeof(BIN_ARRAY); i++)
                        {
                                if (i < 16)
                                {
                                        //1 << 31 == 2147483648
                                        DEC_VALUE += (BIN_ARRAY[i] << ((sizeof(BIN_ARRAY)-17) - i))*65536;

                                }
                                else
                                {
                                        DEC_VALUE += BIN_ARRAY[i] << ((sizeof(BIN_ARRAY)-1) - i);
                                }

                        }
                        Serial.print("\nDec Value: ");Serial.print(DEC_VALUE);



                        //Code for binary to decimal end
                        //Code for binary to hex start
                        Serial.print("\nHex Value: ");

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
                                Serial.print(HEX_VALUE[dec_value]);
                        }
                        //Code for binary to hex end
                        int i = 10;
                        Serial.print("\nOct Value: ");
                        while (i >= 0)
                        {
                                unsigned long pow_8_val = _pow(8,i);
                                //Serial.print("\n");Serial.print(i);Serial.print(" ");Serial.print(pow_8_val);Serial.print(" = ");
                                if (pow_8_val <= DEC_VALUE)
                                {

                                        Serial.print(int(DEC_VALUE/pow_8_val));
                                        DEC_VALUE -= int(DEC_VALUE/pow_8_val) * pow_8_val;
                                        //Serial.print("\nDEC: ");Serial.print(DEC_VALUE);
                                }

                                else
                                {

                                        Serial.print("0");
                                }
                                i--;
                        }



        Serial.print("\nEND");
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
