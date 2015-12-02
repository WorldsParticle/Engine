# Locate log4cpp library This module defines
#
# ::
#
#   LOG4CPP_FOUND          - if false, do not try to link to log4cpp
#   LOG4CPP_LIBRARY        - log4cpp lib
#   LOG4CPP_INCLUDE_DIR    - where to find log4cpp headers
#

FIND_PATH(LOG4CPP_INCLUDE_DIR
    NAMES log4cpp/config.h
    HINTS
    ENV LOG4CPP_DIR
    PATHS
    ~/Library/Frameworks
    /Library/Frameworks
    /sw
    /opt/local
    /opt/csw
    /opt
    )

FIND_LIBRARY(LOG4CPP_LIBRARY
    NAMES log4cpp
    HINTS
    ENV LOG4CPP_DIR
    PATHS
    ~/Library/Frameworks
    /Library/Frameworks
    /sw
    /opt/local
    /opt/csw
    /opt
    )

FIND_PACKAGE_HANDLE_STANDARD_ARGS(log4cpp
    REQUIRED_VARS LOG4CPP_LIBRARY LOG4CPP_INCLUDE_DIR
    )

MARK_AS_ADVANCED(LOG4CPP_LIBRARY LOG4CPP_INCLUDE_DIR)
