# worldsparticle
Utilisation d'OpenGL 4+ avec Qt

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
