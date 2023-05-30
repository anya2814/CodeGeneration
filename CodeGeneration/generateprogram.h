#ifndef GENERATEPROGRAM_H
#define GENERATEPROGRAM_H

#include <iostream>
#include <QDebug>
#include "codegeneration.h"

class GenerateProgram
{
public:
     enum language {
     Cpp = 0,
     Csharp = 1,
     Java = 2
     };

public:
    static std::string generate(language prLang);
};

#endif // GENERATEPROGRAM_H
