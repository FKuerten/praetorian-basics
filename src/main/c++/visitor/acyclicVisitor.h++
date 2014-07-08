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

#ifndef PRAETORIAN_BASICS_VISITOR_ACYCLICVISITOR_HPP
    #define PRAETORIAN_BASICS_VISITOR_ACYCLICVISITOR_HPP

    namespace Praetorian {
        namespace Basics {
            namespace Visitor {

                class AcyclicVisitor {
                    public:
                        virtual ~AcyclicVisitor();
                };

            }
        }
    }

    #include "noSuchVisitorException.h++"

    #define CREATE_VISITOR_INTERFACE(ClassName) \
    class Visitor { \
        public: \
            virtual void visit(ClassName const &) = 0; \
            virtual ~Visitor() {}; \
    }

    #define CREATE_VISITOR_METHOD(ClassName) \
    void \
    ClassName::accept(::Praetorian::Basics::Visitor::AcyclicVisitor & visitor) const \
    { \
        if (ClassName::Visitor* correctVisitor = dynamic_cast<ClassName::Visitor*>(&visitor)) { \
            correctVisitor->visit(*this); \
        } else { \
            throw ::Praetorian::Basics::Visitor::NoSuchVisitorException(); \
        } \
    }


#endif
