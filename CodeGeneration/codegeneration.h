#ifndef CODEGENERATION_H
#define CODEGENERATION_H

#include"cpp.h"
#include"csharp.h"
#include"java.h"

class CodeGeneration
{
public:
    virtual std::string generateProgram() = 0;
};



class CodeGenerationCpp: public CodeGeneration
{
public:
    std::string generateProgram() override;
};



class CodeGenerationCsharp: public CodeGeneration
{
public:
    std::string generateProgram() override;
};



class CodeGenerationJava: public CodeGeneration
{
public:
    std::string generateProgram() override;
};

#endif // CODEGENERATION_H
