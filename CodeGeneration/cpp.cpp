#include "cpp.h"

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
        if (i != ACCESS_MODIFIERS.size() - 1) result += "\n";
    }

    result += generateShift( level ) + "};\n";
    return result;
}

std::string PrintOperatorCpp::compile( unsigned int level ) const {
    return generateShift( level ) + "printf( \"" + m_text + "\" );\n";
}

