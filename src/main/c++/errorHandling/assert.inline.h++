//
//  Copyright 2014 Fabian "Praetorian" Kürten
//  Copyright ? "MrHen"
//
//  This file is part of praetorian-basics.
//  praetorian-basics program is free software: you can redistribute it
//  and/or modify it under the terms of the GNU General Public License
//  as published by the Free Software Foundation, exactly version 3 of
//  the License.
//
//  praetorian-basics program is distributed in the hope that it will be
//  useful but WITHOUT ANY WARRANTY; without even the implied warranty
//  of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not,
//  see <http://www.gnu.org/licenses/>.
//

/*
 * This is not a source file, do not compile it directly!
 */
/*
 * This is not a simple header file, do not include it directly!
 * (unless you are assert.h++ or assert.c++ in the same folder)
 */

#ifdef INLINE
    #define MAYBE_INLINE inline
#else
    #define MAYBE_INLINE
#endif

namespace Assert {

    MAYBE_INLINE
    AssertionError assertDEE_(double const a
                             ,double const b
                             ,double const delta
                             ,std::string const & sa
                             ,std::string const & sb
                             ,std::string const & file
                             ,unsigned int const line
                             ,std::string const & function
                             )
    {
        return AssertionError("doubles not close enough "+sa+"=" + xtos(a) + ", " + sb + "=" + xtos(b) + ", delta=" + xtos(delta), file, line, function);
    }
}
