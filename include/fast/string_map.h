// vim: set expandtab tabstop=4 shiftwidth=4:
//----------------------------------------------------------------------------
//                                    fast
//----------------------------------------------------------------------------
// This file is part of fast.
//
// fast is free software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the Free Software
// Foundation; either version 2 of the License, or (at your option) any later
// version.
//
// fast is distributed in the hope that it will be useful, but WITHOUT ANY
// WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
// details.
//
// You should have received a copy of the GNU General Public License along
// with fast; if not, write to the Free Software Foundation, Inc., 59 Temple
// Place, Suite 330, Boston, MA  02111-1307  USA
//----------------------------------------------------------------------------
// Creado:  sáb feb  7 22:23:59 ART 2004
// Autores: Leandro Lucarella <luca@lugmen.org.ar>
//----------------------------------------------------------------------------
//
// $Id$
//

#ifndef FAST_STRING_MAP_H
#define FAST_STRING_MAP_H

#include "fast/string.h"
#include <map>

namespace fast {

/// String map used to describe a set of variables.
typedef std::map< string, string > string_map;

} // namespace fast

#endif // FAST_STRING_MAP_H
