#
#===============================================================================
#
# Copyright (C) 2011 Associated Universities, Inc. Washington DC, USA.
#
# This program is free software; you can redistribute it
# and/or modify it under the terms of the GNU General Public
# License as published by the Free Software Foundation; either
# version 2 of the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will
# be useful, but WITHOUT ANY WARRANTY; without even the implied
# warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# See the GNU General Public License for more details.
#
# You should have received a copy of the GNU General
# Public License along with this program; if not, write to the Free
# Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
#
# Correspondence concerning GBT software should be addressed as follows:
#  	GBT Operations
# 	National Radio Astronomy Observatory
# 	P. O. Box 2
# 	Green Bank, WV 24944-0002 USA
#
#===============================================================================

# .SUMMARY A makefile that supports development using C++ and C files.
# 
# .LIB(M&C)

# EDITING THIS MAKEFILE
# First Read the README file.
# To customize this makefile, edit the following tokens:
#     EXECUTABLE (Name of your executable program)
#     USRLIBS (List of user developed libraries to link the EXECUTABLE
#              This list has dependency checking performed on it.)
#     SYSLIBS (List of system or third party libraries - no dependency checking)
#     USER_INCLUDES (Directories containing non-system header files)
#     PRODUCT (A list of desired targets)
#
#
#############################################################################
#Section 1: Developer defined Variables. 
#           (see Section 3 for developer defined rules and targets.)

# Pick what targets should be generated from this directory
# PRODUCT=$(EXECUTABLE) $(RELINKTARGET) $(LIBRARYTARGET) $(HTMLTARGET) $(EMBEDDED) $(DAEMON) $(TOOL)
PRODUCT=$(SHAREDLIBRARYTARGET) $(LIBRARYTARGET)

# Provide a name for EXECUTABLE, DAEMON or EMBEDDED targets
#EXECUTABLE=
#DAEMON=
#EMBEDDED=
# Set TOPLEVEL to the top of the source tree (e.g. /gbt1/monctrl/src)
# If left unset, it defaults to $YGOR_ROOT
TOPLEVEL=../../../../..

#############################################################################
#Section 2: Common Variables and target rules

include $(YGOR_ROOT)/include/CommonRules.mk
#include $(YGOR_ROOT)/include/CoreFiles.mk

#############################################################################
# Section 3: Additional Developer defined Rules and Targets.
#
#USRLIBS += 
USER_INCLUDES += -I../../Manager
USER_INCLUDES += -I$(GB_ROOT)/headers
USER_INCLUDES += -I$(TOPLEVEL)/headers
USER_INCLUDES += -I$(YGOR_ROOT)/libraries/DeviceAccess
USER_INCLUDES += -I$(YGOR_ROOT)/libraries/DataDesc
#SYSLIBS +=
CXXFLAGS += -fpic
