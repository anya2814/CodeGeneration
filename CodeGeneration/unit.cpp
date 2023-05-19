#include "unit.h"

void MethodUnit::add( const std::shared_ptr< Unit >& unit, Flags /* flags */ ) {
    m_body.push_back( unit );
}

