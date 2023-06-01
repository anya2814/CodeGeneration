#ifndef CODEGENERATION_H
#define CODEGENERATION_H

#include<iostream>
#include"cpp.h"
#include"csharp.h"
#include"java.h"

// абстрактный базовый класс - абстрактная фабрика
class CodeGeneration
{
public:
    virtual std::shared_ptr<ClassUnit> GetClass( const std::string& name ) const = 0;
    virtual std::shared_ptr<MethodUnit> GetMethod( const std::string& name, const std::string& returnType, Unit::Flags
                                   flags ) const = 0;
    virtual std::shared_ptr<PrintOperatorUnit> GetPrintOperator( const std::string& text ) const = 0;
};



// класс возвращает умные указатели на объекты класса, метода и оператора печати для языка С++
class CodeGenerationCpp : public CodeGeneration
{
public:
    explicit CodeGenerationCpp() {}
    std::shared_ptr<ClassUnit> GetClass( const std::string& name ) const;
    std::shared_ptr<MethodUnit> GetMethod( const std::string& name, const std::string& returnType, Unit::Flags
                                   flags ) const;
    std::shared_ptr<PrintOperatorUnit> GetPrintOperator( const std::string& text ) const;
};



// класс возвращает умные указатели на объекты класса, метода и оператора печати для языка С#
class CodeGenerationCsharp : public CodeGeneration
{
public:
    explicit CodeGenerationCsharp() {}
    std::shared_ptr<ClassUnit> GetClass( const std::string& name ) const;
    std::shared_ptr<MethodUnit> GetMethod( const std::string& name, const std::string& returnType, Unit::Flags
                                   flags ) const;
    std::shared_ptr<PrintOperatorUnit> GetPrintOperator( const std::string& text ) const;
};



// класс возвращает умные указатели на объекты класса, метода и оператора печати для языка Java
class CodeGenerationJava : public CodeGeneration
{
public:
    explicit CodeGenerationJava() {}
    std::shared_ptr<ClassUnit> GetClass( const std::string& name ) const;
    std::shared_ptr<MethodUnit> GetMethod( const std::string& name, const std::string& returnType, Unit::Flags
                                   flags ) const;
    std::shared_ptr<PrintOperatorUnit> GetPrintOperator( const std::string& text ) const;
};

#endif // CODEGENERATION_H
