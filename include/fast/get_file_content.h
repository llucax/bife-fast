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
// Creado:  sáb feb  7 20:13:34 ART 2004
// Autores: Leandro Lucarella <luca@lugmen.org.ar>
//----------------------------------------------------------------------------
//
// $Id$
//

#ifndef FAST_GET_FILE_CONTENT_H
#define FAST_GET_FILE_CONTENT_H

#include "fast/string.h"

namespace fast {

/**
 * Gets file content.
 *
 * @param  filename Name of the file to get the content.
 * @return File content.
 */
class get_file_content {
    public:
        string operator()(const string&) const;
};

} // namespace fast

#endif // FAST_GET_FILE_CONTENT_H
