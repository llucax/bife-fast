// vim: set expandtab tabstop=4 shiftwidth=4 fdm=marker:
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
// Creado:  sáb feb  7 23:19:07 ART 2004
// Autores: Leandro Lucarella <luca@lugmen.org.ar>
//----------------------------------------------------------------------------
//
// $Id$
//

//{{{ include
#include "fast/get_file_content.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
//}}}

//{{{ get_file_content
fast::string fast::get_file_content::operator()(const string& filename) const
{
    std::ifstream in(filename.c_str());
    // TODO - Verificar apertura.
    //      - Tirar excepción si pasa algo (21.3.6 Stroustrup).
    if (!in) {
        throw std::runtime_error(filename);
    }
    std::stringstream out;
    out << in.rdbuf();
    return out.str();
}
//}}} get_file_content

