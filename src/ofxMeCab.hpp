//
//  ofxMeCab.hpp
//  ofxMeCabExample
//
//  Created by Akira on 12/7/15.
//
//

/*----------
 📝 how to build
 add
 HAVE_CONFIG_H
 to [Apple LLVM - Processing] > [Preprocessor Macros]

 add
 ../../../addons/ofxMeCab/libs/mecab/mecab_Prefix.pch
 to [Apple LLVM] > [Prefix Header]
 ----------*/


#ifndef ofxMeCab_hpp
#define ofxMeCab_hpp

#include "ofMain.h"
#include <mecab.h>

struct MorphObj
{
    MorphObj()
    {
        bComplete = true;;
    }
    
    void dump()
    {
        ofLogNotice("ofxMeCab::MorphObj") << "表層       : " << hyousou;
        ofLogNotice("ofxMeCab::MorphObj") << "原型       : " << genkei;
        ofLogNotice("ofxMeCab::MorphObj") << "品詞       : " << hinshi;
        ofLogNotice("ofxMeCab::MorphObj") << "品詞細分類1 : " << hinshiSaibunrui1;
        ofLogNotice("ofxMeCab::MorphObj") << "品詞細分類2 : " << hinshiSaibunrui2;
        ofLogNotice("ofxMeCab::MorphObj") << "品詞細分類3 : " << hinshiSaibunrui3;
        ofLogNotice("ofxMeCab::MorphObj") << "活用形     : " << katsuyoukei;
        ofLogNotice("ofxMeCab::MorphObj") << "活用型     : " << katsuyougata;
        ofLogNotice("ofxMeCab::MorphObj") << "読み       : " << yomi;
        ofLogNotice("ofxMeCab::MorphObj") << "発音       : " << hatsuon;
    }
    
    bool bComplete;
    string hyousou;
    string genkei;
    string hinshi;
    string hinshiSaibunrui1;
    string hinshiSaibunrui2;
    string hinshiSaibunrui3;
    string katsuyoukei;
    string katsuyougata;
    string yomi;
    string hatsuon;
};


class ofxMeCab : public ofThread
{
public:
    
    ofxMeCab();
    void setDict(string absDicPath);
    void parse(string jpTxt);
    vector<string> getParsedScentence(string jpTxt);
    void exit();
    
    ofEvent<MorphObj> parseEvent;
    
protected:
    
    void threadedFunction();
    
    bool bSetDict;
    
    deque<string> jpTxtQ;
    mecab_t *mecab;
};

#endif /* ofxMeCab_hpp */
