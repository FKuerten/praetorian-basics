#
#   Copyright 2014 Fabian "Praetorian" Kürten
#
#   This file is part of praetorian-basics.
#   praetorian-basics program is free software: you can redistribute it
#   and/or modify it under the terms of the GNU General Public License
#   as published by the Free Software Foundation, exactly version 3 of
#   the License.
#
#   praetorian-basics program is distributed in the hope that it will be
#   useful but WITHOUT ANY WARRANTY; without even the implied warranty
#   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#   GNU General Public License for more details.
#
#   You should have received a copy of the GNU General Public License
#   along with this program (COPYING.GPL).  If not, see
#   <http://www.gnu.org/licenses/>.
#

# Configuration section
MODULE_NAME=basics
DEPENDENCIES=
LIBS:=-ldl
CXXFLAGS+= --std=c++11
ARFLAGS:=crvs

# Automatic section
INCLUDEDIRS:=${MODULEDIR}/target/generated
INCLUDEDIRS+=${MODULEDIR}/../${DEPENDENCIES}/src/main/c++
CPPFLAGS+=-I${INCLUDEDIRS}
