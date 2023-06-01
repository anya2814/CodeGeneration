#ifndef UNIT_H
#define UNIT_H

#include <iostream>
#include <vector>
#include <memory>

// виртуальный базовый класс
class Unit {
public:
    using Flags = unsigned int;

    virtual ~Unit() = default;
    virtual void add( const std::shared_ptr< Unit >& , Flags ) {
        throw std::runtime_error( "Not supported" );
    }
    virtual std::string compile( unsigned int level = 0 ) const = 0;

protected:
    // функция для генерации отступов
    virtual std::string generateShift( unsigned int level ) const {
        static const auto DEFAULT_SHIFT = "    ";
        std::string result;
        for( unsigned int i = 0; i < level; ++i ) {
            result += DEFAULT_SHIFT;
        }
        return result;
    }
};



class ClassUnit : public Unit
{
public:
    // перечисление возможных типов доступа в классе
    enum AccessModifier {
    DEFAULT,
    PUBLIC,
    PROTECTED_INTERNAL,
    INTERNAL,
    PROTECTED,
    FILE,
    PRIVATE_PROTECTED,
    PRIVATE
    };

public:
    // строки - типы доступа, которые будут передаваться в генерируемый код
    static const std::vector< std::string > ACCESS_MODIFIERS;

    // конструктор
    explicit ClassUnit( const std::string& name ) : m_name( name ) {
        m_fields.resize( ACCESS_MODIFIERS.size() );
    }

    // функция добавления в код класса
    void add( const std::shared_ptr< Unit >& unit, Flags flags );
protected:
    std::string m_name;                                         // имя класса
    using Fields = std::vector< std::shared_ptr< Unit > >;

    std::vector< Fields > m_fields;                             // для хранения содержимого класса
};



class MethodUnit : public Unit {
public:
    // перечисление возможных модификаторов функций
    enum Modifier {
        STATIC = 1,
        CONST = 1 << 1,
        VIRTUAL = 1 << 2,
        FINAL = 1 << 3,
        ABSTRACT = 1 << 4,
        EXTERN = 1 << 5
    };

public:
    // конструктор
    explicit MethodUnit( const std::string& name, const std::string& returnType, Flags
flags ) :
        m_name( name ), m_returnType( returnType ), m_flags( flags ) { }

    // добавление в функцию содержимого
    void add( const std::shared_ptr< Unit >& unit, Flags /* flags */ = 0 ) ;
    // генерирование кода функции
    std::string compile( unsigned int level = 0 ) const;

protected:
    std::string m_name;                             // имя функции
    std::string m_returnType;                       // тип возвращаемого значения
    Flags m_flags;                                  // флаги модификаторов
    std::vector< std::shared_ptr< Unit > > m_body;  // тело функции
 };



class PrintOperatorUnit : public Unit {
public:
    // конструктор
    explicit PrintOperatorUnit( const std::string& text ) : m_text( text ) { }
protected:
    std::string m_text;                             // текст, который используется как параметр для оператора печати
};

#endif // UNIT_H

