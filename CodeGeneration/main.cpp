#include <QCoreApplication>

#include"generateprogram.h"
#include <QDebug>



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //CodeGenerationCpp obj1;
    //CodeGenerationCsharp obj2;
    //CodeGenerationJava obj3;

    std::cout << GenerateProgram::generate(GenerateProgram::Cpp) << std::endl << std::endl;

    //std::cout << obj2.generateProgram() << std::endl << std::endl;
    //std::cout << CodeGenerationCpp::generateProgram() << std::endl << std::endl;
    //std::cout << obj3.generateProgram() << std::endl;
    return 0;

    return a.exec();
}
