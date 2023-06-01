#ifndef CSHARP_H
#define CSHARP_H

#include "unit.h"

class ClassCsharp : public ClassUnit {
public:
    explicit ClassCsharp( const std::string& name ) : ClassUnit( name ) { }     // конструктор
    std::string compile( unsigned int level = 0) const;                         // генерирование кода для класса
};



class MethodCsharp : public MethodUnit {
public:
    explicit MethodCsharp( const std::string& name, const std::string& returnType, Flags    // конструктор
               flags ) : MethodUnit(name, returnType, flags) { }
 };



class PrintOperatorCsharp : public PrintOperatorUnit {
public:
    explicit PrintOperatorCsharp( const std::string& text ) : PrintOperatorUnit( text ) { } // конструктор

    std::string compile( unsigned int level = 0 ) const;                                // генерирование кода оператора
};


#endif // CSHARP_H
