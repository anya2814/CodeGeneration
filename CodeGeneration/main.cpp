#include <QCoreApplication>

#include"generateprogram.h"
#include <QDebug>



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    CodeGenerationCpp *prLang = new CodeGenerationCpp();

    std::cout << GenerateProgram::generate(prLang) << std::endl;

    delete prLang;

    return a.exec();
}
