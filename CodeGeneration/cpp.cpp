#include "cpp.h"

std::string ClassCpp::compile( unsigned int level ) const
{
    std::string result = generateShift( level ) + "class " + m_name + " {\n";

    // генерируем код для всех добавленных функций
    // по очереди для каждого модификатора доступа
    for( size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i ) {
        if( (m_fields[ i ].empty()) ) {
            continue;
        }
        else if ( ACCESS_MODIFIERS[i] == "" || ACCESS_MODIFIERS[i] == "public" ||
                 ACCESS_MODIFIERS[i] == "protected" || ACCESS_MODIFIERS[i] == "private" )
        {
        result += ACCESS_MODIFIERS[ i ] + ":\n";
        for( const auto& f : m_fields[ i ] ) {
            result += f->compile( level + 1 );
        }
        if (i != ACCESS_MODIFIERS.size() - 1) result += "\n";
        }
        //else std::cout << "Access modifier \"" << ACCESS_MODIFIERS[i] << "\" is not available for this language." << std::endl;
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

