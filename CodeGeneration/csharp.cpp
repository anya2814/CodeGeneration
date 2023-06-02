#include "csharp.h"

std::string ClassCsharp::compile( unsigned int level ) const
{
    std::string result = generateShift( level ) + "class " + m_name + " {\n";
    for( size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i ) {
        if( m_fields[ i ].empty() ) {
            continue;
        }
        else if ( ACCESS_MODIFIERS[i] == "" || ACCESS_MODIFIERS[i] == "public" ||
                 ACCESS_MODIFIERS[i] == "protected internal" || ACCESS_MODIFIERS[i] == "internal" ||
                 ACCESS_MODIFIERS[i] == "protected" || ACCESS_MODIFIERS[i] == "file" ||
                 ACCESS_MODIFIERS[i] == "private protected" || ACCESS_MODIFIERS[i] == "private" )
        {
        for( const auto& f : m_fields[ i ] ) {
            result += generateShift( level + 1 ) + ACCESS_MODIFIERS[ i ];
            if (ACCESS_MODIFIERS[ i ] != "") result += " ";
            result += f->compile( level + 1 );
        }
        if (i != ACCESS_MODIFIERS.size() - 1) result += "\n";
        }
        //else std::cout << "Warning: access modifier \"" << ACCESS_MODIFIERS[i] << "\" is not available for this language." << std::endl;
    }

    result += generateShift( level ) + "};\n";
    return result;
}

std::string MethodCsharp::compile( unsigned int level ) const {
    std::string result = "";
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
    }

    result += " {\n";
    for( const auto& b : m_body ) {
        result += b->compile( level + 1 );
    }
    result += generateShift( level ) + "}\n";
    return result;
}

std::string PrintOperatorCsharp::compile( unsigned int level ) const {
    return generateShift( level ) + "Console.WriteLine( \"" + m_text + "\" );\n";
}

