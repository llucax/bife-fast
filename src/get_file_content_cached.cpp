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
// Creado:  sáb feb  7 20:04:43 ART 2004
// Autores: Leandro Lucarella <luca@lugmen.org.ar>
//----------------------------------------------------------------------------
//
// $Id$
//

//{{{ include
#include "fast/get_file_content_cached.h"
#include "fast/get_file_content.h"
//}}}

//{{{ get_file_content_cached
fast::string fast::get_file_content_cached::operator()(const string& filename)
        const
{
    string_map::const_iterator c = _cache.find(filename);
    if (c == _cache.end()) { // Not found.
        // Get file contents using regular function object.
        get_file_content file;
        _cache[filename] = file(filename);
        return _cache[filename];
    } else {
        return c->second;
    }
}
//}}} get_file_content_cached

