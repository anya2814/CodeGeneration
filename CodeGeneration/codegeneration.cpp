#include "codegeneration.h"

std::shared_ptr<ClassUnit> CodeGenerationCpp::GetClass( const std::string& name ) const {
    return std::make_shared<ClassCpp>(name);
}

std::shared_ptr<MethodUnit> CodeGenerationCpp::GetMethod( const std::string& name, const std::string& returnType, Unit::Flags
                                                          flags ) const {
    return std::make_shared<MethodCpp>(name, returnType, flags);
}

std::shared_ptr<PrintOperatorUnit> CodeGenerationCpp::GetPrintOperator( const std::string& name ) const {
    return std::make_shared<PrintOperatorCpp>(name);
}



std::shared_ptr<ClassUnit> CodeGenerationCsharp::GetClass( const std::string& name ) const {
    return std::make_shared<ClassCsharp>(name);
}

std::shared_ptr<MethodUnit> CodeGenerationCsharp::GetMethod( const std::string& name, const std::string& returnType, Unit::Flags
                                                          flags ) const {
    return std::make_shared<MethodCsharp>(name, returnType, flags);
}

std::shared_ptr<PrintOperatorUnit> CodeGenerationCsharp::GetPrintOperator( const std::string& name ) const {
    return std::make_shared<PrintOperatorCsharp>(name);
}



std::shared_ptr<ClassUnit> CodeGenerationJava::GetClass( const std::string& name ) const {
    return std::make_shared<ClassJava>(name);
}

std::shared_ptr<MethodUnit> CodeGenerationJava::GetMethod( const std::string& name, const std::string& returnType, Unit::Flags
                                                          flags ) const {
    return std::make_shared<MethodJava>(name, returnType, flags);
}

std::shared_ptr<PrintOperatorUnit> CodeGenerationJava::GetPrintOperator( const std::string& name ) const {
    return std::make_shared<PrintOperatorJava>(name);
}
