#ifndef GENERATEPROGRAM_H
#define GENERATEPROGRAM_H

#include <iostream>
#include "codegeneration.h"

class GenerateProgram
{
    static const std::vector< std::string > LANGUAGE_NAMES;
public:
    enum language {
        Cpp = 0,
        Csharp = 1,
        Java = 2
    };

    // генерирование кода, язык зависит от подаваемого параметра
    static std::string generate(language lang);
};

#endif // GENERATEPROGRAM_H
