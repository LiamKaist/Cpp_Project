

#include "../U8g2/src/U8g2lib.h"


class Oled: public U8G2_SH1107_SEEED_128X128_1_SW_I2C {

    protected:
    int initOK = 0;


    public:

        Oled(const u8g2_cb_t *r,uint8_t clockie,uint8_t data,uint8_t reset): U8G2_SH1107_SEEED_128X128_1_SW_I2C(r,clockie,data,reset)
        {this->initOK=1;}

        void diagDraw(void){
            
            U8G2_SH1107_SEEED_128X128_1_SW_I2C::drawBox(1,1,10,10);
            U8G2_SH1107_SEEED_128X128_1_SW_I2C::drawBox(11,11,10,10);
            U8G2_SH1107_SEEED_128X128_1_SW_I2C::drawBox(21,21,10,10);
            U8G2_SH1107_SEEED_128X128_1_SW_I2C::drawBox(31,31,10,10);
            U8G2_SH1107_SEEED_128X128_1_SW_I2C::drawBox(41,41,10,10);
            U8G2_SH1107_SEEED_128X128_1_SW_I2C::drawBox(51,51,10,10);
            U8G2_SH1107_SEEED_128X128_1_SW_I2C::drawBox(61,61,10,10);
        
        }
};