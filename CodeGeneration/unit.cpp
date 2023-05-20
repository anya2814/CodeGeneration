#include "unit.h"

const std::vector< std::string > ClassUnit::ACCESS_MODIFIERS = { "", "public",
    "protected internal", "internal", "protected", "file", "private protected", "private" };

void ClassUnit::add( const std::shared_ptr< Unit >& unit, Flags flags ) {

   int accessModifier = PRIVATE;

   if( flags < ACCESS_MODIFIERS.size() ) {
       accessModifier = flags;
   }

   m_fields[ accessModifier ].push_back( unit );
}

void MethodUnit::add( const std::shared_ptr< Unit >& unit, Flags /* flags */ ) {
    m_body.push_back( unit );
}

std::string MethodUnit::compile( unsigned int level ) const {
    std::string result = generateShift( level );
    if( m_flags & STATIC ) {
        result += "static ";
    } else if( m_flags & VIRTUAL ) {
        result += "virtual ";
    } else if( m_flags & ABSTRACT) {
        result += "abstract ";
    }
    if( m_flags & EXTERN) {
        result += "extern ";
    }
    result += m_returnType + " ";
    result += m_name + "()";
    if( m_flags & CONST ) {
        result += " const";
    } else if( m_flags & FINAL ) {
        result += " final";
    }
    result += " {\n";
    for( const auto& b : m_body ) {
        result += b->compile( level + 1 );
    }
    result += generateShift( level ) + "}\n";
    return result;
}

