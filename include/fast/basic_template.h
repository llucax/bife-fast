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
// Creado:  sáb feb  7 20:04:43 ART 2004
// Autores: Leandro Lucarella <luca@lugmen.org.ar>
//----------------------------------------------------------------------------
//
// $Id$
//

#ifndef FAST_BASIC_TEMPLATE_H
#define FAST_BASIC_TEMPLATE_H

//#include "fast/string.h"
//#include "fast/string_map.h"
//#include <map>
#include <stack>

namespace fast {

/**
 * bate - BAse Template Engine.
 *
 * bate is the base template engine implemented in faste.
 */
template < class F, class S, class M >
class basic_template {

    // Types.
    public:
        /// Cache traits type.
        typedef F file_content_type;
        /// String type.
        typedef S string_type;
        /// Map type.
        typedef M< string_type, string_type > map_type;

    // Attributes.
    private:
        /// Root directory where to search for templates.
        string_type _root;
        /// Postfix added to the blockname to convert it to a filename.
        string_type _postfix;
        /// Function object to get the contents of a "file".
        file_content_type _file_content;
        /// Group stack.
        std::stack< string_type > _group;

    // Methods.
    protected:
        /**
         * Gets a filename based on the block.
         *
         * @param  block Name of the block to get the filename.
         *
         * @return Block's filename.
         */
        string_type build_filename(const string_type& block) const
        {
            string_type group = _group.top();
            if (group.length()) group += '/';
            return _root + '/' + group + block + _postfix;
        }

    public:
        /**
         * Constructor.
         *
         * @param root         Root directory from where to get the templates.
         * @param postfix      Postfix of the template files.
         * @param group        Starting group.
         * @param file_content Function object to get the contents of a "file".
         */
        basic_template(const string_type& root = ".",
                const string_type& postfix = ".tpl", const string_type& group = "",
                const file_content_type& file_content = file_content_type())
            : _root(root), _postfix(postfix), _file_content(file_content)
        { _group.push(group); }

        /// Gets templates root directory.
        string_type root(void) const
        { return _root; }

        /// Sets templates root directory.
        void root(const string_type& root)
        { _root = root; }

        /// Gets templates postfix.
        string_type postfix(void) const
        { return _postfix; }

        /// Sets templates postfix.
        void postfix(const string_type& postfix)
        { _postfix = postfix; }

        /**
         * Gets the current working group.
         *
         * @return Current template's group.
         */
        string_type group(void) const
        { return _group.top(); }

        /**
         * Starts working with a new group of templates.
         *
         * @param group Group of templates to work with.
         */
        void push_group(const string_type& group)
        { _group.push(group); }

        /**
         * Stops working with a group of templates.
         *
         * @return Last template's group used.
         */
        string_type pop_group(void)
        {
            string_type group = _group.top();
            _group.pop();
            return group;
        }

        /**
         * Parses a block replacing keys with values in the hash.
         *
         * @param  block Name of the block to parse.
         * @param  vars  Hash containing the variable names and their values.
         *
         * @return Parsed block with variables replaced.
         */
        string_type parse(const string_type& block, const map_type& vars) const
        {
            // TODO - el build_filename() debería ser parte de la política
            // de reemplazo? o del file_contents?
            // TODO: capturar excepción (pensar política para reportar errores)
            string_type content = _file_content(build_filename(block));
            for (map_type::const_iterator i = vars.begin();
                    i != vars.end(); ++i) {
                // TODO - Parametrizar los 'separadores' y toda la política
                // de search & replace en un template para hacerlo más
                // flexible e implementar cosas como funciones de
                // transformación, por ej. {upper(KEYWORD)}
                string_type key = string("{") + i->first +  "}";
                string_type::size_type pos;
                while ((pos = content.find(key)) != string_type::npos) {
                    content.replace(pos, key.length(), i->second);
                }
            }
            return content;
        }

}; // class basic_template

} // namespace fast

#endif // FAST_BASIC_TEMPLATE_H
