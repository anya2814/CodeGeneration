#ifndef UNIT_H
#define UNIT_H

#include <iostream>
#include <vector>
#include <memory>

class Unit {
public:
    using Flags = unsigned int;

    virtual ~Unit() = default;
    virtual void add( const std::shared_ptr< Unit >& , Flags ) {
        throw std::runtime_error( "Not supported" );
    }
    virtual std::string compile( unsigned int level = 0 ) const = 0;

protected:
    virtual std::string generateShift( unsigned int level ) const  {
        static const auto DEFAULT_SHIFT = "    ";
        std::string result;
        for( unsigned int i = 0; i < level; ++i ) {
            result += DEFAULT_SHIFT;
        }
        return result;
    }
};



class ClassUnit : public Unit
{
public:
     enum AccessModifier {
     DEFAULT,
     PUBLIC,
     PROTECTED_INTERNAL,
     INTERNAL,
     PROTECTED,
     FILE,
     PRIVATE_PROTECTED,
     PRIVATE
     };

public:
     virtual void add( const std::shared_ptr< Unit >& unit, Flags flags );

     virtual std::string compile( unsigned int level = 0) const;

protected:
     std::string m_name;
     using Fields = std::vector< std::shared_ptr< Unit > >;

     std::vector< Fields > m_fields;
};



class MethodUnit : public Unit {
public:
    enum Modifier {
        STATIC = 1,
        CONST = 1 << 1,
        VIRTUAL = 1 << 2,
        FINAL = 1 << 3,
        ABSTRACT = 1 << 4
    };

public:
    void add( const std::shared_ptr< Unit >& unit, Flags /* flags */ = 0 );
    virtual std::string compile( unsigned int level = 0 ) const;

protected:
    std::string m_name;
    std::string m_returnType;
    Flags m_flags;
    std::vector< std::shared_ptr< Unit > > m_body;
 };



class PrintOperatorUnit : public Unit {
public:
    virtual std::string compile( unsigned int level = 0 ) const;

protected:
    std::string m_text;
};

#endif // UNIT_H

