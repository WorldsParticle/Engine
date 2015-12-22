# Locate rapidxml library This module defines
#
# ::
#
#   LOG4CPP_FOUND          - if false, do not try to link to log4cpp
#   LOG4CPP_INCLUDE_DIR    - where to find log4cpp headers
#

FIND_PATH(LOG4CPP_INCLUDE_DIR
    NAMES rapidxml/rapidxml.hpp
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

FIND_PACKAGE_HANDLE_STANDARD_ARGS(RapidXml
    REQUIRED_VARS LOG4CPP_INCLUDE_DIR
    )

MARK_AS_ADVANCED(LOG4CPP_INCLUDE_DIR)
