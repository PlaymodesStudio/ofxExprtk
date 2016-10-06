//
//  ofxExprtk.cpp
//
//  Created by Eduard Frigola on 06/10/16.
//
//

#include "ofxExprtk.h"


void ofxExprtk::addSymbol(string sym, float &variable){
    symbol_table.add_variable(sym, variable);
}

void ofxExprtk::registerSymbols(){
    expression.register_symbol_table(symbol_table);
}

void ofxExprtk::compileExpression(string expression_str){
    parser.compile(expression_str, expression);
}