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

/*
 * This is not a source file, do not compile it directly!
 */
/*
 * This is not a simple header file, do not include it directly!
 * (unless you are assert.h++ in the same folder)
 */

#include <iostream>

namespace Praetorian {
    namespace Basics {
        namespace Iterator {

            template<class Iterator>
            void
            UniqueIterator<Iterator>::findNext()
            {
                //std::clog << "in findNext()" << std::endl;
                while(this->current != this->end) {
                    value_type value = *(this->current);
                    // try insert
                    auto success = this->returnedElements.insert(value);
                    if (success.second) {
                        // new item
                        //std::clog << "new item: " << std::string(*value) << std::endl;
                        return;
                    } else {
                        // existing item
                        //std::clog << "existing item, skipping" << std::endl;
                        ++this->current;
                        continue;
                    }
                }
                //std::clog << "at end!" << std::endl;
            }

            template<class Iterator>
            UniqueIterator<Iterator>::UniqueIterator(Iterator start, Iterator const end)
            : current(start)
            , end(end)
            {
                this->findNext();
            }

            template<class Iterator>
            UniqueIterator<Iterator> &
            UniqueIterator<Iterator>::operator++()
            {
                //std::clog << "pre increment" << std::endl;
                // we can preincrement, the current value will always be contianed in the set
                ++(this->current);
                this->findNext();
                return *this;
            }

            template<class Iterator>
            UniqueIterator<Iterator> const
            UniqueIterator<Iterator>::operator++(int)
            {
                //std::clog << "post increment" << std::endl;
                UniqueIterator<Iterator> copy(*this);
                ++(*this);
                return copy;
            }

            template<class Iterator>
            typename UniqueIterator<Iterator>::value_type
            UniqueIterator<Iterator>::operator*() const
            {
                return *(this->current);
            }


            template<class Iterator>
            bool operator==(UniqueIterator<Iterator> const & lhs, UniqueIterator<Iterator> const & rhs)
            {
                // at end?
                bool const lhsAtEnd = lhs.current == lhs.end;
                bool const rhsAtEnd = rhs.current == rhs.end;
                if (lhsAtEnd && rhsAtEnd) {
                    return true;
                } else if (lhsAtEnd || rhsAtEnd) {
                    return false;
                }
                return (lhs.current          == rhs.current)
                    && (lhs.end              == rhs.end)
                    && (lhs.returnedElements == rhs.returnedElements);
            }

            template<class Iterator>
            bool operator!=(UniqueIterator<Iterator> const & lhs, UniqueIterator<Iterator> const & rhs)
            {
                return !(lhs == rhs);
            }

        }
    }
}
