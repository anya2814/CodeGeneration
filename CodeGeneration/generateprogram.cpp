#include "generateprogram.h"
#include <QDebug>

const std::vector< std::string > GenerateProgram::LANGUAGE_NAMES = { "C++", "C#", "Java"};

std::string GenerateProgram::generate(language lang) {

    CodeGeneration *genLang;
    std::string className = "MyClass";
    switch (lang) {
        case 0:
            genLang = new CodeGenerationCpp;
            className += LANGUAGE_NAMES[0]; break;
        case 1:
            genLang = new CodeGenerationCsharp;
            className += LANGUAGE_NAMES[1]; break;
        case 2:
            genLang = new CodeGenerationJava;
            className += LANGUAGE_NAMES[2]; break;
        default:
            return "This language is not supported or incorrect name.\n"; break;
    }

    auto myClass = genLang->GetClass( className );
    myClass->add(
                genLang->GetMethod( "testFunc1", "void", 0 ),
                ClassUnit::PRIVATE_PROTECTED
                );
    myClass->add(
                genLang->GetMethod( "testFunc2", "void", MethodUnit::STATIC ),
                ClassUnit::PRIVATE
                );
    myClass->add(
                genLang->GetMethod( "testFunc3", "void", MethodUnit::VIRTUAL | MethodUnit::CONST ),
                ClassUnit::PUBLIC
                );
    myClass->add(
                genLang->GetMethod( "testFunc4", "void", MethodUnit::STATIC | MethodUnit::EXTERN ),
                ClassUnit::FILE
                );
    myClass->add(
                genLang->GetMethod( "testFunc5", "void", MethodUnit::ABSTRACT | MethodUnit::CONST ),
                ClassUnit::PROTECTED_INTERNAL
                );
    myClass->add(
                genLang->GetMethod( "testFunc6", "void", MethodUnit::CONST ),
                ClassUnit::INTERNAL
                );

    auto method = genLang->GetMethod( "testFunc7", "void", MethodUnit::STATIC );
    method->add( genLang->GetPrintOperator( R"(Hello, world!)" ) );
    myClass->add( method, ClassUnit::PROTECTED );
    delete genLang;
    return myClass->compile();
}
