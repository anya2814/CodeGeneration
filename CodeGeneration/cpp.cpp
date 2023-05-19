#include "cpp.h"

const std::vector< std::string > ClassCpp::ACCESS_MODIFIERS = { "public",
    "protected", "private" };

void ClassCpp::add( const std::shared_ptr< Unit >& unit, Flags flags ) {

   int accessModifier = PRIVATE;

   if( flags < ACCESS_MODIFIERS.size() ) {
       accessModifier = flags;
   }

   m_fields[ accessModifier ].push_back( unit );
}

std::string ClassCpp::compile( unsigned int level ) const
{
    std::string result = generateShift( level ) + "class " + m_name + " {\n";
    for( size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i ) {
        if( m_fields[ i ].empty() ) {
            continue;
        }
        result += ACCESS_MODIFIERS[ i ] + ":\n";
        for( const auto& f : m_fields[ i ] ) {
            result += f->compile( level + 1 );
        }
        result += "\n";
    }

    result += generateShift( level ) + "};\n";
    return result;
}

std::string MethodCpp::compile( unsigned int level ) const {
    std::string result = generateShift( level );
    if( m_flags & STATIC ) {
        result += "static ";
    } else if( m_flags & VIRTUAL ) {
        result += "virtual ";
    }
    result += m_returnType + " ";
    result += m_name + "()";
    if( m_flags & CONST ) {
        result += " const";
    }
    result += " {\n";
    for( const auto& b : m_body ) {
        result += b->compile( level + 1 );
    }
    result += generateShift( level ) + "}\n";
    return result;
}

std::string PrintOperatorCpp::compile( unsigned int level ) const {
    return generateShift( level ) + "printf( \"" + m_text + "\" );\n";
}

