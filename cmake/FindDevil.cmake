# Locate DevIL / ILU / ILUT libraries, this module defines :
#
# ::
#
#   DEVIL_FOUND			   - if false, do not try to link DevIL
#   DEVIL_LIBRARY_IL       - DevIL library
#   DEVIL_LIBRARY_ILU      - DevILU library
#   DEVIL_LIBRARY_ILUT     - DevILUT library
#   DEVIL_LIBRARIES        - All DevILs library found
#   DEVIL_INCLUDE_DIR      - where to find DevILs headers
#-------------------------------

FIND_PATH(DEVIL_INCLUDE_DIR
    NAMES IL/il.h
    HINTS
    ENV DEVIL_DIR
    PATHS
    ~/Library/Frameworks
    /Library/Frameworks
    /sw
    /opt/local
    /opt/csw
    /opt
    )

FIND_LIBRARY(DEVIL_LIBRARY_IL
    NAMES DevIL devil IL
    HINTS
    ENV DEVIL_DIR
    PATHS
    ~/Library/Frameworks
    /Library/Frameworks
    /sw
    /opt/local
    /opt/csw
    /opt
    )

FIND_LIBRARY(DEVIL_LIBRARY_ILU
    NAMES ILU ilu Ilu
    HINTS
    ENV DEVIL_DIR
    PATHS
    ~/Library/Frameworks
    /Library/Frameworks
    /sw
    /opt/local
    /opt/csw
    /opt
    )

FIND_LIBRARY(DEVIL_LIBRARY_ILUT
    NAMES ILUT ilut ILut
    HINTS
    ENV DEVIL_DIR
    PATHS
    ~/Library/Frameworks
    /Library/Frameworks
    /sw
    /opt/local
    /opt/csw
    /opt
    )

FIND_PACKAGE_HANDLE_STANDARD_ARGS(DevIL
    REQUIRED_VARS DEVIL_INCLUDE_DIR DEVIL_LIBRARY_IL DEVIL_LIBRARY_ILU
    )

SET(DEVIL_LIBRARIES ${DEVIL_LIBRARY_IL} ${DEVIL_LIBRARY_ILU} ${DEVIL_LIBRARY_ILUT})