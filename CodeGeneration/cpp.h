#ifndef CPP_H
#define CPP_H

#include "unit.h"

class ClassCpp : public ClassUnit {
public:
    explicit ClassCpp( const std::string& name ) : ClassUnit( name ) { }    // конструктор
    std::string compile( unsigned int level = 0) const;                     // генерирование кода для класса
};



class MethodCpp : public MethodUnit {
public:
    explicit MethodCpp( const std::string& name, const std::string& returnType, Flags       // конструктор
               flags ) : MethodUnit(name, returnType, flags) { }
    std::string compile( unsigned int level = 0 ) const;                                    // генерирование кода функции
};



class PrintOperatorCpp : public PrintOperatorUnit {
public:
    explicit PrintOperatorCpp( const std::string& text ) : PrintOperatorUnit( text ) { }    // конструктор

    std::string compile( unsigned int level = 0 ) const;                                // генерирование кода оператора
};

#endif // CPP_H
