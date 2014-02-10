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

#ifndef PRAETORIAN_BASICS_VISITOR_NOSUCHVISITOREXCEPTION_HPP
    #define PRAETORIAN_BASICS_VISITOR_NOSUCHVISITOREXCEPTION_HPP

    #include "../errorHandling/exceptions.h++"

    namespace Praetorian {
        namespace Basics {
            namespace Visitor {

                class NoSuchVisitorException : public LogicError {
                    public:
                        NoSuchVisitorException();
                };

            }
        }
    }

#endif
