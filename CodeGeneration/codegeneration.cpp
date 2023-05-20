#include "codegeneration.h"

std::string CodeGenerationCpp::generateProgram() {
    ClassCpp myClass( "MyClassC++" );
    myClass.add(
                std::make_shared< MethodCpp > ( "testFunc1", "void", 0 ),
                ClassCpp::PUBLIC
                );
    myClass.add(
                std::make_shared< MethodCpp >( "testFunc2", "void", MethodCpp::STATIC ),
                ClassCpp::PRIVATE
                );
    myClass.add(
                std::make_shared< MethodCpp >( "testFunc3", "void", MethodCpp::VIRTUAL | MethodCpp::CONST ),
                ClassCpp::PUBLIC
                );

    auto method = std::make_shared< MethodCpp >( "testFunc4", "void", MethodCpp::STATIC );
    method->add( std::make_shared< PrintOperatorCpp >( R"(Hello, world!\n)" ) );
    myClass.add( method, ClassCpp::PROTECTED );
    return myClass.compile();
}

std::string CodeGenerationCsharp::generateProgram() {
    ClassCsharp myClass( "MyClassC#" );
    myClass.add(
                std::make_shared< MethodCsharp > ( "testFunc1", "void", 0 ),
                ClassCsharp::PRIVATE_PROTECTED
                );
    myClass.add(
                std::make_shared< MethodCsharp >( "testFunc2", "void", MethodCsharp::STATIC ),
                ClassCsharp::PRIVATE
                );
    myClass.add(
                std::make_shared< MethodCsharp >( "testFunc3", "void", MethodCsharp::VIRTUAL | MethodCsharp::CONST ),
                ClassCsharp::PUBLIC
                );
    myClass.add(
                std::make_shared< MethodCsharp >( "testFunc4", "void", MethodCsharp::STATIC | MethodCsharp::EXTERN ),
                ClassCsharp::FILE
                );
    myClass.add(
                std::make_shared< MethodCsharp >( "testFunc5", "void", MethodCsharp::ABSTRACT | MethodCsharp::CONST ),
                ClassCpp::PUBLIC
                );
    myClass.add(
                std::make_shared< MethodCsharp >( "testFunc6", "void", MethodCsharp::CONST ),
                ClassCsharp::INTERNAL
                );

    auto method = std::make_shared< MethodCsharp >( "testFunc7", "void", MethodCsharp::STATIC );
    method->add( std::make_shared< PrintOperatorCsharp >( R"(Hello, world!)" ) );
    myClass.add( method, ClassCsharp::PROTECTED_INTERNAL );
    return myClass.compile();
}

std::string CodeGenerationJava::generateProgram() {
    ClassJava myClass( "MyClassJava" );
    myClass.add(
                std::make_shared< MethodJava > ( "testFunc1", "void", 0 ),
                ClassJava::DEFAULT
                );
    myClass.add(
                std::make_shared< MethodJava >( "testFunc2", "void", MethodJava::STATIC ),
                ClassJava::PRIVATE
                );
    myClass.add(
                std::make_shared< MethodJava >( "testFunc3", "void", MethodJava::VIRTUAL | MethodJava::FINAL ),
                ClassJava::PUBLIC
                );

    auto method = std::make_shared< MethodCpp >( "testFunc4", "void", MethodJava::STATIC );
    method->add( std::make_shared< PrintOperatorJava >( R"(Hello, world!)" ) );
    myClass.add( method, ClassJava::PROTECTED );
    return myClass.compile();
}
