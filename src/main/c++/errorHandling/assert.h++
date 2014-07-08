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

#ifndef PRAETORIAN_BASICS_ERROR_HANDLING_ASSERT_HPP
#define PRAETORIAN_BASICS_ERROR_HANDLING_ASSERT_HPP

    /**
     * This module provides assertion macros for easy assertion testing.
     * They will be defined if NDEBUG is not defined. (Otherwise they
     * will still be defined but resolve to an empty expression.)
     */

    #include <string>
    //#include <cmath>
    #include "exceptions.h++"

    // This should return the name of the function. Unfortunately
    // this is compiler dependant.
    #if defined(__GNUC__)
        #define FUNCTION_NAME __PRETTY_FUNCTION__
    #else
        #define FUNCTION_NAME "<unknown>"
    #endif

    #ifndef NDEBUG
        #define ASSERTIONS_ENABLED true
    #else
        #define ASSERTIONS_ENABLED false
    #endif

    #define DO_WRAP(x) do { if(ASSERTIONS_ENABLED){ x } } while(false)

    /**
     * A namespace for the functions so they don't clutter global
     * namespace.
     * (macros ignore namespaces, to indicate that they are defined
     * outside the namespace)
     */
    namespace Assert {

        /**
         * A logic error thrown if an assertion fails.
         */
        class AssertionError : public LogicError {
            public:
                AssertionError(std::string const & message
                                ,std::string const & file
                                ,unsigned int const line
                                ,std::string const &function
                                );
        };

        /**
         * Assertion helper functions.
         */
        template<typename T>
        AssertionError assertGT_(T const & a
                                ,T const & b
                                ,std::string const & sa
                                ,std::string const & sb
                                ,std::string const & file
                                ,unsigned int const line
                                ,std::string const & function
                                    ,std::string const & msg = std::string()
                                );
        template<typename T>
        AssertionError assertGE_(T const & a
                                ,T const & b
                                ,std::string const & sa
                                ,std::string const & sb
                                ,std::string const & file
                                ,unsigned int const line
                                ,std::string const & function
                                    ,std::string const & msg = std::string()
                                );
        template<typename T>
        AssertionError assertLT_(T const & a
                                ,T const & b
                                ,std::string const & sa
                                ,std::string const & sb
                                ,std::string const & file
                                ,unsigned int const line
                                ,std::string const & function
                                ,std::string const & msg = std::string()
                                );
        template<typename T>
        AssertionError assertLE_(T const & a
                                ,T const & b
                                ,std::string const & sa
                                ,std::string const & sb
                                ,std::string const & file
                                ,unsigned int const line
                                ,std::string const & function
                                ,std::string const & msg = std::string()
                                );
        template<typename T>
        AssertionError assertEQ_(T const & a
                                ,T const & b
                                ,std::string const & sa
                                ,std::string const & sb
                                ,std::string const & file
                                ,unsigned int const line
                                ,std::string const & function
                                ,std::string const & msg = std::string()
                                );
        AssertionError assertDEE_(double const a
                                 ,double const b
                                 ,double const delta
                                 ,std::string const & sa
                                 ,std::string const & sb
                                 ,std::string const & file
                                 ,unsigned int const line
                                 ,std::string const & function
                                 );

        /**
         * Conmversion helper functions
         */
        template<typename T>
        std::string xtos(T const & x);

    } // namespace

    // Unfortunetaly template methods need to be in the header :(
    #include "assert.tpl.h++"
    #ifdef INLINE
        // similar for inline methods
        #include "assert.inline.h++"
    #endif

    /**
     * Asserts that a condition is true.
     * @param b the condition
     * @throws AssertionErrror if the condition is false
     */
    #define assertX(b) DO_WRAP( if(!(b)) { throw Assert::AssertionError(#b,__FILE__,__LINE__,FUNCTION_NAME); } )

    /**
     * Assert that two doubles are close to each other.
     * @param a first double
     * @param b second double
     * @param eps maximum allowed difference
     * @throws AssertionError if the doubles are not that close.
     */
    #define assertDEE(a,b,eps) DO_WRAP( if(std::fabs(a-b) > eps) { throw Assert::assertDEE_(a,b,eps,#a,#b,__FILE__,__LINE__,FUNCTION_NAME); } )

    /**
     * Assert binary relation of two values
     * @param a first value
     * @param b second value
     * @throws AssertionError
     */
    #define assertGT(a,b) DO_WRAP( if(!(a> b)) { throw Assert::assertGT_(a,b,#a,#b,__FILE__,__LINE__,FUNCTION_NAME); } )
    #define assertGE(a,b) DO_WRAP( if(!(a>=b)) { throw Assert::assertGE_(a,b,#a,#b,__FILE__,__LINE__,FUNCTION_NAME); } )
    #define assertLT(a,b) DO_WRAP( if(!(a< b)) { throw Assert::assertLT_(a,b,#a,#b,__FILE__,__LINE__,FUNCTION_NAME); } )
    #define assertLE(a,b) DO_WRAP( if(!(a<=b)) { throw Assert::assertLE_(a,b,#a,#b,__FILE__,__LINE__,FUNCTION_NAME); } )
    #define assertEQ(a,b) DO_WRAP( if(!(a==b)) { throw Assert::assertEQ_(a,b,#a,#b,__FILE__,__LINE__,FUNCTION_NAME); } )

    /**
     * Assert binary relation of two values with optional message
     * @param a first value
     * @param b second value
     * @param m a mesasge
     * @throws AssertionError
     */
    #define assertGTM(a,b,m) DO_WRAP( if(!(a> b)) { throw Assert::assertGT_(a,b,#a,#b,__FILE__,__LINE__,FUNCTION_NAME, m); })
    #define assertGEM(a,b,m) DO_WRAP( if(!(a>=b)) { throw Assert::assertGE_(a,b,#a,#b,__FILE__,__LINE__,FUNCTION_NAME, m); })
    #define assertLTM(a,b,m) DO_WRAP( if(!(a< b)) { throw Assert::assertLT_(a,b,#a,#b,__FILE__,__LINE__,FUNCTION_NAME, m); })
    #define assertLEM(a,b,m) DO_WRAP( if(!(a<=b)) { throw Assert::assertLE_(a,b,#a,#b,__FILE__,__LINE__,FUNCTION_NAME, m); })
    #define assertEQM(a,b,m) DO_WRAP( if(!(a==b)) { throw Assert::assertEQ_(a,b,#a,#b,__FILE__,__LINE__,FUNCTION_NAME, m); })
#endif
