int msbOctNum[32] = {};
int lsbOctNum[32] = {};
long decNumIN = 1987001027;
long remainder = 0;
long bufferSize = 0;


void setup()
{
        Serial.begin(115200);
        Serial.print("\nSTART");
        Serial.print("\nOCT Value: ");

        int i = 0;
        while (decNumIN > 8)
        {

                remainder = decNumIN % 8;
                decNumIN /= 8;
                lsbOctNum[i] = remainder;
                //Serial.print("\ni: ");Serial.print(i);Serial.print(" ");Serial.print(remainder);
                i++;
                bufferSize = i;

        }
        //Serial.print("\nbufferSize: ");Serial.print(bufferSize);Serial.print("\n");

        if (lsbOctNum[i] == 0)
        {

                        lsbOctNum[i] = decNumIN;
        }

        int bufferSize_origional = bufferSize;
        for (int x = 0; x <= bufferSize_origional; x++)
        {

                msbOctNum[x] = lsbOctNum[bufferSize];
                bufferSize--;
                Serial.print(msbOctNum[x]);
        }
}


void loop()
{

/*
        if (lsbOctNum[i] = 0)
        {

                        lsbOctNum[i] = decNumIN;
                        //Serial.print("\nTEST FOR LOOP: ");Serial.print(x);
        }

        for (int x = 0; x < bufferSize; x++)
        {

                msbOctNum[x] = lsbOctNum[bufferSize];
                bufferSize--;
                Serial.print(msbOctNum[x]);
        }
*/
}
