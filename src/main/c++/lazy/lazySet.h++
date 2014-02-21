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

#ifndef PRAETORIAN_BASICS_LAZY_SET_HPP
    #define PRAETORIAN_BASICS_LAZY_SET_HPP

    #include <set>
    // std::less
    #include <functional>
    // std::allocator
    #include <memory>
    #include <iterator>

    namespace Praetorian {
        namespace Basics {
            namespace Lazy {

                template<class T
                        ,class Compare = std::less<T>
                        ,class Alloc = std::allocator<T>
                        >
                class LazySet;

                template<class T
                        ,class Compare = std::less<T>
                        ,class Alloc = std::allocator<T>
                        >
                class LazySetConstIterator;

                template<class T
                        ,class Compare = std::less<T>
                        ,class Alloc = std::allocator<T>
                        >
                    bool operator==(LazySetConstIterator<T, Compare, Alloc> const & lhs, LazySetConstIterator<T, Compare, Alloc> const & rhs);
                    template<class T
                        ,class Compare = std::less<T>
                        ,class Alloc = std::allocator<T>
                        >
                    bool operator!=(LazySetConstIterator<T, Compare, Alloc> const & lhs, LazySetConstIterator<T, Compare, Alloc> const & rhs);

                template<class T
                        ,class Compare
                        ,class Alloc
                        >
                class LazySetConstIterator : std::iterator<std::output_iterator_tag, T> {
                        public: // types
                            typedef LazySet<T, Compare, Alloc> LazySetType;
                            typedef std::set<T, Compare, Alloc> SetType;

                        private: // variable
                            SetType returnedElements;
                            LazySetType const & theSet;
                            bool afterEnd;

                        public: // methods
                            LazySetConstIterator(LazySetType const & lazySet, SetType const & returnedElements);
                            LazySetConstIterator(LazySetType const & lazySet, bool afterEnd);

                            LazySetConstIterator<T, Compare, Alloc> operator++();
                            T const & operator*() const;

                            friend bool operator==<>(LazySetConstIterator<T, Compare, Alloc> const & lhs, LazySetConstIterator<T, Compare, Alloc> const & rhs);
                            friend bool operator==<>(LazySetConstIterator<T, Compare, Alloc> const & lhs, LazySetConstIterator<T, Compare, Alloc> const & rhs);
                    };

                template<class T
                        ,class Compare
                        ,class Alloc
                        >
                class LazySet {
                    private: // variables
                        std::set<T, Compare, Alloc> knownElements;
                        something source;

                    public: // types
                        typedef LazySetConstIterator<T, Compare, Alloc> const_iterator;

                        friend class LazySetConstIterator<T, Compare, Alloc> ;
                    public: // methods
                        const_iterator cbegin() const;
                        const_iterator cend() const;
                };

            }
        }
    }

    #include "lazySet.tpl.h++"

#endif
