#ifndef JAVA_H
#define JAVA_H

#include "unit.h"

class ClassJava : public ClassUnit {
public:
     explicit ClassJava( const std::string& name ) : ClassUnit( name ) { }      // конструктор
     std::string compile( unsigned int level = 0) const;               // генерирование кода для класса
};



class MethodJava : public MethodUnit {
public:
    explicit MethodJava( const std::string& name, const std::string& returnType, Flags      // конструктор
               flags ) : MethodUnit(name, returnType, flags) { }
    std::string compile( unsigned int level = 0 ) const;                                    // генерирование кода функции
 };



class PrintOperatorJava : public PrintOperatorUnit {
public:
    explicit PrintOperatorJava( const std::string& text ) : PrintOperatorUnit( text ) { }   // конструктор

    std::string compile( unsigned int level = 0 ) const;                                // генерирование кода оператора
};

#endif // JAVA_H
