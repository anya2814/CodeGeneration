//#include <QCoreApplication>

#include"generateprogram.h"
#include <QDebug>



int main()
{
    std::cout << GenerateProgram::generate(GenerateProgram::Cpp) << std::endl;
    std::cout << GenerateProgram::generate(GenerateProgram::Csharp) << std::endl;
    std::cout << GenerateProgram::generate(GenerateProgram::Java) << std::endl;

    return 0;
}
