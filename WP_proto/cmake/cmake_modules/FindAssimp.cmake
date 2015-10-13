# Locate Assimp library This module defines
#
# ::
#
#   ASSIMP_FOUND          - if false, do not try to link to assimp
#   ASSIMP_LIBRARY        - assimp lib
#   ASSIMP_INCLUDE_DIR    - where to find assim headers
#

FIND_PATH(ASSIMP_INCLUDE_DIR
    NAMES assimp/version.h
   HINTS
      ENV ASSIMP_DIR
    PATHS
    ~/Library/Frameworks
    /Library/Frameworks
    /sw
    /opt/local
    /opt/csw
    /opt
    )

FIND_LIBRARY(ASSIMP_LIBRARY
    NAMES assimp
    HINTS
      ENV ASSIMP_DIR
    PATHS
    ~/Library/Frameworks
    /Library/Frameworks
    /sw
    /opt/local
    /opt/csw
    /opt
    )

FIND_PACKAGE_HANDLE_STANDARD_ARGS(Assimp
    REQUIRED_VARS ASSIMP_LIBRARY ASSIMP_INCLUDE_DIR
    )

MARK_AS_ADVANCED(ASSIMP_LIBRARY ASSIMP_INCLUDE_DIR)
