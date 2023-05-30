#ifndef CODEGENERATION_H
#define CODEGENERATION_H

#include<iostream>
#include"cpp.h"
#include"csharp.h"
#include"java.h"

class CodeGeneration
{
public:
    //using Flags = unsigned int;
    virtual std::shared_ptr<ClassUnit> GetClass( const std::string& name ) = 0;
    virtual std::shared_ptr<MethodUnit> GetMethod( const std::string& name, const std::string& returnType, Unit::Flags
                                   flags ) = 0;
    virtual std::shared_ptr<PrintOperatorUnit> GetPrintOperator( const std::string& text ) = 0;
};



class CodeGenerationCpp : public CodeGeneration
{
public:
    explicit CodeGenerationCpp() {}
    std::shared_ptr<ClassUnit> GetClass( const std::string& name );
    std::shared_ptr<MethodUnit> GetMethod( const std::string& name, const std::string& returnType, Unit::Flags
                                   flags );
    std::shared_ptr<PrintOperatorUnit> GetPrintOperator( const std::string& text );
};



class CodeGenerationCsharp : public CodeGeneration
{
public:
    explicit CodeGenerationCsharp() {}
    std::shared_ptr<ClassUnit> GetClass( const std::string& name );
    std::shared_ptr<MethodUnit> GetMethod( const std::string& name, const std::string& returnType, Unit::Flags
                                   flags );
    std::shared_ptr<PrintOperatorUnit> GetPrintOperator( const std::string& text );
};



class CodeGenerationJava : public CodeGeneration
{
public:
    explicit CodeGenerationJava() {}
    std::shared_ptr<ClassUnit> GetClass( const std::string& name );
    std::shared_ptr<MethodUnit> GetMethod( const std::string& name, const std::string& returnType, Unit::Flags
                                   flags );
    std::shared_ptr<PrintOperatorUnit> GetPrintOperator( const std::string& text );
};

#endif // CODEGENERATION_H
