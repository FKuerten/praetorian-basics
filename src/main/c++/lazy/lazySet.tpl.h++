//
//  Copyright 2014 Fabian "Praetorian" Kürten
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
 * (unless you are lazySet.h++ in the same folder)
 */

namespace Praetorian {
    namespace Basics {
        namespace Lazy {

            template <typename T, typename Compare, typename Alloc>
            bool operator==(LazySetConstIterator<T, Compare, Alloc> const & lhs, LazySetConstIterator<T, Compare, Alloc> const & rhs)
            {
                if (&(lhs.theSet) != &(rhs.theSet)) {
                    return false;
                } else if (lhs.atEnd != rhs.atEnd) {
                    return false;
                } else if (lhs.atEnd) {
                    return true;
                } else if (lhs.returnedElements == rhs.returnedElements) {
                    return true;
                } else {
                    return false;
                }
            }

            template <typename T, typename Compare, typename Alloc>
            bool operator!=(LazySetConstIterator<T, Compare, Alloc> const & lhs, LazySetConstIterator<T, Compare, Alloc> const & rhs)
            {
                if (&(lhs.theSet) != &(rhs.theSet)) {
                    return true;
                } else if (lhs.atEnd != rhs.atEnd) {
                    return true;
                } else if (lhs.atEnd) {
                    return false;
                } else if (lhs.returnedElements != rhs.returnedElements) {
                    return true;
                } else {
                    false;
                }
            }

            template <typename T, typename Compare, typename Alloc>
            LazySetConstIterator<T, Compare, Alloc>::LazySetConstIterator(LazySetType const & lazySet, SetType const & returnedElements)
            : returnedElements(returnedElements)
            , theSet(lazySet)
            {
            }

            template <typename T, typename Compare, typename Alloc>
            LazySetConstIterator<T, Compare, Alloc>::LazySetConstIterator(LazySetType const & lazySet, bool afterEnd)
            : returnedElements()
            , theSet(lazySet)
            , afterEnd(afterEnd)
            {
            }

            //template <typename T, typename Compare, typename Alloc>
            //T const & LazySetConstIterator<T, Compare, Alloc>::operator*() const
            //{
            //}


            template <typename T, typename Compare, typename Alloc>
            typename LazySet<T, Compare, Alloc>::const_iterator LazySet<T, Compare, Alloc>::cbegin() const
            {
                return const_iterator(*this, std::set<T, Compare, Alloc>());
            }

            template <typename T, typename Compare, typename Alloc>
            typename LazySet<T, Compare, Alloc>::const_iterator LazySet<T, Compare, Alloc>::cend() const
            {
                return const_iterator(*this, true);
            }

        }
    }
}
