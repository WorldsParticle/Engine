# worldsparticle

Utilisation d'OpenGL 4+ avec Qt

La documentation du projet est disponible ici : https://lefebv-z.github.io/worldsparticle/

Ne pas utiliser decltype & noexcept, problème de compatibilité avec la compilation windows.

# Compilation

## Linux

```shell
cd cmake
cmake -DCMAKE_BUILD_TYPE=Release ..
make
```

## Windows

Actuellement la compilation sur windows marche, j'ai réussis a faire le linkage, mais a cause du fait qu'on a utiliser les std::cout je ne sais pas pourquoi le programme ce ferme directement. Sachant qu'il ne marche uniquement si je le fait tourner sur ma carte graphique nvidia.

### Telechargements des librairies

toujours dans la même architecture (64 ||32), ne pas faire de mix !

#### Devil :

    Site officiel : http://openil.sourceforge.net/
    Lien direct 32 (16/11/2015) : http://sourceforge.net/projects/openil/files/DevIL%20Windows%20SDK/1.7.8/DevIL-SDK-x86-1.7.8.zip/download

#### Assimp :

    Site officiel : http://assimp.sourceforge.net/
    Lien direct 32 (16/11/2015) : http://freefr.dl.sourceforge.net/project/assimp/assimp-3.1/assimp-3.1.1-win-binaries.zip

WARNING : pour ma part j'ai du recompiler Assimp a cause d'une erreur de linkage 1107 surement du a un compilo différent du miens. (visual studio 2013)

Le FindAssimp attend que la variable "ASSIMP_DIR" soit set a l'emplacement du dossier Assimp pour qu'il trouve la librairie sur windows. (aka FindLua)

# LIENS
http://doc.qt.io/qt-5/qtgui-openglwindow-example.html -> optimisations qt pour utiliser QOpenGLContext
https://en.wikipedia.org/wiki/Rule_of_three_%28C%2B%2B_programming%29

reminder : Note that the FBX SDK is not covered by the GNU General Public License (GPL), and the source code is not publicly available. Some source code does exists for customizing the Maya and 3ds Max FBX plug-ins, though it is packaged in the FBX Extensions SDK, and not in the FBX SDK itself. The latest release and any previous version of the FBX SDK can be obtained on the Autodesk FBX website at http://www.autodesk.com/fbx.The FBX SDK cannot be redistributed or repackaged without written permission from Autodesk. Should you wish to distribute an open-source project which uses the FBX SDK, you must include a link to the Autodesk FBX website so the user may install the required version of the FBX SDK.
