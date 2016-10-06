//
//  ofxExprtk.h
//
//  Created by Eduard Frigola on 06/10/16.
//
//

#ifndef ofxExprtk_h
#define ofxExprtk_h

#include "ofMain.h"
#include "exprtk.hpp"

class ofxExprtk{
public:
    ofxExprtk(){};
    ~ofxExprtk(){};
    
    void addSymbol(string sym, float &variable);
    void registerSymbols();
    
    void compileExpression(string expression);
    
    float evaluateExpression(){return expression.value();};
    
private:
    typedef exprtk::symbol_table<float> symbol_table_t;
    typedef exprtk::expression<float>     expression_t;
    typedef exprtk::parser<float>             parser_t;
    
    symbol_table_t symbol_table;
    expression_t expression;
    parser_t parser;
};

#endif /* ofxExprtk_h */
