#ifndef CODEGENERATION_H
#define CODEGENERATION_H

#include"cpp.h"
#include"csharp.h"
#include"java.h"
#include<iostream>

class CodeGeneration
{
public:
    using Flags = unsigned int;
    virtual std::string generateProgram() = 0;
    virtual std::shared_ptr<ClassUnit> GetClass( const std::string& name ) = 0;
    virtual std::shared_ptr<MethodUnit> GetMethod( const std::string& name, const std::string& returnType, Flags
                                   flags ) = 0;
    virtual std::shared_ptr<PrintOperatorUnit> GetPrintOperator( const std::string& text ) = 0;
};



class CodeGenerationCpp : public CodeGeneration
{
public:
    std::shared_ptr<ClassUnit> GetClass( const std::string& name );
    std::shared_ptr<MethodUnit> GetMethod( const std::string& name, const std::string& returnType, Flags
                                   flags );
    std::shared_ptr<PrintOperatorUnit> GetPrintOperator( const std::string& text );
};



class CodeGenerationCsharp : public CodeGeneration
{
public:
    std::shared_ptr<ClassUnit> GetClass( const std::string& name );
    std::shared_ptr<MethodUnit> GetMethod( const std::string& name, const std::string& returnType, Flags
                                   flags );
    std::shared_ptr<PrintOperatorUnit> GetPrintOperator( const std::string& text );
};



class CodeGenerationJava : public CodeGeneration
{
public:
    std::shared_ptr<ClassUnit> GetClass( const std::string& name );
    std::shared_ptr<MethodUnit> GetMethod( const std::string& name, const std::string& returnType, Flags
                                   flags );
    std::shared_ptr<PrintOperatorUnit> GetPrintOperator( const std::string& text );
};

#endif // CODEGENERATION_H
