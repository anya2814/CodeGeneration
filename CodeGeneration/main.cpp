#include <QCoreApplication>

#include <classunit.h>
#include <methodunit.h>
#include <printoperatorunit.h>

std::string generateProgram() {
    ClassUnit myClass( "MyClass" );
    // при добавлении тоже появляется disassembler
    myClass.add(
                std::make_shared< MethodUnit > ( "testFunc1", "void", 0 ),
                ClassUnit::PUBLIC
                );
    myClass.add(
                std::make_shared< MethodUnit >( "testFunc2", "void", MethodUnit::STATIC ),
                ClassUnit::PRIVATE
                );
    myClass.add(
                std::make_shared< MethodUnit >( "testFunc3", "void", MethodUnit::VIRTUAL | MethodUnit::CONST ),
                ClassUnit::PUBLIC
                );

    auto method = std::make_shared< MethodUnit >( "testFunc4", "void", MethodUnit::STATIC );
    method->add( std::make_shared< PrintOperatorUnit >( R"(Hello, world!\n)" ) );
    method->add( std::make_shared< PrintOperatorUnit >( R"(Hello, world!\n)" ) );

    myClass.add( method, ClassUnit::PROTECTED );
    std::string result = myClass.compile();

    return result;
}

int main(/*int argc, char *argv[]*/)
{
    //QCoreApplication a(argc, argv);

    std::string result = generateProgram();
    std::cout << result << std::endl;
    std::cout << result << std::endl;
    std::cout << result << std::endl;

    //std::cout << generateProgram() << std::endl;


    return 0;//a.exec();
}
