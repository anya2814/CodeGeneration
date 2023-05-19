#ifndef CPP_H
#define CPP_H

#include "Unit.h"

class ClassCpp : public ClassUnit
{
public:
     static const std::vector< std::string > ACCESS_MODIFIERS;

     explicit ClassCpp( const std::string& name ) : m_name( name ) {
         m_fields.resize( ACCESS_MODIFIERS.size() );
     }

     void add( const std::shared_ptr< Unit >& unit, Flags flags );

     std::string compile( unsigned int level = 0) const;
};



class MethodCpp : public MethodUnit {
public:
    enum Modifier {
        STATIC = 1,
        CONST = 1 << 1,
        VIRTUAL = 1 << 2
    };

public:
    MethodCpp( const std::string& name, const std::string& returnType, Flags
flags ) :
        m_name( name ), m_returnType( returnType ), m_flags( flags ) { }

    void add( const std::shared_ptr< Unit >& unit, Flags /* flags */ = 0 );
    std::string compile( unsigned int level = 0 ) const;

private:
    std::string m_name;
    std::string m_returnType;
    Flags m_flags;
    std::vector< std::shared_ptr< Unit > > m_body;
 };



class PrintOperatorCpp : public PrintOperatorUnit {
public:
    explicit PrintOperatorUnit( const std::string& text ) : m_text( text ) { };

    std::string compile( unsigned int level = 0 ) const;

private:
    std::string m_text;
};

#endif // CPP_H
