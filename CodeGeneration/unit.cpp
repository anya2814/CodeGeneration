#include "unit.h"

const std::vector< std::string > ClassUnit::ACCESS_MODIFIERS = { "", "public",
    "protected internal", "internal", "protected", "file", "private protected", "private" };

void ClassUnit::add( const std::shared_ptr< Unit >& unit, Flags flags ) {

   int accessModifier = PRIVATE;

   if( flags < ACCESS_MODIFIERS.size() ) {
       accessModifier = flags;
   }

   // добавляем (например, функцию) в вектор с определенным типом доступа
   m_fields[ accessModifier ].push_back( unit );
}

void MethodUnit::add( const std::shared_ptr< Unit >& unit, Flags /* flags */ ) {
    // добавляем (например, оператор) в тело функции
    m_body.push_back( unit );
}

