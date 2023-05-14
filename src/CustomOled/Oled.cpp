

#include <Oled.h>

using namespace std;
Oled::Oled(const u8g2_cb_t *r,uint8_t clockie,uint8_t data,uint8_t reset): U8G2_SH1107_SEEED_128X128_1_SW_I2C(r,clockie,data,reset){

}


void Oled::displayData(){
    Oled::sentenceWrite("No data to display",15,10);
}

void Oled::retrieveData(){
    Oled::sentenceWrite("No data to receive",15,10);
}

void Oled::sentenceWrite(string sentence, int maxLen, unsigned long speed){
    
    list<string> sentenceList;
    //Use of STL list library to display on Oled
    int i;
    for (i=0; i<sentence.size(); i=i+speed){

        if (i+maxLen < sentence.size()){
            sentenceList.push_back(sentence.substr(i, maxLen));
        }
        else{
            sentenceList.push_back(sentence.substr(i));
        }

    }

    list<string>::iterator it;
    for (it = sentenceList.begin(); it != sentenceList.end(); ++it){
        Oled::firstPage();
        do {
            Oled::setFont(u8g2_font_fub11_tf);
            Oled::drawStr(0,24, (*it).c_str());
        } while ( Oled::nextPage() );
        delay(10);
    }
    Oled::clearDisplay();

}

string Oled::removeSpaces(string sentence){
    sentence.erase(std::remove_if(sentence.begin(), sentence.end(), ::isspace),sentence.end()); //Removing spaces to prevent display issues
    return sentence;
}



void Oled::operator<< (const string & sentence)
{
    Oled::sentenceWrite(sentence,18,4);
}