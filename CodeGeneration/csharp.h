#ifndef CSHARP_H
#define CSHARP_H

#include "unit.h"

class ClassCsharp : public ClassUnit {
public:
    explicit ClassCsharp( const std::string& name ) : ClassUnit( name ) { }
    std::string compile( unsigned int level = 0) const override;
};



class MethodCsharp : public MethodUnit {
public:
    explicit MethodCsharp( const std::string& name, const std::string& returnType, Flags
               flags ) : MethodUnit(name, returnType, flags) { }
 };



class PrintOperatorCsharp : public PrintOperatorUnit {
public:
    explicit PrintOperatorCsharp( const std::string& text ) : PrintOperatorUnit( text ) { }

    std::string compile( unsigned int level = 0 ) const;
};


#endif // CSHARP_H
