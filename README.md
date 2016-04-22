# Engine

Ce projet est un Moteur graphique utilisant OpenGL 4.2, c++14 && gsl.

# Compilation

## Linux


### Debug

```shell
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=debug ..
make
```

### Release

```shell
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=release ..
make
```

## Windows

TODO mart_p

### Release

Compilation 64 && Release sur windows.

#### Installation GLEW


#### Installation Log4cpp


#### Installation Assimp


#### Installation GLM

### Debug

Compilation 64 && Debug sur windows

#### Installation GLEW


#### Installation Log4cpp


#### Installation Assimp


#### Installation GLM


Compilation 32 && Debug sur windows

TODO lefebv_z
##### Installation GLEW
##### Installation Log4cpp
##### Installation Assimp
##### Installation GLM

#### Les libs doivent être compilés en local.


#### Generation solution Engine

Depuis cmake-gui, indiquer le dossier source étant la racine du dépot Engine
	et le dossier bin "pathEngine"/cmake.
Lancer configure et indiquer les paths manquants si nécessaires.
Choisir le compilateur "Visual Studio 14 2015" lors de la permière configuration
	(les versions précédentes ne fonctionneront pas).
Lancer generate une fois la configuration réussie.

#### Compilation Engine

Ouvrir la solution VS2015 générée dans le dossier cmake.
Vérifier dans les propriétés du projet Engine, dans C/C++ > Code Generation > Runtime Library
	que la valeur est bien "Multi-threaded Debug DLL (/MDd)"
Faire un BUILD_ALL ou REBUILD_ALL.

#### Tests Engine

Vérifier dans les propriétés du projet Engine, dans C/C++ > Code Generation > Runtime Library
	que la valeur est bien "Multi-threaded Debug (/MTd)"
Définir le test voulu en tant que projet de lancement par défaut.
Compiler et lancer.

#### Compilation Editor

Ouvrir Editor.pro à la racine du dépot Editor.
Editer le .pro et ajouter les paths des include dans le INCLUDEPATH (solution temporaire).
Utiliser le kit de compilation "Desktop Qt 5.6.0 MSVC2015 32bit"
	(les versions précédentes ne fonctionneront pas).
Exécuter qmake (nécessaire à chaque modification du .pro).
Tout (re)compiler.
Lancer le projet.

	
	