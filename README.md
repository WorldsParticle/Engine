# worldsparticle
Utilisation d'OpenGL 4+ avec Qt

# Compilation

## Linux

```shell
cd cmake
cmake -DCMAKE_BUILD_TYPE=Release ..
make
```

## Windows

TODO : someone on Windows

Le FindAssimp attend que la variable "ASSIMP_DIR" soit set a l'emplacement du dossier Assimp pour qu'il trouve la librairie sur windows. (aka FindLua)

# LIENS
http://doc.qt.io/qt-5/qtgui-openglwindow-example.html -> optimisations qt pour utiliser QOpenGLContext

