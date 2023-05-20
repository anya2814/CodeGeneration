#ifndef CPP_H
#define CPP_H

#include "unit.h"

class ClassCpp : public ClassUnit {
public:
    explicit ClassCpp( const std::string& name ) : ClassUnit( name ) { }
    std::string compile( unsigned int level = 0) const override;
};



class MethodCpp : public MethodUnit {
public:
    MethodCpp( const std::string& name, const std::string& returnType, Flags
               flags ) : MethodUnit(name, returnType, flags) { }
 };



class PrintOperatorCpp : public PrintOperatorUnit {
public:
    explicit PrintOperatorCpp( const std::string& text ) : PrintOperatorUnit( text ) { }

    std::string compile( unsigned int level = 0 ) const;
};

#endif // CPP_H
