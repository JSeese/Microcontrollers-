//**********INPUT SIMULATOR**********//
unsigned long time;
int Input;
short inputRandomRoll;
int previoustime;
int currenttime;
bool ONE_SHOT = false;
short SUM_INDEX = 0;
int PRODUCT_INDEX;
short HEX_SWITCH = 11;
bool DEBOUNCE = false;
short BUTTON_COUNT = 1;

//**********INPUT SIMULATOR**********//


//build an array for the binary number 10100011
bool BIN_ARRAY[] = {1,0,1,0,0,0,1,1};

void setup()
{
        Serial.begin(57600);
}

void loop()
{


        while (!ONE_SHOT)
        {
                Serial.print("\nLocations of 1's: ");

                for (int i = 0; i < sizeof(BIN_ARRAY); i++)
                {
                        if (BIN_ARRAY[i] == 1)
                        {
                        Serial.print(i);Serial.print(",");
                        SUM_INDEX += i;
                        PRODUCT_INDEX = sq(SUM_INDEX);//sum of all the locations multiplied by its self. 15 * 15
                        }

                }
                Serial.print("\nSum of locations: ");Serial.print(SUM_INDEX);
                Serial.print("\nProduct of sums: ");Serial.print(PRODUCT_INDEX);//Since the first '1' is in the 0 index the product will always be 0
                Serial.print("\nSwitch Statement HEX code: ");
                ONE_SHOT = true;
        }

       switch (HEX_SWITCH)
        {
                Serial.print("\nSwitch Statement HEX code: ");
                case 1:{
                        Serial.print("1");HEX_SWITCH = 0;
                        }break;
                case 2:{
                        Serial.print("2");HEX_SWITCH = 0;
                        }break;
                case 3:{
                        Serial.print("3");
                        DEBOUNCE = true;
                        HEX_SWITCH = 0;
                        Serial.print("\n");Serial.print("\n");Serial.print("\n");
                        }break;
                case 4:{
                        Serial.print("4");HEX_SWITCH = 0;
                        }break;
                case 5:{
                        Serial.print("5");HEX_SWITCH = 0;
                        }break;
                case 6:{
                        Serial.print("6");HEX_SWITCH = 0;
                        }break;
                case 7:{
                        Serial.print("7");HEX_SWITCH = 12;
                        }break;
                case 8:{
                        Serial.print("8");HEX_SWITCH = 0;
                        }break;
                case 9:{
                        Serial.print("9");HEX_SWITCH = 0;
                        }break;
                case 10:{
                        Serial.print("A");HEX_SWITCH = 0;
                        }break;
                case 11:{
                        Serial.print("B");HEX_SWITCH = 7;
                        }break;
                case 12:{
                        Serial.print("C");HEX_SWITCH = 15;
                        }break;
                case 13:{
                        Serial.print("D");HEX_SWITCH = 0;
                        }break;
                case 14:{
                        Serial.print("E");HEX_SWITCH = 0;
                        }break;
                case 15:{
                        for (int x =0; x <= 1; x++)
                        {
                                Serial.print("F");
                        }
                        HEX_SWITCH = 3;
                        }break;
        }


        //**********INPUT SIMULATOR**********//
        while (DEBOUNCE)
        {

             time = millis();

             inputRandomRoll = random(0, 10);

             if (inputRandomRoll <= 5)
             {
                     Input = Input + currenttime;  // Input <------------- Amount of time PB_1 has been on
             }

             else
             {
                     Input = 0;
             }
             if (Input >= 300 && DEBOUNCE)
             {

                             Serial.print("\nInput time =:   ");Serial.print(Input);Serial.print("\n");
                             Serial.print("\nCount =:   ");Serial.print(BUTTON_COUNT);Serial.print("\n");
                             BUTTON_COUNT++;
             }
             if (BUTTON_COUNT >= 11)
             {
               DEBOUNCE = false;
             }

             delay(50);
             previoustime = millis();
             currenttime = previoustime - time;
           }
               //**********INPUT SIMULATOR**********//

}
