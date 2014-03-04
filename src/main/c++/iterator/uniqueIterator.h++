//
//  Copyright 2014 Fabian "Praetorian" Kürten
//
//  This file is part of praetorian-basics.
//  The praetorian-basics library is free software: you can redistribute
//  it and/or modify it under the terms of the GNU General Public
//  License as published by the Free Software Foundation, exactly
//  version 3 of the License.
//
//  The praetorian-basics library is distributed in the hope that it
//  will be useful but WITHOUT ANY WARRANTY; without even the implied
//  warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
//  See the GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not,
//  see <http://www.gnu.org/licenses/>.
//

#ifndef PRAETORIAN_BASICS_ITERATOR_UNIQUEITERATOR_HPP
    #define PRAETORIAN_BASICS_ITERATOR_UNIQUEITERATOR_HPP

    namespace Praetorian {
        namespace Basics {
            namespace Iterator {

                template<class Iterator, class Comparator>
                class UniqueIterator;

                template<class Iterator, class Comparator>
                bool operator==(UniqueIterator<Iterator, Comparator> const & lhs, UniqueIterator<Iterator, Comparator> const & rhs);
                template<class Iterator, class Comparator>
                bool operator!=(UniqueIterator<Iterator, Comparator> const & lhs, UniqueIterator<Iterator, Comparator> const & rhs);

                template<class Iterator, class Comparator>
                class UniqueIterator {
                    public:
                        typedef typename Iterator::value_type value_type;

                    private: // variables
                        typename Iterator::Ptr current;
                        typename Iterator::ConstPtr end;
                        std::set<value_type, Comparator> returnedElements;

                    private: // method
                        void findNext();

                    public:
                        UniqueIterator(typename Iterator::Ptr current, typename Iterator::ConstPtr end);

                        UniqueIterator<Iterator, Comparator> & operator++();
                        UniqueIterator<Iterator, Comparator> const operator++(int);
                        value_type operator*() const;

                    friend bool operator==<>(UniqueIterator<Iterator, Comparator> const & lhs, UniqueIterator<Iterator, Comparator> const & rhs);
                    friend bool operator!=<>(UniqueIterator<Iterator, Comparator> const & lhs, UniqueIterator<Iterator, Comparator> const & rhs);
                };

            }
        }
    }

    #include "uniqueIterator.tpl.h++"

#endif
