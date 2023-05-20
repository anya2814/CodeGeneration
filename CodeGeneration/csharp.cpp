#include "csharp.h"

std::string ClassCsharp::compile( unsigned int level ) const
{
    std::string result = generateShift( level ) + "class " + m_name + " {\n";
    for( size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i ) {
        if( m_fields[ i ].empty() ) {
            continue;
        }
        for( const auto& f : m_fields[ i ] ) {
            result += generateShift( level + 1 ) + ACCESS_MODIFIERS[ i ];
            if (ACCESS_MODIFIERS[ i ] != "") result += " ";
            result += f->compile( level + 1 );
        }
        if (i != ACCESS_MODIFIERS.size() - 1) result += "\n";
    }

    result += generateShift( level ) + "};\n";
    return result;
}

std::string PrintOperatorCsharp::compile( unsigned int level ) const {
    return generateShift( level ) + "Console.WriteLine( \"" + m_text + "\" );\n";
}

