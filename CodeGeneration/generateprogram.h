#ifndef GENERATEPROGRAM_H
#define GENERATEPROGRAM_H

#include <iostream>
#include <QDebug>
#include "codegeneration.h"

class GenerateProgram
{
public:
    // генерирование кода, язык зависит от подаваемого параметра
    static std::string generate(const CodeGeneration *genLang);
};

#endif // GENERATEPROGRAM_H
