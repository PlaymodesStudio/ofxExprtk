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

template<typename T>
class ofxExprtk{
public:
    ofxExprtk(){};
    ~ofxExprtk(){};
    
    void addSymbol(string sym, T &variable);
    void registerSymbols();
    
    bool compileExpression(string expression);
    
    T evaluateExpression(){return expression.value();};
    
private:
    typedef exprtk::symbol_table<T> symbol_table_t;
    typedef exprtk::expression<T>     expression_t;
    typedef exprtk::parser<T>             parser_t;
    
    symbol_table_t symbol_table;
    expression_t expression;
    parser_t parser;
};


template<typename T>
void ofxExprtk<T>::addSymbol(string sym, T &variable){
    symbol_table.add_variable(sym, variable);
}

template<typename T>
void ofxExprtk<T>::registerSymbols(){
    expression.register_symbol_table(symbol_table);
}

template<typename T>
bool ofxExprtk<T>::compileExpression(string expression_str){
    
    if(parser.compile(expression_str, expression))
    {
        cout << "Exprtk : Parser compiled expression ! " << endl;
        return true;
    }
    else
    {
        cout << "Exprtk : Parser FAILED to compile expression ! " << endl;
        return false;
    }
}

#endif /* ofxExprtk_h */
