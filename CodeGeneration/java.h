#ifndef JAVA_H
#define JAVA_H

#include "unit.h"

class ClassJava : public ClassUnit {
public:
     explicit ClassJava( const std::string& name ) : ClassUnit( name ) { }
     std::string compile( unsigned int level = 0) const override;
};



class MethodJava : public MethodUnit {
public:
    explicit MethodJava( const std::string& name, const std::string& returnType, Flags
               flags ) : MethodUnit(name, returnType, flags) { }
 };



class PrintOperatorJava : public PrintOperatorUnit {
public:
    explicit PrintOperatorJava( const std::string& text ) : PrintOperatorUnit( text ) { }

    std::string compile( unsigned int level = 0 ) const;
};

#endif // JAVA_H
