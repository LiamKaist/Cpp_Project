#ifndef OLED_H
#define OLED_H


#include <U8g2lib.h>
#include <list>
#include <string>


using namespace std;
class Oled: public U8G2_SH1107_SEEED_128X128_1_SW_I2C {

    protected:
    int initOK = 0;
    string removeSpaces(string sentence);

    public:
    Oled(const u8g2_cb_t *r,uint8_t clockie,uint8_t data,uint8_t reset);
    void diagDraw(void);
    void sentenceWrite(string sentence, int maxLen, unsigned long speed);
    void operator << (const string & sentence);

};

#endif